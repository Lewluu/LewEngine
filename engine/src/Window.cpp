#include "Window.h"

lwg::Window::Window() {}

void lwg::Window::init() {
    _m_SetupMonitor();
    _m_SetupWindow();
}

void lwg::Window::startLoop(GFX *gfx) {
    if (!_m_glfw_window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(_m_glfw_window)) {
        glfwSwapBuffers(_m_glfw_window);

        gfx->setContext();

        glfwSwapInterval(1);
        glfwPollEvents();
    }

    glfwDestroyWindow(_m_glfw_window);
}

void lwg::Window::_m_SetupMonitor() {
    int count, width, height, xscale, yscale, xpos, ypos;
    
    _m_glfw_monitor = glfwGetPrimaryMonitor();

    const char *name = glfwGetMonitorName(_m_glfw_monitor);

    glfwGetVideoModes(_m_glfw_monitor, &count);
    glfwGetMonitorWorkarea(_m_glfw_monitor, &xpos, &ypos, &width, &height);

    std::cout << "Monitor Context Data:" << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "XScale: " << xscale << std::endl;
    std::cout << "YScale: " << yscale << std::endl;
    std::cout << "XPos: " << xpos << std::endl;
    std::cout << "YPos: " << ypos << std::endl;
}

void lwg::Window::_m_SetupWindow() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    _m_glfw_window = glfwCreateWindow(800, 600, "Vulkan Window", NULL, NULL);

    glfwMakeContextCurrent(_m_glfw_window);
}

lwg::Window::~Window(){}