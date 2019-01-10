#pragma once
#include "types.hpp"
#include "vector3D.hpp"
#include "matrix3D.hpp"

namespace math {
	template<class T> umatrix3D<T> scale(uvector3D<T> sv) {
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ sv.x, 0, 0, 0},
			{ 0,    sv.y, 0,    0 },
			{ 0,    0,    sv.z, 0 },
			{ 0,    0,    0,    1 }
			}};
	}

	template<class T> umatrix3D<T> scale(const umatrix3D<T>& m, uvector3D<T> sv) {
		umatrix3D<T> sm = scale(sv);
		sm = sm * m;
		return sm;
	}

	template<class T> umatrix3D<T> translate(uvector3D<T> tv) {
		return umatrix3D<T>::multidimensional_constructor<4>{ {
			{ 1, 0, 0, tv.x },
			{ 0, 1, 0, tv.y },
			{ 0, 0, 1, tv.z },
			{ 0, 0, 0, 1 }
			}};
	}
	template<class T> umatrix3D<T> translate(const umatrix3D<T>& m, uvector3D<T> tv) {
		umatrix3D<T> tm = translate(tv);
		tm = tm * m;
		return tm;
	}

	template<class T> umatrix3D<T> rotate(uvector3D<T> dv) { //TODO
		uradian<T> xrad = deg_to_rad(dv.x);
		uradian<T> yrad = deg_to_rad(dv.y);
		uradian<T> zrad = deg_to_rad(dv.z);

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

	template<class T> umatrix3D<T> rotate(const umatrix3D<T>& m, uvector3D<T> dv) {
		umatrix3D<T> rm = rotate(dv);
		rm = rm * m;
		return rm;
	}
}
