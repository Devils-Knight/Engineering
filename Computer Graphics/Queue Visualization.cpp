#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std ;
int N = 0 ;

int l = 0 , r = 0 , n = 20 ;
int W = 200 , H = 50 ;
vector< string > elements(n) ;


void place(float x, float y, float z, string s) {
  glRasterPos3f(x, y, z);
  for (int i =0 ; i< s.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
  }
}

void choice();

void liner(double x , double y , double px , double py){
    glPointSize(1);
    glBegin(GL_LINE_STRIP);
        glVertex2i(x,y);
        glVertex2i(px,py);
    glEnd();
    glFlush();
}

void show (){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
        int ct = 0 , i = l ;
        while(i!=r)
        {   if(elements[i].size()==0) break;
            int x = 150 , y = ct*H ;
            liner(x,y,x+W,y) ;
            liner(x,y,x,y+H) ;
            liner(x+W,y,x+W,y+H) ;
            liner(x+W,y+H,x,y+H) ;
            place(x+10,y+20,0,elements[i]) ;
            ct ++ ;
            i ++ ; i%=n ;
        }
        glFlush();
        choice();
}

void push(){
    if((r+1)%n==l) { cout << "Queue is full \n" ; return ; }
    cout << "Enter the element : " ;
    string s ; cin >> s ; cout << endl ;
    elements[r] = s ; r++ ;
    show () ;
}
void pop(){
    if(l==r){ cout <<"Queue is empty \n" ; return;}
    cout <<elements[l] <<" is deleted \n" ;
    elements[l] = "" ;
    l ++ ; l%=n ;
    show () ;
}

void choice(){
    cout <<"\nEnter 'p' or 'P' to Push element into the queue \n";
    cout <<"Enter 'D' or 'd' to Pop element from the queue \n";
    cout <<"Enter 'esc' to exit \n";
    cout <<"Enter your choice :  ";
    char k ; cin >> k ; cout << endl ;
    if(k =='p'||k =='P'){
        push() ;
    }
    else if(k =='d'||k =='D'){
        pop() ;
    }
    else exit(0) ;

}

void arb (long long int m){
    long long int  n0 = 1e7 , k = 0 ;  m *= n0 ;
    for(long long int i=0;i<m ; i++ ){
        k++ ; k-- ;
    }
}


void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500, 450,-50) ;
	glFlush() ;
}

void display(){
    glColor3f(0.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if(N==0){
         choice() ;
    }N++;
    glFlush() ;
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
	glutInitWindowPosition(1000,150);
	glutCreateWindow(" Queue Visualization ");
	init();
	glutDisplayFunc(display);
    cout << " Enter 1 to continue : " ;
    int yy ;
    cin >> yy ;
	glutMainLoop();
	return 0;

}
