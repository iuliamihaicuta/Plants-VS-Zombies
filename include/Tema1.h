#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/include/shapes.h"
#include "lab_m1/Tema1/include/enemies.h"
#include "lab_m1/Tema1/include/defense.h"
#include "lab_m1/Tema1/include/star.h"
#include "components/text_renderer.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1() = default;
        ~Tema1() = default;

        void Init() override;

        static glm::vec3 GetRandomColor();
        static int GetColorIdx(glm::vec3 color);
        static int getDistance();
        static int getSquareSide();
        static int getStartX();
        static int getStartY();
        static int getRectangleWidth();

        struct Color
        {
			glm::vec3 red = glm::vec3(0.941, 0.365, 0.302);
            glm::vec3 orange = glm::vec3(0.953, 0.576, 0.455);
            glm::vec3 yellow = glm::vec3(0.976, 0.804, 0.373);
            glm::vec3 blue = glm::vec3(0.102, 0.749, 0.773);

            glm::vec3 center = glm::vec3(0.988, 0.98, 0.396);
		};

    private:
        void CreateGrid();
        void CreateGUI();
        void RenderGrid();
        void RenderGUI(int time);
        glm::vec3 GetColor(int x);

        void UpdateEnemy(float deltaTimeSeconds);
        void UpdateStars(float deltaTimeSeconds);
        void UpdateRhombuses(float deltaTimeSeconds);
        bool m1::Tema1::isEnemyOnLine(int y);

        int getNumberOfStars(int color);
        void addStarToGUI();
        void addDefenseToGrid();
        void removeDefenseFromGrid();

        void GameOver();
        void LevelUp();
        void Win();

        void addEnemy();
        void CheckCollision();
        void RenderEnemies(float deltaTimeSeconds);

        void Tema1::AnimationDisappearDefense(std::vector<Defense>& defenseToDisappear, float deltaTimeSeconds);
        void CheckIfDefenseIsHit(Defense defense, int idx);
        void AttackEnemy(Defense& defense, float deltaTimeSeconds);

        int getSelectedRhombus(int mouseX, int mouseY);
        int getSelectedSquare(int mouseX, int mouseY);
        Star getSelectedStar(int mouseX, int mouseY);

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;


        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;

        void OnKeyPress(int key, int mods);


    protected:
        glm::ivec2 resolution;
        static const int distance = 30;
        static const int diffDistance = 25;
        static const int diffDistanceStar = 5.5;
        static const int squareSide = 125;
        static const int squareSide2 = 75;
        static const int rectangleWidth = 75;
        static const int rectangleHeight = 435;
        static const int startX = 20;
        static const int startY = 20;
        int radius = 19;
        int nrStars = 5;
        int nrLifes = 3;


        // vector of Mesh *
        std::vector<Defense> rhombuses;
 
        // enemies
        std::vector<Enemy> enemies;
        float lastRenderTimeEnemy = 0;
        int random = 0;
        // enemies by color and lines
        int enemiesByColor[3][5] = { 0 };

        // stars
        // std::vector<Mesh*> stars;
        std::vector<Star> stars;
        Star selectedStar = Star(glm::vec3(-1, -1, -1));
        
        float lastRenderTimeStar = 0;

        // rhombuses
        std::vector<Mesh*> squares;
        int selectedRhombus = -1;
        int selectedSquare = -1;
        int rhombusesGrid[3][3] = { 0 };

        std::vector<Defense> defensesToDisappear;

        int moveX = 0;
        int moveY = 0;
        bool drag = false;
        Defense defenseToDrag;


        GLenum polygonMode;
        gfxc::TextRenderer* textRenderer;

        int level = 0;
        int timeSinceLevel = -1;
        bool waitLevel = false;
        bool waitWin = false;
    };
}   // namespace m1
