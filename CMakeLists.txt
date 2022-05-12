cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()


project(gruniovita)

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Gruniovita")
set(VITA_TITLEID  "GRUNIOPSV")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
)

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PROJECT_NAME}
  src/main.c
  src/screen.c
  src/game.c
)

target_link_libraries(${PROJECT_NAME}
  SDL2
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceAudioIn_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceAppMgr_stub
  SceTouch_stub
  SceHid_stub
  SceMotion_stub
  m
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  FILE assets/grunio_red_1.bmp assets/grunio_red_1.bmp
  FILE assets/grunio_red_2.bmp assets/grunio_red_2.bmp
  FILE assets/grunio_red_3.bmp assets/grunio_red_3.bmp
  FILE assets/grunio_blue_1.bmp assets/grunio_blue_1.bmp
  FILE assets/grunio_blue_2.bmp assets/grunio_blue_2.bmp
  FILE assets/grunio_blue_3.bmp assets/grunio_blue_3.bmp
  FILE assets/grunio_green_1.bmp assets/grunio_green_1.bmp
  FILE assets/grunio_green_2.bmp assets/grunio_green_2.bmp
  FILE assets/grunio_green_3.bmp assets/grunio_green_3.bmp
  FILE assets/grunio_gray_1.bmp assets/grunio_gray_1.bmp
  FILE assets/grunio_gray_2.bmp assets/grunio_gray_2.bmp
  FILE assets/grunio_gray_3.bmp assets/grunio_gray_3.bmp
  FILE assets/carrot_red.bmp assets/carrot_red.bmp
  FILE assets/carrot_blue.bmp assets/carrot_blue.bmp
  FILE assets/carrot_green.bmp assets/carrot_green.bmp
  FILE assets/carrot_gray.bmp assets/carrot_gray.bmp
  FILE assets/font.ttf assets/font.ttf
)