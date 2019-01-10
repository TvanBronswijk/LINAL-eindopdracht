#pragma once
#include "basic_matrix.hpp"
#include "vector3D.hpp"

namespace math {
	template<class T> using umatrix3D = umatrix<T, 4>;

	template<class T> uvector3D<T> operator * (const umatrix3D<T>& l, const uvector3D<T>& r) {
		uvector3D<T> result(r);
		for (int i = 0; i < l.rows(); i++)
			result.x *= l(i, 0);
		for (int i = 0; i < l.rows(); i++)
			result.y *= l(i, 1);
		for (int i = 0; i < l.rows(); i++)
			result.z *= l(i, 2);
		return result;
	}
}
