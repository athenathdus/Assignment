/********************************************************************************************************************/
/*             HW#5 :  gluLookAt()의 실시간제어                                                              */
/*  작성자 : 박소연                              날짜 : 2020년 11월 10일                                                     */
/*                                                                                                                                         */
/* 문제 정의 : 시점 좌표계를 키보드 콜백 함수로 실시간 제어가 가능하도록 구현하는 것이다.
* glLookAt()함수의 인자를 float 변수 ax,ay,az,ex,ey를 사용하여 더해 0.1 씩 증가할 수 있도록 만들었다.
* 마이키보드와 마이 스폐셜 함수를 통해 방향키와 특정 문자를 누르면 증가 또는 감소 할 수 있도록 하였다.
/*                                                                                             */
/*******************************************************************************************************************/

#include <GL/glut.h>

void DrawGround() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -0.71, 2.0);
    glVertex3f(2.0, -0.71, 2.0);
    glVertex3f(2.0, -0.71, -2.0);
    glVertex3f(-2.0, -0.71, -2.0);
    glEnd();

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
    for (float x = -2.0; x <= 2.2; x += 0.2) {
        glVertex3f(x, -0.7, -2.0);
        glVertex3f(x, -0.7, 2.0);
    }

    for (float z = -2.0; z <= 2.2; z += 0.2) {
        glVertex3f(-2.0, -0.7, z);
        glVertex3f(2.0, -0.7, z);
    }
    glEnd();
}

float ex, ey, ax, ay, az; //float 변수 선언

void MyDisplay() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0 + ex, 3.5 + ey, 3.5, 0.0 + ax, 0.0 + ay, 0.0 + az, 0.0, 1.0, 0.0);  //gluLookAt()함수에 선언한 float 변수들을 더함

    //gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    DrawGround();

    glColor3f(1.0, 1.0, 0.0);
    glutWireTeapot(1.0);

    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

// 타이머 콜백을 사용하여 연속적으로 0.1 씩 증가 또는 감소 하게 만들었음

void MyIdleax() {
    ax = ax + 0.1f;

    glutPostRedisplay();
}
void MyIdleax2() {
    ax = ax - 0.1f;

    glutPostRedisplay();
}
void MyIdleay() {
    ay = ay + 0.1f;

    glutPostRedisplay();
}
void MyIdleay2() {
    ay = ay - 0.1f;

    glutPostRedisplay();
}
void MyIdleaz() {
    az = az + 0.1f;

    glutPostRedisplay();
}
void MyIdleaz2() {
    az = az - 0.1f;

    glutPostRedisplay();
}
void MyIdleex() {
    ex = ex + 0.1f;

    glutPostRedisplay();
}
void MyIdleex2() {
    ex = ex - 0.1f;

    glutPostRedisplay();
}
void MyIdleey() {
    ey = ey + 0.1f;

    glutPostRedisplay();
}
void MyIdleey2() {
    ey = ey - 0.1f;

    glutPostRedisplay();
}

//void MyTimerax(int Value) {
//    ax = ax + 0.1f;
//
//    glutPostRedisplay();
//    glutTimerFunc(40, MyTimerax, 1);
//}
void MyTimerax2(int Value) {
    ax = ax - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerax2, 1);
}
void MyTimeray(int Value) {
    ay = ay + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeray, 1);
}
void MyTimeray2(int Value) {
    ay = ay - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeray2, 1);
}
void MyTimeraz(int Value) {
    az = az + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeraz, 1);
}
void MyTimeraz2(int Value) {
    az = az + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeraz2, 1);
}

void MyTimerey(int Value) {
    ey = ey + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerey, 1);
}
void MyTimerey2(int Value) {
    ey = ey - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerey2, 1);
}
void MyTimerex(int Value) {
    ex = ex + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerex, 1);
}
void MyTimerex2(int Value) {
    ex = ex - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerex2, 1);
}
void MyTimer(int Value) {
    ax = ax + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}


void MyKeyboard(unsigned char key, int x, int y) {  //해당 문자를 눌렀을때 타이머를 부름 

    switch (key) {
    case 'a':case 'A':
        glutIdleFunc(MyIdleax);
        break;

    case 'f': case 'F':
        glutIdleFunc(MyIdleax2);
        break;

    case 'r': case 'R':
        glutIdleFunc(MyIdleay);
        break;

    case 'v': case 'V':
        glutIdleFunc(MyIdleay2);
        break;

    case 'z': case 'Z':
        glutIdleFunc(MyIdleaz);
        break;

    case 't': case 'T':
        glutIdleFunc(MyIdleaz2);
        break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {  //방향키를 눌렀을때 타이머콜백을 부름
    switch (key) {
    case GLUT_KEY_UP:
        glutIdleFunc(MyIdleey);
        break;
    case GLUT_KEY_DOWN:
        glutIdleFunc(MyIdleey2);
        break;
    case GLUT_KEY_LEFT:
        glutIdleFunc(MyIdleex2);
        break;
    case GLUT_KEY_RIGHT:
        glutIdleFunc(MyIdleex);
        break;

    default:
        break;
    } glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("VCS (View Coordinate System)");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutSpecialFunc(MySpecial); //mySpecial 추가
    glutKeyboardFunc(MyKeyboard);  //myKeyboard 추가
    
    glutMainLoop();
    return 0;
}