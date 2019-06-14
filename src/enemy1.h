#include "main.h"

#ifndef ENEMY1_H
#define ENEMY1_H


class Enemy1 {
public:
    Enemy1() {}
    Enemy1(float x, float y, color_t color);
    glm::vec3 position;
    double speed;
    double theta;
    void draw(glm::mat4 VP);
    double radius;
    double distance(float x,float y);
    void tick();
private:
    VAO *object;
    VAO *object1;
};

#endif // ENEMY1_H
