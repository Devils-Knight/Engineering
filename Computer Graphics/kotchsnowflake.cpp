#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
float PI= 3.1415926535;
using namespace std;
int z = sqrt(3) * 150;
int it = -1;
class Curve{
    float angle = (60*PI)/180;
public:
   void kotchCurve(int x1, int y1, int x2, int y2, int iteration){
    if(iteration == -1){
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
        if(it== 0){
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_LINE_LOOP);
            glVertex2i(100, 170);
            glVertex2i(250, z+170);
            glVertex2i(400, 170);
            glEnd();
            glFlush();
            return;
        }
        ///Calling Kotch Curve function for all three sides of triangle
        else{
            kotchCurve(250,z+170,100,170,it);
            kotchCurve(400,170,250,z+170,it);
            kotchCurve(100,170,400,170,it);
        }
    }


};
Curve koch;             ///object Declaration

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void defIteration()
{
    cout<<"\n\tEnter number of iterations : ";
    cin>>it;
}

void def()
{
    cout<<"\n\t\t\t\tMOUSE EVENTS";
    cout<<"\n\n\tLeft Button : Display Kotch Snowflake Curve";
    cout<<"\n\tRight Button : Clear Screen";
    cout<<"\n\tMiddle Button : Exit"<<endl;
    defIteration();
}

void mouse(int btn, int state, int x, int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glutPostRedisplay();
    }

    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        it = -1;
        defIteration();
    }

    if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
        exit(0);
    }
}
void display(){
    koch.display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutCreateWindow("Kotch Snowflake Curve");
    glutPositionWindow(200, 200);
    glutReshapeWindow(500, 500);
    glutDisplayFunc(display);
    init();
    def();
    glutMouseFunc(mouse);
    glutMainLoop();
}
