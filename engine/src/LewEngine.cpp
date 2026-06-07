#include <iostream>
#include "include/LewEngine.h"

lwg::LewEngine::LewEngine() {
    glfwInit();

    _m_window = new Window;
    _m_window->init();

    if (VULKAN_INIT_TRUE) {
        _m_gfx = new VkGFX;
    }
}

void lwg::LewEngine::start() {
    _m_window->startLoop();
}

void lwg::LewEngine::terminate() {
    glfwTerminate();
}

lwg::LewEngine::~LewEngine(){
    delete _m_window;
}
