# lua_c_binding_for_monkeys
new to lua, and not that smart, making the simpliest example possible.

using lua 5.3

## Example 1
no variable passed from lua to C or the opposite just calling

### env
*define lua env*

create a variable to store lua path
```
LUA_PATH=[my_path_to_lua]
```

add lua path to path so we can execute lua command
```
PATH=$LUA_PATH:$PATH
```


OSX
### lua calls C
build clib called by lua
```
clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup hello.c -o hello.so -I$LUA_PATH
```
run lua script calling path
```
lua helloworld.lua
```
>hello world

### C calls lua
build c executable calling lua script
```
clang -DLUA_USE_APICHECK=1 -g hello_call_lua_from_c.c -o hello_c -I$LUA_PATH -L$LUA_PATH -llua
```
run executable  
it calls the lua script which calls C
```
./hello_c
```
>hello world

## Example 2
using a c function that has a return value (a string here)

build lua lib having the function returning a string
```
clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup call_function.c -o call_function.so -I$LUA_PATH
```
run executable  
it calls the lua script which calls C
```
lua hello_world_string.lua
```
result
>hello world
