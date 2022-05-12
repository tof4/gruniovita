set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PROJECT_NAME}
  src/main.c
  src/screen.c
  src/game.c
)

add_definitions(-DLINUX)

target_link_libraries(${PROJECT_NAME}
  SDL2
  SDL2main
)    