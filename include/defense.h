	#pragma once

	#include "components/simple_scene.h"
	#include "star.h"

	namespace m1
	{
		class Defense
		{
			public:
			Defense(glm::vec3 center, glm::vec3 color, int x, int y);
			Defense(glm::vec3 center, glm::vec3 color);
			Defense() = default;
			~Defense() = default;

			int disappear(float deltaTime);
			void rotateStars(float deltaTime);
			void translateStars(int deltaTime);
			bool isColorful();

			glm::vec3 getCenter();
			void setCenter(glm::vec3 center);

			Mesh* getRhombus();
			int getColor();
			glm::vec3 getColorVec();
			int getY();
			int getX();
			glm::mat3 getModelMatrix();

			void addStar(Star star);
			std::vector<Star> & getStars();

			void setTimeSinceLastStar(int time);
			int getTimeSinceLastStar();

			protected:
				int color;
				int y;
				int x;
				glm::vec3 center;
				Mesh* rhombus;
				std::vector<Star> stars;
				glm::vec3 colorVec;

				int timeSinceLastStar = -1;

				float scaleX = 1;
				float scaleY = 1;
				glm::mat3 modelMatrix;

				bool colorful = false;
		};
	}