#ifndef LV_CONF_H
#define LV_CONF_H

#define LV_COLOR_DEPTH 32
#define LV_USE_OS LV_OS_NONE
#define LV_USE_STDLIB_MALLOC LV_STDLIB_CLIB
#define LV_USE_STDLIB_STRING LV_STDLIB_CLIB
#define LV_USE_STDLIB_SPRINTF LV_STDLIB_CLIB
#define LV_DEF_REFR_PERIOD 16

/* Desktop backend only; hardware ports will supply their own configuration. */
#define LV_USE_SDL 1
#define LV_SDL_INCLUDE_PATH <SDL.h>
#define LV_SDL_DIRECT_EXIT 1

#endif
