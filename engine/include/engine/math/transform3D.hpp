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

	template<class T> umatrix3D<T> rotate(uvector<T, 3> dv) {
		uradian<T> xrad = deg_to_rad(dv[0]);
		uradian<T> yrad = deg_to_rad(dv[1]);
		uradian<T> zrad = deg_to_rad(dv[2]);

		umatrix3D<T> xrot = umatrix3D<T>::multidimensional_constructor<4>{ {
			{ 1, 0, 0, 0 },
			{ 0, cos(xrad), -sin(xrad), 0 },
			{ 0, sin(xrad), cos(xrad), 0},
			{ 0, 0, 0, 1}
			} };

		umatrix3D<T> yrot = umatrix3D<T>::multidimensional_constructor<4>{ {
			{ cos(yrad), 0, sin(yrad), 0 },
			{ 0, 1, 0, 0 },
			{ -sin(yrad), 0, cos(yrad), 0},
			{ 0, 0, 0, 1}
			} };

		umatrix3D<T> zrot = umatrix3D<T>::multidimensional_constructor<4>{ {
			{ cos(zrad), sin(zrad), 0, 0 },
			{ -sin(zrad), cos(zrad), 0, 0 },
			{ 0, 0, 1, 0},
			{ 0, 0, 0, 1}
			} };

		return zrot * yrot * xrot;
	}

	template<class T> umatrix3D<T> rotate(const umatrix3D<T>& m, uvector<T, 3> dv) {
		umatrix3D<T> rm = rotate(dv);
		rm = rm * m;
		return rm;
	}
}
