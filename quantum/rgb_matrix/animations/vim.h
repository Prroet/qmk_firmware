RGB_MATRIX_EFFECT(VIM)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool VIM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    if (params->init) {
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
        memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
    }
    RGB rgb_vim = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv_vim);
    rgb_matrix_set_color(g_led_config.matrix_co[3][6], rgb_vim.r, rgb_vim.g, rgb_vim.b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][7], rgb_vim.r, rgb_vim.g, rgb_vim.b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][8], rgb_vim.r, rgb_vim.g, rgb_vim.b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][9], rgb_vim.r, rgb_vim.g, rgb_vim.b);
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
