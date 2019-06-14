#include "score.h"
#include "main.h"

Score::Score(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->ver=0;
    this->object = create3DObject(GL_TRIANGLES, ver, vertex_buffer_data, COLOR_BACKGROUND, GL_FILL);
}

void Score::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->object = create3DObject(GL_TRIANGLES, ver, vertex_buffer_data, COLOR_BACKGROUND, GL_FILL);
    draw3DObject(this->object);
}

void Score::tick(int sco,int len,int type) 
{
    int s=sco;
    this->ver=0;
    //unit
    for(int i=0;i<len;i++)
    {
        switch(s%10)
        {
            case 0: zero(i,type);break;
            case 1: one(i,type);break;
            case 2: two(i,type);break;
            case 3: three(i,type);break;
            case 4: four(i,type);break;
            case 5: five(i,type);break;
            case 6: six(i,type);break;
            case 7: seven(i,type);break;
            case 8: eight(i,type);break;
            case 9: nine(i,type);break;
        }   
        s/=10; 
    }
    
}

void Score::zero(float val,int type)
{
    int o=((this->ver)*3);
    this->vertex_buffer_data[0+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.875;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.75;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.875;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.75;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.75;
    this->vertex_buffer_data[17+o]=0.0;

    this->vertex_buffer_data[18+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.125;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.25;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.25;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.25;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.125;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.125;
    this->vertex_buffer_data[35+o]=0.0;

    this->vertex_buffer_data[36+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.75;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.25;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.75;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.75;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.25;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.25;
    this->vertex_buffer_data[53+o]=0.0;

    this->vertex_buffer_data[54+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.75;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.75;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.25;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.75;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.25;
    this->vertex_buffer_data[71+o]=0.0;  
    this->ver+=24;
}


void Score::one(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.125;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.125;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.125;
    this->vertex_buffer_data[17+o]=0.0;
    
    this->ver+=6;
}


void Score::two(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.75;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.75;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.75;
    this->vertex_buffer_data[17+o]=0.0;


    this->vertex_buffer_data[18+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.75;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.5625;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.75;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.5625;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.75;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.5625;
    this->vertex_buffer_data[35+o]=0.0;


    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.5625;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.5625;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.4375;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.5625;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.4375;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.4375;
    this->vertex_buffer_data[53+o]=0.0;


    this->vertex_buffer_data[54+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.4375;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.25;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.4375;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.4375;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.25;
    this->vertex_buffer_data[71+o]=0.0;


    this->vertex_buffer_data[72+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[73+o]=3.25;
    this->vertex_buffer_data[74+o]=0.0;

    this->vertex_buffer_data[75+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[76+o]=3.125;
    this->vertex_buffer_data[77+o]=0.0;

    this->vertex_buffer_data[78+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[79+o]=3.25;
    this->vertex_buffer_data[80+o]=0.0;

    this->vertex_buffer_data[81+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[82+o]=3.25;
    this->vertex_buffer_data[83+o]=0.0;

    this->vertex_buffer_data[84+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[85+o]=3.125;
    this->vertex_buffer_data[86+o]=0.0;

    this->vertex_buffer_data[87+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[88+o]=3.125;
    this->vertex_buffer_data[89+o]=0.0;
    
    this->ver+=30;    
}


void Score::three(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.125;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.125;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.125;
    this->vertex_buffer_data[17+o]=0.0;


    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.875;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.75;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.875;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.75;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.875;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.75;
    this->vertex_buffer_data[35+o]=0.0;

    
    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.5625;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.4375;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.5625;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.4375;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.5625;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.4375;
    this->vertex_buffer_data[53+o]=0.0;

    
    this->vertex_buffer_data[54+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.25;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.125;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.25;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.125;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.125;
    this->vertex_buffer_data[71+o]=0.0;

    this->ver+=24;
}


void Score::four(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.125;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.125;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.125;
    this->vertex_buffer_data[17+o]=0.0;


    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.5625;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.4375;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.5625;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.4375;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.5625;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.4375;
    this->vertex_buffer_data[35+o]=0.0;


    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.875;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.5625;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.875;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.5625;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.875;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.5625;
    this->vertex_buffer_data[53+o]=0.0;

    this->ver+=18;    
}


void Score::five(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.75;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.75;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.75;
    this->vertex_buffer_data[17+o]=0.0;


    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.875;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.5625;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.875;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.5625;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.875;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.5625;
    this->vertex_buffer_data[35+o]=0.0;
    

    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.5625;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.4375;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.5625;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.4375;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.5625;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.4375;
    this->vertex_buffer_data[53+o]=0.0;


    this->vertex_buffer_data[54+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.5625;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.25;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.5625;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.5625;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.25;
    this->vertex_buffer_data[71+o]=0.0;  


    this->vertex_buffer_data[72+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[73+o]=3.25;
    this->vertex_buffer_data[74+o]=0.0;

    this->vertex_buffer_data[75+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[76+o]=3.125;
    this->vertex_buffer_data[77+o]=0.0;

    this->vertex_buffer_data[78+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[79+o]=3.25;
    this->vertex_buffer_data[80+o]=0.0;

    this->vertex_buffer_data[81+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[82+o]=3.25;
    this->vertex_buffer_data[83+o]=0.0;

    this->vertex_buffer_data[84+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[85+o]=3.125;
    this->vertex_buffer_data[86+o]=0.0;

    this->vertex_buffer_data[87+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[88+o]=3.125;
    this->vertex_buffer_data[89+o]=0.0;      
    
    this->ver+=30;
}


void Score::six(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.75;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.75;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.75;
    this->vertex_buffer_data[17+o]=0.0;


    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.875;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.5625;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.875;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.5625;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.875;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.5625;
    this->vertex_buffer_data[35+o]=0.0;


    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.5625;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.4375;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.5625;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.4375;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.5625;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.4375;
    this->vertex_buffer_data[53+o]=0.0;


    this->vertex_buffer_data[54+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.5625;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.25;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.5625;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.5625;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.25;
    this->vertex_buffer_data[71+o]=0.0;


    this->vertex_buffer_data[72+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[73+o]=3.25;
    this->vertex_buffer_data[74+o]=0.0;

    this->vertex_buffer_data[75+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[76+o]=3.125;
    this->vertex_buffer_data[77+o]=0.0;

    this->vertex_buffer_data[78+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[79+o]=3.25;
    this->vertex_buffer_data[80+o]=0.0;

    this->vertex_buffer_data[81+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[82+o]=3.25;
    this->vertex_buffer_data[83+o]=0.0;

    this->vertex_buffer_data[84+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[85+o]=3.125;
    this->vertex_buffer_data[86+o]=0.0;

    this->vertex_buffer_data[87+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[88+o]=3.125;
    this->vertex_buffer_data[89+o]=0.0;


    this->vertex_buffer_data[90+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[91+o]=3.4375;
    this->vertex_buffer_data[92+o]=0.0;

    this->vertex_buffer_data[93+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[94+o]=3.25;
    this->vertex_buffer_data[95+o]=0.0;

    this->vertex_buffer_data[96+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[97+o]=3.4375;
    this->vertex_buffer_data[98+o]=0.0;

    this->vertex_buffer_data[99+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[100+o]=3.25;
    this->vertex_buffer_data[101+o]=0.0;

    this->vertex_buffer_data[102+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[103+o]=3.4375;
    this->vertex_buffer_data[104+o]=0.0;

    this->vertex_buffer_data[105+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[106+o]=3.25;
    this->vertex_buffer_data[107+o]=0.0;
    
    this->ver+=36;
}


void Score::seven(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.125;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.125;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.125;
    this->vertex_buffer_data[17+o]=0.0;
    
    
    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.875;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.75;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.875;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.75;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.875;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.75;
    this->vertex_buffer_data[35+o]=0.0;

    this->ver+=12;
}


void Score::eight(float val,int type)
{
    int o=((this->ver)*3);
    this->vertex_buffer_data[0+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.875;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.75;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.875;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.75;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.75;
    this->vertex_buffer_data[17+o]=0.0;

    this->vertex_buffer_data[18+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.125;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.25;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.25;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.25;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.125;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.125;
    this->vertex_buffer_data[35+o]=0.0;

    this->vertex_buffer_data[36+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.75;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.25;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.75;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.75;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.0-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.25;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.25;
    this->vertex_buffer_data[53+o]=0.0;

    this->vertex_buffer_data[54+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.75;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.75;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.25;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.25;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.75;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.25;
    this->vertex_buffer_data[71+o]=0.0;  
    

    this->vertex_buffer_data[72+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[73+o]=3.5625;
    this->vertex_buffer_data[74+o]=0.0;

    this->vertex_buffer_data[75+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[76+o]=3.4375;
    this->vertex_buffer_data[77+o]=0.0;

    this->vertex_buffer_data[78+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[79+o]=3.5625;
    this->vertex_buffer_data[80+o]=0.0;

    this->vertex_buffer_data[81+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[82+o]=3.4375;
    this->vertex_buffer_data[83+o]=0.0;

    this->vertex_buffer_data[84+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[85+o]=3.5625;
    this->vertex_buffer_data[86+o]=0.0;

    this->vertex_buffer_data[87+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[88+o]=3.4375;
    this->vertex_buffer_data[89+o]=0.0;
    this->ver+=30;
}


void Score::nine(float val,int type)
{
    int o=((this->ver)*3);

    this->vertex_buffer_data[0+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[1+o]=3.875;
    this->vertex_buffer_data[2+o]=0.0;

    this->vertex_buffer_data[3+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[4+o]=3.125;
    this->vertex_buffer_data[5+o]=0.0;

    this->vertex_buffer_data[6+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[7+o]=3.875;
    this->vertex_buffer_data[8+o]=0.0;

    this->vertex_buffer_data[9+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[10+o]=3.125;
    this->vertex_buffer_data[11+o]=0.0;

    this->vertex_buffer_data[12+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[13+o]=3.875;
    this->vertex_buffer_data[14+o]=0.0;

    this->vertex_buffer_data[15+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[16+o]=3.125;
    this->vertex_buffer_data[17+o]=0.0;
    
    
    this->vertex_buffer_data[18+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[19+o]=3.875;
    this->vertex_buffer_data[20+o]=0.0;

    this->vertex_buffer_data[21+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[22+o]=3.75;
    this->vertex_buffer_data[23+o]=0.0;

    this->vertex_buffer_data[24+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[25+o]=3.875;
    this->vertex_buffer_data[26+o]=0.0;

    this->vertex_buffer_data[27+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[28+o]=3.75;
    this->vertex_buffer_data[29+o]=0.0;

    this->vertex_buffer_data[30+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[31+o]=3.875;
    this->vertex_buffer_data[32+o]=0.0;

    this->vertex_buffer_data[33+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[34+o]=3.75;
    this->vertex_buffer_data[35+o]=0.0;


    this->vertex_buffer_data[36+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[37+o]=3.5625;
    this->vertex_buffer_data[38+o]=0.0;

    this->vertex_buffer_data[39+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[40+o]=3.4375;
    this->vertex_buffer_data[41+o]=0.0;

    this->vertex_buffer_data[42+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[43+o]=3.5625;
    this->vertex_buffer_data[44+o]=0.0;

    this->vertex_buffer_data[45+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[46+o]=3.4375;
    this->vertex_buffer_data[47+o]=0.0;

    this->vertex_buffer_data[48+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[49+o]=3.5625;
    this->vertex_buffer_data[50+o]=0.0;

    this->vertex_buffer_data[51+o]=3.375-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[52+o]=3.4375;
    this->vertex_buffer_data[53+o]=0.0;


    this->vertex_buffer_data[54+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[55+o]=3.875;
    this->vertex_buffer_data[56+o]=0.0;

    this->vertex_buffer_data[57+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[58+o]=3.5625;
    this->vertex_buffer_data[59+o]=0.0;

    this->vertex_buffer_data[60+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[61+o]=3.875;
    this->vertex_buffer_data[62+o]=0.0;

    this->vertex_buffer_data[63+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[64+o]=3.5625;
    this->vertex_buffer_data[65+o]=0.0;

    this->vertex_buffer_data[66+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[67+o]=3.875;
    this->vertex_buffer_data[68+o]=0.0;

    this->vertex_buffer_data[69+o]=3.125-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[70+o]=3.5625;
    this->vertex_buffer_data[71+o]=0.0;

    this->vertex_buffer_data[72+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[73+o]=3.25;
    this->vertex_buffer_data[74+o]=0.0;

    this->vertex_buffer_data[75+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[76+o]=3.125;
    this->vertex_buffer_data[77+o]=0.0;

    this->vertex_buffer_data[78+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[79+o]=3.25;
    this->vertex_buffer_data[80+o]=0.0;

    this->vertex_buffer_data[81+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[82+o]=3.25;
    this->vertex_buffer_data[83+o]=0.0;

    this->vertex_buffer_data[84+o]=3-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[85+o]=3.125;
    this->vertex_buffer_data[86+o]=0.0;

    this->vertex_buffer_data[87+o]=3.5-(val*0.75)-(type*6.0);
    this->vertex_buffer_data[88+o]=3.125;
    this->vertex_buffer_data[89+o]=0.0;
    this->ver+=30;
}