/*********************************************************
Materia: Gráficas Computacionales
Fecha: 23 de Octubre del 2017
Autor: A01370699 Abraham Soto
Autor: A01376121 Luis Ricardo Gutierrez
*********************************************************//*
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>

#include "inputFile.h"
#include "Mesh.h"
#include "shader.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"
using namespace std;
using namespace glm;

Mesh mesh;
ShaderProgram program;
Transform _transform;
Transform _transform2;
Transform _transform3;
Camera _camera;
float deg = 0.0f;
float scala = 0.5f;
int creciendo = 1;

void Initialize() {

	vector<vec3> positions;
	vector<vec3> colors;

	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));

	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));


	vector<unsigned int> indices = {
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 1,
		1, 3, 2, 4, 3, 1
	};

	mesh.CreateMesh(5);
	mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	mesh.SetIndices(indices, GL_STATIC_DRAW);

	program.CreateProgram();
	program.AttachShader("Default.vert", GL_VERTEX_SHADER);
	program.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	program.SetAttribute(0, "VertexPosition");
	program.SetAttribute(1, "VertexColor");
	program.LinkProgram();
	_camera.MoveForward(0.0f);
	_camera.SetPosition(0, 0, 25);
	_transform.SetScale(3, 3, 3);
}

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.01f, 0.01f, 0.01f, true);
	deg += .01;
	_transform.SetPosition(5 * glm::cos(glm::radians(deg)), 5 * glm::sin(glm::radians(deg)), 0.0f);

	_transform2.Rotate(-0.01f, -0.01f, -0.01f, true);
	_transform2.SetScale(scala, scala, scala);

	if (scala >= 1.0f) {
		creciendo = 0;
	}
	else if (scala <= 0.25f) {
		creciendo = 1;
	}

	if (creciendo == 0) {
		scala -= 0.0001f;
	}
	else if (creciendo == 1) {
		scala += 0.0001f;
	}



	program.Activate();

	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);

	//program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	//mesh.Draw(GL_TRIANGLES)

	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);



	program.Deactivate();


	glutSwapBuffers();
}

void Idle() {
	glutPostRedisplay();
}

void ReshapeWindow(int w, int h) {
	glViewport(0, 0, w, h);

}

int main(int argc, char* argv[]) {
	// Inicializar freeglut
	// Freeglut se encargfa de crear una ventana en donde podemos dibujar Gráficas Computacionales
	glutInit(&argc, argv);
	glutInitContextVersion(4, 2);


	// Iniciar el contexto de OpenGL, se refiere a las capacidades de la aplicación gráfica
	// En este caso se trabaja con el pipeline progamable
	glutInitContextProfile(GLUT_CORE_PROFILE);

	// Freeglut nos permite configurar eventos que ocurren en la ventana
	// Un evento que interesa es cuando alguien cierra la ventana
	// En este caso, se deja de renderear la escena y se termina el programa
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// También configuramos frambuffer, en este caso solicitamos un buffer
	// true color RGBA, un buffer de produndidad y un segundo buffer para renderear
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); // Dos framebuffers

															   // Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);

	// Creeamos la ventana y le damos un título.
	glutCreateWindow("Hello World OpenGL!");

	glutDisplayFunc(GameLoop);
	//asociamos una función ara el cambio de resolucion de la ventana.
	//freeglut la va a mandar a llamar 
	//cuando alguien cambie el tamaño de la ventana
	glutReshapeFunc(ReshapeWindow);

	//asociamos la función cuando openGL entra en estado de reposos
	glutIdleFunc(Idle);
	// Inicializamos GLEW. Esta librería se encarga de obtener el API de OpenGL de nuestra tarjeta de video
	glewInit();
	glClearColor(1.0f, 1.0f, 3.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	std::cout << glGetString(GL_VERSION) << std::endl;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Configuración inicial de nuestro programa
	Initialize();
	// Iniciar la aplicación. El Main se pausará en esta línea hasta que se cierre la ventana.
	glutMainLoop();

	return 0;
}*/