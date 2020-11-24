/********************************************************************************************************************/
/*             HW#7 : 뷰폿 분할응용                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 11월 24 일                                                     */
/*                                                                                                                                         */
/* 문제 정의 : 코드 7-2를 참조하여 2개이상의 물체를 한 뷰폿에 그렸다. 하나의 윈도우를 4개의
* 뷰폿으로 분할하였으며 우상단 뷰폿은 gluPerspective함수를 사용하여 원근투영하였고, 좌하단의 뷰폿은
* glOrtho 함수를 사용하여 평행투영 하였다. 키보드 콜백을 사용하여 glLookup에 ex,ey,ez,px,py,pz등의
* 변수를 추가하여 올바른 키를 누르면 카메라의 위치가 증가하거나 감소하도록 조정하였다.
* 다음으로 마우스 콜백을 사용하여 아이들을 불러오고, 아이들을 사용하여 연속적으로 증가 또는 감소하도록 하였다. 
/*                                                                                             */
/*******************************************************************************************************************/
#include <GL/glut.h>

int Width, Height;
float ex, ey, ez, px, py, pz;
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawScene() {
    glColor3f(0.5, 0.5, 1.0);
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, 2.0);
    glEnd();
    glPopMatrix();

    glColor3f(0.1, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.5);
    glutWireTeapot(1.0);
    glPopMatrix();
}

void MyDisplay() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glViewport(0, 0, Width / 2, Height / 2);  //좌하단 (평행투영 glOrtho)
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-3.6, 3.6, -2.7, 2.7, 5, 19.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(0.0 + ex, 3.0 + ey, 5.0 + ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();

    glViewport(Width / 2, Height / 2, Width / 2, Height / 2);   //우상단 (원근투영 gluPerspective)
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPerspective(28, 800.0 / 600.0, 5.0, 19.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(5.0 + px, 5.0 + py, 5.0 + pz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h) {
    Width = w;
    Height = h;
}



void MyKeyboard(unsigned char key, int x, int y) {  //해당 문자를 눌렀을때 증가 및 감소
    switch (key) {
    case 'a':case 'A':
        ex = ex + 0.2f;
        px = px + 0.2;
        break;

    case 'f': case 'F':
        ey = ey + 0.2f;
        py = py + 0.2;
        break;

    case 'z': case 'Z':
        ez = ez + 0.2f;
        pz = pz + 0.2f;
        break;

    case 'd':case 'D':
        ex = ex - 0.2f;
        px = px - 0.2;
        break;

    case 'g': case 'G':
        ey = ey - 0.2f;
        py = py - 0.2f;
        break;

    case 't': case 'T':
        ez = ez - 0.2f;
        pz = pz - 0.2f;
        break;
        glutPostRedisplay();
    }

    glutPostRedisplay();
}

void MyIdleax() {  //아이들 사용하여 연속적으로 증가 
    ex = ex + 0.1f;
    px = px + 0.1f;

    glutPostRedisplay();
}
void MyIdleax2() {  //아이들 사용하여 연속적으로 감소 
    ex = ex - 0.1f;
    px = px - 0.1f;
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {  //마우스콜백함수
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        glutIdleFunc(MyIdleax);
    }
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        glutIdleFunc(MyIdleax2);
    }
}


int main(int argc, char** argv) {
    Width = 500;
    Height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(0, 0);
    glutInit(&argc, argv);
    glutCreateWindow("Viewpory Partition");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);  //myKeyboard 추가
    glutMouseFunc(MyMouseClick);
    glutMainLoop();
    return 0;
}

