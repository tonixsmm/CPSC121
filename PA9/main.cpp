#include "PA9.h"

int main (int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(600, 300);
    glutCreateWindow("Connect Four");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}