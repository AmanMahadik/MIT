#include<GL/glu.h>
#include<gl/glut.h>
#include<iostream>
using namespace std;
float angle =0.0f;
void init()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1.0,1.0,50.0);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.f,-7.0f);
    glRotatef(angle,1.0f,1.0f,1.0f);
    glColor3f(1,0,0);
    glutSolidCube(2.0);
    glColor3f(1,1,1);
    glLineWidth(2.0);
    glutWireCube(2.02);
    glutSwapBuffers();
}
void timer(int value)
{
    angle += 1.0f;
    if(angle>360)
    {
        angle=0;
    }
    glutPostRedisplay();
    glutTimerFunc(16,timer,0);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Spinning Cube");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;

}

