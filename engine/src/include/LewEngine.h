#ifndef GLFW_INIT
#define GLFW_INIT
#include <GLFW/glfw3.h>
#include <iostream>
#endif

#include "Window.h"

namespace lwg {
    class LewEngine {
        public:
            LewEngine();
            void start();
            void terminate();
            ~LewEngine();
        private:
            Window *_m_window;
    };
}