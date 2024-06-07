# bulletphysics 

Quite stable rigidbody physics engine.

https://github.com/bulletphysics/bullet3


## installation 

vcpkg supports bulletphysics as the name of bullet3. 
The current version is 3.25, which is the latest.


## link 

```cmake
  find_package(Bullet CONFIG REQUIRED)
  target_link_libraries(main PRIVATE ${BULLET_LIBRARIES})
```

## basic concepts and usage






