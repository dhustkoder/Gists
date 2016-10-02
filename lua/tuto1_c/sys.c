#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static lua_State* init_lua();

int main()
{
	lua_State* const lstate = init_lua();
	if (!lstate)
		return EXIT_FAILURE;

	luaL_dofile(lstate, "sum.lua");
	lua_getglobal(lstate, "sum"); // push sum to the lua stack
	// check if the object in the top of stach is a function
	if (lua_isfunction(lstate, -1)) {
		// push the arguments
		lua_pushnumber(lstate, 20);
		lua_pushnumber(lstate, 22);
		// protected call , 2 args, 1 result
		if (lua_pcall(lstate, 2, 1, 0) != 0) {
			printf("error running function f: %s\n", lua_tostring(lstate, -1));
		} else if (!lua_isnumber(lstate, -1)) {
			printf("sum didn't returned a number\n");
		} else {
			const double result = lua_tonumber(lstate, -1);
			lua_pop(lstate, 1);
			printf("sum's result: %lf\n", result);
		}
	} else {
		printf("global \'sum\' is not a function!\n");
	}

	lua_close(lstate);
	return EXIT_SUCCESS;
}



lua_State* init_lua()
{
	// create a new state and load libs
	lua_State* const new_state = luaL_newstate();
	if (new_state != NULL) {
		luaL_openlibs(new_state);
		return new_state;
	} else {
		printf("failed to create Lua Satate\n");
		return NULL;
	}
}



