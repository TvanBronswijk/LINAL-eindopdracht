#pragma once
#include "types.hpp"
#include "vector2D.hpp"
#include "matrix2D.hpp"

namespace math {
	template<class T> umatrix2D<T> scale(uvector2D<T> sv) {
		return umatrix2D<T>::multidimensional_constructor<3>{{
			{ sv.x(), 0,    0 },
			{ 0,    sv.y(), 0 },
			{ 0,    0,    1 }
		}};
	}

	template<class T> umatrix2D<T> scale(const umatrix2D<T>& m, uvector2D<T> sv) {
		umatrix2D<T> sm = scale(sv);
		sm = sm * m;
		return sm;
	}

	template<class T> umatrix2D<T> translate(uvector2D<T> tv) {
		return umatrix2D<T>::multidimensional_constructor<3>{{
			{ 1, 0, tv.x() },
			{ 0, 1, tv.y() },
			{ 0, 0, 1    }
		}};
	}
	template<class T> umatrix2D<T> translate(const umatrix2D<T>& m, uvector2D<T> tv) {
		umatrix2D<T> tm = translate(tv);
		tm = tm * m;
		return tm;
	}

	template<class T> umatrix2D<T> rotate(T deg) {
		uradian<T> rad = deg_to_rad(deg);
		return umatrix2D<T>::multidimensional_constructor<3>{ {
			{cos(rad),  sin(rad), 0},
			{-sin(rad), cos(rad), 0},
			{0,			0,		  1}
		} };
	}

	template<class T> umatrix2D<T> rotate(const umatrix2D<T>& m, T deg) {
		umatrix2D<T> rm = rotate(deg);
		rm = rm * m;
		return rm;
	}
}

