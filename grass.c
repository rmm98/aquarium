#include<GL/glut.h>
void grass(int x)
{
    if(x==1000)
        return;
    glBegin(GL_POLYGON);
        glColor3f(0.000, 0.392, 0.000);
        glVertex2i(-480+x,-197);
        glVertex2i(-450+x,-197);
        glColor3f(0.678, 1.000, 0.184);
        glVertex2i(-440+x,-160);
        glColor3f(0.604, 0.804, 0.196);
        glVertex2i(-460+x,-180);
        glColor3f(0.678, 1.000, 0.184);
        glVertex2i(-465+x,-160);
        glColor3f(0.604, 0.804, 0.196);
        glVertex2i(-470+x,-180);
        glColor3f(0.678, 1.000, 0.184);
        glVertex2i(-490+x,-160);
    glEnd();
    grass(x+100);
}
