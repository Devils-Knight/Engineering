#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

static int window;
static int choice;
class basic
{

    public:

    float xc, yc, r;
    float ax1, ay1, ax2, ay2;

    void drawPixelSymmetry(int x, int y)
    {

        glPointSize(4.0);
        glBegin(GL_POINTS);
        glVertex2f(xc+x,yc+y);
        glVertex2f(xc-x,yc+y);
        glVertex2f(xc+x,yc-y);
        glVertex2f(xc-x,yc-y);
        glVertex2f(xc+y,yc+x);
        glVertex2f(xc-y,yc+x);
        glVertex2f(xc+y,yc-x);
        glVertex2f(xc-y,yc-x);
        glEnd();
    }

 void modifiedbresenham()
    {
        int dx, dy, e, inc1, inc2, x,y;
        float c1=0.15,c2;
        int incx = 1, incy = 1;
        x = ax1;
        y = ay1;

        dx = ax2 - ax1;
        dy = ay2 - ay1;

        if (dx < 0)
            dx = -dx;
        if (dy < 0)
            dy = -dy;

        if (ax2 < ax1)
            incx = -1;
        if (ay2 < ay1)
            incy = -1;

        glPointSize(4.0);

        if (dx > dy)
        {
            glBegin(GL_POINTS);
            glColor3f(c1,0.7,c2);
            glVertex2i(x,y);
            glEnd();
            e = (2 * dy) - dx;
            inc1 = 2 * (dy - dx);
            inc2 = 2 * dy;
            for(int i = 0; i < dx; i++) {
                if (e >= 0)
                {
                    y += incy;
                    e += inc1;
                }
                else
                    e += inc2;
                x += incx;
                glBegin(GL_POINTS);
                glColor3f(c1,0.7,c2);
                glVertex2i(x,y);
                glEnd();
            }
        }
        else
        {
            glBegin(GL_POINTS);
            glColor3f(c1,0.7,c2);
            glVertex2i(x,y);
            glEnd();
            e = (2 * dx) - dy;
            inc1 = 2 * (dx - dy);
            inc2 = 2 * dx;
            for (int i = 0; i < dy; i++) {
                if (e >= 0)
                {
                    x += incx;
                    e += inc1;
                }
                else
                    e += inc2;
                y += incy;
                glBegin(GL_POINTS);
                glColor3f(c1,0.7,c2);
                glVertex2i(x,y);
                glEnd();
            }
        }
        glFlush();
        c1=c1+0.1;
        c2=c2+0.15;
    }

    void BresenhamDisplay()
    {
        float x,y,c;
        float d = 3 - 2*r;
        x = 0;
        y = r;
        do
        {
            drawPixelSymmetry(x,y);
            glColor3f(1.0,c,0.5);
            if(d < 0)
            {
                d += 4*x + 6;
                x += 1;
            }
            else
            {
                d += 4*(x-y) + 10;
                x += 1;
                y -= 1;
            }
        }while(x <= y);
        glFlush();
        c+=1;
    }

};
class pattern
{
public:
    float x1,y1,r1;
    basic b;
    void pattern_1()
    {
        b.xc=x1;
        b.yc=y1;
        b.r=r1;
        b.BresenhamDisplay();
        b.r=2*r1;
        b.BresenhamDisplay();
        int t=r1*sqrt(3);
        b.ax1=x1-t;
        b.ax2=x1+t;
        b.ay1=y1-r1;
        b.ay2=y1-r1;
        b.modifiedbresenham();
        b.ax2=x1;
        b.ay2=2*r1+y1;
        b.modifiedbresenham();
        b.ax1=x1+t;
        b.ay1=y1-r1;
        b.modifiedbresenham();
    }
    void pattern_2()
    {
        b.xc=x1;
        b.yc=y1;
        b.r=r1;
        b.BresenhamDisplay();
        int t=r1*sqrt(2);
        b.ax1=x1-t;
        b.ax2=x1;
        b.ay1=y1;
        b.ay2=y1+t;
        b.modifiedbresenham();
        b.ax1=x1+t;
        b.modifiedbresenham();
        b.ay2=y1-t;
        b.modifiedbresenham();
        b.ax1=x1-t;
        b.modifiedbresenham();
        b.ax1=x1-t;
        b.ax2=x1+t;
        b.ay1=y1+t;
        b.ay2=y1+t;
        b.modifiedbresenham();
        b.ax1=x1+t;
        b.ay1=y1-t;
        b.modifiedbresenham();
        b.ax2=x1-t;
        b.ay2=y1-t;
        b.modifiedbresenham();
        b.ax1=x1-t;
        b.ay1=y1+t;
        b.modifiedbresenham();
    }
    void pattern_3(){
        int t=r1/2;
        b.ax1=x1-t;
        b.ax2=x1+t;
        b.ay1=y1+t;
        b.ay2=y1+t;
        b.modifiedbresenham();
        b.ax1=x1+t;
        b.ay1=y1-t;
        b.modifiedbresenham();
        b.ax2=x1-t;
        b.ay2=y1-t;
        b.modifiedbresenham();
        b.ax1=x1-t;
        b.ay1=y1+t;
        b.modifiedbresenham();
        b.ax1=(x1-2*t);
        b.ax2=x1;
        b.ay1=y1;
        b.ay2=(y1+2*t);
        b.modifiedbresenham();
        b.ax1=(x1+2*t);
        b.modifiedbresenham();
        b.ay2=(y1-2*t);
        b.modifiedbresenham();
        b.ax1=(x1-2*t);
        b.modifiedbresenham();
        t*=2;
        b.ax1=x1-t;
        b.ax2=x1+t;
        b.ay1=y1+t;
        b.ay2=y1+t;
        b.modifiedbresenham();
        b.ax1=x1+t;
        b.ay1=y1-t;
        b.modifiedbresenham();
        b.ax2=x1-t;
        b.ay2=y1-t;
        b.modifiedbresenham();
        b.ax1=x1-t;
        b.ay1=y1+t;
        b.modifiedbresenham();
    }
};
pattern p;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

void display(void)
 {
    if(choice==1){
    glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        p.pattern_1();
        glPopMatrix();
    }
    else if(choice==2){
    glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        p.pattern_2();
        glPopMatrix();
    }
    else if(choice==3){
    glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        p.pattern_3();
        glPopMatrix();
    }
    glFlush();
}
void keyboard_event(unsigned char key, int x, int y)
{
    if(key == 27)
        exit(0);
    else if(key == 13)
    {glClearColor(1,1,1, 1.0);
     glutPostRedisplay();}

    else
    cout<<"\n You have pressed: \n"<<key;
}

int main(int argc,char **argv)
{
    cout<<"<-------WELCOME------>\n";
    cout<<"Different Patterns:\n1.>Pattern A \n2.>Pattern B \n3.>Pattern C \n";
    cout<<"Please Enter the choice :";
    cin>>choice;
    if (choice==1 || choice==2){
    cout<<"Enter center coordinates of the inner circle : ";
    cin>>p.x1>>p.y1;
    cout<<"Enter radius of circle : ";
    cin>>p.r1;}
    else{
    cout<<"Enter coordinates of the diagonal intersection of inner square : ";
    cin>>p.x1>>p.y1;
    cout<<"Enter side of square : ";
    cin>>p.r1;}


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    window = glutCreateWindow("Pattern drawing");
    init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard_event);
	glutMainLoop();
}

