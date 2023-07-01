//! tarpc를 완전하게 이해하고 손쉽게 RPC 처럼 분산 처리를 이어서 할 수 있는 
//! 구조를 만든다. 

mod call_1;

#[tokio::main]
async fn main() -> anyhow::Result<()> {

    call_1::process().await?;

    Ok(())
}