#pragma once

#include "texture.h"
#include "vector2.h"
#include "show.h"

typedef struct s_label t_label;

SDL_Renderer *get_renderer();
SDL_Window *get_window();
void render_window(const char *title, int width, int height);

t_texture load_texture(const char *file_path, float multiplier);
void render_texture(t_texture texture, t_vector2 position, double rotation, int flip_mode);
void render_label(t_label label);
void render_int_label(t_label *label, int number, char buf[]);

void create_text_texture(t_label *label);

void clear_window();
void display();
void destroy_window_and_renderer();

