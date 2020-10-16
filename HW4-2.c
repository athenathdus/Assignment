/********************************************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(2)                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 10월 15일                                                      */
/*                                                                                                                                         */
/* 문제 정의 : 방향키를 누르면, 4개의 vertex좌표가 동일하게 왼쪽, 오른쪽, 아래쪽, 위쪽 으로 0.1씩 이동하게
코드를 확장하였다. 주어진 vertex 4개에서 gx,gy 라는 변수를 추가하여 각 키를 누르면 움직이게 만들었고,
if ,else문으로 범위를 지정하여 window화면에서 벗어나지 않게 만들었다.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/
#include <GL/glut.h>
GLfloat gx, gy;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 + gy, 0.0);
    glEnd();
    glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch(key)
        case 'Q':
            exit(1);
}

void MySpecial(int key, int x, int y) { //special key 를 사용하여, 왼쪽, 아래쪽, 오른쪽, 위쪽으로 움직이게 만듦
    switch (key) {
    case GLUT_KEY_PAGE_UP:  //zoomin
        gx = gx + 0.1f;
        gy = gy + 0.1f;
        break;
    case GLUT_KEY_PAGE_DOWN: //zoomout
        gy = gy - 0.1f;
        gx = gx - 0.1f;
        break;
    case GLUT_KEY_UP:  //위쪽
        if (gy >= 0.4)
            gy = gy;
        else
            gy = gy + 0.1f;
        break;

    case GLUT_KEY_DOWN: //아래쪽
        if (gy <= -0.5)
            gy = gy;
        else
            gy = gy - 0.1f;
        break;
    case GLUT_KEY_LEFT: //왼쪽
        if (gx <= -0.5)
            gx = gx;
        else
            gx = gx - 0.1f;
        break;
    case GLUT_KEY_RIGHT:  //오른쪽
        if (gx >= 0.4)
            gx = gx;
        else
            gx = gx + 0.1f;
        break;
    default:
        break;
    }
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Keyboard Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);

    glutMainLoop();
    return 0;
}
