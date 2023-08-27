#pragma once

#include "base_includes.h"
#include "vector2.h"
#include "texture.h"

typedef struct s_object {
    t_vector2 position;
    t_texture texture;
    float speed;
    int flip_mode;
} t_object;

t_object create_object(float x, float y, t_texture texture, float speed, int flip_mode);
void update_building(t_object *building);
void render_object(t_object *building);
