// Source for the graphics pipeline context
#pragma once
#ifdef VULKAN_INIT
#include "VkGFX.h"
#endif

namespace lwg {
    class GFX {
        public:
            GFX();
            ~GFX();
            void init();
            void setContext();
        private:
            TargetGFX *_m_target_gfx;
    };
}