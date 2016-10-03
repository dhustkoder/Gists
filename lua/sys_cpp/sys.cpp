#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <exception>
#include <string>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

template<class T>
constexpr const bool is_numeric_v = std::conditional_t<std::is_floating_point<T>::value
                                   || std::is_integral<T>::value,
				   std::true_type, std::false_type>::value;
template<class T>
constexpr const bool is_string_v = std::conditional_t<std::is_convertible<char*, T>::value,
                                     std::true_type, std::false_type>::value;


class LuaState 
{
public:
	LuaState();
	~LuaState();
	void DoFile(const char* file_name);
	template<class T>
	std::enable_if_t<is_numeric_v<T>, T>  Read(int idx) const noexcept;
	template<class T>
	std::enable_if_t<is_string_v<T>, std::string>  Read(int idx) const noexcept;
	template<class T>
	auto Pop() noexcept;
	void Push(double val);
	void Push(const char* str);
	template<class ...Args>
	int ProtectedCall(const char* func, Args&& ...args);
private:
	void PushArgs(){}
	template<class T>
	void PushArgs(T&& arg);
	template<class T, class ...Args>
	void PushArgs(T&& arg, Args&& ...args);
	
	lua_State* const m_l;
};

inline LuaState::LuaState()
	: m_l(luaL_newstate())
{
	if (m_l) {
		luaL_openlibs(m_l);
	} else {
		throw std::runtime_error("Failed to create new Lua State");
	}
}

inline LuaState::~LuaState()
{
	lua_close(m_l);
}


inline void LuaState::Push(const double val)
{
	lua_pushnumber(m_l, val);
}


inline void LuaState::Push(const char* str)
{
	lua_pushstring(m_l, str);
}

template<class T>
void LuaState::PushArgs(T&& arg)
{
	Push(std::forward<T>(arg));
}

template<class T, class ...Args>
void LuaState::PushArgs(T&& arg, Args&& ...args)
{
	Push(std::forward<T>(arg));
	PushArgs(std::forward<Args>(args)...);
}


template<class T>
inline std::enable_if_t<is_numeric_v<T>, T> LuaState::Read(const int idx) const noexcept
{
	return lua_tonumber(m_l, idx);
}

template<class T>
inline std::enable_if_t<is_string_v<T>, std::string> LuaState::Read(const int idx) const noexcept
{
	const auto str = lua_tostring(m_l, idx);
	return str != nullptr ? str : "";
}


template<class T>
inline auto LuaState::Pop() noexcept
{
	auto val = Read<T>(-1);
	lua_pop(m_l, 1);
	return val;
}


inline void LuaState::DoFile(const char* const file_name)
{
	using namespace std::string_literals;
	if (luaL_dofile(m_l, file_name) != 0) {
		const auto errmsg = Pop<const char*>();
		throw std::runtime_error("luaL_dofile failed: "s + errmsg);
	}
}



template<class ...Args>
int LuaState::ProtectedCall(const char* const func, Args&& ...args)
{
	constexpr const auto nargs = sizeof...(Args);
	static_assert(static_cast<int>(nargs) == nargs, "");
	lua_getglobal(m_l, func);
	PushArgs(std::forward<Args>(args)...);
	const auto top_before = lua_gettop(m_l) - nargs - 1;
	lua_pcall(m_l, static_cast<int>(nargs), LUA_MULTRET, 0);
	return lua_gettop(m_l) - top_before;
}


int main()
{
	try {
		LuaState lua;
		lua.DoFile("hello.lua");
		lua.DoFile("functions.lua");
		const auto call = [&](const char* fun, auto&& ...args) {
			const auto nresults = lua.ProtectedCall(fun, std::forward<decltype(args)>(args)...);
			std::cout << fun << " results:\n";
			for (int i = 1; i <= nresults; ++i)
				std::cout << '[' << i << "] = " << lua.Pop<std::string>() << '\n';
		};
		
		call("sum", 20, 22);
		call("get_great_warriors");

	} catch (std::exception& e) {
		std::cout << "Fatal Exception: " << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


