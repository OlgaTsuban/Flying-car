#pragma once

#include "base_includes.h"
#include "player.h"
#include "renderer.h"
#include "vector2.h"
#include "object.h"
#include "objects_spawner.h"
#include "show.h"
#include "string.h"
#include "file.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define START_OBJECTS_SPEED 7
#define PATH_TO_SAVE_FILE "resource/save.dat"

static t_vector2 START_PLAYER_POS = {WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2};
