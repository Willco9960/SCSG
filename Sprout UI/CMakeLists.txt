cmake_minimum_required(VERSION 3.20)
project(KitchenSproutSimulator LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Change these without editing the UI code.
set(SPROUT_WIDTH 800 CACHE STRING "Simulator width in pixels")
set(SPROUT_HEIGHT 480 CACHE STRING "Simulator height in pixels")
foreach(dimension SPROUT_WIDTH SPROUT_HEIGHT)
    if(NOT "${${dimension}}" MATCHES "^[1-9][0-9]*$" OR ${${dimension}} GREATER 8192)
        message(FATAL_ERROR "${dimension} must be an integer from 1 to 8192")
    endif()
endforeach()

find_package(SDL2 REQUIRED CONFIG)
set(LV_BUILD_CONF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf.h" CACHE PATH "" FORCE)
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/lvgl)
target_link_libraries(lvgl PUBLIC SDL2::SDL2)

add_executable(kitchensprout src/simulator_main.c src/ui.c)
if(APPLE)
    set_target_properties(kitchensprout PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.kitchensprout.simulator")
endif()
target_include_directories(kitchensprout PRIVATE src)
target_compile_definitions(kitchensprout PRIVATE
    SPROUT_WIDTH=${SPROUT_WIDTH} SPROUT_HEIGHT=${SPROUT_HEIGHT})
target_link_libraries(kitchensprout PRIVATE lvgl::lvgl)
target_compile_options(kitchensprout PRIVATE -Wall -Wextra -Wpedantic)
