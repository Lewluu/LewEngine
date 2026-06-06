#ifndef GLFW_INIT
#define GLFW_INIT
#include <iostream>
#include <GLFW/glfw3.h>
#endif

namespace lwg{
    class Window {
        public:
            Window();
            void init();
            void startLoop();
            ~Window();
        private:
            GLFWmonitor* _m_glfw_monitor;       // Used for default fullscreen values
            GLFWwindow* _m_glfw_window;
            void _m_SetupMonitor();
            void _m_SetupWindow();
    };
}