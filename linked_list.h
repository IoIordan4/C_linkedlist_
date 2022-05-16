#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define MAX_STR_LEN 64

enum LinkedL_status { LinkedList_OK = 0, LinkedList_NOK = -1 };

typedef struct tstr_node {
	char data[MAX_STR_LEN];
	struct tstr_node *next;
} tstr_node;

struct tstr_node* create_node(char* input);

int sorted_list_insert(tstr_node** head, tstr_node* pstr_node);

int sorted_list_remove(tstr_node** head, tstr_node* pstr_node);

int printListElements(tstr_node** head);

int deallocate(tstr_node** head);

int cleanInput(char* input);

int convertAndCheckForLetters(char* givenStr);

#endif