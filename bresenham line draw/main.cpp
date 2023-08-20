#include <stdio.h>

#include <GL/gl.h>

#include <GL/glut.h>

float x1,y1,x2,y2,m,i,j,p,x,y;

int dx=0,dy=0;

void display(void)

{


    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);//Line color
    glBegin(GL_LINES);//FOR X AXIS
    glVertex2f(-100.0,0.0);
    glVertex2f(400.0,0.0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);//FOR Y AXIS
    glVertex2f(0.0,400.0);
    glVertex2f(0.0,-100.0);
    glEnd();

    glColor3f (0.0, 0.0, 0.0);//Line color
    glBegin(GL_POINTS);
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    p=(2*dy)-dx;
    while(x<=x2)
    {
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        printf("%f %f\n",x,y);
        x++;
        if(p<0)
        {
            p=p+2*dy;
        }
        else
        {
            p=p+2*dy-2*dx;
            y++;
        }

    }

    glFlush ();

}

void init (void)

{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-100,400,-100,400);


}


int main(int argc, char** argv)

{

    printf("Value of x1 : ");
    scanf("%f", & x1);
    printf("Value of y1 : ");
    scanf("%f", & y1);
    printf("Value of x2 : ");
    scanf("%f", & x2);
    printf("Value of y2 : ");
    scanf("%f", & y2);

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_RGB);

    glutInitWindowSize (500, 500);

    glutInitWindowPosition (100, 100);

    glutCreateWindow ("Bresenham Line Draw Algorithm");
    init ();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
