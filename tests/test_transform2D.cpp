#include <engine/math/transform2D.hpp>
#include <engine/math/matrix2D.hpp>

int scale_vector() {
	math::umatrix2D<float> matrix_1 = math::scale(math::uvector<float, 2>({ 2.0f, 2.0f }));

	if (matrix_1.at(0, 0) != 2.0f || matrix_1.at(1, 1) != 2.0f || matrix_1.at(2, 2) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int scale_matrix_vector() {
	math::umatrix2D<float> matrix_1 = math::umatrix2D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };

	math::umatrix2D<float> matrix_2 = math::scale(matrix_1, math::uvector<float, 2>({ 2.0f, 2.0f }));

	if (matrix_2.at(0, 0) != 2.0f || matrix_2.at(1, 1) != 2.0f || matrix_2.at(2, 2) != 0.0f) {
		return 1;
	}
	else { return 0; }
}

int translate_vector() {
	math::umatrix2D<float> matrix_1 = math::translate(math::uvector<float, 2>({ 2.0f, 2.0f }));

	if (matrix_1.at(0,2) != 2.0f || matrix_1.at(1, 2) != 2.0f || matrix_1.at(2,2) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int translate_matrix_vector() {
	math::umatrix2D<float> matrix_1 = math::umatrix2D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };

	math::umatrix2D<float> matrix_2 = math::translate(matrix_1, math::uvector<float, 2>({ 2.0f, 2.0f }));

	if (matrix_2.at(0, 2) != 3.0f || matrix_2.at(1, 2) != 3.0f || matrix_2.at(2, 2) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int rotate_degree() {
	math::umatrix2D<float> matrix_2 = math::rotate(180.0f);

	if (matrix_2.at(0, 0) != -1.0f || matrix_2.at(1, 1) != -1.0f || matrix_2.at(2, 2) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int rotate_matrix_degree() {
	math::umatrix2D<float> matrix_1 = math::umatrix2D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };

	math::umatrix2D<float> matrix_2 = math::rotate(matrix_1, 180.0f);

	if (matrix_2.at(0, 0) != -1.00000012f || matrix_2.at(1, 1) != -0.999999940f || matrix_2.at(2, 2) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int main() {
	int number = 0;
	try {
		number += scale_vector();
		number += scale_matrix_vector();
		number += translate_vector();
		number += translate_matrix_vector();
		number += rotate_degree();
		number += rotate_matrix_degree();

		return number;
	}
	catch (int e) {
		return 1;
	}
}