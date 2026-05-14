#include "include/LewEngine.h"

LewEngine::LewEngine() {
    _m_log.init();
    _m_camera.init();
    _m_events.init();
    _m_device.init();
    _m_ui.init();
    _m_scene3d.init();
}