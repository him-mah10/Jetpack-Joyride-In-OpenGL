#include "main.h"

#ifndef SC_H
#define SC_H


class SC {
public:
    SC() {}
    SC(float x, float y);
    glm::vec3 position;
    int count;
    double radius;
    void draw(glm::mat4 VP);
    void tick();
    double speed; 
private:
    VAO *object;
};

#endif // SC_H
