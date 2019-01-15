#pragma once

namespace rendering::rendering3d {
	template<class T>
	struct view {
		T first;
		T second;
		view() : first(T(0)), second(T(0)) {}
		view(T first, T second) : first(first), second(second) {}
		static const view xy;
		static const view yz;
		static const view xz;
	};
	template<class T> const view<T> view<T>::xy = view<T>{ T(0), T(1) };
	template<class T> const view<T> view<T>::yz = view<T>{ T(1), T(2) };
	template<class T> const view<T> view<T>::xz = view<T>{ T(0), T(2) };
}
