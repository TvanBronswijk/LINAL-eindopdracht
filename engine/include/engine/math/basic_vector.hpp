#pragma once
#include <array>
#include "types.hpp"

namespace math {
	template<class T, size_t Rows>
	struct uvector {
	public:
		uvector() = default;
		uvector(std::array<T, Rows> values) : _values(values) {};
		~uvector() = default;
		T& operator[](size_t index){ return _values[index]; }
		const T& operator[](size_t index) const { return _values[index]; }
		uvector<T, Rows>& operator+=(const uvector<T, Rows>& r) { for (size_t i = 0; i < Rows; i++) _values[i] += r[i]; return *this; }
		uvector<T, Rows>& operator-=(const uvector<T, Rows>& r) { for (size_t i = 0; i < Rows; i++) _values[i] -= r[i]; return *this; }
		uvector<T, Rows>& operator*=(const uscalar<T>& r) { for (size_t i = 0; i < Rows; i++) _values[i] *= r; return *this; }
		uvector<T, Rows>& operator/=(const uscalar<T>& r) { for (size_t i = 0; i < Rows; i++) _values[i] *= r; return *this; }
		friend bool operator==(const uvector<T, Rows>&, const uvector<T, Rows>&);
		friend bool operator!=(const uvector<T, Rows>&, const uvector<T, Rows>&);
	protected:
		std::array<T, Rows> _values;
	};
	template<class T, size_t Rows> uvector<T, Rows> operator + (const uvector<T, Rows>& l, const uvector<T, Rows>& r) { uvector<T, Rows> result(l); result += r; return result; };
	template<class T, size_t Rows> uvector<T, Rows> operator - (const uvector<T, Rows>& l, const uvector<T, Rows>& r) { uvector<T, Rows> result(l); result -= r; return result; };
	template<class T, size_t Rows> uvector<T, Rows> operator * (uscalar<T> l, const uvector<T, Rows>& r) { uvector<T, Rows> result(r); result *= l; return result; };
	template<class T, size_t Rows> uvector<T, Rows> operator * (const uvector<T, Rows>& l, uscalar<T> r) { uvector<T, Rows> result(l); result *= r; return result; };
	template<class T, size_t Rows> uvector<T, Rows> operator / (const uvector<T, Rows>& l, uscalar<T> r) { uvector<T, Rows> result(l); result /= r; return result; };
	template<class T, size_t Rows> bool operator==(const uvector<T, Rows>& l, const uvector<T, Rows>& r) { for (int i = 0; i < Rows; i++) if (l[i] != r[i]) return false; return true; }
	template<class T, size_t Rows> bool operator!=(const uvector<T, Rows>& l, const uvector<T, Rows>& r) { return !(l == r); }
}
