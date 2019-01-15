//#include <engine/math/transform3D.hpp>
#include <engine/math/matrix3D.hpp>

int make() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	if (matrix_1.at(1, 1) != 1.0f || matrix_1.at(2, 2) != 1.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int plus() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	math::umatrix3D<float> matrix_2 = matrix_1 + matrix_1;

	if (matrix_2.at(2, 2) != 2.0f || matrix_2.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int minus() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	math::umatrix3D<float> matrix_2 = matrix_1 - matrix_1;

	if (matrix_2.at(2, 2) != 0.0f || matrix_2.at(0, 0) != 0.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int matrix_times_scalar() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	math::umatrix3D<float> matrix_2 = matrix_1 * math::uscalar<float>(2.0f);

	if (matrix_2.at(2, 2) != 2.0f || matrix_2.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int scalar_times_matrix() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	math::umatrix3D<float> matrix_2 = math::uscalar<float>(2.0f) * matrix_1;

	if (matrix_2.at(2, 2) != 2.0f || matrix_2.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int matrix_times_matrix() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	math::umatrix3D<float> matrix_2 = matrix_1 * matrix_1;

	if (matrix_2.at(2, 2) != 4.0f || matrix_2.at(0, 0) != 4.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int divide_by_scalar() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f }
		} };

	math::umatrix3D<float> matrix_2 = matrix_1 /= math::uscalar<float>(2.0f);

	if (matrix_2.at(2, 2) != 1.0f || matrix_2.at(0, 0) != 1.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int plus_is() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	matrix_1 += matrix_1;

	if (matrix_1.at(2, 2) != 2.0f || matrix_1.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int minus_is() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f }
	} };

	matrix_1 -= matrix_1;

	if (matrix_1.at(2, 2) != 0.0f || matrix_1.at(0, 0) != 0.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int times_is() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	matrix_1 *= math::uscalar<float>(2.0f);

	if (matrix_1.at(2, 2) != 2.0f || matrix_1.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int divide_by_is() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f }
		} };

	matrix_1 /= math::uscalar<float>(2.0f);

	if (matrix_1.at(2, 2) != 1.0f || matrix_1.at(0, 0) != 1.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int matrix_operator() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
			{ 2.0f, 2.0f, 2.0f, 2.0f },
			{ 2.0f, 2.0f, 2.0f, 2.0f },
			{ 2.0f, 2.0f, 2.0f, 2.0f },
			{ 2.0f, 2.0f, 2.0f, 2.0f }
			} };

	if (matrix_1(2, 2) != 2.0f || matrix_1(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int foreach() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<4>{ {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		} };

	matrix_1.foreach([](auto& val) { val += 1; });

	if (matrix_1.at(2, 2) != 2.0f || matrix_1.at(0, 0) != 2.0f) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int number = 0;
	try {
		number += make();
		number += plus();
		number += minus();
		number += matrix_times_scalar();
		number += scalar_times_matrix();
		number += matrix_times_matrix();
		number += divide_by_scalar();
		number += plus_is();
		number += minus_is();
		number += times_is();
		number += divide_by_is();
		number += matrix_operator();
		number += foreach();

		return number;
	}
	catch (int e) {
		return 1;
	}
}
