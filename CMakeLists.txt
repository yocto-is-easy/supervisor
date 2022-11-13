project(supervisor)

cmake_minimum_required(VERSION 3.12)

include_directories(
    include/
)

add_executable(observe
    src/client/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME}-service
    src/impl/main.cpp
)

find_package(Threads REQUIRED)

target_link_libraries(observe
    Threads::Threads
)

target_link_libraries(${CMAKE_PROJECT_NAME}-service
    Threads::Threads
)
