/// The adventures of shapePerson continue!!
// more user interaction and animation...

//compile with:  g++ openGLdemo6.cpp -lglut -lGLU -lGL

#include <GLUT/glut.h>   //opengL library
#include <GL/freeglut.h>    //freeglut library
#include <math.h>   //cos, sin, M_PI
#include <unistd.h>  // sleep(), usleep()
#include <iostream>

using namespace std;

//Create an array of 255 booleans to represent the ascii values' pressed states.
// For example, since the ascii value of 'j' is 106, 
// looking at keyStates['j'] is really looking at keyStates[106]
// Adapted from http://www.swiftless.com/tutorials/opengl/keyboard.html
bool keyStates[256]; 

// **** shapePerson function prototypes *****//
void drawLeftLeg(double x, double height);
void drawRightLeg(double x, double height);
void drawLeftArm(double x, double height);
void drawRightArm(double x, double height);
void drawTorso(double x, double height);
void drawCircle(double r, double x, double y);
void drawShapePerson(double x, double height);

// function that controls what to do when each key is pressed
// this is the function glut calls when a key goes down
// NOTE that since keyPressed is used as the keyboard event function, it MUST have the args shown
void keyPressed (unsigned char key, int x, int y) {  
    //cout << x << endl;
    static double startPos = -1;  //shapePerson starts all the way at the left side of window
    //remember, static means the value of the variable is preserved between function calls

    double i; //for loop increment
    double moveAmount = 0;  //amount to move shapePerson
    keyStates[key] = true; // Set the state of the current key to true/pressed

    if (key == 'f'){ // if the f key is pressed...
        cout << "Move forward!" << endl;
        cout << "Enter amount to move forward: (decimal value 0 - 2)" << endl;
        cin >> moveAmount;
        //move shapePerson forward the specified amount:
        for (i = startPos; i <= startPos + moveAmount; i += .05){
            glClear(GL_COLOR_BUFFER_BIT);        
            drawShapePerson(i, .4);
            usleep(150000);    
            glFlush();   //flush the buffer
            
        }
        startPos = i;  //keep track of where shapePerson was last standing
    }
     
    else if(key == 'b'){ // if the b key is pressed...
        cout << "Move backward!" << endl;
        cout << "Enter amount to move backward: (decimal value 0 - 2)" << endl;
        cin >> moveAmount;
        // move shapePerson backward the specified amount
        for (i = startPos; i >= startPos - moveAmount; i -= .05){
            glClear(GL_COLOR_BUFFER_BIT);        
            drawShapePerson(i, .4);
            usleep(150000);    
            glFlush();   //flush the buffer 
        }
        startPos = i; // keep track of where shapePerson was last standing
    } 

    else if(key == 'a'){
        cout << "Action!!" << endl;
        //draw shapePerson with no movement
        glClear(GL_COLOR_BUFFER_BIT);        
        drawShapePerson(startPos, .4);  //use last known location
        usleep(150000);    
        glFlush(); 
    }
}  

// function that glut will call when key stops being pressed 
// since keyUp is a keyboard event function, it MUST have the arguments shown 
void keyUp (unsigned char key, int x, int y) {  
    keyStates[key] = false; // Set the state of the current key to false/not pressed  
} 

// function to draw shapePerson at position one
void positionOne(void){
    glClear(GL_COLOR_BUFFER_BIT);  
    drawShapePerson(-1,.4);
    glFlush();   //flush the buffer
}

// function to handle the window setup
void myGlutInit(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutInitWindowSize(500, 500);   // **experiment with different window sizes by changing these arguments
    glutInitWindowPosition(600, 300);   // **experiment with different window locations by changing these arguments
    glutCreateWindow("ShapePerson gets a free-throw!");
    glutKeyboardFunc(keyPressed);  // specifies which function to call if there is a key down event
    glutKeyboardUpFunc(keyUp);   // specifies which function to call if there is a key up event        
}

int main(int argc, char* argv[]){

    //set all keyStates to false/not pressed
    for (bool k : keyStates){ 
    k = false; 
    }

    char userPlay;
    cout << "Would you like to move? (y/n)" << endl;
    cin >> userPlay;
    if(userPlay == 'y'){
        cout << "Press f to move forward, b to move backward, and a to act!" << endl;
        cout << "The 'window' must be active for your key-presses to work..." << endl;
        myGlutInit(argc, argv);   //moving the window setup into its own function, send the command line args too!
        glutDisplayFunc(positionOne); //specifies function to call when window is up and running
        glutMainLoop();
    }
    cout << "Thanks for playing!" << endl;

    return 0;
}



/********** SHAPEPERSON FUNCTION DEFINITIONS *********/

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