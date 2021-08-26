#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

static int menuId;

int i = 0;

bool complete = false;

float m[40][3], nm[40][2], mult[3] = {0};

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(3.0);
    gluOrtho2D(-300, 300, -300, 300);
}

void multiply(float a[3][3], int j)
{
    mult[0] = a[0][0]*m[j][0] + a[0][1]*m[j][1] + a[0][2]*m[j][2];
    mult[1] = a[1][0]*m[j][0] + a[1][1]*m[j][1] + a[1][2]*m[j][2];
    mult[2] = a[2][0]*m[j][0] + a[2][1]*m[j][1] + a[2][2]*m[j][2];
}

void setNewMatrix(float a[3][3])
{
    for(int j = 0; j < i; j++)
    {
        multiply(a, j);

        nm[j][0] = mult[0];
        nm[j][1] = mult[1];
    }
}

void display2DTransformation()
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
        for(int j = 0; j < i; j++)
        {
            glVertex2i(nm[j][0], nm[j][1]);
        }
    glEnd();

    glBegin(GL_LINE_LOOP);
        for(int j = 0; j < i; j++)
        {
            glVertex2i(nm[j][0], nm[j][1]);
        }
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27)
    {
        cout<<"\n\tYou have pressed : Escape"<<endl;
        cout<<"\tClosing Output Window"<<endl;
        exit(0);
    }
    else
    {
        cout<<"\n\tYou have pressed : "<<key<<endl;
        cout<<"\tEnter Escape to exit"<<endl;
    }
}

void display()
{
    glColor3f(1.0, 0.0, 0.0);
    if(!complete && i != 0)
    {
        glBegin(GL_POINTS);
            glVertex2i(m[i-1][0], m[i-1][1]);
        glEnd();

        if(i > 1)
        {
            glBegin(GL_LINES);
                glVertex2i(m[i-2][0], m[i-2][1]);
                glVertex2i(m[i-1][0], m[i-1][1]);
            glEnd();
        }
    }

    if(complete)
    {
        glBegin(GL_LINES);
            glVertex2i(m[i-1][0], m[i-1][1]);
            glVertex2i(m[0][0], m[0][1]);
        glEnd();
    }

    glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        m[i][0] = x-300;
        m[i][1] = 300-y;
        m[i++][2] = 1;
        glutPostRedisplay();
    }

    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        complete = true;
        glutPostRedisplay();
    }
}

class transformation
{
    float homogenousMatrix[3][3];

    public:

    transformation()
    {
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                if(j == k)
                    homogenousMatrix[j][k] = 1;
                else
                    homogenousMatrix[j][k] = 0;
    }

    void translation(int tx, int ty)
    {
        homogenousMatrix[0][2] = tx;
        homogenousMatrix[1][2] = ty;

        setNewMatrix(homogenousMatrix);

        display2DTransformation();

        cout<<"\n\tTranslation Done"<<endl;
    }

    void scaling(float sx, float sy)
    {
        homogenousMatrix[0][0] = sx;
        homogenousMatrix[1][1] = sy;

        setNewMatrix(homogenousMatrix);

        display2DTransformation();

        cout<<"\n\tScaling Done"<<endl;
    }

    void shearing(float shx, float shy)
    {
        homogenousMatrix[1][0] = shy;
        homogenousMatrix[0][1] = shx;

        setNewMatrix(homogenousMatrix);

        display2DTransformation();

        cout<<"\n\tShearing Done"<<endl;
    }

    void rotation(int choice, float angle)
    {
        if(choice == 1)
        {
            homogenousMatrix[0][0] = cos(angle);
            homogenousMatrix[0][1] = -sin(angle);
            homogenousMatrix[1][0] = sin(angle);
            homogenousMatrix[1][1] = cos(angle);
        }

        else if(choice == 2)
        {
            homogenousMatrix[0][0] = cos(angle);
            homogenousMatrix[0][1] = sin(angle);
            homogenousMatrix[1][0] = -sin(angle);
            homogenousMatrix[1][1] = cos(angle);
        }

        setNewMatrix(homogenousMatrix);

        display2DTransformation();

        cout<<"\n\tRotation Done"<<endl;
    }

