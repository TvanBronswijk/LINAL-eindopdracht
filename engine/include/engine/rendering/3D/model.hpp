#pragma once
#include "engine/rendering/renderer.hpp"
#include "engine/math.hpp"
#include "mesh.hpp"
#include "view.hpp"

namespace rendering::rendering3d {
	class model {
	public:
		model(mesh mesh, renderer& renderer) : _mesh(mesh), _renderer(&renderer) {};
		model& scale(math::uvector<float, 3>);
		model& translate(math::uvector<float, 3>);
		model& rotate(math::uvector<float, 3>);
		model& rotate(math::uvector<float, 3>, math::uvector3D<float>);
		math::uvector3D<float> center();
		void render(view<float> view, float x = 0.0f, float y = 0.0f);
		void render_angles(view<float> view, float x = 0.0f, float y = 0.0f);

		math::uvector3D<float> origin{ 0.0f, 0.0f, 0.0f, 1.0f };
		math::uvector3D<float> heading{0.0f, 0.0f, 1.0f, 1.0f};
		math::uvector3D<float> up{0.0f, 1.0f, 0.0f, 1.0f};
		math::uvector3D<float> side{1.0f, 0.0f, 0.0f, 1.0f};
	private:
		renderer* _renderer;
		mesh _mesh;
		math::uvector<float, 3> _scale{ { 1.0f, 1.0f, 1.0f } };
	};
}
