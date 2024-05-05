# design link

## what drives design?

- usability (functionality)
  - ease of use
  - declarative 
  - compositional

- testability
  - unit testable

- implementation
  - simplicity
  - readability
  - clarity
  - correctness


## Communication

- tcp 

- Codec 
  - is a concept with traits and functions
  - LengthDelimitedCodec
  - LineEndingCodec
  - SodiumCodec
  - composition of codecs is desirable
  - example of codec composition
    - SodiumCodec 
      - LengthDelimitedCodec 
  - ChainCodec
  - BypassCodec
    
- TcpLink<Codec, Packetizer>
- TcpLinkHandler<Codec, Packetizer>
  - TcpLinkServer<Codec, Packetizer> 
  - TcpLinkClient<Codec, Packetizer>

- Packetizer
  - Packet
  - Ptr
  - Key
  - Dispatcher

- FlatbuffersTopicPacketizer<size_t topic_len = 16>
  - object api based 
  - flatbuffers::nativetable as Packet  

- JsonKeyPacketizer
  - converts bytes stream to nlohmann::json Packet 
  - static key field name 

- BypassPacketizer
  - 

- Dispatcher<TopicType, PacketType> 
  - DirectDispatcher
  - StrandDispatcher
    - use post of a strand 
  - QueuedDispatcher

- IoRunner
  - ThreadIoRunner
  - ThreadlessIoRunner

ExecutionService<IoRunner> provides:
- timer service
- post service
- has io_context
- has IoRunner

- Node<IoRunner>
  - has ExecutionService<IoRunner>
  - named servers 
  - named clients
  - subclassing
  - start_server<Code, Packetizer>(name, endpoint)
  - start_client<Code, Packetizer>(name, endpoint)
  - start_server<Code, Packetizer>(name)
  - start_client<Code, Packetizer>(name)
  - stop_server(name)
  - stop_client(name)
  - get_server(name)
  - get_client(name)
  - json configuration
    - match with the names of servers and clients


## testability

- FlatbuffersTopicPacketizer
  - bytes, len
  - subscribe
  - check on the subscription result

- JsonKeyPacketizer
  - same as FlatbuffersTopicPacketizer

- Codecs
  - setup with bytes payload
  - check on the packets

- IoRunner
  - test with post

Before implementing Node, make examples with the above constructs.
Then the role and responsibility of Node will become clearer.

## usability

### basic send and recv

```c++
TcpLinkServer<ChainCodec<SodiumCodec, LengthDelimitedCodec>, FlatbuffersTopicPacketizer> server;
server.listen(endpoint, PG_LINK_CB(on_accepted), PG_LINK_CB(on_disconnected));
server.sub(login, PG_FB_CB(on_login));

FlatbuffersTopicPacketizer::Ptr pkt;
server.send(link_handle, pkt)
```

### timer 

Node provides access to underlying io_context. 

ExecutionService<IoRunner> provides:
- timer service
- post service
- io runner
- io_context reference provided from outisde

### How can we use strands?

It needs to understand completely to use strands. If not, there are risks in 
designing overall runtime behavior. 

- timers
- posts
- dispatching packets

Look at more examples and think more on it.


## exericse

exercise in code:
- chatting application 
- json protocol 
- loose implementation of: 
  - Codec
    - LineEndingCodec
    - JsonKeyPacketizer
  - Dispatcher
    - DirectDispatcher
    - ChatDispatcher
  - TcpLinkServer
  - TcpLink
  - TcpLinkClient

- chatting:
  - search user
  - send broadcast
  - create a room 
    - invite a user
  - leave a room
  - destroy a room

- experiment:
  - a strand for each room
  - handles packets to a room through the strand





