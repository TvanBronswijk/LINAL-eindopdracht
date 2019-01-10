//#include <engine/math/transform3D.hpp>
//#include <engine/math/matrix3D.hpp>

int make() {
	//math::umatrix2D<float> matrix_1 = math::umatrix2D<float>::multidimensional_constructor<3>{ {
	//	{ 1.0f, 1.0f, 1.0f },
	//	{ 1.0f, 1.0f, 1.0f },
	//	{ 1.0f, 1.0f, 1.0f }
	//	} };

	//if (matrix_1.at(1,1) != 1.0f || matrix_1.at(2,2) != 1.0f) {
	//	return 0;
	//}
	//else {
	//	return 1;
	//}
	return 1;
}

int main() {
	int number = 0;
	try {
		number += make();
		//number += plus();
		//number += minus();
		//number += matrix_times_scalar();
		//number += scalar_times_matrix();
		//number += matrix_times_matrix();
		//number += divide_by_scalar();
		//number += plus_is();
		//number += minus_is();
		//number += times_is();
		//number += divide_by_is();
		//number += matrix_operator();
		//number += foreach();


		return number;
	}
	catch (int e) {
		return 1;
	}
}