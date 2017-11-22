/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 2017
Autor: A01376121 Luis Ricardo Gutiérrez
Autor: A01374637 Josep Romagosa 
*********************************************************/
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
#include <IL/il.h>
#include "Texture2D.h"
#include "Depthbuffer.h"

using namespace std;
using namespace glm;

Mesh mesh;
ShaderProgram program;
ShaderProgram program2;
ShaderProgram program3;
Transform _transform;
Transform _transform2;
Camera _camera;
Camera _camera2;
//int cont = 0;
mat4 modelMatrix;
mat3 normalMatrix;
mat4 modelMatrix2;
mat3 normalMatrix2;
vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
vec3 lightPosition = vec3(-20.0f, -1.0f, 30.0f);
vec3 lightPosition2 = vec3(0.0f, 20.0f, 0.0f);
Texture2D crate;
Texture2D cerdo;
Texture2D base;
Depthbuffer depth;

void Initialize() {

	vector<vec3> positions;
	vector<vec3> colors;
	vector<vec3> normals;
	vector<vec2> textures;

	crate.LoadTexture("cratetexture.jpg");
	base.LoadTexture("base.jpg");
	cerdo.LoadTexture("cerdito.jpg");
	/*
	vec3 amarillo = vec3(1.0f, 1.0f, 0.0f);
	vec3 morado = vec3(0.55f, 0.00f, 0.55f);
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
	colors.push_back(gris);*/

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

	normals.push_back(vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(vec3(0.0f, 0.0f, 1.0f));

	normals.push_back(vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(vec3(0.0f, 0.0f, -1.0f));

	normals.push_back(vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(1.0f, 0.0f, 0.0f));

	normals.push_back(vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(vec3(-1.0f, 0.0f, 0.0f));

	normals.push_back(vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(vec3(0.0f, 1.0f, 0.0f));

	normals.push_back(vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(vec3(0.0f, -1.0f, 0.0f));
	for (int i = 0; i < 6; i++) {
		textures.push_back(vec2(1.0f, 0.0f));
		textures.push_back(vec2(1.0f, 1.0f));
		textures.push_back(vec2(0.0f, 0.0f));
		textures.push_back(vec2(0.0f, 1.0f));
		
	}

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
	mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	mesh.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	mesh.SetIndices(indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	
	program2.CreateProgram();
	program2.AttachShader("depth.vert",GL_VERTEX_SHADER);
	program2.AttachShader("depth.frag", GL_FRAGMENT_SHADER);
	program2.SetAttribute(0, "VertexPosition");
	program2.LinkProgram();

	program3.CreateProgram();
	program3.AttachShader("Shadow.vert", GL_VERTEX_SHADER);
	program3.AttachShader("Shadow.frag", GL_FRAGMENT_SHADER);
	program3.SetAttribute(0, "VertexPosition");
	program.SetAttribute(1, "VertexColor");
	program.SetAttribute(2, "VertexNormal");
	program.SetAttribute(3, "VertexTexCoord");
	program3.LinkProgram();

	program3.Activate();
	program3.SetUniformf("Resolution", 400.0f, 400.0f);
	program3.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	program3.SetUniformf("LightPosition", lightPosition2.x, lightPosition2.y, lightPosition2.z);
	program3.SetUniformf("CameraPosition", _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);
	program3.SetUniformi("DiffuseTexture", 0);
	program3.SetUniformi("DiffuseTexture2", 1);
	program3.SetUniformi("ShadowMap", 2);

	program3.Deactivate();

	program.CreateProgram();
	program.AttachShader("Shadow2.vert", GL_VERTEX_SHADER);
	program.AttachShader("Shadow2.frag", GL_FRAGMENT_SHADER);
	program.SetAttribute(0, "VertexPosition");
	program.SetAttribute(1, "VertexColor");
	program.SetAttribute(2, "VertexNormal");
	program.SetAttribute(3, "VertexTexCoord");
	program.LinkProgram();

	program.Activate();
	program3.SetUniformf("Resolution", 400.0f, 400.0f);
	program.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	program.SetUniformf("LightPosition", lightPosition2.x, lightPosition2.y, lightPosition2.z);
	program.SetUniformf("CameraPosition", _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);
	program.SetUniformi("DiffuseTexture", 0);
	program.SetUniformi("DiffuseTexture2", 1);
	program3.SetUniformi("ShadowMap", 2);
	program.Deactivate();

	_camera.SetPosition(0.0f, 20.0f, 50.0f);
	_camera2.SetPosition(lightPosition2.x, lightPosition2.y, lightPosition2.z);
	_camera2.Pitch(-90);
	_camera.Pitch(-20);
	_camera2.SetOrthographic(100.0f, 1.0f);
	_transform.SetPosition(0.0f, 5.0f, 0.0f);
	_transform2.SetScale(15.0f, 0.25f, 15.0f);
	_transform2.SetPosition(0.0f, -5.0f, 0.0f);

	depth.Create(2048);
}

void GameLoop() {
	_transform.Rotate(0.02f, 0.02f, 0.02f, false);//Rotación Local
	depth.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program2.Activate();
	program2.SetUniformMatrix("mvpMatrix", _camera2.GetViewProjection() * _transform.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program2.SetUniformMatrix("mvpMatrix", _camera2.GetViewProjection() * _transform2.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);

	program2.Deactivate();
	depth.Unbind();
	glViewport(0, 0, 400, 400);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program.Activate();
	glActiveTexture(GL_TEXTURE0);
	crate.Bind();
	glActiveTexture(GL_TEXTURE1);
	cerdo.Bind();
	glActiveTexture(GL_TEXTURE2);
	depth.BindDepthMap();

	//program.SetUniformf("lightColor", lightColor.x, lightColor.y, lightColor.z);
	//program.SetUniformf("LightPosition", lightPosition.x, lightPosition.y, lightPosition.z);
	//program.SetUniformf("cameraPosition", _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);
	modelMatrix = _transform.GetModelMatrix();
	normalMatrix = transpose(inverse(mat3(_transform.GetModelMatrix())));
	program.SetUniformMatrix("modelMatrix", modelMatrix);
	program.SetUniformMatrix3("normalMatrix", normalMatrix);
	program.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	program.SetUniformMatrix("LightVPMatrix", _camera2.GetViewProjection());
	mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	crate.Unbind();
	glActiveTexture(GL_TEXTURE1);
	cerdo.Unbind();
	glActiveTexture(GL_TEXTURE2);
	depth.UnbindDepthMap();
	program.Deactivate();

	program3.Activate();

	glActiveTexture(GL_TEXTURE0);
	base.Bind();
	glActiveTexture(GL_TEXTURE2);
	depth.BindDepthMap();
	modelMatrix2 = _transform2.GetModelMatrix();
	normalMatrix2 = transpose(inverse(mat3(_transform2.GetModelMatrix())));
	program3.SetUniformMatrix("modelMatrix", modelMatrix2);
	program3.SetUniformMatrix3("normalMatrix", normalMatrix2);
	program3.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	program3.SetUniformMatrix("LightVPMatrix", _camera2.GetViewProjection());
	mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	base.Unbind();
	glActiveTexture(GL_TEXTURE2);
	depth.UnbindDepthMap();

	program3.Deactivate();



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
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	std::cout << glGetString(GL_VERSION) << std::endl;
	glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
	

	ilInit();
	//Queremos cambiar el punto de origen
	ilEnable(IL_ORIGIN_SET);
	//Configuramos el origen de las texturas generadas por devil como abajo a la izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Configuración inicial de nuestro programa
	Initialize();
	// Iniciar la aplicación. El Main se pausará en esta línea hasta que se cierre la ventana.
	glutMainLoop();

	return 0;
}