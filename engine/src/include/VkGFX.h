// Source for the graphics pipeline context
#pragma once
#include <vulkan/vulkan.h>
#ifdef GLFW_INIT
#include <GLFW/glfw3.h>
#endif
#include <iostream>
#include <vector>
#include <cstring>
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
            void cleanup() override;
            bool setDebug;
        private:
            void _m_EnableDebug();
            VkInstance *_m_vk_instance;
            VkApplicationInfo *_m_vk_app_info;
            VkInstanceCreateInfo *_m_vk_instance_create_info;
            VkResult *_m_vk_result;

            // Debugging attributes and methods
            const std::vector<const char*> _m_validation_layers = { "VK_LAYER_KHRONOS_validation" };
            bool _m_CheckValidationLayerSupport();
            static VKAPI_ATTR VkBool32 VKAPI_CALL _m_DebugCallback(
                VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                void* pUserData);
            VkDebugUtilsMessengerEXT *_m_debug_messenger;
            void _m_SetupDebugMessenger();
            void _m_PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
            VkResult _m_CreateDebugUtilsMessengerExt(
                VkInstance instance, 
                const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
                const VkAllocationCallbacks* pAllocator, 
                VkDebugUtilsMessengerEXT* pDebugMessenger);
            void _m_DestroyDebugUtilsMessengerEXT(
                VkInstance instance, 
                VkDebugUtilsMessengerEXT debugMessenger, 
                const VkAllocationCallbacks* pAllocator);
    };
}