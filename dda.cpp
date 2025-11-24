#include<GL/glut.h>

#include<GL/glu.h>
#include<iostream>
using namespace std;
void putpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void DDA(int x1,int y1,int x2, int y2)
{
    int dx= x2-x1;
    int dy= y2-y1;

    int steps = abs(dx)>abs(dy) ? abs(dx) : abs(dy);
    float xinc =dx/(float)steps;
    float yinc =dy/(float)steps;
    float x =x1;
    float y =y1;
    for(int i=0;i<=steps;i++)
    {
        putpixel(x,y);
        x +=xinc;
        y +=yinc;
    }
}
void myInit()
{

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    gluOrtho2D(0,500,0,500);
    glPointSize(5.0);
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    DDA(100,100,300,100);
    DDA(100,100,100,300);
    DDA(300,100,300,300);
    DDA(100,300,300,300);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("MY First DDA Program");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
