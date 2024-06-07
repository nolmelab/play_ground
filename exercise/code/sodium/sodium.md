# sodium 

## codespace vcpkg install error 

- failed whiling checking the hash 
    - git pull 
    - vcpkg update
    - vcpkg install

- failed to install after build success 

```bash
-- Building x64-linux-rel
-- Installing x64-linux-rel
-- Fixing pkgconfig file: /opt/vcpkg/packages/libsodium_x64-linux/lib/pkgconfig/libsodium.pc
-- Fixing pkgconfig file: /opt/vcpkg/packages/libsodium_x64-linux/debug/lib/pkgconfig/libsodium.pc
CMake Error: File /opt/vcpkg/ports/libsodium/sodiumConfig.cmake.in does not exist.
CMake Error at ports/libsodium/portfile.cmake:69 (configure_file):
  configure_file Problem configuring file
Call Stack (most recent call first):
  scripts/ports.cmake:175 (include)
```

- sodiumConfig.cmake.in file exists in vcpkg github repo, but not in local ports folder
    - this error was introduced by rm folders, ports and versions 
    - clone vcpkg to vcpkg2 
    - cp ports from vcpkg2 into vcpkg recursively
    - lessons: 
        - practice git more
        - practice vcpkg more 



