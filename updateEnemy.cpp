#include "include/Main.h"

void m1::Tema1::addEnemy()
{
    // generate random number between 5 and 8;
    float time = Engine::GetElapsedTime();
    if (random == 0) {
        random = rand() % 4 + 5;
    }

    // add enemy if time passed
    if (lastRenderTimeEnemy == 0 || time - lastRenderTimeEnemy > random) {
        // get new enemy of random color on random line
        Enemy enemy(resolution.x, level);
        enemies.push_back(enemy);
        enemiesByColor[enemy.getY()][enemy.getColor()]++;

        lastRenderTimeEnemy = time;
        random = 0;
    }
}

void m1::Tema1::CheckCollision()
{
    for (int i = 0; i < enemies.size(); ++i) {
        Enemy& enemy = enemies[i];

        for (int j = 0; j < rhombuses.size(); ++j) {
            Defense& defense = rhombuses[j];

            // check if the enemy is on the same line
            if ((enemy.getColor() == defense.getColor() || defense.isColorful()) && enemy.getY() == defense.getY()) {
                float enemyX = enemy.getTranslateX() + enemy.getCenter().x;

                // check if the enemy is in the range of the defense
                for (int k = 0; k < defense.getStars().size(); ++k) {
                    Star& star = defense.getStars()[k];
                    float starX = star.getTranslateX() + star.getCenter().x;

                    float distance = enemyX - starX;
                    if (distance < 35) {
                        // enemy is hit
                        enemiesByColor[enemy.getY()][enemy.getColor()]--;
                        enemy.loseLife();
                        enemiesByColor[enemy.getY()][enemy.getColor()]++;
                        defense.getStars().erase(defense.getStars().begin() + k);
                    }
                }
            }
        }
    }
}

void m1::Tema1::UpdateEnemy(float deltaTimeSeconds)
{
    addEnemy();
    CheckCollision();
    RenderEnemies(deltaTimeSeconds);
}
