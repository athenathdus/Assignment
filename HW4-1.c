/********************************************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(1)                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 10월 15일                                                      */
/*                                                                                                                                         */
/* 문제 정의 : 키를 누르면, 4개의 vertex좌표가 동일하게 왼쪽, 오른쪽, 아래쪽, 위쪽 으로 0.1씩 이동하게
코드를 확장하였다. 주어진 vertex 4개에서 gx,gy 라는 변수를 추가하여 각 키를 누르면 움직이게 만들었고,
색상은 RGB를 사용하여 빨간색은 (1,0,0), 파란색은 (0,0,1) 이 되도록 변수를 추가하여 조정하였다.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/

#include <GL/glut.h>
GLfloat gx, gy, c, d, e; //변수 gx,gy,c,d,e를 선언


void MyDisplay() {  // vertex에 gx,gy 변수를 추가하여 mykeyboard 에서 쉽게 사용할 수 있도록 만듦
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5+c, 0.5+d, 0.5+e);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + gx, -0.5 - gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 - gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 - gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 - gy, 0.0);
    glEnd();
    glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) { 

    switch (key) {
    case 'a':case 'A': // 4 개의 vertex 좌표가 동일하게 왼쪽으로 0.1 씩 이동
        gx = gx - 0.1f;
        break;

    case 'f': case 'F': // 4 개의 vertex 좌표가 동일하게 오른쪽으로 0.1 씩 이동
        gx = gx + 0.1f;
        break;

    case 'r': case 'R': //4 개의 vertex 좌표가 동일하게 아래쪽으로 0.1 씩 이동하고 빨간색으로 Polygon 칠함
        c = c + 0.5;
        d = d - 0.5;
        e = e - 0.5;
       
        gy = gy - 0.1f;
        break;

    case 'v': case 'V': // 4 개의 vertex 좌표가 동일하게 위쪽으로 0.1 씩 이동
       
        gy = gy + 0.1f;
        break;

    case 'b':  // 파란색으로 Polygon 칠함
        c = c - 0.5;
        d = d - 0.5;
        e = e + 0.5;
        break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        break;
    case GLUT_KEY_LEFT:
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
