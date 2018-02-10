/*
Implementation of a constexpr string
Visual Studio 2017 doesn't implement constexpr length 
in char_traits. This should be updated in the Tools Update 1

Taken from: http://en.cppreference.com/w/cpp/concept/LiteralType
*/
#pragma once
#include <stdexcept>

class conststr
{
public:
	constexpr conststr() : _p{}, _sz(0) {}

	template<std::size_t N>
	constexpr conststr(const char(&a)[N]) : _p(a), _sz(N - 1) {}

	constexpr conststr(const conststr& cs) 
		: _p(cs._p)
		, _sz(cs._sz)
	{

	}

	constexpr char operator[](std::size_t n) const {
		return n < _sz ? _p[n] : throw std::out_of_range("");
	}

	constexpr std::size_t size() const { return _sz; }
private:
	const char* _p;
	std::size_t _sz;
};