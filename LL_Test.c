#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "linked_list.h"


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    tstr_node* head = NULL;
    char input[MAX_STR_LEN];
    int choice;

    do
    {
        printf("\n.1 for adding string to list\n.2 for removing string from list\n.3 for printing list\n.4 Deallocate entire list\n.5 for exit\n");
        scanf_s("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter string you want to add to list\n");
                fgets(input, MAX_STR_LEN, stdin);
                do
                {                    
                    fgets(input, MAX_STR_LEN, stdin);
                    cleanInput(input);
                    if(convertAndCheckForLetters(input) == LinkedList_OK)
                    {
                        sorted_list_insert(&head, create_node(input));
                    }
                    else
                    {
                        if(input[0] == '\0') {}
                        else {
                            printf("Please insert only letters!\n");
                        }
                    }
                }
                while (input[0] != '\0');
                break;

            case 2:
                printf("Enter the string you want to remove from the list\n");
                fgets(input, MAX_STR_LEN, stdin);
                do
                {
                    fflush(stdin);
                    fgets(input, MAX_STR_LEN, stdin);
                    cleanInput(input);
                    if(convertAndCheckForLetters(input) == LinkedList_OK)
                    {
                        tstr_node* temp = create_node(input);
                        sorted_list_remove(&head, temp);
                        free(temp);
                    }
                    else
                    {
                        if (input[0] == '\0') {}
                        else {
                            printf("Please insert only letters!\n");
                        }
                    }
                }while (input[0] != '\0');
                break;
            case 3:
                printf("Printing list members...\n");
                printListElements(&head);
                break;

            case 4:
                printf("Deallocating the list\n");
                deallocate(&head);
                break;

        }
    }while(choice!=5);
    free(head);
    _CrtDumpMemoryLeaks();

    return 0;
}
