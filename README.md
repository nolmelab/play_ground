# playground

play series. This is a playground lbirary and examples to help developing massive 
multiplayer services such as games.

learn crate에서 연습을 하면서, play crate를 만든다. 

## 목표 

- 아주 많은 놀이터를 만들 수 있는 확장성 (Capacity Scalability)
- 많은 사람들이 놀 수 있는 성능 (Performance)
- 다양한 놀이를 만들 수 있는 유연성 (Flexibility)
- 쉽게 놀이를 만들 수 있는 틀 (Structure and Tools)
- 서비스 관리를 쉽게 할 수 있는 틀 (Structure and Tools)

이런 뛰어난 서버를 바로 코딩을 시작하여 전체를 모두 마칠 수 있는 능력이 
없으므로 play ground는 playground를 만들기위한 긴 여정이 될 것이다. 

이곳 저곳에서 헤매고 멈추고 다시 시작하는 길을 걷는 과정이 되고 
하루 하루 꾸준히 나아가는 더딘 발걸음이다. 

## 진행 

- loggig / tracing 

- async / await 
  - future 
  - pin / pin project 
  - waker 

- tcp 통신 
  - TcpStream, TcpListener, Codec
  - Json codec, serde-json
  - Flexbuffer

- channel   
  - mpsc, oneshot 
  - performance benchmarking 

- sqlx 
  - postgres
    - stored procedure
  - query, sp 연동 

- redis 
  - set, get, hset, hset, sorted list 
  - pub / sub 
  - clustering 

- reqwest 
  - rest api + hyper server
  - jwt 사용예 

- chat 
  - move, message, action, topic, tag, capacity, private, invite
  - client tui 
  - encryption 
    - sodium 
  - login 
    - database 
    - redis cache 
  - instance management 
    - search for topic rooms 
    - elasticsearch? 

- mo 
  - design schema table loading 
    - code generation 
    - loading and validation 
    - search 
  - navimesh
  - physics (overlap detection)
  - flexbuffer
  - instance management 
    - region based 
    - channels
  - community service 
    - guild, party, friends, matching 
  - caching 
  - character / pc / npc / volume 
    - stat, skill, buff / debuff 
    - ability, level, ... 
  - sharding
    - character (game) database
  - unreal cient 

- mmo 
  - sector (grid) 
    - traffic filtering 
    - fast search for entities
  - crowd 

  
- live / service functionality 
  - platform integration
  - billing 
  - wait queue  

