#include "include/Tema1.h"
#include "include/transform2D.h"

void m1::Tema1::UpdateStars(float deltaTimeSeconds) {
    float time = Engine::GetElapsedTime();

    // add stars at random locations every 8 seconds
    if (lastRenderTimeStar == 0 || time - lastRenderTimeStar > 8) {
        // add 3 stars
        for (int i = 0; i < 3; ++i) {
            int x = rand() % resolution.x;
            int y = rand() % resolution.y;
            Star star(glm::vec3(x, y, 45));
            stars.push_back(star);
        }

        lastRenderTimeStar = time;
    }

    /// render stars
    for (Star star : stars) {
        RenderMesh2D(star.getStar(), shaders["VertexColor"], glm::mat3(1));
    }
}

void m1::Tema1::AnimationDisappearDefense(std::vector<Defense>& defense, float deltaTimeSeconds)
{
    for (Defense& defense : defensesToDisappear) {
        // scale the rhombus until it disappears
        int check = defense.disappear(deltaTimeSeconds);

        if (check == 0) {
            RenderMesh2D(defense.getRhombus(), shaders["VertexColor"], defense.getModelMatrix());
        }
        else {
			// remove from vector
            defensesToDisappear.erase(defensesToDisappear.begin());
		}
    }
}

void m1::Tema1::CheckIfDefenseIsHit(Defense defense, int idx)
{
    for (Enemy enemy : enemies) {
        // check if the enemy is on the same line
        if (enemy.getY() == defense.getY()) {
            int enemyX = enemy.getTranslateX() + enemy.getCenter().x;
            int defenseX = defense.getCenter().x;

            if (enemyX >= defenseX - squareSide / 2 && enemyX <= defenseX + squareSide / 2) {
                // remove from rhombuses
                defensesToDisappear.push_back(Defense(defense.getCenter(), defense.getColorVec()));
                rhombuses.erase(rhombuses.begin() + idx);
                rhombusesGrid[defense.getX()][defense.getY()] = 0;
            }
        }
    }
}

void m1::Tema1::AttackEnemy(Defense& defense, float deltaTimeSeconds)
{
    // check if there are enemies on the same line with the same color
    if (enemiesByColor[defense.getY()][defense.getColor()] > 0 || (isEnemyOnLine(defense.getY()) && defense.isColorful())) {
        // add star every 2 seconds
        int currentTime = Engine::GetElapsedTime();
        float timeBetweenStars = 1.5f;

        if (defense.getTimeSinceLastStar() == -1 || currentTime - defense.getTimeSinceLastStar() > timeBetweenStars) {
            defense.setTimeSinceLastStar(currentTime + static_cast<int>(timeBetweenStars));
            defense.addStar(Star(glm::vec3(defense.getCenter().x, defense.getCenter().y, 45), defense.getColorVec()));
        }
    }

    // rotate all stars
    defense.rotateStars(deltaTimeSeconds);
    for (Star& star : defense.getStars()) {
        RenderMesh2D(star.getStar(), shaders["VertexColor"], star.getModelMatrix());
    }
}

void m1::Tema1::UpdateRhombuses(float deltaTimeSeconds)
{
    // render the rhombus that is dragged at the mouse position
    if (drag) {
        RenderMesh2D(defenseToDrag.getRhombus(), shaders["VertexColor"], transform2D::Translate(moveX, moveY));
    }

    for (int i = 0; i < rhombuses.size(); ++i) {
        Defense& defense = rhombuses[i];

        // check if the defense is hit and remove it if it is
        CheckIfDefenseIsHit(defense, i);
        // attack the enemies if there are any on the same line with the same color
        AttackEnemy(defense, deltaTimeSeconds);
    }

    for (int i = 0; i < rhombuses.size(); ++i) {
        Defense& defense = rhombuses[i];
        RenderMesh2D(defense.getRhombus(), shaders["VertexColor"], glm::mat3(1));
    }

    // render the animation of the rhombuses that are hit
    AnimationDisappearDefense(defensesToDisappear, deltaTimeSeconds);
}

bool m1::Tema1::isEnemyOnLine(int y) {
    return enemiesByColor[y][1] + enemiesByColor[y][2] + enemiesByColor[y][3] + enemiesByColor[y][4] > 0;
}
