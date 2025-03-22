/*

Root for building test code.
Related or not-related to the engine.
Ex: testing certain C++ aspects, scripts, buildchain, libraries, etc.

The code from this directory is build via 'build-engine.sh -m test' command

*/
 #include "Test.h"
 #include "Log.h"


 int main(){

    Test t;
    Log l;

    t.setValues("Eu sunt testul", 1);
    t.callValues();

    l.setFormat(LT);
    l.Info("Test Info");

    return 0;
 }
