#include "semring.h"
#include "main.h"

Semring::Semring(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->radius_inner=1.2;
    this->radius_outer=1.8;
    this->count=0;
    GLfloat vertex_buffer_data_inner[4500];
    for (int i=0;i<500;i++)
    { 
        vertex_buffer_data_inner[i*9+0]=0.0f;
        vertex_buffer_data_inner[i*9+1]=0.0f;
        vertex_buffer_data_inner[i*9+2]=0.0f;

        vertex_buffer_data_inner[i*9+3]=this->radius_inner*cos(2*3.14159265*i/1000);
        vertex_buffer_data_inner[i*9+4]=this->radius_inner*sin(2*3.14159265*i/1000);
        vertex_buffer_data_inner[i*9+5]=0.0f;

        vertex_buffer_data_inner[i*9+6]=this->radius_inner*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_inner[i*9+7]=this->radius_inner*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_inner[i*9+8]=0.0f;
    };
    //this->object = glDrawArrays(GL_TRIANGLES, 0, 3);
    this->object_inner = create3DObject(GL_TRIANGLES, 1500, vertex_buffer_data_inner, COLOR_BACKGROUND1, GL_FILL);

    GLfloat vertex_buffer_data_outer[4500];
    for (int i=0;i<500;i++)
    { 
        vertex_buffer_data_outer[i*9+0]=0.0f;
        vertex_buffer_data_outer[i*9+1]=0.0f;
        vertex_buffer_data_outer[i*9+2]=0.0f;

        vertex_buffer_data_outer[i*9+3]=this->radius_outer*cos(2*3.14159265*i/1000);
        vertex_buffer_data_outer[i*9+4]=this->radius_outer*sin(2*3.14159265*i/1000);
        vertex_buffer_data_outer[i*9+5]=0.0f;

        vertex_buffer_data_outer[i*9+6]=this->radius_outer*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_outer[i*9+7]=this->radius_outer*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_outer[i*9+8]=0.0f;
    };
    //this->object = glDrawArrays(GL_TRIANGLES, 0, 3);
    this->object_outer = create3DObject(GL_TRIANGLES, 1500, vertex_buffer_data_outer, COLOR_SEMRING, GL_FILL);
}

void Semring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_outer);
    draw3DObject(this->object_inner);
}

void Semring::tick()
{
    this->count+=1;
}