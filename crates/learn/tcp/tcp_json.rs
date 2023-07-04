use dashmap::DashMap;
use tokio::net::{ TcpListener, TcpStream };
use tokio::io::{ AsyncReadExt, AsyncWriteExt };
use bytes::BytesMut;
use std::net::SocketAddr;
use std::sync::{Arc, RwLock};
use anyhow::Error;

struct Server {
    addr: String,
    sessions: Arc<DashMap<String, Arc<RwLock<Session>>>>,
}

struct Session {
    sessions: Arc<DashMap<String, Arc<RwLock<Session>>>>,
    stream: TcpStream,
    addr: SocketAddr,
    buffer: BytesMut,
}

struct Client {
    addr: String,
}

impl Server {
    pub fn new(addr: String) -> Self {
        Self {
            addr,
            sessions: Arc::new(DashMap::new()),
        }
    }

    #[allow(unreachable_code)] // XXX: temporal
    pub async fn run(&mut self) -> Result<(), Error> {
        let server = TcpListener::bind(&self.addr).await?;

        loop {
            // 동작하는 구조를 만들고 완전하게 한다. 헤맬 수 밖에 없다.
            // 찬찬히 다시 생각해야겠다. 어디서 어떻게 해야 할까?
            // 서버에 접근할 필요가 있다. 싱글톤처럼.

            let stream = server.accept().await?;
            let sessions = self.sessions.clone();
            let session = Arc::new(RwLock::new(Session::new(sessions, stream.0, stream.1)));
            let working_session = session.clone();

            self.sessions.insert(session.addr.to_string(), session);

            tokio::spawn(async move {
                let result = working_session.run().await;
                if let Err(e) = result {
                    println!("{}", e);
                }
            });

            // oneshot channel try_recv()로 종료 확인?
        }

        Ok(())
    }
}

impl Session {
    // new
    fn new(
        sessions: Arc<DashMap<String, Arc<RwLock<Session>>>>,
        stream: TcpStream,
        addr: SocketAddr
    ) -> Self {
        Self {
            sessions,
            stream,
            addr,
            buffer: BytesMut::with_capacity(4096),
        }
    }

    #[allow(unreachable_code)]
    async fn run(&mut self) -> Result<(), Error> {
        loop {
            let result = self.stream.read_buf(&mut self.buffer).await;

            match result {
                Err(e) => {
                    // error
                }
                Ok(len) => {
                    if len == 0 {
                        // peer disconnected
                    } else {
                        // process the buffer
                    }
                }
            }
        }

        Ok(())
    }
}

impl Client {
    pub fn new(addr: String) -> Self {
        Self {
            addr,
        }
    }

    pub async fn run(&mut self) -> Result<(), Error> {
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[tokio::test]
    async fn test_echo() {
        let mut server = Server::new("127.0.0.1:7000".to_string());

        // server.run()
        // use tokio::spawn 또는 JoinHandle로 대기

        let mut client = Client::new("127.0.0.1:7000".to_string());
        // client.run()
    }
}
