#pragma once

namespace math {
	using scalar = float;

	template<class T>
	struct point {
		const T x, y;
		point(T x, T y) : x(x), y(y) {}
		~point() = default;
	};

	template<class T>
	struct vector {
		T x, y;
		vector(T x, T y) : x(x), y(y) {};
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
		~vector() = default;
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
	struct rectangle {
		const T x, y, w, h, x1, y1, x2, y2;
		rectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h), x1(x), y1(y), x2(x + w), y2(y + h) {}
		point<T> origin() const { return {x1, y1}; }
		point<T> center() const { return {x+w/2, y+h/2}; }
		point<T> end() const { return {x2, y2}; }
		~rectangle() = default;
	};

	template<class T>
	struct matrix {
	private:
		size_t _r;
		size_t _c;
		T* _arr;
	public:
		matrix(size_t rows, size_t columns) : _r(rows), _c(columns), _arr(new T[rows*columns]) {}
		T& at(size_t r, size_t c) const { return operator()(r, c); }
		T& operator()(size_t r, size_t c) const { return _arr[r * _c + c]; }
		~matrix() { delete[] _arr; }
	};
}
