//OpenGL32.lib Glu32.lib Glaux.lib

#include <GL/GLAUX.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
#define PI acos(-1.0)
using namespace std;
float angle=0.0,deltaAngle = 0.0,ratio;
float x=230.0f,y=6.4f,z=0.0f;
float lx=-18.0f,ly=0.0f,lz=0.0f;
float deltaMove = 0,h,w;
int font=(int)GLUT_BITMAP_8_BY_13;
static GLint snowman_display_list;
int bitmapHeight=13,state=0,state2=0,count=0,statew=0,state3=0,fix=0,raf=1,aa=0,sum=0;
float j=-20.0f,k=-10.0f,q=20.0f,l=10.0f;
GLfloat	l_t=0,u_p=0;
GLfloat ra=0;
int flag=0;

GLuint texture[22];

void LoadGLTextures()
{
	AUX_RGBImageRec* TextureImage;

	glGenTextures(22,texture);


	if (TextureImage = auxDIBImageLoad("1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("2.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("3.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

if (TextureImage = auxDIBImageLoad("4.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


if (TextureImage = auxDIBImageLoad("5.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
if (TextureImage = auxDIBImageLoad("6.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

   if (TextureImage = auxDIBImageLoad("7.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("8.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

    if (TextureImage = auxDIBImageLoad("9.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
if (TextureImage = auxDIBImageLoad("10.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("11.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[11]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("12.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[12]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("13.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[13]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("14.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[14]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
    if (TextureImage = auxDIBImageLoad("15.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[15]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("16.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[16]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("17.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[17]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("18.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


    if (TextureImage = auxDIBImageLoad("19.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[19]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

if (TextureImage = auxDIBImageLoad("20.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[20]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("21.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[21]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("22.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[22]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}












}



void my_keyboard(unsigned char key, int x, int y)
{

switch (key) {


		case 's':
        state=1;
		break;

		case 'w':
		state2=1;
		break;

       case 'd':
        u_p=u_p+3;
        glutPostRedisplay();
        break;

        case 'u':
        u_p=u_p-3;
        glutPostRedisplay();
        break;

        case 'l':
        l_t =l_t-3;
        glutPostRedisplay();
        break;

        case 'r':
        l_t =l_t+3;
        glutPostRedisplay();
        break;

        case 'f':
        flag=1;
        glutPostRedisplay();
        break;


        default:
        break;

	}
}

void changeSize(int w1, int h1)
{
    if(h1 == 0)
        h1 = 1;

    w = w1;
    h = h1;
    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
        gluPerspective(45,ratio,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   gluLookAt(x, y, z,
         x + lx,y + ly,z + lz,
            0.0f,1.0f,0.0f);
}


void bookshelf_front(){

    glBindTexture(GL_TEXTURE_2D, texture[13]);
	glPushMatrix();

	glRotatef(90, 0.0, 90.0, 0.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-20.0f,-12.0f,-76.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(38.0f,-12.0f,-76.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(38.0f,17.0f,-76.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-20.0f,17.0f,-76.0);
    glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-80.0f,8.2f,-57.0f);
    glBindTexture(GL_TEXTURE_2D, texture[16]);

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 8.7f,19.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f, 8.7f,19.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(0.0f, -20.0f, 19.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, -20.0f,19.0f);
	glEnd();
    glPopMatrix();


    glPushMatrix();
	glTranslatef(-80.0f,8.2f,1.0f);
    glBindTexture(GL_TEXTURE_2D, texture[16]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 8.7f,19.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f, 8.7f,19.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(0.0f, -20.0f, 19.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, -20.0f,19.0f);
	glEnd();
    glPopMatrix();

}


void window(){

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    //1
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(25,0,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(12.0f,12.0f,39.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,12.0f,39.5);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,39.5);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(12.0f,0.0f,39.5);
    glEnd();
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(12.0f,12.0f,40.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,12.0f,40.5);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,40.5);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(12.0f,0.0f,40.5);
    glEnd();
	glPopMatrix();


	//2
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-25,0,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(12.0f,12.0f,39.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,12.0f,39.5);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,39.5);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(12.0f,0.0f,39.5);
    glEnd();
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(12.0f,12.0f,40.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,12.0f,40.5);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,40.5);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(12.0f,0.0f,40.5);
    glEnd();
	glPopMatrix();


}

void shelf4(){

    glBindTexture(GL_TEXTURE_2D, texture[5]);
    //1
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0,-2,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(15.0f,15.0f,39);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,15.0f,39);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0f,0.0f,39);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(15.0f,0.0f,39);
    glEnd();

	glPopMatrix();
}




void table_leg()
{
    glBindTexture(GL_TEXTURE_2D, texture[18]);

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-29,-10,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,-49.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.5f,0.0f,-49.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.5f,4.0f,-49.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,4.0f,-49.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-29,-10,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,-48.5);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(.5f,0.0f,-48.5);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(.5f,4.0f,-48.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,4.0f,-48.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-29,-10,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,0.0f,-49.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0f,0.0f,-48.5);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(.5f,0.0f,-48.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.5f,0.0f,-49.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-29,-10,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.5f,0.0f,-49.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.5f,0.0f,-48.5);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(.5f,4.0f,-48.5);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.5f,4.0f,-49.0);
    glEnd();
    glPopMatrix();
}

void table(){

    glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
	glTranslatef(-62,0,30);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-5.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(15.0f,-5.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(15.0f,-5.0f,-8.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-5.0f,-8.0);
    glEnd();

    glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(15.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(15.0f,-6.0f,-8.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-6.0f,-8.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);


    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(15.0f, -6.0f,0.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(15.0f, -5.0f,0.0f);//10
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,-8.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,-8.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(15.0f, -6.0f,-8.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(15.0f, -5.0f,-8.0f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f, -6.0f,-8.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f, -5.0f,-8.0f);//10
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(15.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(15.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(15.0f, -6.0f,-8.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(15.0f, -5.0f,-8.0f);//10
	glEnd();

    glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(15.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(15.0f,-6.0f,-8.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-6.0f,-8.0);
    glEnd();
	glPopMatrix();

	table_leg();

	glPushMatrix();
	glTranslatef(-12,0,0);
	table_leg();
	glTranslatef(0,0,-5);
	table_leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-5);
	table_leg();
	glPopMatrix();



}

void chair(){


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[22]);
	glTranslatef(-62,0,36);//x shamne piche z hori
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-5.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,-5.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(5.0f,-5.0f,-5.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-5.0f,-5.0);
    glEnd();

    glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(5.0f,-6.0f,-5.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-6.0f,-5.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);


    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.0f, -6.0f,0.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, -5.0f,0.0f);//10
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,-5.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,-5.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.0f, -6.0f,-5.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, -5.0f,-5.0f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f, -6.0f,-5.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f, -5.0f,-5.0f);//10
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, -5.0f,0.0f);//00
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.0f, -6.0f,0.0f);//00
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.0f, -6.0f,-5.0f);//10
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, -5.0f,-5.0f);//10
	glEnd();

    glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,-6.0f,0.0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(5.0f,-6.0f,-5.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f,-6.0f,-5.0);
    glEnd();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-10,0,3);
	table_leg();
	glTranslatef(0,0,3.5);
	table_leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12,0,3);
	table_leg();
	glTranslatef(0,0,3.5);
	table_leg();
	glPopMatrix();




}

	void drawSnowMan()
	{

     glPushMatrix();
    //glTranslatef(-150.0f,0.0f,-10.0f);
     glRotatef(270,0,1,0);

	glPushMatrix();

	glTranslatef(-20.0f,8.2f,0.0f);


    //rooftop
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 60.0f, 8.7f,-50.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-60.0f, 8.7f,-50.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-60.0f, 8.7f, 40.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 60.0f, 8.7f, 40.0f);
	glEnd();

    //rooftop extended
    glBindTexture(GL_TEXTURE_2D, texture[18]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 65.0f, 8.8f,-55.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-65.0f, 8.8f,-55.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-65.0f, 8.8f, 45.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 65.0f, 8.8f, 45.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 65.0f, 12.0f,-55.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-65.0f, 12.0f,-55.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-65.0f, 12.0f, 45.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 65.0f, 12.0f, 45.0f);
	glEnd();

	//rooftop small rt
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 65.0f, 8.8f,-55.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-65.0f, 8.8f,-55.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-65.0f, 12.0f,- 55.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 65.0f, 12.0f,-55.0f);
	glEnd();
    //left
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 65.0f, 8.8f,45.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-65.0f, 8.8f,45.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-65.0f, 12.0f, 45.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 65.0f, 12.0f,45.0f);
	glEnd();

    //front
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 65.0f, 8.8f,-55.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 65.0f, 8.8f, 45.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 65.0f,12.0f, 45.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 65.0f,12.0f,-55.0f);
	glEnd();



	//back
	glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -65.0f, 8.8f,-55.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -65.0f, 8.8f, 45.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -65.0f,12.0f, 45.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -65.0f,12.0f,-55.0f);
	glEnd();

    //left wall
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 60.0f, 8.7f,39.5f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-60.0f, 8.7f,39.5f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-60.0f, -20.0f, 39.5f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 60.0f, -20.0f,39.5f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 60.0f, 8.7f,40.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-60.0f, 8.7f,40.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-60.0f, -20.0f, 40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 60.0f, -20.0f,40.0f);
	glEnd();

//right wall
    glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 60.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(10.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(10.0f, -20.0f,- 50.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 60.0f, -20.0f,-50.0f);
	glEnd();

	//in

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 60.0f, 8.7f,-49.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(10.0f, 8.7f,-49.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(10.0f, -20.0f,- 49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 60.0f, -20.0f,-49.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-60.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f, -20.0f,- 50.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -60.0f, -20.0f,-50.0f);
	glEnd();

	//in
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-60.0f, 8.7f,-49.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 8.7f,-49.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f, -20.0f,- 49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -60.0f, -20.0f,-49.0f);
	glEnd();



//front wall

    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 60.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 60.0f, 8.7f, 40.f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 60.0f,-20.0f, 40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 60.0f,-20.0f,-50.0f);
	glEnd();



//back wall
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -60.0f, 8.7f,-50.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -60.0f, 8.7f, 40.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -60.0f,-20.0f, 40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -60.0f,-20.0f,-50.0f);
	glEnd();

//floor
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 60.0f,-20.0f, 40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-60.0f,-20.0f, 40.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-60.0f,-20.0f,-50.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 60.0f,-20.0f,-50.0f);
	glEnd();


//door in
if(flag==0){
    glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 10.0f, 6.7f,-49.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 6.7f,-49.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f, -20.0f,- 49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 10.0f, -20.0f,-49.0f);
	glEnd();

//door out
    glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 10.0f, 6.7f,-51.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 6.7f,-51.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f, -20.0f,- 51.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 10.0f, -20.0f,-51.0f);
	glEnd();

}
	//shelf1
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 55.0f, 8.7f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(20.0f, 8.7f,-46.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(20.0f, -20.0f,- 46.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 55.0f, -20.0f,-46.0f);
	glEnd();


    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 8.7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 40.0f, 8.7f,-46.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 40.0f,-20.0f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f,-20.0f,-49.0f);
	glEnd();

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 20.0f, 8.7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 20.0f, 8.7f,-46.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 20.0f,-20.0f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 20.0f,-20.0f,-49.0f);
	glEnd();



	//shelf2
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -30.0f, 8.7f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-10.0f, 8.7f,-46.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-10.0f, -20.0f,- 46.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -30.0f, -20.0f,-46.0f);
	glEnd();


    glBindTexture(GL_TEXTURE_2D, texture[16]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -30.0f, 8.7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -30.0f, 8.7f,-46.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -30.0f,-20.0f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -30.0f,-20.0f,-49.0f);
	glEnd();

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -10.0f, 8.7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -10.0f, 8.7f,-46.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -10.0f,-20.0f,-46.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -10.0f,-20.0f,-49.0f);
	glEnd();

	//painting

    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-35.0f, .7f,-48.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-45.0f, .7f,-48.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-45.0f, -8.0f,- 48.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-35.0f, -8.0f,-48.0f);
	glEnd();



    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -35.0f, .7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -35.0f, .7f,-48.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -35.0f,-8.0f,-48.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -35.0f,-8.0f,-49.0f);
	glEnd();



    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -45.0f, .7f,-49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -45.0f, .7f,-48.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -45.0f,-8.0f,-48.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -45.0f,-8.0f,-49.0f);
	glEnd();


	//clock
	/*glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f(-38.0f, 7.7f,-49.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f(-42.0f, 7.7f,-49.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f(-42.0f, 2.0f,- 49.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f(-38.0f, 2.0f,-49.0f);
	glEnd();*/


//shelf3





    glBindTexture(GL_TEXTURE_2D, texture[17]);

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 10.0f, 7.7f,40.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -10.0f, 7.7f, 40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -10.0f,-10.0f, 35.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.0f,-10.0f,35.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	//glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -10.0f, 7.7f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -10.0f, 7.7f,40.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -10.0f,-10.0f,35.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -10.0f,-10.0f,40.0f);
	glEnd();

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.0f, 7.7f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 10.0f, 7.7f,40.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 10.0f,-10.0f,35.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 10.0f,-10.0f,40.0f);
	glEnd();




    glPushMatrix();
    glTranslatef(35,-5,0);

//shelf 5
    glBindTexture(GL_TEXTURE_2D, texture[14]);

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 12.0f, 13.9f,35.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -12.0f, 13.9f, 35.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -12.0f,-13.9f, 35.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 12.0f,-13.9f,35.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -12.0f, 13.9f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -12.0f,13.9f,35.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -12.0f,-13.9f,35.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -12.0f,-13.9f,40.0f);
	glEnd();

    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glColor3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 12.0f, 13.9f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 12.0f, 13.9f,35.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 12.0f,-13.9f,35.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 12.0f,-13.9f,40.0f);
	glEnd();

//book case



    glPushMatrix();
    glTranslatef(-60,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 8.0f, 10.0f,37.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -8.0f, 10.0f, 37.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -8.0f,0.0f, 37.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 8.0f,0.0f,37.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[15]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -8.0f, 10.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -8.0f,10.0f,37.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -8.0f,0.0f,37.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -8.0f,0.0f,40.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[15]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 8.0f, 10.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 8.0f, 10.0f,37.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 8.0f,0.0f,37.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 8.0f,0.0f,40.0f);
	glEnd();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(-75,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[19]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f, 8.0f,39.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -3.0f, 8.0f, 39.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -3.0f,1.0f, 39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,1.0f,39.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -3.0f, 8.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -3.0f,8.0f,39.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -3.0f,1.0f,39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -3.0f,1.0f,40.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 8.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 8.0f,39.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f,1.0f,39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,1.0f,40.0f);
	glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-85,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[21]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f, 8.0f,39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -3.0f, 8.0f, 39.0f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -3.0f,1.0f, 39.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f,1.0f,39.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( -3.0f, 8.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( -3.0f,8.0f,39.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( -3.0f,1.0f,39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( -3.0f,1.0f,40.0f);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glBegin(GL_QUADS);
	glTranslatef(0.0f,0.0f,18.3f);
	glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 8.0f,40.0f);
	glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 8.0f,39.0f);
	glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f,1.0f,39.0f);
	glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,1.0f,40.0f);
	glEnd();

    glPopMatrix();


    glPopMatrix();



    glPopMatrix();


    bookshelf_front();
    window();
    shelf4();


    glPushMatrix();
    glTranslatef(6,0,-10);
    table();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,0,-10);

    chair();
    glPopMatrix();

     glPopMatrix();

