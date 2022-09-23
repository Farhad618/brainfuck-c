#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head, *presentPointer;
int pointerat = 0;
int br = 0;

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

	int setTimer = atoi(argv[2]);

	if( argc > 3 ) {
	     printf("Too many arguments supplied.\nbfc <filename> <millisecond>");
	     return 0;
	}
	else if(argc < 3){
	     printf("Two argument expected.\nbfc <filename> <millisecond>");
	     return 0;
	}

	FILE *fp;
	fp = fopen(argv[1],"r");
	char ch;

	if (!fp)
	{
		printf("Cannot open this file.");
		return 0;
	}

	while (!feof(fp)) {		
	    ch = fgetc(fp);

	    switch(ch) {
	    	case '+':
	    		incvalue();
	    		break;
	    	case '-':
	    		decvalue();
	    		break;
	    	case '>':
	    		incpointer();
	    		break;
	    	case '<':
	    		decpointer();
	    		break;
	    	case '.':
	    		printvalue();
	    		break;
	    	case ',':
	    		inputvalue();
	    		break;
	    	case '[':
	    		br = 1;
	    		if (presentPointer->data == 0)
	    		{
	    			while(br){
	    				ch = fgetc(fp);
	    				if (ch == '[')
	    				{
	    					br++;
	    				} else if (ch == ']')
	    				{
	    					br--;
	    				}
	    			}
	    		}
	    		break;
	    	case ']':
	    		br = 1;
	    		while(br){
					fseek(fp, -2, SEEK_CUR);
	    			ch = fgetc(fp);
	    			
	    			if (ch == '[')
	    			{
	    				br--;
	    			} else if (ch == ']')
	    			{
	    				br++;
	    			}
	    		}
	    		fseek(fp, -1, SEEK_CUR);
	    		break;
	    	default:
	    		continue;
	    }

		if (setTimer)
		{
			printf("\r");
			printall();
			Sleep(setTimer);			
		}

	}

	if (!setTimer)
	{
		printall();
	}

	return 0;
}


void printall(){ // memory cell
	struct node *tmpptr = head;
	int i=0;
    while (tmpptr != NULL)
    {
        if (pointerat == i)
        {
        	printf("[%d]\t", tmpptr->data);
        } else {
        	printf("%d\t", tmpptr->data);
        }
        i++;
        tmpptr = tmpptr->next;
    }
}

void placePointer(){ // currently not useful

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
		printf("%c\n", presentPointer->data);
	}
}