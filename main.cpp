//HEADERS
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
// GLOBAL VARIABLES
//Game Speed
int gameSpeedFPS = 50;
//Game Track
int start = 0;
int gameOver = 0;
int level = 0;
//Track Score
int score = 0;
//Form move track
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;
//For Card Left / RIGHT
int horizontalPos = 0 ;
//Car Coming
int car1 = 0;
int lrIndex1 = 0;
int car2 = +35;
int lrIndex2 = 0;
int car3 = +70;
int lrIndex3 = 0;

//Function to draw text characters
void drawText(char ch[],float xpos, float ypos)
{
 int numofchar = strlen(ch);
 int i = 0;
 glColor3f(1.0f, 1.0f, 1.0f);
 glRasterPos2f( xpos , ypos);
 for (i = 0; i <= numofchar - 1; i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]); //Font name and character
 }
}

void drawText2(char ch[],float xpos, float ypos)
{
 int numofchar = strlen(ch);
 int i = 0;
 glColor3f(0.0f, 0.0f, 1.0f);
 glRasterPos2f( xpos , ypos);
 for (i = 0; i <= numofchar - 1; i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, ch[i]); //Font name and character
 }
}

void gameScreenDraw(){
 //Road
 glColor3f(0.5, 0.5, 0.5);
 glBegin(GL_POLYGON);
 glVertex2f(20,0);
 glVertex2f(20,100);
 glVertex2f(80,100);
 glVertex2f(80,0);
 glEnd();
 //Road Left Border
 glColor3f(1.000, 1.000, 1.000);
 glBegin(GL_POLYGON);
 glVertex2f(20,0);
 glVertex2f(20,100);
 glVertex2f(23,100);
 glVertex2f(23,0);
 glEnd();
 //Road Right Border
 glColor3f(1.000, 1.000, 1.000);
 glBegin(GL_POLYGON);
 glVertex2f(77,0);
 glVertex2f(77,100);
 glVertex2f(80,100);
 glVertex2f(80,0);
 glEnd();

//Road Middle Border
 //TOP
 glColor3f(1.000, 1.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(48,roadDivTop+80);
 glVertex2f(48,roadDivTop+100);
 glVertex2f(52,roadDivTop+100);
 glVertex2f(52,roadDivTop+80);
 glEnd();
 roadDivTop--
;
 if(roadDivTop<
-100){
 roadDivTop =20;
 score++;

}
 //Midle
 glColor3f(1.000, 1.000, 0.200);
 glBegin(GL_POLYGON);
 glVertex2f(48,roadDivMdl+40);
 glVertex2f(48,roadDivMdl+60);
 glVertex2f(52,roadDivMdl+60);
 glVertex2f(52,roadDivMdl+40);
 glEnd();
 roadDivMdl--;
 if(roadDivMdl<-60){
 roadDivMdl =60;
 score++;
 }
 //Bottom
 glColor3f(1.000, 1.000, 0.400);
 glBegin(GL_POLYGON);
 glVertex2f(48,roadDivBtm+0);
 glVertex2f(48,roadDivBtm+20);
 glVertex2f(52,roadDivBtm+20);
 glVertex2f(52,roadDivBtm+0);
 glEnd();
 roadDivBtm--;
 if(roadDivBtm<-20){
 roadDivBtm=100;
 score++;
 }

 //Score Board
 glColor3f(0.000, 0.300, 0.700);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(0,20);
 glVertex2f(20,20);
 glVertex2f(20,0);
 glEnd();

 drawText("Score", 5, 10);

 //Take score int variable and convert into char array to display score
 std::string str = std::to_string(score);
 char* char_arr;
 std::string str_obj(str);
 char_arr = &str_obj[0];

 drawText(char_arr, 5, 5);

     //Speed Print
    char buffer1 [50];
    sprintf (buffer1, "SPEED:%dKm/h", gameSpeedFPS);
    drawText2(buffer1,80.5,5);

 //Player's Car

 //Front Tire
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(horizontalPos+26-2,5);
 glVertex2f(horizontalPos+26-2,7);
 glVertex2f(horizontalPos+30+2,7);
 glVertex2f(horizontalPos+30+2,5);
 glEnd();

 //Back Tire
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(horizontalPos+26-2,1);
 glVertex2f(horizontalPos+26-2,3);
 glVertex2f(horizontalPos+30+2,3);
 glVertex2f(horizontalPos+30+2,1);
 glEnd();

 //Car Body
 glColor3f(0.6, 1.000, 0.2);
 glBegin(GL_POLYGON);
 glVertex2f(horizontalPos+26,1);
 glVertex2f(horizontalPos+26,8);
 glColor3f(0.000, 0.6, 0.6);
 glVertex2f(horizontalPos+28,10);
 glVertex2f(horizontalPos+30,8);
 glVertex2f(horizontalPos+30,1);
 glEnd();
 //Opposite car Reddish
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex1+26-2,car1+100-4);
 glVertex2f(lrIndex1+26-2,car1+100-6);
 glVertex2f(lrIndex1+30+2,car1+100-6);
 glVertex2f(lrIndex1+30+2,car1+100-4);
 glEnd();
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex1+26-2,car1+100);
 glVertex2f(lrIndex1+26-2,car1+100-2);
 glVertex2f(lrIndex1+30+2,car1+100-2);
 glVertex2f(lrIndex1+30+2,car1+100);
 glEnd();
 glColor3f(1.000, 0.300, 0.200);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex1+26,car1+100);
 glVertex2f(lrIndex1+26,car1+100-7);
 glVertex2f(lrIndex1+28,car1+100-9);
 glVertex2f(lrIndex1+30,car1+100-7);
 glVertex2f(lrIndex1+30,car1+100);
 glEnd();
 car1--;
 if(car1<-100){
 car1=0;
 lrIndex1=horizontalPos;
 }

 //Kill check car 1
 if((abs(horizontalPos-lrIndex1)<8) && (car1+100<10)){
 start = 0;
 gameOver=1;
 }
 //Opposite car Purple
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex2+26-2,car2+100-4);
 glVertex2f(lrIndex2+26-2,car2+100-6);
 glVertex2f(lrIndex2+30+2,car2+100-6);
 glVertex2f(lrIndex2+30+2,car2+100-4);
 glEnd();
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex2+26-2,car2+100);
 glVertex2f(lrIndex2+26-2,car2+100-2);
 glVertex2f(lrIndex2+30+2,car2+100-2);
 glVertex2f(lrIndex2+30+2,car2+100);
 glEnd();
 glColor3f(0.7, 0.100, 0.7);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex2+26,car2+100);
 glVertex2f(lrIndex2+26,car2+100-7);
 glVertex2f(lrIndex2+28,car2+100-9);
 glVertex2f(lrIndex2+30,car2+100-7);
 glVertex2f(lrIndex2+30,car2+100);
 glEnd();
 car2--;
 if(car2<-100){
 car2=0;
 lrIndex2=horizontalPos;

}

 //Kill check car2
 if((abs(horizontalPos-lrIndex2)<8) && (car2+100<10)){
 start = 0;
 gameOver = 1;

}
 //Opposite car pink
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex3+26-2,car3+100-4);
 glVertex2f(lrIndex3+26-2,car3+100-6);
 glVertex2f(lrIndex3+30+2,car3+100-6);
 glVertex2f(lrIndex3+30+2,car3+100-4);
 glEnd();
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex3+26-2,car3+100);
 glVertex2f(lrIndex3+26-2,car3+100-2);
 glVertex2f(lrIndex3+30+2,car3+100-2);
 glVertex2f(lrIndex3+30+2,car3+100);
 glEnd();
 glColor3f(1.000, 0.3, 0.700);
 glBegin(GL_POLYGON);
 glVertex2f(lrIndex3+26,car3+100);
 glVertex2f(lrIndex3+26,car3+100-7);
 glVertex2f(lrIndex3+28,car3+100-9);
 glVertex2f(lrIndex3+30,car3+100-7);
 glVertex2f(lrIndex3+30,car3+100);
 glEnd();
 car3--
