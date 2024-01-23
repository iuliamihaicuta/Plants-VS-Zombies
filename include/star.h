#pragma once

#include "components/simple_scene.h"

namespace m1
{
	class Star
	{
	public:
		Star(glm::vec3 center);
		Star(Mesh* star, int translateX);
		Star(glm::vec3 center, glm::vec3 color);
		Star() = default;
		~Star() = default;

		glm::vec3 getCenter();
		Mesh* getStar();

		void setTranslateX(float x);
		float getTranslateX();

		void setAngle(float angle);
		float getAngle();

		void setModelMatrix(glm::mat3 modelMatrix);
		glm::mat3 & getModelMatrix();

		glm::vec3 getColor();


	protected:
		Mesh* star;
		glm::vec3 center;
		glm::vec3 color;

		float translateX = 0;
		float angle = 0;
		glm::mat3 modelMatrix = glm::mat3(1);
	};
}