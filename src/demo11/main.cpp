
#include <chrono>
#include <complex>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.cpp"
#include "Line.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
void processInput(GLFWwindow* window);

Line createOneLine2d();
std::array<Line,3> createLines3d();


// settings
const unsigned int SCR_WIDTH = 800, SCR_HEIGHT = 600;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;   // time between current frame and last frame
float lastFrame = 0.0f;

Camera camera;


int main() {
    // glfw: initialize and configure
    if (!glfwInit()) {
        std::cout << "Failure to initialize GLFW context" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LeanOpengl", nullptr, nullptr);
    if (!window) {
        std::cout << "Failure to create window." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD." << std::endl;
        exit(EXIT_FAILURE);
    }

    camera.position = vec3(3,3,3);

    float angle = 0.0f;
    float rotationSpeed = 50.0f;


    // 2d line enxample
    Line oneLine = createOneLine2d();


    // 3d lines example
    std::array<Line,3> lines = createLines3d();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f, 100.0f);



    // render loop
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        std::cout << "deltaFrame= " << deltaTime << "  lastFrame= " << lastFrame << std::endl;

        // input
        processInput(window);

        // render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw
        oneLine.draw();


        angle = deltaTime * rotationSpeed;
        camera.position = vec3(3*cos(glm::radians(angle)), 3, 3*sin(glm::radians(angle)));
        glm::mat4 view = glm::lookAt(camera.position, vec3(0,0,0), vec3(0,1,0));

        lines[0].setMVP(projection * view);
        lines[1].setMVP(projection * view);
        lines[2].setMVP(projection * view);

        lines[0].draw();
        lines[1].draw();
        lines[2].draw();

        lastFrame = currentFrame;

        // glfw: swat buffers and pool IO events (keys pressed/ released, mouse moved etc)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose.

    // glfw: termiante, clearing all previous allocated GLFW resources
    glfwTerminate();
    exit(EXIT_SUCCESS);
}


// framebuffer_size_callback: whenever the window size changed (by Os or user resize) this callback functon executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// processInput: process all input. query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        std::cout << "press 'A'" << std::endl;
    }
}

Line createOneLine2d() {
    // 2d line example
    vec3 start = vec3(10,10,0);
    vec3 end = vec3(20,20,0);

    float x1 = start.x;
    float y1 = start.y;
    float x2 = end.x;
    float y2 = end.y;
    float w = SCR_WIDTH;
    float h = SCR_HEIGHT;

    // convert 3d world space position 2d screen space position
    x1 = 2*x1 / w - 1;
    y1 = 2*y1 / h - 1;

    x2 = 2*x2 / w - 1;
    y2 = 2*y2 / h - 1;

    start.x = x1;
    start.y = y1;
    end.x = x2;
    end.y = y2;

    Line line4(start, end);
    line4.setColor(glm::vec3(0.5f,0.5f,0.5f));
    return line4;
}

std::array<Line,3> createLines3d() {
    std::array<Line,3> lines;

    Line line1(vec3(0,0,0), vec3(1,0,0));
    line1.setColor(vec3(1,0,0));
    Line line2(vec3(0,0,0), vec3(0,1,0));
    line2.setColor(vec3(0,1,0));
    Line line3(vec3(0,0,0), vec3(0,0,1));
    line3.setColor(vec3(0,0,1));

    lines[0] = line1;
    lines[1] = line2;
    lines[2] = line3;

    return lines;
}