printf("aaak");

    glPopMatrix();
	glutSwapBuffers() ;

	}

GLuint createDL()
{
    GLuint snowManDL;
    snowManDL = glGenLists(2);
    glNewList(snowManDL+1,GL_COMPILE);
    drawSnowMan();
    glEndList();
    glNewList(snowManDL,GL_COMPILE);
    glPushMatrix();
    glCallList(snowManDL+1);
    glPopMatrix();
    glEndList();
    return(snowManDL);
}

void initScene()
{
	LoadGLTextures();

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

    snowman_display_list = createDL();
}

void orientMe(float ang)
{

    angle += ang;
    lx = sin(angle);
    lz = -cos(angle);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx,y + ly,z + lz,0.0f,1.0f,0.0f);
}

void moveMeFlat(float i)
{
   x= x + i*(lx)*.10;
   if(statew == 1 )
   y= y + i*(ly)*.10;
   z= z + i*(lz)*.10;
    glLoadIdentity();
    gluLookAt(x, y, z,x +lx,y +ly,z + lz,0.0f,1.0f,0.0f);
}

void setOrthographicProjection()
{

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
       gluOrtho2D(0, w, 0, h);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
    glMatrixMode(GL_MODELVIEW);
}


void resetPerspectiveProjection()
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font,char *string)
{
  char *c;

  glRasterPos2f(x, y);

  for (c=string; *c != '\0'; c++)
  {
		glutBitmapCharacter(font, *c);
  }
}


