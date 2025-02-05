//main.cpp
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(void)
{
	// Create a window and an OpenGL context
	GLFWwindow* window;

	// Initialize GLFW
	if (!glfwInit()) {
		std::cout << "Failed!" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(960, 640, "Hello World", NULL, NULL);

	if (!window)
	{
		// Exit if creation fails
		std::cout << "Failed! WOW!" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Activate the OpenGL context
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 960, 640);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Enter the engine's game loop
	while (!glfwWindowShouldClose(window))
	{
		// Render here
		
		glClearColor(49.f / 255, 77.f / 255, 121.f / 255, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// inputs and events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