    void reflection(int choice)
    {
        if(choice == 1)
        {
            homogenousMatrix[1][1] = -1;

            setNewMatrix(homogenousMatrix);

            display2DTransformation();

            cout<<"\n\tReflection Done"<<endl;
        }

        else if(choice == 2)
        {
            homogenousMatrix[0][0] = -1;

            setNewMatrix(homogenousMatrix);

            display2DTransformation();

            cout<<"\n\tReflection Done"<<endl;
        }

        else
        {
            cout<<"\n\n\tWrong Choice!!!";
        }
    }
};

transformation t;

void menu(int val)
{
    if(val == 1)
    {
        int tx, ty;

        cout<<"\n\t\t\tTRANSLATION";
        cout<<"\n\n\tEnter Translation factor";
        cout<<"\n\n\tEnter tx : ";
        cin>>tx;
        cout<<"\tEnter ty : ";
        cin>>ty;

        t.translation(tx, ty);
    }

    else if(val == 2)
    {
        float sx, sy;

        cout<<"\n\t\t\tSCALING";
        cout<<"\n\n\tEnter Scaling factor";
        cout<<"\n\n\tEnter sx : ";
        cin>>sx;
        cout<<"\tEnter sy : ";
        cin>>sy;

        t.scaling(sx, sy);
    }

    else if(val == 3)
    {
        float shx, shy;

        cout<<"\n\t\t\tSHEARING";
		cout<<"\n\n\tEnter Shearing factor";
        cout<<"\n\n\tEnter shx : ";
        cin>>shx;
        cout<<"\tEnter shy : ";
        cin>>shy;

		t.shearing(shx, shy);
    }

    else if(val == 4)
    {
        int angle, choice;
        float a;

        cout<<"\n\t\t\tROTATION";
		cout<<"\n\n\t1) Clockwise";
		cout<<"\n\t2) Anti-Clockwise";
		cout<<"\n\n\tEnter your Choice : ";
		cin>>choice;

		cout<<"\n\tEnter angle of Rotation : ";
		cin>>angle;

		a = (3.14*angle)/180;

        t.rotation(choice, a);
    }

    else if(val == 5)
    {
        int choice;

        cout<<"\n\t\t\tREFELCTION";
		cout<<"\n\n\t1) Reflection about x-axis";
		cout<<"\n\t2) Reflection about y-axis";
		cout<<"\n\n\tEnter your choice (1-2) : ";
		cin>>choice;

		t.reflection(choice);
    }

    else if(val == 6)
    {
        i = 0;
        complete = false;
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

    else if(val == 7)
    {
        exit(0);
    }
}

void createMenu()
{
    menuId = glutCreateMenu(menu);
        glutAddMenuEntry("TRANSLATION", 1);
        glutAddMenuEntry("SCALING", 2);
        glutAddMenuEntry("SHEARING", 3);
        glutAddMenuEntry("ROTATION", 4);
        glutAddMenuEntry("REFLECTION", 5);
        glutAddMenuEntry("CLEAR", 6);
        glutAddMenuEntry("EXIT", 7);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

void def()
{
    cout<<"\n\t\t\t\tMOUSE EVENTS"<<endl;
    cout<<"\n\tLeft Button : Providing Vertices of Polygon"<<endl;
    cout<<"\tRight Button : Closing the Polygon"<<endl;
    cout<<"\tMiddle Button : Transformation Menu"<<endl;

    cout<<"\n\t\t\t\tMENU EVENTS";
    cout<<"\n\n\t1) Translation";
    cout<<"\n\t2) Scaling";
    cout<<"\n\t3) Shearing";
    cout<<"\n\t4) Rotation";
    cout<<"\n\t5) Reflection";
    cout<<"\n\t6) Clear";
    cout<<"\n\t7) Exit";
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutCreateWindow("2D Transformations");
    glutPositionWindow(200, 200);
    glutReshapeWindow(600, 600);
    def();
    init();
    createMenu();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
