/********************************************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 메뉴콜백(1)                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 10월 15일                                                      */
/*                                                                                                                                         */
/* 문제 정의 : 주 메뉴는 총 다섯개로, Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit 가 있다.
그 아래 submenu로 각각 small, large버전이 있으며, change color 메뉴로 red,green, blue 가 있다.
색은 color변수를 사용하여 누르면 각각 r,g,b 색으로 바뀌게 만들었으며, submenu들은 glutaddsubmenu를
사용하여 만들었다. mydisplay에 if문을 사용하여 sphere,torus,teapot,small 등의 구체적인 정보를 기입하였고,
4개의 메뉴를 만들고, myinit에 넣어주었다. 
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/
#include <GL/glut.h>

GLboolean IsSphere = 1;  //sphere,torus,teapot,issmall 를 선언
GLboolean IsTorus = 1;
GLboolean IsTeapot = 1;
GLboolean IsSmall = 1;

GLfloat color1 = 0;  // r,g,b 색 지정을 위한 변수 선언
GLfloat color2 = 0;
GLfloat color3 = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(color1, color2, color3);

    if ((IsSphere) && (IsSmall) && (!IsTorus) && (!IsTeapot))  //sphere 이 small 일때 
        glutWireSphere(0.5, 30, 30);
    else if ((IsSphere) && (!IsSmall) && (!IsTorus) && (!IsTeapot))  //sphere 이 big 일때 
        glutWireSphere(0.7, 30, 30);
    else if ((IsTorus) && (IsSmall) && (!IsSphere) && (!IsTeapot))  //Torus 가 small 일때 
        glutWireTorus(0.1, 0.3, 40, 20);
    else if ((IsTorus) && (!IsSmall) && (!IsSphere) && (!IsTeapot))  //Torus 가 big 일때 
        glutWireTorus(0.2, 0.5, 40, 20);
    else if ((IsTeapot) && (!IsSmall) && (!IsSphere) && (!IsTorus))  //Teapot 이 big 일때 
        glutWireTeapot(0.5); 
    else //Teapot 이 small 일때 
        glutWireTeapot(0.3);

    glFlush();
}


void MyMainMenu(int entryID) {  //exit를 위한 mainmenu

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

    GLint MySphere = glutCreateMenu(MySphereMenu);  //sphere의 submenu 생성
    glutAddMenuEntry("Small Sphere", 1);
    glutAddMenuEntry("Large Sphere", 2);

    GLint MyTorus = glutCreateMenu(MyTorusMenu);  //torus의 submenu 생성
    glutAddMenuEntry("Small Torus", 1);
    glutAddMenuEntry("Large Torus", 2);

    GLint MyTeapot = glutCreateMenu(MyTeapotMenu);  //teapot의 submenu 생성
    glutAddMenuEntry("Small Teapot", 1);
    glutAddMenuEntry("Large Teapot", 2);

    GLint MyColor = glutCreateMenu(MyColorMenu);  //color의 submenu 생성
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    // 색을 누르고, 마우스를 한번 클릭하게 되면 색 변함 **

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
