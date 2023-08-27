#include "../inc/header.h"

 static void Music_Load(void) {
	music_tracks[MUSIC_BACKGROUND] = Mix_LoadMUS("resource/audio/GAME_VERTICAL_BGM.ogg");
	music_tracks[MUSIC_BACKGROUND_LOWCOST] = Mix_LoadMUS("resource/audio/GAME_VERTICAL_BGM_LOWCOST.ogg");
	music_tracks[MUSIC_CRASH] = Mix_LoadMUS("resource/audio/GAME_VERTICAL_CRASH.ogg");
	music_tracks[MUSIC_GAMEOVER] = Mix_LoadMUS("resource/audio/GAME_VERTICAL_GAMEOVER.ogg");
}

static void Music_Play(MUSIC_TRACK track, Sint32 loop) {
	Mix_PlayMusic(music_tracks[track], loop);
}

static void Music_Unload(void) {
	int i = 0;
	for (; i < MUSIC_MAX; ++i)
		if (music_tracks[i])
			Mix_FreeMusic(music_tracks[i]);
}

static void Texture_Create_Bitmap(const char *filepath, TEXTURE texture_id)
{
	SDL_Surface *bitmap = SDL_LoadBMP(filepath);
	textures[texture_id] = SDL_CreateTextureFromSurface(render, bitmap);
	SDL_FreeSurface(bitmap);

}
static void Texture_Create_Bit(const char *filepath, TEXTURE texture_id)
 {
	SDL_Surface *bitmap = IMG_Load(filepath);
	textures[texture_id] = SDL_CreateTextureFromSurface(render, bitmap);
	SDL_FreeSurface(bitmap);
}


static void Texture_Load(void) {
	textures[TEXTURE_SCREEN] =
		SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TEXTURE_WIDTH, TEXTURE_HEIGHT);

	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_0.bmp", TEXTURE_NUMBER_0);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_1.bmp", TEXTURE_NUMBER_1);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_2.bmp", TEXTURE_NUMBER_2);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_3.bmp", TEXTURE_NUMBER_3);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_4.bmp", TEXTURE_NUMBER_4);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_5.bmp", TEXTURE_NUMBER_5);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_6.bmp", TEXTURE_NUMBER_6);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_7.bmp", TEXTURE_NUMBER_7);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_8.bmp", TEXTURE_NUMBER_8);
	Texture_Create_Bitmap("resource/images/VERTICAL_NUMBER_9.bmp", TEXTURE_NUMBER_9);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR.png", TEXTURE_PLAYER_CAR);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR_FLY.png", TEXTURE_PLAYER_CAR_FLY);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR_FLY_UP.png", TEXTURE_PLAYER_CAR_FLY_UP);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR_FLY_DOWN.png", TEXTURE_PLAYER_CAR_FLY_DOWN);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR_HEAD_LIGHT.png", TEXTURE_PLAYER_CAR_HEAD_LIGHT);
	Texture_Create_Bit("resource/images/VERTICAL_PLAYER_CAR_CRASH.png", TEXTURE_PLAYER_CAR_CRASH);
	Texture_Create_Bitmap("resource/images/VERTICAL_LOGO.bmp", TEXTURE_LOGO);
	Texture_Create_Bitmap("resource/images/VERTICAL_STATUS_SCORE.bmp", TEXTURE_STATUS_SCORE);
	Texture_Create_Bitmap("resource/images/VERTICAL_STATUS_BOX.bmp", TEXTURE_STATUS_BOX);
	Texture_Create_Bitmap("resource/images/VERTICAL_STATUS_LEVEL.bmp", TEXTURE_STATUS_LEVEL);
	Texture_Create_Bitmap("resource/images/VERTICAL_STATUS_FLY.bmp", TEXTURE_STATUS_FLY);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_0.png", TEXTURE_OPPOSITE_CAR_0);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_1.png", TEXTURE_OPPOSITE_CAR_1);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_2.png", TEXTURE_OPPOSITE_CAR_2);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_3.png", TEXTURE_OPPOSITE_CAR_3);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_4.png", TEXTURE_OPPOSITE_CAR_4);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_5.png", TEXTURE_OPPOSITE_CAR_5);
	Texture_Create_Bit("resource/images/VERTICAL_OPPOSITE_CAR_6.png", TEXTURE_OPPOSITE_CAR_6);
	Texture_Create_Bitmap("resource/images/VERTICAL_GAMEOVER.bmp", TEXTURE_GAMEOVER);
	Texture_Create_Bitmap("resource/images/VERTICAL_GAMEOVER_CRASH.bmp", TEXTURE_GAMEOVER_CRASH);
	Texture_Create_Bitmap("resource/images/VERTICAL_GAMEOVER_FIELD.bmp", TEXTURE_GAMEOVER_FIELD);
}

