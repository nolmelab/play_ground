# Notes - CMake Step 1

## cli works well

```bash
cmake .
make
```

## vscode cmake configure does not work. why?

vscode does not make progress after displaying "... configuring...".
go with cli for now. maybe forever. live with keyboard. 

After restarting codespace several times, configuration works. Why?
- Somehow, build directory is created at top level 
- It seems that that is the indication of something happened to make cmake works
- .vscode/settings.json has a cmake source directory set.
    - It makes cmake work




