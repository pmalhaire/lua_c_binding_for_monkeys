#include <stdio.h>
#include "lua.h" 
#include "lualib.h"
#include "lauxlib.h"

const char * hello_world_string() {
	return "hello world\n";
}

static int lua_hello_world_string_c(lua_State *L) {
	lua_pushstring(L, hello_world_string());
	return 1;
}

static const luaL_Reg call_functionlib[] = {
{"hello_world_string", lua_hello_world_string_c},
{NULL,NULL}
};

int luaopen_call_function(lua_State *L) {
	luaL_newlib (L,call_functionlib); 
	return 1;
}

