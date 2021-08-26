#include<windows.h>
#include<iostream>
#include <GL/glut.h>
#include<math.h>

using namespace std;

float ax1,ax2,ay1,ay2;

void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,0.5,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000,1000,-1000,1000);
}

void keyboard(unsigned char key, int x,int y){

    if(key == 13)
    {
        exit(0);
    }
    else
    {
        cout<<"You have Entered : "<<key<<endl;
    }
}

void display(void)
{
    float x , y, dx, dy, p;
    p = (2*dx) - dy;
    x = ax1;
    y = ay1;
    dx = ax2 - ax1;
    dy = ay2 - ay1;
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.5);
    glVertex2i(x,y);
    glEnd();
    while ( x <= ax2)
    {
        if(p < 0){
            p += 2 * dy;
            x += 1;
            y = y;
        }
        else if(p >= 0){
            p += (2*dy) - (2*dx);
            x += 1;
            y += 1;
        }
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFlush();
}

int main(int argc, char** argv)
{
    cout<<"Enter starting coordinates : ";
    cin>>ax1>>ay1;
    cout<<"Enter ending coordinates : ";
    cin>>ax2>>ay2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Bresenham's Line Generation");
    glutPositionWindow(500,200);
    glutReshapeWindow(500,500);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
