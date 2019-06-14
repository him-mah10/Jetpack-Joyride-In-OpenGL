#include "main.h"
#include "timer.h"
#include "ball.h"
#include "wall.h"
#include "enemy1.h"
#include "enemy2.h"
#include "coins.h"
#include "prop.h"
#include "score.h"
#include "mag.h"
#include "semring.h"
#include "enemy3.h"
#include "baloon.h"
#include "super_coin.h"
#include "dragon.h"
#include "dragon_ball.h"
#include "diamond.h"
#include "background.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
Wall wall1;
Wall wall2;
Prop prop;
Score sco;
vector<Background> background;
Score life_dis;
vector<Dragon> dragon;
float fac;
vector<DB> db;
vector<Semring>semring;
int baloon_press;
float radius;
int life;
bool hit;
bool inside_ring;
vector<Diamond> diamond;
vector<SC> sc;
vector<Enemy2> enemy2_vector;
vector<Enemy3> enemy3_vector;
vector<Coins> coins_vector;
vector<Enemy1> enemy1_vector;
vector<Baloon> baloon_vector;
vector<Mag> mag_vector;
float screen_zoom=1, screen_center_x = 0, screen_center_y = 0, zoom_factor=0.025;
float camera_rotation_angle = 90;
int score;
float greenx,redx;
float pro_count=200;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    //Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
     Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    for(int i=0;i<background.size();i++)
        background[i].draw(VP);
    for(int i=0;i<semring.size();i++)
        semring[i].draw(VP);
    ball1.draw(VP);
    wall1.draw(VP);
    wall2.draw(VP);
    prop.draw(VP);
    sco.draw(VP);
    life_dis.draw(VP);
    for(int i=0;i<dragon.size();i++)
    {
        dragon[i].position.y=ball1.position.y;
        dragon[i].draw(VP);
    }
    for(int i=0;i<diamond.size();i++)
    {
        diamond[i].draw(VP);
    }
    for(int i=0;i<sc.size();i++)
    {
        sc[i].draw(VP);
    }
    for(int i=0;i<coins_vector.size();i++)
    {
        coins_vector[i].draw(VP);
    }
    for(int i=0;i<db.size();i++)
    {
        db[i].draw(VP);
    }
    for(int i=0;i<enemy1_vector.size();i++)
    {
        enemy1_vector[i].draw(VP);
    }
    for(int i=0;i<enemy2_vector.size();i++)
    {
        enemy2_vector[i].draw(VP);
    }
    for(int i=0;i<mag_vector.size();i++)
    {
        mag_vector[i].draw(VP);
    }
    for(int i=0;i<enemy3_vector.size();i++)
    {
        enemy3_vector[i].draw(VP);
    }
    for(int i=0;i<baloon_vector.size();i++)
    {
        baloon_vector[i].draw(VP);
    }
}

