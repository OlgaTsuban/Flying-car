#include "../inc/renderer.h"

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;

SDL_Renderer *get_renderer() {
    return renderer;
}

SDL_Window *get_window() {
    return window;
}

void render_window(const char *title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window failed to init. Error: %s\n", SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void destroy_window_and_renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void render_texture(t_texture texture, t_vector2 position, double rotation, int flip_mode) {
    SDL_Rect src = {0, 0, texture.src_size.x, texture.src_size.y};
    SDL_Rect dst = {position.x - texture.dst_size.x / 2,
        position.y - texture.dst_size.y / 2,
        texture.dst_size.x,
        texture.dst_size.y};
    SDL_RenderCopyEx(renderer, texture.tex, &src, &dst, rotation, NULL, flip_mode);
}

void create_text_texture(t_label *label) {
    SDL_Surface *surface = TTF_RenderText_Blended(label->font, label->text, label->text_color);
    label->rendered_texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_SizeText(label->font, label->text, &label->text_area.w, &label->text_area.h);
    SDL_FreeSurface(surface);
}

void render_label(t_label label) {
    SDL_RenderCopy(renderer, label.rendered_texture, NULL, &label.text_area);
}

void render_int_label(t_label *label, int number, char buf[]) {
    SDL_itoa(number, buf, 10);
    label->text = buf;
    create_text_texture(label);
}

t_texture load_texture(const char *file_path, float multiplier) {
    SDL_Surface *surface = IMG_Load(file_path);
    if (surface == NULL) {
        printf("Failed to create surface of file: %s\n", file_path);
    }
    t_texture texture = {{surface->w, surface->h}, {surface->w * multiplier, surface->h * multiplier}, NULL};
    texture.tex = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture.tex == NULL) {
        printf("Failed to create surface of file: %s\n", file_path);
    }
    SDL_FreeSurface(surface);
    return texture;
}

void clear_window() {
    SDL_RenderClear(renderer);
}

void display() {
    SDL_RenderPresent(renderer);
}

