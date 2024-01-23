#include "include/shapes.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* shapes::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* shapes::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* shapes::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    float halfRadius = radius / 2.5;
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center, color),
		VertexFormat(center + glm::vec3(radius * cos(0), radius * sin(0), 0), color),
        VertexFormat(center + glm::vec3(halfRadius * cos(0 + M_PI / 5), halfRadius * sin(0 + M_PI / 5), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(2 * M_PI / 5), radius * sin(2 * M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(halfRadius * cos(2 * M_PI / 5 + M_PI / 5), halfRadius * sin(2 * M_PI / 5 + M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(radius * cos(4 * M_PI / 5), radius * sin(4 * M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(halfRadius * cos(4 * M_PI / 5 + M_PI / 5), halfRadius * sin(4 * M_PI / 5 + M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(radius * cos(6 * M_PI / 5), radius * sin(6 * M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(halfRadius * cos(6 * M_PI / 5 + M_PI / 5), halfRadius * sin(6 * M_PI / 5 + M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(radius * cos(8 * M_PI / 5), radius * sin(8 * M_PI / 5), 0), color),
        VertexFormat(center + glm::vec3(halfRadius * cos(8 * M_PI / 5 + M_PI / 5), halfRadius * sin(8 * M_PI / 5 + M_PI / 5), 0), color)
	};

	Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1};

    if (fill) {

        star->SetDrawMode(GL_TRIANGLE_FAN);
    }
    else {
        // Draw the star outline with a line loop
        star->SetDrawMode(GL_LINE_LOOP);
    }

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* shapes::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float radius,
    bool fill)
{
    float halfRadius = radius / 2.5;
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center, glm::vec3(0.988, 0.98, 0.396)),
        VertexFormat(center + glm::vec3(radius * cos(0), radius * sin(0), 0), glm::vec3(0.941, 0.365, 0.302)),
        VertexFormat(center + glm::vec3(halfRadius * cos(0 + M_PI / 5), halfRadius * sin(0 + M_PI / 5), 0), glm::vec3(0.941, 0.365, 0.302)),
        VertexFormat(center + glm::vec3(radius * cos(2 * M_PI / 5), radius * sin(2 * M_PI / 5), 0), glm::vec3(0.953, 0.576, 0.455)),
        VertexFormat(center + glm::vec3(halfRadius * cos(2 * M_PI / 5 + M_PI / 5), halfRadius * sin(2 * M_PI / 5 + M_PI / 5), 0), glm::vec3(0.953, 0.576, 0.455)),
        VertexFormat(center + glm::vec3(radius * cos(4 * M_PI / 5), radius * sin(4 * M_PI / 5), 0), glm::vec3(0.976, 0.804, 0.373)),
        VertexFormat(center + glm::vec3(halfRadius * cos(4 * M_PI / 5 + M_PI / 5), halfRadius * sin(4 * M_PI / 5 + M_PI / 5), 0), glm::vec3(0.976, 0.804, 0.373)),
        VertexFormat(center + glm::vec3(radius * cos(6 * M_PI / 5), radius * sin(6 * M_PI / 5), 0), glm::vec3(0.941, 0.365, 0.302)),
        VertexFormat(center + glm::vec3(halfRadius * cos(6 * M_PI / 5 + M_PI / 5), halfRadius * sin(6 * M_PI / 5 + M_PI / 5), 0), glm::vec3(0.941, 0.365, 0.302)),
        VertexFormat(center + glm::vec3(radius * cos(8 * M_PI / 5), radius * sin(8 * M_PI / 5), 0), glm::vec3(0.102, 0.749, 0.773)),
        VertexFormat(center + glm::vec3(halfRadius * cos(8 * M_PI / 5 + M_PI / 5), halfRadius * sin(8 * M_PI / 5 + M_PI / 5), 0), glm::vec3(0.102, 0.749, 0.773))
    };

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1 };

    if (fill) {

        star->SetDrawMode(GL_TRIANGLE_FAN);
    }
    else {
        // Draw the star outline with a line loop
        star->SetDrawMode(GL_LINE_LOOP);
    }

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* shapes::CreateHexagon(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
		VertexFormat(center + glm::vec3(radius * cos(0), radius * sin(0), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(M_PI / 3), radius * sin(M_PI / 3), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(2 * M_PI / 3), radius * sin(2 * M_PI / 3), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(M_PI), radius * sin(M_PI), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(4 * M_PI / 3), radius * sin(4 * M_PI / 3), 0), color),
		VertexFormat(center + glm::vec3(radius * cos(5 * M_PI / 3), radius * sin(5 * M_PI / 3), 0), color)
	};

	Mesh* hexagon = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5 };

    if (fill) {
		hexagon->SetDrawMode(GL_TRIANGLE_FAN);
	}
    else {
		// Draw the hexagon outline with a line loop
		hexagon->SetDrawMode(GL_LINE_LOOP);
	}

	hexagon->InitFromData(vertices, indices);
	return hexagon; 
}

Mesh* shapes::CreateRhombus(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center + glm::vec3(0, radius, 0), color),
        VertexFormat(center + glm::vec3(radius / 2, 0, 0), color),
        VertexFormat(center + glm::vec3(0, -radius, 0), color),
        VertexFormat(center + glm::vec3(-radius / 2, 0, 0), color),
        VertexFormat(center + glm::vec3(0, radius / 4, 0), color),
        VertexFormat(center + glm::vec3(1.5 * radius, radius / 4, 0), color),
        VertexFormat(center + glm::vec3(1.5 * radius, -radius / 4, 0), color),
        VertexFormat(center + glm::vec3(0, -radius / 4, 0), color)
    };

    Mesh* rhombus = new Mesh(name);

    std::vector<unsigned int> indices;

    if (fill) {
        indices = 
        {
            0, 1, 2,
            3, 0, 2,
            4, 5, 7,
            5, 6, 7
        };
		rhombus->SetDrawMode(GL_TRIANGLES);
	}
    else {
		// Draw the rhombus outline with a line loop
        indices = { 0, 1, 2, 3, 0, 7, 6, 5, 4 };
		rhombus->SetDrawMode(GL_LINE_LOOP);
	}

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}

Mesh* shapes::CreateRhombus(
    const std::string& name,
    glm::vec3 center,
    float radius,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center + glm::vec3(0, radius, 0),glm::vec3(0.976, 0.804, 0.373)),
        VertexFormat(center + glm::vec3(radius / 2, 0, 0), glm::vec3(0.953, 0.576, 0.455)),
        VertexFormat(center + glm::vec3(0, -radius, 0), glm::vec3(0.976, 0.804, 0.373)),
        VertexFormat(center + glm::vec3(-radius / 2, 0, 0), glm::vec3(0.941, 0.365, 0.302)),
        VertexFormat(center + glm::vec3(0, radius / 4, 0), glm::vec3(0.953, 0.576, 0.455)),
        VertexFormat(center + glm::vec3(1.5 * radius, radius / 4, 0), glm::vec3(0.102, 0.749, 0.773)),
        VertexFormat(center + glm::vec3(1.5 * radius, -radius / 4, 0), glm::vec3(0.102, 0.749, 0.773)),
        VertexFormat(center + glm::vec3(0, -radius / 4, 0), glm::vec3(0.953, 0.576, 0.455))
    };

    Mesh* rhombus = new Mesh(name);

    std::vector<unsigned int> indices;

    if (fill) {
        indices =
        {
            0, 1, 2,
            3, 0, 2,
            4, 5, 7,
            5, 6, 7
        };
        rhombus->SetDrawMode(GL_TRIANGLES);
    }
    else {
        // Draw the rhombus outline with a line loop
        indices = { 0, 1, 2, 3, 0, 7, 6, 5, 4 };
        rhombus->SetDrawMode(GL_LINE_LOOP);
    }

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}