#include<stdio.h>

//Function
void ReadFile(char* nameFile, char* buff)
{
	FILE *ptr_file;
	ptr_file = fopen(nameFile, "r");
	if (!ptr_file)
		return;
	fgets(buff, 16, ptr_file);
	//printf("%s", buff);
	fclose(ptr_file);
}
void SubBytes()
{

}
// functionMain
int main()
{
	
	unsigned char message[16], state[4][4];
	char* fileName = "message.txt";
	ReadFile(fileName, message);
	
	
	return 1;

}