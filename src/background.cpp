#include "background.h"
#include "main.h"

Background::Background(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->speed = 0.005;
    GLfloat vertex_buffer_data1[18];
    GLfloat vertex_buffer_data2[18];
    GLfloat vertex_buffer_data3[18];

    GLfloat vertex_buffer_data4[9];
    GLfloat vertex_buffer_data5[9];
    GLfloat vertex_buffer_data6[9];
    GLfloat vertex_buffer_data7[9];
    
    vertex_buffer_data1[0]=2;
    vertex_buffer_data1[1]=2.5;
    vertex_buffer_data1[2]=0;

    vertex_buffer_data1[3]=2;
    vertex_buffer_data1[4]=0;
    vertex_buffer_data1[5]=0;

    vertex_buffer_data1[6]=-2;
    vertex_buffer_data1[7]=2.5;
    vertex_buffer_data1[8]=0;

    vertex_buffer_data1[9]=2;
    vertex_buffer_data1[10]=0;
    vertex_buffer_data1[11]=0;

    vertex_buffer_data1[12]=-2;
    vertex_buffer_data1[13]=2.5;
    vertex_buffer_data1[14]=0;

    vertex_buffer_data1[15]=-2;
    vertex_buffer_data1[16]=0;
    vertex_buffer_data1[17]=0;


    vertex_buffer_data2[0]=2;
    vertex_buffer_data2[1]=0;
    vertex_buffer_data2[2]=0;

    vertex_buffer_data2[3]=2;
    vertex_buffer_data2[4]=-0.75;
    vertex_buffer_data2[5]=0;

    vertex_buffer_data2[6]=-2;
    vertex_buffer_data2[7]=0;
    vertex_buffer_data2[8]=0;

    vertex_buffer_data2[9]=2;
    vertex_buffer_data2[10]=-0.75;
    vertex_buffer_data2[11]=0;

    vertex_buffer_data2[12]=-2;
    vertex_buffer_data2[13]=0;
    vertex_buffer_data2[14]=0;

    vertex_buffer_data2[15]=-2;
    vertex_buffer_data2[16]=-0.75;
    vertex_buffer_data2[17]=0;


    vertex_buffer_data3[0]=2;
    vertex_buffer_data3[1]=-0.75;
    vertex_buffer_data3[2]=0;

    vertex_buffer_data3[3]=2;
    vertex_buffer_data3[4]=-2.5;
    vertex_buffer_data3[5]=0;

    vertex_buffer_data3[6]=-2;
    vertex_buffer_data3[7]=-0.75;
    vertex_buffer_data3[8]=0;

    vertex_buffer_data3[9]=2;
    vertex_buffer_data3[10]=-2.5;
    vertex_buffer_data3[11]=0;

    vertex_buffer_data3[12]=-2;
    vertex_buffer_data3[13]=-0.75;
    vertex_buffer_data3[14]=0;

    vertex_buffer_data3[15]=-2;
    vertex_buffer_data3[16]=-2.5;
    vertex_buffer_data3[17]=0;


    
    vertex_buffer_data4[0]=2;
    vertex_buffer_data4[1]=2.5;
    vertex_buffer_data4[2]=0;

    vertex_buffer_data4[3]=2;
    vertex_buffer_data4[4]=1.8;
    vertex_buffer_data4[5]=0;

    vertex_buffer_data4[6]=1.3;
    vertex_buffer_data4[7]=2.5;
    vertex_buffer_data4[8]=0;


    vertex_buffer_data5[0]=-2;
    vertex_buffer_data5[1]=2.5;
    vertex_buffer_data5[2]=0;

    vertex_buffer_data5[3]=-2;
    vertex_buffer_data5[4]=1.8;
    vertex_buffer_data4[5]=0;

    vertex_buffer_data5[6]=-1.3;
    vertex_buffer_data5[7]=2.5;
    vertex_buffer_data5[8]=0;


    vertex_buffer_data6[0]=2;
    vertex_buffer_data6[1]=-2.5;
    vertex_buffer_data6[2]=0;

    vertex_buffer_data6[3]=2;
    vertex_buffer_data6[4]=-1.5;
    vertex_buffer_data6[5]=0;

    vertex_buffer_data6[6]=1.3;
    vertex_buffer_data6[7]=-2.5;
    vertex_buffer_data6[8]=0;


    vertex_buffer_data7[0]=-2;
    vertex_buffer_data7[1]=-2.5;
    vertex_buffer_data7[2]=0;

    vertex_buffer_data7[3]=-2;
    vertex_buffer_data7[4]=-1.5;
    vertex_buffer_data7[5]=0;

    vertex_buffer_data7[6]=-1.3;
    vertex_buffer_data7[7]=-2.5;
    vertex_buffer_data7[8]=0;

this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_BACKGROUND1, GL_FILL);
this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_BACKGROUND2, GL_FILL);
this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_BACKGROUND3, GL_FILL);
this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_BACKGROUND, GL_FILL);
this->object5 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data5, COLOR_BACKGROUND, GL_FILL);
this->object6 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data6, COLOR_BACKGROUND, GL_FILL);
this->object7 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data7, COLOR_BACKGROUND, GL_FILL);
}

void Background::draw(glm::mat4 VP) {
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
    draw3DObject(this->object6);
    draw3DObject(this->object7);
}
void Background::tick() 
{
    this->position.x-=this->speed;
}
