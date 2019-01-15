// CSE 5462 Lab1
// Woongki Lee

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	int size;
	char word[20];
	int length;
	int check = 0;
	int count = 0;
	int p = 0;
	char words[10000];
	int t = p + check;

	if(argc!=4){
		printf("The number of arguments is wrong.\n");
		return -1;
	}

	// file open	
	if (( fp = fopen(argv[1], "r")) == NULL ){
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	
	length = strlen(argv[2]);

	// read file
	fscanf(fp, "%s", word);
	strcpy(words, word);

	while (fscanf(fp, "%s", word) == 1)
	{
		strcat(words, " ");
		strcat(words, word);		
	}

	printf("%s\n", words);

	// find words
	while (words[p]){

		printf("p = %d\n", p);

		while (check < length && argv[2][check]) {
			t = p + check;
			printf("check = %d\n", check);
			if(words[t]==argv[2][check]){
				check++;	
			}else{
				break;
			}
		}

		if(check == length) count++;

		p++;
		check = 0;
	}

	//file size
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	fclose(fp);
	
	// write file
	fp = fopen(argv[3], "w");
	fprintf(fp, "Size of file is %d\n", size);
	fprintf(fp, "Number of matches = %d\n", count);
	printf("Size of file is %d\n", size);
	printf("Number of matches = %d\n", count);

} 
