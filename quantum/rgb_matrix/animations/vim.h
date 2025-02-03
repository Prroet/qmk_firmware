RGB_MATRIX_EFFECT(VIM)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool VIM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv_complement = rgb_matrix_config.hsv;
    hsv_complement.h   = (rgb_matrix_config.hsv.h + 127) % 255;
    RGB rgb            = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    RGB rgb_complement = rgb_matrix_hsv_to_rgb(hsv_complement);
    if (params->init) {
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
        memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
    }
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // H J K L
    for (uint8_t i = 6; i <= 9; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(g_led_config.matrix_co[3][i], rgb_complement.r, rgb_complement.g, rgb_complement.b);
    }
    // ESC
    for (uint8_t i = 0; i < 1; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(g_led_config.matrix_co[0][i], rgb_complement.r, rgb_complement.g, rgb_complement.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
