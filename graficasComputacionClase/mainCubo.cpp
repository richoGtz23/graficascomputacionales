/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 2017
Autor: A01375051 Luis Ricardo Gutiérrez
*********************************************************/
/*
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>

#include "inputFile.h"
#include "Mesh.h"
#include "Shader.h"
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
Transform _transform4;
Transform _transform5;
Camera _camera;
int cont = 0;

void Initialize() {

	vector<vec3> positions;
	vector<vec3> colors;

	vec3 amarillo = vec3(1.0f, 1.0f, 0.0f);
	vec3 morado = vec3(0.55f, 0.000f, 0.55f);
	vec3 rojo = vec3(1.0f, 0.0f, 0.0f);
	vec3 verde = vec3(0.0f, 1.0f, 0.0f);
	vec3 azul = vec3(0.0f, 0.0f, 1.0f);
	vec3 gris = vec3(0.5f, 0.5f, 0.5f);
	colors.push_back(amarillo);
	colors.push_back(amarillo);
	colors.push_back(amarillo);
	colors.push_back(amarillo);

	colors.push_back(morado);
	colors.push_back(morado);
	colors.push_back(morado);
	colors.push_back(morado);

	colors.push_back(rojo);
	colors.push_back(rojo);
	colors.push_back(rojo);
	colors.push_back(rojo);

	colors.push_back(verde);
	colors.push_back(verde);
	colors.push_back(verde);
	colors.push_back(verde);

	colors.push_back(azul);
	colors.push_back(azul);
	colors.push_back(azul);
	colors.push_back(azul);

	colors.push_back(gris);
	colors.push_back(gris);
	colors.push_back(gris);
	colors.push_back(gris);
	
	vec3 vector1 = vec3(3.0f, 3.0f,3.0f);//+ + +
	vec3 vector2 = vec3(3.0f, 3.0f, -3.0f);// + + -
	vec3 vector3 = vec3(3.0f, -3.0f, -3.0f);// + - -
	vec3 vector4 = vec3(3.0f, -3.0f, 3.0f);// + - +
	vec3 vector5 = vec3(-3.0f, -3.0f, 3.0f);//- - +
	vec3 vector6 = vec3(-3.0f, 3.0f, 3.0f);// - + +
	vec3 vector7 = vec3(-3.0f, 3.0f, -3.0f);//- + -
	vec3 vector8 = vec3(-3.0f, -3.0f, -3.0f);// - - -

	positions.push_back(vector4);//->0 + - +
	positions.push_back(vector1);//->1 + + +
	positions.push_back(vector5);//->2 - - +
	positions.push_back(vector6);//->3 - + +

	positions.push_back(vector3);//->4 + - -
	positions.push_back(vector2);//->5 + + -
	positions.push_back(vector8);//->6 - - -
	positions.push_back(vector7);//->7 - + -

	positions.push_back(vector3);//->8 + - -
	positions.push_back(vector2);//->9 + + -
	positions.push_back(vector4);//->10 + - +
	positions.push_back(vector1);//->11 + + +

	positions.push_back(vector8);//->12 - - -
	positions.push_back(vector7);//->13 - + -
	positions.push_back(vector5);//->14 - - +
	positions.push_back(vector6);//->15 - + +

	positions.push_back(vector1);//->16 + + +
	positions.push_back(vector2);//->17 + + -
	positions.push_back(vector6);//->18 - + +
	positions.push_back(vector7);//->19 - + -

	positions.push_back(vector4);//->20 + - +
	positions.push_back(vector3);//->21 + - -
	positions.push_back(vector5);//->22 - - +
	positions.push_back(vector8);//->23 - - -
												   												   	
	vector<unsigned int> indices = { 
		0, 1, 2, 2, 1, 3,
		4, 5, 6, 6, 5, 7,
		8, 9, 10, 10, 9, 11,
		12, 13, 14, 14, 13, 15,
		16, 17, 18, 18, 17, 19,
		20,21,22,22,21,23,
	};
	mesh.CreateMesh(24);
	mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	mesh.SetIndices(indices, GL_STATIC_DRAW);

	program.CreateProgram();
	program.AttachShader("Default.vert", GL_VERTEX_SHADER);
	program.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	program.SetAttribute(0, "VertexPosition");
	program.SetAttribute(1, "VertexColor");
	program.LinkProgram();

	//_camera.SetOrthographic(6.0f, 1.0f);
	_camera.MoveUp(5,true);
	_camera.MoveForward(25,true);
	_camera.SetRotation(-30.0f,0.0f,0.0f);
}

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cont++;
	if (cont%1550==0) {
		glClearColor(glm::sin(glm::radians(float(cont))), glm::cos(glm::radians(float(cont))), glm::cos(glm::radians(float(cont)))*glm::sin(glm::radians(float(cont))), 0.0f);
	}
	//_camera.MoveForward(0.0001f);
	//_transform.Rotate(0.0f, 0.01f, 0.0f, true);//Rotación Global
	_camera.Rotate(0.0f, 0.005f, 0.0f, true);
	_transform.Rotate(0.0f, 0.0f, 0.02f, true);//Rotación Local
	_transform2.SetScale(12.0f, 0.2f, 12.0f);
	_transform2.SetPosition(0.0f, -5.0f, 0.0f);
	_transform3.SetPosition(20.0f,0.0f,0.0f);
	_transform3.Rotate(0.02f,0.0f,0.0f,true);
	_transform4.SetPosition(-20.0f, 0.0f, 0.0f);
	_transform5.SetPosition(-20.0f, 6.0f, 0.0f);
	_transform4.Rotate(0.0f, 0.02f, 0.0f, true);
	_transform5.Rotate(0.0f, -0.02f, 0.0f, true);
	program.Activate();
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform3.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform4.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform5.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.Deactivate();


	glutSwapBuffers();
}

void Idle() {
	//cuando entra en estado de reposo se vuelve a dibujar
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
	glutCreateWindow("Hello World!");

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
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// Configuración inicial de nuestro programa
	Initialize();
	// Iniciar la aplicación. El Main se pausará en esta línea hasta que se cierre la ventana.
	glutMainLoop();

	return 0;
}*/