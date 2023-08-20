#include<stdio.h>
#include<bits/stdc++.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
GLfloat tx,ty,R;
void getData()
{
    cout<<"Enter Fixed Point : ";
    cin>>tx>>ty;
    cout<<endl;
    cout<<"Enter Rotation Angle : ";
    cin>>R;
    cout<<endl;
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.1,0.4);
    glVertex2f(0.7,0.4);
    glVertex2f(0.4,0.8);
    glEnd();
    glLoadIdentity();
    glTranslatef(tx,ty,0);// rotate about fixed point
    glRotatef(R,0,0,1);// rotate about z axis
    glTranslatef(-tx,-ty,0);
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
    glutInitWindowSize(600,600);
    glutCreateWindow("Triangle Rotation");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
