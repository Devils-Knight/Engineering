#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

class circleALgo
{

    public:

    float xc, yc, r;

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

    void drawPixel(int x, int y)
    {
        glPointSize(4.0);
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_POINTS);
            glVertex2f(xc+x, yc+y);
        glEnd();
    }

    void DDAdisplay()
    {
        float x1, y1, x2, y2, startx, starty;
        x1 = r;
        y1 = 0;
        startx = x1;
        starty = y1;
        int val, i = 0;
        do
        {
            val = pow(2,i);
            i++;
        }while(val<r);
        float e = 1 / pow(2, i-1);
        do
        {
            x2 = x1 + y1*e;
            y2 = y1 - x2*e;
            drawPixel(x2, y2);
            x1 = x2;
            y1 = y2;
        }while((startx-x1)>e || (y1-starty)<e);
        glFlush();
    }

    void BresenhamDisplay()
    {
        float x,y;
        float d = 3 - 2*r;
        x = 0;
        y = r;
        do
        {
            drawPixelSymmetry(x,y);
            glColor3f(1.0,0.0,0.0);
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
    }

    void MidPointDisplay()
    {
        float x,y;
        float d = 5/4 - r;
        x = 0;
        y = r;
        do
        {
            drawPixelSymmetry(x,y);
            glColor3f(0.0,1.0,0.0);
            if(d < 0)
            {
                d += 2*x + 1;
                x += 1;
            }
            else
            {
                d += 2*(x-y) + 1;
                x += 1;
                y -= 1;
            }
        }while(x <= y);
        glFlush();
    }

};

circleALgo c;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27)
    {
        exit(0);
    }

    else if(key == 'd' || key == 'D')
    {
        value = 2;
    }

    else if(key == 'b' || key == 'B')
    {
        value= 3;
    }

    else if(key == 'm' || key =='M')
    {
        value = 4;
    }

    else
    {
        cout<<"You have entered : "<<key<<endl;
    }

    glutPostRedisplay();
}

void menu(int num)
{
    if(num == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
    }

    else if(num == 5)
    {
        glutDestroyWindow(window);
        exit(0);
    }

    else
    {
        value = num;
    }

    glutPostRedisplay();
}

void createmenu(void)
{
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("DDA Circle", 2);
    glutAddMenuEntry("Bresenham Circle", 3);
    glutAddMenuEntry("Mid-Point Circle", 4);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Create", submenu_id);
    glutAddMenuEntry("Exit",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void)
 {
    glClear(GL_COLOR_BUFFER_BIT);

    if(value == 2)
    {
        glPushMatrix();
        c.DDAdisplay();
        glPopMatrix();
    }

    else if(value == 3)
    {
        glPushMatrix();
        c.BresenhamDisplay();
        glPopMatrix();
    }

    else if(value == 4)
    {
        glPushMatrix();
        c.MidPointDisplay();
        glPopMatrix();
    }

    glFlush();
}

int main(int argc,char **argv)
{
    cout<<"<-------WELCOME------>\n";
    cout<<"circle generation by:\n 1.>DDA CIRCLE (please enter key =d)\n2.>Bresenham Circle (please enter key =b)\n3.>Mid-Point Circle (please enter key =m)\n";
    cout<<"Enter coordinates of center : ";
    cin>>c.xc>>c.yc;
    cout<<"Enter Radius : ";
    cin>>c.r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    window = glutCreateWindow("Circle Drawing Algorithms");
    init();
	createmenu();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
