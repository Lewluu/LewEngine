add_executable(${PROJECT_NAME} ${TEST_DIR}/src/main.cpp)

set(
    LIB_SRC 
    ${LIB_DIR}/Test.cpp 
    ${LIB_DIR}/Log.cpp
)

add_library(LibTest ${LIB_SRC})

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    LibTest
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${LIB_DIR}
)