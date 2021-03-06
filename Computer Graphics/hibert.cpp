#include<windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

double points[2][2];

class line
{
public:
int n, xx, yy, x, y, h, r, d, l, u;
		void dda_line(int,int,int,int);
		void lineto(int,int);
		void move(int j,int h,int &x,int &y);
		void hilbert(int r, int d,int l,int u,int i,int h,int &x,int &y);
}p;
void line::dda_line(int xini,int yini,int xend,int yend)
{
    glPointSize(1.0);
    double dx=(xend-xini);
    double dy=(yend-yini);
    double steps;
    float xInc,yInc,x=xini,y=yini;
    steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
    xInc=dx/(float)steps;
    yInc=dy/(float)steps;
    glLineWidth(10.0);
    glVertex2f(x,y);
    int k;
    for(k=0;k<steps;k++)
    {
      x+=xInc;
      y+=yInc;
     glVertex2f(x,y);
  }
}
void line::lineto(int x, int y) {
    points[1][0] = x;
    points[1][1] = y;

    glBegin(GL_POINTS);
    p.dda_line(points[0][0], points[0][1],points[1][0], points[1][1]);
    glEnd();

    glutSwapBuffers();

    points[0][0] = x;
    points[0][1] = y;
}

void line::move(int j,int h,int &x,int &y) {
    if(j==1) y-=h;
    else if(j==2) x+=h;
    else if(j==3) y+=h;
    else if(j==4) x-=h;
    lineto(x,y);
    usleep(50000);
}

void line::hilbert(int r, int d,int l,int u,int i,int h,int &x,int &y) {

    if(i>0) {
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}


void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    p.hilbert(p.r,p.d,p.l,p.u,p.n,p.h,p.x,p.y);

}


int main(int argc, char *argv[]) {

    p.xx = 50;
    p.yy = 150;
    p.h = 10;
    p.r = 2;
    p.d = 3;
    p.l = 4;
    p.u = 1;

    cout<<"\nGive the value of n (number of iterations) : ";
    cin>>p.n;
    p.x = p.xx;
    p.y = p.yy;
    points[0][0] = p.x;
    points[0][1] = p.y;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Hilbert Curve");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
