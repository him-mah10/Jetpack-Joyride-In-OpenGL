#include "enemy3.h"
#include "main.h"

Enemy3::Enemy3(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->speed = 0.07;
    this->count=0;
    static const GLfloat vertex_buffer_data[] = {
         0.0f, 0.0f, 0.0f,
         -0.1f, 0.2f, 0.0f,
         0.6f, 0.0f, 0.0f,
         0.0f, 0.0f, 0.0f,
         0.6f, 0.0f, 0.0f,
         -0.1f, -0.2f , 0.0f
    };
    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Enemy3::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Enemy3::tick() 
{
    (this->count)+=1;
    if(this->count<60)
    {
        this->position.x-=0.03;
        this->position.y-=0.007;
    }
    else if(this->count<101)
    {
        this->position.x-=0.007;
        this->position.y-=0.03;
    }
    else
    {
        this->position.x+=0.03;
        this->position.y-=0.007;
    }
}

bool Enemy3::detect_collision(float x,float y,float radius)
{
    float width_this=0.7;
    float height_this=0.4;
    
    float distance_center_x=x-this->position.x-0.25;
    float distance_center_y=y-this->position.y;
    
    if(distance_center_y<0)
        distance_center_y*=-1;
    if(distance_center_x<0)
        distance_center_x*=-1;   

    if( distance_center_x < (radius+width_this) && distance_center_y < (radius + height_this) )
    {
        return true;
    }
    else
        return false;
}