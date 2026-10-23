#include "lvgl.h"
#include "ui.h"

int main(void)
{
    lv_init();

    /* The SDL backend also supplies LVGL's tick and delay callbacks. */
    lv_display_t *display = lv_sdl_window_create(SPROUT_WIDTH, SPROUT_HEIGHT);
    if(display == NULL) return 1;
    lv_sdl_window_set_title(display, "KitchenSprout - LVGL simulator");

    lv_indev_t *mouse = lv_sdl_mouse_create();
    if(mouse == NULL) return 1;
    lv_indev_set_display(mouse, display);

    ui_init();

    /* LVGL renders widgets, dispatches input, and advances timers here.
     * Closing the window exits through LV_SDL_DIRECT_EXIT. */
    while(1) {
        lv_timer_handler();
        lv_delay_ms(5);
    }
}