void tick_input(GLFWwindow *window) {
    for(int i=0;i<background.size();i++)
        background[i].tick();
    int left  = glfwGetKey(window, GLFW_KEY_A);
    int right = glfwGetKey(window, GLFW_KEY_D);
    int up = glfwGetKey(window, GLFW_KEY_W);
    int normal_zoom = glfwGetKey(window, GLFW_KEY_S);
    //int baloon_press = glfwGetKey(window, GLFW_KEY_B);
    int propulsion = glfwGetKey(window, GLFW_KEY_SPACE);
    if (left && !inside_ring) {
        ball1.tick(0);
    }
    if(right && !inside_ring)
    {
        ball1.tick(1);
    }
    if(up && !inside_ring)
    {
        ball1.tick(2);
    }
    if(!up && !inside_ring)
    {
        ball1.tick(-1);
    }
    if(normal_zoom)
    {
        screen_zoom=1;
        reset_screen();
    }
    if(propulsion && pro_count>3 && (left||right||up) && !inside_ring)
    {
        ball1.speed=ball1.pro_speed;
        pro_count-=5;
        if(pro_count<0)
            pro_count=0;
    }
    if(!propulsion)
    {
        ball1.speed=(ball1.pro_speed/2);    
    }
    if(baloon_press && score>=2)
    {
        score-=2;
        Baloon b;
        b = Baloon(ball1.position.x+0.2,ball1.position.y);
        baloon_vector.push_back(b);
        baloon_press=0;
    }
    else 
        baloon_press=0;
    if(inside_ring && semring.size()>0)
    {
        if(!radius)
        {
            if(ball1.position.x<semring[0].position.x)
            {
                radius=semring[0].position.x-ball1.position.x;
                fac=0.01;
            }
            else
            {
                radius=ball1.position.x-semring[0].position.x;
                fac=-0.01;
            }
        }
        ball1.position.x+=fac;
        float rad_s=radius*radius;
        float x_s=(ball1.position.x-semring[0].position.x)*(ball1.position.x-semring[0].position.x);
        ball1.position.y=semring[0].position.y+sqrt(rad_s - x_s);

        if(fac<0)
        {
            if(semring[0].position.x-ball1.position.x-fac>=radius)
                inside_ring=false;
        }
        else
        {
            if(ball1.position.x-semring[0].position.x+fac>=radius)
                inside_ring=false;   
        }
        
        /*if( ((ball1.position.x > (semring.position.x-semring.radius_outer) && ball1.position.x < (semring.position.x-semring.radius_inner)) || (ball1.position.x < (semring.position.x+semring.radius_outer) && ball1.position.x > (semring.position.x+semring.radius_inner))) && ball1.position.y > (semring.position.y-0.08) && ball1.position.y < (semring.position.y+0.08))
        {
         inside_ring=false;
        }*/

    }
    if(!inside_ring && radius)
    {
        radius=0;
        if(semring.size()>0)
            ball1.position.y=semring[0].position.y-0.5;
        //ball1.ga=ball1.oga;
    }
    if(semring.size()<1)
        inside_ring=false;

    if(semring.size()>0)
    {
        semring[0].tick();
        if(semring[0].count==400)
            semring.erase(semring.begin());
    }
}