static void Texture_Draw(Sint32 x, Sint32 y, TEXTURE texture_id) {
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	SDL_QueryTexture(textures[texture_id], NULL, NULL, &rectangle.w, &rectangle.h);
	SDL_RenderCopy(render, textures[texture_id], NULL, &rectangle);
}

static void Texture_Unload(void) {
	int i = 0;
	for (; i < TEXTURE_MAX; ++i)
		if (textures[i])
			SDL_DestroyTexture(textures[i]);
}




static void vertical_Render_Score(Sint16 x_pos, Sint16 y_pos);

static void vertical_Show_Game_Over_Screen(void) {
	SDL_SetRenderDrawColor(render, 228, 137, 137, 100);
	SDL_RenderClear(render);

	Texture_Draw(72, 40, TEXTURE_GAMEOVER);
	Texture_Draw(120, 160, TEXTURE_GAMEOVER_FIELD);

	SDL_Rect rectangle;
	SDL_SetRenderDrawColor(render, 228, 137, 137, 0);
	rectangle.x = 132;
	rectangle.y = 172;
	rectangle.w = 256;
	rectangle.h = 80;
	SDL_RenderFillRect(render, &rectangle);

	Texture_Draw(144, 200, TEXTURE_STATUS_SCORE);
	Texture_Draw(260, 192, TEXTURE_STATUS_BOX);

	vertical_Render_Score(254, -8);

	Texture_Draw(188, 320, TEXTURE_GAMEOVER_CRASH);
}

static void vertical_Render_Separator(void) {
	Sint16 start_y, end_y;

	SDL_Rect rectangle;
	SDL_SetRenderDrawColor(render, 250, 250, 250, 0);
	rectangle.x = VERTICAL_SEPARATOR_0_START_X-5;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_SEPARATOR_0_END_X + 1 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	SDL_SetRenderDrawColor(render, 250, 250, 250, 0);
	rectangle.x = VERTICAL_SEPARATOR_1_START_X-5;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_SEPARATOR_1_END_X + 1 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	start_y = Vertical_separator_0_block_start_y;
	end_y = start_y + VERTICAL_SEPARATOR_HEIGHT_SPACE;
	while (SDL_TRUE) {
		SDL_SetRenderDrawColor(render, 150, 150, 150, 0);
		rectangle.x = VERTICAL_SEPARATOR_0_START_X-5;
		rectangle.y = start_y-80;
		rectangle.w = VERTICAL_SEPARATOR_0_END_X + 1 - rectangle.x;
		rectangle.h = end_y - rectangle.y;
		SDL_RenderFillRect(render, &rectangle);

		start_y += VERTICAL_SEPARATOR_HEIGHT;
		end_y = start_y + VERTICAL_SEPARATOR_HEIGHT_SPACE;
		if (start_y > VERTICAL_DISPLAY_END_Y)
			break;
		if (end_y > VERTICAL_DISPLAY_END_Y)
			end_y = VERTICAL_DISPLAY_END_Y-12;
	}
	Vertical_separator_0_block_start_y += VERTICAL_SEPARATOR_HEIGHT_SPACE;
	if (Vertical_separator_0_block_start_y >=
		(VERTICAL_DISPLAY_START_Y + VERTICAL_SEPARATOR_HEIGHT_SPACE * VERTICAL_SEPARATOR_RATIO))
		Vertical_separator_0_block_start_y = VERTICAL_DISPLAY_START_Y;

	start_y = Vertical_separator_1_block_start_y;
	end_y = start_y + VERTICAL_SEPARATOR_HEIGHT_SPACE;
	while (SDL_TRUE) {
		SDL_SetRenderDrawColor(render, 150, 150, 150, 0);
		rectangle.x = VERTICAL_SEPARATOR_1_START_X-5;
		rectangle.y = start_y-80;
		rectangle.w = VERTICAL_SEPARATOR_1_END_X + 1 - rectangle.x;
		rectangle.h = end_y - rectangle.y;
		SDL_RenderFillRect(render, &rectangle);

		start_y += VERTICAL_SEPARATOR_HEIGHT;
		end_y = start_y + VERTICAL_SEPARATOR_HEIGHT_SPACE;
		if (start_y > VERTICAL_DISPLAY_END_Y)
			break;
		if (end_y > VERTICAL_DISPLAY_END_Y)
			end_y = VERTICAL_DISPLAY_END_Y-12;
	}
	Vertical_separator_1_block_start_y += VERTICAL_SEPARATOR_HEIGHT_SPACE;
	if (Vertical_separator_1_block_start_y >=
		(VERTICAL_DISPLAY_START_Y + VERTICAL_SEPARATOR_HEIGHT_SPACE * VERTICAL_SEPARATOR_RATIO))
		Vertical_separator_1_block_start_y = VERTICAL_DISPLAY_START_Y;
}

