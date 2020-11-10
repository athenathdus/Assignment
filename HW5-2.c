/********************************************************************************************************************/
/*                    HW#5 : 로봇팔 손가락 구현                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 11월 11일                                                     */
/*                                                                                                                                         */
/* 문제 정의 : 손가락 3개를 가진 로봇팔을 제작하는 것이다. 각 손가락 당 관절은 2개 이상으로 구현하였다
* 로봇의 손가락 3개와 관절2개까지 구현하였지만, 1,2,3 키를 누르게 되면 손가락을 접었다 폈다 해야해서 
* 마이키보드 함수를 구현하였지만, 움직이지 않았다. 또 마우스 콜백을 사용해서 회전 및 돌아가기를 해야하지만
* 전에것을 구현하지 못하여 마우스 콜백의 틀만 완성하였다. 할수있는 부분에 있어서는 최선을 다해 구현하였다. 
* 
/*                                                                                             */
/*******************************************************************************************************************/


#include <stdlib.h>
#include <gl/glut.h>

static int shoulder = 0, elbow = 0, hand = 0, finger1 = 0, finger2 = 0, finger3 = 0;
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);	 // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
    glScalef(1.5, 0.4, 1.0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0.0, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
      //  glColor3f(1.0, 1.0, 1.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01, 0.0, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.05, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01,-0.01, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.3, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01, -0.01, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
    glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glutSwapBuffers();

}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {  //마우스 콜백
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        
    }
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {

    }
}

void MyKeyboard(unsigned char key, int x, int y) {  //마이키보드 함수 

    switch (key) {
    case '1':
        finger1 = (finger1 + 5) % 360;
        break;
    case '2':
        finger2 = (finger2 + 5) % 360;
        break;
    case '3':
        finger3 = (finger3 + 5) % 360;
        break;
    
    default:
        break;
    }
  glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);

    glutMainLoop();
    return 0;
}
