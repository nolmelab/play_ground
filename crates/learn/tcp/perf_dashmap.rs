//! 멀티쓰레드 또는 멀티 태스크에서 벤치마킹하는 건 꽤 노력이 필요하다.
//! 필요한 일이고 또 능숙해져야 하는 부분임에는 틀림없다.
//! tcp_json의 Client/Server로 벤치마킹을 할 수 있도록 한다.
//! 여기서는 간단한 cargo bench 내장 기능으로 사용법과 단일 쓰레드 성능만
//! 비교해서 확인한다.
//!
//! cargo bench는 unstable feature이다. unstable feature가 필요할 때가 있다.
//! 하지만 되도록 stable하게 유지하는 게 좋다. 특히, 앱 단에서는 그렇다.
//!

#[cfg(test)]
mod test {
    use easybench::{ bench, bench_env };
    use dashmap::DashMap;
    use std::sync::Arc;

    #[test]
    fn test_bench_simple() {
        // Simple benchmarks are performed with `bench`.
        println!(
            "fib 200: {}",
            bench(|| fib(200))
        );
        println!(
            "fib 500: {}",
            bench(|| fib(500))
        );
    }

    #[test]
    fn test_bench_insert() {
        let m = DashMap::<String, String>::new(); 

        println!(
            "dashmap insert: {}",
            bench(|| dashmap_insert(&m))
        );

        println!("count: {}", m.len());
    }

    #[tokio::test]
    async fn test_use_dashmap() {
        let m = Arc::new(DashMap::<String, String>::new()); 

        let rm1 = m.clone();
        let rm2 = m.clone();

        let t1 = tokio::spawn(
            async move {
                for i in 0..100 {
                   rm1.insert(format!("key{}", i), "value".to_string());
                }
            }
        );

        let t2 = tokio::spawn(
            async move {
                for i in 100..200 {
                    rm2.insert(format!("key{}", i), "value".to_string());
                }
            }
        );

        let _ = t1.await;
        let _ = t2.await;

        assert!(m.len()  == 200);
    }

    fn fib(v: u32) {}

    // 이 또한 수월한 일은 아니지만 easybench는 이해하기 쉬운 코드이다.
    // 통계를 포함하는 struct로 구성해서 전달하면 더 많은 처리를 할 수 있다.
    fn dashmap_insert(m: &DashMap<String, String>) {
        static mut counter : u32 = 0;
        let lc = unsafe { counter };
        m.insert(format!("Veloren{}", lc), "What a fantastic game!".to_string());
        unsafe { counter += 1 };
    }
}
