//! oneshot 채널의 생성/처리/소멸의 성능을 살펴본다. 
//! 
//! 
use tokio::sync::oneshot;

#[tokio::main]
async fn main() {
    let (tx, rx) = oneshot::channel::<u32>();
    // channel() 함수는 생각보다 여러 가지를 포함하는 구조체를 만든다. 
    // Task 두 개를 포함한다. 
    // async_chain은 Response 정도가 가장 좋다. 
    // 
}
