#include<stdio.h>
//Global variables
//Cipher Key
unsigned char cipherKey[44][4];
//Sbox
int sbox[256] = {
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }; //F
int rsbox[256] =
{ 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb
, 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb
, 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e
, 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25
, 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92
, 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84
, 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06
, 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b
, 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73
, 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e
, 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b
, 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4
, 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f
, 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef
, 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61
, 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

int Rcon[255] = {
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
	0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
	0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
	0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
	0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
	0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
	0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
	0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
	0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
	0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
	0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
	0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
	0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
	0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
	0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
	0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb };
//
//Function
//Function ReadFile
void ReadFile(char* nameFile, char* buff)
{
	FILE *ptr_file;
	ptr_file = fopen(nameFile, "r");
	if (!ptr_file)
		return;
	fread(buff, sizeof(char), 16, ptr_file);
	//printf("%s", buff);
	fclose(ptr_file);
}
//Function WriteFile
void WriteFile(char* nameFile, char* buff)
{
	FILE *ptr_file;
	ptr_file = fopen(nameFile, "w");
	if (!ptr_file)
		return;
	fwrite(buff, 1, 16, ptr_file);
	//printf("%s", buff);
	fclose(ptr_file);
}
//Function intialize first state 
void TrensferMessageInStateArray(char state[4][4], char* message)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = message[i * 4 + j];
		}
	}

}
//Function transfer encode Message
void TransferEncodeMessageToEncodeTable (char state[4][4], char* encode)
{
	for (int i = 0; i < 4 ; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			encode[i * 4 + j] = state[j][i];
		}
	}
}
//Function get value from Sbox matrix
int getValueFromSbox(int number)
{
	int valueFromSbox = sbox[number];
	return valueFromSbox;
}
//Function get value from InvSbox matrix
int getValueFromInvSbox(int number)
{
	int valueFromInvSbox = rsbox[number];
	return valueFromInvSbox;
}
//Function SubBytes
void SubBytes(char state[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = getValueFromSbox(state[i][j]);
		}
	}
}
//Function InvSubBytes
void InvSubBytes(char state[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = getValueFromInvSbox(state[i][j]);
		}
	}
}
//Function ShiftRows
void ShiftRows(char state[4][4])
{
	unsigned char valueToSave;
	for (int numOfRows = 1; numOfRows < 4; numOfRows++)
	{
		for (int j = 0; j < numOfRows; j++)
		{
			valueToSave = state[numOfRows][0];
			for (int i = 0; i < 4; i++)
			{
				if (i != 3)
					state[numOfRows][i] = state[numOfRows][i + 1];
				else
					state[numOfRows][i] = valueToSave;
			}
		}
	}
}
//Function InvShiftRows
void InvShiftRows(char state[4][4])
{

}
//Function MixColumns
void MixColumns(char state[4][4])
{
	unsigned char temp[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[j] = state[j][i];
		}
		state[0][i] = ((temp[0] << 1) ^ (temp[1] << 2)) ^ temp[2] ^ temp[3];
		state[1][i] = temp[0] ^ (temp[1] << 1) ^ (temp[2] << 2) ^ temp[3];
		state[2][i] = temp[0] ^ temp[1] ^ (temp[2] << 1) ^ (temp[3] << 2);
		state[3][i] = (temp[0] << 2) ^ temp[1] ^ temp[2] ^ (temp[3] << 1);
	}
}
//Function KeyExpansion
void KeyExpansion(unsigned char temp[4])
{
	//unsigned char temp[4];
	int Nk = 4;
	int Nb = 4;
	int Nr = 10;
	unsigned char temp_w;
	for (int i = Nk; i < Nb * (Nr + 1); i++)
	{
		for (int j = 0; j < Nk; j++)
		{
			temp[j] = cipherKey[(i - 1)][j];
		}
		if ((i % Nk) == 0)
		{
			//RotWord
			temp_w = temp[0];
			for (int r = 0; r < 3; r++)
			{
				temp[r] = temp[r + 1];
			}
			temp[3] = temp_w;
			//SubWord
			for (int s = 0; s < 4; s++)
			{
				temp[s] = getValueFromSbox(temp[s]);
			}
			temp[0] = temp[0] ^ Rcon[i / Nk];
		}
		else if (Nk > 6 && (i % Nk) == 4)
		{
			//SubWord
			for (int s = 0; s < 4; s++)
			{
				temp[s] = getValueFromSbox(temp[s]);
			}
		}
		cipherKey[i][0] = cipherKey[(i - Nk)][0] ^ temp[0];
		cipherKey[i][1] = cipherKey[(i - Nk)][1] ^ temp[1];
		cipherKey[i][2] = cipherKey[(i - Nk)][2] ^ temp[2];
		cipherKey[i][3] = cipherKey[(i - Nk)][3] ^ temp[3];
	}
}
//Function AddRoundKey
void AddRoundKey(char state[4][4], int iterRound)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = state[i][j] ^ cipherKey[i + 4 * iterRound][j];
		}
	}
}


// functionMain
int main()
{
	int numOfRound = 10;

	unsigned char message[16], state[4][4], encode[16];
	
	char* fileName = "message.txt";
	ReadFile(fileName, &message);
	TrensferMessageInStateArray(&state, message);

	char* fileNameKey = "Key.txt";
	unsigned char key[16];
	ReadFile(fileNameKey, &key);
	TrensferMessageInStateArray(&cipherKey, &key);

	unsigned char temp[4];
	KeyExpansion(&temp);

	AddRoundKey(&state, 0);
	for (int i = 1; i < numOfRound; i++)
	{
		SubBytes(&state);
		ShiftRows(&state);
		MixColumns(&state);
		AddRoundKey(&state, i);
	}
	SubBytes(&state);
	ShiftRows(&state);
	AddRoundKey(&state, numOfRound);


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", state[i][j]);
		}
		printf("\n");
	}

	TransferEncodeMessageToEncodeTable(&state, &encode);
	char* fileNameWrite = "EncodeMessage.txt";
	WriteFile(fileNameWrite, &encode);
	return 1;

}