#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<bits/stdc++.h>

using namespace std;

bool complete=false;
bool colorcomplete=false;

int i=0;

class points{

    public:

    int x,y;

    void setxy(int p,int q)
    {
        x=p;
        y=q;
    }
}p[20];

void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,480.0,0.0);
}

void display()
{

    if(!complete)
    {
        glPointSize(3);
        glBegin(GL_LINE_STRIP);
            glVertex2i(p[i-2].x,p[i-2].y);
            glVertex2i(p[i-1].x,p[i-1].y);
        glEnd();
        glFlush();
    }
    else
    {
        glPointSize(3);
        glBegin(GL_LINE_STRIP);
            glVertex2i(p[i-1].x,p[i-1].y);
            glVertex2i(p[0].x,p[0].y);
        glEnd();
        glFlush();
    }
}
void colorfill()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
	glColor3f(1,0,0);
	glRecti(500,50,550,100);
	glColor3f(0,1,0);
	glRecti(550,50,600,100);
	glColor3f(0,0,1);
	glRecti(500,100,550,150);
	glColor3f(1,1,0);
	glRecti(550,100,600,150);
	glColor3f(0,1,1);
	glRecti(500,150,550,200);
	glColor3f(1,0,1);
	glRecti(550,150,600,200);
	glColor3f(10,8,1);
	glRecti(500,200,550,250);
	glColor3f(0.5,10,5);
	glRecti(550,200,600,250);
	glFlush();
}

void mymouse(int button,int state,int x,int y)
{
	if(!colorcomplete)
		colorfill();

	if(x>=500&&x<=600)
	{
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
            if(x>=500&&x<=550)
            {
                if(y>=50&&y<=100)
                {
                    glColor3f(1,0,0);
                    colorcomplete=true;
                }
                else if(y>=100&&y<=150)
                {
                    glColor3f(0,0,1);
                    colorcomplete=true;
                }
                else if(y>=150&&y<=200)
                {
                    glColor3f(0,1,1);
                    colorcomplete=true;
                }
                else if(y>=200&&y<=250)
                {
                    glColor3f(10,8,1);
                    colorcomplete=true;
                }
            }
            else if(x>=550&&y<=600)
            {
                if(y>=50&&y<=100)
                {
                    colorcomplete=true;
                    glColor3f(0,1,0);
                }
                else if(y>=100&&y<=150)
                {
                    colorcomplete=true;
                    glColor3f(1,1,0);
                }
                else if(y>=150&&y<=200)
                {
                    colorcomplete=true;
                    glColor3f(1,0,1);
                }
                else if(y>=200&&y<=250)
                {
                    colorcomplete=true;
                    glColor3f(0.5,10,5);
                }
            }
        }
	}

	if(x>=0 && x<500)
	{
        if(colorcomplete &&!complete && button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
            p[i++].setxy(x,y);
            glPointSize(4);
            glBegin(GL_POINTS);
                glVertex2i(p[i-1].x,p[i-1].y);
            glEnd();
            glFlush();
        }
        if(!complete && button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        {
            complete=true;
            p[i].setxy(p[0].x,p[0].y);
            glutPostRedisplay();
        }

        if(!complete && i>1)
            glutPostRedisplay();
	}


    if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        i = 0;
        complete = false;
        colorcomplete = false;
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
}

void def()
{
    cout<<"\n\t\t Mouse Buttons Usage"<<endl;
    cout<<"\t\t---------------------"<<endl;
    cout<<"Left Button   : Color Selection from color palette and providing Vertices of Polygon"<<endl;
    cout<<"Right Button  : Closing the Polygon"<<endl;
    cout<<"Middle Button : Clearing the screen"<<endl;
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(500,300);
	glutCreateWindow("Polygon Drawing using mouse");
	myInit();
	def();
	glutDisplayFunc(display);
    glutMouseFunc(mymouse);
	glutMainLoop();
	return 0;
}
