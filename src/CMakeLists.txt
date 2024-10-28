
set(sources
        Matrix4.cpp
        Vector3.cpp
)

add_library(vecmath ${sources})
target_include_directories(vecmath PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(vecmathc SHARED vecmath.cpp)
target_link_libraries(vecmathc PRIVATE vecmath)
