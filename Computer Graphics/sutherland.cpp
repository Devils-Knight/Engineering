#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

static int menuId;

int i = 0, j = 0, val;

int xmax, xmin, ymax, ymin;

int TOP=8, BOTTOM=4, RIGHT=2, LEFT=1, MIDDLE=0;

bool colorComplete = false;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

class linePoints
{
    public:

    int x, y;

    setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

linePoints l[50], l1[50];

class ClippingWindow
{
    public :

    int x, y;

    setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

ClippingWindow c[2];

void modifiedBresenham(int ax1, int ay1, int ax2, int ay2)
{
    glPointSize(1.0);
    int dx, dy, e, inc1, inc2, x,y;
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

    if (dx > dy)
    {
        glBegin(GL_POINTS);
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
            glVertex2i(x,y);
            glEnd();
        }
    }
    else
    {
        glBegin(GL_POINTS);
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
            glVertex2i(x,y);
            glEnd();
        }
    }
    glFlush();
}

void display()
{
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2i(l[i-1].x, l[i-1].y);
    glEnd();

    if(i >= 2 && i%2 == 0)
    {
        modifiedBresenham(l[i-2].x, l[i-2].y, l[i-1].x, l[i-1].y);
    }

    glFlush();
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

void colorFill()
{
    glColor3f(1.0, 0.0, 0.0);
    glRecti(350, 450, 400, 425);
    glColor3f(0.0, 1.0, 0.0);
    glRecti(400, 450, 450, 425);
    glColor3f(0.0, 0.0, 1.0);
    glRecti(350, 425, 400, 400);
    glColor3f(1.0, 1.0, 0.0);
    glRecti(400, 425, 450, 400);
    glColor3f(0.0, 1.0, 1.0);
    glRecti(350, 400, 400, 375);
    glColor3f(1.0, 0.0, 1.0);
    glRecti(400, 400, 450, 375);
    colorComplete = true;
}

void mouse(int btn, int state, int x, int y)
{
    if(!colorComplete)
    {
        colorFill();
    }

    if(x >= 350 && x <= 400)
    {
        if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(y >= 50 && y <= 75)
                glColor3f(1.0, 0.0, 0.0);
            else if(y >= 75 && y <= 100)
                glColor3f(0.0, 0.0, 1.0);
            else if(y >= 100 && y <= 125)
                glColor3f(0.0, 1.0, 1.0);
        }

    }
    else if(x >= 400 && x <= 450)
    {
        if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(y >= 50 && y <= 75)
                glColor3f(0.0, 1.0, 0.0);
            else if(y >= 75 && y <= 100)
                glColor3f(1.0, 1.0, 0.0);
            else if(y >= 100 && y <= 125)
                glColor3f(1.0, 0.0, 1.0);
        }
    }

    if(x >= 0 && x <= 345)
    {
        if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            l[i++].setPoint(x, 500 - y);
            glutPostRedisplay();
        }

        if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            if(j >= 0 && j <= 1)
            {
                c[j++].setPoint(x, 500 - y);
                glBegin(GL_POINTS);
                    glVertex2f(c[j-1].x, c[j-1].y);
                glEnd();
                glFlush();
            }
            if(j == 2)
            {
                //Setting xmax, xmin, ymax, ymin of Clipping Window
                if(c[0].x > c[1].x)
                {
                    xmax = c[0].x;
                    xmin = c[1].x;
                }
                else
                {
                    xmax = c[1].x;
                    xmin = c[0].x;
                }

                if(c[0].y > c[1].y)
                {
                    ymax = c[0].y;
                    ymin = c[1].y;
                }
                else
                {
                    ymax = c[1].y;
                    ymin = c[0].y;
                }

                glBegin(GL_POINTS);
                    glVertex2f(c[0].x, c[1].y);
                    glVertex2f(c[1].x, c[0].y);
                glEnd();

                glBegin(GL_LINE_LOOP);
                    glVertex2f(c[0].x, c[0].y);
                    glVertex2f(c[0].x, c[1].y);
                    glVertex2f(c[1].x, c[1].y);
                    glVertex2f(c[1].x, c[0].y);
                glEnd();

                j = 3; //j = 3 means clipping window is drawn successfully
                glFlush();
            }
        }

    }
}

int regionCode(int x, int y)
{
    int c1 = MIDDLE;

    if(x >= xmax) c1 = RIGHT;
    else if(x < xmin) c1 = LEFT;

    if(y >= ymax) c1 |= TOP;
    else if(y < ymin) c1 |= BOTTOM;

    return c1;
}

