#include <iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

static bool paused = false;

/*void *currentfont;
int f = 0;
void setFont(void *font)
{
        currentfont = font;
}
void drawstring(float x, float y, float z, char *string)
{
         char *c;
         glRasterPos3f(x,y,z);
         for(c = string; *c != '\0'; c++)
         {
                glColor3f(0.0, 0.0, 0.0);
                glutBitmapCharacter(currentfont, *c);
         }
}
 void first_page()
{
        //glClear(GL_COLOR_BUFFER_BIT);
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.529, 0.808, 0.922);
        drawstring(100.0, 455.0, 1.0,"******* * * * * * * * * * INTRODUCTION * * * * * * * * * *********");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.0, 0.0, 1.0);
        drawstring(160.0, 430.0, 1.0,"PESIT BANGLORE SOUTH CAMPUS");
        glColor3f(0.0, 0.0, 1.0);
        drawstring(100.0, 400.0, 1.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
        glColor3f(0.863, 0.078, 0.235);
        drawstring(130.0, 360.0, 1.0,"A MINI PROJECT ON SODIUM/POTASSIUM PUMP");
        glColor3f(1.000, 0.843, 0.000);
        drawstring(120.0, 330.0, 1.0,"");
        glColor3f(0.678, 1.000, 0.184);
        setFont(GLUT_BITMAP_9_BY_15);
        drawstring(120.0, 250.0, 1.0,"BY");
        glColor3f(1.000, 0.843, 0.000);
        drawstring(120.0, 330.0, 1.0,"");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.502, 0.000, 0.502);
        drawstring(120.0, 230.0, 1.0,"1. GUNJAN DWIVEDI                                1PE14CS044");
        glColor3f(0.502, 0.000, 0.502);
        drawstring(120.0, 210.0, 1.0,"2. MAYANK PRAKASH                             1PE14CS070");
        glColor3f(0.95, 0.15, 0.0);
        drawstring(120.0, 150.0, 1.0,"UNDER THE GUIDANCE OF");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(120.0, 130.0, 1.0,"1. Ms. Shubha Raj");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(120.0, 110.0, 1.0,"2. Dr. Sarasvathi");
        glColor3f(0.196, 0.804, 0.196);
        drawstring(200.0, 50.0, 1.0,"PRESS ENTER TO START");
        //glFlush();
} */

