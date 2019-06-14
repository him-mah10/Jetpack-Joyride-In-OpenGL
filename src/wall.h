#include "main.h"

#ifndef WALL_H
#define WALL_H


class Wall {
public:
    Wall() {}
    Wall(int pos, color_t color);
    int pos;
    glm::vec3 position;
    void tick(int arg);
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // WALL_H
