/********************************************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 타이머콜백(1)                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 10월 15일                                                      */
/*                                                                                                                                         */
/* 문제 정의 : 도형이 흰색부터 검은색까지 15가지 다영한 색깔로 바뀌도록 함.
/* timer callback을 사용하여 계속 반복되게 만들었고, timer callback이 불릴때마다 색변수에 gx,gy,gz를 더하여,
   색이 계속 바뀌도록 만들었다.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/

#include <gl/glut.h>

GLfloat Delta = 0.0;
GLfloat gx, gy, gz;  //float변수 gx,gy,gz를 선언
int key;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0 - gx, 1.0 - gy, 1.0-gz);  //색 변화를 위해, 1.0에서 gx,gy,gz를 뺄수 있도록 정의
    glVertex3f(-1.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}
void MyTimer(int Value) {

    gx += 0.05;   //gx가 0.05 더해지게 만듦.
    gy += 0.05;   //gy가 0.05 더해지게 만듦.
    gz += 0.05;   //gz가 0.05 더해지게 만듦.
    //
    glutPostRedisplay();
    glutTimerFunc(500, MyTimer, 1);
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Timer Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(1000, MyTimer, 1);

    glutMainLoop();
    return 0;
}
