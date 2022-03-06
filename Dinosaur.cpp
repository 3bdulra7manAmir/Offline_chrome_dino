
#include <GL/glut.h>
#include <Windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <thread>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>


//Music
#pragma comment(lib, "winmm.lib")

static double animationPeriod = 5; //Animation speed.
static int isAnimate = 0;      //Start after death, Status Disabled.
int Randnum;
int n = 1;
const int fact = 3; //Dino Size
const int x = 80;   //Dino Start Point
const double DEG2RAD = 3.1415926535897932384 / 180;
char X = 'x';
char Score[] = "Score: "; //Score Text.
char c[] = "0   ";
static double w = 200;
static int flag = 0;
static int walk = 0;
static int x_ = 2500;
using namespace std;


//Score Counter.
void counter()
{
    for (int i = 0; i = 1;)
    {
        if (isAnimate == 1)
        {
            int x = 0;
            Sleep(500 - x);
            string number = to_string(n);
            strcpy_s(c, number.c_str());
            n++;
            if (n % 20 == 0)
            {
                animationPeriod -= 0.2;
                x += 5;
            }

        }
        else i = 1;
    }
}

//Random Trees.
void Random()
{
    int max;
    max = 3;
    srand(time(0));
    Randnum = rand() % max;
}

//Animation Speed.
void animate(int value)
{
    if (isAnimate)
    {
        glutPostRedisplay();
        glutTimerFunc(animationPeriod, animate, 1);
    }

}

//Keys Input.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        if (isAnimate)
        {
            isAnimate = 0;
            PlaySound(NULL, NULL, SND_ALIAS);
        }
        else
        {
            PlaySound(TEXT("E:\\breakout.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            isAnimate = 1;
            animate(1);
        }
        break;
    }
}

void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_UP && flag == 0 && w <= 200.0 && isAnimate == 1)
    {
        flag = 1;
    }
}

//DinaSuar Collision with Trees.
double collision(double len1, double len2, double len3)
{
    //Random Case 1
    if (Randnum == 0)
    {
        if (abs(157 + x - (x_ + x + 70)) <= 100 + x)
        {
            if (5 * fact + w <= 500 * len1)

                return 1;
            return 0;
        }
    }
    //Random Case 2 short one
    if (Randnum == 1)
    {
        //X col
        if (abs(157 + x - (x_ + x + 80)) <= 100 + x)
        {
            //Y col
            if (5 * fact + w <= 400 * len3)

                return 1;
            return 0;
        }
    }
    //Random Case 3 two trees
    if (Randnum == 2)
    {
        if (abs(157 + x - (x_ + x + -80)) <= 100 + x)
        {
            if (5 * fact + w <= 400 * len2)

                return 1;
            return 0;
        }
    }


    return 0;
}

//Drawing Circle.
void draw_circle(double theta, double inner_radius, double outer_radius, int x, int y, int sin_sign = 1, int cos_sign = 1) {
    glBegin(GL_POINTS);
    glColor3f(170.0 / 255.0, 170.0 / 255.0, 170.0 / 255.0);
    for (double r = outer_radius; r >= inner_radius; r -= 3.0) {
        for (double i = 0; i < theta; i++) {
            double degInRad = i * DEG2RAD;
            glVertex2f(cos_sign * cos(degInRad) * r + x, sin_sign * sin(degInRad) * r + y);
        }
    }
    glEnd();
}

//First "Long" Tree Model.
void generate_tree1(int x_, double len1)
{
    int x = 20;
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_, 250 * len1);
    glVertex2f(x_ + x, 250 * len1);
    glVertex2f(x_ + x, 650 * len1);
    glVertex2f(x_, 650 * len1);
    glEnd();

    draw_circle(180.0, 0.0, x / 2, x_ + x / 2, 650 * len1);

    glBegin(GL_POLYGON);
    glVertex2f(x_ + x + 25, 400 * len1);
    glVertex2f(x_ + x + 50, 400 * len1);
    glVertex2f(x_ + x + 50, 600 * len1);
    glVertex2f(x_ + x + 25, 600 * len1);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 600 * len1);

    glBegin(GL_POLYGON);
    glVertex2f(x_ - 25, 400 * len1);
    glVertex2f(x_ - 50, 400 * len1);
    glVertex2f(x_ - 50, 600 * len1);
    glVertex2f(x_ - 25, 600 * len1);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 600 * len1);
    draw_circle(90.0, 25, 50, x_ + x, 400 * len1, -1);
    draw_circle(90.0, 25, 50, x_, 400 * len1, -1, -1);
}

