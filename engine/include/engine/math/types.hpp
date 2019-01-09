#pragma once
#include <cassert>
#include <vector>

namespace math {
	//PI
	constexpr float pi = 3.14159265358979323846f;

	//Scalar
	template<class T>
	using uscalar = T;
	using scalar = uscalar<float>;

	//Radial
	template<class T>
	using uradian = T;
	using radian = uradian<float>;

	template<class T>
	uradian<T> deg_to_rad(T deg) { return deg * (pi / 180.0f); };

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
				T num = 0;
				for (size_t i = 0; i < l.columns(); i++)
					num += l(ri, i) * r(i, ci);
				result(ri, ci) = num;
			}
		}
		return result;
	}

	template<class T>
	umatrix<T> scale(T sx, T sy) {
		return umatrix<T>{{
			{sx, 0,  0},
			{0,  sy, 0},
			{0,  0,  1}
		}};
	}
	template<class T>
	umatrix<T> scale(const uvector2d<T>& sv) { return scale(sv.x, sv.y); }
	template<class T>
	umatrix<T>& scale(umatrix<T>& m, T sx, T sy) {
		umatrix<T> sm = {{
			{sx, 0,  0},
			{0,  sy, 0},
			{0,  0,  1}
		}};
		m = sm * m;
		return m;
	}
	template<class T>
	umatrix<T>& scale(umatrix<T>& m, const uvector2d<T>& sv) { return scale(m, sv.x, sv.y); }

	template<class T>
	umatrix<T> translate(T tx, T ty) {
		return umatrix<T>{{
			{1,  0, tx},
			{0,  1, ty},
			{0,  0,  1}
		}};
	}
	template<class T>
	umatrix<T> translate(const uvector2d<T>& tv) { return translate(tv.x, tv.y); }
	template<class T>
	umatrix<T>& translate(umatrix<T>& m, T tx, T ty) {
		umatrix<T> tm = {{
			{1,  0, tx},
			{0,  1, ty},
			{0,  0,  1}
		}};
		m = tm * m;
		return m;
	}
	template<class T>
	umatrix<T>& translate(umatrix<T>& m, const uvector2d<T>& tv) { return translate(m, tv.x, tv.y); }

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
	umatrix<T>& rotate(umatrix<T>& m, T deg, uvector2d<T> ov) {
		return rotate(m, deg, ov.x, ov.y);
	}


	using matrix = umatrix<float>;
}
