#include "include/Tema1.h"

int m1::Tema1::getDistance() {
    return distance;
}

int m1::Tema1::getSquareSide() {
    return squareSide;
}

int m1::Tema1::getStartX() {
    return startX;
}

int m1::Tema1::getStartY() {
    return startY;
}

int m1::Tema1::getRectangleWidth()
{
    return rectangleWidth;
}

glm::vec3 m1::Tema1::GetRandomColor()
{
    // generate random number between 1 and 4
    Color colors;
    int random = rand() % 4 + 1;

    // return color
    switch (random) {
        case 1:
            return colors.red;
        case 2:
            return colors.orange;
        case 3:
            return colors.yellow;
        default:
            return colors.blue;
    }
}

int m1::Tema1::GetColorIdx(glm::vec3 color)
{
    if (color == Color().red) {
        return 1;
    }

    if (color == Color().orange) {
        return 2;
    }

    if (color == Color().yellow) {
        return 3;
    }

    return 4;
}

glm::vec3 m1::Tema1::GetColor(int x)
{
    Color colors;

    switch (x) {
        case 1:
            return colors.red;
        case 2:
            return colors.orange;
        case 3:
            return colors.yellow;
        default:
            return colors.blue;
    }
}

int m1::Tema1::getNumberOfStars(int color)
{
    // return number of stars for a given color
    switch (color) {
        case (1):
            return 1;
        case (2):
            return 2;
        case (3):
            return 2;
        case (4):
            return 3;
        default:
            return 0;
    }
}

int m1::Tema1::getSelectedRhombus(int mouseX, int mouseY)
{
    // check if the mouse is not near the rhombuses
    if (mouseY > resolution.y - distance || mouseY < resolution.y - distance - squareSide) {
        return -1;
    }

    // return the index of the selected rhombus
    if (mouseX > startX && mouseX < startX + squareSide) {
        return 1;
    }

    if (mouseX > startX + squareSide + 2 * distance && mouseX < startX + squareSide + 2 * distance + squareSide) {
        return 2;
    }

    if (mouseX > startX + 2 * squareSide + 4 * distance && mouseX < startX + 2 * squareSide + 4 * distance + squareSide) {
        return 3;
    }

    if (mouseX > startX + 3 * squareSide + 6 * distance && mouseX < startX + 3 * squareSide + 6 * distance + squareSide) {
        return 4;
    }

    return -1;
}

int m1::Tema1::getSelectedSquare(int mouseX, int mouseY)
{
    // return the index of the selected square
    if (mouseX > startX + rectangleWidth && mouseX < startX + rectangleWidth + squareSide) {
        if (mouseY > startY && mouseY < startY + squareSide) {
            return 0;
        }
        else if (mouseY > startY + squareSide + distance && mouseY < startY + 2 * squareSide + distance) {
            return 1;
        }
        else if (mouseY > startY + 2 * squareSide + 2 * distance && mouseY < startY + 3 * squareSide + 2 * distance) {
            return 2;
        }
    }
    else if (mouseX > startX + rectangleWidth + squareSide + distance && mouseX < startX + rectangleWidth + 2 * squareSide + distance) {
        if (mouseY > startY && mouseY < startY + squareSide) {
            return 3;
        }
        else if (mouseY > startY + squareSide + distance && mouseY < startY + 2 * squareSide + distance) {
            return 4;
        }
        else if (mouseY > startY + 2 * squareSide + 2 * distance && mouseY < startY + 3 * squareSide + 2 * distance) {
            return 5;
        }
    }
    else if (mouseX > startX + rectangleWidth + 2 * squareSide + 2 * distance && mouseX < startX + rectangleWidth + 3 * squareSide + 2 * distance) {
        if (mouseY > startY && mouseY < startY + squareSide) {
            return 6;
        }
        else if (mouseY > startY + squareSide + distance && mouseY < startY + 2 * squareSide + distance) {
            return 7;
        }
        else if (mouseY > startY + 2 * squareSide + 2 * distance && mouseY < startY + 3 * squareSide + 2 * distance) {
            return 8;
        }
    }

    return -1;
}

m1::Star m1::Tema1::getSelectedStar(int mouseX, int mouseY)
{
    // return the selected star
    for (Star star : stars) {
        glm::vec3 center = star.getCenter();
        int distance = sqrt((center.x - mouseX) * (center.x - mouseX) + (center.y - mouseY) * (center.y - mouseY));
        if (distance < 35) {
            return star;
        }
    }

    return Star(glm::vec3(-1, -1, -1));
}
