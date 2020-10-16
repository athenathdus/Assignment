/********************************************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - ldle콜백(1)                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 10월 15일                                                      */
/*                                                                                                                                         */
/* 문제 정의 : 방향키를 누르면, 4개의 vertex좌표가 동일하게 왼쪽, 오른쪽, 아래쪽, 위쪽 으로 0.1씩 이동하게
코드를 확장하였다. 주어진 vertex 4개에서 gx,gy 라는 변수를 추가하여 각 키를 누르면 움직인다. Idle콜백과
special key를 사용하여 구현하였다. 
/*                                                                                                                  */
/*******************************************************************************************************************/


#include <GL/glut.h>

GLfloat Delta = 0.0;
GLfloat gx = 0;
GLfloat gy = 0; //gx,gy 변수 
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.8);  //네 vertex 정의
    glVertex3f(-0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 + gy, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyIdle1() {  //idle 1 (오른쪽 이동)
  
          if(gx<0.5)
              gx = gx + 0.01f;

    glutPostRedisplay();
}
void MyIdle2() {  //idle 2 (위쪽 이동)

    if(gy<0.5)
        gy = gy + 0.01f;

    glutPostRedisplay();
}
void MyIdle3() {  //idle 3 (아래쪽 이동)
    if (gy>-0.5)
        gy = gy - 0.01f;

    glutPostRedisplay();
} 
void MyIdle4() { //idle 4 (왼쪽 이동)
    if(gx>-0.5)
        gx = gx - 0.01f;
    glutPostRedisplay();
}
void MySpecial(int key, int x, int y) { //special key 를 사용하여, 왼쪽, 아래쪽, 오른쪽, 위쪽으로 움직이게 만듦
    switch (key) {
    
    case GLUT_KEY_UP:  //위쪽
        glutIdleFunc(MyIdle2);
        break;
    case GLUT_KEY_DOWN: //아래쪽
        glutIdleFunc(MyIdle3);
        break;
    case GLUT_KEY_LEFT: //왼쪽
        glutIdleFunc(MyIdle4);
        break;
    case GLUT_KEY_RIGHT:  //오른쪽
        glutIdleFunc(MyIdle1);
        break;
    default:
        break;
    }
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
    glutCreateWindow("Idle Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(MySpecial); //myspecial을 불러 idle callback 사용함 
    glutMainLoop();
    return 0;
}
