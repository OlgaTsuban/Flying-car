#include "../inc/main.h"
#include "functions.c"

void init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL_INIT has failed. SDL_ERROR: %s\n", SDL_GetError());
    }
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("IMG_INIT has failed. SDL_ERROR: %s\n", SDL_GetError());
    }
    if (TTF_Init() == -1) {
        printf("TTF_Init has failed. SDL_ERROR: %s\n", SDL_GetError());
    }
}


void free_objects(t_objects_spawner *objects_spawner) {
    for (t_list *node = objects_spawner->objects_list; node != NULL; node = node->next) {
        free(node->data);
    }
    clear_list(&objects_spawner->objects_list);
}

int main () {
    srand(time(NULL));
    init_sdl();
    render_window("Flying_Car", WINDOW_WIDTH, WINDOW_HEIGHT);
    printf("Game oppened successfully\n");




    SDL_Rect window_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect centered_rect = {500, 200, WINDOW_WIDTH - 1000, WINDOW_HEIGHT - 400};

    // Loading textures
    SDL_Texture *background_texture1 = IMG_LoadTexture(get_renderer(), "resource/images/backgroung1.jpg");
    SDL_Texture *background_texture2 = IMG_LoadTexture(get_renderer(), "resource/images/backgroung2.jpg");
    SDL_Texture *background_texture3 = IMG_LoadTexture(get_renderer(), "resource/images/backgroung3.jpg");
    SDL_Texture *menu = IMG_LoadTexture(get_renderer(), "resource/images/start3.png");

    t_texture player_texture = load_texture("resource/images/player.png", 0.2);
    t_texture object_texture1 = load_texture("resource/images/object1.png", 1);
    t_texture object_texture2 = load_texture("resource/images/object2.png", 1);
    t_texture object_texture3 = load_texture("resource/images/object3.png", 1);
    t_texture object_texture4 = load_texture("resource/images/object4.png", 1);
    t_texture object_texture5 = load_texture("resource/images/object5.png", 1);

    t_textures_arr objects_textures = {malloc(5 * sizeof(t_texture)), 5};
    objects_textures.arr[0] = object_texture1;
    objects_textures.arr[1] = object_texture2;
    objects_textures.arr[2] = object_texture3;
    objects_textures.arr[3] = object_texture4;
    objects_textures.arr[4] = object_texture5;

    // Init audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *menu_music = Mix_LoadMUS("resource/audio/joshua-mclean-mountain-trials.mp3");
    Mix_Music *music = Mix_LoadMUS("resource/audio/soundtrack.mp3");
    Mix_Chunk *bonk_sound = Mix_LoadWAV("resource/audio/VERTICAL_CRASH.ogg");

    // Init colors
    SDL_Color white_color = {255, 255, 255, 255};
    SDL_Color red_color = {255, 0, 0, 255};
    SDL_Color pink_color = {248, 128, 128, 128};
    SDL_Color black_color = {0, 0, 0, 255};
    SDL_Color grey_color = {100, 100, 100, 255};

    // Loading fonts
    TTF_Font *ubuntu_bold_24 = TTF_OpenFont("resource/fonts/pixel2.ttf", 40);
    TTF_Font *bungee_spice_regular_40 = TTF_OpenFont("resource/fonts/t1.ttf", 40);
    TTF_Font *bungee_spice_regular_90 = TTF_OpenFont("resource/fonts/mario.ttf", 90);
    TTF_Font *bungee_spice_regular_80 = TTF_OpenFont("resource/fonts/neco.ttf", 85);
    TTF_Font *ubuntu_bold_20 = TTF_OpenFont("resource/fonts/pixel2.ttf", 32);

    // Init Labels
    t_label name_text_label = create_label("Flying car", bungee_spice_regular_90, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 530);

    /////////////////////////////////////////////////////
    t_label level1_text_label = create_label("For horizontal level:", ubuntu_bold_24, black_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 530);
    t_label w1_text_label = create_label("W - fly", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 480);
    t_label esc_text_label = create_label("Esc - pause", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 440);

     t_label level2_text_label = create_label("For vertical level:", ubuntu_bold_24, black_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 360);
    t_label w2_text_label = create_label("W - drive up", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 310);
    t_label s_text_label = create_label("S - drive down", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 270);
    t_label a_text_label = create_label("A - drive to the left", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 230);
    t_label d_text_label = create_label("D - drive to the right", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 190);
    t_label space_text_label = create_label("Space - fly", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 150);

///////////////////////////////////////////////////////////


    t_label new_game_label = create_label("Start", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50);
    t_label continue_label = create_label("Continue", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 40);
    t_label next_game_label = create_label("Next", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 30);

    t_label settings_label = create_label("Settings", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 0);
    t_label set_volume_label = create_label("Volume:", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2 - 40, WINDOW_HEIGHT / 2 - 50);
    t_label increase_volume_label = create_label(">", ubuntu_bold_24, grey_color, WINDOW_WIDTH / 2 + 160, WINDOW_HEIGHT / 2 - 50);
    t_label decrease_volume_label = create_label("<", ubuntu_bold_24, grey_color, WINDOW_WIDTH / 2 + 55, WINDOW_HEIGHT / 2 - 50);
    t_label current_volume_label = create_label("0", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2 + 85, WINDOW_HEIGHT / 2 - 50);
    t_label settings_back_label = create_label("Back", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 60);

    t_label settings2_back_label = create_label("Back", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 10);
    t_label settings3_back_label = create_label("Back", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 200);
    ///////////////////////////////////////////
    t_label options_label = create_label("Options", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 50);
     ///////////////////////////////////////////

    t_label quit_label = create_label("Quit", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 100);

    t_label score_counter_label = create_label("0", bungee_spice_regular_80, black_color, WINDOW_WIDTH / 2, 10);




    t_label score_text = create_label("Your score: ", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT / 2 - 90);
    t_label loose_menu_score = create_label("0", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2 + 105, WINDOW_HEIGHT / 2 - 90);


   t_label best_score_text = create_label("Choose level: ", ubuntu_bold_24, black_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 160);



    t_label main_menu_label = create_label("Menu", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 20);

    t_label level1_label = create_label("Horizontal", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50);
    t_label level2_label = create_label("Vertical", ubuntu_bold_24, white_color, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    t_labels_arr loose_menu_labels = {malloc(2 * sizeof(t_label)), 2};
    loose_menu_labels.arr[0] = score_text;
    loose_menu_labels.arr[1] = loose_menu_score;




    t_labels_arr main_menu_labes = {malloc(1 * sizeof(t_label)), 1};
    main_menu_labes.arr[0] = name_text_label;

    t_labels_arr level_settings_labels = {malloc(1 * sizeof(t_label)), 1};
    level_settings_labels.arr[0] = best_score_text;


    t_labels_arr settings_menu_labels = {malloc(2 * sizeof(t_label)), 2};
    settings_menu_labels.arr[0] = set_volume_label;
    settings_menu_labels.arr[1] = current_volume_label;

     /////////////////////////////////////////////////////////////

    t_labels_arr options_menu_labels = {malloc(9 * sizeof(t_label)), 9};
     options_menu_labels.arr[0] = level1_text_label;
     options_menu_labels.arr[1] = w1_text_label;
     options_menu_labels.arr[2] = esc_text_label;
     options_menu_labels.arr[3] = level2_text_label;
     options_menu_labels.arr[4] = w2_text_label;
     options_menu_labels.arr[5] = s_text_label;
     options_menu_labels.arr[6] = a_text_label;
     options_menu_labels.arr[7] = d_text_label;
     options_menu_labels.arr[8] = space_text_label;
     //////////////////////////////////////////////////////////



    // Init Buttons
    t_button new_game_button = {new_game_label, red_color, white_color, NEW_GAME};
    t_button continue_button = {continue_label, red_color, white_color, CONTINUE};
    t_button next_game_button = {next_game_label, red_color, white_color, NEW_GAME};

    t_button settings_button = {settings_label, red_color, white_color, SETTINGS};
    t_button settings_increase_vol_button = {increase_volume_label, red_color, grey_color, INCREASE_VOLUME};
    t_button settings_decrease_vol_button = {decrease_volume_label, red_color, grey_color, DECREASE_VOLUME};
    t_button settings_back_button = {settings_back_label, red_color, white_color, BACK};
    ////////////////////////////////////////////////////////////////////////////
    t_button options_button = {options_label, red_color, white_color, OPTIONS};
    //////////////////////////////////////////////////////////////////////////
    t_button settings2_back_button = {settings2_back_label, red_color, white_color, BACK};
    t_button settings3_back_button = {settings3_back_label, red_color, white_color, BACK};




    t_button level1_button = {level1_label, red_color, white_color, LEVEL1};
    t_button level2_button = {level2_label, red_color, white_color, LEVEL2};





    t_button quit_button = {quit_label, red_color, white_color, QUIT};
 
    t_button main_menu_button = {main_menu_label, red_color, white_color, GOTO_MAIN_MENU};

    t_buttons_arr main_menu_buttons = {malloc(4 * sizeof(t_button)), 4};
    main_menu_buttons.arr[0] = new_game_button;
    main_menu_buttons.arr[1] = settings_button;
    main_menu_buttons.arr[2] = quit_button;
    main_menu_buttons.arr[3] = options_button;


    t_buttons_arr level_settings_buttons = {malloc(3 * sizeof(t_button)), 3};
    level_settings_buttons.arr[0] = level1_button;
    level_settings_buttons.arr[1] = level2_button;
    level_settings_buttons.arr[2] = settings_back_button;



    t_buttons_arr settings_menu_buttons = {malloc(3 * sizeof(t_button)), 3};
    settings_menu_buttons.arr[0] = settings_increase_vol_button;
    settings_menu_buttons.arr[1] = settings_decrease_vol_button;
    settings_menu_buttons.arr[2] = settings2_back_button;

////////////////////////////////////////////////
t_buttons_arr options_menu_buttons = {malloc(1 * sizeof(t_button)), 1};
    options_menu_buttons.arr[0] = settings3_back_button;
///////////////////////////////////////////////

    t_buttons_arr loose_menu_buttons = {malloc(2 * sizeof(t_button)), 2};
    loose_menu_buttons.arr[0] = next_game_button;
    loose_menu_buttons.arr[1] = main_menu_button;

    t_buttons_arr escape_menu_buttons = {malloc(2 * sizeof(t_button)), 2};
    escape_menu_buttons.arr[0] = continue_button;
    escape_menu_buttons.arr[1] = main_menu_button;



    const int FPS = 60;
    const int MAX_FRAME_DELAY = 1000 / FPS;
    Uint32 frame_start = 0;
    Uint32 frame_time = 0;
    float delta = 0;
    Uint32 mouse_moved = SDL_GetTicks();

    int score_count = 0;
    int best_score = load_int_from_file(PATH_TO_SAVE_FILE);

    t_player player = create_player(START_PLAYER_POS, 0, 0, player_texture);
    t_objects_spawner objects_spawner = create_objects_spawner(2, objects_textures, 7);
    SDL_Event event;
    const Uint8 *key_states = SDL_GetKeyboardState(NULL);
    bool is_first_build_setted = false;
    bool is_score_increased = false;

    bool loose = false;
    bool exit_request = false;
    bool understood_controls = false;
    bool main_menu_request = true;
    bool new_game_started = false;

    Uint32 hide_cursor_after_ms = 2000;
    int volume = 100;

    while(!exit_request) {
        new_game_started = false;
        if (main_menu_request)
            Mix_PlayMusic(menu_music, -1);
        while (main_menu_request) {
           
            t_button_action main_menu_result = show_menu(main_menu_buttons, &main_menu_labes, pink_color, &window_rect, false);
	    if (main_menu_result == NEW_GAME) {
                t_button_action level_main_result =  show_menu(level_settings_buttons, &level_settings_labels, pink_color, &window_rect, false);
                if (level_main_result == LEVEL1) {
                	 Mix_PlayMusic(music, -1);
                	Mix_VolumeMusic(volume);
                	Mix_Volume(-1, volume);
                	new_game_started = true;
                	main_menu_request = false;
                }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (level_main_result == LEVEL2) {

			srand(time(0));

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		fprintf(stderr, "SDL_Init Error: %s.\n", SDL_GetError());
		return EXIT_FAILURE;
	}

#if defined(_WIN32)
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
#endif
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

	SDL_Window *window = SDL_CreateWindow("Flying_Car",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s.\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (render == NULL) {
		fprintf(stderr, "SDL_CreateRenderer Error: %s.\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	Texture_Load();

	int result = Mix_Init(MIX_INIT_OGG);
	if (result != MIX_INIT_OGG) {
		fprintf(stderr, "Mix_Init Error: %s.\n", Mix_GetError());
		return EXIT_FAILURE;
	}
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 4096) == -1) {
		fprintf(stderr, "Mix_OpenAudio Error: %s.\n", Mix_GetError());
		return EXIT_FAILURE;
	}

	Music_Load();

	SDL_SetRenderTarget(render, textures[TEXTURE_SCREEN]);
	SDL_RenderClear(render);
	vertical_Main();
	SDL_SetRenderTarget(render, NULL);

#ifndef __EMSCRIPTEN__
	while (!exit_main_loop) {


		if (event.key.keysym.sym == SDLK_ESCAPE) {
			Mix_PauseMusic();
			SDL_ShowCursor(true);
			Uint32 menu_started = SDL_GetTicks();
			t_button_action loose_menu_result = show_menu(escape_menu_buttons, NULL, pink_color, &centered_rect, true);
			frame_start += SDL_GetTicks() - menu_started;
			if (loose_menu_result == CONTINUE) {
				Mix_ResumeMusic();
			} else if (loose_menu_result == GOTO_MAIN_MENU) {
				main_menu_request = true;
			}
		}

		main_loop(textures[TEXTURE_SCREEN]);
		SDL_Delay(VERTICAL_TIMER_ELAPSE); // 10 FPS.
}
#else
	CONTEXT_EMSCRIPTEN context;
	context.texture = textures[TEXTURE_SCREEN];
	emscripten_set_main_loop_arg(main_loop_emscripten, &context, 10, 1); // 10 FPS.
#endif

	Mix_CloseAudio();
	Music_Unload();
	Texture_Unload();

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	     }
            else if (main_menu_result == SETTINGS) {
                show_settings_menu(settings_menu_buttons, &settings_menu_labels, pink_color, &window_rect, false, &volume);
               }
               //////////////////////////////////////////////////////
               else if (main_menu_result == OPTIONS) {
               	show_menu(options_menu_buttons, &options_menu_labels, pink_color, &window_rect, false);
               }
               ///////////////////////////////////////////////////////
                else if (main_menu_result == QUIT) {
                  exit_request = true;
                  main_menu_request = false;
            }
        }

        frame_start = SDL_GetTicks();

        // Input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                loose = true;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_q) {
                    exit_request = true;
                } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                    Mix_PauseMusic();
                    SDL_ShowCursor(true);
                    Uint32 menu_started = SDL_GetTicks();
                    t_button_action loose_menu_result = show_menu(escape_menu_buttons, NULL, pink_color, &centered_rect, true);
                    frame_start += SDL_GetTicks() - menu_started;
                    if (loose_menu_result == CONTINUE) {
                        Mix_ResumeMusic();
                    } else if (loose_menu_result == GOTO_MAIN_MENU) {
                        main_menu_request = true;
                    }
                }
            } else if (event.type == SDL_MOUSEMOTION) {
                SDL_ShowCursor(true);
                mouse_moved = SDL_GetTicks();
            }
        }

        // player moving, some updates and calculations
        if (SDL_GetTicks() - mouse_moved >= hide_cursor_after_ms) {
            SDL_ShowCursor(false);
        }
        if (key_states[SDL_SCANCODE_W]) {
            understood_controls = true;
            player.velocity.y -= (delta * 13);
        } else {
            player.velocity.y += (delta * 9.8f);
        }
        update_player(&player);
        for (t_list *node = objects_spawner.objects_list; node != NULL; node = node->next) {
            if (node->data != NULL) {
                t_object *top_object = &((*(t_couple_of_objects *)node->data).top_object);
                t_object *bottom_object = &((*(t_couple_of_objects *)node->data).bottom_object);
                update_building(top_object);
                update_building(bottom_object);
            }
        }
        update_objects_spawner(&objects_spawner, delta);
        objects_spawner.objects_speed += 0.002;

        int fisrst_build_param[3];

        // Collider
        SDL_Rect rect_buffer;
        SDL_Rect player_rect = {player.position.x - player.texture.dst_size.x / 2 + 40,
                            player.position.y - player.texture.dst_size.y / 2 + 20,
                            player.texture.dst_size.x - 40, player.texture.dst_size.y - 20};
        for (t_list *node = objects_spawner.objects_list; node != NULL; node = node->next) {
            if (node->data == NULL) break;
            t_couple_of_objects couple_of_objects = *(t_couple_of_objects *)node->data;

            t_object top_object = couple_of_objects.top_object;
            t_object bottom_object = couple_of_objects.bottom_object;
            SDL_Rect top_object_rect = {top_object.position.x - top_object.texture.dst_size.x / 2,
                                        top_object.position.y - top_object.texture.dst_size.y / 2,
                                        top_object.texture.dst_size.x, top_object.texture.dst_size.y};
            SDL_Rect bottom_object_rect = {bottom_object.position.x - bottom_object.texture.dst_size.x / 2,
                                            bottom_object.position.y - bottom_object.texture.dst_size.y / 2,
                                            bottom_object.texture.dst_size.x, bottom_object.texture.dst_size.y};
            if (SDL_IntersectRect(&player_rect, &top_object_rect, &rect_buffer)) {
                loose = true;
            } else if (SDL_IntersectRect(&player_rect, &bottom_object_rect, &rect_buffer)) {
                loose = true;
            }
            if (is_first_build_setted == false) {
                fisrst_build_param[0] = top_object_rect.x;
                fisrst_build_param[1] = bottom_object_rect.y;
                fisrst_build_param[2] = bottom_object_rect.h;
                is_first_build_setted = true;
            }
        }

        if (is_first_build_setted == true) {
            SDL_Rect score_collider_rect = {fisrst_build_param[0] + player_rect.w, fisrst_build_param[1] - (fisrst_build_param[2] / 2) + (player_rect.h / 2),
                                            1, player_rect.w * 2};
            if (player_rect.x + (player_rect.w / 2) < score_collider_rect.x - (score_collider_rect.w / 2)
                && SDL_IntersectRect(&player_rect, &score_collider_rect, &rect_buffer)
                && is_score_increased == false) {
                score_count += 1;
                char buffer[10];
                render_int_label(&score_counter_label, score_count, buffer);
                is_score_increased = true;
            }
            if (player_rect.x + (player_rect.w / 2) > score_collider_rect.x + (score_collider_rect.w / 2)
                && !SDL_IntersectRect(&player_rect, &score_collider_rect, &rect_buffer)
                && is_score_increased == true){
                is_score_increased = false;
            }
            is_first_build_setted = false;
        }


        //Falling under screen
        if (player_rect.y + (player_rect.h * (-1)) >= WINDOW_HEIGHT) {
            loose = true;
        }

        // Render
        //clear_window();
        if (new_game_started) {

        }
        if (score_count == 0) {
          SDL_RenderCopy(get_renderer(), background_texture1, NULL, NULL);
        }
        else if (score_count%3 == 0 && score_count != 0) {
          SDL_RenderCopy(get_renderer(), background_texture1, NULL, NULL);
        }
        else if (score_count%3 == 1 && score_count != 0) {
          SDL_RenderCopy(get_renderer(), background_texture2, NULL, NULL);
        }
        else if (score_count%3 == 2 && score_count != 0) {
          SDL_RenderCopy(get_renderer(), background_texture3, NULL, NULL);
        }

        for (t_list *node = objects_spawner.objects_list; node != NULL; node = node->next) {
            if (node->data != NULL) {
                t_object *top_object = &((*(t_couple_of_objects *)node->data).top_object);
                t_object *bottom_object = &((*(t_couple_of_objects *)node->data).bottom_object);
                render_object(top_object);
                render_object(bottom_object);
            }
        }
        render_player(player);
        render_label(score_counter_label);
        /*if (!understood_controls) {
            render_label(tip_label);
        }*/
        display();

        // FPS limiter
        frame_time = SDL_GetTicks() - frame_start;
        //static int wall = 0;
        if (MAX_FRAME_DELAY > frame_time) {
            SDL_Delay(MAX_FRAME_DELAY - frame_time);
            delta = (float)MAX_FRAME_DELAY / 1000;
        } else {
            delta = (float)frame_time / 1000;
        }

        if (loose || main_menu_request) {
            if (loose)
                Mix_PlayChannel(-1, bonk_sound, 0);
            Mix_PauseMusic();
            if (score_count > best_score) {
                best_score = score_count;
                write_int_to_file(best_score, PATH_TO_SAVE_FILE);
            }
            SDL_ShowCursor(true);

            if (loose) {
                char buffer1[10];
                char buffer2[10];
               render_int_label(&loose_menu_labels.arr[1], best_score, buffer1);
                render_int_label(&loose_menu_labels.arr[1], score_count, buffer2);
                t_button_action loose_menu_result = show_menu(loose_menu_buttons, &loose_menu_labels, pink_color, &centered_rect, true);
                if (loose_menu_result == NEW_GAME) {
                    Mix_PlayMusic(music, -1);
                    new_game_started = true;
                } else if (loose_menu_result == GOTO_MAIN_MENU) {
                    main_menu_request = true;
                }
                loose = false;
            }

            player.position = START_PLAYER_POS;
            player.velocity.x = 0;
            player.velocity.y = 0;
            free_objects(&objects_spawner);
            score_count = 0;
            objects_spawner.objects_speed = START_OBJECTS_SPEED;
            char buffer[10];
            render_int_label(&score_counter_label, score_count, buffer);
        }
    }
    if (score_count > best_score) {
        write_int_to_file(score_count, PATH_TO_SAVE_FILE);
    }

    // Free everything and exit
    for (int i = 0; i < objects_textures.size; i++) {
        SDL_DestroyTexture(objects_textures.arr[i].tex);
    }
    SDL_DestroyTexture(player_texture.tex);

    free_objects(&objects_spawner);

    Mix_FreeMusic(music);
    Mix_FreeChunk(bonk_sound);
    Mix_CloseAudio();

    TTF_CloseFont(ubuntu_bold_24);
    TTF_CloseFont(bungee_spice_regular_40);

    free(loose_menu_labels.arr);
    free(objects_textures.arr);
    free(main_menu_buttons.arr);
    free(loose_menu_buttons.arr);
    free(escape_menu_buttons.arr);
    free(level_settings_buttons.arr);
    destroy_window_and_renderer();
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    return 0;
}
