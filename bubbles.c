#include <GL/glut.h>
extern int bubbleoff;

void bubble(int r,int x,int y)
{
    float angle;
    glColor3f(0.000, 0.749, 1.000);
    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
        for(int i = 0;i<=360;i++)
        {
            angle = i * 3.142/180;
            glVertex2f(x+r*cos(angle),y+bubbleoff+r*sin(angle));
        }
    glEnd();
}
