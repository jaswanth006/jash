#include<GL/glut.h>
#include<math.h>
#include<stdio.h>   //definitions/declarations for standard I/O routines
#include<stdlib.h>   //declarations/definitions for commonly used library functions
#define H_SPIN 0.02
static GLfloat g_spin=H_SPIN;
void helicopter(int xx,int yy);
int start=0;
float xx=100,yy=200;
GLfloat theta=0.0,theta1=0.0,theta2=0.0,theta3=0.0,flag1=0,flag2=0;
void drawstring(float x,float y,float z,char *string)
	{
		 char *c;
		 glRasterPos3f(x,y,z);
		 for(c=string;*c!='\0';c++)
	 {
	  		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
	 }
	}
	void drawstring1(float x,float y,float z,char *string)
	{
		 char *c;
	 	glRasterPos3f(x,y,z);
	 	for(c=string;*c!='\0';c++)
	 	{
	  glutBitmapCharacter(GLUT_BITMAP_8_BY_13,*c);
		 }
	}
	void drawstring2(float x,float y,float z,char *string)
	{
		 char *c;
	 	glRasterPos3f(x,y,z);
	 	for(c=string;*c!='\0';c++)
	 	 {
	  		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*c);
		 }
	}


	void frontscreen()
	{
			 glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.0,0.0,0.0);
	 		drawstring(400,900,0.0,"CGV");
	 		drawstring(470,900,0.0,"MINI");
	 		drawstring(550,900,0.0,"PROJECT");
	 	glColor3f(0.0,0.0,0.0);
	 		drawstring(460,850,0.0,"DEMONSTRATION OF HELICOPTER");
	 		//drawstring(270,410,0.0,"");
	 		//drawstring(350,410,0.0,"BOOTH]");
	 	glColor3f(0.0,0.0,0.0);
	 		drawstring1(300,700,0.0,"Submitted");
	 		drawstring1(390,700,0.0,"by:STEP UP");
	 	glColor3f(0.0,0.0,0.0);
	 		drawstring1(300,620,0.0,"Students Name                 USN");
	 	glColor3f(1.0,0.0,0.0);
	 		drawstring2(300,580,0.0,"Name            USN");
	 		drawstring2(300,540,0.0,"Name             USN");
	 	glColor3f(0.0,0.0,0.0);
	 		drawstring1(270,480,0.0,"Under the Guidance of");
	 	glColor3f(1.0,0.0,0.0);
	 		drawstring2(280,440,0.0,"Prof: ");
	 	glColor3f(0.0,0.0,0.0);
	 		drawstring1(400,270,0.0,"Year 2020-21");
		glColor3f(0.0,0.0,0.0);
	 		drawstring1(200,230,0.0,"For instructions press: n");

		glFlush();
glutSwapBuffers();
	}


	void instruction()
{

	 glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.0,0.0,0.0);
	 		drawstring(460,850,0.0,"Instructions");


	 	glColor3f(1.0,0.0,0.0);
	 		drawstring2(300,700,0.0,"s: Start");
	 		drawstring2(300,650,0.0,"m: move");
	 		drawstring2(300,600,0.0,"h: Speed increase");
			drawstring2(300,550,0.0,"l: speed decrease");
			drawstring2(300,500,0.0,"r: move right");
			drawstring2(300,450,0.0,"b: move left");
			drawstring2(300,400,0.0,"u: move up");
			drawstring2(300,350,0.0,"d: move down");
			drawstring2(300,300,0.0,"q: quit");
			drawstring2(300,250,0.0,"for next press: c");
	glFlush();
	//glutSwapBuffers();

}

void  mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,1.0,1.0,1.0);
	if(flag1==0)
	{
		frontscreen();
	}
	else
	{

	if(flag2==0)

		instruction();

	else
	{
	if(!start)
	{

		glColor3f(1.0,1.0,1.0);
		helicopter(xx,yy);

		glRasterPos2f(200, 200);


		glutIdleFunc(NULL);
	}

	else
	{


		glColor3f(1.0,1.0,1.0);
		helicopter(xx,yy);
		glutSwapBuffers();
	}
	glFlush();

	}
	}
	glutSwapBuffers();
    }


void limit()
{

		if(theta<100)
		  theta+=50.0;
		else theta=0;

		if(theta1<100)
		 theta1+=50.0;
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;

		glutPostRedisplay();
}

void helicopter(int x,int y)

