#include <engine/math/transform3D.hpp>
#include <engine/math/matrix3D.hpp>

int scale_vector() {
	math::umatrix3D<float> matrix_1 = math::scale(math::uvector<float, 3>({ 2.0f, 2.0f, 2.0f }));

	if (matrix_1.at(0, 0) != 2.0f || matrix_1.at(1, 1) != 2.0f || matrix_1.at(2, 2) != 2.0f) {
		return 1;
	}
	else { return 0; }
}

int scale_matrix_vector() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };

	math::umatrix3D<float> matrix_2 = math::scale(matrix_1, math::uvector<float, 3>({ 2.0f, 2.0f, 2.0f }));

	if (matrix_2.at(0, 0) != 2.0f || matrix_2.at(1, 1) != 2.0f || matrix_2.at(2, 2) != 2.0f) {
		return 1;
	}
	else { return 0; }
}

int translate_vector() {
	math::umatrix3D<float> matrix_1 = math::translate(math::uvector<float, 3>({ 2.0f, 2.0f, 2.0f }));

	if (matrix_1.at(0, 0) != 1.0f || matrix_1.at(0, 3) != 2.0f || matrix_1.at(1, 3) != 2.0f) {
		return 1;
	}
	else { return 0; }
}

int translate_matrix_vector() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };

	math::umatrix3D<float> matrix_2 = math::translate(matrix_1, math::uvector<float, 3>({ 2.0f, 2.0f, 2.0f }));

	if (matrix_2.at(0, 2) != 3.0f || matrix_2.at(1, 2) != 3.0f || matrix_2.at(2, 2) != 3.0f) {
		return 1;
	}
	else { return 0; }
}

int rotate_vector() {
	math::umatrix3D<float> matrix_2 = math::rotate(math::uvector<float, 3>({ 180.0f, 0.0f, 0.0f }));

	if (matrix_2.at(0, 0) != 1.0f || matrix_2.at(1, 1) != -1.0f || matrix_2.at(3, 3) != 1.0f) {
		return 1;
	}
	else { return 0; }
}

int rotate_matrix_vector() {
	math::umatrix3D<float> matrix_1 = math::umatrix3D<float>::multidimensional_constructor<3>{ {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f }
	} };


	math::umatrix3D<float> matrix_2 = math::rotate(matrix_1, math::uvector<float, 3>({ 180.0f, 180.0f, 180.0f }));

	if (matrix_2.at(0, 0) != 1.0f || matrix_2.at(1, 1) != 0.999999881f || matrix_2.at(2, 2) != 1.00000012f) {
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
		number += rotate_vector();
		number += rotate_matrix_vector();

		return number;
	}
	catch (int e) {
		return 1;
	}
}