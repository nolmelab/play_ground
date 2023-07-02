//! tarpc를 완전하게 이해하고 손쉽게 RPC 처럼 분산 처리를 이어서 할 수 있는 
//! 구조를 만든다. 
//! 
//! tonic이 gRpc 구현으로 더 많이 사용하고 있다. RPC가 필요한 경우 
//! tonic을 사용한다. 

mod tarpc_call;

#[tokio::main]
async fn main() -> anyhow::Result<()> {

    tarpc_call::process().await?;

    Ok(())
}