#include <iostream>
#include "include/LewEngine.h"

lwg::LewEngine::LewEngine() {
    glfwInit();
    _m_SetupMonitor();
    _m_SetupWindow();
    // _m_log.init();
    // _m_camera.init();
    // _m_events.init();
    // _m_device.init();
    // _m_ui.init();
    // _m_scene3d.init();
}

void lwg::LewEngine::_m_SetupMonitor() {
    int count, width, height, xscale, yscale, xpos, ypos;

    _m_monitor = glfwGetPrimaryMonitor();
    const char *name = glfwGetMonitorName(_m_monitor); 

    glfwGetVideoModes(_m_monitor, &count);
    glfwGetMonitorWorkarea(_m_monitor, &xpos, &ypos, &width, &height);

    std::cout << "Monitor Context Data:" << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "XScale: " << xscale << std::endl;
    std::cout << "YScale: " << yscale << std::endl;
    std::cout << "XPos: " << xpos << std::endl;
    std::cout << "YPos: " << ypos << std::endl;
}

void lwg::LewEngine::_m_SetupWindow() {
    _m_window = glfwCreateWindow(640, 480, "Vulkan Window", _m_monitor, NULL);
}

lwg::LewEngine::~LewEngine(){}
