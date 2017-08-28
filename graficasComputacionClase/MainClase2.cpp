/*#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//OPEN GL VIEJITO SOLO ESTA CLASE
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f,-1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	glutSwapBuffers();
}

int triangulo(int argc, char* argv[]) {
	//inicializar freeglut
	glutInit(&argc,argv);

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	//FREEGLUT NOS PERMITE CONFIGRUAR EVETNOS QUE OCURREN EN LA VENTANA
	//EJ: cuando alguien cierra la ventana, stop render->close window
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World GL");
	glutDisplayFunc(GameLoop);
	glewInit();

	glClearColor(1.0f,1.0f,0.5f,1.0f);

	glutMainLoop();
    return 0;
}*/