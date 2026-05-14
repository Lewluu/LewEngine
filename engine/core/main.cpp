#include "LewEngine.h"


int main() {
    // Main LewEngine object
    lwg::LewEngine lwg;
    
    try {
        lwg.init();
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
