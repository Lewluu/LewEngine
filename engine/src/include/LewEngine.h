#ifndef GLFW_INIT
#define GLFW_INIT
#include <GLFW/glfw3.h>
#include <iostream>
#endif
#include "Window.h"
// #ifdef GFX_INIT
// #define GFX_INIT
// #include "GFX.h"
// #endif
// #ifdef VULKAN_INIT
// #define VULKAN_INIT_TRUE 1
// #include "VkGFX.h"
// #endif

namespace lwg {
    class LewEngine {
        public:
            LewEngine();
            void start();
            void terminate();
            ~LewEngine();
        private:
            Window *_m_window;
            // GFX *_m_gfx;
    };
}