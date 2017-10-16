/*#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"


Mesh _mesh;
ShaderProgram _shaderProgram;
void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.

	// Creaci�n del atributo de posiciones de los v�rtices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec2> positions;
	std::vector<glm::vec3> colors;

	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(18))), (float)glm::sin(glm::radians((float)(18)))));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(18))) / 2.0f, (float)glm::sin(glm::radians((float)(18))) / 2.0f));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(306))), (float)glm::sin(glm::radians((float)(306)))));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(306))) / 2.0f, (float)glm::sin(glm::radians((float)(306))) / 2.0f));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(234))), (float)glm::sin(glm::radians((float)(234)))));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(234))) / 2.0f, (float)glm::sin(glm::radians((float)(234))) / 2.0f));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(162))), (float)glm::sin(glm::radians((float)(162)))));
	positions.push_back(glm::vec2((float)glm::cos(glm::radians((float)(162))) / 2.0f, (float)glm::sin(glm::radians((float)(162))) / 2.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	for (int i = 0; i < 12; i++) {
		colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	}


	_mesh.CreateMesh(12);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW,0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag",GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0,"VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();
}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	_shaderProgram.Activate();
	_mesh.Draw(GL_TRIANGLE_STRIP);
	_shaderProgram.Deactivate();

	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versi�n espec�fica de OpenGL.
	glutInitContextVersion(4, 4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicaci�n
	// gr�fica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un t�tulo.
	glutCreateWindow("Hello World GL");
	// Asociamos una funci�n de render.
	//Esta funci�n se mandar� a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una funci�n para el cambio de resoluci�n
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tama�o de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la funci�n que se mandar� a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librer�a se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometr�as.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuraci�n inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicaci�n. El main se pausar� en esta l�nea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}*/