cmake_minimum_required(VERSION 3.19.8)

set(CMAKE_MAKE_PROGRAM $ENV{MAKE} CACHE INTERNAL "")

project(LewEngine VERSION 1.0)

if(${MODE} STREQUAL test)

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
    set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

    include(${TEST_DIR}/CMakeLists.txt)
elseif(${MODE} STREQUAL full)
    add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

    set(
        LIB_SRC 
        ${LIB_DIR}/Test.cpp 
        ${LIB_DIR}/Log.cpp
    )

    # Build libraries code directly into source code
    target_sources(${PROJECT_NAME} PUBLIC
        ${LIB_SRC}
    )

    find_package(Vulkan REQUIRED)
    find_package(glfw3 REQUIRED)
    find_package(glm REQUIRED)

    target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        Vulkan::Vulkan
        glfw
        glm::glm
    )

    target_include_directories(
        ${PROJECT_NAME} PUBLIC
        ${LIB_DIR}
    )
endif()
