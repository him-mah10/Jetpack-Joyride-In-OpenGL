#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->move_left=false;
    this->ga=0.004;
    this->radius=0.3;
    this->move_right=false;
    this->down_speed = 0.02;
    this->odown_speed = this->down_speed;
    //this->sub_speed = 0.0009;
    this->speed = 0.05;
    this->pro_speed = 0.15;
    this->ospeed = this->speed;
    this->upspeed = this->speed;
    this->oga=this->ga;
    
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
    
    GLfloat vertex_buffer_data1[36];
    vertex_buffer_data1[0]=0.2;
    vertex_buffer_data1[1]=0.14;
    vertex_buffer_data1[2]=0;

    vertex_buffer_data1[3]=0.2;
    vertex_buffer_data1[4]=0.05;
    vertex_buffer_data1[5]=0;

    vertex_buffer_data1[6]=0.06;
    vertex_buffer_data1[7]=0.14;
    vertex_buffer_data1[8]=0;

    vertex_buffer_data1[9]=0.2;
    vertex_buffer_data1[10]=0.05;
    vertex_buffer_data1[11]=0;

    vertex_buffer_data1[12]=0.06;
    vertex_buffer_data1[13]=0.14;
    vertex_buffer_data1[14]=0;

    vertex_buffer_data1[15]=0.06;
    vertex_buffer_data1[16]=0.05;
    vertex_buffer_data1[17]=0;



    vertex_buffer_data1[18]=-0.2;
    vertex_buffer_data1[19]=0.14;
    vertex_buffer_data1[20]=0;

    vertex_buffer_data1[21]=-0.2;
    vertex_buffer_data1[22]=0.05;
    vertex_buffer_data1[23]=0;

    vertex_buffer_data1[24]=-0.06;
    vertex_buffer_data1[25]=0.14;
    vertex_buffer_data1[26]=0;

    vertex_buffer_data1[27]=-0.2;
    vertex_buffer_data1[28]=0.05;
    vertex_buffer_data1[29]=0;

    vertex_buffer_data1[30]=-0.06;
    vertex_buffer_data1[31]=0.14;
    vertex_buffer_data1[32]=0;

    vertex_buffer_data1[33]=-0.06;
    vertex_buffer_data1[34]=0.05;
    vertex_buffer_data1[35]=0;


    this->object = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data1, COLOR_BLACK, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick(int arg) 
{
    if(arg==0 && this->position.x>(-3.8))
    {
        this->position.x-=this->speed;
        this->move_left=true;
        this->move_right=false;
    }
    else if(arg==1 && this->position.x<3.8)
    {
        this->position.x+=this->speed;//right
        this->move_right=true;
        this->move_left=false;
    }
    else if(arg==2 && this->position.y<2.8)
    {
        this->position.y+=this->upspeed;//up
        this->down_speed=0.02;
        this->move_right=false;
        this->move_left=false;
    }
    else if(arg==-1 && (this->position.y>-2.8))
    {
        this->position.y-=this->down_speed;
        if(this->move_right && this->position.x<3.8)
            this->position.x+=this->speed;
        else if(this->move_left && this->position.x>(-3.8))
            this->position.x-=this->speed;
        else if(this->move_right && this->position.x>=3.8)
        {
            this->move_left=true;
            this->move_right=false;
        }
        else if(this->move_left && this->position.x<=(-3.8))
        {
            this->move_left=false;
            this->move_right=true;   
        }
    }
}

void Ball::increase_down_speed()
{
    this->down_speed+=this->ga;
}