#pragma once

#include "main.h"
#include "linked_list.h"
#include "object.h"
#include "random.h"
#include "texture.h"
#include "arrays.h"

typedef struct s_objects_spawner {
    t_list *objects_list;
    float seconds_between_spawns;
    t_textures_arr available_textures;
    float objects_speed;
    float timer;
} t_objects_spawner;

typedef struct s_couple_of_objects {
    t_object top_object;
    t_object bottom_object;
} t_couple_of_objects;

t_objects_spawner create_objects_spawner(float seconds_between_spawns, t_textures_arr available_textures,
float objects_speed);
void update_objects_spawner(t_objects_spawner *objects_spawner, float delta);
