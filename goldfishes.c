#include <GL/glut.h>
extern int offset1;
extern int rot1;

void fish1(int x,int y)
{
    glPushMatrix();
    glTranslatef(offset1,0,0);
    if(!rot1){
        glTranslatef(x+10,y-10,0);
        glRotatef(180,0,1,0);
        glTranslatef(-(x+10),-(y-10),0);
    }
    glColor3f(1.000, 0.843, 0.000);
    glBegin(GL_POLYGON);
        glVertex2i(x,y);
        glVertex2i(x+30,y);
        glVertex2i(x+30,y-20);
        glVertex2i(x,y-20);
    glEnd();

    glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);
        glVertex2i(x,y-10);
        glVertex2i(x-10,y-20);
        glVertex2i(x-10,y);
    glEnd();

    glColor3f(0,0,0);
    glPointSize(2.0);
    glBegin(GL_POINTS);
        glVertex2i(x+25,y-10);
    glEnd();
    glPopMatrix();
}
