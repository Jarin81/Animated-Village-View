#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>


float boatX = 0;
float boatY = 0;

float sunY = -80;

float cloudX = 0;
float dayNight = 0;
float x=0, y=0;

void introText()
{
    char text[150];

    sprintf(text, "UNIVERSITY OF INFORMATION TECHNOLOGY & SCIENCES",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 50 , 170 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Project Name: Village View",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 50 , 150 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Submitted By :",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 50 , 130 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Jarin Tasnim Khan",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 60 , 120 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "ID - 1914551081",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 60 , 110 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Department of CSE",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 60 , 100 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Submitted To:",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 50 , 80 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Salim Shadman Ankur",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 60 , 70 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Lecturer of CSE Department",5.00,8.00);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f( 60 , 60 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "Press 'd' for Day Mode",5.00,8.00);
    glColor3f(1, 0, 1);
    glRasterPos2f( 80 , 30 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, " Press 'n' for Night Mode",5.00,8.00);
    glColor3f(1, 0, 0);
    glRasterPos2f( 80 , 20 );
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

//Sun, Clouds
void circle(float x, float y, double r)
{
    float x1,y1,pi=3.1416,A;
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        A = (i*2*pi)/25;
        x1 = x+((r-.07)*cos(A));
        y1 = y+(r*sin(A));

        glVertex2f(x1,y1);
    }
    glEnd();
}

void water(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.0f, 0.8f, 0.9f);
    } else {
      glColor3f(0.0f, 0.4f, 0.9f);
    }

	glBegin(GL_QUADS);

	glVertex2i(0,0);
	glVertex2i(0, 70);
	glVertex2i(610, 150);
	glVertex2i(610, 0);

	glEnd();
	glPopMatrix();
}

void sky(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.5f, 1.0f, 1.0f);
    } else {
      glColor3f(0.0f, 0.0f, 0.0f);
    }
	glBegin(GL_QUADS);

	glVertex2i(0, 240);
	glVertex2i(610, 240);
	glVertex2i(610, 400);
	glVertex2i(0, 400);

	glEnd();
	glPopMatrix();
}

void sun(void)
{
    if(dayNight == 0){
        glColor3f(1.0, 0.843, 0.0);
    } else {
        glColor3f(1.0, 1.0, 1.0);
    }
    circle(270,350,40);
}

void moving_sun(void)
{
    if (sunY>=0)
        sunY=0;
    else
        sunY += .01;

    glPushMatrix();
    glTranslatef(0, sunY, 0);
    sun();
    glPopMatrix();
}

void cloud1(void)
{
    if(dayNight == 0){
      glColor3f(0.80,0.80,0.80);
    } else {
      glColor3f(0.5f, 0.5f, 0.5f);
    }

    circle(150,350,35);
    circle(180,365,30);
    circle(200,345,30);
    circle(220,360,35);
}

void cloud2(void)
{
    if(dayNight == 0){
      glColor3f(0.80,0.80,0.80);
    } else {
      glColor3f(0.5f, 0.5f, 0.5f);
    }

    circle(390,350,30);
    circle(340,360,30);
    circle(360,340,30);
    circle(370,360,30);
}

void moving_cloud(void)
{
    cloudX +=0.05;
    if (cloudX>500)
    {
        cloudX = -450;
    }

    glPushMatrix();
    glTranslatef(cloudX, 0, 0);
    cloud1();
    cloud2();
    glPopMatrix();
}

void field(void)
{
    if(dayNight == 0){
      glColor3f(0.8,0.5,0.2);
    } else {
      glColor3f(0.8f, 0.3f, 0.2f);
    }

    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(0,240);
    glVertex2i(610,240);
    glVertex2i(610,130);
    glEnd();
}

void mountain(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.0f, 1.0f, 0.0f);
    } else {
      glColor3f(0.0f, 0.5f, 0.1f);
    }

	glBegin(GL_TRIANGLES);

	glVertex2i(-20, 240);
	glVertex2i(50, 300);
	glVertex2i(130, 240);

	glEnd();
	glPopMatrix();
}

void door(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.1f, 1.0f, 0.5f);
    } else {
      glColor3f(0.1f, 0.5f, 0.5f);
    }

	glBegin(GL_QUADS);

	glVertex2i(115, 125);
	glVertex2i(145, 125);
	glVertex2i(145, 170);
	glVertex2i(115, 170);

	glEnd();
	glPopMatrix();

}

void window_1(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(1.0f, 0.0f, 0.0f);
    } else {
      glColor3f(0.5f, 0.0f, 0.0f);
    }

	glBegin(GL_QUADS);

	glVertex2i(150, 160);
	glVertex2i(175, 160);
	glVertex2i(175, 180);
	glVertex2i(150, 180);

	glEnd();
	glPopMatrix();

}

