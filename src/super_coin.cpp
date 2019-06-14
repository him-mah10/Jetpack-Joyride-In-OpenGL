#include "super_coin.h"
#include "main.h"

SC::SC(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->speed = 0.02;
    this->count=0;
    this->radius=0.15;

    GLfloat vertex_buffer_data[9000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f;
        vertex_buffer_data[i*9+1]=0.0f;
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+5]=0.0f;

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+8]=0.0f;
    };
    this->object = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, COLOR_BRONZE, GL_FILL);

}

void SC::draw(glm::mat4 VP) {
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

void SC::tick() 
{
    this->count++;
    this->position.x+=this->speed;
    if(this->count%60==0)
        this->position.x-=(this->count*this->speed);
    if(this->count%30==0)
        this->position.y+=(50*this->speed);
    else if(this->count%30 == 15)
        this->position.y-=(50*this->speed);
}