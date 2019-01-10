#pragma once
#include "types.hpp"

namespace math {
	template<class T>
	struct uvector2D {
		T x, y;
		uvector2D() : x(T(0)), y(T(0)) {};
		uvector2D(T x, T y) : x(x), y(y) {};
		~uvector2D() = default;
		uvector2D<T>& operator+=(const uvector2D<T>& r) { x += r.x; y += r.y; return *this; }
		uvector2D<T>& operator-=(const uvector2D<T>& r) { x -= r.x; y -= r.y; return *this; }
		uvector2D<T>& operator*=(uscalar<T> r) { x *= r; y *= r; return *this; }
		uvector2D<T>& operator/=(uscalar<T> r) { x /= r; y /= r; return *this; }
	};
	template<class T> uvector2D<T> operator + (const uvector2D<T>& l, const uvector2D<T>& r) { return { l.x + r.x, l.y + r.y }; };
	template<class T> uvector2D<T> operator - (const uvector2D<T>& l, const uvector2D<T>& r) { return { l.x - r.x, l.y - r.y }; };
	template<class T> uvector2D<T> operator * (uscalar<T> s, const uvector2D<T>& v) { return { s*v.x, s*v.y }; };
	template<class T> uvector2D<T> operator * (const uvector2D<T>& v, uscalar<T> s) { return { v.x*s, v.y*s }; };
	template<class T> uvector2D<T> operator / (const uvector2D<T>& v, uscalar<T> s) { return { v.x/s, v.y/s }; };
}
