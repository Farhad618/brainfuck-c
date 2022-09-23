// file_content_reverse_read_test.c

#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch;

	fp = fopen("file3.txt", "r");

	while (ch != ']') {
	    ch = fgetc(fp);
	    printf("%c", ch);
	}

	printf("\n");

	/*// ftell(fp);
	while(ch != '['){
		ch = fgetc(fp);
		printf("%c", ch);
		fseek(fp, -2, SEEK_CUR);
	}*/

	/*fseek(fp, -2, SEEK_CUR);
	ch = fgetc(fp);
	fseek(fp, -2, SEEK_CUR);
	ch = fgetc(fp);*/

	printf("%i %c", ftell(fp), ch);

	int br = 1, i=0;

	while(br){
		fseek(fp, -2, SEEK_CUR);
		ch = fgetc(fp);
		printf("{");
		printf(">%c<", ch);
		printf("}\n");
		
		if (ch == '[')
		{
			br--;
		} else if (ch == ']')
		{
			br++;
		}

	}

	return 0;
}