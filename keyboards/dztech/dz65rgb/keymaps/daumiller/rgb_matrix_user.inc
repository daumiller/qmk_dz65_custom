RGB_MATRIX_EFFECT(trans_flag_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool trans_flag_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  uint8_t value = rgb_matrix_get_val();
  HSV hsv_blue  = {140, 169, value}; // rgb:85,205,252 => hsv:197deg, 66.3%, 98.8% => u8_hsv:140,169,252
  HSV hsv_pink  = {247, 125, value}; // rgb:247,168,184 => hsv:348deg, 32.0%, 96.9% => u8_hsv:247,82,247
  RGB rgb_blue  = rgb_matrix_hsv_to_rgb(hsv_blue);
  RGB rgb_pink  = rgb_matrix_hsv_to_rgb(hsv_pink);

  // 0-14, 15-29, 30-43, 44-57, 58-67
  // skip empty spots 57 & 64
  for(uint8_t idx= 0; idx<=14; ++idx) { rgb_matrix_set_color(idx, rgb_blue.r, rgb_blue.g, rgb_blue.b); }
  for(uint8_t idx=15; idx<=29; ++idx) { rgb_matrix_set_color(idx, rgb_pink.r, rgb_pink.g, rgb_pink.b); }
  for(uint8_t idx=30; idx<=43; ++idx) { rgb_matrix_set_color(idx, value,      value,      value     ); }
  for(uint8_t idx=44; idx<=56; ++idx) { rgb_matrix_set_color(idx, rgb_pink.r, rgb_pink.g, rgb_pink.b); }
  for(uint8_t idx=58; idx<=67; ++idx) { rgb_matrix_set_color(idx, rgb_blue.r, rgb_blue.g, rgb_blue.b); if(idx == 63) { ++idx; } }

  return rgb_matrix_check_finished_leds(led_max);
}

#endif