static void vertical_Render_Road(void) {
	SDL_Rect rectangle;
	SDL_SetRenderDrawColor(render, 150, 150, 150, 0);
	rectangle.x = VERTICAL_ROAD_0_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_ROAD_2_END_X + 1 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);
}

static void vertical_Render_Score(Sint16 x_pos, Sint16 y_pos) {
	Sint16 value;
	Sint16 remain;

	SDL_Rect rectangle;
	SDL_SetRenderDrawColor(render, 228, 137, 137, 0);
	rectangle.x = x_pos + 4;
	rectangle.y = y_pos + 52;
	rectangle.w = x_pos + 39 + 1 - rectangle.x;
	rectangle.h = y_pos + 58 - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	value = Vertical_score % 10;
	remain = Vertical_score / 10;

	while (SDL_TRUE)
	{
		Texture_Draw(x_pos + 65, y_pos + 208, value);

		x_pos -= 18;
		if (remain > 0) {
			value = remain % 10;
			remain = remain / 10;
		}
		else
			break;
	}
}




static void vertical_Render_Status(void) {
	Sint16 x_pos;
	Sint16 y_pos;
	Sint16 index;

	vertical_Render_Score(VERTICAL_STATUS_START_X, VERTICAL_DISPLAY_START_Y);

	SDL_Rect rectangle;
	SDL_SetRenderDrawColor(render, 228, 137, 137, 0);
	rectangle.x = VERTICAL_STATUS_START_X + 16;
	rectangle.y = VERTICAL_DISPLAY_START_Y + 296;
	rectangle.w = VERTICAL_STATUS_START_X + 116 + 4 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_START_Y + 320 - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	x_pos = VERTICAL_STATUS_START_X + 64;
	y_pos = VERTICAL_DISPLAY_START_Y + 296;

	Texture_Draw(x_pos, y_pos, Vertical_level);

	x_pos = VERTICAL_STATUS_START_X + 16;
	y_pos = VERTICAL_DISPLAY_START_Y + 408;
	for (index = 0; index < 5; index++) {
		if (index < Vertical_fly_charger_count)
			SDL_SetRenderDrawColor(render, 228, 137, 137, 0);
		else
			SDL_SetRenderDrawColor(render, 100, 100, 100, 0);
		rectangle.x = x_pos + index * 16;
		rectangle.y = y_pos - 8 - index;
		rectangle.w = x_pos + 8 + index * 16 + 4 - rectangle.x;
		rectangle.h = y_pos - rectangle.y;
		SDL_RenderFillRect(render, &rectangle);
	}

	x_pos = VERTICAL_STATUS_START_X + 100;
	y_pos = VERTICAL_DISPLAY_START_Y + 384;
	Texture_Draw(x_pos, y_pos, Vertical_fly_count);
}

static void vertical_Render_Player_Car(void) {
	Sint16 dx;
	Sint16 dy;

	TEXTURE image;

	if (Vertical_player_is_car_fly == SDL_FALSE)
		Texture_Draw(Vertical_player_car.pos_x, Vertical_player_car.pos_y, TEXTURE_PLAYER_CAR);
	else {
		dx = (VERTICAL_PLAYER_CAR_FLY_IMAGE_SIZE_X - VERTICAL_PLAYER_CAR_IMAGE_SIZE_X) / 2;
		dy = (VERTICAL_PLAYER_CAR_FLY_IMAGE_SIZE_Y - VERTICAL_PLAYER_CAR_IMAGE_SIZE_Y) / 2;
		dx = Vertical_player_car.pos_x - dx;
		dy = Vertical_player_car.pos_y - dy;
		switch (Vertical_player_car_fly_duration) {
			case 0:
			case 1:
				image = TEXTURE_PLAYER_CAR_FLY_UP;
				break;
			case (VERTICAL_PLAYER_CAR_FLY_FRAME_COUNT - 1):
			case (VERTICAL_PLAYER_CAR_FLY_FRAME_COUNT - 2):
				image = TEXTURE_PLAYER_CAR_FLY_DOWN;
				break;
			default:
				image = TEXTURE_PLAYER_CAR_FLY;
				break;
		}
		Texture_Draw(dx, dy, image);
	}
}

static void vertical_Render_Opposite_Car(void) {
	Sint16 index;
	for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
		if (Vertical_opposite_car[index].is_empty == SDL_FALSE)
			Texture_Draw(Vertical_opposite_car[index].pos_x, Vertical_opposite_car[index].pos_y,
				Vertical_opposite_car[index].image);
	}
}

static void vertical_Render_Player_Car_Crash(void) {
	Texture_Draw(Vertical_player_car.pos_x, Vertical_player_car.pos_y - 5, TEXTURE_PLAYER_CAR_CRASH);
}

