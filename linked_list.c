#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linked_list.h"

struct tstr_node* create_node(char* input)
{

    tstr_node* pstr_node = malloc(sizeof(tstr_node));
    if (pstr_node == NULL)
    {
        exit(LinkedList_NOK);
    }
    strcpy(pstr_node->data, input);
    pstr_node->next = NULL;
    return pstr_node;
}

int sorted_list_insert(tstr_node** head, tstr_node* pstr_node)
{
    
    if (head == NULL)
    {
        return LinkedList_NOK;
    }

    tstr_node* curr;
    if(*head == NULL || strcmp(((*head)->data), pstr_node->data) > 0)
    {
        pstr_node->next = *head;
        *head = pstr_node;
        return LinkedList_OK;
    }
    else
    {
        curr = *head;
        while( curr->next != NULL && strcmp(curr->next->data, pstr_node->data) < 0)
        {
            curr = curr->next;
        }
        pstr_node->next = curr->next;
        curr->next = pstr_node;
        return LinkedList_OK;
    }
    return LinkedList_NOK;
}

int sorted_list_remove(tstr_node **head, tstr_node* pstr_node)
{
    if (head == NULL || *head == NULL) {
        printf("List is already empty\n");
        return LinkedList_NOK;
    }
    struct tstr_node *curr, *previous;
    curr = *head;
    previous = *head;

    if(strcmp((char*)curr, (char*)pstr_node->data)==0)
    {
        *head = curr->next;
        free(curr);
    }
    else
    {
        while(strcmp((char*)curr, (char*)pstr_node->data)!=0)
        {
            previous = curr;
            curr = curr->next;
        }
        previous->next = curr->next;
        free(curr);
    }
    return LinkedList_OK;
}

int printListElements(tstr_node** head)
{
    if (*head == NULL)
    {
        printf("Link is empty!\n");
        return LinkedList_NOK;
    }

    int size = 0;
    struct tstr_node *curr;
    curr = *head;

    while(curr != NULL)
    {
        printf("%s\n", curr->data);
        curr = curr->next;
        size++;
    }
    free(curr);
    printf("Size of Linked List is: %d\n", size);
    return LinkedList_OK;
}

int deallocate(tstr_node** head)
{
    if (head == NULL) {
        return LinkedList_NOK;
    }
    tstr_node* curr = *head;
    while(curr != NULL)
    {
        curr = curr->next;
        free(*head);
        *head = curr;
    }
    return LinkedList_OK;
}

int cleanInput(char* input)
{
    if (strlen(input) == 0) {
        return LinkedList_NOK;
    }
    int len;
    len = strlen(input);
    int i;
    for (i = 0; i < len-1; i++) {}
    input[i] = '\0';
    return LinkedList_OK;
}

int convertAndCheckForLetters(char* givenStr)
{

    int i;
    if (givenStr[0] == ' ' || givenStr[0] == '\0')
    {
        return LinkedList_NOK;
    }
    for (i = 0; givenStr[i] != '\0'; i++)
    {
        if ((givenStr[i] >= 'a' && givenStr[i] <= 'z') || (givenStr[i] >= 'A' && givenStr[i] <= 'Z') || (givenStr[i] == ' '))
        {
            if (givenStr[i] >= 'A' && givenStr[i] <= 'Z')
            {
                givenStr[i] = givenStr[i] + 32;
            }
        }
        else
        {
            return LinkedList_NOK;
        }
    }
    return LinkedList_OK;
}