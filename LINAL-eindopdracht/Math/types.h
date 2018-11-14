#pragma once

namespace math {
	using scalar = float;

	template<class T>
	struct point {
		T x, y;
		point(T x, T y) : x(x), y(y) {}
		~point() = default;
	};

	template<class T>
	struct vector {
		T x, y;
		vector(T x, T y) : x(x), y(y) {};
		vector operator*(scalar s) { return {x*s, y*s}; }
		vector operator+(const vector& v) { return {x+v.x, y+v.y}; }
		vector operator-(const vector& v) { return {x-v.x, y-v.y}; }
		~vector() = default;
	};

	template<class T>
	struct rectangle {
		T x, y, w, h, x1, y1, x2, y2;
		rectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h), x1(x), y1(y), x2(x + w), y2(y + h) {}
		point<T> origin() { return {x1, y1}; }
		point<T> center() { return {x+w/2, y+h/2}; }
		~rectangle() = default;
	};
}
