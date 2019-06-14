#include "main.h"

#ifndef SCORE_H
#define SCORE_H


class Score {
public:
    Score() {}
    Score(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick(int score,int len,int type);
    int ver;
    GLfloat vertex_buffer_data[435];
private:
    VAO *object;
    void zero(float pos,int type);
    void one(float pos,int type);
    void two(float pos,int type);
    void three(float pos,int type);
    void four(float pos,int type);
    void five(float pos,int type);
    void six(float pos,int type);
    void seven(float pos,int type);
    void eight(float pos,int type);
    void nine(float pos,int type);
};

#endif // SCORE_H
