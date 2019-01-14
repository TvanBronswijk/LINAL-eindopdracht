#pragma once

namespace rendering {
	template<class T>
	struct upoint {
		T x, y;
		upoint() = default;
		upoint(T x, T y) : x(x), y(y) {}
		~upoint() = default;
	};
	using point = upoint<int>;

	template<class T>
	struct urectangle {
		T x, y, w, h, x1, y1, x2, y2;
		urectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h), x1(x), y1(y), x2(x + w), y2(y + h) {}
		~urectangle() = default;
		upoint<T> origin() const { return { x1, y1 }; }
		upoint<T> center() const { return { x + w / 2, y + h / 2 }; }
		upoint<T> end() const { return { x2, y2 }; }
	};
	using rectangle = urectangle<int>;
};
