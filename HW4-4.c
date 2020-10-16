/********************************************************************************************************************/
/*             HW#4 : Callback ���α׷���  - �޴��ݹ�(1)                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 10�� 15��                                                      */
/*                                                                                                                                         */
/* ���� ���� : �� �޴��� �� �ټ�����, Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit �� �ִ�.
�� �Ʒ� submenu�� ���� small, large������ ������, change color �޴��� red,green, blue �� �ִ�.
���� color������ ����Ͽ� ������ ���� r,g,b ������ �ٲ�� ���������, submenu���� glutaddsubmenu��
����Ͽ� �������. mydisplay�� if���� ����Ͽ� sphere,torus,teapot,small ���� ��ü���� ������ �����Ͽ���,
4���� �޴��� �����, myinit�� �־��־���. 
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/
#include <GL/glut.h>

GLboolean IsSphere = 1;  //sphere,torus,teapot,issmall �� ����
GLboolean IsTorus = 1;
GLboolean IsTeapot = 1;
GLboolean IsSmall = 1;

GLfloat color1 = 0;  // r,g,b �� ������ ���� ���� ����
GLfloat color2 = 0;
GLfloat color3 = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(color1, color2, color3);

    if ((IsSphere) && (IsSmall) && (!IsTorus) && (!IsTeapot))  //sphere �� small �϶� 
        glutWireSphere(0.5, 30, 30);
    else if ((IsSphere) && (!IsSmall) && (!IsTorus) && (!IsTeapot))  //sphere �� big �϶� 
        glutWireSphere(0.7, 30, 30);
    else if ((IsTorus) && (IsSmall) && (!IsSphere) && (!IsTeapot))  //Torus �� small �϶� 
        glutWireTorus(0.1, 0.3, 40, 20);
    else if ((IsTorus) && (!IsSmall) && (!IsSphere) && (!IsTeapot))  //Torus �� big �϶� 
        glutWireTorus(0.2, 0.5, 40, 20);
    else if ((IsTeapot) && (!IsSmall) && (!IsSphere) && (!IsTorus))  //Teapot �� big �϶� 
        glutWireTeapot(0.5); 
    else //Teapot �� small �϶� 
        glutWireTeapot(0.3);

    glFlush();
}


void MyMainMenu(int entryID) {  //exit�� ���� mainmenu

    if (entryID == 5)       exit(0);

    glutPostRedisplay();
}

void MyColorMenu(int entryID) {  //color menu 

    if (entryID == 1) { color1 = 1; color2 = 0; color3 = 0; }
    else if (entryID == 2) { color1 = 0; color2 = 1; color3 = 0; }
    else if (entryID == 3) { color1 = 0; color2 = 0; color3 = 1; }
}
void MySphereMenu(int entryID) {  //sphere menu
    IsSphere = 1; IsTorus = 0; IsTeapot = 0;
    if (entryID == 1)  IsSmall = 1;
    else if (entryID == 2)  IsSmall = 0;

    glutPostRedisplay();
}
void MyTorusMenu(int entryID) {  //torus menu
    IsSphere = 0; IsTorus = 1; IsTeapot = 0;
    if (entryID == 1)  IsSmall = 1;
    else if (entryID == 2) IsSmall = 0;

    glutPostRedisplay();
}
void MyTeapotMenu(int entryID) {  //teapot menu
    IsSphere = 0; IsTorus = 0; IsTeapot = 1;
    if (entryID == 1)  IsSmall = 1;
    else if (entryID == 2)  IsSmall = 0;

    glutPostRedisplay();
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySphere = glutCreateMenu(MySphereMenu);  //sphere�� submenu ����
    glutAddMenuEntry("Small Sphere", 1);
    glutAddMenuEntry("Large Sphere", 2);

    GLint MyTorus = glutCreateMenu(MyTorusMenu);  //torus�� submenu ����
    glutAddMenuEntry("Small Torus", 1);
    glutAddMenuEntry("Large Torus", 2);

    GLint MyTeapot = glutCreateMenu(MyTeapotMenu);  //teapot�� submenu ����
    glutAddMenuEntry("Small Teapot", 1);
    glutAddMenuEntry("Large Teapot", 2);

    GLint MyColor = glutCreateMenu(MyColorMenu);  //color�� submenu ����
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    // ���� ������, ���콺�� �ѹ� Ŭ���ϰ� �Ǹ� �� ���� **

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("Draw Sphere", MySphere);
    glutAddSubMenu("Draw Torus", MyTorus);
    glutAddSubMenu("Draw Teapot", MyTeapot);
    glutAddSubMenu("Change Color", MyColor);
    glutAddMenuEntry("Exit", 5);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Menu Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);

    glutMainLoop();
    return 0;
}
