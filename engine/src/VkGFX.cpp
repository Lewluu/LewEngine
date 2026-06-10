#include "VkGFX.h"

lwg::VkGFX::VkGFX() {}

void lwg::VkGFX::init() {
    _m_vk_instance = new VkInstance;
    _m_vk_app_info = new VkApplicationInfo{};
    _m_vk_instance_create_info = new VkInstanceCreateInfo{};
    _m_vk_result = new VkResult;

    // Configure application info
    _m_vk_app_info->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    _m_vk_app_info->pApplicationName = "Test Vulkan";
    _m_vk_app_info->applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    _m_vk_app_info->pEngineName = "LewEngine";
    _m_vk_app_info->engineVersion = VK_MAKE_VERSION(1, 0, 0);
    _m_vk_app_info->apiVersion = VK_API_VERSION_1_0;
    _m_vk_instance_create_info->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    _m_vk_instance_create_info->pApplicationInfo = _m_vk_app_info;
}

void lwg::VkGFX::setWindowInstance() {
    uint32_t glfw_extensions_count = 0;
    const char ** glfw_extensions;

    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extensions_count);

    _m_vk_instance_create_info->enabledExtensionCount = glfw_extensions_count;
    _m_vk_instance_create_info->ppEnabledExtensionNames = glfw_extensions;
    _m_vk_instance_create_info->enabledLayerCount = 0;
}

void lwg::VkGFX::setApiInstance() {
    *(_m_vk_result) = vkCreateInstance(_m_vk_instance_create_info, nullptr, _m_vk_instance);

    if (*(_m_vk_result) != VK_SUCCESS) {
        throw std::runtime_error("FAILED TO CREATE VK INSTANCE");
    }

    // Gather vulkan extension support
    uint32_t vk_extension_count = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &vk_extension_count, nullptr);

    std::vector<VkExtensionProperties> extensions(vk_extension_count);
    vkEnumerateInstanceExtensionProperties(nullptr, &vk_extension_count, extensions.data());

    std::cout << "Available vulkan extensions ..." << std::endl;
    for (const auto &extension : extensions) {
        std::cout << extension.extensionName << std::endl;
    }
}

void lwg::VkGFX::setContext() {
    
}

lwg::VkGFX::~VkGFX() {
    vkDestroyInstance(*_m_vk_instance, nullptr);
    delete _m_vk_instance, _m_vk_app_info, _m_vk_instance_create_info, _m_vk_result;
}