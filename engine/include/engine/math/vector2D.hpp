#pragma once
#include "basic_vector.hpp"

namespace math {
	template<class T>
	struct uvector2D : public uvector<T, 3> {
		uvector2D() : uvector{ {T(0), T(0), T(0)} } {};
		uvector2D(T x, T y) : uvector{ {x, y, T(0)} } {};
		uvector2D(T x, T y, T w) : uvector{ {x, y, w} } {};
		uvector2D(const uvector<T, 3>& v) : uvector(v) {};
		uvector2D& operator=(const uvector<T, 3>& v) { for (int i = 0; i < 3; i++) _values[i] = v[i]; return *this; }
		T& x() { return _values[0]; }
		const T& x() const { return _values[0]; }
		T& y() { return _values[1]; }
		const T& y() const { return _values[1]; }
		T& w() { return _values[2]; }
		const T& w() const { return _values[2]; }
		~uvector2D() = default;
	};
}
