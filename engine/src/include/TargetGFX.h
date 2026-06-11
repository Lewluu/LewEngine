#pragma once

namespace lwg {
    class TargetGFX {
        public:
            virtual void init() = 0;
            virtual void setContext() = 0;
            virtual void setWindowInstance() = 0;
            virtual void setApiInstance() = 0;
    };
}