#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head, *presentPointer;
int pointerat = 0;


void printall();
void placePointer();
void incpointer(); // >
void decpointer(); // <
void incvalue(); // +
void decvalue(); // -
void inputvalue(); // ,
void printvalue(); // .

int main(int argc, char const *argv[])
{
	head = (struct node *) malloc(sizeof(struct node));
	head->prev = NULL;
	head->data = 0;
	head->next = NULL;
	presentPointer = head;

	// incpointer();
	// incpointer();
	// decvalue();
	// decpointer();
	// incvalue();
	// decpointer();
	// inputvalue();
	inputvalue();
	printvalue();


	printf("\n");
	printf("\n");
	printall();
	printf("\n");
	placePointer();
	return 0;
}


void printall(){ // memory cell
	struct node *tmpptr = head;
    while (tmpptr != NULL)
    {    
        // printf("%d %d %d\n", tmpptr->prev, tmpptr, tmpptr->next);
        printf("%d\t", tmpptr->data);
        tmpptr = tmpptr->next;
    }
}

void placePointer(){

	for (int i = 0; i < pointerat; ++i)
	{
		printf("\t");
	}
	printf("^");
}

void incpointer(){
	pointerat++;
	if (presentPointer->next)
	{
		presentPointer = presentPointer->next;
	} else {
		struct node *new_node = (struct node *) malloc(sizeof(struct node));
		presentPointer->next = new_node;
		new_node->prev = presentPointer;
		new_node->data = 0;
		new_node->next = NULL;
		presentPointer = new_node;
		// free(new_node);
	}
}

void decpointer(){
	if (presentPointer->prev)
	{
		pointerat--;
		presentPointer = presentPointer->prev;
	}
}

void incvalue(){
	if (presentPointer)
	{
		presentPointer->data++;
	}
}

void decvalue(){
	if (presentPointer)
	{
		presentPointer->data--;
	}
}

void inputvalue(){
	if (presentPointer)
	{
		printf("> ");
		scanf(" %c", &presentPointer->data);
	}
}

void printvalue(){
	if (presentPointer)
	{
		printf("%c", presentPointer->data);
	}
}