#include <stdio.h>
#include "lua.h" 
#include "lualib.h"
#include "lauxlib.h"

void hello_world_c()
{
	printf("hello world\n");
	return;
}

static int lua_hello_world_from_c(lua_State *L)
{
	hello_world_c();
	return 1;
}

static const luaL_Reg hellolib[] = {
{"hello_world", lua_hello_world_from_c},
{NULL,NULL}
};

LUALIB_API int luaopen_hello (lua_State *L) {
	luaL_newlib (L,hellolib); 
	return 1;
}

