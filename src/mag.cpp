#include "mag.h"
#include "main.h"

Mag::Mag(float x, float y) {
    this->position = glm::vec3(x, y, 0);

    this->vertex_buffer_data_red[0]=0;
    this->vertex_buffer_data_red[1]=0;
    this->vertex_buffer_data_red[2]=0.0;

    this->vertex_buffer_data_red[3]=1;
    this->vertex_buffer_data_red[4]=0;
    this->vertex_buffer_data_red[5]=0.0;

    this->vertex_buffer_data_red[6]=0;
    this->vertex_buffer_data_red[7]=-0.25;
    this->vertex_buffer_data_red[8]=0.0;

    this->vertex_buffer_data_red[9]=0;
    this->vertex_buffer_data_red[10]=-0.25;
    this->vertex_buffer_data_red[11]=0.0;

    this->vertex_buffer_data_red[12]=1;
    this->vertex_buffer_data_red[13]=0;
    this->vertex_buffer_data_red[14]=0.0;

    this->vertex_buffer_data_red[15]=1;
    this->vertex_buffer_data_red[16]=-0.25;
    this->vertex_buffer_data_red[17]=0.0;
    
    
    this->vertex_buffer_data_red[18]=0.25;
    this->vertex_buffer_data_red[19]=-0.25;
    this->vertex_buffer_data_red[20]=0.0;

    this->vertex_buffer_data_red[21]=0.25;
    this->vertex_buffer_data_red[22]=-1.25;
    this->vertex_buffer_data_red[23]=0.0;

    this->vertex_buffer_data_red[24]=0;
    this->vertex_buffer_data_red[25]=-0.25;
    this->vertex_buffer_data_red[26]=0.0;

    this->vertex_buffer_data_red[27]=0.25;
    this->vertex_buffer_data_red[28]=-1.25;
    this->vertex_buffer_data_red[29]=0.0;

    this->vertex_buffer_data_red[30]=0;
    this->vertex_buffer_data_red[31]=-0.25;
    this->vertex_buffer_data_red[32]=0.0;

    this->vertex_buffer_data_red[33]=0;
    this->vertex_buffer_data_red[34]=-1.25;
    this->vertex_buffer_data_red[35]=0.0;

    
    this->vertex_buffer_data_red[36]=0;
    this->vertex_buffer_data_red[37]=-1;
    this->vertex_buffer_data_red[38]=0.0;

    this->vertex_buffer_data_red[39]=0;
    this->vertex_buffer_data_red[40]=-1.25;
    this->vertex_buffer_data_red[41]=0.0;

    this->vertex_buffer_data_red[42]=1;
    this->vertex_buffer_data_red[43]=-1;
    this->vertex_buffer_data_red[44]=0.0;

    this->vertex_buffer_data_red[45]=0;
    this->vertex_buffer_data_red[46]=-1.25;
    this->vertex_buffer_data_red[47]=0.0;

    this->vertex_buffer_data_red[48]=1;
    this->vertex_buffer_data_red[49]=-1;
    this->vertex_buffer_data_red[50]=0.0;

    this->vertex_buffer_data_red[51]=1;
    this->vertex_buffer_data_red[52]=-1.25;
    this->vertex_buffer_data_red[53]=0.0;



    this->vertex_buffer_data_blue[0]=1;
    this->vertex_buffer_data_blue[1]=-1;
    this->vertex_buffer_data_blue[2]=0.0;

    this->vertex_buffer_data_blue[3]=1.155;
    this->vertex_buffer_data_blue[4]=-1;
    this->vertex_buffer_data_blue[5]=0.0;

    this->vertex_buffer_data_blue[6]=1;
    this->vertex_buffer_data_blue[7]=-1.25;
    this->vertex_buffer_data_blue[8]=0.0;

    this->vertex_buffer_data_blue[9]=1;
    this->vertex_buffer_data_blue[10]=-1.25;
    this->vertex_buffer_data_blue[11]=0.0;

    this->vertex_buffer_data_blue[12]=1.155;
    this->vertex_buffer_data_blue[13]=-1;
    this->vertex_buffer_data_blue[14]=0.0;

    this->vertex_buffer_data_blue[15]=1.155;
    this->vertex_buffer_data_blue[16]=-1.25;
    this->vertex_buffer_data_blue[17]=0.0;
    
    
    this->vertex_buffer_data_blue[18]=1;
    this->vertex_buffer_data_blue[19]=0;
    this->vertex_buffer_data_blue[20]=0.0;

    this->vertex_buffer_data_blue[21]=1;
    this->vertex_buffer_data_blue[22]=-0.25;
    this->vertex_buffer_data_blue[23]=0.0;

    this->vertex_buffer_data_blue[24]=1.155;
    this->vertex_buffer_data_blue[25]=0;
    this->vertex_buffer_data_blue[26]=0.0;

    this->vertex_buffer_data_blue[27]=1;
    this->vertex_buffer_data_blue[28]=-0.25;
    this->vertex_buffer_data_blue[29]=0.0;

    this->vertex_buffer_data_blue[30]=1.155;
    this->vertex_buffer_data_blue[31]=0;
    this->vertex_buffer_data_blue[32]=0.0;

    this->vertex_buffer_data_blue[33]=1.155;
    this->vertex_buffer_data_blue[34]=-0.25;
    this->vertex_buffer_data_blue[35]=0.0;

    this->object_red = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data_red, COLOR_FIRE, GL_FILL);
    this->object_blue = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data_blue, COLOR_BLUE, GL_FILL);
}

void Mag::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_red);
    draw3DObject(this->object_blue);
}