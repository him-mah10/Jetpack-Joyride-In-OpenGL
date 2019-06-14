#include "main.h"

#ifndef PROP_H
#define PROP_H


class Prop {
public:
    Prop() {}
    Prop(float x, float y, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick(float arg);
    GLfloat vertex_buffer_data[18];
private:
    VAO *object;
};

#endif // PROP_H
