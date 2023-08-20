#include<stdio.h>
#include<bits/stdc++.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
GLfloat xmax=0.5,xmin=-0.5,ymax=0.5,ymin=-0.5;
GLfloat x1=-0.7,y1=-0.3,x2=-0.6,y2=0.9;
int clip_flag=0;
int c1,c2,c;
GLfloat x,y;
int Left=1,Right=2,Bottom=4,Top=8;
int get_code(GLfloat x,GLfloat y)
{
    int code=0;
    if(x<xmin)
        code=code | Left;
    if(x>xmax)
        code=code | Right;
    if(y<ymin)
        code=code| Bottom;
    if(y>ymax)
        code=code|Top;
    return code;
}
void clip()
{
    if(c1)
        c=c1;
    else
        c=c2;

    if(c & Left)
    {
        x=xmin;
        y=y1 + (y2 -y1)*((xmin-x1)/(x2-x1));
    }
    if(c & Right)
    {
        x=xmax;
        y=y1 + (y2 -y1)*((xmax-x1)/(x2-x1));
    }
    if(c & Bottom)
    {
        y=ymin;
        x=x1+(x2-x1)*((ymin-y1)/(y2-y1));
    }
    if(c & Top)
    {
        y=ymax;
        x=x1+(x2-x1)*((ymax-y1)/(y2-y1));
    }
    if(c==c1)
    {
        x1=x;
        y1=y;
    }
    else
    {
        x2=x;
        y2=y;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    while(1 & clip_flag==1)
    {
        c1=get_code(x1,y1);
        c2=get_code(x2,y2);
        if((c1|c2)==0) ///completely inside
            break;
        else if((c1&c2)!=0) /// completely outside
            break;
        else
            clip();
    }

    glFlush();
}
void key(unsigned char ch,int x,int y)
{
    clip_flag=1;
    glutPostRedisplay();
}
int main(int argv,char **argc)
{

    // getdata();

    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("KOCH");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();

    return 0;
}
