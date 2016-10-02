#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static lua_State* init_lua();
static int get_global_function(lua_State* lstate, const char* funcname);
static double pop_number(lua_State* lstate);

int main()
{
	lua_State* const lstate = init_lua();
	if (!lstate)
		return EXIT_FAILURE;

	luaL_dofile(lstate, "hello.lua"); // load and run hello.lua
	luaL_dofile(lstate, "sum.lua"); // load sum.lua

	if (get_global_function(lstate, "sum")) {
		// push the arguments
		lua_pushnumber(lstate, 20);
		lua_pushnumber(lstate, 22);
		// protected call , 2 args, 1 result
		if (lua_pcall(lstate, 2, 1, 0) != 0) {
			printf("error running function f: %s\n", lua_tostring(lstate, -1));
		} else if (!lua_isnumber(lstate, -1)) {
			printf("sum didn't returned a number\n");
		} else {
			const double result = pop_number(lstate);
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
	}

	printf("failed to create Lua Satate\n");
	return NULL;
}

int get_global_function(lua_State* const lstate, const char* const funcname)
{
	lua_getglobal(lstate, funcname); // get the globalname nad check if is function
	if (!lua_isfunction(lstate, -1)) {
		lua_pop(lstate, 1); // pop it if it is not a function
		return 0;
	}

	return 1;
}

double pop_number(lua_State* const lstate)
{
	const double num = lua_tonumber(lstate, -1);
	lua_pop(lstate, 1);
	return num;
}
