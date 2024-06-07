# tiny renderer

A graphics course at https://github.com/ssloy/tinyrenderer/wiki

## steps

- read the documents 
- follow the code
- understand underlying math and algorithms 
- think about the whole process 
- the above steps will be mixed and repeated

## preface

I worked on a OpenGL based renderer, a very basic version which has following features: 
- shader management
- model without normal or bump map
- skeletal animation
- texture 
- alpha blending 
- FBX importer 
- scene management
- particle system
    - sprite, ribbon, trail
    - mesh 
    - emitters
- A very basic tool 

That was one year project to enhance rendering of a quite old game. 
It took quite long time since rendering is not the area of my expertise. 

Rendering is still an interesting area, even so for game developers. 
But there is Unreal and Unity. It is very hard to be more competitive than those two 
engines. That's why there are not many self made game engines out there. 
Technology has evolved so much and lots of knowledge and algorithms are required
to be implemented to be competitive. 

Then why am I learning rendering again? 
Because a simple and efficient renderer is required for game server programmers to: 
    - experiment spatial algorithms like collisions and navigation 
    - visualize server states with spatial information 
    - pure interest, which is always important for a programmer.

## Lesson 0: getting started

- a tiny software rasterizer
    - do it yourself 
    - which is the proper (or best) way to learn

- show how opengl works by implementing one
    - 500 lines
    - tga file class


## Lesson 1: Bresenhams's Line Drawing Algorithm 

- add TGA file to git repo

- TGAColor constructors added explictly 
    - several build errors are fixed

- TGA preview plugin installed to view the result

- step 1 approach has drawbacks: 
    - y value increment is not proportional to x value increment 

- step 2 enhancement: 
    - make the coordinates in [0, 1]
    - get dy from dx

- step 3 enhancement: 
    - steep line support 
    - coordinate swap support when they are reversed

- step 4 profiling: 
    - use gprof 
    - cmake option for clang to optimize
    - -pg -g -ggdb -O0 option makes gprof work
    - simple and powerful tool

- wavefront obj loader and wireframe rendering 
    - loader 
    - rendering 












