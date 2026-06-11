// Source for the graphics pipeline context
#pragma once
#include <vulkan/vulkan.h>
#ifdef GLFW_INIT
#include <GLFW/glfw3.h>
#endif
#include <iostream>
#include <vector>
#include "TargetGFX.h"

namespace lwg {
    class VkGFX : public TargetGFX {
        public:
            VkGFX();
            ~VkGFX();
            void init() override;
            void setWindowInstance() override;
            void setApiInstance() override;
            void setContext() override;
        private:
            VkInstance *_m_vk_instance;
            VkApplicationInfo *_m_vk_app_info;
            VkInstanceCreateInfo *_m_vk_instance_create_info;
            VkResult *_m_vk_result;
    };
}