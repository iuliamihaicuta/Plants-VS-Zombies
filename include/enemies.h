#pragma once

#include "components/simple_scene.h"

namespace m1
{
	class Enemy
	{
		public:
		Enemy(int x, int level);
		Enemy() = default;
		~Enemy() = default;

		int disappear(float deltaTime);
		void translate(float deltaTime);

		void loseLife();
		bool isDead();
		bool isScaled();

		Mesh* GetHexa1();
		Mesh* GetHexa2();
		int GetRandomY();

		glm::vec3 getCenter();
		void setCenter(glm::vec3 center);

		void setTranslateX(int x);
		int getTranslateX();

		int getLife();
		void setLife(int life);

		int getColor();
		int getY();
		glm::vec3 getColorVec();
			
		glm::mat3 getModelMatrix();

		protected:
			glm::vec3 color;
			glm::vec3 center;
			int hexaRadius = 30;
			int hexa2Radius = 40;
			int idx;
			Mesh* hexa1;
			Mesh* hexa2;
			int centX;
			float translateX = 0;
			float scale = 1;

			int life = 3;

			int y;
			int colorIdx;
			glm::mat3 modelMatrix;

			bool isChangingColor = false;
			bool isBig = false;
	};
}