void tick_elements() {
   for(int i=0;i<background.size();i++)
   {
    if(background[i].position.x<-8)
        background.erase(background.begin()+i);
   }
   for(int i=0;i<coins_vector.size();i++)
   {
        coins_vector[i].tick();
   }
   for(int i=0;i<db.size();i++)
   {
        db[i].tick();
   }
   for(int i=0;i<enemy1_vector.size();i++)
   {
        enemy1_vector[i].tick();
   }
   for(int i=0;i<diamond.size();i++)
   {
        diamond[i].tick();
   }
   for(int i=0;i<sc.size();i++)
   {
        sc[i].tick();
   }
   for(int i=0;i<baloon_vector.size();i++)
   {
        baloon_vector[i].tick();
   }
   for(int i=0;i<coins_vector.size();i++)
   {
        if(coins_vector[i].position.x<-5)
        {
            coins_vector.erase(coins_vector.begin() + i);
        }
        else
        {
            if( distance( coins_vector[i].position.x , coins_vector[i].position.y , ball1.position.x , ball1.position.y ) <= (coins_vector[i].radius + ball1.radius))
            {
                score++;
                coins_vector.erase(coins_vector.begin() + i);       
            }
        }
   }

   for(int i=0;i<db.size();i++)
   {
        if(db[i].position.x<-5)
        {
            db.erase(db.begin() + i);
        }
        else
        {
            if( distance( db[i].position.x , db[i].position.y , ball1.position.x , ball1.position.y ) <= (db[i].radius + ball1.radius) && !inside_ring)
            {
                life-=1;
                
                hit=true;
                db.erase(db.begin()+i);       
            }
        }
   }

   for(int i=0;i<enemy1_vector.size();i++)
   {
        if(enemy1_vector[i].position.x<-6)
        {
            enemy1_vector.erase(enemy1_vector.begin() + i);
        }
        else if(enemy1_vector[i].distance(ball1.position.x,ball1.position.y)<=(ball1.radius))
        {
            if( (enemy1_vector[i].position.x <= ball1.position.x) && ( ball1.position.x <= ( enemy1_vector[i].position.x+sin(enemy1_vector[i].theta ))) && (enemy1_vector[i].position.y >=  ball1.position.y) && ( ball1.position.y >= ( enemy1_vector[i].position.y-cos(enemy1_vector[i].theta ))) && !inside_ring)
            {    
                score-=100;
                enemy1_vector.erase(enemy1_vector.begin() + i);       
            }
        }
   }
   if(diamond.size()>0)
   {
        if( ball1.position.x > diamond[0].position.x-0.3 && ball1.position.x < diamond[0].position.x && ball1.position.y > diamond[0].position.y-0.3 && ball1.position.y < diamond[0].position.y )
        {
            if(life==9)
                score+=500;
            else
                life++;
            diamond.erase(diamond.begin());
        }
   }
   if(sc.size()>0)
   {
        if( distance( sc[0].position.x , sc[0].position.y , ball1.position.x , ball1.position.y ) <= (sc[0].radius + ball1.radius))
        {
                score+=20;
                sc.erase(sc.begin());       
        }
   }
   for(int i=0;i<baloon_vector.size();i++)
   {
        if(baloon_vector[i].position.y<-3)
        {
            baloon_vector.erase(baloon_vector.begin() + i);
        }
        if(enemy1_vector.size()>0)
        {
            if(enemy1_vector[0].distance(baloon_vector[i].position.x,baloon_vector[i].position.y)<=(baloon_vector[i].radius))
            {
                if( (enemy1_vector[0].position.x <= baloon_vector[i].position.x) && ( baloon_vector[i].position.x <= ( enemy1_vector[0].position.x+sin(enemy1_vector[0].theta ))) && (enemy1_vector[0].position.y >=  baloon_vector[i].position.y) && ( baloon_vector[i].position.y >= ( enemy1_vector[0].position.y-cos(enemy1_vector[0].theta ))) )
                {    
                    score+=50;
                    baloon_vector.erase(baloon_vector.begin() + i); 
                    enemy1_vector.erase(enemy1_vector.begin());    
                    continue;  
                }
            }
        }
   }
   if(enemy2_vector.size() > 0)
   {
        enemy2_vector[0].tick();
   
       if(enemy2_vector[0].count>150 && !inside_ring)
       {
            double by=ball1.position.y;
            double e2y=enemy2_vector[0].position.y;
            if( by-e2y > (-1*(ball1.radius-0.05)) && by-e2y < (ball1.radius-0.05))
            {
                enemy2_vector.erase(enemy2_vector.begin());
                life-=1;
                
                hit=true;
            }
            e2y+=2.0;
            if( by-e2y > (-1*(ball1.radius-0.05)) && by-e2y < (ball1.radius-0.05))
            {
                enemy2_vector.erase(enemy2_vector.begin());
                life-=1;
                
                hit=true;
            }
       }
       if(enemy2_vector[0].count>800)
       {
            enemy2_vector.erase(enemy2_vector.begin());
        }
   }
   if(enemy3_vector.size()>0)
   {
        bool is_collision = enemy3_vector[0].detect_collision(ball1.position.x,ball1.position.y,ball1.radius);
       if(is_collision && !inside_ring)
       {
        life--;
        
        hit=true;
       }

       enemy3_vector[0].tick();
       if(enemy3_vector[0].count>=162)
        enemy3_vector.erase(enemy3_vector.begin());
   }
   
   if(semring.size()>0)
    if( ((ball1.position.x > (semring[0].position.x-semring[0].radius_outer) && ball1.position.x < (semring[0].position.x-semring[0].radius_inner)) || (ball1.position.x < (semring[0].position.x+semring[0].radius_outer) && ball1.position.x > (semring[0].position.x+semring[0].radius_inner))) && ball1.position.y > (semring[0].position.y-0.03) && ball1.position.y < (semring[0].position.y+0.03))
        {
            inside_ring=true;
        }

   sco.tick(score,4,0);
   life_dis.tick(life,1,1);
   prop.tick(pro_count/100);
   if(dragon.size()>0 && dragon[0].count>300)
    dragon.erase(dragon.begin());

}

