#pragma once
#include "types.hpp"
#include "vector2D.hpp"
#include "vector3D.hpp"
#include "matrix.hpp"

namespace math {
	template<class T>
	umatrix<T> scale(T sx, T sy) {
		return umatrix<T>{ {
			{sx, 0, 0},
			{ 0,  sy, 0 },
			{ 0,  0,  1 }
			}};
	}
	template<class T>
	umatrix<T> scale(const uvector2D<T>& sv) { return scale(sv.x, sv.y); }
	template<class T>
	umatrix<T>& scale(umatrix<T>& m, T sx, T sy) {
		umatrix<T> sm = { {
			{sx, 0,  0},
			{0,  sy, 0},
			{0,  0,  1}
		} };
		m = sm * m;
		return m;
	}
	template<class T>
	umatrix<T>& scale(umatrix<T>& m, const uvector2D<T>& sv) { return scale(m, sv.x, sv.y); }

	template<class T>
	umatrix<T> translate(T tx, T ty) {
		return umatrix<T>{ {
			{1, 0, tx},
			{ 0,  1, ty },
			{ 0,  0,  1 }
			}};
	}
	template<class T>
	umatrix<T> translate(const uvector2D<T>& tv) { return translate(tv.x, tv.y); }
	template<class T>
	umatrix<T>& translate(umatrix<T>& m, T tx, T ty) {
		umatrix<T> tm = { {
			{1,  0, tx},
			{0,  1, ty},
			{0,  0,  1}
		} };
		m = tm * m;
		return m;
	}
	template<class T>
	umatrix<T>& translate(umatrix<T>& m, const uvector2D<T>& tv) { return translate(m, tv.x, tv.y); }

	template<class T>
	umatrix<T>& rotate(umatrix<T>& m, T deg) {
		uradian<T> rad = deg_to_rad(deg);
		umatrix<T> rm = { {
			{cos(rad),  sin(rad), 0},
			{-sin(rad),  cos(rad), 0},
			{0,  0, 1}
		} };
		m = rm * m;
		return m;
	}

	template<class T>
	umatrix<T>& rotate(umatrix<T>& m, T deg, T ox, T oy) {
		uradian<T> rad = deg_to_rad(deg);
		translate(m, -ox, -oy);
		umatrix<T> rm = { {
			{cos(rad),  sin(rad), 0},
			{-sin(rad),  cos(rad), 0},
			{0,  0, 1}
		} };
		m = rm * m;
		translate(m, ox, oy);
		return m;
	}

	template<class T>
	umatrix<T>& rotate(umatrix<T>& m, T deg, uvector2D<T> ov) {
		return rotate(m, deg, ov.x, ov.y);
	}
}

