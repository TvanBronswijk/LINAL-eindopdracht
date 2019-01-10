#pragma once
#include <cassert>
#include <vector>
#include <array>

namespace math {
	template<class T, size_t Rows>
	struct umatrix {
	public:
		template<size_t Columns> using multidimensional_constructor = std::array<std::array<T, Columns>, Rows>;
		template<size_t Columns> umatrix(multidimensional_constructor<Columns> matrix) : umatrix(Columns) {
			for (int xi = 0; xi < Rows; xi++)
				for (int yi = 0; yi < Columns; yi++)
					this->at(xi, yi) = matrix[xi][yi];
		}
		umatrix(size_t columns) : _rows(Rows), _columns(columns), _collection(std::vector<T>(Rows*columns)) { assert(Rows > 0); assert(columns > 0); }
		~umatrix() = default;
		size_t rows() const { return _rows; }
		size_t columns() const { return _columns; }
		T& at(size_t r, size_t c) { return _collection[r * columns() + c]; }
		const T& at(size_t r, size_t c) const { return _collection[r * columns() + c]; }
		T& operator () (size_t r, size_t c) { return at(r, c); }
		const T& operator () (size_t r, size_t c) const { return at(r, c); }

		umatrix<T, Rows>& operator += (const umatrix<T, Rows>& r) {
			assert(columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) += r(ri, ci);
			return *this;
		}
		umatrix<T, Rows>& operator -= (const umatrix<T, Rows>& r) {
			assert(columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) -= r(ri, ci);
			return *this;
		}
		umatrix<T, Rows>& operator *= (const uscalar<T>& r) {
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) *= r;
			return *this;
		}
	private:
		size_t _rows;
		size_t _columns;
		std::vector<T> _collection;
	};

	template<class T, size_t Rows>
	umatrix<T, Rows> operator + (const umatrix<T, Rows>& l, const umatrix<T, Rows>& r) {
		assert(l.columns() == r.columns());
		umatrix<T, Rows> result(r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) + r(ri, ci);
		return result;
	}

	template<class T, size_t Rows>
	umatrix<T, Rows> operator - (const umatrix<T, Rows>& l, const umatrix<T, Rows>& r) {
		assert(l.columns() == r.columns());
		umatrix<T, Rows> result(r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) - r(ri, ci);
		return result;
	}

	template<class T, size_t Rows>
	umatrix<T, Rows> operator * (const uscalar<T>& l, const umatrix<T, Rows>& r) {
		umatrix<T, Rows> result(r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l * r(ri, ci);
		return result;
	}

	template<class T, size_t Rows>
	umatrix<T, Rows> operator * (const umatrix<T, Rows>& l, const uscalar<T>& r) {
		umatrix<T, Rows> result(l.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) * r;
		return result;
	}

	template<class T, size_t Rows>
	umatrix<T, Rows> operator * (const umatrix<T, Rows>& l, const umatrix<T, Rows>& r) {
		umatrix<T, Rows> result(r.columns());
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

	template<class T> using umatrix2D = umatrix<T, 3>;
	template<class T> using umatrix3D = umatrix<T, 4>;
}
