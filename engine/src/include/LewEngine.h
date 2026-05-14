#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace lwg {
    class LewEngine {
        public:
            LewEngine();
            ~LewEngine();
        private:
            lwg::Log _m_log;
            lwg::Camera _m_camera;
            lwg::Events _m_events;
            lwg::Device _m_device;
            lwg::UI _m_ui;
            lwg::Scene3D _m_scene3d;
    }
}