float cmlxn = 0, cmlxp = 0,  cmuxn = 0, cmuxp = 0; // cell membrane selective opening
void cell_membrane(void)
{
        glColor3f(0, 1, 0);
        glBegin(GL_QUADS); // Draw a filled rectangle with current color
                glVertex2d(-85, 20);
                glVertex2d(-100, 20);
                glVertex2d(-100, -30);
                glVertex2d(-85, -30);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2d(-55, 20);
                glVertex2d(-40, 20);
                glVertex2d(-40, -30);
                glVertex2d(-55, -30);
        glEnd();

        //movable parts
        glPushMatrix();
        glColor3f(1, 0.15, 0);
        if(cmlxn >= -30 && !paused)
        {
                cmlxn -= 0.008;
                glTranslated(cmlxn, 0, 0);
                cmlxp = cmlxn;
        }
        else if (cmlxp <= 0 && !paused)
        {
                cmlxp += 0.008;
                glTranslated(cmlxp, 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(-55, -30);
                glVertex2d(-85, -30);
                glVertex2d(-85, -32);
                glVertex2d(-55, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        if (cmuxp <= 30 && !paused)
        {
                cmuxp += 0.008;
                glTranslatef(cmuxp  , 0, 0);
                cmuxn = cmuxp;
        }
        else if (cmuxn >= 0 && !paused)
        {
                cmuxn -= 0.008;
                glTranslatef(cmuxn  , 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(-85, 20);
                glVertex2d(-55, 20);
                glVertex2d(-55, 22);
                glVertex2d(-85, 22);
        glEnd();
        glPopMatrix();
}

void cells(void) //total static
{
        int j = 0, k = 0;
        //right upper portion
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(90 + k, 20);
                        glVertex2d(95 + k, 20);
                        glVertex2d(95 + k, 15);
                        glVertex2d(90 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(95 + k, 20);
                        glVertex2d(100 + k, 20);
                        glVertex2d(100 + k, 15);
                        glVertex2d(95 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //upper middle portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, 20);
                        glVertex2d(-40 + k, 20);
                        glVertex2d(-40 + k, 15);
                        glVertex2d(-35 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, 20);
                        glVertex2d(-30 + k, 20);
                        glVertex2d(-30 + k, 15);
                        glVertex2d(-35 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //left upper portions
        j = 0;
        k = 0;
        for(int i = 1; i <= 9; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS); // Draw a filled rectangle with current color
                        glVertex2d(-105 - k, 20);
                        glVertex2d(-100 - k, 20);
                        glVertex2d(-100 - k, 15);
                        glVertex2d(-105 - k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 8; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-105 - k, 20);
                        glVertex2d(-110 - k, 20);
                        glVertex2d(-110 - k, 15);
                        glVertex2d(-105 - k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //right lower portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(90 + k, -30);
                        glVertex2d(95 + k, -30);
                        glVertex2d(95 + k, -25);
                        glVertex2d(90 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(95 + k, -30);
                        glVertex2d(100 + k, -30);
                        glVertex2d(100 + k, -25);
                        glVertex2d(95 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //lower middle portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-40 + k, -30);
                        glVertex2d(-40 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-30 + k, -30);
                        glVertex2d(-30 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //left lower portions
        j = 0;
        k = 0;
        for(int i = 1; i <= 9; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS); // Draw a filled rectangle with current color
                        glVertex2d(-105 - k, -30);
                        glVertex2d(-100 - k, -30);
                        glVertex2d(-100 - k, -25);
                        glVertex2d(-105 - k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 8; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-105 - k, -30);
                        glVertex2d(-110 - k, -30);
                        glVertex2d(-110 - k, -25);
                        glVertex2d(-105 - k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
}

float indy = 0;
void concentration_indicator(void)
{
        int k = 0, l = 0;
        for(int i=1; i <= 20; i += 1)
        {
                glColor3ub(230 - k, 0 + k, 0); // transparency indicating increase in electronic gradient potential
                glBegin(GL_QUADS);
                        glVertex2f(180, -45+l);
                        glVertex2f(183, -45+l);
                        glVertex2f(183, -50+l);
                        glVertex2f(180, -50+l);
                glEnd();
                l += 5;
                k += 10;
        }
        // indicator position
        if (indy < 100 && !paused)
        {
                indy += 0.0134; //for syncing with channel protein gateway
        }
        glPushMatrix();
        glTranslated(0, indy, 0);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
                glVertex2d(179, -50);
                glVertex2d(177, -48);
                glVertex2d(177, -52);
        glEnd();
        glPopMatrix();
}

float nalx = 0, narx = 0;
void sodium(void)
{
        int k = 0;
        glPushMatrix();
        if (narx <= 20 && !paused)
        {
                narx += 0.0053;
                glTranslatef(narx, 0, 0);
                nalx = narx;
        }
        else if (nalx > 0 && !paused)
        {
                nalx -= 0.0053;
                glTranslatef(nalx, 0, 0);
        }
        glColor3f(0.5, 0, 0.2);
        for(int i = 1; i <= 9; i += 1)
        {
                glBegin(GL_POLYGON);
                        glVertex2d(-100 + k, -45);
                        glVertex2d(-105 + k, -50);
                        glVertex2d(-100 + k, -55);
                        glVertex2d(-95 + k, -50);
                glEnd();
                k += 25;
        }
        glPopMatrix();
}

float atplx = 0, atprx = 0;
void ATP(void)
{
        int k = 0;
        glPushMatrix();
        if (atplx >= -20 && !paused)
        {
                atplx -= 0.0053;
                glTranslatef(atplx, 0, 0);
                atprx = atplx;
        }
        else if(atprx <= 0 && !paused)
        {
                atprx += 0.0053;
                glTranslatef(atprx, 0, 0);
        }
        for(int i = 0; i <= 5; i += 1)
        {
                glColor3f(0, 1, 1);
                glBegin(GL_POLYGON);
                        glVertex2d(-120 + k, -90);
                        glVertex2d(-110 + k, -90);
                        glVertex2d(-115 + k, -80);
                glEnd();
                glColor3f(1, 1, 0);
                glBegin(GL_POLYGON);
                        glVertex2d(-120 + k, -90);
                        glVertex2d(-123 + k, -95);
                        glVertex2d(-117 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-110 + k, -90);
                        glVertex2d(-113 + k, -95);
                        glVertex2d(-107 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-120 + k, -90);
                        glVertex2d(-123 + k, -95);
                        glVertex2d(-117 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-115 + k, -80);
                        glVertex2d(-112 + k, -75);
                        glVertex2d(-118 + k, -75);
                glEnd();
                k += 45;
        }
        glPopMatrix();
}

float klx = 0, krx = 0;
void potassium(void)
{
        int k = 0;
        glPushMatrix();
        if (krx <= 20 && !paused)
        {
                krx += 0.0053;
                glTranslatef(krx, 0, 0);
                klx = krx;
        }
        else if (klx > 0 && !paused)
        {
                klx -= 0.0053;
                glTranslatef(klx, 0, 0);
        }
        glColor3f(0.8, 0.3, 0.5);
        for(int i = 1; i <= 6; i += 1)
        {
                glBegin(GL_POLYGON);
                        glVertex2d(-90 + k, 35);
                        glVertex2d(-97 + k, 42);
                        glVertex2d(-90 + k, 49);
                        glVertex2d(-83 + k, 42);
                glEnd();
                k += 25;
        }
        glPopMatrix();
}

float goxp = 0, goxn = 0;
void glucose_out(void)
{
        glPushMatrix();
        if(goxn >= -20 && !paused)
        {
                goxn -= 0.0053;
                glTranslatef(goxn, 0, 0);
                goxp = goxn;
        }
        else if(goxp <= 0 && !paused)
        {
                goxp += 0.0053;
                glTranslatef(goxp, 0, 0);
        }
        glColor3f(0.5, 1, 0.4);
        int k = 0;
        for(int i = 1; i <= 5; i += 1)
        {
                glBegin(GL_POLYGON);
                        glVertex2f(-110 + k, 90);
                        glVertex2f(-115 + k, 85);
                        glVertex2f(-110 + k, 80);
                        glVertex2f(-105 + k, 80);
                        glVertex2f(-100 + k, 85);
                        glVertex2f(-105 + k, 90);
                glEnd();
                k += 50;
        }
        glColor3f(1, 1, 0.2);
        k = 0;
        for (int i = 1; i <= 5; i +=1)
        {
                glBegin(GL_POLYGON);
                        glVertex2f(-108 + k, 75);
                        glVertex2f(-113 + k, 70);
                        glVertex2f(-113 + k, 65);
                        glVertex2f(-108 + k, 60);
                        glVertex2f(-103 + k, 65);
                        glVertex2f(-103 + k, 70);
                glEnd();
                k += 50;
        }
        glPopMatrix();
}

//float glulx = 0, glurx = 0, gluy = 0; //glucose movement 3 Right : 2 Left
//void glucose_out_in(void)
//{
//                glColor3f()
//}

// active transport initiation for glucose transportation when potential builds up; i.e. channel protein opens-up
float cplxn = 0, cplxp = 0;
float cpuxp = 0, cpuxn = 0;
void channel_protein(void)
{
        glColor3f(0, 1, 1);
        glBegin(GL_QUADS); // Draw a filled rectangle with current color
                glVertex2d(30, 20);
                glVertex2d(45, 20);
                glVertex2d(45, -30);
                glVertex2d(30, -30);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2d(75, 20);
                glVertex2d(90, 20);
                glVertex2d(90, -30);
                glVertex2d(75, -30);
        glEnd();
        glColor3f(0.25, 0.15, 0.75);
        glPushMatrix();
        //movable parts
        if (cplxn >= -30 && !paused)
        {
                cplxn -= 0.008;
                glTranslatef(cplxn, 0, 0);
                cplxp = cplxn;
        }
        else if (cplxp <= 0 && !paused)
        {
                cplxp += 0.008;
                glTranslatef(cplxp, 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(75, -30);
                glVertex2d(45, -30);
                glVertex2d(45, -32);
                glVertex2d(75, -32);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        if (cpuxp <= 30 && !paused)
        {
                cpuxp += 0.008;
                glTranslatef(cpuxp, 0, 0);
                cpuxn = cpuxp;
        }
        else if (cpuxn >= 0 && !paused)
        {
                cpuxn -= 0.008;
                glTranslatef(cpuxn, 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(45, 20);
                glVertex2d(75, 20);
                glVertex2d(75, 22);
                glVertex2d(45, 22);
        glEnd();
        glPopMatrix();
}

void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT );//clear the window with current clearing color, i.e. removes the last drawing from the window
        //     first_page();
        // rotation yet to be applied
        cell_membrane(); //partially done, i.e. opening and closing. waiting yet to be deployed
        cells(); //done
        concentration_indicator(); //done
        sodium(); // modeling done, translation left
        ATP(); // partially done. transition to ADP left over
        potassium(); // modelling done, translation left
        glucose_out(); //done
        //glucose_out_in();
        channel_protein(); //partially done, i.e. opening and closing. waiting yet to be deployed
        glutSwapBuffers(); //for animation; glFlush() not required as it implicitly applies before rendering
        glutPostRedisplay();// iteration over rendering to show the movable parts
}

void reshape(GLsizei w, GLsizei h)
{
        GLfloat aspectRatio;
        if(h == 0)  // Prevent a divide by zero
        {
                h = 1;
        }
        glViewport(0, 0, w, h); // Set Viewport to window dimensions
        // Reset coordinate system
        glMatrixMode(GL_PROJECTION); // actual view volume defined here
        glLoadIdentity(); // required as "glOrtho(x1, x2, y1, y2, z1, z2)" modifies the existing clipping volume and doesn't establish the clipping volume
        // Establish clipping volume (left, right, bottom, top, near, far)
        aspectRatio = (GLfloat)w / (GLfloat)h;
        // maintaining the square window
        if (w <= h) // vertical modification
        {
                glOrtho (-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
        }
        else // horizontal modification
        {
                glOrtho (-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
        }
        // all the updates are to be registered on the model
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void handleKeypress(unsigned char key, int x, int y)
 {
        switch (key)
        {
                //case 13:
                case 27:        exit(0); //Escape key
                case 'p':       paused = !paused;
                                         break;
        }
}

/*void init()
{
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glColor3f(1.0, 0.0, 0.0);
        gluOrtho2D(0.0, 639.0, 0.0, 479.0);
}*/

int main(int argc, char **argv)
{
        glutInit(&argc, argv); //to pass command line arguments and initialize GLUT library
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); /*type of display mode : DOUBLE buffered, i.e. drawing commands executed off-screen
                                                                                                                        *and swapped into view of the window, for ANIMATION
                                                                                                                        *SINGLE buffered, i.e. drawing commands are performed on the window displayed
                                                                                                                        *RGBA, i.e. specify colors with separate intensities */
        glutInitWindowSize(1000, 480);
        glutInitWindowPosition(0,0);
//        init();
        glutCreateWindow("Na+/K+ pump"); // creates window on the screen
        glClearColor(0, 0, 0 , 0); //initialization before rendering
        glutDisplayFunc(display); //called whenever window needs to be drawn
        glutKeyboardFunc(handleKeypress);
        glutReshapeFunc(reshape);
        glutMainLoop();
        return 0;
}
