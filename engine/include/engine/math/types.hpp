#pragma once

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
}
