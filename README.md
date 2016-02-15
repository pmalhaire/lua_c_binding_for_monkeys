# lua_c_binding_for_monkeys
new to lua, and not that smart, making the simpliest example possible.

using lua 5.3

## Example 1
no variable passed from lua to C or the opposite just calling

OSX
### lua calls C
build clib called by lua
```
$clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup hello.c -o hello.so -I[my_path_to_lua]/include
```
add lua to path (we are monkeys) to use lua command
```
$PATH=[my_path_to_lua]:$PATH
```
run lua script calling path
```
$lua helloworld.lua
hello world
$
```
### C calls lua
build c executable calling lua script
```
$ clang -DLUA_USE_APICHECK=1 -g hello_call_lua_from_c.c -o hello_c -I[my_path_to_lua] -L[my_path_to_lua] -llua
```
run executable  
it calls the lua script which calls C
```
$ ./hello_c
hello world
$ 
```
