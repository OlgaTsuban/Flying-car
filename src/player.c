#include "../inc/main.h"
#include "../inc/player.h"
#include "../inc/vector2.h"
#include "../inc/renderer.h"
#include "../inc/texture.h"

t_player create_player(t_vector2 position, float vel_x, float vel_y, t_texture texture) {
    t_player new_entity = {position, {vel_x, vel_y}, texture};
    return new_entity;
}

// Must executes each frame
void update_player(t_player *player) {
    t_vector2 new_player_position = plus_vectors(player->position, player->velocity);
    if (new_player_position.y >= 0) {
        player->position = new_player_position;
    } else {
        player->velocity = devide_vector_by(negate_vector(player->velocity), 2);
    }
}

void render_player(t_player player) {
    render_texture(player.texture, player.position, player.velocity.y * 5, SDL_FLIP_NONE);
}
