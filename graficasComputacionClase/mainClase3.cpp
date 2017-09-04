/*#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
//identificador del manager al que vamos a asociar todos los VBOss
GLuint vao;

void Initialize() {
	//creando la memoria
	//creacion del atributo posiciones de los vertices, lista de vec2
	//en el CPU
	std::vector < glm::vec2 > positions;
	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(0.5f, 0.5f));
	positions.push_back(glm::vec2(-0.5f, -0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));
	//queremos generar un manager
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	GLuint positionsVBO;
	glGenBuffers(1, &positionsVBO);
	//creamos la memoria de posiciones para poder utilizarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//creamos la mem y la incializamos con los datos de positions
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//activamos el atributo en la tarjeta de video
	glEnableVertexAttribArray(0);
	//configuramos los datos del atributo de la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//ya no vamos a tilizar el vbo
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//desactivamos el manager
	glBindVertexArray(0);




}
void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//activamos el manager, en este momento se activan todos los VBOs asociados atomáticamente
	glBindVertexArray(vao);
	//funcion de dibujado sin indices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//terminamos de utilizar el manager
	glBindVertexArray(0);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//inicializar freeglut
	glutInit(&argc, argv);
	//solicitando una version especifica de opengl
	glutInitContextVersion(4, 4);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//FREEGLUT NOS PERMITE CONFIGRUAR EVETNOS QUE OCURREN EN LA VENTANA
	//EJ: cuando alguien cierra la ventana, stop render->close window
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World GL");
	
	glutDisplayFunc(GameLoop);
	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	Initialize();

	glutMainLoop();
	return 0;
}*/