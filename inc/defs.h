#ifndef STRUCTS_H
#define STRUCTS_H

static SDL_bool exit_main_loop = SDL_FALSE;
static SDL_bool using_new_background_ogg = SDL_FALSE;
static SDL_Renderer *render = NULL;
static SDL_bool Vertical_is_new_game = SDL_TRUE;
static SDL_bool Vertical_is_crashing = SDL_FALSE;
static Sint16 Vertical_crashing_count_down;
static Sint16 Vertical_separator_0_block_start_y;
static Sint16 Vertical_separator_1_block_start_y;
static Sint16 Vertical_last_car_road;
static SDL_bool Vertical_player_is_car_fly;
static Sint16 Vertical_player_car_fly_duration;
static Sint16 Vertical_score;
static Sint16 Vertical_level;
static Sint16 Vertical_pass;
static Sint16 Vertical_fly_count;
static Sint16 Vertical_fly_charger_count;

static SDL_bool Vertical_key_up_pressed = SDL_FALSE;
static SDL_bool Vertical_key_down_pressed = SDL_FALSE;
static SDL_bool Vertical_key_right_pressed = SDL_FALSE;
static SDL_bool Vertical_key_left_pressed = SDL_FALSE;

static VERTICAL_CAR_STRUCT Vertical_player_car;
static VERTICAL_OPPOSITE_CAR_TYPE_STRUCT Vertical_opposite_car_type[VERTICAL_OPPOSITE_CAR_TYPE_COUNT];
static VERTICAL_OPPOSITE_CAR_STRUCT Vertical_opposite_car[VERTICAL_OPPOSITE_CAR_COUNT];

#endif //STRUCTS_H