void initGL(GLFWwindow *window, int width, int height) {

    ball1       = Ball(-3, -2.8, COLOR_SKIN);
    wall1       = Wall(0,COLOR_WALL);
    wall2       = Wall(1,COLOR_WALL);
    
    prop        = Prop(0,0,COLOR_GREENO);
    sco         = Score(0,0);
    life_dis    = Score(0,0);
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);
}

void make_triangle(int region,double x)
{
    Coins coins[16];
    double y;
    if(region==0)
        y=2.8;
    else if(region==1)
        y=0.3;
    else
        y=-1.9;
    coins[0] = Coins(x, y-0.9, COLOR_COINS);
    
    coins[1] = Coins(x+0.3, y-0.9, COLOR_COINS);
    coins[2] = Coins(x+0.3, y-0.6, COLOR_COINS);
    
    coins[3] = Coins(x+0.6, y-0.9, COLOR_COINS);
    coins[4] = Coins(x+0.6, y-0.6, COLOR_COINS);
    coins[5] = Coins(x+0.6, y-0.3, COLOR_COINS);

    coins[6] = Coins(x+0.9, y-0.9, COLOR_COINS);
    coins[7] = Coins(x+0.9, y-0.6, COLOR_COINS);
    coins[8] = Coins(x+0.9, y-0.3, COLOR_COINS);
    coins[9] = Coins(x+0.9, y, COLOR_COINS);

    coins[10] = Coins(x+1.2, y-0.9, COLOR_COINS);
    coins[11] = Coins(x+1.2, y-0.6, COLOR_COINS);
    coins[12] = Coins(x+1.2, y-0.3, COLOR_COINS);

    coins[13] = Coins(x+1.5, y-0.9, COLOR_COINS);
    coins[14] = Coins(x+1.5, y-0.6, COLOR_COINS);

    coins[15] = Coins(x+1.8, y-0.9, COLOR_COINS);
    for(int i=0;i<16;i++)
        coins_vector.push_back(coins[i]);
}

void make_lines(int region,double y_sub,double x)
{
    double y;
    if(region==0)
        y=2.8;
    else if(region==1)
        y=0.3;
    else
        y=-1.9;

    Coins coins[10];

    coins[0] = Coins(x, y-y_sub, COLOR_COINS);
    coins[1] = Coins(x, y-y_sub-0.3, COLOR_COINS);

    coins[2] = Coins(x+0.3, y-y_sub, COLOR_COINS);
    coins[3] = Coins(x+0.3, y-y_sub-0.3, COLOR_COINS);

    coins[4] = Coins(x+0.6, y-y_sub, COLOR_COINS);
    coins[5] = Coins(x+0.6, y-y_sub-0.3, COLOR_COINS);

    coins[6] = Coins(x+0.9, y-y_sub, COLOR_COINS);
    coins[7] = Coins(x+0.9, y-y_sub-0.3, COLOR_COINS);

    coins[8] = Coins(x+1.2, y-y_sub, COLOR_COINS);
    coins[9] = Coins(x+1.2, y-y_sub-0.3, COLOR_COINS);

    for(int i=0;i<10;i++)
        coins_vector.push_back(coins[i]);
}

void make_rectangle(int region,double x)
{
    double y;
    if(region==0)
        y=2.8;
    else if(region==1)
        y=0.3;
    else
        y=-1.9;

    Coins coins[20];

    coins[0] = Coins(x, y, COLOR_COINS);
    coins[1] = Coins(x, y-0.3, COLOR_COINS);
    coins[2] = Coins(x, y-0.6, COLOR_COINS);
    coins[3] = Coins(x, y-0.9, COLOR_COINS);

    coins[4] = Coins(x+0.3, y, COLOR_COINS);
    coins[5] = Coins(x+0.3, y-0.3, COLOR_COINS);
    coins[6] = Coins(x+0.3, y-0.6, COLOR_COINS);
    coins[7] = Coins(x+0.3, y-0.9, COLOR_COINS);

    coins[8] = Coins(x+0.6, y, COLOR_COINS);
    coins[9] = Coins(x+0.6, y-0.3, COLOR_COINS);
    coins[10] = Coins(x+0.6, y-0.6, COLOR_COINS);
    coins[11] = Coins(x+0.6, y-0.9, COLOR_COINS);

    coins[12] = Coins(x+0.9, y, COLOR_COINS);
    coins[13] = Coins(x+0.9, y-0.3, COLOR_COINS);
    coins[14] = Coins(x+0.9, y-0.6, COLOR_COINS);
    coins[15] = Coins(x+0.9, y-0.9, COLOR_COINS);

    coins[16] = Coins(x+1.2, y, COLOR_COINS);
    coins[17] = Coins(x+1.2, y-0.3, COLOR_COINS);
    coins[18] = Coins(x+1.2, y-0.6, COLOR_COINS);
    coins[19] = Coins(x+1.2, y-0.9, COLOR_COINS);
    for(int i=0;i<20;i++)
        coins_vector.push_back(coins[i]);
}

