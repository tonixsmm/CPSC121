/* To download openGL on your VM, run:
    $ sudo apt update
    $ sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev
   After install, you may need to restart your VM.
*/

//compile with:  g++ openGLdemo2.cpp -lglut -lGLU -lGL

#include <GLUT/glut.h>   //see codebind.com/linux-tutorials/install-opengl-ubuntu-linux
#include <cmath>  // sin(), cos(), M_PI
using namespace std;

// function to draw a triangle (color and location determined inside function)
void drawTriangle(void){

    glBegin(GL_POLYGON); //begin drawing this vertex figure
    glColor3f(1.0, 1.0, 0.0);   // ***experiment with colors by changing one or more of these arguments

    // the two arguments in each glVertex2f() call are the x and y coordinate of a point
    // here we are creating our triangle based on connecting these three points:
    glVertex2f(0.5, 0.0);    //vertex one
    glVertex2f(0.0, 0.0);    //vertex two    //note that this vertex is at the origin
    glVertex2f(0.0, 0.5);    //vertex three

    glEnd(); //end drawing this vertex figure
}

// function to draw a rectangle (color and location determined inside function)
void drawRectangle(void){
    
    glBegin(GL_POLYGON); //begin drawing this vertex figure
    glColor3f(1.0, 1.0, 1.0);   // ***experiment with colors by changing one or more of these arguments

    // the two arguments in each glVertex2f() call are the x and y coordinate of a point
    // here we are creating our rectangle based on connecting four points:
    // ***choose the four vertices of the rectangle
    glVertex2f(0.5, 0.0);    //vertex one
    glVertex2f(0.0, 0.0);    //vertex two    //note that this vertex is at the origin
    glVertex2f(0.0, 0.5);
    glVertex2f(0.5, 0.5);

    glEnd(); //end drawing this vertex figure
}

// function to draw a hexagon (color and location determined inside function)
void drawHexagon(void){
    
    glBegin(GL_POLYGON); //begin drawing this vertex figure
    glColor3f(1.0, 0.0, 1.0);   // **experiment with colors by changing one or more of these arguments

    // here we are creating our hexagon based on connecting these six points:
    glVertex2f(-0.2, 0.1);   
    glVertex2f(-0.35, 0.1);  
    glVertex2f(-0.4, 0.25);    
    glVertex2f(-0.35, 0.4);    
    glVertex2f(-0.2, 0.4);     
    glVertex2f(-0.15, 0.25);    
    // *** try changing the shape of the hexagon by shifting the values in the vertices

    glEnd(); //end drawing this vertex figure
}

// function to draw a perfectly regular hexagon at a specified location
void drawBetterHexagon(double x, double y){
    //center of hexagon is located at x, y
    glBegin(GL_POLYGON);  //begin drawing this vertex figure
    glColor3f(1.0, 0.0, 0.0);   // what color does this seem to produce?

    for(double i = 0; i < 2 * M_PI; i += M_PI/3){   //this loop will produce a series of triangles that form the hexagon
        // each triangle produces M_PI/3 (or 60 degrees) of the hexagon
        glVertex2f(x, y);
        glVertex2f(x + cos(i), y + sin(i));
        glVertex2f(x + cos(i + M_PI/3), y + sin(i + M_PI/3));
    }

    glEnd();  //end drawing this vertex figure 
}
// ***How can I adjust the SIZE of this hexagon???


//this is the primary display function, which controls what will end up being displayed
void myDisplay(void){

    glClearColor(0, 0, 0, 1); // setting the background color of the window  
            //***experiment with different arguments in FIRST THREE POSITIONS (last one is opacity/intensity)
    glClear(GL_COLOR_BUFFER_BIT); 

    drawTriangle();        //draw a triangle by calling the drawTriangle() function
    drawRectangle();  //***you need to finish the drawRectangle() function
    drawHexagon();
    drawBetterHexagon(0, 0); //draw our improved hexagon centered at these coordinates
    
    glFlush();   //flush buffer so rendering is immediate
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);   // **experiment with different window sizes by changing these arguments
    glutInitWindowPosition(600, 300);   // **experiment with different window locations by changing these arguments
    glutCreateWindow("C++ Rocks!");   // **try putting different text in your window display
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    
    return 0;
}