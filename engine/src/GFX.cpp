#include "GFX.h"

lwg::GFX::GFX(){

    if (VULKAN_INIT) {
        _m_target_gfx = new VkGFX;
    }

}

void lwg::GFX::init() {
    _m_target_gfx->init();
    _m_target_gfx->setWindowInstance();
    _m_target_gfx->setApiInstance();
}

void lwg::GFX::setContext() {
    _m_target_gfx->setContext();
}

lwg::GFX::~GFX() {
    delete _m_target_gfx;
}