void make_circle(int region,double x)
{
    double y;
    if(region==0)
        y=2.8;
    else if(region==1)
        y=0.3;
    else
        y=-1.9;

    Coins coins[8];

    coins[0] = Coins(x, y-0.3, COLOR_COINS);
    coins[1] = Coins(x, y-0.6, COLOR_COINS);
    
    coins[2] = Coins(x+0.3, y, COLOR_COINS);
    coins[3] = Coins(x+0.3, y-0.3, COLOR_COINS);
    coins[4] = Coins(x+0.3, y-0.6, COLOR_COINS);
    coins[5] = Coins(x+0.3, y-0.9, COLOR_COINS);

    coins[6] = Coins(x+0.6, y-0.6, COLOR_COINS);
    coins[7] = Coins(x+0.6, y-0.3, COLOR_COINS);

    for(int i=0;i<8;i++)
        coins_vector.push_back(coins[i]);
}

int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1000;
    int height = 700;
    long long count=1;
    inside_ring=false;
    baloon_press=0;
    radius=0;
    score=0;
    int mag_count=0;
    hit=false;
    life=3;

    window = initGLFW(width, height);

    initGL (window, width, height);
    /* Draw in loop */
    while (!glfwWindowShouldClose(window) && life>0) {
        // Process timers
        if(score<0)
            score=0;
        if (t60.processTick()) {
           draw();
            glfwSwapBuffers(window);
            tick_input(window);
            tick_elements();
            if(count%240==0)
            {
                int shape,region=0;
                shape = rand()%4;
                region = rand()%3;
                switch(shape)
                {
                    case 0: make_triangle(region,4.0);
                            make_triangle(region,6.2);
                            make_triangle(region,8.4);
                            break;
                    case 1: make_lines(region,0.0,4.0);
                            make_lines(region,0.3,5.5);
                            make_lines(region,0.0,7.0);
                            break;
                    case 2: make_rectangle(region,4.0);
                            make_rectangle(region,5.8);
                            make_rectangle(region,7.6);
                            break;
                    case 3: make_circle(region,4.0);
                            make_circle(region,5.0);
                            make_circle(region,6.0);
                            break;
                    default: make_rectangle(region,4.0);
                            make_rectangle(region,5.8);
                            make_rectangle(region,7.6);
                            break;
                }
            }
            if(count%900==0)
            {
                Enemy1 enemy1;
                enemy1 = Enemy1(4, rand()%5-2, COLOR_FIRE);
                enemy1_vector.push_back(enemy1);
            }
            if(count%2000==0)
            {
                Enemy2 enemy2;
                enemy2 = Enemy2(rand()%3-1,COLOR_RED);
                enemy2_vector.push_back(enemy2);
            }
            if(count%1000==1)
            {
                Background b;
                b = Background(8,0);
                background.push_back(b);
            }
            if(count%200==0 && pro_count<200)
            {
                pro_count+=3;
            }
            if(count%3000==1200)
            {
                Mag mag;
                mag = Mag(rand()%4-1,rand()%4-1);
                mag_vector.push_back(mag);
                mag_count=1;
            }
            if(count%1200==1000 )
            {
                Enemy3 enemy3;
                enemy3      = Enemy3(ball1.position.x+1.2,rand()%3,COLOR_BROWN);
                enemy3_vector.push_back(enemy3);
            }
            if(count%1800==0)
            {
                Semring s;
                s     = Semring(rand()%3-1,rand()%2);
                semring.push_back(s);
            }
            if(count%8000 == 5897)
            {
                Dragon d;
                d = Dragon(ball1.position.y);
                dragon.push_back(d);
            }
            if(count%4000 == 578)
            {
                Diamond d;
                d = Diamond(rand()%2-2,rand()%3-1);
                diamond.push_back(d);
            }
            if(diamond.size()>0 && diamond[0].count==300)
                diamond.erase(diamond.begin());
            if(count%2320 == 1)
            {
                SC s;
                s = SC(rand()%3-1,rand()%3-1);
                sc.push_back(s);
            }
            if(sc.size()>0 && sc[0].count==200)
                sc.erase(sc.begin());
            if(dragon.size()>0 && dragon[0].count%60==10)
            {
                DB dd;
                dd = DB(dragon[0].position.x-0.6,ball1.position.y);
                db.push_back(dd);
            }
            if(mag_count>0)
            {
                mag_count++;
                if((ball1.position.x < mag_vector[0].position.x) || (ball1.position.x > (mag_vector[0].position.x+1.155)))
                {
                    ball1.speed=ball1.ospeed*3;
                    if(ball1.position.x < mag_vector[0].position.x && !inside_ring)
                    {
                        ball1.position.x+=(ball1.ospeed/8);
                    }
                    else if(!inside_ring)
                    {
                        ball1.position.x-=(ball1.ospeed/8);
                    }
                }
                else
                    ball1.speed=ball1.ospeed;

                if(ball1.position.y < (mag_vector[0].position.y-1))
                {
                    if(!inside_ring)
                        ball1.position.y+=(ball1.ospeed/5);
                    ball1.upspeed=ball1.ospeed*3;
                    ball1.ga=ball1.oga/3;
                    ball1.down_speed=ball1.odown_speed/3;
                }
                else if(ball1.position.y > mag_vector[0].position.y)
                {
                    ball1.upspeed=ball1.ospeed/3;
                    ball1.ga=ball1.oga*3;
                    ball1.down_speed=ball1.odown_speed*3;
                }
                else
                {
                    ball1.upspeed=ball1.ospeed;
                    ball1.ga=ball1.oga;
                    ball1.down_speed=ball1.odown_speed;
                }

                if(mag_count>=400)
                {
                    ball1.speed=ball1.ospeed;
                    ball1.upspeed=ball1.ospeed;
                    ball1.ga=ball1.oga;
                    ball1.down_speed=ball1.odown_speed;
                    mag_vector.erase(mag_vector.begin());
                    mag_count=0;
                }
            }
            count++;
            if(ball1.position.y>-2.8 && !inside_ring)
                ball1.increase_down_speed();
            else
            {
                ball1.move_right=false;
                ball1.move_left=false;
            }
            if(hit)
            {
                ball1.position.x=-3;
                ball1.position.y=-2.8;
                dragon.erase(dragon.begin(),dragon.end());
                db.erase(db.begin(),db.end());
                semring.erase(semring.begin(),semring.end());
                enemy1_vector.erase(enemy1_vector.begin(),enemy1_vector.end());
                enemy2_vector.erase(enemy2_vector.begin(),enemy2_vector.end());
                enemy3_vector.erase(enemy3_vector.begin(),enemy3_vector.end());
                coins_vector.erase(coins_vector.begin(),coins_vector.end());
                baloon_vector.erase(baloon_vector.begin(),baloon_vector.end());
                mag_vector.erase(mag_vector.begin(),mag_vector.end());
                diamond.erase(diamond.begin(),diamond.end());
                sc.erase(sc.begin(),sc.end());
                hit=false;
                ball1.ga=ball1.oga;
                mag_count=0;
                ball1.down_speed=ball1.speed;
                ball1.speed=ball1.ospeed;
                count+=100;
            }
        }

        glfwPollEvents();
    }
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\tYour score is: "<<score<<"\n\n\n\t\t\t      Thanks for playing. :)\n\n\n\n\n\n\n\n \n\n\n";
    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}

