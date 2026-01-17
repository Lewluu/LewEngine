#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>

#include "Test.h"
#include "Log.h"

void testLibs() {
   Test t;
   Log l;

   t.setValues("Eu sunt testul", 1);
   t.callValues();

   l.setFormat(LT);
   l.Info("Test Info");
}

void testApi(){

   glfwInit();
   
   GLFWwindow *window = glfwCreateWindow(800, 600, "Test GLFW", NULL, NULL);

   glfwMakeContextCurrent(window);

   while (!glfwWindowShouldClose(window)) {
      // glClear(GL_COLOR_BUFFER_BIT);
      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwTerminate();
}

int main(){

   testApi();

   return 0;
}
