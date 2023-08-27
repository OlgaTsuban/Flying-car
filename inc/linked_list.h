#pragma once

#include "base_includes.h"

typedef struct s_list {
	void *data;
	struct s_list *next;
} t_list;

t_list *create_node(void *data);
void pop_front(t_list **list);
void push_back(t_list **list, void *data);
void pop_index(t_list **list, int index);
void clear_list(t_list **list);

