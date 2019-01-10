#pragma once
#include "types.hpp"
#include "vector2D.hpp"

namespace math {
	template<class T>
	struct uvector3D {
		T x, y, z;
		uvector3D() : x(T(0)), y(T(0)), z(T(0)) {};
		uvector3D(T x, T y, T z) : x(x), y(y), z(z) {};
		uvector3D(uvector2D<T> v, T z) : x(v.x), y(.y), z(z) {};
		~uvector3D() = default;
		uvector3D<T>& operator+=(const uvector3D<T>& r) { x += r.x; y += r.y; z += r.z; return *this; }
		uvector3D<T>& operator-=(const uvector3D<T>& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }
		uvector3D<T>& operator*=(const uscalar<T>& r) { x *= r; y *= r; z *= r; return *this; }
		uvector3D<T>& operator/=(const uscalar<T>& r) { x /= r; y /= r; z /= r; return *this; }
	};
	template<class T> uvector3D<T> operator + (const uvector3D<T>& l, const uvector3D<T>& r) { return { l.x + r.x, l.y + r.y, l.z + r.z }; };
	template<class T> uvector3D<T> operator - (const uvector3D<T>& l, const uvector3D<T>& r) { return { l.x - r.x, l.y - r.y, l.z - r.z }; };
	template<class T> uvector3D<T> operator * (uscalar<T> s, const uvector3D<T>& v) { return { s*v.x, s*v.y, s*v.z }; };
	template<class T> uvector3D<T> operator * (const uvector3D<T>& v, uscalar<T> s) { return { v.x*s, v.y*s, v.z*s }; };
	template<class T> uvector3D<T> operator / (const uvector3D<T>& v, uscalar<T> s) { return { v.x / s, v.y / s, v.z / s }; };
}
