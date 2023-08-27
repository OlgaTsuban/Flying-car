#pragma once

#include "base_includes.h"
#include "vector2.h"

typedef struct s_texture {
    t_vector2 src_size;
    t_vector2 dst_size;
    SDL_Texture *tex;
} t_texture;