void window_2(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(1.0f, 0.0f, 0.0f);
    } else {
      glColor3f(0.5f, 0.0f, 0.0f);
    }

	glBegin(GL_QUADS);

	glVertex2i(85, 160);
	glVertex2i(110, 160);
	glVertex2i(110, 180);
	glVertex2i(85, 180);

	glEnd();
	glPopMatrix();

}

void roof(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.2f, 0.4f, 0.5f);
    } else {
      glColor3f(0.2f, 0.1f, 0.5f);
    }

	glBegin(GL_QUADS);

	glVertex2i(70, 195);
	glVertex2i(190, 195);
	glVertex2i(180, 220);
	glVertex2i(80, 220);

	glEnd();
    glPopMatrix();
}

void house(void)
{
glPushMatrix();
    if(dayNight == 0){
      glColor3f(1.0f, 1.0f, 0.0f);
    } else {
      glColor3f(1.0f, 0.8f, 0.0f);
    }

	glBegin(GL_QUADS);

	glVertex2i(80, 125);
	glVertex2i(180, 125);
	glVertex2i(180, 195);
	glVertex2i(80, 195);

	glEnd();

    glPopMatrix();

    roof();
    window_1();
    window_2();
    door();
}

void boat(void)
{
	glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(370,20);
	glVertex2i(480, 20);
	glVertex2i(510, 50);
	glVertex2i(330, 50);
	glEnd();


	glBegin(GL_TRIANGLES);
	if(dayNight == 0){
      glColor3f(0.5f, 0.5f, 0.5f);
    } else {
      glColor3f(0.5f, 0.3f, 0.5f);
    }

	glVertex2i(330,50);
	glVertex2i(420, 50);
	glVertex2i(420, 80);
	glEnd();
}

void moving_boat(void)
{
    boatX +=0.05;
    if (boatX>280)
    {
        boatX = -550;
    }
    glPushMatrix();
    glTranslatef(boatX, 0, 0);
    boat();
    glPopMatrix();
}


void tree_below(void)
{
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	glVertex2i(290, 110);
	glVertex2i(296, 110);
	glVertex2i(296, 130);
	glVertex2i(290, 130);

	glEnd();
	glPopMatrix();

}

void tree(void)
{
    glPushMatrix();
    if(dayNight == 0){
      glColor3f(0.1f, 0.5f, 0.1f);
    } else {
      glColor3f(0.0f, 0.4f, 0.1f);
    }

	glBegin(GL_TRIANGLES);

	glVertex2i(265, 130);
	glVertex2i(321, 130);
	glVertex2i(293, 230);
	glEnd();
	glPopMatrix();

	tree_below();

}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glClearColor(0,0,0,0);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D(0.0, 610.0+x, 0.0, 400.0+y);
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();

sky();
moving_sun();

mountain();
glPushMatrix();
  glTranslatef(120, 0, 1);
  glScalef(1.2, 1, 1);
  mountain();
glPopMatrix();

glPushMatrix();
  glTranslatef(220, -120, 1);
  glScalef(1.5, 1.5, 1);
  mountain();
glPopMatrix();

glPushMatrix();
  glTranslatef(350, -48, 1);
  glScalef(1.2, 1.2, 1);
  mountain();
glPopMatrix();

glPushMatrix();
  glTranslatef(480, -120, 1);
  glScalef(1.3, 1.5, 1);
  mountain();
glPopMatrix();

moving_cloud();
field();

water();

house();


glPushMatrix();
  glTranslatef(-60, -20, 1);
  glScalef(.90, .90, 1);
  house();
glPopMatrix();

glPushMatrix();
  glTranslatef(250, 0, 1);
  glScalef(1.2, 1.2, 1);
  house();
glPopMatrix();


tree();
glPushMatrix();
  glTranslatef(-60, 0, 1);
  tree();
glPopMatrix();

glPushMatrix();
  glTranslatef(225, 50, 1);
  glScalef(1, 1.1, 1);
  tree();
glPopMatrix();

glPushMatrix();
  glTranslatef(285, 50, 1);
  glScalef(1, 1.1, 1);
  tree();
glPopMatrix();

moving_boat();


glFlush();
glutPostRedisplay();
glutSwapBuffers();
}

void Intro()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0,200,0,200);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    introText();
    glEnd();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y)
{
    switch ( key )
    {
    case 'n':
        dayNight = 1;
        glutDisplayFunc(display);
        break;
    case 'd':
        dayNight = 0;
        glutDisplayFunc(display);
        break;
    case 'l':
        x+=1;
        y+=1;
        break;
    case 's':
        x-=1;
        y-=1;
        break;
    case 27:
        exit(1);
    }
    glutPostRedisplay();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1200, 680);

	glutInitWindowPosition(0, 0);
    glutCreateWindow("Village View");

    glutKeyboardFunc(myKeyboardFunc);

    glutDisplayFunc(display);

    glutDisplayFunc(Intro);
    glDepthFunc(GL_LEQUAL);

    glutMainLoop();

    return 0;
}
