#include <engine/math/vector3D.hpp>

int make() {
	math::uvector3D<float> vector3d(0.0f, 0.0f, 0.0f);
	return 0;
}

int plus() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uvector3D<float> vector3d_2(1.0f, 1.0f, 1.0f);

	math::uvector3D<float> vector3d_3 = vector3d_1 + vector3d_2;
	if (vector3d_3.x() != 2.0f || vector3d_3.y() != 2.0f || vector3d_3.z() != 2.0f) {
		return 1;
	}
	else return 0;
}

int minus() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uvector3D<float> vector3d_2(1.0f, 1.0f, 1.0f);

	math::uvector3D<float> vector3d_3 = vector3d_1 - vector3d_2;

	if (vector3d_3.x() != 0.0f || vector3d_3.y() != 0.0f || vector3d_3.z() != 0.0f) {
		return 1;
	}
	else return 0;
}

int vector_times_scalar() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uscalar<float> scalar(2.0f);

	math::uvector3D<float> vector3d_2 = vector3d_1 * scalar;

	if (vector3d_2.x() != 2.0f || vector3d_2.y() != 2.0f || vector3d_2.z() != 2.0f) {
		return 1;
	}
	else return 0;
}
int scalar_times_vector() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uscalar<float> scalar(2.0f);

	math::uvector3D<float> vector3d_2 = scalar * vector3d_1;

	if (vector3d_2.x() != 2.0f || vector3d_2.y() != 2.0f || vector3d_2.z()  != 2.0f) {
		return 1;
	}
	else return 0;
}

int divide_by_scalar() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uscalar<float> scalar(1.0f);

	math::uvector3D<float> vector3d_2 = vector3d_1 / scalar;

	if (vector3d_2.x() != 1.0f || vector3d_2.y() != 1.0f || vector3d_2.z() != 1.0f) {
		return 1;
	}
	else return 0;
}

int plus_is() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);

	vector3d_1 += math::uvector3D<float>(1.0f, 1.0f, 1.0f);
	if (vector3d_1.x() != 2.0f || vector3d_1.y() != 2.0f || vector3d_1.z() != 2.0f) {
		return 1;
	}
	else return 0;
}

int minus_is() {
	math::uvector3D<float> vector2d_1(1.0f, 1.0f, 1.0f);

	vector2d_1 -= math::uvector3D<float>(1.0f, 1.0f, 1.0f);

	if (vector2d_1.x() != 0.0f || vector2d_1.y() != 0.0f || vector2d_1.z() != 0.0f) {
		return 1;
	}
	else return 0;
}

int times_is() {
	math::uvector3D<float> vector3d_1(1.0f, 1.0f, 1.0f);
	math::uscalar<float> scalar(2.0f);

	vector3d_1 *= scalar;

	if (vector3d_1.x() != 2.0f || vector3d_1.y() != 2.0f || vector3d_1.z() != 2.0f) {
		return 1;
	}
	else return 0;
}

int divide_by_is() {
	math::uvector3D<float> vector3d_1( 1.0f, 1.0f, 1.0f );
	math::uscalar<float> scalar(1.0f);

	vector3d_1 /= scalar;

	if (vector3d_1.x() != 1.0f || vector3d_1.y() != 1.0f || vector3d_1.z() != 1.0f) {
		return 1;
	}
	else return 0;
}

int main() {
	int number = 0;
	try {
		number += make();
		number += plus();
		number += minus();
		number += vector_times_scalar();
		number += scalar_times_vector();
		number += divide_by_scalar();
		number += plus_is();
		number += minus_is();
		number += times_is();
		number += divide_by_is();
		
		return number;
	}
	catch(int e){
		return 1;
	}
}