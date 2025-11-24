#include <GL/glut.h>

float x1p=50, y1p=350, x2p=350, y2p=50;
float xmin=100, ymin=100, xmax=300, ymax=300;

int INSIDE=0, LEFT=1, RIGHT=2, BOTTOM=4, TOP=8;

int getCode(float x, float y)
{
    int code = INSIDE;
    if (x < xmin)  code |= LEFT;
    if (x > xmax)  code |= RIGHT;
    if (y < ymin)  code |= BOTTOM;
    if (y > ymax)  code |= TOP;
    return code;
}

void display()
{
    float x1=x1p, y1=y1p, x2=x2p, y2=y2p;
    int c1 = getCode(x1,y1);
    int c2 = getCode(x2,y2);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex2f(x1p,y1p);
        glVertex2f(x2p,y2p);
    glEnd();

    while (true)
    {
        if ((c1==0) && (c2==0)) break;
        else if (c1 & c2) return;
        else
        {
            float x, y;
            int out = c1 ? c1 : c2;

            if (out & TOP){
                x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
                y = ymax;
            }
            else if (out & BOTTOM){
                x = x1 + (x2-x1)*(ymin-y1)/(y2-y1);
                y = ymin;
            }
            else if (out & RIGHT){
                y = y1 + (y2-y1)*(xmax-x1)/(x2-x1);
                x = xmax;
            }
            else {
                y = y1 + (y2-y1)*(xmin-x1)/(x2-x1);
                x = xmin;
            }

            if (out == c1){
                x1 = x; y1 = y; c1 = getCode(x1,y1);
            }
            else {
                x2 = x; y2 = y; c2 = getCode(x2,y2);
            }
        }
    }

    // Draw clipped line (green)
    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Simple Cohen-Sutherland");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
