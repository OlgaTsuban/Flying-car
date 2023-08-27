#pragma once

#include "vector2.h"
#include "base_includes.h"
#include "arrays.h"
#include "renderer.h"
#include "main.h"

typedef enum e_button_action {
    NEW_GAME,
    CONTINUE,
    ABOUT,
    SETTINGS,
    OPTIONS,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    GOTO_MAIN_MENU,
    QUIT,
    BACK,
    LEVEL1,
    LEVEL2
} t_button_action;

typedef struct s_label {
    char *text;
    TTF_Font *font;
    SDL_Color text_color;
    SDL_Rect text_area;
    SDL_Texture *rendered_texture;
} t_label;


typedef struct s_button {
    t_label label;
    SDL_Color mouse_over_color;
    SDL_Color default_color;
    t_button_action button_action;
} t_button;

t_label create_label(char *text, TTF_Font *font, SDL_Color text_color, int x, int y);
t_button_action show_menu(t_buttons_arr buttons, t_labels_arr *labels, SDL_Color background_color, const SDL_Rect *background_area, bool clear_each_frame);
t_button_action show_settings_menu(t_buttons_arr buttons, t_labels_arr *labels, SDL_Color background_color, const SDL_Rect *background_area, bool clear_each_frame, int *volume);

