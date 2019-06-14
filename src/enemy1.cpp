#include "enemy1.h"
#include "main.h"


Enemy1::Enemy1(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->radius=0.1;
    this->speed=0.02;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    this->theta = 3.14159265/180*(rand()%90);
    GLfloat vertex_buffer_data[18000];
    GLfloat vertex_buffer_data1[18];
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
    for (int i=1000;i<2000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f+sin(this->theta);
        vertex_buffer_data[i*9+1]=0.0f-1*cos(this->theta);
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)+sin(this->theta);
        vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000)-1*cos(this->theta);
        vertex_buffer_data[i*9+5]=0.0f;

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)+sin(this->theta);
        vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)-1*cos(this->theta);
        vertex_buffer_data[i*9+8]=0.0f;
    };
    vertex_buffer_data1[0]=0.0;
    vertex_buffer_data1[1]=0.0;
    vertex_buffer_data1[2]=0.0;  

    vertex_buffer_data1[3]=sin(this->theta);
    vertex_buffer_data1[4]=-1*cos(this->theta);
    vertex_buffer_data1[5]=0.0;

    vertex_buffer_data1[6]=sin(this->theta)-0.02;
    vertex_buffer_data1[7]=-1*cos(this->theta)-0.02;
    vertex_buffer_data1[8]=0.0;

    vertex_buffer_data1[9]=0.0;
    vertex_buffer_data1[10]=0.0;
    vertex_buffer_data1[11]=0.0;

    vertex_buffer_data1[12]=sin(this->theta);
    vertex_buffer_data1[13]=-1*cos(this->theta);
    vertex_buffer_data1[14]=0.0;

    vertex_buffer_data1[15]=0.02;
    vertex_buffer_data1[16]=0.02;
    vertex_buffer_data1[17]=0.0;
    //this->object = glDrawArrays(GL_TRIANGLES, 0, 3);
    this->object = create3DObject(GL_TRIANGLES, 6000, vertex_buffer_data, COLOR_ORANGE, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, color, GL_FILL);
}

void Enemy1::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object);
}

double Enemy1::distance(float x,float y)
{
    double m=-1/tan(theta);
    double a=(y - (x*m) + (m*this->position.x) - this->position.y);//(sqrt(1+(m*m));
    if(a<0)
        a*=-1;
    return a/sqrt(1+m*m);
}

void Enemy1::tick() 
{
   this->position.x-=this->speed;
}