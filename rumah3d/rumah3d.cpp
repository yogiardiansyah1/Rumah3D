// Fungsi keyboard -> n. w, a, s, d, 8, 2, 4, 6, 7, 9, 1, 3
// 5 untuk buka pintu 
// n untuk menyalakan tv

#include<windows.h>
#include <glut.h>

int is_depth,p,o;
float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xfar = 0.0f;
float yfar = 0.0f;
float zfar = 0.0f;
bool mouseDown = false;

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void size(int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);

void halaman();
void rumah();
void pintu();
void pagar();
void jendela();
void kasur();
void lemari();
void meja();
void kursi();
void tv();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Yogi Ardiansyah - 672018220");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(size);
    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9);
    glLineWidth(6);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    glRotatef(zrot, 0, 0, 1);
    glTranslatef(xfar, 0, 0);
    glTranslatef(0, yfar, 0);
    glTranslatef(0, 0, zfar);
    
	halaman();
	rumah();
	pintu();
	pagar();
	jendela();
	kasur();
	lemari();
	meja();
	kursi();
	tv();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'n':
	case 'N':
		o+=1;
		display();
		break;
    case '9':
        yfar += 3;
        break;
    case '7':
        yfar -= 3;
        break;
    case '6':
        xfar -= 3;
        break;
    case '4':
        xfar += 3;
        break;
    case '2':
        zfar -= 3;
        break;
    case '8':
        zfar += 3;
        break;
    case 'd':
    case 'D':
        yrot -= 3;
        break;
    case 'a':
    case 'A':
        yrot += 3;
        break;
    case 's':
    case 'S':
        xrot -= 3;
        break;
    case 'w':
    case 'W':
        xrot += 3;
        break;
    case '1':
        zrot += 3;
        break;
    case '3':
        zrot -= 3;
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    }
    display();
}

void size(int w, int h)
{
    if (h == 0)
        h = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, w / h, 5, 500);
    glTranslatef(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}


void halaman()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.2);
	glVertex3f(-200.0, -40.0, -100.0);
	glVertex3f(200.0, -40.0, -100.0);
	glVertex3f(200.0, -40.0, 100.0);
	glVertex3f(-200.0, -40.0, 100.0);
	glEnd();
}

void rumah()
{
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.7, 0.6);
	glVertex3f(-80,-40, 50);
	glVertex3f(-80, 40, 50);
	glVertex3f(80, 40, 50);
	glVertex3f(80, -40, 50);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.7, 0.6);
	glVertex3f(-80.0, -40.0, -50.0);
	glVertex3f(-80.0, 40.0, -50.0);
	glVertex3f(80.0, 40.0, -50.0);
	glVertex3f(80.0,-40.0, -50.0);
	glEnd();

	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.7, 0.6);
	glVertex3f(-80.0, 40.0, 50.0);
	glVertex3f(-80.0, -40.0, 50.0);
	glVertex3f(-80.0, -40.0, -50.0);
	glVertex3f(-80.0, 40.0, -50.0);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.7, 0.6);
	glVertex3f(80.0, 40.0, 50.0);
	glVertex3f(80.0, -40.0, 50.0);
	glVertex3f(80.0, -40.0, -50.0);
	glVertex3f(80.0, 40.0, -50.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.2);
	glVertex3f(-80.0, 40.0, 50.0);
	glVertex3f(80.0, 40.0, 50.0);
	glVertex3f(80.0, 40.0, -50.0);
	glVertex3f(-80.0, 40.0, -50.0);
	glEnd();

	//bawah
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.2);
	glVertex3f(-80.0, -40.0, -50.0);
	glVertex3f(80.0, -40.0, -50.0);
	glVertex3f(80.0, -40.0, 50.0);
	glVertex3f(-80.0, -40.0, 50.0);
	glEnd();

	//atap
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.2, 0.2);
	glVertex3f(0.0, 80.0, 40.0);
	glVertex3f(80.0, 40.0, 50.0);
	glVertex3f(-80.0, 40.0, 50.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.2, 0.2);
	glVertex3f(-80.0, 40.0, 50.0);
	glVertex3f(0.0, 80.0, 40.0);
	glVertex3f(0.0, 80.0, -40.0);
	glVertex3f(-80.0, 40.0, -50.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.2, 0.2);
	glVertex3f(80.0, 40.0, 50.0);
	glVertex3f(0.0, 80.0, 40.0);
	glVertex3f(0.0, 80.0, -40.0);
	glVertex3f(80.0, 40.0, -50.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.2, 0.2);
	glVertex3f(0.0, 80.0, -40.0);
	glVertex3f(80.0, 40.0, -50.0);
	glVertex3f(-80.0, 40.0, -50.0);
	glEnd();
}

