#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static lua_State* init_lua();
static void print_stack(lua_State* lstate, int nresults);
static int get_global_function(lua_State* lstate, const char* fname);
static int protected_call(lua_State* lstate, int nargs);
double pop_number(lua_State* lstate);
size_t pop_str(lua_State* lstate, char* buffer, size_t size);


int main()
{
	lua_State* const lstate = init_lua();
	if (!lstate)
		return EXIT_FAILURE;

	luaL_dofile(lstate, "hello.lua"); // load and run hello.lua
	luaL_dofile(lstate, "functions.lua"); // load functions.lua

	if (get_global_function(lstate, "get_great_warriors")
	     && get_global_function(lstate, "sum")) {
		// push the sum's arguments
		lua_pushnumber(lstate, 20);
		lua_pushnumber(lstate, 22);
		int nresults = protected_call(lstate, 2); // call sum
		printf("sum results:\n");
		print_stack(lstate, nresults);
		lua_pop(lstate, nresults); // pop its results from stack, (the function is poped when its called)
		nresults = protected_call(lstate, 0); // call get_great_warriors
		printf("get_great_warriors results:\n");
		print_stack(lstate, nresults);
		lua_pop(lstate, nresults); // pop get_great_warriors results
	}

	lua_close(lstate);
	return EXIT_SUCCESS;
}


void print_stack(lua_State* lstate, const int nresults)
{
	for (int i = 0; i < nresults; ++i)
		printf("[%d] = %s\n", i, lua_tostring(lstate, -(i)-1));
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

int get_global_function(lua_State* const lstate, const char* const fname)
{
	lua_getglobal(lstate, fname);
	if (lua_isfunction(lstate, -1))
		return 1;

	lua_pop(lstate, 1);
	return 0;
}

int protected_call(lua_State* const lstate, const int nargs)
{
	const int top_before = lua_gettop(lstate) - nargs - 1;
	if (lua_pcall(lstate, nargs, LUA_MULTRET, 0) != LUA_OK) {
		printf("lua_pcall failed: %s\n", lua_tostring(lstate, -1));
		lua_pop(lstate, -1);
		return -1;
	}
	return lua_gettop(lstate) - top_before;
}

double pop_number(lua_State* const lstate)
{
	const double num = lua_tonumber(lstate, -1);
	lua_pop(lstate, 1);
	return num;
}


size_t pop_str(lua_State* const lstate, char* const buffer, const size_t buffer_size) 
{
	const char* str = lua_tostring(lstate, -1);
	const size_t str_size = strlen(str);
	if (str_size > buffer_size)
		return str_size;
	memcpy(buffer, str, sizeof(char) * str_size);
	lua_pop(lstate, 1);
	return 0;
}


