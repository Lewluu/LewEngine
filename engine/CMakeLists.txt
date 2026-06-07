cmake_minimum_required(VERSION 3.19.8)

set(CMAKE_MAKE_PROGRAM $ENV{MAKE} CACHE INTERNAL "")

project(LewEngine VERSION 1.0)

if(${MODE} STREQUAL test)

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
    set(LIB_DIR ${TEST_DIR}/src/include)

    include(${TEST_DIR}/CMakeLists.txt)
    
elseif(${MODE} STREQUAL full OR ${MODE} STREQUAL rebuild)

    add_compile_definitions(GLFW_INIT VULKAN_INIT)      # Let it be default for now

    set(CORE ${CMAKE_CURRENT_SOURCE_DIR}/core/main.cpp)
    set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    set(LIB_DIR ${SRC_DIR}/include)
    set(COMP_DIR ${LIB_DIR}/components)
    set(
        SRC_FILES
        ${SRC_DIR}/LewEngine.cpp 
        ${SRC_DIR}/Window.cpp
        # ${SRC_DIR}/GFX.cpp
        # ${SRC_DIR}/VkGFX.cpp
    )

    add_executable(${PROJECT_NAME} ${CORE})

    # Build libraries code directly into source code
    target_sources(${PROJECT_NAME} PUBLIC
        ${SRC_FILES}
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
