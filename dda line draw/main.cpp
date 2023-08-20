#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);//FOR DISPLAY COLOE CLEAR PREV BIT
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

  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  glColor3f(1.0,0.0,1.0);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void myInit (void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);//Display color
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100,400,-100,400);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("DDA Line Draw ");
  myInit ();
  glutDisplayFunc(display);
  glutMainLoop();
}
