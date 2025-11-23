#include <iostream>
#include<GL/glut.h>
#include<GL/glu.h>
using namespace std;
void myInit()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    gluOrtho2D(0,500,0,500);
}
void putpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void BresLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
void BresCircle(int xc,int yc,int r)
{
    int x=0;
    int y=r;
    int d= 3-2*r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y);
        putpixel(xc - x, yc + y);
        putpixel(xc + x, yc - y);
        putpixel(xc - x, yc - y);
        putpixel(xc + y, yc + x);
        putpixel(xc - y, yc + x);
        putpixel(xc + y, yc - x);
        putpixel(xc - y, yc - x);
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    BresLine(100, 100, 300, 100);
    BresLine(100,300, 300,300);
    BresLine(100,100,100,300);
    BresLine(300,100,300,300);
    BresCircle(200,200,50);
    glFlush();
}
int main(int argc,char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(500,500);
   glutCreateWindow("House using bresenham algorithm");
   myInit();
   glutDisplayFunc(display);
   glutMainLoop();
}
