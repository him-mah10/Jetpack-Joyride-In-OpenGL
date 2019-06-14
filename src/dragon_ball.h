#include "main.h"

#ifndef DB_H
#define DB_H


class DB {
public:
    DB() {}
    DB(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double speed; 
    int count;
    double radius;
private:
    VAO *object;
};

#endif // DB_H