;
 if(car3<-100){
 car3=0;
 lrIndex3=horizontalPos;
 }

 //Kill check car3
 if((abs(horizontalPos-lrIndex3)<8) && (car3+100<10)){
 start = 0;
 gameOver=1;
 }
}
void introScreenDraw(){
 //Road Background
 glColor3f(0.000, 0.392, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(0,55);
 glVertex2f(100,55);
 glColor3f(0.604, 0.804, 0.196);
 glVertex2f(100,0);
 glVertex2f(0,0);
 glEnd();
 //Road Design In Front Page
 glColor3f(0.5, 0.5, 0.5);
 glBegin(GL_TRIANGLES);
 glVertex2f(32-2+21,55);
 glVertex2f(100,0);
 glVertex2f(0,0);
 glEnd();
 //Road Sky
 glColor3f(0.000, 0.749, 1.000);
 glBegin(GL_POLYGON);
 glVertex2f(100,100);
 glVertex2f(0,100);
 glColor3f(0.686, 0.933, 0.933);
 glVertex2f(0,55);
 glVertex2f(100,55);
 glEnd();

 //Player's Car

 //Front Tire
 glColor3f(0.000, 0.000, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(44+2,25);
 glVertex2f(44+2,27);
 glVertex2f(52+2,27);
 glVertex2f(52+2,25);
 glEnd();

 //Back Tire
 glColor3f(0.00, 0.00, 0.000);
 glBegin(GL_POLYGON);
 glVertex2f(44,21);
 glVertex2f(44,23);
 glVertex2f(52+4,23);
 glVertex2f(52+4,21);
 glEnd();

 //Car Body
 glColor3f(0.6, 1.000, 0.1);
 glBegin(GL_POLYGON);
 glVertex2f(46+2+-2,21);
 glVertex2f(46+2,28);
 glColor3f(0.000, 0.5, 0.5);
 glVertex2f(48+2,30);
 glVertex2f(50+2,28);
 glVertex2f(50+2+2,21);
 glEnd();
 //Text Information Intro Page

 drawText("CAR RACER GAME", 34, 90);
 drawText("By Ayush Chauhan", 34.5, 75);
 drawText("PRESS SPACE TO START", 29, 10);
}
void display(){
 glClear(GL_COLOR_BUFFER_BIT);
 if(start == 1){
 glClearColor(0.000, 0.7, 0.200,1);
 gameScreenDraw();
 }
 else{

 introScreenDraw();
 }
 glFlush();
 glutSwapBuffers();
}
void spl_keys(int key, int x, int y){
 switch (key) {
 //Slows down game
 case GLUT_KEY_DOWN:
 if(gameSpeedFPS>(50+(level*2)))
 gameSpeedFPS=gameSpeedFPS-2;
 break;
 //Speeds game up
 case GLUT_KEY_UP:
 gameSpeedFPS=gameSpeedFPS+2;
 break;
 //Moves car left
 case GLUT_KEY_LEFT:
 if(horizontalPos>=0){
 horizontalPos = horizontalPos - (gameSpeedFPS/10);
 if(horizontalPos<0){
 horizontalPos=-1;
 }
 }
 break;
 //Moves car right
 case GLUT_KEY_RIGHT:
 if(horizontalPos<=44){
 horizontalPos = horizontalPos + (gameSpeedFPS/10);
 if(horizontalPos>44){
 horizontalPos = 45;
 }
 }
 break;
 default:
 break;
 }
}
void processKeys(unsigned char key, int x, int y) {
 switch (key)
 {
 case ' ':
 if(start==0){
 start = 1;
 gameOver = 0;
 gameSpeedFPS = 50;
 roadDivTopMost = 0;
 roadDivTop = 0;
 roadDivMdl = 0;
 roadDivBtm = 0;
 horizontalPos = 0 ;
 car1 = 0;
 lrIndex1=0;
 car2 = +35;
 lrIndex2=0;
 car3 = +70;
 lrIndex3=0;
 score=0;
 level=0;
 //Pressing space starts the game, sets initial variables
 }
 break;
 case 27:
 exit(0); //Pressing escape exits
 break;
 default:
 break;
 }
}
void timer(int){
 glutPostRedisplay(); //Marks the frame ready for updating and calls display function
 glutTimerFunc(1000/gameSpeedFPS,timer,0);
}
int main(int argc, char *argv[])
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 glutInitWindowSize(500,650); // Make a window of 500*650
 glutInitWindowPosition(20,20); // Init position of that window
 glutCreateWindow("Car Racer"); //Title of window
 glutDisplayFunc(display); //Function that draws on the screen
 glutSpecialFunc(spl_keys); //Car Control keys
 glutKeyboardFunc(processKeys); //Function that defines what to do with keyboard input | Start and end game
 glOrtho(0,100,0,100,-1,1); //For orthographic project
 glClearColor(0.2, 0.3, 0.3,1); //Default color
 glutTimerFunc(1000,timer,0); //Timer function to set frame update rate
 glutMainLoop(); //Repeatedly run code
 return 0;
}
