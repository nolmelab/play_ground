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
  - LengthDelimitedCodec
  - LineEndingCodec
  - SodiumCodec
  - composition of codecs is desirable
  - example of codec composition
    - SodiumCodec 
      - LengthDelimitedCodec 
    
- Node
  - has Links
    - tcp connection management
  - listen 
  - connect to multiple Nodes
    - named  
  - Link level Codec 