//Third "Short" Trees Model.
void generate_tree2(int x_, double len2)
{
    int x = 20;
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_, 200 * len2);
    glVertex2f(x_ + x, 200 * len2);
    glVertex2f(x_ + x, 400 * len2);
    glVertex2f(x_, 400 * len2);
    glEnd();

    draw_circle(180.0, 0.0, x / 2, x_ + x / 2, 400 * len2);

    glBegin(GL_POLYGON);
    glVertex2f(x_ + x + 25, 300 * len2);
    glVertex2f(x_ + x + 50, 300 * len2);
    glVertex2f(x_ + x + 50, 400 * len2);
    glVertex2f(x_ + x + 25, 400 * len2);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 400 * len2);

    glBegin(GL_POLYGON);
    glVertex2f(x_ - 25, 300 * len2);
    glVertex2f(x_ - 50, 300 * len2);
    glVertex2f(x_ - 50, 400 * len2);
    glVertex2f(x_ - 25, 400 * len2);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 400 * len2);
    draw_circle(90.0, 25, 50, x_ + x, 300 * len2, -1);
    draw_circle(90.0, 25, 50, x_, 300 * len2, -1, -1);
}

//Second "Short" Two Trees Model.
void generate_tree3(int x_, double len3)
{
    //first short tree
    int x = 20;
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_, 200 * len3);
    glVertex2f(x_ + x, 200 * len3);
    glVertex2f(x_ + x, 400 * len3);
    glVertex2f(x_, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, x / 2, x_ + x / 2, 400 * len3);

    glBegin(GL_POLYGON);
    glVertex2f(x_ + x + 25, 300 * len3);
    glVertex2f(x_ + x + 50, 300 * len3);
    glVertex2f(x_ + x + 50, 400 * len3);
    glVertex2f(x_ + x + 25, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 400 * len3);

    glBegin(GL_POLYGON);
    glVertex2f(x_ - 25, 300 * len3);
    glVertex2f(x_ - 50, 300 * len3);
    glVertex2f(x_ - 50, 400 * len3);
    glVertex2f(x_ - 25, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 400 * len3);
    draw_circle(90.0, 25, 50, x_ + x, 300 * len3, -1);
    draw_circle(90.0, 25, 50, x_, 300 * len3, -1, -1);

    //second short tree
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_ - 150, 200 * len3);
    glVertex2f(x_ - x - 150, 200 * len3);
    glVertex2f(x_ - x - 150, 400 * len3);
    glVertex2f(x_ - 150, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, x / 2, x_ - x - 280 / 2, 400 * len3);

    glBegin(GL_POLYGON);
    glVertex2f(x_ - x - 175, 300 * len3);
    glVertex2f(x_ - x - 200, 300 * len3);
    glVertex2f(x_ - x - 200, 400 * len3);
    glVertex2f(x_ - x - 175, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - x - 375.0 / 2, 400 * len3);

    glBegin(GL_POLYGON);
    glVertex2f(x_ - 125, 300 * len3);
    glVertex2f(x_ - 100, 300 * len3);
    glVertex2f(x_ - 100, 400 * len3);
    glVertex2f(x_ - 125, 400 * len3);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 225.0 / 2, 400 * len3);
    draw_circle(90.0, 25, 50, x_ - 150, 300 * len3, -1);
    draw_circle(90.0, 25, 50, x_ - x - 150, 300 * len3, -1, -1);
}


//Reset Values.
void reset()
{
    w = 200;
    flag = 0;
    walk = 0;
    x_ = 2500;
    animationPeriod = 5;
    isAnimate = 0;
    n = 1;
}

