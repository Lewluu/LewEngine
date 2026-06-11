#include "VkGFX.h"

lwg::VkGFX::VkGFX() {}

void lwg::VkGFX::init() {
    _m_vk_instance = new VkInstance;
    _m_vk_app_info = new VkApplicationInfo{};
    _m_vk_instance_create_info = new VkInstanceCreateInfo{};
    _m_vk_instance_create_info->enabledLayerCount = 0;      // Default if debugging not enabled
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

    // Init debugging
    if (setDebug == true) {
        _m_EnableDebug();
    }
}

void lwg::VkGFX::setWindowInstance() {
    uint32_t glfw_extensions_count = 0;
    const char ** glfw_extensions;

    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extensions_count);
    std::vector<const char*> extensions(glfw_extensions, glfw_extensions + glfw_extensions_count);

    _m_vk_instance_create_info->enabledLayerCount = 0;
    if (setDebug == true) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        _m_vk_instance_create_info->enabledLayerCount = 1;   
    }

    _m_vk_instance_create_info->enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    _m_vk_instance_create_info->ppEnabledExtensionNames = extensions.data();
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

VKAPI_ATTR VkBool32 VKAPI_CALL lwg::VkGFX::_m_DebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) {
    // 
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}

void lwg::VkGFX::_m_PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
    createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = _m_DebugCallback;
}

void lwg::VkGFX::_m_SetupDebugMessenger() {
    VkDebugUtilsMessengerCreateInfoEXT create_info;
    _m_PopulateDebugMessengerCreateInfo(create_info);

    if (_m_CreateDebugUtilsMessengerExt(*_m_vk_instance, &create_info, nullptr, _m_debug_messenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }
}

VkResult lwg::VkGFX::_m_CreateDebugUtilsMessengerExt(
    VkInstance instance, 
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
    const VkAllocationCallbacks* pAllocator, 
    VkDebugUtilsMessengerEXT* pDebugMessenger) {
    // 
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void lwg::VkGFX::_m_DestroyDebugUtilsMessengerEXT(
                VkInstance instance, 
                VkDebugUtilsMessengerEXT debugMessenger, 
                const VkAllocationCallbacks* pAllocator) {
    //
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}

bool lwg::VkGFX::_m_CheckValidationLayerSupport() {
    uint32_t layer_count;
    vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

    std::vector<VkLayerProperties> available_layers(layer_count);
    vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

    for (const char* layer_name : _m_validation_layers) {
        bool layer_found = false;
        for (const auto &layer_properties : available_layers) {
            if (strcmp(layer_name, layer_properties.layerName) == 0) {
                layer_found = true;
            }
        }
        if (!layer_found) {
            return false;
        }    
    }

    return true;
}

void lwg::VkGFX::_m_EnableDebug() {
    if (!_m_CheckValidationLayerSupport()) {
        throw std::runtime_error("validation layers requested, but not available!");
    }

    _m_vk_instance_create_info->enabledLayerCount = _m_validation_layers.size();
    _m_vk_instance_create_info->ppEnabledLayerNames = _m_validation_layers.data();

    _m_debug_messenger = new VkDebugUtilsMessengerEXT;

    _m_SetupDebugMessenger();
}

void lwg::VkGFX::setContext() {
    
}

void lwg::VkGFX::cleanup() {
    vkDestroyInstance(*_m_vk_instance, nullptr);
    if (this->setDebug == true) {
        _m_DestroyDebugUtilsMessengerEXT(*_m_vk_instance, *_m_debug_messenger, nullptr);
    }
}

lwg::VkGFX::~VkGFX() {
    delete _m_vk_instance, _m_vk_app_info, _m_vk_instance_create_info, _m_vk_result, _m_debug_messenger;
}