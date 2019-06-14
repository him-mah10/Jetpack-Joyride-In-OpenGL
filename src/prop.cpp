#include "prop.h"
#include "main.h"

Prop::Prop(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    
    this->vertex_buffer_data[0]=-1.0;
    this->vertex_buffer_data[1]=-3.25;
    this->vertex_buffer_data[2]=0.0;

    this->vertex_buffer_data[3]=1.0;
    this->vertex_buffer_data[4]=-3.25;
    this->vertex_buffer_data[5]=0.0;

    this->vertex_buffer_data[6]=-1.0;
    this->vertex_buffer_data[7]=-3.75;
    this->vertex_buffer_data[8]=0.0;

    this->vertex_buffer_data[9]=1.0;
    this->vertex_buffer_data[10]=-3.25;
    this->vertex_buffer_data[11]=0.0;

    this->vertex_buffer_data[12]=-1.0;
    this->vertex_buffer_data[13]=-3.75;
    this->vertex_buffer_data[14]=0.0;

    this->vertex_buffer_data[15]=1.0;
    this->vertex_buffer_data[16]=-3.75;
    this->vertex_buffer_data[17]=0.0;
    this->object = create3DObject(GL_TRIANGLES, 6, this->vertex_buffer_data, color, GL_FILL);
}

void Prop::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->object = create3DObject(GL_TRIANGLES, 6, this->vertex_buffer_data, COLOR_GREENO, GL_FILL);
    draw3DObject(this->object);
}

void Prop::tick(float arg) 
{
    this->vertex_buffer_data[0]=-1.0;
    this->vertex_buffer_data[1]=-3.25;
    this->vertex_buffer_data[2]=0.0;

    this->vertex_buffer_data[3]=-1.0+arg;
    this->vertex_buffer_data[4]=-3.25;
    this->vertex_buffer_data[5]=0.0;

    this->vertex_buffer_data[6]=-1.0;
    this->vertex_buffer_data[7]=-3.75;
    this->vertex_buffer_data[8]=0.0;

    this->vertex_buffer_data[9]=-1.0+arg;
    this->vertex_buffer_data[10]=-3.25;
    this->vertex_buffer_data[11]=0.0;

    this->vertex_buffer_data[12]=-1.0+arg;
    this->vertex_buffer_data[13]=-3.75;
    this->vertex_buffer_data[14]=0.0;

    this->vertex_buffer_data[15]=-1.0;
    this->vertex_buffer_data[16]=-3.75;
    this->vertex_buffer_data[17]=0.0;
}
