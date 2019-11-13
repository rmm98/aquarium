#include <GL/glut.h>
#include <math.h>
#include <time.h>
void pebbles(int x)
{
    if(x>912)
    {
        float angle;
    int i;
    glColor3f(0.980, 0.502, 0.447);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-492+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    glColor3f(0.933, 0.910, 0.667);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-480+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    glColor3f(0.576, 0.439, 0.859);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-468+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    return;
    }

    float angle;
    int i;
    glColor3f(0.980, 0.502, 0.447);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-492+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    glColor3f(0.933, 0.910, 0.667);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-480+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    glColor3f(0.576, 0.439, 0.859);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-468+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    glColor3f( 	0.502, 0.502, 0.000);
    glBegin(GL_POLYGON);
        for( i=0;i<360;i++)
        {
            angle = i*3.142/180;
            glVertex2f(-456+x+6*cos(angle),-192+5*sin(angle));
        }
    glEnd();
    pebbles(x+48);
}
