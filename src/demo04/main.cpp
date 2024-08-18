#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main() {
    // initialize GLFW library
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // add window creation hints
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    //glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    // create a new window
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // make window's context current
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    // loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // render
        glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap front and black buffers
        glfwSwapBuffers(window);

        // pool for process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
