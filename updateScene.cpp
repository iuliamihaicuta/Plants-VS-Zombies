#include "include/Tema1.h"

void m1::Tema1::addStarToGUI()
{
    for (int i = 0; i < stars.size(); ++i) {
        // remove the selected star and add it to the GUI
        if (stars[i].getCenter() == selectedStar.getCenter()) {
            nrStars++;
            stars.erase(stars.begin() + i);
            break;
        }
    }
}

void m1::Tema1::addDefenseToGrid()
{
    int nrOfStars = getNumberOfStars(GetColorIdx(GetColor(selectedRhombus)));

    // add defense to grid if there are enough stars
    if (nrStars - nrOfStars >= 0) {
        // get the position of the selected square
        int x = selectedSquare / 3;
        int y = selectedSquare % 3;

        // add defense to grid
        Defense defense(glm::vec3(startX + rectangleWidth + x * (squareSide + distance) + squareSide / 2, startY + y * (squareSide + distance) + squareSide / 2, 30), GetColor(selectedRhombus), x, y);
        rhombuses.push_back(defense);
        rhombusesGrid[x][y] = 1;

        // remove stars from GUI
        nrStars -= nrOfStars;
    }
}

void m1::Tema1::removeDefenseFromGrid()
{
    for (int i = 0; i < rhombuses.size(); ++i) {
        // remove defense from grid
        if (rhombuses[i].getCenter() == glm::vec3(startX + rectangleWidth + (selectedSquare / 3) * (squareSide + distance) + squareSide / 2, startY + (selectedSquare % 3) * (squareSide + distance) + squareSide / 2, 30)) {
            defensesToDisappear.push_back(Defense(rhombuses[i].getCenter(), rhombuses[i].getColorVec()));
            rhombuses.erase(rhombuses.begin() + i);

            // remove defense from rhombusesGrid
            rhombusesGrid[selectedSquare / 3][selectedSquare % 3] = 0;
            break;
        }
    }
}