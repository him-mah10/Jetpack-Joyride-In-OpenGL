#include "main.h"

#ifndef COINS_H
#define COINS_H


class Coins {
public:
    Coins() {}
    Coins(float x, float y, color_t color);
    glm::vec3 position;
    double speed;
    double radius;
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *object;
};

#endif // COINS_H
