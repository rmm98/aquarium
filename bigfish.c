#include <GL/glut.h>

extern int offset3,rot3;
extern float xf,yf,zf;

void bigfish(int x,int y)
{
    glPushMatrix();
    glTranslatef(offset3,0,0);
    if(!rot3){
        glTranslatef(x+65,y,0);
        glRotatef(180,0,1,0);
        glTranslatef(-x-65,-y,0);
    }
    glScalef(xf,yf,zf);
    glBegin(GL_POLYGON);
    glColor3f(0.439, 0.502, 0.565);
        glVertex2i(x-20,y);
        glVertex2i(x+20,y+30);
        glColor3f(0.902, 0.902, 0.980);
        glVertex2i(x+100,y);
        glVertex2i(x+10,y-25);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.000, 0.627, 0.478);
        glVertex2i(x+20,y+30);
        glVertex2i(x+25,y+35);
        glVertex2i(x+100,y);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.902, 0.902, 0.980);
        glVertex2i(x+95,y);
        glColor3f(1.000, 0.627, 0.478);
        glVertex2i(x+145,y+30);
        glColor3f(0.439, 0.502, 0.565);
        glVertex2i(x+125,y);
        glVertex2i(x+145,y-30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.698, 0.133, 0.133);
        glVertex2i(x-5,y-13);
        glVertex2i(x+2,y-10);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
        glVertex2i(x+5,y+3);
    glEnd();

    glPointSize(1.0);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
        glVertex2i(x+5,y+3);
    glEnd();

    glPopMatrix();
}
