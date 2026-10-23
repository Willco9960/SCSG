#include "ui.h"
#include "lvgl.h"

static void on_test_click(lv_event_t *event)
{
    lv_obj_t *label = lv_event_get_user_data(event);
    lv_label_set_text(label, "Mouse input works!");
}

void ui_init(void)
{
    lv_obj_t *screen = lv_screen_active();
    lv_obj_set_style_bg_color(screen, lv_color_hex(0xF5EFDF), 0);

    lv_obj_t *title = lv_label_create(screen);
    lv_label_set_text(title, "KitchenSprout - UI starter");
    lv_obj_set_style_text_color(title, lv_color_hex(0x655447), 0);
    lv_obj_align(title, LV_ALIGN_CENTER, 0, -40);

    /* Only a mouse check; replace this with your own UI as you learn. */
    lv_obj_t *button = lv_button_create(screen);
    lv_obj_set_size(button, 200, 52);
    lv_obj_set_style_bg_color(button, lv_color_hex(0x91A888), 0);
    lv_obj_align(button, LV_ALIGN_CENTER, 0, 30);

    lv_obj_t *label = lv_label_create(button);
    lv_label_set_text(label, "Test mouse input");
    lv_obj_set_style_text_color(label, lv_color_hex(0x292D26), 0);
    lv_obj_center(label);
    lv_obj_add_event_cb(button, on_test_click, LV_EVENT_CLICKED, label);
}
