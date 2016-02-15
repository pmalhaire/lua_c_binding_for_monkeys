#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int main() {
    // Create new Lua state and load the lua libraries
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Tell Lua to load and run the file sample_script.lua
    luaL_dofile(L, "helloworld.lua");

    // Close the Lua state
    lua_close(L);
    return 0;
}

