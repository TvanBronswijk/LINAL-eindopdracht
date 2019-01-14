#pragma once
#include "basic_vector.hpp"

namespace math {
	template<class T>
	struct uvector3D : public uvector<T, 4> {
		uvector3D() : uvector{ T(0), T(0), T(0) } {};
		uvector3D(T x, T y, T z) : uvector{ { x, y, z, T(0) } } {};
		uvector3D(T x, T y, T z, T w) : uvector{ { x, y, z, w } } {};
		T& x() { return _values[0]; }
		const T& x() const { return _values[0]; }
		T& y() { return _values[1]; }
		const T& y() const { return _values[1]; }
		T& z() { return _values[2]; }
		const T& z() const { return _values[2]; }
		T& w() { return _values[3]; }
		const T& w() const { return _values[3]; }
	};

	template<class T> uscalar<T> dot(const uvector3D<T>& l, const uvector3D<T>& r) { return l.x()*r.x() + l.y()*r.y() + l.z()*r.z(); }
	template<class T> uvector3D<T> cross(const uvector3D<T>& l, const uvector3D<T>& r) { return {l.y()*r.z() - l.z()*r.y(), l.z()*r.x() - l.x()*r.z(), l.x()*r.y() - l.y()*r.x()}; }
	template<class T> uvector3D<T> normalize(const uvector3D<T>& l, const uvector3D<T>& r) { uscalar<T> l = std::sqrt(dot(l, r)); return {}; } //TODO
}
