#pragma once
#include <cassert>
#include <vector>
#include "vector2D.hpp"

namespace math {
	template<class T>
	struct umatrix {
		template<class T>
		using matrix_collection = std::vector<std::vector<T>>;
	private:
		size_t _r;
		size_t _c;
		std::vector<T> _arr;
	public:
		umatrix(matrix_collection<T> matrix)
			: umatrix(matrix.size(), matrix[0].size(), matrix) {}
		umatrix(size_t rows, size_t columns, matrix_collection<T> matrix)
			: umatrix(rows, columns) {
			for (size_t ri = 0; ri < rows; ri++)
				for (size_t ci = 0; ci < columns; ci++)
					at(ri, ci) = matrix[ri][ci];
		}
		umatrix(size_t rows, size_t columns)
			: _r(rows), _c(columns), _arr(std::vector<T>(rows*columns)) {
			assert(rows > 0);
			assert(columns > 0);
		}
		~umatrix() = default;
		size_t rows() const { return _r; }
		size_t columns() const { return _c; }
		T& at(size_t r, size_t c) { return _arr[r * _c + c]; }
		const T& at(size_t r, size_t c) const { return _arr[r * _c + c]; }
		T& operator () (size_t r, size_t c) { return at(r, c); }
		const T& operator () (size_t r, size_t c) const { return at(r, c); }

		umatrix<T>& operator += (const umatrix<T>& r) {
			assert(rows() == r.rows() && columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) += r(ri, ci);
			return *this;
		}
		umatrix<T>& operator -= (const umatrix<T>& r) {
			assert(rows() == r.rows() && columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) -= r(ri, ci);
			return *this;
		}
		umatrix<T>& operator *= (const uscalar<T>& r) {
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) *= r;
			return *this;
		}
	};

	template<class T>
	umatrix<T> operator + (const umatrix<T>& l, const umatrix<T>& r) {
		assert(l.rows() == r.rows() && l.columns() == r.columns());
		umatrix<T> result(l.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) + r(ri, ci);
		return result;
	}

	template<class T>
	umatrix<T> operator - (const umatrix<T>& l, const umatrix<T>& r) {
		assert(l.rows() == r.rows() && l.columns() == r.columns());
		umatrix<T> result(l.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) - r(ri, ci);
		return result;
	}

	template<class T>
	umatrix<T> operator * (const uscalar<T>& l, const umatrix<T>& r) {
		umatrix<T> result(r.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l * r(ri, ci);
		return result;
	}

	template<class T>
	umatrix<T> operator * (const umatrix<T>& l, const uscalar<T>& r) {
		umatrix<T> result(l.rows(), l.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) * r;
		return result;
	}

	template<class T>
	umatrix<T> operator * (const umatrix<T>& l, const umatrix<T>& r) {
		umatrix<T> result(l.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++) {
			for (size_t ci = 0; ci < result.columns(); ci++) {
				T num = 0;
				for (size_t i = 0; i < l.columns(); i++)
					num += l(ri, i) * r(i, ci);
				result(ri, ci) = num;
			}
		}
		return result;
	}

	using matrix = umatrix<float>;
}
