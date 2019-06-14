#include "main.h"

#ifndef MAG_H
#define MAG_H


class Mag {
public:
    Mag() {}
    Mag(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    GLfloat vertex_buffer_data_red[54];
    GLfloat vertex_buffer_data_blue[36];
private:
    VAO *object_red;
    VAO *object_blue;
};

#endif // MAG_H