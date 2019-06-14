#include "main.h"

#ifndef ENEMY3_H
#define ENEMY3_H


class Enemy3 {
public:
    Enemy3() {}
    Enemy3(float x, float y, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double speed;
    int count;
    bool detect_collision(float x,float y, float radius);
private:
    VAO *object;
};

#endif // ENEMY3_H
