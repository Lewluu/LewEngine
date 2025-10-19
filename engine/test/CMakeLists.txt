add_executable(${PROJECT_NAME} ${TEST_DIR}/src/main.cpp)

# set(
#     LIB_SRC 
#     ${LIB_DIR}/Test.cpp 
#     ${LIB_DIR}/Log.cpp
# )
# 
# add_library(LibTest ${LIB_SRC})

# default STATIC
add_library(LibTest ${LIB_DIR}/Test.cpp)
# comment this to skip log build
# add_library(LogTest STATIC ${LIB_DIR}/Log.cpp)
# comment this to not use already build log
add_library(LogTest STATIC IMPORTED)

# comment this to not use already build log
set_target_properties(LogTest PROPERTIES IMPORTED_LOCATION ${PROJ_PATH}/test/src/lib/static/libLogTest.a)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    LibTest
    LogTest
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${LIB_DIR}
)