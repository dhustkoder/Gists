#ifndef GAMEBOY_APU_PROTOTYPE_FINALLY_HPP_
#define GAMEBOY_APU_PROTOTYPE_FINALLY_HPP_

template<class F>
struct Finally {
	Finally(F&& f) 
		: m_f(static_cast<F&&>(f))
	{
	}
	~Finally() 
	{
		m_f();
	}
	const F m_f;
};

template<class F>
constexpr Finally<F> finally(F&& f)
{
	return Finally<F>(static_cast<F&&>(f));
} 

#endif
