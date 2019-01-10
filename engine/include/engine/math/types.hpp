#pragma once

namespace math {
	//PI
	constexpr float pi = 3.14159265358979323846f;

	//Scalar
	template<class T> using uscalar = T;

	//Radial
	template<class T> using uradian = T;
	template<class T> uradian<T> deg_to_rad(T deg) { return deg * (pi / 180.0f); };
}
