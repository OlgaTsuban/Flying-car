#include "../inc/random.h"

int random_range(int min, int max) {
	return rand() % (max - min + 1) + min;
}

