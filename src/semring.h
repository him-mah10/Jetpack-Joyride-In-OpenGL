#include "main.h"

#ifndef SEMRING_H
#define SEMRING_H


class Semring {
public:
    Semring() {}
    Semring(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius_outer;
    double radius_inner;
    int count;
    void tick();
private:
    VAO *object_outer;
    VAO *object_inner;
};

#endif // SEMRING_H
