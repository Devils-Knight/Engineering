#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
float PI=3.1415926535;
using namespace std;

static int menuId;

int ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0, it = 0;
class Curve{
    float angle = (60*PI)/180;
public:

    void kotchCurve(int x1, int y1, int x2, int y2, int iteration){
        if(iteration == 0){
            glColor3f(1.0,0.0,0.0);
             glBegin(GL_LINE_STRIP);
                 glVertex2i(x1, y1);
                 glVertex2i(x2, y2);
             glEnd();
             glFlush();
             return;
        }

         int x3 = (2*x1+x2)/3;
         int y3 = (2*y1+y2)/3;

         int x4 = (x1+2*x2)/3;
         int y4 = (y1+2*y2)/3;

         int x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
         int y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);

         if(iteration > 0){
             kotchCurve(x1, y1, x3, y3, iteration-1);
             kotchCurve(x3, y3, x, y, iteration-1);
             kotchCurve(x, y, x4, y4, iteration-1);
             kotchCurve(x4, y4, x2, y2, iteration-1);
         }
         else{
             glColor3f(1.0,0.0,0.0);
             glBegin(GL_LINE_STRIP);
                 glVertex2i(x1, y1);
                 glVertex2i(x3, y3);
                 glVertex2i(x, y);
                 glVertex2i(x4, y4);
                 glVertex2i(x2, y2);
             glEnd();
             glFlush();
         }
    }
    void display(){
        kotchCurve(ax1, ay1, ax2, ay2, it);
    }


};
Curve koch;     ///Object declaration
void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27)
    {
        cout<<"\nYou have pressed : Escape"<<endl;
        cout<<"Closing Output Window"<<endl;
        exit(0);
    }
    else
    {
        cout<<"\nYou have pressed : "<<key<<endl;
        cout<<"Enter Escape to exit"<<endl;
    }
}
void mouse(int btn, int state, int x, int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ax1 = x;
        ay1 = 500-y;
    }

    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        ax2 = x;
        ay2 = 500-y;
        cout<<"\n\tEnter number of iterations : ";
        cin>>it;
        glutPostRedisplay();
        cout<<"\n\tKotch Curve Drawn Successfully"<<endl;
    }
}
void menu(int val)
{
    if(val == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        ax1  = ax2 = ay1 = ay2 = it = 0;
    }
}

void createMenu()
{
    menuId = glutCreateMenu(menu);
        glutAddMenuEntry("CLEAR SCREEN", 1);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

void def()
{
    cout<<"\n\t\t\t\tMOUSE EVENTS";
    cout<<"\n\n\t1) Left Button : Provide Starting Coordinates";
    cout<<"\n\t2) Right Button : Provide Ending Coordinates";
    cout<<"\n\n\t\t\t\tMENU EVENTS";
    cout<<"\n\n\t1) Clear Screen"<<endl;
}
void display(){
    koch.display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutCreateWindow("Kotch Curve");
    glutPositionWindow(200, 200);
    glutReshapeWindow(500, 500);
    init();
    createMenu();
    def();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
