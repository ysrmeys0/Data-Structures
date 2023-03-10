#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
	struct Node* prev;
} Node;

Node* newNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void deleteAllNodes(Node* head)
{
	Node *ptr1, *ptr2, *dup;
	ptr1 = head;

	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		while (ptr2->next != NULL) 
        {
			if (ptr1->data == ptr2->next->data) 
            {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else
            {
                ptr2 = ptr2->next;
            }
		}
		ptr1 = ptr1->next;
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
		
	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) 
    {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 2);
	push(&head, 1);
	push(&head, 8);
	push(&head, 10);
    push(&head, 8);
    push(&head, 5);
    push(&head, 5);
    push(&head, 9);
    push(&head, 8);
    push(&head, 1);

	printf("\n Original Linked list ");
	printList(head);

    deleteAllNodes(head);
    printf("\n Modified Linked list ");
	printList(head);

	getchar();
}