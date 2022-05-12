find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PROJECT_NAME}
  src/main.c
  src/screen.c
  src/game.c
)

add_definitions(-DLINUX)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})