static void vertical_Render(void) {
	SDL_Rect rectangle;
	rectangle.x = VERTICAL_STATUS_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_STATUS_END_X + 1 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderSetClipRect(render, &rectangle);

	vertical_Render_Status();

	rectangle.x = VERTICAL_ROAD_0_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_ROAD_2_END_X + 1 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderSetClipRect(render, &rectangle);

	vertical_Render_Road();
	vertical_Render_Separator();
	vertical_Render_Opposite_Car();
	vertical_Render_Player_Car();
}

static void vertical_Render_Background(void) {
	SDL_Rect rectangle;

	SDL_SetRenderDrawColor(render, 228, 137, 137, 0);
	SDL_RenderClear(render);

	SDL_SetRenderDrawColor(render,228, 137, 137, 0);
	rectangle.x = VERTICAL_DISPLAY_START_X - 4;
	rectangle.y = VERTICAL_DISPLAY_START_Y - 4;
	rectangle.w = VERTICAL_DISPLAY_END_X + 8 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y + 4 - rectangle.y;
	SDL_RenderDrawRect(render, &rectangle);

	SDL_SetRenderDrawColor(render, 130, 230, 100, 0);
	rectangle.x = VERTICAL_GRASS_0_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_GRASS_0_END_X + 4 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	SDL_SetRenderDrawColor(render, 100, 180, 100, 0);
	SDL_RenderDrawLine(render, VERTICAL_GRASS_0_END_X - 1,
		VERTICAL_DISPLAY_START_Y, VERTICAL_GRASS_0_END_X - 1, VERTICAL_DISPLAY_END_Y - 1);

	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderDrawLine(render, VERTICAL_GRASS_0_END_X,
		VERTICAL_DISPLAY_START_Y, VERTICAL_GRASS_0_END_X, VERTICAL_DISPLAY_END_Y);

	SDL_SetRenderDrawColor(render, 130, 230, 100, 0);
	rectangle.x = VERTICAL_GRASS_1_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_GRASS_1_END_X + 4 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	SDL_SetRenderDrawColor(render, 100, 180, 100, 0);
	SDL_RenderDrawLine(render, VERTICAL_GRASS_1_START_X + 1,
		VERTICAL_DISPLAY_START_Y, VERTICAL_GRASS_1_START_X + 1, VERTICAL_DISPLAY_END_Y - 1);

	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderDrawLine(render, VERTICAL_GRASS_1_START_X,
		VERTICAL_DISPLAY_START_Y, VERTICAL_GRASS_1_START_X, VERTICAL_DISPLAY_END_Y);

	SDL_SetRenderDrawColor(render,228, 137, 137, 0);
	rectangle.x = VERTICAL_STATUS_START_X;
	rectangle.y = VERTICAL_DISPLAY_START_Y;
	rectangle.w = VERTICAL_STATUS_END_X + 4 - rectangle.x;
	rectangle.h = VERTICAL_DISPLAY_END_Y - rectangle.y;
	SDL_RenderFillRect(render, &rectangle);

	Texture_Draw(VERTICAL_STATUS_START_X + 0, VERTICAL_DISPLAY_START_Y +  0, TEXTURE_LOGO);
	Texture_Draw(VERTICAL_STATUS_START_X + 20, VERTICAL_DISPLAY_START_Y + 168, TEXTURE_STATUS_SCORE);
	Texture_Draw(VERTICAL_STATUS_START_X + 8, VERTICAL_DISPLAY_START_Y + 200, TEXTURE_STATUS_BOX);
	Texture_Draw(VERTICAL_STATUS_START_X + 24, VERTICAL_DISPLAY_START_Y + 256, TEXTURE_STATUS_LEVEL);
	Texture_Draw(VERTICAL_STATUS_START_X + 8, VERTICAL_DISPLAY_START_Y + 288, TEXTURE_STATUS_BOX);
	Texture_Draw(VERTICAL_STATUS_START_X + 8, VERTICAL_DISPLAY_START_Y + 356, TEXTURE_STATUS_FLY);
}

