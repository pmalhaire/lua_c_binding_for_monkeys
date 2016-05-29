# lua_c_binding_for_monkeys
new to lua, and not that smart, making the simpliest example possible.

using lua 5.3

### get lua
download lua from official page 
https://www.lua.org/download.html

extract it (fix name here it's lua 5.3.2)
```
tar -xzvf lua-5.3.2.tar.gz
cd lua-5.3.2
make macosx
make local
```
Note: *Here we don't do make install to keep environement clean. Instead we do a local install*

*define lua env*

create a variable to store lua path
```
LUA_BIN_PATH=[my_path_to_lua]/install/bin
LUA_INCLUDE_PATH=[my_path_to_lua]/install/include
LUA_LIB_PATH=[my_path_to_lua]/install/lib
```
ex for [my_path_to_lua]
> /home/toto/lua-5.3.2

add lua path to path so we can execute lua command
```
PATH=$LUA_BIN_PATH:$PATH
```

## Example 1
no variable passed from lua to C or the opposite just calling

OSX
### lua calls C
build clib called by lua
```
clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup hello.c -o hello.so -I$LUA_INCLUDE_PATH
```
run lua script calling path
```
lua helloworld.lua
```
>hello world

### C calls lua
build c executable calling lua script
```
clang -DLUA_USE_APICHECK=1 -g hello_call_lua_from_c.c -o hello_c -I$LUA_INCLUDE_PATH -L$LUA_LIB_PATH -llua
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
clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup call_function.c -o call_function.so -I$LUA_INCLUDE_PATH
```
run the lua script printing the c string in lua
```
lua hello_world_string.lua
```
>hello world
