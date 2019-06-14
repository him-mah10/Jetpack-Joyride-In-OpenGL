#include "main.h"

#ifndef ENEMY2_H
#define ENEMY2_H


class Enemy2 {
public:
    Enemy2() {}
    Enemy2(float y, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius;
    double distance(float x,float y);
    void tick();
    int number_of_vertices;
    GLfloat vertex_buffer_data[36000];
    GLfloat vertex_buffer_data1[36];
    int count;
private:
    VAO *object;
    VAO *object1;
};

#endif // ENEMY2_H
