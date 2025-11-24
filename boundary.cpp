#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0, 500, 0, 500);
}

void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void boundaryFill(int x, int y, float fill[3], float boundary[3])
{
    float color[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);

    if ((color[0] != boundary[0] || color[1] != boundary[1] || color[2] != boundary[2]) &&
        (color[0] != fill[0] || color[1] != fill[1] || color[2] != fill[2]))
    {
        glColor3fv(fill);
        putpixel(x, y);

        boundaryFill(x + 1, y, fill, boundary);
        boundaryFill(x - 1, y, fill, boundary);
        boundaryFill(x, y + 1, fill, boundary);
        boundaryFill(x, y - 1, fill, boundary);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2i(150, 100);
        glVertex2i(300, 150);
        glVertex2i(350, 300);
        glVertex2i(250, 350);
        glVertex2i(150, 250);
    glEnd();
    glFlush();

    float fillColor[3] = {1, 0, 0};
    float boundaryColor[3] = {1, 1, 1};

    boundaryFill(150, 150, fillColor, boundaryColor);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Boundary Fill");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
