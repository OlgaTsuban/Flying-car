#include "../inc/show.h"

t_label create_label(char *text, TTF_Font *font, SDL_Color text_color, int x, int y) {
    t_label new_label = {text, font, text_color, {x, y, 0, 0}, NULL};
    TTF_SizeText(font, text, &new_label.text_area.w, &new_label.text_area.h);
    new_label.text_area.x -= new_label.text_area.w / 2;
    create_text_texture(&new_label);
    return new_label;
}

t_button_action show_menu(t_buttons_arr buttons, t_labels_arr *labels, SDL_Color background_color, const SDL_Rect *background_area, bool clear_each_frame) {
    const int FPS = 30;
    const int MAX_FRAME_DELAY = 1000 / FPS;
    Uint32 frame_start = 0;
    Uint32 frame_time = 0;


    if (labels != NULL) {
        for (int i = 0; i < labels->size; i++) {
            create_text_texture(&labels->arr[i]);
        }
    }

    SDL_Event event;
    for (bool done = false; done == false;) {
        while (SDL_PollEvent(&event)) {
            SDL_Rect cursor_rect = {event.motion.x, event.motion.y, 1, 1};
            if (event.type == SDL_QUIT) {
                done = true;
            } else if (event.type == SDL_MOUSEMOTION) {
                for (int i = 0; i < buttons.size; i++) {
                    if (SDL_HasIntersection(&cursor_rect, &buttons.arr[i].label.text_area)) {
                        buttons.arr[i].label.text_color = buttons.arr[i].mouse_over_color;
                        create_text_texture(&buttons.arr[i].label);
                    } else {
                        buttons.arr[i].label.text_color = buttons.arr[i].default_color;
                        create_text_texture(&buttons.arr[i].label);
                    }
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                for (int i = 0; i < buttons.size; i++) {
                    if (SDL_HasIntersection(&cursor_rect, &buttons.arr[i].label.text_area)) {
                        buttons.arr[i].label.text_color = buttons.arr[i].default_color;
                        create_text_texture(&buttons.arr[i].label);
                        return buttons.arr[i].button_action;
                    }
                }
            }
        }

        if (clear_each_frame) {
            clear_window();
        }
        SDL_SetRenderDrawColor(get_renderer(), background_color.r, background_color.g, background_color.b, background_color.a);
        SDL_RenderFillRect(get_renderer(), background_area);
        SDL_SetRenderDrawColor(get_renderer(), 248, 128, 128, background_color.a);
        for (int i = 0; i < buttons.size; i++) {
            render_label(buttons.arr[i].label);
        }
        if (labels != NULL) {
            for (int i = 0; i < labels->size; i++) {
                render_label(labels->arr[i]);
            }
        }

        display();

        frame_time = SDL_GetTicks() - frame_start;
        if (MAX_FRAME_DELAY > frame_time) {
            SDL_Delay(MAX_FRAME_DELAY - frame_time);
        }
    }

    return QUIT;
}




t_button_action show_settings_menu(t_buttons_arr buttons, t_labels_arr *labels, SDL_Color background_color, const SDL_Rect *background_area, bool clear_each_frame, int *volume) {
    const int FPS = 30;
    const int MAX_FRAME_DELAY = 1000 / FPS;
    Uint32 frame_start = 0;
    Uint32 frame_time = 0;

    char buff[10];
    SDL_itoa(*volume, buff, 10);
    labels->arr[1].text = buff;
    if (labels != NULL) {
        for (int i = 0; i < labels->size; i++) {
            create_text_texture(&labels->arr[i]);
        }
    }

    SDL_Event event;
    for (bool done = false; done == false;) {
        while (SDL_PollEvent(&event)) {
            SDL_Rect cursor_rect = {event.motion.x, event.motion.y, 1, 1};
            if (event.type == SDL_QUIT) {
                done = true;
            } else if (event.type == SDL_MOUSEMOTION) {
                for (int i = 0; i < buttons.size; i++) {
                    if (SDL_HasIntersection(&cursor_rect, &buttons.arr[i].label.text_area)) {
                        buttons.arr[i].label.text_color = buttons.arr[i].mouse_over_color;
                        create_text_texture(&buttons.arr[i].label);
                    } else {
                        buttons.arr[i].label.text_color = buttons.arr[i].default_color;
                        create_text_texture(&buttons.arr[i].label);
                    }
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Increase volume
                if (SDL_HasIntersection(&cursor_rect, &buttons.arr[0].label.text_area)) {
                    if (*volume + 10 <= 100) {
                        *volume += 10;
                        char buff[10];
                        SDL_itoa(*volume, buff, 10);
                        labels->arr[1].text = buff;
                        create_text_texture(&labels->arr[1]);
                        Mix_VolumeMusic(*volume);
                    }
                }
                // Decrease volume
                if (SDL_HasIntersection(&cursor_rect, &buttons.arr[1].label.text_area)) {
                    if (*volume - 10 >= 0) {
                        *volume -= 10;
                        char buff[10];
                        SDL_itoa(*volume, buff, 10);
                        labels->arr[1].text = buff;
                        create_text_texture(&labels->arr[1]);
                        Mix_VolumeMusic(*volume);
                    }
                }
                // Exit to main menu
                if (SDL_HasIntersection(&cursor_rect, &buttons.arr[2].label.text_area)) {
                    return buttons.arr[2].button_action;
                }
            }
        }

        if (clear_each_frame) {
            clear_window();
        }
        SDL_SetRenderDrawColor(get_renderer(), background_color.r, background_color.g, background_color.b, background_color.a);
        SDL_RenderFillRect(get_renderer(), background_area);
        SDL_SetRenderDrawColor(get_renderer(), 248, 128, 128, background_color.a);
        for (int i = 0; i < buttons.size; i++) {
            render_label(buttons.arr[i].label);
        }
        if (labels != NULL) {
            for (int i = 0; i < labels->size; i++) {
                render_label(labels->arr[i]);
            }
        }

        display();

        frame_time = SDL_GetTicks() - frame_start;
        if (MAX_FRAME_DELAY > frame_time) {
            SDL_Delay(MAX_FRAME_DELAY - frame_time);
        }
    }
    return QUIT;
}
