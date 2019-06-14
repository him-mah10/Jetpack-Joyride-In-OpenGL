#include "enemy2.h"
#include "main.h"


Enemy2::Enemy2(float y, color_t color) {
    this->position = glm::vec3(0, y, 0);
    this->radius=0.01;
    this->number_of_vertices=0;
    this->count=0;
    for (int i=0;i<1000;i++)
    { 
        this->vertex_buffer_data[i*9+0]=-3.95f;
        this->vertex_buffer_data[i*9+1]=0.0f;
        this->vertex_buffer_data[i*9+2]=0.0f;

        this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)-3.95;
        this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        this->vertex_buffer_data[i*9+5]=0.0f;

        this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)-3.95;
        this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        this->vertex_buffer_data[i*9+8]=0.0f;
    };
    for (int i=1000;i<2000;i++)
    { 
        this->vertex_buffer_data[i*9+0]=-3.95f;
        this->vertex_buffer_data[i*9+1]=0.0f+2.0;
        this->vertex_buffer_data[i*9+2]=0.0f;

        this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)-3.95;
        this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000)+2.0;
        this->vertex_buffer_data[i*9+5]=0.0f;

        this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)-3.95;
        this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)+2.0;
        this->vertex_buffer_data[i*9+8]=0.0f;
    };
    for (int i=2000;i<3000;i++)
    { 
        this->vertex_buffer_data[i*9+0]=3.95f;
        this->vertex_buffer_data[i*9+1]=0.0f;
        this->vertex_buffer_data[i*9+2]=0.0f;

        this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)+3.95;
        this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        this->vertex_buffer_data[i*9+5]=0.0f;

        this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)+3.95;
        this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        this->vertex_buffer_data[i*9+8]=0.0f;
    };
    for (int i=3000;i<4000;i++)
    { 
        this->vertex_buffer_data[i*9+0]=3.95f;
        this->vertex_buffer_data[i*9+1]=0.0f+2.0;
        this->vertex_buffer_data[i*9+2]=0.0f;

        this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)+3.95;
        this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000)+2.0;
        this->vertex_buffer_data[i*9+5]=0.0f;

        this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)+3.95;
        this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)+2.0;
        this->vertex_buffer_data[i*9+8]=0.0f;
    }

    /**/
    //this->object = glDrawArrays(GL_TRIANGLES, 0, 3);
    this->object = create3DObject(GL_TRIANGLES, 12000, this->vertex_buffer_data, COLOR_ORANGE, GL_FILL);
}

void Enemy2::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->object = create3DObject(GL_TRIANGLES, 12000, this->vertex_buffer_data, COLOR_BLACK, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, this->number_of_vertices, this->vertex_buffer_data1, COLOR_FIRE, GL_FILL);
    draw3DObject(this->object1);
    draw3DObject(this->object);
}

void Enemy2::tick() 
{
   this->count++;
   if(count<=120)
   {
        this->radius+=0.0009;
        for (int i=0;i<1000;i++)
        { 
            this->vertex_buffer_data[i*9+0]=-3.95f;
            this->vertex_buffer_data[i*9+1]=0.0f;
            this->vertex_buffer_data[i*9+2]=0.0f;

            this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)-3.95;
            this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
            this->vertex_buffer_data[i*9+5]=0.0f;

            this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)-3.95;
            this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
            this->vertex_buffer_data[i*9+8]=0.0f;
        }

        for (int i=1000;i<2000;i++)
        { 
            this->vertex_buffer_data[i*9+0]=-3.95f;
            this->vertex_buffer_data[i*9+1]=0.0f+2.0;
            this->vertex_buffer_data[i*9+2]=0.0f;

            this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)-3.95;
            this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000)+2.0;
            this->vertex_buffer_data[i*9+5]=0.0f;

            this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)-3.95;
            this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)+2.0;
            this->vertex_buffer_data[i*9+8]=0.0f;
        }

        for (int i=2000;i<3000;i++)
        { 
            this->vertex_buffer_data[i*9+0]=3.95f;
            this->vertex_buffer_data[i*9+1]=0.0f;
            this->vertex_buffer_data[i*9+2]=0.0f;

            this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)+3.95;
            this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
            this->vertex_buffer_data[i*9+5]=0.0f;

            this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)+3.95;
            this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
            this->vertex_buffer_data[i*9+8]=0.0f;
        }

        for (int i=3000;i<4000;i++)
        { 
            this->vertex_buffer_data[i*9+0]=3.95f;
            this->vertex_buffer_data[i*9+1]=0.0f+2.0;
            this->vertex_buffer_data[i*9+2]=0.0f;

            this->vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000)+3.95;
            this->vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000)+2.0;
            this->vertex_buffer_data[i*9+5]=0.0f;

            this->vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)+3.95;
            this->vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)+2.0;
            this->vertex_buffer_data[i*9+8]=0.0f;
        }
   }
   if(count==150)
   {
        this->number_of_vertices=12;
        this->vertex_buffer_data1[0]=-4.0;
        this->vertex_buffer_data1[1]=-0.01;
        this->vertex_buffer_data1[2]=0.0;

        this->vertex_buffer_data1[3]=4.0;
        this->vertex_buffer_data1[4]=-0.01;
        this->vertex_buffer_data1[5]=0.0;

        this->vertex_buffer_data1[6]=-4.0;
        this->vertex_buffer_data1[7]=0.01;
        this->vertex_buffer_data1[8]=0.0;

        this->vertex_buffer_data1[9]=-4.0;
        this->vertex_buffer_data1[10]=0.01;
        this->vertex_buffer_data1[11]=0.0;

        this->vertex_buffer_data1[12]=4.0;
        this->vertex_buffer_data1[13]=-0.01;
        this->vertex_buffer_data1[14]=0.0;

        this->vertex_buffer_data1[15]=4.0;
        this->vertex_buffer_data1[16]=0.01;
        this->vertex_buffer_data1[17]=0.0;

        this->vertex_buffer_data1[18]=-4.0;
        this->vertex_buffer_data1[19]=1.99;
        this->vertex_buffer_data1[20]=0.0;

        this->vertex_buffer_data1[21]=4.0;
        this->vertex_buffer_data1[22]=1.99;
        this->vertex_buffer_data1[23]=0.0;

        this->vertex_buffer_data1[24]=-4.0;
        this->vertex_buffer_data1[25]=2.01;
        this->vertex_buffer_data1[26]=0.0;

        this->vertex_buffer_data1[27]=-4.0;
        this->vertex_buffer_data1[28]=2.01;
        this->vertex_buffer_data1[29]=0.0;

        this->vertex_buffer_data1[30]=4.0;
        this->vertex_buffer_data1[31]=1.99;
        this->vertex_buffer_data1[32]=0.0;

        this->vertex_buffer_data1[33]=4.0;
        this->vertex_buffer_data1[34]=2.01;
        this->vertex_buffer_data1[35]=0.0;
   } 
}