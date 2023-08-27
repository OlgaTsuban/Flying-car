#include "../inc/linked_list.h"

t_list *create_node(void *data) {
	t_list *node = malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return node;
}

void push_back(t_list **list, void *data) {
	t_list *new_node = create_node(data);
	t_list *last_node = *list;
	if (last_node != NULL) {
		for ( ; last_node->next != NULL; last_node = last_node->next) { }
		last_node->next = new_node;
	} else {
		*list = new_node;
	}
}

void pop_back(t_list **list) {
	t_list *penultimate_node = NULL;
	t_list *last_node = *list;
	for ( ; last_node->next != NULL; last_node = last_node->next)
		penultimate_node = last_node;
	if (last_node == *list)
		*list = NULL;
	free(last_node);
	if (penultimate_node != NULL)
		penultimate_node->next = NULL;
}

void pop_front(t_list **list) {
	t_list *second_node = (*list)->next;
	free(*list);
	*list = NULL;
	if (second_node != NULL)
		*list = second_node;
}

void pop_index(t_list **list, int index) {
	if (index < 0)
		index = 0;
	if (index == 0) {
		pop_front(list);
		return;
	}
	t_list *prev_node = *list;
	for (int i = 1; i < index && prev_node->next != NULL; ++i) {
		prev_node = prev_node->next;
	}
	if (prev_node->next == NULL) {
		pop_back(list);
		return;
	}
	t_list *next_node = prev_node->next->next;
	free(prev_node->next);
	prev_node->next = next_node;
}

void clear_list(t_list **list) {
	t_list *current_node = *list;
	while (current_node != NULL) {
		t_list *next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*list = NULL;
}

