#pragma once

namespace render {
	template<class T>
	struct point {
		const T x, y;
		point(T x, T y) : x(x), y(y) {}
		~point() = default;
	};

	template<class T>
	struct rectangle {
		const T x, y, w, h, x1, y1, x2, y2;
		rectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h), x1(x), y1(y), x2(x + w), y2(y + h) {}
		point<T> origin() const { return { x1, y1 }; }
		point<T> center() const { return { x + w / 2, y + h / 2 }; }
		point<T> end() const { return { x2, y2 }; }
		~rectangle() = default;
	};
};
