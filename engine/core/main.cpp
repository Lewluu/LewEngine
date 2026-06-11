#include "LewEngine.h"


int main() {
    // Main LewEngine object
    lwg::LewEngine lwg;
    
    // Start main app loop
    lwg.start();

    // Finish the process and exit loop
    lwg.terminate();

    return 0;
}
