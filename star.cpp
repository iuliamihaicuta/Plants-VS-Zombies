#include "include/star.h"
#include "include/shapes.h"

m1::Star::Star(glm::vec3 center)
{
	// set center
	this->center = center;
	
	// create star
	this->star = shapes::CreateStar("newStar", center, 35, glm::vec3(0.976, 0.976, 0.973), true);
}

m1::Star::Star(Mesh* star, int translateX)
{
	// set variables
	this->star = star;
	this->translateX = translateX;
}

m1::Star::Star(glm::vec3 center, glm::vec3 color)
{
	// set variables
	this->center = center;
	this->color = color;

	// create star
	if (color == glm::vec3(1, 1, 1)) {
		this->star = shapes::CreateStar("newStar", center, 35, true);
	}
	else {
		this->star = shapes::CreateStar("newStar", center, 35, color, true);
	}
}

glm::vec3 m1::Star::getCenter()
{
	return center;
}

Mesh* m1::Star::getStar()
{
	return star;
}

void m1::Star::setTranslateX(float x)
{
	this->translateX = x;
}

float m1::Star::getTranslateX()
{
	return translateX;
}

void m1::Star::setAngle(float angle)
{
	this->angle = angle;
}

float m1::Star::getAngle()
{
	return angle;
}

void m1::Star::setModelMatrix(glm::mat3 modelMatrix)
{
	this->modelMatrix = modelMatrix;
}

glm::mat3 & m1::Star::getModelMatrix()
{
	return modelMatrix;
}

glm::vec3 m1::Star::getColor()
{
	return color;
}
