#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>


#define WIDTH  800
#define HEIGTH 600


//	callback for resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int heigth) {
	//	set viewport
	glViewport(0, 0, width, heigth);
}

void processInput(GLFWwindow* window) {
	//	check for escape key when closing
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//	create window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGTH, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//	initialize glad 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	float r = 0.0;
	float g = 0.0;
	float b = 0.0;
	
	float a = 0.0;
	bool flip = false;
	while(!glfwWindowShouldClose(window)){
		// inputs
		processInput(window);

		glClearColor(r, 0.2f, 0.4f, a);
		glClear(GL_COLOR_BUFFER_BIT);

		// buffer checks
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// cleanup
	glfwTerminate();

	return 0;
}