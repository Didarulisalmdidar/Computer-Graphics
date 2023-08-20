#include<stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

float rx,ry;//semi-Major axis & semi Minor Axis
float xCenter,yCenter;//center of ellipse

/// rx=100 ry=80 xcenter=150 ycenter=70
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glColor3f(0.0,0.0,0.0); // red foreground
    glBegin(GL_LINES);
    glVertex2f(-300.0,0.0);
    glVertex2f(400.0,0.0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0,400.0);
    glVertex2f(0.0,-300.0);
    glEnd();


    float x = 0;
    float y = ry;//(0,ry) ---
    float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
    //slope
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while(dx < dy)
    {
        //plot (x,y)
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POINTS);
        glVertex2d(xCenter + x,  yCenter+y);
        glVertex2d( xCenter - x,   yCenter + y);
        glVertex2d( xCenter + x, yCenter - y );
        glVertex2d( xCenter - x, yCenter - y);
        glEnd();
        if(p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx =  2 * (ry * ry) * x;
            dy =  2 * (rx * rx) * y;
            p1 = p1 + dx - dy +(ry * ry);
        }
    }
    //ploting for 2nd region of 1st quardant and the slope will be > -1
    //----------------------Region-2------------------------//
    float p2 = (ry * ry )* ( x +  0.5) * ( x +  0.5) +  ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);


    while(y > 0)
    {
        //plot (x,y)
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POINTS);
        glVertex2d(xCenter + x,  yCenter+y);
        glVertex2d( xCenter - x,   yCenter + y);
        glVertex2d( xCenter + x, yCenter - y );
        glVertex2d( xCenter - x, yCenter - y);
        glEnd();
        if(p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            //dy = 2 * rx * rx *y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx) ;
            dx = dx + 2 * (ry * ry) ;
            p2 = p2 + dx -
                 dy + (rx * rx);
        }
    }
    glFlush(); // send all output to the display
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-300,400,-300,400);
}

int main(int argc,char** argv)
{

    printf("\n\nEnter Center Of Ellipse  \n\n");
    scanf("%f", & xCenter);
    scanf("%f", & yCenter);
    printf(" Enter a Semi Major Axix : ");
    scanf("%f", & rx);
    printf(" \nEnter a Semi Minor Axis: ");
    scanf("%f", & ry);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500); // set the size of the window
    glutInitWindowPosition(100,100); // the position of the top-left of window
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    init();
    glutDisplayFunc(display); // set the gl display callback function
    glutMainLoop(); // enter the GL event loop
    return 0;

}
