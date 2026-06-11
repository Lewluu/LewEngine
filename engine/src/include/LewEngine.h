#include "Window.h"
#include "GFX.h"

namespace lwg {
    class LewEngine {
        public:
            LewEngine();
            ~LewEngine();
            void start();
            void terminate();
        private:
            Window *_m_window;
            GFX *_m_gfx;
    };
}