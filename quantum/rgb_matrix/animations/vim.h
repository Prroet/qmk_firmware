RGB_MATRIX_EFFECT(VIM)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool VIM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        // if ( i == led_min + 50 ) {
        //     RGB_MATRIX_TEST_LED_FLAGS();
        //     rgb_matrix_set_color(i, 255, 255, 255);
        // }
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    // uint8_t vim_offset = 67;
    // uint8_t letter_h = vim_offset + led_min;
    // uint8_t letter_i = vim_offset + led_min + 1;
    // uint8_t letter_j = vim_offset + led_min + 2;
    // uint8_t letter_k = vim_offset + led_min + 3;

    // RGB_MATRIX_TEST_LED_FLAGS();
    // rgb_matrix_set_color(letter_h, 0, 0, 0);
    // RGB_MATRIX_TEST_LED_FLAGS();
    // rgb_matrix_set_color(letter_i, 0, 0, 0);
    // RGB_MATRIX_TEST_LED_FLAGS();
    // rgb_matrix_set_color(letter_j, 0, 0, 0);
    // RGB_MATRIX_TEST_LED_FLAGS();
    // rgb_matrix_set_color(letter_k, 0, 0, 0);
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
