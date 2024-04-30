//! async chain은 두 개의 연결을 처리하면서 동시에 비동기로 
//! 처리할 수 있는 방법을 모색하기위한 방법이다. 
//! 한 방법은 TcpStream을 직접 사용하지 않고 채널을 사용하는 방법이 있다. 
//!  
//! reqwest 클라이언트는 send() 호출 후에 Response를 돌려주고 
//! 이를 await할 수 있다. 만약 여러 Task에서 Response를 await할 수 있다면 
//! 이와 같은 구조를 만들어 처리 가능하다. 
//! 

use reqwest::Client;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {



    Ok(())
}

// reqwest는 연결당 하나씩만 처리를 대기할 수 있는 구조이다. 
// 요청 Id를 대기하는 RPC 구조가 아니라면 여러 task에서 대기하는 건 불가능하다.
#[allow(unused)]
async fn process_request() -> Result<(), reqwest::Error> {
    let client = Client::new();

    // send()에서 대부분의 처리를 하고 돌아온다. 
    // hyper를 내부적으로 사용하여 통신을 처리한다. 
    let response = client.get("http://example.com").send().await?;

    // Process the response here
    // For example, you can read the response body as a string
    let response_text = response.text().await?;
    println!("Response: {}", response_text);

    Ok(())
}

// AtomicAwaker를 통해 다른 Future를 깨울 수 있다. 
//  