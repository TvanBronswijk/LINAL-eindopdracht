#pragma once
#include "types.hpp"
#include "vector3D.hpp"
#include "matrix3D.hpp"

namespace math {
	template<class T> umatrix3D<T> scale(uvector<T, 3> sv) {
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ sv[0], 0, 0, 0},
			{ 0,    sv[1], 0,    0 },
			{ 0,    0,    sv[2], 0 },
			{ 0,    0,    0,    1 }
			}};
	}

	template<class T> umatrix3D<T> scale(const umatrix3D<T>& m, uvector<T, 3> sv) {
		umatrix3D<T> sm = scale(sv);
		sm = sm * m;
		return sm;
	}

	template<class T> umatrix3D<T> translate(uvector<T, 3> tv) {
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ 1, 0, 0, tv[0] },
			{ 0, 1, 0, tv[1] },
			{ 0, 0, 1, tv[2] },
			{ 0, 0, 0, 1 }
			}};
	}
	template<class T> umatrix3D<T> translate(const umatrix3D<T>& m, uvector<T, 3> tv) {
		umatrix3D<T> tm = translate(tv);
		tm = tm * m;
		return tm;
	}
	template<class T> umatrix3D<T> rotate_x(uradian<T> r) {
		uradian<T> rad = deg_to_rad(r);
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ 1, 0, 0, 0 },
			{ 0, cos(rad), -sin(rad), 0 },
			{ 0, sin(rad), cos(rad), 0},
			{ 0, 0, 0, 1}
			} };
	}
	template<class T> umatrix3D<T> rotate_y(uradian<T> r) {
		uradian<T> rad = deg_to_rad(r);
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ cos(rad), 0, sin(rad), 0 },
			{ 0, 1, 0, 0 },
			{ -sin(rad), 0, cos(rad), 0 },
			{ 0, 0, 0, 1 }
			} };
	}
	template<class T> umatrix3D<T> rotate_z(uradian<T> r) {
		uradian<T> rad = deg_to_rad(r);
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ cos(rad), sin(rad), 0, 0 },
			{ -sin(rad), cos(rad), 0, 0 },
			{ 0, 0, 1, 0},
			{ 0, 0, 0, 1}
			} };
	}

	template<class T> umatrix3D<T> rotate(uvector<T, 3> dv) {
		return rotate_z(dv[2]) * rotate_y(dv[1]) * rotate_x(dv[0]);
	}

	template<class T> umatrix3D<T> rotate(const umatrix3D<T>& m, uvector<T, 3> dv) {
		umatrix3D<T> rm = rotate(dv);
		rm = rm * m;
		return rm;
	}
}