void renderScene(void)
{

    if (deltaMove)
        moveMeFlat(deltaMove);

	if(fix == 1)
	{
	if(raf ==1)
     moveMeFlat(.1);
	if(angle> -7.85 && x <=7)
	{
       raf=0;
        orientMe(-.003);
	}

	if(angle <= -7.85 )
	{
        moveMeFlat(.3);
		if(x<= -84)
		{
          orientMe(-.003);
		}
	}
     if( angle <= -9.48 )
      orientMe(.003);

     if(z>30)
     {
            orientMe(-.003);
     }

      if(angle <= -9.6 &&  x>21 && z>-30)
      {
         orientMe(-.0015);
      if(x>62)
      {
		fix=0;
		state2=1;
	  }
     }
    }

    if (deltaAngle)
	{
      orientMe(deltaAngle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(state == 1)
    {
      x=0.0f,y=250.80f,z=25.0f;
      lx=0.0f,ly=-8.0f,lz=-1.0f;
      state=0;
    }
    if(state2 == 1)
    {
       x=230.0f,y=6.4f,z=0.0f;
       lx=-18.0f,ly=0.0f,lz=0.0f;
       state2 =0;
    }

    if(state3 == 1)
    {
       ly=0.0f;
       state3=0;
    }

   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  	glLoadIdentity();
	gluLookAt(x, y, z,
             x + lx,y + ly,z + lz,
             0.0f,1.0f,0.0f);

      glBindTexture(GL_TEXTURE_2D, texture[10]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f);		glVertex3f(-400.0f, -13.0f, -400.0f);
        glTexCoord2f(0.0f, 1.0f);		glVertex3f(-400.0f, -13.0f,  400.0f);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 400.0f, -13.0f,  400.0f);
        glTexCoord2f(1.0f, 0.0f);		glVertex3f( 400.0f, -13.0f, -400.0f);
    glEnd();
	glPushMatrix();
	glRotatef(l_t,0.0f,1.0f,0.0f);
	glPushMatrix();
	glRotatef(u_p,1.0f,0.0f,0.0f);

    glCallList(snowman_display_list);

	glPopMatrix();
	glPopMatrix();


    glClearColor(0, 0.7, 1, 0.0);
    setOrthographicProjection();
    glPushMatrix();
    glLoadIdentity();
    glPopMatrix();
    resetPerspectiveProjection();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 27)
			exit(0);

}

