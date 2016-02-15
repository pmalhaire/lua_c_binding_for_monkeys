# lua_c_binding_for_monkeys
new to lua, and not that smart, making the simpliest example possible.

just binding hello_word from c to lua 
hello.c creates hello lib

helloworld.lua calls hello world from c in lua
## Build & run
using clang : 
```
$clang -DLUA_USE_APICHECK=1 -g  --shared -undefined dynamic_lookup hello.c -o hello.so -I[my_path_to_lua]/include
$[my_path_to_lua]/lua helloworld.lua
hello world
$

