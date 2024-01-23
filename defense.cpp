#include "include/defense.h"
#include "include/shapes.h"
#include "include/Tema1.h"
#include "include/transform2D.h"

m1::Defense::Defense(glm::vec3 center, glm::vec3 color, int x, int y)
{
	// there is a 20% chance that the defense will be colorful and kill any enemy
	colorful = rand() % 5 == 0;

	// initialize variables
	this->center = center;
	this->x = x;
	this->y = y;

	if (colorful) {
		// create rhombus that can kill any enemy
		this->color = 5;
		this->colorVec = glm::vec3(1, 1, 1);

		// create rhombus
		rhombus = shapes::CreateRhombus("newRhombus", center, 50, true);
	}
	else {
		this->color = Tema1::GetColorIdx(color);
		this->colorVec = color;

		// create rhombus
		rhombus = shapes::CreateRhombus("newRhombus", center, 50, color, true);
	}
}

m1::Defense::Defense(glm::vec3 center, glm::vec3 color)
{
	// initialize variables
	this->center = center;
	this->color = Tema1::GetColorIdx(color);
	this->colorVec = color;

	// create rhombus
	rhombus = shapes::CreateRhombus("newRhombus", center, 50, color, true);
}

int m1::Defense::disappear(float deltaTime)
{
	// scale down
	scaleX -= 3 * deltaTime;
	scaleY -= 3 * deltaTime;

	// update model matrix
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(center.x, center.y);
	modelMatrix *= transform2D::Scale(scaleX, scaleY);
	modelMatrix *= transform2D::Translate(-center.x, -center.y);

	// check if disappeared
	if (scaleX <= 0)
		return 1;

	return 0;
}

void m1::Defense::rotateStars(float deltaTime)
{
	// rotate stars
	for (auto& star : this->stars)
	{
		// update angle and translateX
		star.setAngle(star.getAngle() - 5 * deltaTime);
		star.setTranslateX(star.getTranslateX() + 300 * deltaTime);

		glm::mat3 modelMatrix = glm::mat3(1);

		// update model matrix
		modelMatrix *= transform2D::Translate(star.getTranslateX(), 0);

		modelMatrix *= transform2D::Translate(star.getCenter().x, star.getCenter().y);
		modelMatrix *= transform2D::Rotate(star.getAngle());
		modelMatrix *= transform2D::Translate(-star.getCenter().x, -star.getCenter().y);

		star.setModelMatrix(modelMatrix);
	}
}

void m1::Defense::translateStars(int deltaTime)
{
	for (auto& star : stars)
	{
		star.setTranslateX(star.getTranslateX() + 60 * deltaTime);

		// glm::mat3 modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(star.getTranslateX(), 0);

		star.setModelMatrix(modelMatrix);
	}
}

glm::vec3 m1::Defense::getCenter()
{
	return center;
}

void m1::Defense::setCenter(glm::vec3 center)
{
	this->center = center;
}

Mesh* m1::Defense::getRhombus()
{
	return rhombus;
}

int m1::Defense::getColor()
{
	return color;
}

glm::vec3 m1::Defense::getColorVec()
{
	return colorVec;
}

int m1::Defense::getY()
{
	return y;
}

int m1::Defense::getX()
{
	return x;
}

glm::mat3 m1::Defense::getModelMatrix()
{
	return modelMatrix;
}

void m1::Defense::addStar(Star star)
{
	stars.push_back(star);
}

std::vector<m1::Star> & m1::Defense::getStars()
{
	return stars;
}

void m1::Defense::setTimeSinceLastStar(int time)
{
	timeSinceLastStar = time;
}

int m1::Defense::getTimeSinceLastStar()
{
	return timeSinceLastStar;
}

bool m1::Defense::isColorful()
{
	return colorful;
}