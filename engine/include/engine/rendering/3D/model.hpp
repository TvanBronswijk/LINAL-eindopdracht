#pragma once
#include "engine/rendering/renderer.hpp"
#include "engine/math.hpp"
#include "mesh.hpp"

namespace rendering::rendering3d {
	class model {
	public:
		model(mesh mesh, renderer& renderer) : _mesh(mesh), _renderer(&renderer) {};
		model& scale(math::uvector<float, 3>);
		model& translate(math::uvector<float, 3>);
		model& rotate(math::uvector<float, 3>);
		model& rotate(math::uvector<float, 3>, math::uvector3D<float>);
		void render(float x = 0.0f, float y = 0.0f);
	private:
		renderer* _renderer;
		mesh _mesh;
	};
}
