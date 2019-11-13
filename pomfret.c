#include <GL/glut.h>

extern int offset1;
extern int rot1;

void fish2(int x,int y)
{
    glPushMatrix();
    glTranslatef(offset1,0,0);
    if(!rot1){
        glTranslatef(x+40,y-30,0);
        glRotatef(180,0,1,0);
        glTranslatef(-(x+40),-(y-30),0);
    }
    glBegin(GL_POLYGON);
        glColor3f(0.980, 0.502, 0.447);
        glVertex2i(x-2,y+5);
        glColor3f(1.000, 0.714, 0.757);
        glVertex2i(x+25,y-10);
        glColor3f(0.980, 0.502, 0.447);
        glVertex2i(x-2,y-25);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.980, 0.502, 0.447);
        glVertex2i(x+50,y+18);
        glVertex2i(x+80,y-10);
        glVertex2i(x+50,y-38);
        glColor3f(1.000, 0.714, 0.757);
        glVertex2i(x+20,y-10);
    glEnd();
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
        glVertex2i(x+70,y-10);
    glEnd();
    glPopMatrix();
}
