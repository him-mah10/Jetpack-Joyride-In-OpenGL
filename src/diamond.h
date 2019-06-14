#include "main.h"

#ifndef DIAMOND_H
#define DIAMOND_H


class Diamond {
public:
    Diamond() {}
    Diamond(float x, float y);
    glm::vec3 position;
    int count;
    void draw(glm::mat4 VP);
    void tick();
    double speed; 
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // DIAMOND_H