void pintu()
{
	if (is_depth == 1)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.8,0.4,0.2);
		glVertex3f(-10,-40, 51);
		glVertex3f(-10, 0, 51);
		glVertex3f(10, 0, 51);
		glVertex3f(10, -40, 51);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.00, 0.00, 0.0);
		glVertex3f(-6,-30, 51);
		glVertex3f(-6, -20, 51);
		glEnd();
	}
	else 
	{
		glBegin(GL_POLYGON);
		glColor3f(0.8,0.4,0.2);
		glVertex3f(-10,-40, 71);
		glVertex3f(-10, 0, 71);
		glVertex3f(10, 0, 51);
		glVertex3f(10, -40, 51);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.00, 0.00, 0.0);
		glVertex3f(-6,-30, 71);
		glVertex3f(-6, -20, 71);
		glEnd();
	}
}

void pagar()
{
	//depan
	for(p=-90;p<=80;p+=10)
	{
		glBegin(GL_POLYGON);
		glColor3f(1.00, 0.30, 0.20);
		glVertex3f(p,-40, 80);
		glVertex3f(p+8, -40, 80);
		glVertex3f(p+8, 0, 80);
		glVertex3f(p+4, 4, 80.0);
		glVertex3f(p, 0, 80);
		glVertex3f(p,-40, 80);
		glEnd();
	}

	//belakang
	for(p=-90;p<=80;p+=10)
	{
		glBegin(GL_POLYGON);
		glColor3f(1.00, 0.30, 0.20);
		glVertex3f(p,-40, -80);
		glVertex3f(p+8, -40, -80);
		glVertex3f(p+8, 0, -80);
		glVertex3f(p+4, 4, -80.0);
		glVertex3f(p, 0, -80);
		glVertex3f(p,-40, -80);
		glEnd();
	}

	//kiri
	for(p=-79;p<=80;p+=10)
	{
		glBegin(GL_POLYGON);
		glColor3f(1.00, 0.30, 0.20);
		glVertex3f(-90,-40, p);
		glVertex3f(-90, -40, p+8);
		glVertex3f(-90, 0, p+8);
		glVertex3f(-90, 4, p+4);
		glVertex3f(-90, 0, p);
		glVertex3f(-90,-40, p);
		glEnd();
	}

	//kanan
	for(p=-79;p<=80;p+=10)
	{
		glBegin(GL_POLYGON);
		glColor3f(1.00, 0.30, 0.20);
		glVertex3f(88,-40, p);
		glVertex3f(88, -40, p+8);
		glVertex3f(88, 0, p+8);
		glVertex3f(88, 4, p+4);
		glVertex3f(88, 0, p);
		glVertex3f(88,-40, p);
		glEnd();
	}
}

void jendela()
{
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(-55, -10, 51);
	glVertex3f(-55, 20, 51);
	glVertex3f(-35, 20, 51);
	glVertex3f(-35, -10, 51);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-55,5, 51);
	glVertex3f(-35,5, 51);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-45, -10, 51);
	glVertex3f(-45, 20, 51);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(55, -10, 51);
	glVertex3f(55, 20, 51);
	glVertex3f(35, 20, 51);
	glVertex3f(35, -10, 51);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(55,5, 51);
	glVertex3f(35,5, 51);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(45, -10, 51);
	glVertex3f(45, 20, 51);
	glEnd();

	//belakang

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(-55, -10, -51);
	glVertex3f(-55, 20, -51);
	glVertex3f(-35, 20, -51);
	glVertex3f(-35, -10, -51);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-55,5, -51);
	glVertex3f(-35,5, -51);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-45, -10, -51);
	glVertex3f(-45, 20, -51);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(55, -10, -51);
	glVertex3f(55, 20, -51);
	glVertex3f(35, 20, -51);
	glVertex3f(35, -10, -51);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(55,5, -51);
	glVertex3f(35,5, -51);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(45, -10, -51);
	glVertex3f(45, 20, -51);
	glEnd();

	//kiri

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(-81, -10, -35);
	glVertex3f(-81, 20, -35);
	glVertex3f(-81, 20, -15);
	glVertex3f(-81, -10, -15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-81,5, -35);
	glVertex3f(-81,5, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-81, -10, -25);
	glVertex3f(-81, 20, -25);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(-81, -10, 35);
	glVertex3f(-81, 20, 35);
	glVertex3f(-81, 20, 15);
	glVertex3f(-81, -10, 15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-81,5, 35);
	glVertex3f(-81,5, 15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-81, -10, 25);
	glVertex3f(-81, 20, 25);
	glEnd();

	//kanan

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(81, -10, -35);
	glVertex3f(81, 20, -35);
	glVertex3f(81, 20, -15);
	glVertex3f(81, -10, -15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(81,5, -35);
	glVertex3f(81,5, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(81, -10, -25);
	glVertex3f(81, 20, -25);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.00, 1.00, 1.0);
	glVertex3f(81, -10, 35);
	glVertex3f(81, 20, 35);
	glVertex3f(81, 20, 15);
	glVertex3f(81, -10, 15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(81,5, 35);
	glVertex3f(81,5, 15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(81, -10, 25);
	glVertex3f(81, 20, 25);
	glEnd();
}

void kasur()
{
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-70.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, 10.0);
	glVertex3f(-70.0, -40.0, 10.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-70.0, -30.0, -40.0);
	glVertex3f(-40.0, -30.0, -40.0);
	glVertex3f(-40.0, -30.0, 10.0);
	glVertex3f(-70.0, -30.0, 10.0);
	glEnd();

	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-70.0, -30.0, 10.0);
	glVertex3f(-40.0, -30.0, 10.0);
	glVertex3f(-40.0, -40.0, 10.0);
	glVertex3f(-70.0, -40.0, 10.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-70.0, -30.0, -40.0);
	glVertex3f(-40.0, -30.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-70.0, -40.0, -40.0);
	glEnd();

	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-70.0, -30.0, -40.0);
	glVertex3f(-70.0, -40.0, -40.0);
	glVertex3f(-70.0, -40.0, 10.0);
	glVertex3f(-70.0, -30.0, 10.0);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-40.0, -30.0, -40.0);
	glVertex3f(-40.0, -40.0, -40.0);
	glVertex3f(-40.0, -40.0, 10.0);
	glVertex3f(-40.0, -30.0, 10.0);
	glEnd();
}

