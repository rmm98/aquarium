#include <GL/glut.h>

extern int offset2;
extern int rot2;

void fish3(int x,int y)
{
    glPushMatrix();
    glTranslatef(offset2,0,0);
    if(!rot2){
        glTranslatef(x,y,0);
        glRotatef(180,0,1,0);
        glTranslatef(-x,-y,0);
    }
    float angle;
    int i;
    int sw =1;
    glBegin(GL_POLYGON);
        for(i=0;i<360;i++){
            sw = !sw;
            if(sw)
                glColor3f(0.373, 0.620, 0.627);
            else
                glColor3f(0.690, 0.769, 0.871);
            angle = i*3.142/180;
            glVertex2f(x+25*cos(angle),y+14*sin(angle));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.373, 0.620, 0.627);
        glVertex2i(x+25,y);
        glColor3f(0.690, 0.769, 0.871);
        glVertex2i(x+35,y+14);
        glVertex2i(x+35,y-14);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
        glVertex2i(x-15,y+2);
    glEnd();
    glPopMatrix();
}
