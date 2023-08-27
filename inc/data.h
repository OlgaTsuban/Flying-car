#ifndef DATA_H
#define DATA_H
#define WINDOW_WIDTH1                                   (1280)
#define WINDOW_HEIGHT1                                  (720)
#define TEXTURE_WIDTH                                  (512)
#define TEXTURE_HEIGHT                                 (512)

#define VERTICAL_PLAYER_CAR_IMAGE_SIZE_X                 (60)
#define VERTICAL_PLAYER_CAR_IMAGE_SIZE_Y                 (80)
#define VERTICAL_PLAYER_CAR_CARSH_IMAGE_SIZE_X           (60)
#define VERTICAL_PLAYER_CAR_CARSH_IMAGE_SIZE_Y           (100)
#define VERTICAL_PLAYER_CAR_FLY_IMAGE_SIZE_X             (92)
#define VERTICAL_PLAYER_CAR_FLY_IMAGE_SIZE_Y             (108)
#define VERTICAL_PLAYER_CAR_HEAD_LIGHT_IMAGE_SIZE_X      (28)
#define VERTICAL_PLAYER_CAR_HEAD_LIGHT_IMAGE_SIZE_Y      (60)
#define VERTICAL_PLAYER_CAR_HEAD_LIGHT_0_SHIFT           (4)
#define VERTICAL_PLAYER_CAR_HEAD_LIGHT_1_SHIFT           (28)
#define VERTICAL_OPPOSITE_CAR_TYPE_COUNT                 (28)
#define VERTICAL_PLAYER_CAR_FLY_FRAME_COUNT              (10)
#define VERTICAL_OPPOSITE_CAR_0_IMAGE_SIZE_X             (68)
#define VERTICAL_OPPOSITE_CAR_0_IMAGE_SIZE_Y             (140)
#define VERTICAL_OPPOSITE_CAR_1_IMAGE_SIZE_X             (48)
#define VERTICAL_OPPOSITE_CAR_1_IMAGE_SIZE_Y             (72)
#define VERTICAL_OPPOSITE_CAR_2_IMAGE_SIZE_X             (60)
#define VERTICAL_OPPOSITE_CAR_2_IMAGE_SIZE_Y             (80)
#define VERTICAL_OPPOSITE_CAR_3_IMAGE_SIZE_X             (48)
#define VERTICAL_OPPOSITE_CAR_3_IMAGE_SIZE_Y             (72)
#define VERTICAL_OPPOSITE_CAR_4_IMAGE_SIZE_X             (68)
#define VERTICAL_OPPOSITE_CAR_4_IMAGE_SIZE_Y             (108)
#define VERTICAL_OPPOSITE_CAR_5_IMAGE_SIZE_X             (52)
#define VERTICAL_OPPOSITE_CAR_5_IMAGE_SIZE_Y             (84)
#define VERTICAL_OPPOSITE_CAR_6_IMAGE_SIZE_X             (52)
#define VERTICAL_OPPOSITE_CAR_6_IMAGE_SIZE_Y             (88)
#define VERTICAL_OPPOSITE_CAR_COUNT                      (32)
#define VERTICAL_OPPOSITE_CAR_DEFAULT_APPEAR_RATE        (8)
#define VERTICAL_MAX_FLY_COUNT                           (12)
#define VERTICAL_TIMER_ELAPSE                            (120)
#define VERTICAL_PLAYER_CAR_SHIFT                        (22)
#define VERTICAL_PLAYER_CAR_FLY_SHIFT                    (16)
#define VERTICAL_DISPLAY_START_X                         (12)
#define VERTICAL_DISPLAY_START_Y                         (12)
#define VERTICAL_DISPLAY_END_X                           (496)
#define VERTICAL_DISPLAY_END_Y                           (496)
#define VERTICAL_ROAD_WIDTH                              (92)
#define VERTICAL_SEPARATOR_WIDTH                         (12)
#define VERTICAL_GRASS_WIDTH                             (28)
#define VERTICAL_STATUS_WIDTH                            (136)
#define VERTICAL_SEPARATOR_HEIGHT_SPACE                  (12)
#define VERTICAL_SEPARATOR_RATIO                         (24)
#define VERTICAL_SEPARATOR_HEIGHT                        (VERTICAL_SEPARATOR_HEIGHT_SPACE*VERTICAL_SEPARATOR_RATIO)
#define VERTICAL_STATUS_NUMBER_WIDTH                     (16)
#define VERTICAL_STATUS_NUBBER_HEIGHT                    (28)

#define VERTICAL_GRASS_0_START_X                         (VERTICAL_DISPLAY_START_X)
#define VERTICAL_GRASS_0_END_X                           (VERTICAL_GRASS_0_START_X + VERTICAL_GRASS_WIDTH)-4
#define VERTICAL_ROAD_0_START_X                          (VERTICAL_GRASS_0_START_X + VERTICAL_GRASS_WIDTH)
#define VERTICAL_ROAD_0_END_X                            (VERTICAL_ROAD_0_START_X + VERTICAL_ROAD_WIDTH)-4
#define VERTICAL_SEPARATOR_0_START_X                     (VERTICAL_ROAD_0_START_X + VERTICAL_ROAD_WIDTH)
#define VERTICAL_SEPARATOR_0_END_X                       (VERTICAL_SEPARATOR_0_START_X + VERTICAL_SEPARATOR_WIDTH)-4
#define VERTICAL_ROAD_1_START_X                          (VERTICAL_SEPARATOR_0_START_X + VERTICAL_SEPARATOR_WIDTH)
#define VERTICAL_ROAD_1_END_X                            (VERTICAL_ROAD_1_START_X + VERTICAL_ROAD_WIDTH)-4
#define VERTICAL_SEPARATOR_1_START_X                     (VERTICAL_ROAD_1_START_X + VERTICAL_ROAD_WIDTH)
#define VERTICAL_SEPARATOR_1_END_X                       (VERTICAL_SEPARATOR_1_START_X + VERTICAL_SEPARATOR_WIDTH)-4
#define VERTICAL_ROAD_2_START_X                          (VERTICAL_SEPARATOR_1_START_X + VERTICAL_SEPARATOR_WIDTH)
#define VERTICAL_ROAD_2_END_X                            (VERTICAL_ROAD_2_START_X + VERTICAL_ROAD_WIDTH)-4
#define VERTICAL_GRASS_1_START_X                         (VERTICAL_ROAD_2_START_X + VERTICAL_ROAD_WIDTH)
#define VERTICAL_GRASS_1_END_X                           (VERTICAL_GRASS_1_START_X + VERTICAL_GRASS_WIDTH)-4
#define VERTICAL_STATUS_START_X                          (VERTICAL_GRASS_1_START_X + VERTICAL_GRASS_WIDTH)
#define VERTICAL_STATUS_END_X                            (VERTICAL_STATUS_START_X + VERTICAL_STATUS_WIDTH)

#define VERTICAL_RELEASE_ALL_KEY {                       \
    Vertical_key_up_pressed      = SDL_FALSE;            \
    Vertical_key_down_pressed    = SDL_FALSE;            \
    Vertical_key_left_pressed    = SDL_FALSE;            \
    Vertical_key_right_pressed   = SDL_FALSE;            \
    if (Vertical_is_crashing == SDL_TRUE)                \
        return;                                        \
}

#endif //DATA_H
