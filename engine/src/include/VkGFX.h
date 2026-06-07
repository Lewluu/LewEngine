// Source for the graphics pipeline context
#ifndef GLFW_INIT
#define GLFW_INIT
#include <iostream>
#include <GLFW/glfw3.h>
#endif
#include "GFX.h"
#include <vulkan/vulkan.h>

namespace lwg {
    class VkGFX : public GFX {
        public:
            VkGFX();
            ~VkGFX();
            void init();
        private:
            VkInstance *_m_vk_instance;
            VkApplicationInfo *_m_vk_app_info;
            VkInstanceCreateInfo *_m_vk_instance_create_info;
            VkResult *_m_vk_result;
    };
}