#include "game/entities/entityfactory.hpp"

using namespace rendering::rendering3d;
model entityfactory::create_spaceship() {
	mesh msh{
	matrix3D::multidimensional_constructor<4>{ {
		{-25.0f, 25.0f, 0.0f, 0.0f},
		{-25.0f, -25.0f, 25.0f, -15.0f},
		{-25.0f, -25.0f, -25.0f, -15.f},
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
model entityfactory::create_bullet() {
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
model entityfactory::create_asteroid() {
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
