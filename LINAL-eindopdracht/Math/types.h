#pragma once
#include <cassert>
#include <vector>

namespace math {
	//Scalar
	template<class T>
	using uscalar = T;
	using scalar = uscalar<float>;

	//Vector
	template<class T>
	struct uvector2d {
		T x, y;
		uvector2d(T x, T y) : x(x), y(y) {};
		~uvector2d() = default;
		uvector2d<T>& operator+=(const uvector2d<T>& r) {
			x += r.x;
			y += r.y;
			return *this;
		}
		uvector2d<T>& operator-=(const uvector2d<T>& r) {
			x -= r.x;
			y -= r.y;
			return *this;
		}
		uvector2d<T>& operator*=(const uscalar<T>& r) {
			x *= r;
			y *= r;
			return *this;
		}
	};
	template<class T>
	uvector2d<T> operator + (const uvector2d<T>& l, const uvector2d<T>& r) { return { l.x + r.x, l.y + r.y }; };
	template<class T>
	uvector2d<T> operator - (const uvector2d<T>& l, const uvector2d<T>& r) { return { l.x - r.x, l.y - r.y }; };
	template<class T>
	uvector2d<T> operator * (const uscalar<T>& s, const uvector2d<T>& v) { return { s*v.x, s*v.y }; };
	template<class T>
	uvector2d<T> operator * (const uvector2d<T>& v, const uscalar<T>& s) { return { v.x*s, v.y*s }; };

	using vector2d = uvector2d<float>;

	//Matrix
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
		matrix_collection<T> get() {
			matrix_collection<T> result;
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					result[ri][ci] = at(ri, ci);
			return result;
		}
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
				T lrow = 1;
				for (size_t i = 0; i < l.columns(); i++)
					lrow *= l(ri, i);
				T rcol = 1;
				for (size_t i = 0; i < l.columns(); i++)
					rcol *= r(i, ci);
				result(ri, ci) = lrow + rcol;
			}
		}
		return result;
	}

	using matrix = umatrix<float>;
}
