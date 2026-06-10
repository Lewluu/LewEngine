#pragma once
#ifdef GLFW_INIT
#include <GLFW/glfw3.h>
#endif
#include <iostream>
#include "GFX.h"

namespace lwg{
    class Window {
        public:
            Window();
            ~Window();
            void init();
            void startLoop(GFX *gfx);
        private:
            GLFWmonitor* _m_glfw_monitor;       // Used for default fullscreen values
            GLFWwindow* _m_glfw_window;
            void _m_SetupMonitor();
            void _m_SetupWindow();
    };
}