void pressKey(int key, int x, int y)
{

    switch (key)
	{
        case GLUT_KEY_LEFT : deltaAngle = -0.006f;break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.006f;break;
        case GLUT_KEY_UP : deltaMove = .4;break;
        case GLUT_KEY_DOWN : deltaMove = -.4;break;
    }
}

void releaseKey(int key, int x, int y)
{

    switch (key)
	{
        case GLUT_KEY_LEFT : if (deltaAngle < 0.0f)
                                 deltaAngle = 0.0f;
                             break;
        case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
                                 deltaAngle = 0.0f;
                             break;
        case GLUT_KEY_UP :     if (deltaMove > 0)
                                 deltaMove = 0;
                             break;
        case GLUT_KEY_DOWN : if (deltaMove < 0)
                                 deltaMove = 0;
                             break;
    }
}

void spinDisplay(void)
{
	l_t =l_t+.2;
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
            glutIdleFunc(renderScene);
         break;
      default:
         break;
   }

}


int main(int argc, char **argv)
{
     printf("\nMouse Configuration:");
     printf("\nLeft-right mouse button:Look around");
	 printf("\nKeyboard Configuration:");
     printf("\n\t\tw - Walking View");
     printf("\n\t\ts - Satellite View");
     printf("\n\t\td - Down");
     printf("\n\t\tu - Up");
     printf("\n\t\tl - Left");
     printf("\n\t\tr - Right");
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,600);
    glutCreateWindow("Farha's Library room");
	glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouse);
    glutKeyboardFunc(my_keyboard);
    initScene();
    glutMainLoop();

    return(0);
}