//Score Printing.
void output(int x, int y, char* string)
{
    int len;
    len = (int)strlen(string);
    GLvoid* font = GLUT_BITMAP_TIMES_ROMAN_24;
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glRasterPos2f(x, y);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

//Rendering fun.
void render(void)
{

    //Walking Points
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    for (int i = 0; i < 100; i++)
    {
        glVertex2f(rand() % 2000, 200);
        glVertex2f((rand() + 31) % 2000, 150);
    }
    glEnd();

    //Trees Shapes
    if (Randnum == 0)
    {
        generate_tree1(x_, 1.0);
    }
    if (Randnum == 1)
    {
        generate_tree2(x_, 1.0);
    }
    if (Randnum == 2)
    {
        generate_tree3(x_, 1.0);
    }

    //Moving Animation.
    if (x_ >= 0)
        x_ -= 5;
    else
    {
        x_ = 2000 + rand() % 400;
        Random();
    }
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f((170.0) / 255.0, (170.0) / 255.0, (170.0) / 255.0);
    glVertex2f(0, 250);
    glVertex2f(2000, 250);
    glEnd();
    glLineWidth(10);



    //DinSaur Drawing.
    glBegin(GL_LINES);
    glColor3f(170.0 / 255.0, 170.0 / 255.0, 170.0 / 255.0);
    glVertex2f(10 + x, 75 * fact + w);
    glVertex2f(10 + x, 45 * fact + w);
    glVertex2f(15 + x, 65 * fact + w);
    glVertex2f(15 + x, 40 * fact + w);
    glVertex2f(20 + x, 60 * fact + w);
    glVertex2f(20 + x, 35 * fact + w);
    glVertex2f(25 + x, 55 * fact + w);
    glVertex2f(25 + x, 35 * fact + w);
    glVertex2f(30 + x, 55 * fact + w);
    glVertex2f(30 + x, 35 * fact + w);
    glVertex2f(35 + x, 55 * fact + w);
    glVertex2f(35 + x, 25 * fact + w);
    glVertex2f(40 + x, 60 * fact + w);
    glVertex2f(40 + x, 5 * fact + w - walk);
    glVertex2f(45 + x, 65 * fact + w);
    glVertex2f(45 + x, 15 * fact + w);
    glVertex2f(45 + x, 10 * fact + w - walk);
    glVertex2f(45 + x, 5 * fact + w - walk);
    glVertex2f(50 + x, 10 * fact + w - walk);
    glVertex2f(50 + x, 5 * fact + w - walk);
    glVertex2f(55 + x, 10 * fact + w - walk);
    glVertex2f(55 + x, 5 * fact + w - walk);
    glVertex2f(50 + x, 65 * fact + w);
    glVertex2f(50 + x, 20 * fact + w);
    glVertex2f(55 + x, 70 * fact + w);
    glVertex2f(55 + x, 25 * fact + w);
    glVertex2f(63 + x, 75 * fact + w);
    glVertex2f(63 + x, 20 * fact + w);
    glVertex2f(70 + x, 115 * fact + w);
    glVertex2f(70 + x, 5 * fact + w + walk);
    glVertex2f(78 + x, 120 * fact + w);
    glVertex2f(78 + x, 25 * fact + w);
    glVertex2f(78 + x, 10 * fact + w + walk);
    glVertex2f(78 + x, 5 * fact + w + walk);
    glVertex2f(85 + x, 10 * fact + w + walk);
    glVertex2f(85 + x, 5 * fact + w + walk);
    glVertex2f(87 + x, 120 * fact + w);
    glVertex2f(87 + x, 115 * fact + w);
    glVertex2f(87 + x, 110 * fact + w);
    glVertex2f(87 + x, 30 * fact + w);
    glVertex2f(95 + x, 120 * fact + w);
    glVertex2f(95 + x, 35 * fact + w);
    glVertex2f(103 + x, 120 * fact + w);
    glVertex2f(103 + x, 75 * fact + w);
    glVertex2f(103 + x, 65 * fact + w);
    glVertex2f(103 + x, 60 * fact + w);
    glVertex2f(110 + x, 65 * fact + w);
    glVertex2f(110 + x, 60 * fact + w);
    glVertex2f(118 + x, 65 * fact + w);
    glVertex2f(118 + x, 55 * fact + w);
    glVertex2f(112 + x, 120 * fact + w);
    glVertex2f(112 + x, 85 * fact + w);
    glVertex2f(112 + x, 80 * fact + w);
    glVertex2f(112 + x, 75 * fact + w);
    glVertex2f(120 + x, 120 * fact + w);
    glVertex2f(120 + x, 85 * fact + w);
    glVertex2f(120 + x, 80 * fact + w);
    glVertex2f(120 + x, 75 * fact + w);
    glVertex2f(126 + x, 120 * fact + w);
    glVertex2f(126 + x, 85 * fact + w);
    glVertex2f(126 + x, 80 * fact + w);
    glVertex2f(126 + x, 75 * fact + w);
    glVertex2f(135 + x, 120 * fact + w);
    glVertex2f(135 + x, 85 * fact + w);
    glVertex2f(135 + x, 80 * fact + w);
    glVertex2f(135 + x, 75 * fact + w);
    glVertex2f(142 + x, 120 * fact + w);
    glVertex2f(142 + x, 85 * fact + w);
    glVertex2f(150 + x, 120 * fact + w);
    glVertex2f(150 + x, 85 * fact + w);
    glVertex2f(157 + x, 115 * fact + w);
    glVertex2f(157 + x, 85 * fact + w);
    glEnd();

    //Checking Collisions
    if (collision(1.0, 1.0, 1.0))
    {
        PlaySound(NULL, NULL, SND_ALIAS);
        reset();
    }
    if (w <= 200) {
        if (walk == -20)
            walk = 20;
        else {
            walk = -20;
        }
    }
    else {
        walk = 0;
    }

    if (flag == 1) {
        if (w <= 1000) {
            w = w + 8;
        }
        else {
            flag = 0;
        }
    }
    else if (w >= 200)
        w = w - 8;

}

void setup(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2000, 0.0, 2000);
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    render();
    output(1600, 1800, Score);
    output(1800, 1800, c);
    glFlush();


}

int main(int argc, char** argv) {

    thread first(counter);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1230, 650);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Dinosaur!!");
    setup();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);

    glutMainLoop();
}