void menu(int val)
{
    if(val == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
            glVertex2f(c[0].x, c[0].y);
            glVertex2f(c[0].x, c[1].y);
            glVertex2f(c[1].x, c[1].y);
            glVertex2f(c[1].x, c[0].y);
        glEnd();
        int code1, code2;
        int z = 0;  //Loop variable
        int w = 0;  //Pointer to lines in Clipping Window
        while(z < i)
        {
            code1 = regionCode(l[z].x, l[z].y);
            code2 = regionCode(l[z+1].x, l[z+1].y);

            if((code1|code2) == 0)
            {
                l1[w].x = l[z].x;
                l1[w].y = l[z].y;
                l1[w+1].x = l[z+1].x;
                l1[w+1].y = l[z+1].y;
                w += 2;
            }

            else if((code1&code2) == 0)
            {
                int code3 = MIDDLE;

                if((code3|code1) == 0)
                {
                    l1[w].x = l[z].x;
                    l1[w].y = l[z].y;
                    w++;
                }
                else
                {
                    if((code1&4) > 0)
                    {
                        l1[w].y = ymin;
                        l1[w].x = l[z].x + 1.0/(l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(ymin-l[z].y);
                        w++;
                    }

                    else if((code1&8) > 0)
                    {
                        l1[w].y = ymax;
                        l1[w].x = l[z].x + 1.0/(l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(ymax-l[z].y);
                        w++;
                    }

                    else if((code1&1) > 0)
                    {
                        l1[w].x = xmin;
                        l1[w].y = l[z].y + (l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(xmin-l[z].x);
                        w++;
                    }

                    else if((code1&2) > 0)
                    {
                        l1[w].x = xmax;
                        l1[w].y = l[z].y + (l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(xmax-l[z].x);
                        w++;
                    }
                }

                if((code3|code2) == 0)
                {
                    l1[w].x = l[z+1].x;
                    l1[w].y = l[z+1].y;
                    w++;
                }
                else
                {
                    float m=(l[z+1].y-l[z].y)/(l[z+1].x-l[z].x);

                    if((code2&4) > 0)
                    {
                        l1[w].y = ymin;
                        l1[w].x = l[z+1].x + 1.0/(l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(ymin-l[z+1].y);
                        w++;
                    }

                    else if((code2&8) > 0)
                    {
                        l1[w].y = ymax;
                        l1[w].x = l[z+1].x + 1.0/(l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(ymax-l[z+1].y);
                        w++;
                    }

                    else if((code2&1) > 0)
                    {
                        l1[w].x = xmin;
                        l1[w].y = l[z+1].y + (l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(xmin-l[z+1].x);
                        w++;
                    }

                    else if((code2&2) > 0)
                    {
                        l1[w].x = xmax;
                        l1[w].y = l[z+1].y + (l[z+1].y-l[z].y)/(l[z+1].x-l[z].x)*(xmax-l[z+1].x);
                        w++;
                    }
                }
            }

            z += 2;
        }

        i = 2;

        while(i <= w)
        {
            if(i >= 2 && i%2 == 0)
            {
                glBegin(GL_POINTS);
                    glVertex2i(l1[i-2].x, l1[i-2].y);
                    glVertex2i(l1[i-1].x, l1[i-1].y);
                glEnd();
                modifiedBresenham(l1[i-2].x, l1[i-2].y, l1[i-1].x, l1[i-1].y);
            }
            i += 2;
        }
        glFlush();
    }

    else if(val == 2)
    {
        i = 0;
        j = 0;
        colorComplete = false;
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5.0);
        glFlush();
    }
}

void createMenu()
{
    menuId = glutCreateMenu(menu);
        glutAddMenuEntry("CLIP", 1);
        glutAddMenuEntry("CLEAR", 2);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

void def()
{
    cout<<"\n\t\t\tMOUSE EVENTS"<<endl;
    cout<<"\n\tRight Button : Provide Diagonal Points of Clipping Window";
    cout<<"\n\tLeft Button : Draw line";
    cout<<"\n\n\t\t\tMENU EVENTS"<<endl;
    cout<<"\n\tMiddle Button : 1) Clipping Window";
    cout<<"\n\tMiddle Button : 2) Clearing the Screen";
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutCreateWindow("Line Clipping");
    glutPositionWindow(200, 200);
    glutReshapeWindow(500, 500);
    def();
    init();
    createMenu();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
