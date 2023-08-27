#pragma once

#include "texture.h"
#include "show.h"

typedef struct s_button t_button;
typedef struct s_label t_label;

typedef struct s_textures_arr {
    t_texture *arr;
    int size;
} t_textures_arr;

typedef struct s_buttons_arr {
    t_button *arr;
    int size;
} t_buttons_arr;

typedef struct s_labels_arr {
    t_label *arr;
    int size;
} t_labels_arr;

