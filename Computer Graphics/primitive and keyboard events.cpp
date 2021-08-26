#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
void display();
void reshape(int,int);
void init(){
    glClearColor(1,1,1,1);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(10);
    //draw
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(-2,2);
    glVertex2f(-2,7);
    glVertex2f(-7,7);
    glVertex2f(-7,2);

    //draw end
    glEnd();
    glFlush();
    glLineWidth(10);
    //draw

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(-3,-1);
    glVertex2f(-3,-6);
    glVertex2f(-8,-6);
    glVertex2f(-8,-1);
    //draw end
    glEnd();
    glFlush();
    glLineWidth(10);
    //draw

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(5,-1);
    glVertex2f(2.5,-7);
    glVertex2f(7.5,-7);

    //draw end
    glEnd();
    glFlush();
    glLineWidth(10);
    //draw

    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(6,6);
    glVertex2f(7,3.5);
    glVertex2f(6,1);
    glVertex2f(4,1);
    glVertex2f(3,3.5);
    glVertex2f(4,6);


    //draw end
    glEnd();
    glFlush();

}
void keyboard_event(unsigned char key, int x, int y)
{
    if(key == 27)               // Esc key
        exit(0);
    else if(key == 13)          //Enter key
    {glClearColor(0,1,1, 1.0);
     glutPostRedisplay();}

    else
    cout<<"\n You have pressed: \n"<<key;
}

    void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc,char**argv)

{
    cout<<"----------WELCOME!!!--------"<<endl<<endl;
    cout<<"PRESS ENTER TO CHANGE BACKGROUND COLOR"<<endl<<endl;
    cout<<"PRESS ESC KEY TO EXIT"<<endl<<endl;
    glutInit(&argc,argv);//compulsory
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(500,0);
    glutInitWindowSize(800,500);
    glutCreateWindow("Window_1");
    glutDisplayFunc(display);
    //glutDisplayFunc(display1);//compulsory
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_event);
    init();
    glutMainLoop();//compulsory



}
