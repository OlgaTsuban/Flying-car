#include "../inc/objects_spawner.h"

t_objects_spawner create_objects_spawner(float seconds_between_spawns, t_textures_arr available_textures,
float objects_speed) {
    t_list *objects_list = create_node(NULL);
    t_objects_spawner objects_spawner = {objects_list, seconds_between_spawns, available_textures, objects_speed, 0};
    return objects_spawner;
}

void update_objects_spawner(t_objects_spawner *objects_spawner, float delta) {
    if (objects_spawner->timer >= objects_spawner->seconds_between_spawns) {
        objects_spawner->timer = 0;
        float random_y_offset = random_range(WINDOW_HEIGHT / -2 + 120, WINDOW_HEIGHT / 2 - 120);
        int top_random_texture_index = random_range(0, objects_spawner->available_textures.size - 1);
        int bottom_random_texture_index = random_range(0, objects_spawner->available_textures.size - 1);
        t_object top_object = create_object(WINDOW_WIDTH + 150, random_y_offset,
            objects_spawner->available_textures.arr[top_random_texture_index], objects_spawner->objects_speed, SDL_FLIP_VERTICAL);
        t_object bottom_object = create_object(WINDOW_WIDTH + 150, WINDOW_HEIGHT + random_y_offset,
            objects_spawner->available_textures.arr[bottom_random_texture_index], objects_spawner->objects_speed, SDL_FLIP_NONE);

        t_couple_of_objects *couple_of_objects = malloc(sizeof(t_couple_of_objects));
        couple_of_objects->top_object = top_object;
        couple_of_objects->bottom_object = bottom_object;
        if (objects_spawner->objects_list != NULL && objects_spawner->objects_list->data == NULL) {
            objects_spawner->objects_list->data = couple_of_objects;
        } else {
            push_back(&objects_spawner->objects_list, couple_of_objects);
        }
    } else {
        objects_spawner->timer += delta;
    }

    t_couple_of_objects *first_couple_of_objects = NULL;
    if (objects_spawner->objects_list != NULL)
        first_couple_of_objects = (t_couple_of_objects *)objects_spawner->objects_list->data;

    if (first_couple_of_objects != NULL && first_couple_of_objects->top_object.position.x <= -150) {
        free(objects_spawner->objects_list->data);
        pop_front(&(objects_spawner->objects_list));
    }
}
