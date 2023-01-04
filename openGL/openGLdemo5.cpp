/// The adventures of shapePerson continue!!
// We experiment with a keyboard interaction

//compile with:  g++ openGLdemo5.cpp -lglut -lGLU -lGL

#include <GLUT/glut.h>   //opengL library
#include <GL/freeglut.h>    //freeglut library
#include <math.h>   //cos, sin, M_PI
#include <unistd.h>  // sleep(), usleep()
#include <iostream>


using namespace std;

// some function prototypes (definitions below main to clean up this space)
void drawLeftLeg(double x, double height);
void drawRightLeg(double x, double height);
void drawLeftArm(double x, double height);
void drawRightArm(double x, double height);
void drawTorso(double x, double height);
void drawCircle(double r, double x, double y);
void drawShapePerson(double x, double height);

// function to draw shapePerson at position one
void positionOne(void){
    glClear(GL_COLOR_BUFFER_BIT);  
    drawShapePerson(-1,.4);
    glFlush();   //flush the buffer
}

// since myDisplay is being used as a keyboard event function, it MUST have the arguments shown
void myDisplay(unsigned char k, int x, int y){  
    double forward; //amount to advance shapePerson
    char userMove;
    cout << "Would you like to move forward? (y/n)" << endl;
    cin >> userMove;
    if (userMove == 'y'){
        cout << "Enter amount to move forward: (decimal value 0 - 2)" << endl;
        cin >> forward;
    }
    //move shapePerson forward the specified amount:
    for (double i = -1; i <= forward - 1; i += .05){
        glClear(GL_COLOR_BUFFER_BIT);        
        drawShapePerson(i, .4);
        usleep(150000);    
        glFlush();     
    }
}

// function to handle the window setup
void myGlutInit(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); //return control to program after window closed
    glutInitWindowSize(500, 500);   
    glutInitWindowPosition(600, 300);   
    glutCreateWindow("Adventures of ShapePerson!");
}

int main(int argc, char* argv[]){

    char userPlay;
    cout << "would you like to play? (y/n)" << endl;
    cin >> userPlay;
    if(userPlay == 'y'){
        myGlutInit(argc, argv);   //moving the window setup into its own function, send the command line args too!
        glutDisplayFunc(positionOne);  //specify function to call once window up and running
        glutKeyboardFunc(myDisplay);  // >> this specifies which function to call if there is a keyboard event
        glutMainLoop();
    }
    cout << "Thanks for playing!" << endl;

    return 0;
}

/**********  FUNCTIONS  ************/

// function to draw shapePerson left leg based on horizontal location and height
void drawLeftLeg(double x, double height){
    glBegin(GL_POLYGON); 
    glColor3f(1.0, 1.0, 0.0);   
    glVertex2f(x - .01, (height / 3) - .98);   
    glVertex2f(x - .035, (height / 3) - .98);   
    glVertex2f(x - .065, -1);  
    glVertex2f(x - .04, -1);  
    glEnd(); 
}

// function to draw shapePerson right leg based on horizontal location and height
void drawRightLeg(double x, double height){
    glBegin(GL_POLYGON); 
    glColor3f(1.0, 1.0, 0.0);   
    glVertex2f(x + .01, (height / 3) - .98);   
    glVertex2f(x + .035, (height / 3) - .98);  
    glVertex2f(x + .065, -1);  
    glVertex2f(x + .04, -1);   
    glEnd(); 
}

// function to draw shapePerson left arm based on horizontal location and height
void drawLeftArm(double x, double height){
    glBegin(GL_POLYGON); 
    glColor3f(1.0, 1.0, 0.0);   
    glVertex2f(x + .065, (2 * height / 2.5) - 1.03);   
    glVertex2f(x + .065, (2 * height / 2.5) - 1.01);   
    glVertex2f(x + .19, (2 * height / 2.5) - 1.01);  
    glVertex2f(x + .19, (2 * height / 2.5) - 1.03);   
    glEnd(); 
}

// function to draw shapePerson right arm based on horizontal location and height
void drawRightArm(double x, double height){
    glBegin(GL_POLYGON); 
    glColor3f(1.0, 1.0, 0.0);   
    glVertex2f(x + .045, (2 * height / 2.5) - 1.03);    
    glVertex2f(x + .04, (2 * height / 2.5) - 1.01);  
    glVertex2f(x + .16, (2 * height / 2.5) - .91);  
    glVertex2f(x + .17, (2 * height / 2.5) - .93);   
    glEnd(); 
}

// function to draw shapePerson torso based on horizontal location and height
void drawTorso(double x, double height){
    glBegin(GL_POLYGON); 
    glColor3f(0.0, 1.0, 0.0);   
    glVertex2f(x, (height / 3) - 1);    // bottom of torso
    glVertex2f(x - .08, (2 * height / 2.5) - 1);  // top left corner
    glVertex2f(x + .08, (2 * height / 2.5) - 1);     // top right corner
    glEnd();
}

// function to draw a circle of radius r and center x,y
void drawCircle(double r, double x, double y){
    glBegin(GL_POLYGON);  //begin drawing this vertex figure
    glColor3f(1, 0, 0);   
    double incr = 0.5; // the "thickness"  of each of my slices
    for(double i = 0; i*M_PI/180 < 2*M_PI; i += incr){   //this loop will produce a series of very skinny triangles that form a circle
        glVertex3f(x, y, 0);
        glVertex3f(x + r * cos(i * M_PI / 180), y + r * sin(i * M_PI / 180), 0);
        glVertex3f(x + r * cos((incr + i) * M_PI / 180), y + r * sin((incr + i) * M_PI / 180), 0);
    }
    glEnd();  //end drawing this vertex figure
    
}

//function to draw a shapePerson standing at horizontal location x
void drawShapePerson(double x, double height){
    // draw left arm behind torso
    drawLeftArm(x, height);

    // ***torso***
    drawTorso(x, height);

    // draw right arm in front of torso
    drawRightArm(x, height);

    // ***head***
    drawCircle(.05, x, height - 1.03);

    // ***legs***
    drawLeftLeg(x, height);
    drawRightLeg(x, height);
}