#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
float r,x,y,d;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(-100.0,0.0);
    glVertex2f(400.0,0.0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0,400.0);
    glVertex2f(0.0,-100.0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    x=0;
    y=r;
    d=3-2*r;
    while(x<=y)
    {
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glVertex2f(y,x);
        glVertex2f(-y,x);
        glVertex2f(-x,y);
        glVertex2f(-x,-y);
        glVertex2f(-y,-x);
        glVertex2f(y,-x);
        glVertex2f(x,-y);
        glEnd();
        //printf("%f %f %f\n",x,y,d);
        x++;
        if(d<0)
        {
            d=d+4*x+6;
        }
        else{
            y--;
            d=d+4*x-4*y+10;

        }

    }

    glFlush();


}
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,400,-100,400);

}
int main(int argc,char** argv)
{
    printf("Enter radius : ");
    scanf("%f",&r);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham Circle Draw");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
