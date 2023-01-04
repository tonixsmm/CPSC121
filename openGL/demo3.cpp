/* To download openGL on your VM, run:
    $ sudo apt update
    $ sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev
   After install, you may need to restart your VM.
*/

//compile with:  g++ openGLdemo3.cpp -lglut -lGLU -lGL

#include <GLUT/glut.h>   //opengL library
#include <math.h>   //cos, sin, M_PI
#include <unistd.h>  // sleep(), usleep()

using namespace std;

// function to draw a triangle with side length 'side'
void drawTriangle(double side){

    glBegin(GL_POLYGON); //begin drawing this vertex figure
    glColor3f(0.0, 1.0, 0.0);   // ***experiment with colors by changing one or more of these arguments

    // the two arguments in each glVertex2f() call are the x and y coordinate of a point
    // here we are creating our triangle based on connecting these three points:
    glVertex2f(side, 0.0);    //vertex one
    glVertex2f(0.0, 0.0);  //vertex two    //note that this vertex is at the origin
    glVertex2f(0.0, side);     //vertex three

    glEnd(); //end drawing this vertex figure

    // ***Can you set the location of the triangle through function arguments as well???
}

// function to draw a rectangle (color and location determined inside function)
void drawRectangle(void){
    
    glBegin(GL_POLYGON); //begin drawing this vertex figure
    glColor3f(1.0, 1.0, 1.0);   // **experiment with colors by changing one or more of these arguments

    // the two arguments in each glVertex2f() call are the x and y coordinate of a point
    // here we are creating our rectangle based on connecting these four points:
    glVertex2f(0.0, 0.0);    //vertex one
    glVertex2f(-0.5, 0.0);   //vertex two    //this vertex is at the origin
    glVertex2f(-0.5, -0.5);  //vertex three
    glVertex2f(0.0, -0.5);   //vertex four

    glEnd(); //end drawing this vertex figure

    // *** Can you set the location of the rectangle through function arguments as well???

    // *** can you set width and height through function arguments???
}

// function to draw a circle of radius r and center x,y
// note how this is an extension of our hexagon function...
void drawCircle(double r, double x, double y){
    //center of circle is located at x, y
    //radius of circle is r
    glBegin(GL_POLYGON);  //begin drawing this vertex figure
    glColor3f(1, 0, 0);   // what color does this seem to produce?
    double incr = 0.05; // the "thickness"  of each of my slices
    for(double i = 0; i*M_PI/180 < 2*M_PI; i += incr){   //this loop will produce a series of very skinny triangles that form a circle
        glVertex2f(x, y);
        glVertex2f(x + r * cos(i * M_PI / 180), y + r * sin(i * M_PI / 180));
        glVertex2f(x + r * cos((incr + i) * M_PI / 180), y + r * sin((incr + i) * M_PI / 180));
    }
    glEnd();  //end drawing this vertex figure
    
}

void myDisplay(void){
    //this is the primary display function that selects the values to affect the animation speed, sizes, and locations

    // series of drawings WITHOUT ANIMATION
    // glClear(GL_COLOR_BUFFER_BIT);  
    // drawTriangle(.2);        //draw a triangle with side length .2
    // drawRectangle();
    // drawCircle(.2, -.5, .7);  // draw a circle with radius .2 and center -.5,.7
    // glFlush();   //flush the buffer
    

    // series of drawings WITH ANIMATION
    for (double i = 0, x = -1, y = 1; i<1; i+=.05, x +=.1, y-=.1){
        glClear(GL_COLOR_BUFFER_BIT);  
        drawTriangle(i);        //draw a triangle with side length i
        drawCircle(i/2, x, y);  // draw a circle with radius i/2 and center x,y
        usleep(150000);    //pause slightly so we can see the animation happen  (increase number to slow down animation)
        glFlush();   //flush the buffer
    }
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);   // **experiment with different window sizes by changing these arguments
    glutInitWindowPosition(600, 300);   // **experiment with different window locations by changing these arguments
    glutCreateWindow("Open GL!");   // **try  putting different text in your window display
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    
    return 0;
}