{
     GLfloat i,cosine,sine;
	GLint r=35,m=20;

	glColor3f(1.,1.,1.);
	glBegin(GL_POLYGON);
	glVertex2f(x,y+5);
	glVertex2f(x+75,y+20);
	glVertex2f(x+75,y-20);
	glVertex2f(x,y-5);
	glEnd();

	//head
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		cosine=(x+100)+(r*cos(i));
        	sine=y+(r*sin(i));
		glVertex2f(cosine,sine);
	}
	glEnd();

	//black line (seperator)
	glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
	glVertex2f(x+75,y-20);
	glVertex2f(x+75,y+20);
	glEnd();

	//door
	glColor3f(.3,.5,.8);
	glBegin(GL_POLYGON);
	glVertex2f(x+85,y-20);
	glVertex2f(x+85,y+5);
	glVertex2f(x+97,y+5);
	glVertex2f(x+97,y-20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+105,y-20);
	glVertex2f(x+105,y);
	glVertex2f(x+115,y);
	glVertex2f(x+115,y-20);
	glEnd();

	//wing big
	glColor3f(.3,.5,.8);
	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//1
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+80,y+100);
	glVertex2i(x+100,y+100);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta1,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//2
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+80,y-20);
	glVertex2i(x+100,y-20);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta2,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//3
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+30,y-10);
	glVertex2i(x+30,y+10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta3,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//4
        glBegin(GL_POLYGON);
    	glVertex2i(x+160,y+50);
	glVertex2i(x+90,y+30);
	glVertex2i(x+160,y+70);
	glEnd();
	glPopMatrix();

	//wing small
	glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//a
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x,y+30);
	glVertex2i(x-10,y+30);
	glEnd();
	glPopMatrix();

        glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta1,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//b
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x,y-10);
	glVertex2i(x-10,y-10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta2,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//c
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x+20,y+10);
	glVertex2i(x+20,y);
	glEnd();
	glPopMatrix();

	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{

		cosine=(x)+(m*cos(i));
        		sine=(y+10)+(m*sin(i));
		glVertex2f(cosine,sine);


	}
	glEnd();


	glColor3f(1.0,1.0,0.0);
	//foot
            glBegin(GL_LINE_LOOP);
	    glVertex2i(x+80,y-45);
	    glVertex2i(x+80,y-40);
	    glVertex2i(x+120,y-40);
	    glVertex2i(x+125,y-45);
	    glEnd();

	//foot line
	glBegin(GL_LINES);
	glVertex2i(x+100,y-35);
	glVertex2i(x+90,y-40);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x+100,y-35);
	glVertex2i(x+110,y-40);
	glEnd();
}



void move()
{

if(xx<601.0)
{

	if(yy>=400.0)
	{
	do{
		xx=xx+0.03;
	}
		while(xx==600.0);

   	}



	else
	{
		xx=xx+0.01;

		yy=yy+0.03;
	}
	}
else{


		do
		{
			xx=xx+0.02;
			yy=yy-0.02;
		}
		while(yy<=200.0);

 }

	if(theta<100)
		  theta+=50.0;
		else theta=0;

		if(theta1<100)
		 theta1+=50.0;
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;
   	glutPostRedisplay();
}


void inc()
{



if(xx<601.0)
{

	if(yy>=400.0)
	{
	do{
		xx=xx+0.03+g_spin;
	}
		while(xx==600.0);

   	}



	else
	{
		xx=xx+0.01+g_spin;

		yy=yy+0.03+g_spin;
	}
	}
else{


		do
		{
			xx=xx+0.02+g_spin;
			yy=yy-0.02-g_spin;
		}
		while(yy<=200.0);

 }

	if(theta<100)
		  theta+=50.0;
		else theta=0;

		if(theta1<100)
		 theta1+=50.0;
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;
   	glutPostRedisplay();
}



void dec()
{

if(xx<601.0)
{

	if(yy>=400.0)
	{
	do{
		xx=xx+0.08+g_spin;
	}
		while(xx==600.0);

   	}

else
	{
		xx=xx+0.005+g_spin;
		yy=yy+0.01-g_spin;
	}
	}
else{


		do
		{
			xx=xx+0.01+g_spin;
			yy=yy+0.01-g_spin;
		}
		while(yy<=200.0);

 }

	if(theta<100)
		  theta+=50.0;
		else theta=0;

		if(theta1<100)
		 theta1+=50.0;
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;
   	glutPostRedisplay();
}

void mykeyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
		case 115:
				start=1;

		 		glutIdleFunc(limit);

				break;
		case 109:
			glutIdleFunc(move);

			break;

		case 113:
				exit(0);
				break;
		case 104:
			glutIdleFunc(inc);
				g_spin+=H_SPIN;
				break;

		case 108:
				glutIdleFunc(dec);
					g_spin-=H_SPIN;
						break;


		case 114:
				if(xx>=1000)
					xx=0;
				xx=xx+1;
				break;
        case 98:
				xx=xx-1;
				break;


		case 100:		yy=yy-1;

                    break;
        case 117:
		   yy=yy+1;
				glutPostRedisplay();
				break;
		case 110:
			 flag1=1;
			 break;
		case 99:
			 flag2=1;
			 break;
   }


}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,800);
	glutCreateWindow("THE HELICOPTER");
	glutDisplayFunc(mydisplay);
	glutIdleFunc(limit);
	glutKeyboardFunc(mykeyboard);
	init();
	glutMainLoop();
}

