use dashmap::DashMap;
use tokio::net::TcpStream;
use std::sync::Arc;
use std::sync::RwLock;

use anyhow::Error;

struct Server {
    addr: String,
    sessions: Arc<DashMap<u32, Session>>,
}

struct Session {
    stream: TcpStream
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

    pub async fn run(&mut self) -> Result<(), Error> {

        // bind, listen
        // accept loop

        Ok(())
    }
}

impl Session {
    // new 
    // run
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