static void vertical_Init(void) {
	int index;
	Vertical_key_up_pressed = SDL_FALSE;
	Vertical_key_down_pressed = SDL_FALSE;
	Vertical_key_right_pressed = SDL_FALSE;
	Vertical_key_left_pressed = SDL_FALSE;

	Vertical_separator_0_block_start_y = VERTICAL_DISPLAY_START_Y;
	Vertical_separator_1_block_start_y = VERTICAL_DISPLAY_START_Y + VERTICAL_SEPARATOR_HEIGHT_SPACE * 3;
	Vertical_player_car.pos_x = ((VERTICAL_ROAD_1_START_X + VERTICAL_ROAD_1_END_X - VERTICAL_PLAYER_CAR_IMAGE_SIZE_X) / 2);
	Vertical_player_car.dx = VERTICAL_PLAYER_CAR_IMAGE_SIZE_X;
	Vertical_player_car.pos_y = VERTICAL_DISPLAY_END_Y - VERTICAL_PLAYER_CAR_IMAGE_SIZE_Y - 1;
	Vertical_player_car.dy = VERTICAL_PLAYER_CAR_IMAGE_SIZE_Y;
	Vertical_player_car.image = TEXTURE_PLAYER_CAR;
	Vertical_player_car.image_fly = TEXTURE_PLAYER_CAR_FLY;
	Vertical_player_car.image_head_light = TEXTURE_PLAYER_CAR_HEAD_LIGHT;

	Vertical_opposite_car_type[0].dx = VERTICAL_OPPOSITE_CAR_0_IMAGE_SIZE_X;
	Vertical_opposite_car_type[0].dy = VERTICAL_OPPOSITE_CAR_0_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[0].image = TEXTURE_OPPOSITE_CAR_0;
	Vertical_opposite_car_type[0].speed = 16;
	Vertical_opposite_car_type[0].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_0_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[1].dx = VERTICAL_OPPOSITE_CAR_1_IMAGE_SIZE_X;
	Vertical_opposite_car_type[1].dy = VERTICAL_OPPOSITE_CAR_1_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[1].image = TEXTURE_OPPOSITE_CAR_1;
	Vertical_opposite_car_type[1].speed = 20;
	Vertical_opposite_car_type[1].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_1_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[2].dx = VERTICAL_OPPOSITE_CAR_2_IMAGE_SIZE_X;
	Vertical_opposite_car_type[2].dy = VERTICAL_OPPOSITE_CAR_2_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[2].image = TEXTURE_OPPOSITE_CAR_2;
	Vertical_opposite_car_type[2].speed = 28;
	Vertical_opposite_car_type[2].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_2_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[3].dx = VERTICAL_OPPOSITE_CAR_3_IMAGE_SIZE_X;
	Vertical_opposite_car_type[3].dy = VERTICAL_OPPOSITE_CAR_3_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[3].image = TEXTURE_OPPOSITE_CAR_3;
	Vertical_opposite_car_type[3].speed = 16;
	Vertical_opposite_car_type[3].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_3_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[4].dx = VERTICAL_OPPOSITE_CAR_4_IMAGE_SIZE_X;
	Vertical_opposite_car_type[4].dy = VERTICAL_OPPOSITE_CAR_4_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[4].image = TEXTURE_OPPOSITE_CAR_4;
	Vertical_opposite_car_type[4].speed = 16;
	Vertical_opposite_car_type[4].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_4_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[5].dx = VERTICAL_OPPOSITE_CAR_5_IMAGE_SIZE_X;
	Vertical_opposite_car_type[5].dy = VERTICAL_OPPOSITE_CAR_5_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[5].image = TEXTURE_OPPOSITE_CAR_5;
	Vertical_opposite_car_type[5].speed = 24;
	Vertical_opposite_car_type[5].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_5_IMAGE_SIZE_X) / 2;

	Vertical_opposite_car_type[6].dx = VERTICAL_OPPOSITE_CAR_6_IMAGE_SIZE_X;
	Vertical_opposite_car_type[6].dy = VERTICAL_OPPOSITE_CAR_6_IMAGE_SIZE_Y;
	Vertical_opposite_car_type[6].image = TEXTURE_OPPOSITE_CAR_6;
	Vertical_opposite_car_type[6].speed = 16;
	Vertical_opposite_car_type[6].dx_from_road = (VERTICAL_ROAD_WIDTH - VERTICAL_OPPOSITE_CAR_6_IMAGE_SIZE_X) / 2;

	for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
		Vertical_opposite_car[index].is_empty = SDL_TRUE;
		Vertical_opposite_car[index].is_add_score = SDL_FALSE;
	}

	Vertical_is_crashing = SDL_FALSE;
	Vertical_last_car_road = 0;
	Vertical_player_is_car_fly = SDL_FALSE;
	Vertical_score = 0;
	Vertical_level = 1;
	Vertical_pass = 0;
	Vertical_fly_count = 1;
	Vertical_fly_charger_count = 0;
}




static void vertical_Main(void) {
	if (Vertical_is_new_game != SDL_FALSE) {
		vertical_Init();
		Vertical_is_new_game = SDL_FALSE;
	}

	vertical_Render_Background();
	vertical_Render();

	if (using_new_background_ogg)
		Music_Play(MUSIC_BACKGROUND, -1);
	else
		Music_Play(MUSIC_BACKGROUND_LOWCOST, -1);
}

static void vertical_Key_Left_Pressed(void) {
	VERTICAL_RELEASE_ALL_KEY;
	Vertical_key_left_pressed = SDL_TRUE;
}

static void vertical_Key_Left_Released(void) {
	Vertical_key_left_pressed = SDL_FALSE;
}

