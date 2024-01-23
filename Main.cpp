#include "lab_m1/Tema1/include/Main.h"

#include <vector>
#include <iostream>

#include "include/transform2D.h"


using namespace std;
using namespace m1;

void Tema1::Init()
{
    // set resolution and camera position
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // set text variables
    polygonMode = GL_FILL;
    textRenderer = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    textRenderer->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 80);

    // create grid and GUI
    CreateGrid();
    CreateGUI();

    timeSinceLevel = Engine::GetElapsedTime();
}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.267, 0.306, 0.396, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
    // check if game is over
    if (nrLifes > 0) {
        int time = Engine::GetElapsedTime();
        if (time - timeSinceLevel > 60) {
            if (level == 3) {
                Win();
            }
            else

            LevelUp();

			// update time
			timeSinceLevel = time;
		}
        
        // render grid and GUI
        RenderGrid();
        RenderGUI(time);

        // update game elements
        UpdateStars(deltaTimeSeconds);
        UpdateEnemy(deltaTimeSeconds);
        UpdateRhombuses(deltaTimeSeconds);
    }
    else {
        if (waitLevel) {
            LevelUp();
        } else if (waitWin) {
            Win();
        } else {
			GameOver();
		}
    }
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
   // set the position of the mouse
   moveX += deltaX;
   moveY -= deltaY;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    
    // check if the left button was pressed
    if (button == 1) {
        // check if the mouse is near a star or a rhombus
        selectedStar = getSelectedStar(mouseX, 720 - mouseY);
        selectedRhombus = getSelectedRhombus(mouseX, 720 - mouseY);

        // if the mouse is near a rhombus, set drag to true
        if (selectedRhombus != -1) {
            drag = true;

            moveX = mouseX;
            moveY = 720 - mouseY;

            defenseToDrag = Defense(glm::vec3(0, 0, 49), GetColor(selectedRhombus));
        }
    } else if (button == 2) {
        // select the square if the right button was pressed
        selectedSquare = getSelectedSquare(mouseX, 720 - mouseY);
    }
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    drag = false;

    if (button == 1 && selectedStar.getCenter() != glm::vec3(-1, -1, -1)) {
        // add star to GUI
        addStarToGUI();
        selectedStar = Star(glm::vec3(-1, -1, -1));
    } else if (button == 1 && selectedRhombus != -1) {
        // add defense to grid
        selectedSquare = getSelectedSquare(mouseX, 720 - mouseY);

        if (selectedSquare != -1 && rhombusesGrid[selectedSquare / 3][selectedSquare % 3] != 1) {
            addDefenseToGrid();
        }

        selectedRhombus = -1;
        selectedSquare = -1;
    } else if (button == 2 && selectedSquare != -1) {
        // remove defense from grid
        if (rhombusesGrid[selectedSquare / 3][selectedSquare % 3] == 1) {
            // delete rhombus
            removeDefenseFromGrid();
        }
        selectedSquare = -1;
    }
}

void Tema1::OnKeyPress(int key, int mods)
{
    // restart the game if the space key was pressed
    if (key == GLFW_KEY_SPACE)
    {
        // reset all variables
        nrLifes = 3;
        
        if (!waitLevel) {
            nrStars = 5;
        }

        enemies.clear();
        stars.clear();
        rhombuses.clear();
        defensesToDisappear.clear();

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                enemiesByColor[i][j] = 0;
            }
        }

        lastRenderTimeEnemy = 0;
        random = 0;

        lastRenderTimeStar = 0;
        selectedStar = Star(glm::vec3(-1, -1, -1));
        selectedRhombus = -1;
        selectedSquare = -1;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                rhombusesGrid[i][j] = 0;
            }
        }
    // set text color and background color
    const glm::vec3 kTextColor = NormalizedRGB(166, 172, 205);
    const glm::vec3 kBackgroundColor = NormalizedRGB(41, 45, 62);

    // Render "GAME OVER" text in the middle of the screen
    textRenderer->RenderText("GAME OVER", resolution.x / 2 - 0.1 * resolution.x, resolution.y / 2 - 0.1 * resolution.y, 0.6f, kTextColor);

    // Render "Press SPACE to restart" text in the middle of the screen
    textRenderer->RenderText("Press SPACE to restart", resolution.x / 2 - 0.15f * resolution.x, resolution.y / 2, 0.4f, kTextColor);


        waitLevel = false;
        waitWin = false;
        timeSinceLevel = Engine::GetElapsedTime();
    }
}

void Tema1::GameOver()
{
	// set text color and background color
	const glm::vec3 kTextColor = NormalizedRGB(166, 172, 205);
	const glm::vec3 kBackgroundColor = NormalizedRGB(41, 45, 62);

	// Render "GAME OVER" text in the middle of the screen
	textRenderer->RenderText("GAME OVER", resolution.x / 2 - 0.1 * resolution.x, resolution.y / 2 - 0.1 * resolution.y, 0.6f, kTextColor);

	// Render "Press SPACE to restart" text in the middle of the screen
	textRenderer->RenderText("Press SPACE to restart", resolution.x / 2 - 0.15f * resolution.x, resolution.y / 2, 0.4f, kTextColor);

    level = 0;
}

void Tema1::LevelUp()
{
    if (!waitLevel) {
        waitLevel = true;

        level++;
        nrLifes = 0;
    }

    const glm::vec3 kTextColor = NormalizedRGB(166, 172, 205);
    const glm::vec3 kBackgroundColor = NormalizedRGB(41, 45, 62);

    // Render "NEXT LEVEL" text in the middle of the screen
    textRenderer->RenderText("NEXT LEVEL", resolution.x / 2 - 0.1 * resolution.x, resolution.y / 2 - 0.1 * resolution.y, 0.6f, kTextColor);
    textRenderer->RenderText("Press SPACE to continue", resolution.x / 2 - 0.15f * resolution.x, resolution.y / 2, 0.4f, kTextColor);
}

void Tema1::Win()
{
    if (!waitWin) {
        waitWin = true;
        nrLifes = 0;

        level = 0;
    }
    
    // set text color and background color
	const glm::vec3 kTextColor = NormalizedRGB(166, 172, 205);
	const glm::vec3 kBackgroundColor = NormalizedRGB(41, 45, 62);

	// Render "YOU WIN" text in the middle of the screen
	textRenderer->RenderText("YOU WIN", resolution.x / 2 - 0.1 * resolution.x, resolution.y / 2 - 0.1 * resolution.y, 0.6f, kTextColor);

	// Render "Press SPACE to restart" text in the middle of the screen
	textRenderer->RenderText("Press SPACE to restart", resolution.x / 2 - 0.15f * resolution.x, resolution.y / 2, 0.4f, kTextColor);
}
