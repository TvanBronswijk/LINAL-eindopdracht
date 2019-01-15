#include "game/entities/entityfactory.hpp"

using namespace rendering::rendering3d;
model entityfactory::create_spaceship() {
	mesh msh{
matrix3D::multidimensional_constructor<4>{ {
	{0.0f, 50.0f, 25.0f, 25.0f},
	{0.0f, 0.0f, 50.0f, 10.0f},
	{0.0f, 0.0f, 0.0f, 10.f},
	{1.0f, 1.0f, 1.0f, 1.0f}
}},
{
	{0, 1},
	{1, 2},
	{2, 0},
	{0, 3},
	{1, 3},
	{2, 3}
} };
	return { msh, *_renderer };

}
model entityfactory::create_target() {
	mesh msh{
matrix3D::multidimensional_constructor<17>{ {
	{-5.0f, 5.0f, 15.0f, 15.0f, 5.0f, -5.0f, -15.0f, -15.0f, -7.5f, 7.5f, 20.0f, 20.0f, 7.5f, -7.5f, -20.0f, -20.0f, 0.0f},
	{-15.0f, -15.0f, -5.0f, 5.0f, 15.0f, 15.0f, 5.0f, -5.0f, -20.0f, -20.0f, -7.5f , 7.0f, 20.0f, 20.0f, 7.5f, -8.0f, 0.0f},
	{-12.5f, -12.5f, -12.5f, -12.5f, -12.5f, -12.5f, -12.5f, -12.5f, -2.5f, -2.5f, -2.5f, -2.5f, -2.5f, -2.5f, -2.5f, -2.5f, 17.5f},
	{1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
}},
{
	//hexagon front
	{0, 1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	{5,6},
	{6,7},
	{7,0},
	{8,9},
	{9,10},
	{10,11},
	{11,12},
	{12,13},
	{13,14},
	{14,15},
	{15,8},

	//connect middel circle with outer
	{0,8},
	{1,9},
	{2,10},
	{3,11},
	{4,12},
	{5,13},
	{6,14},
	{7,15},

	//connect to back
	{8,16},
	{9,16},
	{10,16},
	{11,16},
	{12,16},
	{13,16},
	{14,16},
	{15,16},
	
} };
	return { msh, *_renderer };
}
model entityfactory::create_bullet() {
	mesh msh{
matrix3D::multidimensional_constructor<2>{ {
	{0.0f, 10.0f},
	{0.0f, 0.0f},
	{0.0f, 0.0f},
	{1.0f, 1.0f}
}},
{
	{0, 1},
} };
	return { msh, *_renderer };
}
model entityfactory::create_asteroid() {
	mesh msh{
matrix3D::multidimensional_constructor<10>{ {
	{-5.0f, 5.0f, 15.0f, 15.0f, 5.0f, -5.0f, -15.0f, -15.0f, 0.0f, 0.0f},
	{-10.0f, -10.0f, 0.0f, 10.0f, 20.0f, 20.0f, 10.0f, 0.0f, 5.0f, 5.0f},
	{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -20.0f, 20.0f},
	{1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
}},
{
	//hexagon
	{0, 1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	{5,6},
	{6,7},
	{7,0},

	//point begin
	{0,8},
	{1,8},
	{2,8},
	{3,8},
	{4,8},
	{5,8},
	{6,8},
	{7,8},

	//point end
	{0,9},
	{1,9},
	{2,9},
	{3,9},
	{4,9},
	{5,9},
	{6,9},
	{7,9}
} };
	return { msh, *_renderer };
}