static void vertical_Key_Right_Pressed(void) {
	VERTICAL_RELEASE_ALL_KEY;
	Vertical_key_right_pressed = SDL_TRUE;
}

static void vertical_Key_Right_Released(void) {
	Vertical_key_right_pressed = SDL_FALSE;
}

static void vertical_Key_Up_Pressed(void) {
	VERTICAL_RELEASE_ALL_KEY;
	Vertical_key_up_pressed = SDL_TRUE;
}

static void vertical_Key_Up_Released(void) {
	Vertical_key_up_pressed = SDL_FALSE;
}

static void vertical_Key_Down_Pressed(void) {
	VERTICAL_RELEASE_ALL_KEY;
	Vertical_key_down_pressed = SDL_TRUE;
}

static void vertical_Key_Down_Released(void) {
	Vertical_key_down_pressed = SDL_FALSE;
}

static void vertical_Key_Fly_Pressed(void) {
	if (Vertical_player_is_car_fly != SDL_FALSE)
		return;

	if (Vertical_fly_count > 0) {
		Vertical_player_is_car_fly = SDL_TRUE;
		Vertical_player_car_fly_duration = 0;
		Vertical_fly_count--;
	}
}

static void vertical_Keyboard_Key_Handler(Sint32 vkey_code, Sint32 key_state) {
	switch (vkey_code) {
		case SDLK_a:
		case SDLK_LEFT:
			(key_state) ? vertical_Key_Left_Pressed() : vertical_Key_Left_Released();
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			(key_state) ? vertical_Key_Right_Pressed() : vertical_Key_Right_Released();
			break;
		case SDLK_w:
		case SDLK_UP:
			(key_state) ? vertical_Key_Up_Pressed() : vertical_Key_Up_Released();
			break;
		case SDLK_s:
		case SDLK_DOWN:
			(key_state) ? vertical_Key_Down_Pressed() : vertical_Key_Down_Released();
			break;
		case SDLK_SPACE:
		case SDLK_RETURN:
			if (key_state)
				vertical_Key_Fly_Pressed();
			break;
		case SDLK_n:
		case SDLK_TAB:
			if (key_state) {
				if (!using_new_background_ogg)
					Music_Play(MUSIC_BACKGROUND, -1);
				else
					Music_Play(MUSIC_BACKGROUND_LOWCOST, -1);
				using_new_background_ogg = !using_new_background_ogg;
			}
			break;
		case SDLK_m:
			if (key_state) {
				if (volume_old == -1)
					volume_old = Mix_VolumeMusic(0);
				else {
					Mix_VolumeMusic(volume_old);
					volume_old = -1;
				}
			}
			break;
		case SDLK_q:
			if (key_state)
				exit_main_loop = SDL_TRUE;
			break;
	}
}

/* === LOGIC CODE === */

static void vertical_Crashing(void) {
	Music_Play(MUSIC_CRASH, 0);

	Vertical_is_crashing = SDL_TRUE;
	Vertical_crashing_count_down = 50;
}

static void vertical_New_Opposite_Car(void) {
	Sint16 index;
	Sint16 validIndex = 0;
	Sint16 no_slot;
	Sint16 car_type = 0;
	Uint8 road;
	Sint16 car_pos_x = 0;
	Sint16 car_shift;
	Sint16 enough_space;
	Sint16 rand_num;
	Sint16 speed_add;

	no_slot = SDL_TRUE;
	if ((rand() % VERTICAL_OPPOSITE_CAR_DEFAULT_APPEAR_RATE) == 0) {
		for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
			if (Vertical_opposite_car[index].is_empty != SDL_FALSE) {
				validIndex = index;
				no_slot = SDL_FALSE;
				break;
			}
		}
	}

	if (no_slot != SDL_FALSE)
		return;

	road = rand() % 3;

	if (road == Vertical_last_car_road) {
		road++;
		road %= 3;
	}

	if (Vertical_level < 3) {
		rand_num = rand() % 11;
		switch (rand_num) {
			case 0:
			case 1:
				car_type = 0;
				break;
			case 2:
			case 3:
			case 4:
				car_type = 1;
				break;
			case 5:
				car_type = 2;
				break;
			case 6:
			case 7:
				car_type = 3;
				break;
			case 8:
				car_type = 4;
				break;
			case 9:
				car_type = 5;
				break;
			case 10:
				car_type = 6;
				break;
		}
	}

	if (Vertical_level >= 3) {
		rand_num = rand() % 11;
		switch (rand_num) {
			case 0:
				car_type = 0;
				break;
			case 1:
			case 2:
				car_type = 1;
				break;
			case 3:
			case 4:
				car_type = 2;
				break;
			case 5:
			case 6:
				car_type = 3;
				break;
			case 7:
				car_type = 4;
				break;
			case 8:
			case 9:
				car_type = 5;
				break;
			case 10:
				car_type = 6;
				break;
		}
	}
	enough_space = SDL_TRUE;
	for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
		if ((Vertical_opposite_car[index].is_empty == SDL_FALSE) &&
			(Vertical_opposite_car[index].pos_y < (VERTICAL_PLAYER_CAR_IMAGE_SIZE_Y * 1.5)))
			enough_space = SDL_FALSE;
	}

	if (enough_space == SDL_FALSE)
		return;

	speed_add = Vertical_level - 1;

	Vertical_opposite_car[validIndex].is_empty = SDL_FALSE;
	Vertical_opposite_car[validIndex].is_add_score = SDL_FALSE;
	Vertical_opposite_car[validIndex].dx = Vertical_opposite_car_type[car_type].dx;
	Vertical_opposite_car[validIndex].dy = Vertical_opposite_car_type[car_type].dy;
	Vertical_opposite_car[validIndex].speed = Vertical_opposite_car_type[car_type].speed + speed_add;
	Vertical_opposite_car[validIndex].dx_from_road = Vertical_opposite_car_type[car_type].dx_from_road;
	Vertical_opposite_car[validIndex].image = Vertical_opposite_car_type[car_type].image;

	car_shift = Vertical_opposite_car[validIndex].dx_from_road;

	switch (road) {
	case 0:
		car_pos_x = VERTICAL_ROAD_0_START_X + car_shift;
		break;
	case 1:
		car_pos_x = VERTICAL_ROAD_1_START_X + car_shift;
		break;
	case 2:
		car_pos_x = VERTICAL_ROAD_2_START_X + car_shift;
		break;
	}

	Vertical_opposite_car[validIndex].pos_x = car_pos_x;
	Vertical_opposite_car[validIndex].pos_y = VERTICAL_DISPLAY_START_Y - Vertical_opposite_car[validIndex].dy;
	Vertical_opposite_car[validIndex].road_id = road;

	Vertical_last_car_road = road;
}




