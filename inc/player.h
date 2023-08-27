#pragma once

#include "base_includes.h"
#include "vector2.h"
#include "texture.h"

typedef struct s_player {
    t_vector2 position;
    t_vector2 velocity;
    t_texture texture;
} t_player;

t_player create_player(t_vector2 position, float vel_x, float vel_y, t_texture texture);
void update_player(t_player *player);
void render_player(t_player player);
