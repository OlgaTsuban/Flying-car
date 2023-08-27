#include "../inc/main.h"
#include "../inc/object.h"
#include "../inc/renderer.h"

t_object create_object(float x, float y, t_texture texture, float speed, int flip_mode) {
    t_vector2 building_position = {x, y};
    t_object building = {building_position, texture, speed, flip_mode};
    return building;
}

// Must be called each frame
void update_building(t_object *building) {
    building->position.x -= building->speed;
}

void render_object(t_object *building) {
    render_texture(building->texture, building->position, 0, building->flip_mode);
}