static void vertical_CollisionCheck(void) {
	Sint16 index;
	Sint16 minA_x, minA_y, maxA_x, maxA_y;
	Sint16 minB_x, minB_y, maxB_x, maxB_y;

	minA_x = Vertical_player_car.pos_x - 1;
	maxA_x = minA_x + Vertical_player_car.dx - 1;
	minA_y = Vertical_player_car.pos_y - 1;
	maxA_y = minA_y + Vertical_player_car.dy - 1;

	for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
		if (Vertical_opposite_car[index].is_empty == SDL_FALSE) {
			minB_x = Vertical_opposite_car[index].pos_x - 1;
			maxB_x = minB_x + Vertical_opposite_car[index].dx - 1;
			minB_y = Vertical_opposite_car[index].pos_y - 1;
			maxB_y = minB_y + Vertical_opposite_car[index].dy - 1;
			if (((minA_x <= minB_x) && (minB_x <= maxA_x)) || ((minA_x <= maxB_x) && (maxB_x <= maxA_x))) {
				if (((minA_y <= minB_y) && (minB_y <= maxA_y)) || ((minA_y <= maxB_y) && (maxB_y <= maxA_y))) {
					vertical_Crashing();
					return;
				}
			}

			if ((minA_x >= minB_x) && (minA_x <= maxB_x) && (minA_y >= minB_y) && (minA_y <= maxB_y)) {
				vertical_Crashing();
				return;
			}

			if ((minA_x >= minB_x) && (minA_x <= maxB_x) && (maxA_y >= minB_y) && (maxA_y <= maxB_y)) {
				vertical_Crashing();
				return;
			}

			if ((maxA_x >= minB_x) && (maxA_x <= maxB_x) && (minA_y >= minB_y) && (minA_y <= maxB_y)) {
				vertical_Crashing();
				return;
			}

			if ((maxA_x >= minB_x) && (maxA_x <= maxB_x) && (maxA_y >= minB_y) && (maxA_y <= maxB_y)) {
				vertical_Crashing();
				return;
			}

			if ((maxA_y < minB_y) && (Vertical_opposite_car[index].is_add_score == SDL_FALSE)) {
				Vertical_score++;
				Vertical_pass++;
				Vertical_opposite_car[index].is_add_score = SDL_TRUE;

				if (Vertical_pass == 10)
					Vertical_level++; /* level 2 */
				else if (Vertical_pass == 20)
					Vertical_level++; /* level 3 */
				else if (Vertical_pass == 30)
					Vertical_level++; /* level 4 */
				else if (Vertical_pass == 40)
					Vertical_level++; /* level 5 */
				else if (Vertical_pass == 50)
					Vertical_level++; /* level 6 */
				else if (Vertical_pass == 60)
					Vertical_level++; /* level 7 */
				else if (Vertical_pass == 70)
					Vertical_level++; /* level 8 */
				else if (Vertical_pass == 100)
					Vertical_level++; /* level 9 */

				Vertical_fly_charger_count++;
				if (Vertical_fly_charger_count >= 6) {
					if (Vertical_fly_count < VERTICAL_MAX_FLY_COUNT) {
						Vertical_fly_charger_count = 0;
						Vertical_fly_count++;
					} else
						Vertical_fly_charger_count--;
				}
			}
		}
	}
}

