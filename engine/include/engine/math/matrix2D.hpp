#pragma once
#include "basic_matrix.hpp"
#include "vector2D.hpp"

namespace math {
	template<class T> using umatrix2D = umatrix<T, 3>;

	template<class T> uvector2D<T> operator * (const umatrix2D<T>& l, const uvector2D<T>& r) {
		uvector2D<T> result(r);
		for (int i = 0; i < l.rows(); i++)
			result.x *= l(i, 0);
		for (int i = 0; i < l.rows(); i++)
			result.y *= l(i, 1);
		return result;
	}
}
