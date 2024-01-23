#include "include/enemies.h"
#include "include/Main.h"
#include "include/transform2D.h"

using namespace std;


m1::Enemy::Enemy(int x, int level)
{
    // initialize variables
    this->idx = idx;
    this->centX = x;

    // get random color
    color = m1::Tema1::GetRandomColor();
    this->colorIdx = m1::Tema1::GetColorIdx(color);

    // get random y
    int centY = GetRandomY();
    center = glm::vec3(centX, centY, 30);

    m1::Tema1::Color colors;

    // starting with level 2, there is a 25% chance that the enemy will be big and have 5 lives
    if (level >= 2) {
        isBig = rand() % 4 == 0;
    }

    if (isBig) {
        // Create first hexagon
        hexa1 = shapes::CreateHexagon("hexagon1", center, hexa2Radius, color, true);

        // Create second hexagon
        hexa2 = shapes::CreateHexagon("hexagon2", center + glm::vec3(0, 0, 1), hexa2Radius * 0.6, colors.center, true);
        life = 5;
    } else {
        // Create first hexagon
        hexa1 = shapes::CreateHexagon("hexagon1", center, hexaRadius, color, true);

        // Create second hexagon
        hexa2 = shapes::CreateHexagon("hexagon2", center + glm::vec3(0, 0, 1), hexaRadius * 0.6, colors.center, true);
        life = 3;
    }

    if (level >= 1 && !isBig) {
        // starting with level 1, there is a 50% chance that the enemy will change color when hit
        isChangingColor = rand() % 2;
    } else if (level >= 3) {
		// starting with level 3, there is a 50% chance that a big enemy will change color when hit
        isChangingColor = rand() % 2;
	}
}

int m1::Enemy::disappear(float deltaTime)
{
    // scale down
    scale -= deltaTime;

    // update model matrix
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX, 0);

    modelMatrix *= transform2D::Translate(center.x, center.y);
    modelMatrix *= transform2D::Scale(scale, scale);
    modelMatrix *= transform2D::Translate(-center.x, -center.y);


    // check if disappeared
    if (scale <= 0)
		return 1;

    return 0;
}

void m1::Enemy::translate(float deltaTime)
{
    // translate
    translateX -= 70 * deltaTime;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX, 0);
}

void m1::Enemy::loseLife()
{
    life--;

    if (isChangingColor && life > 0) {
		// change color of enemy
        color = m1::Tema1::GetRandomColor();
        this->colorIdx = m1::Tema1::GetColorIdx(color);

        if (isBig) {
            hexa1 = shapes::CreateHexagon("hexagon1", center, hexa2Radius, color, true);
        }
        else {
            hexa1 = shapes::CreateHexagon("hexagon1", center, hexaRadius, color, true);
        }
	}
}

bool m1::Enemy::isDead()
{
	return life <= 0;
}

bool m1::Enemy::isScaled()
{
	return scale < 1;
}

Mesh* m1::Enemy::GetHexa1()
{
    return hexa1;
}

Mesh* m1::Enemy::GetHexa2()
{
	return hexa2;
}

int m1::Enemy::GetRandomY()
{
    // get random y
    y = rand() % 3;

    int startY = Tema1::getStartY();
    int squareSide = Tema1::getSquareSide();
    int distance = Tema1::getDistance();

    // compute center y
    if (y == 0)
        return startY + squareSide / 2;
    else if (y == 1)
        return startY + 3 * squareSide / 2 + distance;
    else
        return startY + 5 * squareSide / 2 + 2 * distance;
}

glm::vec3 m1::Enemy::getCenter()
{
    return center;
}

void m1::Enemy::setCenter(glm::vec3 center)
{
    this->center = center;
}

void m1::Enemy::setTranslateX(int x)
{
	this->translateX = x;
}

int m1::Enemy::getTranslateX()
{
	return translateX;
}

int m1::Enemy::getLife()
{
	return life;
}

void m1::Enemy::setLife(int life)
{
	this->life = life;
}

int m1::Enemy::getColor()
{
	return colorIdx;
}

int m1::Enemy::getY()
{
	return y;
}

glm::vec3 m1::Enemy::getColorVec()
{
    return color;
}

glm::mat3 m1::Enemy::getModelMatrix()
{
	return modelMatrix;
}