static void vertical_Framemove(void) {
	Sint16 shift;
	Sint16 max;
	Sint16 index;

	Vertical_player_car_fly_duration++;
	if (Vertical_player_car_fly_duration == VERTICAL_PLAYER_CAR_FLY_FRAME_COUNT)
		Vertical_player_is_car_fly = SDL_FALSE;

	shift = VERTICAL_PLAYER_CAR_SHIFT;
	if (Vertical_key_up_pressed) {
		if (Vertical_player_car.pos_y - shift < VERTICAL_DISPLAY_START_Y)
			shift = Vertical_player_car.pos_y - VERTICAL_DISPLAY_START_Y - 4;
		if (Vertical_player_is_car_fly == SDL_FALSE)
			Vertical_player_car.pos_y -= shift;
	}

	if (Vertical_key_down_pressed) {
		max = Vertical_player_car.pos_y + Vertical_player_car.dy;
		if (max + shift > VERTICAL_DISPLAY_END_Y)
			shift = VERTICAL_DISPLAY_END_Y - max;
		if (Vertical_player_is_car_fly == SDL_FALSE)
			Vertical_player_car.pos_y += shift;
	}

	if (Vertical_key_right_pressed) {
		max = Vertical_player_car.pos_x + Vertical_player_car.dx;
		if (max + shift > VERTICAL_ROAD_2_END_X)
			shift = VERTICAL_ROAD_2_END_X - max;
		Vertical_player_car.pos_x += shift;
	}

	if (Vertical_key_left_pressed) {
		if (Vertical_player_car.pos_x - shift < VERTICAL_ROAD_0_START_X)
			shift = Vertical_player_car.pos_x - VERTICAL_ROAD_0_START_X - 4;
		Vertical_player_car.pos_x -= shift;
	}

	for (index = 0; index < VERTICAL_OPPOSITE_CAR_COUNT; index++) {
		if (Vertical_opposite_car[index].is_empty == SDL_FALSE) {
			Vertical_opposite_car[index].pos_y += Vertical_opposite_car[index].speed;
			if (Vertical_opposite_car[index].pos_y > (VERTICAL_DISPLAY_END_Y + Vertical_opposite_car[index].dy))
				Vertical_opposite_car[index].is_empty = SDL_TRUE;
		}
	}

	if (Vertical_player_is_car_fly != SDL_FALSE) {
		shift = VERTICAL_PLAYER_CAR_FLY_SHIFT;
		if (Vertical_player_car.pos_y - shift < VERTICAL_DISPLAY_START_Y)
			shift = Vertical_player_car.pos_y - VERTICAL_DISPLAY_START_Y - 4;
		Vertical_player_car.pos_y -= shift;
	} else
		vertical_CollisionCheck();

	vertical_New_Opposite_Car();
}

/* === END LOGIC CODE === */

static void vertical_Cyclic_Timer(void) {
	if (Vertical_is_crashing == SDL_FALSE) {
		vertical_Framemove();
		vertical_Render();
	} else {
		Vertical_crashing_count_down--;
		if (Vertical_crashing_count_down >= 40)
			vertical_Render_Player_Car_Crash();
		else {
			if (Vertical_crashing_count_down == 39)
				Music_Play(MUSIC_GAMEOVER, 0);
			vertical_Show_Game_Over_Screen();
		}
		if (Vertical_crashing_count_down <= 0) {
			Vertical_is_crashing = SDL_FALSE;
			Vertical_is_new_game = SDL_TRUE;
			vertical_Main();
		}
	}
}

static void main_loop(SDL_Texture *texture) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit_main_loop = SDL_TRUE;
				break;
			case SDL_KEYDOWN:
				vertical_Keyboard_Key_Handler(event.key.keysym.sym, SDL_TRUE);
				break;
			case SDL_KEYUP:
				vertical_Keyboard_Key_Handler(event.key.keysym.sym, SDL_FALSE);
				break;
		}
	}
	SDL_SetRenderTarget(render, texture);
	vertical_Cyclic_Timer();
	SDL_SetRenderTarget(render, NULL);
	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = WINDOW_WIDTH1;
	rectangle.h = WINDOW_HEIGHT1;
	SDL_RenderCopy(render, texture, &rectangle, NULL);
	SDL_RenderPresent(render);
}

#ifdef __EMSCRIPTEN__
static void main_loop_emscripten(void *arguments) {
	CONTEXT_EMSCRIPTEN *context = arguments;
	main_loop(context->texture);
}
#endif
