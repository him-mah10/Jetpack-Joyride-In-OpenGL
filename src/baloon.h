#include "main.h"

#ifndef BALOON_H
#define BALOON_H


class Baloon {
public:
    Baloon() {}
    Baloon(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double ga;
    double radius;
    double speed;
    double down_speed;
private:
    VAO *object;
};

#endif // BALOON_H
