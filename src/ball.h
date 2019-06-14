#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(int arg);
    double ga;
    bool move_left;
    double radius;
    bool move_right;
    double speed;
    double ospeed;
    double oga;
    double upspeed;
    double odown_speed;
    double pro_speed;
    double down_speed;
    //double sub_speed;
    void increase_down_speed(); 
private:
    VAO *object;
    VAO *object1;
};

#endif // BALL_H
