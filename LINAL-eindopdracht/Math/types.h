#pragma once
#include <cassert>
#include <vector>

namespace math {
	using scalar = float;

	template<class T>
	struct vector {
		T x, y;
		vector(T x, T y) : x(x), y(y) {};
		~vector() = default;
		vector& operator+=(const vector& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
		vector& operator-=(const vector& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}
		vector& operator*=(const scalar& s) {
			x *= s;
			y *= s;
			return *this;
		}
	};

	template<class T>
	vector<T> operator + (const vector<T>& l, const vector<T>& r) { return { l.x+r.x, l.y+r.y }; };
	template<class T>
	vector<T> operator - (const vector<T>& l, const vector<T>& r) { return { l.x-r.x, l.y-r.y }; };
	template<class T>
	vector<T> operator * (const scalar& s, const vector<T>& v) { return { s*v.x, s*v.y }; };
	template<class T>
	vector<T> operator * (const vector<T>& v, const scalar& s) { return { v.x*s, v.y*s }; };

	template<class T>
	struct matrix {
	private:
		size_t _r;
		size_t _c;
		std::vector<T> _arr;
	public:
		matrix(size_t rows, size_t columns) : _r(rows), _c(columns), _arr(std::vector<T>(rows*columns)) {}
		~matrix() = default;
		size_t rows() const { return _r; }
		size_t columns() const { return _c; }
		T& at(size_t r, size_t c) { return _arr[r * _c + c]; }
		const T& at(size_t r, size_t c) const { return _arr[r * _c + c]; }
		T& operator () (size_t r, size_t c) { return at(r,c); }
		const T& operator () (size_t r, size_t c) const { return at(r,c); }

		matrix<T>& operator += (const matrix<T>& r) {
			assert(rows() == r.rows() && columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) += r(ri, ci);
			return *this;
		}

		matrix<T>& operator -= (const matrix<T>& r) {
			assert(rows() == r.rows() && columns() == r.columns());
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					at(ri, ci) -= r(ri, ci);
			return *this;
		}
	};

	template<class T>
	matrix<T> operator + (const matrix<T>& l, const matrix<T>& r) {
		assert(l.rows() == r.rows() && l.columns() == r.columns());
		matrix<T> result(l.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) + r(ri, ci);
		return result;
	}

	template<class T>
	matrix<T> operator - (const matrix<T>& l, const matrix<T>& r) {
		assert(l.rows() == r.rows() && l.columns() == r.columns());
		matrix<T> result(l.rows(), r.columns());
		for (size_t ri = 0; ri < result.rows(); ri++)
			for (size_t ci = 0; ci < result.columns(); ci++)
				result(ri, ci) = l(ri, ci) - r(ri, ci);
		return result;
	}
}
