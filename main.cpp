#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grass.c"
#include "pebbles.c"
#include "bubbles.c"
#include "goldfishes.c"
#include "pomfret.c"
#include "silverfish.c"
#include "bigfish.c"

int page = 0;
int offset1 = 1,state1 = 1,rot1 = 1;
int offset2 = -1,state2 = 1,rot2 = 1;
int offset3 = -1,state3 = 1,rot3 = 1;
int bubbleoff = 1;
int big_fish = 0;
float xf=1,yf=1,zf = 1;
char info[] = "blank";

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600,600,-300,300);
}

void drawText(char *string,float x,float y,float z)
{
    char *c;
	glRasterPos3f(x,y,z);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , *c);
	}
}

void display()
{
    if(page == 0)
    {
        glClearColor(0.5,0,0.3,0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0,1.0,1.0);
        drawText("COMPUTER GRAPHICS MINI-PROJECT",-180,180,0);
        drawText("4NM16CS118",-220,50,0);
        drawText("4NM16CS119",-220,0,0);
        drawText("4NM16CS120",-220,-50,0);
        drawText("REEVAN MARIO MIRANDA",30,50,0);
        drawText("RENISHA VEERA BARNES",30,0,0);
        drawText("ROSHNI MIRANDA",30,-50,0);
        drawText("AQUARIUM SIMULATION",-130,-180,0);
    }

    else if(page == 1)
    {
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        //Tank polygon
        glColor3f(0.690, 0.878, 0.902);
        glBegin(GL_POLYGON);
            glVertex2i(-500,200);
            glVertex2i(500,200);
            glVertex2i(500,-200);
            glVertex2i(-500,-200);
        glEnd();

        //Tank Frame
        glColor3f(0.824, 0.412, 0.118);
        glLineWidth(4.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(-500,200);
            glVertex2i(500,200);
            glVertex2i(500,-200);
            glVertex2i(-500,-200);
        glEnd();

        //Tank Roof
        glColor3f( 	0.627, 0.322, 0.176);
        glBegin(GL_POLYGON);
            glVertex2i(-550,200);
            glVertex2i(-500,230);
            glVertex2i(500,230);
            glVertex2i(550,200);
        glEnd();

        //Fish
        bubble(20,-400,-150);
        bubble(10,-390,-190);

        bubble(20,-380+700,-150);
        bubble(10,-390+700,-190);

        if(big_fish)
            bigfish(150,0);
        else{
            fish1(-400,-100);
            fish1(-350,-70);
            fish1(-350,-130);
            fish2(-400,100);
            fish3(330,-10);
            fish3(400,-20);
            fish3(420,30);
        }
        grass(0);

        glColor3f(0.000, 0.392, 0.000);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2i(-499,-196);
            glVertex2i(499,-196);
        glEnd();

        pebbles(0);
    }

    if(page == 2)
    {
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glColor3f(0.933, 0.910, 0.667);
            glVertex2i(-300,200);
            glVertex2i(300,200);
            glVertex2i(300,-200);
            glVertex2i(-300,-200);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor3f(0.251, 0.878, 0.816);
            glVertex2i(-300,200);
            glVertex2i(300,200);
            glVertex2i(300,-200);
            glVertex2i(-300,-200);
        glEnd();

        if(strcmp(info,"goldf")==0)
        {
            glColor3f(1.000, 0.271, 0.000);
            drawText("GOLD FISH",-60,160,0);
            glColor3f(0.804, 0.361, 0.361);
            drawText("-The goldfish is a freshwater fish in the family Cyprinidae of order",-270,120,0);
            drawText("  Cypriniformes.",-270,80,0);
            drawText("-It is one of the most commonly kept aquarium fish.",-270,40,0);
            drawText("-A relatively small member of the carp family, the goldfish is native",-270,0,0);
            drawText("  to East Asia.",-270,-40,0);
            drawText("-It was first selectively bred in ancient China more than 1,000 years",-270,-80,0);
            drawText("  ago, and several distinct breeds have since been developed.",-270,-120,0);
            drawText("-Goldfish breeds vary greatly in size, body shape and coloration.",-270,-160,0);

        }

        else if(strcmp(info,"silvf")==0)
        {
            glColor3f(1.000, 0.271, 0.000);
            drawText("SILVER DOLLAR",-60,160,0);
            glColor3f(0.804, 0.361, 0.361);
            drawText("-The silver dollar is a peaceful schooling species that spends most ",-270,120,0);
            drawText("  of its time in the mid to upper-level of the water.",-270,80,0);
            drawText("-Its maximum lifespan is more than ten years.",-270,40,0);
            drawText("-Their diet is almost exclusively vegetarian and in captivity they will",-270,0,0);
            drawText("  often eat all the plants in a tank. They will also eat worms and small ",-270,-40,0);
            drawText("  insects.",-270,-80,0);
        }

        else if(strcmp(info,"pompf")==0)
        {
            glColor3f(1.000, 0.271, 0.000);
            drawText("ANGEL FISH",-60,160,0);
            glColor3f(0.804, 0.361, 0.361);
            drawText("-Possibly the most recognized freshwater fish in aquarium hobby,",-270,120,0);
            drawText("  Angelfish belong to the family Cichlidae.",-270,80,0);
            drawText("-Admired for their graceful swimming behavior, angelfish make",-270,40,0);
            drawText("  stunning additions to large community aquariums.",-270,0,0);
            drawText("-In their natural habitat, they are found almost exclusively in quiet,",-270,-40,0);
            drawText("  slow moving water.",-270,-80,0);
        }

        else if(strcmp(info,"bigcf")==0)
        {
            glColor3f(1.000, 0.271, 0.000);
            drawText("SILVER CATFISH",-70,160,0);
            glColor3f(0.804, 0.361, 0.361);
            drawText("-Catfish got their name from their whiskers-like barbels, however,",-270,120,0);
            drawText("  not all Catfish have them. ",-270,80,0);
            drawText("-And just like they differ in size and features, they also differ in",-270,40,0);
            drawText("  their personalities, with some species being friendlier than others.",-270,0,0);
            drawText("-Smaller sized Catfish, especially those of the Corydoras genus, ",-270,-40,0);
            drawText("  are picked by aquarists for their prolific scavenging abilities ",-270,-80,0);
            drawText("  that’s extremely helpful in tank cleaning and maintenance.",-270,-120,0);
        }
    }

    glutSwapBuffers();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='n'|| key=='N')
        page = 1;
    else if(key == 'b'|| key=='B')
        page = 0;
    else if(key == 'm'||key=='M')
        big_fish = !big_fish;
    display();
    glFlush();
}

void myMouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        page = 2;
        if(big_fish)
            strcpy(info,"bigcf");
        else if(y>=370 && y<=450)
            strcpy(info,"goldf");
        else if(y>=270 && y<=330)
            strcpy(info,"silvf");
        else if(y>=190 && y<=230)
            strcpy(info,"pompf");
        else
            strcpy(info,"blank");
    }
    else if(button == GLUT_RIGHT_BUTTON)
    {
        page = 1;
    }
    display();
    glFlush();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    switch(state1)
    {
        case 1:
            if(offset1<800)
                offset1++;
            else
            {
                state1 = -1;
                rot1 = !rot1;
            }
            break;
        case -1:
            if(offset1>0)
                offset1--;
            else
            {
                state1 = 1;
                rot1 = !rot1;
            }
            break;
    }

    switch(state2)
    {
        case 1:
            if(offset2>-790)
                offset2--;
            else
            {
                state2 = -1;
                rot2 = !rot2;
            }
            break;
        case -1:
            if(offset2<0)
                offset2++;
            else
            {
                state2 = 1;
                rot2 = !rot2;
            }
            break;
    }

    switch(state3)
    {
        case 1:
            if(offset3>-450)
                offset3--;
            else
            {
                state3 = -1;
                rot3 = !rot3;
            }
            break;
        case -1:
            if(offset3<0)
                offset3++;
            else
            {
                state3 = 1;
                rot3 = !rot3;
                if(xf<=1.5){
                    xf+=0.15;yf+=0.15;zf+=0.15;
                }
            }
            break;
    }

    if(bubbleoff<300)
        bubbleoff++;
    else
        bubbleoff=0;
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,600);
    glutCreateWindow("Aquarium Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutMouseFunc(myMouse);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
    return 0;
}