void lemari()
{
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(-20.0, -40.0, -40.0);
	glVertex3f(20.0, -40.0, -40.0);
	glVertex3f(20.0, 10.0, -40.0);
	glVertex3f(-20.0, 10.0, -40.0);
	glEnd();

	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(-20.0, -40.0, -30.0);
	glVertex3f(20.0, -40.0, -30.0);
	glVertex3f(20.0, 10.0, -30.0);
	glVertex3f(-20.0, 10.0, -30.0);
	glEnd();

	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(-20.0, -40.0, -30.0);
	glVertex3f(-20.0, 10.0, -30.0);
	glVertex3f(-20.0, 10.0, -40.0);
	glVertex3f(-20.0, -40.0, -40.0);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(20.0, -40.0, -30.0);
	glVertex3f(20.0, 10.0, -30.0);
	glVertex3f(20.0, 10.0, -40.0);
	glVertex3f(20.0, -40.0, -40.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(20.0, -40.0, -30.0);
	glVertex3f(20.0, -40.0, -40.0);
	glVertex3f(-20.0, -40.0, -40.0);
	glVertex3f(-20.0, -40.0, -30.0);
	glEnd();

	//bawah
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.2,0.2);
	glVertex3f(20.0, 10.0, -30.0);
	glVertex3f(20.0, 10.0, -40.0);
	glVertex3f(-20.0, 10.0, -40.0);
	glVertex3f(-20.0, 10.0, -30.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(0,10, -30);
	glVertex3f(0,-40, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(5,-10, -30);
	glVertex3f(5,-20, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(-5,-10, -30);
	glVertex3f(-5,-20, -30);
	glEnd();
}

void kursi ()
{
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(30,-40, -30);
	glVertex3f(30,-20, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(50,-40, -30);
	glVertex3f(50,-20, -30);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(30,-40, -10);
	glVertex3f(30,-20, -10);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(50,-40, -10);
	glVertex3f(50,-20, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -20.0, 10.0);
	glVertex3f(50.0, -20.0, 10.0);
	glVertex3f(50.0, -20.0, 30.0);
	glVertex3f(30.0, -20.0, 30.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, 10.0, 30.0);
	glVertex3f(50.0, 10.0, 30.0);
	glVertex3f(50.0, -20.0, 30.0);
	glVertex3f(30.0, -20.0, 30.0);
	glEnd();
}

void meja()
{
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(30,-40, 10);
	glVertex3f(30,-20, 10);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(50,-40, 10);
	glVertex3f(50,-20, 10);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(30,-40, 30);
	glVertex3f(30,-20, 30);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(50,-40, 30);
	glVertex3f(50,-20, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -20.0, -30.0);
	glVertex3f(50.0, -20.0, -30.0);
	glVertex3f(50.0, -20.0, -10.0);
	glVertex3f(30.0, -20.0, -10.0);
	glEnd();
}

void tv()
{
	if (o%2 == 0)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 20.0, -20.0);
	glVertex3f(60.0, 20.0, -20.0);
	glVertex3f(60.0, -10.0, -20.0);
	glVertex3f(20.0, -10.0, -20.0);
	glEnd();
	}
	else
	{
		glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 20.0, -20.0);
	glVertex3f(60.0, 20.0, -20.0);
	glVertex3f(60.0, -10.0, -20.0);
	glVertex3f(20.0, -10.0, -20.0);
	glEnd();
	}

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 20.0, -20.0);
	glVertex3f(60.0, 20.0, -20.0);
	glVertex3f(60.0, -10.0, -20.0);
	glVertex3f(20.0, -10.0, -20.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(40,-10,-20);
	glVertex3f(40,-20, -20);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.00, 0.00, 0.0);
	glVertex3f(35,-20,-20);
	glVertex3f(45,-20,-20);
	glEnd();
}