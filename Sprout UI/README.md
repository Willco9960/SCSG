# KitchenSprout LVGL Mac starter

A native C application using LVGL 9.4.0 and SDL2 for a Mac window and mouse.
The initial screen is intentionally limited to a title and an input test button.
No final screen layout, mascot, assets, sensor logic, or hardware choice is implemented.

## Build and run

Prerequisites: Apple command line developer tools, CMake, SDL2.
These were already present on this Mac when the starter was prepared.
On another Mac, install developer tools with `xcode-select --install` and
the remaining tools with `brew install cmake sdl2`.

From the repository:

```sh
cd "/Volumes/External/GT_Projects/SCSG/Sprout UI"
cmake -S . -B build
cmake --build build --parallel 4
open build/kitchensprout.app
```

Click **Test mouse input**; its text should change to **Mouse input works!**.
Close the window to quit. After editing UI code, run the build command again,
then relaunch the application. No web server, Python environment, or IDE is required.

If Homebrew SDL2 isn't discovered, configure with
`cmake -S . -B build -DCMAKE_PREFIX_PATH="$(brew --prefix sdl2)"`.

## Your starting files

| File | Purpose |
| --- | --- |
| `src/ui.c` | Your UI widgets, appearance, and event callbacks. Start here. Uses LVGL only. |
| `src/ui.h` | Declares `ui_init()` so a platform can start your UI. |
| `src/simulator_main.c` | Initializes LVGL, SDL display and mouse, then runs LVGL's timer loop. Desktop only. |
| `lv_conf.h` | LVGL compile-time settings, including the desktop SDL driver. |
| `CMakeLists.txt` | Builds LVGL and your program, links SDL2, and defines simulator resolution. Add new UI source files here. |
| `vendor/lvgl/` | Pinned upstream LVGL source and license; leave unchanged while developing UI. |
| `.gitignore` | Excludes generated build files. |

The event callback in `ui.c` receives the label as user data and updates it when
LVGL reports a click. The main loop must keep running for input, repainting,
and future animations; avoid blocking sleeps or sensor work in UI callbacks.

## Change the provisional resolution

Default: **800 x 480 landscape**. For example:

```sh
cmake -S . -B build -DSPROUT_WIDTH=1024 -DSPROUT_HEIGHT=600
cmake --build build --parallel 4
open build/kitchensprout.app
```

Set the same options back to `800` and `480` to restore the default.
CMake remembers these settings in each build directory. When moving or copying
the project to a new directory, omit `build/` and configure again.

## Porting later

Keep SDL calls and platform details in `simulator_main.c`. On a Raspberry Pi or
embedded target, supply a new entry point, display/input drivers, LVGL
configuration, and build integration, then call the same `ui_init()`.
Match LVGL versions across targets; desktop settings do not establish hardware
RAM, performance, or display compatibility. Keep UI changes in `ui.c` (or new UI
modules), and use mock data initially.

Pixel art, the approved layout, and Sprout animations come later. Obtain the
approved concept images before trying to match the design.
