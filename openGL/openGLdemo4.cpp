/// This demo shows a simple composite figure, shapePerson
/// With and without animation. With and without displayWindow logic.
// See http://www.lighthouse3d.com/cg-topics/glut-and-freeglut/ for freeglut function explanations

//compile with:  g++ openGLdemo4.cpp -lglut -lGLU -lGL

#include <GLUT/glut.h>   //opengL library
#include <GL/freeglut.h>    //***freeglut library - more control over events
#include <math.h>   //cos, sin, M_PI
#include <unistd.h>  // sleep(), usleep()
#include <iostream>

using namespace std;

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
    //center of circle is located at x, y
    //radius of circle is r
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

//this is the primary display function that selects the values to affect the animation speed, sizes, and locations
void myDisplay(void){
    
    // WITHOUT ANIMATION
    glClear(GL_COLOR_BUFFER_BIT);  
    drawShapePerson(-.5,.4);
    glFlush();   //flush the buffer
    
    // WITH ANIMATION
    // for (double i = -1; i <= 1; i += .05){
    //     glClear(GL_COLOR_BUFFER_BIT);
    //     drawShapePerson(i, .4);
    //     usleep(150000);    
    //     glFlush();   //flush the buffer   
    // } 
}

int main(int argc, char* argv[]){

    // Note that my main can do 'normal' cpp code that uses logic to open the displayWindow
    char userPlay;
    cout << "would you like to play? (y/n)" << endl;
    cin >> userPlay;
    //if(userPlay == 'y'){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
        //when we close the display window, the above setting returns control to the original function in your code
        glutInitWindowSize(500, 500);   // **experiment with different window sizes by changing these arguments
        glutInitWindowPosition(600, 300);   // **experiment with different window locations by changing these arguments
        glutCreateWindow("OpenGL!");   // **try  putting different text in your window display
        glutDisplayFunc(myDisplay);
        glutMainLoop();
    //}
    cout << "Thanks for playing!" << endl;   //by default, glut does not return to the flow of code,
                                            // therefore, we use the freeglut behaviors to regain control
    return 0;
}