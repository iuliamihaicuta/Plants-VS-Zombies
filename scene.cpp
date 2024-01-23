#include "include/shapes.h"
#include "include/Tema1.h"

void m1::Tema1::CreateGrid() {
    // create the rectangle
    Mesh* rectangle = shapes::CreateRectangle("rectangle", glm::vec3(startX, startY, 0), rectangleWidth, rectangleHeight, glm::vec3(0.184, 0.204, 0.251), true);
    AddMeshToList(rectangle);

    // create the squares
    Mesh* square00 = shapes::CreateSquare("square00", glm::vec3(startX + rectangleWidth + distance, startY, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square00);

    Mesh* square01 = shapes::CreateSquare("square01", glm::vec3(startX + rectangleWidth + distance, startY + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square01);

    Mesh* square02 = shapes::CreateSquare("square02", glm::vec3(startX + rectangleWidth + distance, startY + squareSide + distance + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square02);

    Mesh* square10 = shapes::CreateSquare("square10", glm::vec3(startX + rectangleWidth + distance + squareSide + distance, startY, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square10);

    Mesh* square11 = shapes::CreateSquare("square11", glm::vec3(startX + rectangleWidth + distance + squareSide + distance, startY + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square11);

    Mesh* square12 = shapes::CreateSquare("square12", glm::vec3(startX + rectangleWidth + distance + squareSide + distance, startY + squareSide + distance + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square12);

    Mesh* square20 = shapes::CreateSquare("square20", glm::vec3(startX + rectangleWidth + distance + squareSide + distance + squareSide + distance, startY, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square20);

    Mesh* square21 = shapes::CreateSquare("square21", glm::vec3(startX + rectangleWidth + distance + squareSide + distance + squareSide + distance, startY + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square21);

    Mesh* square22 = shapes::CreateSquare("square22", glm::vec3(startX + rectangleWidth + distance + squareSide + distance + squareSide + distance, startY + squareSide + distance + squareSide + distance, 0), squareSide, glm::vec3(0.514, 0.769, 0.633), true);
    AddMeshToList(square22);

}

void m1::Tema1::CreateGUI() {
    glm::ivec2 resolution = window->GetResolution();

    // create the squares for the GUI
    Mesh* square1 = shapes::CreateSquare("square1", glm::vec3(startX, resolution.y - distance - squareSide, 0), squareSide, glm::vec3(0.184, 0.204, 0.251));
    AddMeshToList(square1);

    Mesh* square2 = shapes::CreateSquare("square2", glm::vec3(startX + squareSide + 2 * distance, resolution.y - distance - squareSide, 0), squareSide, glm::vec3(0.184, 0.204, 0.251));
    AddMeshToList(square2);

    Mesh* square3 = shapes::CreateSquare("square3", glm::vec3(startX + 2 * squareSide + 4 * distance, resolution.y - distance - squareSide, 0), squareSide, glm::vec3(0.184, 0.204, 0.251));
    AddMeshToList(square3);

    Mesh* square4 = shapes::CreateSquare("square4", glm::vec3(startX + 3 * squareSide + 6 * distance, resolution.y - distance - squareSide, 0), squareSide, glm::vec3(0.184, 0.204, 0.251));
    AddMeshToList(square4);

    // create the rhombuses for the GUI
    Color colors;

    Mesh* rhombus0 = shapes::CreateRhombus("rhombus0", glm::vec3(startX + squareSide / 2 - 25, resolution.y - distance - squareSide / 2, 0), 50, colors.red, true);
    AddMeshToList(rhombus0);

    Mesh* rhombus1 = shapes::CreateRhombus("rhombus1", glm::vec3(startX + squareSide + 2 * distance + squareSide / 2 - 25, resolution.y - distance - squareSide / 2, 0), 50, colors.orange, true);
    AddMeshToList(rhombus1);

    Mesh* rhombus2 = shapes::CreateRhombus("rhombus2", glm::vec3(startX + 2 * squareSide + 4 * distance + squareSide / 2 - 25, resolution.y - distance - squareSide / 2, 0), 50, colors.yellow, true);
    AddMeshToList(rhombus2);

    Mesh* rhombus3 = shapes::CreateRhombus("rhombus3", glm::vec3(startX + 3 * squareSide + 6 * distance + squareSide / 2 - 25, resolution.y - distance - squareSide / 2, 0), 50, colors.blue, true);
    AddMeshToList(rhombus3);

    // create the lifes    
    for (int i = 0; i < nrLifes; ++i) {
        AddMeshToList(shapes::CreateSquare("life" + std::to_string(i), glm::vec3(startX + 4 * squareSide + i * (squareSide2 + distance) + 8 * distance, resolution.y - distance - squareSide2 - diffDistance, 0), squareSide2, glm::vec3(0.184, 0.204, 0.251), true));
    }

    // stars needed for each color
    Mesh* star11 = shapes::CreateStar("star11", glm::vec3(startX + radius, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star11);

    Mesh* star21 = shapes::CreateStar("star21", glm::vec3(startX + squareSide + 2 * distance + radius, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star21);

    Mesh* star22 = shapes::CreateStar("star22", glm::vec3(startX + squareSide + 2 * distance + 3 * radius + diffDistanceStar, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star22);

    Mesh* star31 = shapes::CreateStar("star31", glm::vec3(startX + 2 * squareSide + 4 * distance + radius, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star31);

    Mesh* star32 = shapes::CreateStar("star32", glm::vec3(startX + 2 * squareSide + 4 * distance + 3 * radius + diffDistanceStar, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star32);

    Mesh* star41 = shapes::CreateStar("star41", glm::vec3(startX + 3 * squareSide + 6 * distance + radius, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star41);

    Mesh* star42 = shapes::CreateStar("star42", glm::vec3(startX + 3 * squareSide + 6 * distance + 3 * radius + diffDistanceStar, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star42);

    Mesh* star43 = shapes::CreateStar("star43", glm::vec3(startX + 3 * squareSide + 6 * distance + 5 * radius + 2 * diffDistanceStar, resolution.y - distance - squareSide - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true);
    AddMeshToList(star43);

    // add 12 stars - the maximum number of stars that can visible be on the screen
    for (int i = 0; i < 12; i++) {
        AddMeshToList(shapes::CreateStar("starLife" + std::to_string(i), glm::vec3(startX + 4 * squareSide + 8 * distance + i * (2 * radius + diffDistanceStar) + radius, resolution.y - distance - squareSide2 - diffDistance - radius, 0), radius, glm::vec3(0.922, 0.922, 0.706), true));
    }

    for (int i = 12; i < 24; ++i) {
        AddMeshToList(shapes::CreateStar("starLife" + std::to_string(i), glm::vec3(startX + 4 * squareSide + 8 * distance + (i - 12) * (2 * radius + diffDistanceStar) + radius, resolution.y - distance - squareSide2 - diffDistance - radius - 40, 20), radius, glm::vec3(0.922, 0.922, 0.706), true));
    }

    for (int i = 24; i < 36; ++i) {
        AddMeshToList(shapes::CreateStar("starLife" + std::to_string(i), glm::vec3(startX + 4 * squareSide + 8 * distance + (i - 24) * (2 * radius + diffDistanceStar) + radius, resolution.y - distance - squareSide2 - diffDistance - radius - 80, 20), radius, glm::vec3(0.922, 0.922, 0.706), true));
    }

    for (int i = 36; i < 48; ++i) {
        AddMeshToList(shapes::CreateStar("starLife" + std::to_string(i), glm::vec3(startX + 4 * squareSide + 8 * distance + (i - 36) * (2 * radius + diffDistanceStar) + radius, resolution.y - distance - squareSide2 - diffDistance - radius - 80, 20), radius, glm::vec3(0.922, 0.922, 0.706), true));
    }

}

void m1::Tema1::RenderGrid() {
    // render rectangle
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], glm::mat3(1));

    // render squares
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            RenderMesh2D(meshes["square" + std::to_string(i) + std::to_string(j)], shaders["VertexColor"], glm::mat3(1));
        }
    }
}

void m1::Tema1::RenderGUI(int time) {
    // render squares for GUI
    for (int i = 1; i < 5; ++i) {
        RenderMesh2D(meshes["square" + std::to_string(i)], shaders["VertexColor"], glm::mat3(1));
    }

    // render rhombuses for GUI
    for (int i = 0; i < 4; ++i) {
        RenderMesh2D(meshes["rhombus" + std::to_string(i)], shaders["VertexColor"], glm::mat3(1));
    }

    // render lifes
    for (int i = 0; i < nrLifes; ++i) {
        RenderMesh2D(meshes["life" + std::to_string(i)], shaders["VertexColor"], glm::mat3(1));
    }

    // render stars needed for each color
    RenderMesh2D(meshes["star11"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star21"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star22"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star31"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star32"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star41"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star42"], shaders["VertexColor"], glm::mat3(1));
    RenderMesh2D(meshes["star43"], shaders["VertexColor"], glm::mat3(1));


    // render available stars
    for (int i = 0; i < nrStars; i++) {
        RenderMesh2D(meshes["starLife" + std::to_string(i)], shaders["VertexColor"], glm::mat3(1));
    }

    // text render
    const glm::vec3 kTextColor = NormalizedRGB(166, 172, 205);

    textRenderer->RenderText("Level: " + std::to_string(level + 1), 1050, 80, 0.5f, kTextColor);

    textRenderer->RenderText(std::to_string(60 - time + timeSinceLevel), resolution.x - 60, resolution.y - 50, 0.5f, kTextColor);
}

void m1::Tema1::RenderEnemies(float deltaTimeSeconds)
{
    // render enemies
    for (int i = 0; i < enemies.size(); ++i) {
        Enemy& enemy = enemies[i];

        // check if the enemy is out of the screen
        if (enemy.getTranslateX() + enemy.getCenter().x < startX + rectangleWidth || enemy.isDead()) {
            // if the enemy just died, remove it from the grid
            if (!enemy.isScaled()) {
                enemiesByColor[enemy.getY()][enemy.getColor()]--;

                if (!enemy.isDead()) {
                    nrLifes--;
                }
            }

            // check if the enemy is still dissapearing
            int check = enemy.disappear(deltaTimeSeconds);

            if (check == 0) {
                RenderMesh2D(enemy.GetHexa1(), shaders["VertexColor"], enemy.getModelMatrix());
                RenderMesh2D(enemy.GetHexa2(), shaders["VertexColor"], enemy.getModelMatrix());
            }
            else {
                // enemiesByColor[enemy.getY()][enemy.getColor()]--;
                enemies.erase(enemies.begin() + i);
            }
        }
        else {
            // if the enemy is not out of the screen or dead, translate it
            enemy.translate(deltaTimeSeconds);

            RenderMesh2D(enemy.GetHexa1(), shaders["VertexColor"], enemy.getModelMatrix());
            RenderMesh2D(enemy.GetHexa2(), shaders["VertexColor"], enemy.getModelMatrix());
        }
    }
}
