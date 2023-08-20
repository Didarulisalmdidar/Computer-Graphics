#include<stdio.h>
#include<bits/stdc++.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
GLfloat sx,sy;
/// sx=0.5 sy=1.2
void getData()
{
    cout<<"Enter magnification factor x : ";
    cin>>sx;
    cout<<endl;
     cout<<"Enter magnification factor y : ";
    cin>>sy;
    cout<<endl;

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.1,0.4);
    glVertex2f(0.7,0.4);
    glVertex2f(0.4,0.8);
    glEnd();
    glLoadIdentity();
    glScaled(sx,sy,0);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.1,0.4);
    glVertex2f(0.7,0.4);
    glVertex2f(0.4,0.8);
    glEnd();
    glFlush();
}


int main(int argv,char** argc)
{
    getData();
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700,700);
    glutCreateWindow("Triangle magnification");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
