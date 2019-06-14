#include "main.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background {
public:
    Background() {}
    Background(float x, float y);
    glm::vec3 position;
    double speed;
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
};

#endif // BACKGROUND_H
