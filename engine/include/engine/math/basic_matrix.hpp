#pragma once
#include <cassert>
#include <functional>
#include <vector>
#include <array>
#include <ostream>
#include "basic_vector.hpp"

namespace math {
	template<class T, size_t Rows>
	struct umatrix {
	public:
		template<size_t Columns> using multidimensional_constructor = std::array<std::array<T, Columns>, Rows>;
		template<size_t Columns> umatrix(multidimensional_constructor<Columns> matrix) : umatrix(Columns) {
			for (int xi = 0; xi < Rows; xi++)
				for (int yi = 0; yi < Columns; yi++)
					this->at(xi, yi) = matrix[xi][yi];
		}
		umatrix(size_t columns) : _rows(Rows), _columns(columns), _collection(std::vector<T>(Rows*columns)) { assert(Rows > 0); assert(columns > 0); }
		~umatrix() = default;
		size_t rows() const { return _rows; }
		size_t columns() const { return _columns; }
		T& at(size_t r, size_t c) { return _collection[r * columns() + c]; }
		const T& at(size_t r, size_t c) const { return _collection[r * columns() + c]; }
		T& operator () (size_t r, size_t c) { return at(r, c); }
		const T& operator () (size_t r, size_t c) const { return at(r, c); }
		void foreach(std::function<void(T&)> func) {
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					func(at(ri, ci));
		}
		void foreach(std::function<void(T&, size_t, size_t)> func) {
			for (size_t ri = 0; ri < rows(); ri++)
				for (size_t ci = 0; ci < columns(); ci++)
					func(at(ri, ci), ri, ci);
		}

		umatrix<T, Rows>& operator += (const umatrix<T, Rows>& r) {
			assert(columns() == r.columns());
			foreach([&](auto& val, auto ri, auto ci) { val += r(ri, ci); });
			return *this;
		}
		umatrix<T, Rows>& operator -= (const umatrix<T, Rows>& r) {
			assert(columns() == r.columns());
			foreach([&](auto& val, auto ri, auto ci) { val -= r(ri, ci); });
			return *this;
		}
		umatrix<T, Rows>& operator *= (uscalar<T> r) { foreach([&](auto& val) { val *= r; }); return *this; }
		umatrix<T, Rows>& operator /= (uscalar<T> r) { foreach([&](auto& val) { val /= r; }); return *this; }
	private:
		size_t _rows;
		size_t _columns;
		std::vector<T> _collection;
	};

	template<class T, size_t Rows> umatrix<T, Rows> operator + (const umatrix<T, Rows>& l, const umatrix<T, Rows>& r) {
		assert(l.columns() == r.columns());
		umatrix<T, Rows> result(r.columns());
		result.foreach([&](auto& val, auto ri, auto ci) { val = l(ri, ci) + r(ri, ci); });
		return result;
	}

	template<class T, size_t Rows> umatrix<T, Rows> operator - (const umatrix<T, Rows>& l, const umatrix<T, Rows>& r) {
		assert(l.columns() == r.columns());
		umatrix<T, Rows> result(r.columns());
		result.foreach([&](auto& val, auto ri, auto ci) { val = l(ri, ci) - r(ri, ci); });
		return result;
	}

	template<class T, size_t Rows> umatrix<T, Rows> operator * (uscalar<T> l, const umatrix<T, Rows>& r) {
		umatrix<T, Rows> result(r.columns());
		result.foreach([&](auto& val, auto ri, auto ci) { val = l * r(ri, ci); });
		return result;
	}

	template<class T, size_t Rows> umatrix<T, Rows> operator * (const umatrix<T, Rows>& l, uscalar<T> r) {
		umatrix<T, Rows> result(l.columns());
		result.foreach([&](auto& val, auto ri, auto ci) { val = l(ri, ci) * r; });
		return result;
	}

	template<class T, size_t LRows, size_t RRows> umatrix<T, LRows> operator * (const umatrix<T, LRows>& l, const umatrix<T, RRows>& r) {
		umatrix<T, LRows> result(r.columns());
		result.foreach([&](auto& val, auto ri, auto ci) { 
			val = T(0);
			for (size_t i = 0; i < l.columns(); i++)
				val += l(ri, i) * r(i, ci);
		});
		return result;
	}

	template<class T, size_t Rows> uvector<T, Rows> operator * (const umatrix<T, Rows>& l, const uvector<T, Rows>& r) {
		uvector<T, Rows> result{};
		for (int ri = 0; ri < l.rows(); ri++)
			for (int ci = 0; ci < l.rows(); ci++)
				result[ri] += (l(ri, ci) * r[ci]);
		return result;
	}

	template<class T, size_t Rows> std::ostream& operator<<(std::ostream& o, const umatrix<T, Rows>& mat) {
		for (int ri = 0; ri < mat.rows(); ri++) {
			o << "{ ";
			for (int ci = 0; ci < mat.columns(); ci++)
				o << mat(ri, ci) << ' ';
			o << "}\n";
		}
		return o;
	}
}
