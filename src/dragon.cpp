#include "dragon.h"
#include "main.h"

Dragon::Dragon(float y) {
    this->position = glm::vec3(3.3, y, 0);
    this->count=0;
    GLfloat vertex_buffer_data1[9];
    GLfloat vertex_buffer_data2[9];
    GLfloat vertex_buffer_data3[18];
    GLfloat vertex_buffer_data4[9];
    GLfloat vertex_buffer_data5[9];

    vertex_buffer_data3[0]=0.4;
    vertex_buffer_data3[1]=0.15;
    vertex_buffer_data3[2]=0.0;

    vertex_buffer_data3[3]=0.4;
    vertex_buffer_data3[4]=-0.15;
    vertex_buffer_data3[5]=0.0;

    vertex_buffer_data3[6]=-0.4;
    vertex_buffer_data3[7]=0.15;
    vertex_buffer_data3[8]=0.0;

    vertex_buffer_data3[9]=0.4;
    vertex_buffer_data3[10]=-0.15;
    vertex_buffer_data3[11]=0.0;

    vertex_buffer_data3[12]=-0.4;
    vertex_buffer_data3[13]=0.15;
    vertex_buffer_data3[14]=0.0;

    vertex_buffer_data3[15]=-0.4;
    vertex_buffer_data3[16]=-0.15;
    vertex_buffer_data3[17]=0.0;

    
    vertex_buffer_data1[0]=-0.6;
    vertex_buffer_data1[1]=0.0;
    vertex_buffer_data1[2]=0.0;

    vertex_buffer_data1[3]=-0.4;
    vertex_buffer_data1[4]=0.08;
    vertex_buffer_data1[5]=0.0;

    vertex_buffer_data1[6]=-0.4;
    vertex_buffer_data1[7]=-0.08;
    vertex_buffer_data1[8]=0.0;    
    

    vertex_buffer_data2[0]=0.4;
    vertex_buffer_data2[1]=-0.15;
    vertex_buffer_data2[2]=0.0;

    vertex_buffer_data2[3]=-0.4;
    vertex_buffer_data2[4]=-0.15;
    vertex_buffer_data2[5]=0.0;

    vertex_buffer_data2[6]=-0.2;
    vertex_buffer_data2[7]=-0.30;
    vertex_buffer_data2[8]=0.0;


    vertex_buffer_data4[0]=0.4;
    vertex_buffer_data4[1]=0.15;
    vertex_buffer_data4[2]=0.0;

    vertex_buffer_data4[3]=-0.4;
    vertex_buffer_data4[4]=0.15;
    vertex_buffer_data4[5]=0.0;

    vertex_buffer_data4[6]=-0.2;
    vertex_buffer_data4[7]=0.30;
    vertex_buffer_data4[8]=0.0;


    vertex_buffer_data5[0]=0.4;
    vertex_buffer_data5[1]=0.0;
    vertex_buffer_data5[2]=0.0;

    vertex_buffer_data5[3]=0.6;
    vertex_buffer_data5[4]=0.08;
    vertex_buffer_data5[5]=0.0;

    vertex_buffer_data5[6]=0.6;
    vertex_buffer_data5[7]=-0.08;
    vertex_buffer_data5[8]=0.0;

    this->object1 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data1, COLOR_BROWN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_YELLOW, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_ORANGE, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data5, COLOR_ORANGE, GL_FILL);
}

void Dragon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    this->count++;
}