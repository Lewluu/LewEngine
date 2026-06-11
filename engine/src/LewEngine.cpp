#include <iostream>
#include "include/LewEngine.h"

lwg::LewEngine::LewEngine() {
    glfwInit();

    _m_window = new Window;
    _m_window->init();

    _m_gfx = new GFX;
    _m_gfx->init();
}

void lwg::LewEngine::start() {
    _m_window->startLoop(_m_gfx);
}

void lwg::LewEngine::terminate() {
    _m_window->cleanup();
    _m_gfx->cleanup();
    glfwTerminate();
}

lwg::LewEngine::~LewEngine(){
    delete _m_window, _m_gfx;
}
