#include<stdio.h>

void main()
{
	FILE *ptr_file;
	char buf[1000];

	ptr_file = fopen("message.txt", "r");
	if (!ptr_file)
		return;

	while (fgets(buf, 1000, ptr_file) != NULL)
	{
		printf("%s", buf);
	}
	printf("%c\n", buf[2]);
	char temp = buf[2];
	printf("%c\n", buf[4]);

	fclose(ptr_file);

}