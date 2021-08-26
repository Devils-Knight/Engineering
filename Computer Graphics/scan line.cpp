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
}p[40];

void scanline()
{
    float m[40];
    int interx[30];
    int n=i,ymax=0,ymin=500,dx,dy,k;

    for(int i=0;i<n;i++)
    {
        if(p[i].y>ymax)
            ymax=p[i].y;
        if(p[i].y<ymin)
            ymin=p[i].y;

        dx=p[i+1].x-p[i].x;
        dy=p[i+1].y-p[i].y;

        if(dx==0)
            m[i]=0;
        if(dy==0)
            m[i]=1;

        if(dx!=0 && dy!=0)
        {
            m[i]=(float)dx/dy;
        }
    }

    for(int y=ymax;y>=ymin;y--)
    {
        k=0;
        for(int i=0;i<n;i++){
            if((p[i].y>y && p[i+1].y<=y) || (p[i].y<=y && p[i+1].y>y)){
                interx[k++]=p[i].x+(m[i]*(y-p[i].y));
            }
        }

        sort(interx,interx+k);

        for(int i=0;i<k-1;i+=2){
            glBegin(GL_LINES);
            glVertex2i(interx[i],y);
            glVertex2i(interx[i+1],y);
            glEnd();
            glFlush();
        }
    }
}

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
            else if(x>=550&&x<=600)
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
        scanline();
    }
}

void def()
{
    cout<<"\n\t\tMOUSE EVENTS"<<endl;
    cout<<"\nLeft Button : Color Selection from color palette and providing Vertices of Polygon"<<endl;
    cout<<"Right Button : Closing the Polygon"<<endl;
    cout<<"Middle Button : Use scan line algorithm to color"<<endl;
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Scanline Algorithm");
	myInit();
	def();
	glutDisplayFunc(display);
    glutMouseFunc(mymouse);
	glutMainLoop();
	return 0;
}
