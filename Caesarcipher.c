#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void encrypt(char *ch , char *res , int key); //function for encrypt inputs(character array needs to convert,pointer to results , key)
void decrypt(char *ch , char *res , int key); //function for decrypt inputs(character array needs to convert,pointer to results , key)

int main(int argc , char *argv[])
{
	
	if(argc != 3)
	{
		printf("<.\\Caesarcipher.exe> [options] <\"Text\">\n");
		printf("[options] : -e <\"plainText\">   To encrypt\n");
		printf("            -d <\"cipherText\">  To decrypt\n");
		return 0;
	}
	//take input arguments
	char *text = argv[2];
	char *result;
	result = (char *)malloc(strlen(text)*sizeof(char));
	
	if(result == NULL)
	{
		printf("memory allocation failed");
	}
	
	//encrypt data
	if(strcmp(argv[1] , "-e") == 0)
	{
		encrypt(text , result , 3);
		printf("%s" , result);
	}
	
	//decrypt data
	else if(strcmp(argv[1] , "-d") == 0)
	{
		decrypt(text , result , 3);
		printf("%s" , result);
		
	}
	else
	{
		printf("<.\\Caesarcipher.exe> [options] <\"Text\">\n");
		printf("[options] : -e <\"plainText\">   To encrypt\n");
		printf("            -d <\"cipherText\">  To decrypt\n");
	}
	free(result);
	return 0;
}


void encrypt(char *ch , char *res , int key)
{
	
	int i;
	
	//for loop for convert characters in input char array(encrypt)
	//shift characters by value of key(in casesarcipher key = 3)
	for(i=0; i < strlen(ch) ; i++)
	{
		
		//res[i] = (ch[i]+key)mod 26
		//In here im not going to use modulo oparetion
		if(ch[i] >= 'A' &&  ch[i] <= 'Z' )
		{
			//case 1. key + ch[i] > 'Z'
			if(ch[i]+key  > 'Z')
				res[i] = 'A' - 1 + ch[i]+key - 'Z'; 	//formula to get converted char after exceeding 'Z'
			//case 2. key + ch[i] <= 'Z'
			else
				res[i] = ch[i]+key ;
		}
		//encrypt lower case letters
		else if(ch[i] >= 'a' && ch[i] <= 'z')
		{
			if(ch[i]+key  > 'z')
				res[i] = 'a' - 1 + ch[i]+key - 'z';
			else
				res[i] = ch[i]+key;
		}
		else
		{	
			//if character is not in alphabet
			//will not encrypt		
			res[i] = ch[i];
		}
		
		
	}
	res[i] = '\0';
}

void decrypt(char *ch , char *res , int key)
{	

	int i;
	
	//for loop for convert characters in input char array(decrypt)
	//shift characters by value of key(in casesarcipher key = 3)
	for(i=0; i < strlen(ch) ; i++)
	{
		//res[i] = (ch[i] - key)mod 26
		//In here im not going to use modulo oparetion
		// (character - key) have 2 cases
		if(ch[i] >= 'A' &&  ch[i] <= 'Z' )
		{
			//case 1. key - character < 'A'
			if(ch[i]-key  < 'A')
				res[i] = 'Z' + 1 - ('A' - (ch[i]-key));  	//formula to get converted char after exceeding 'A' (char - key)
			//case 2. key - character >= 'A'	
			else
				res[i] = ch[i]-key ;
		}
		else if(ch[i] >= 'a' && ch[i] <= 'z')
		{
			if(ch[i]-key  < 'a')
				res[i] = 'z' + 1 - ('a' - (ch[i]-key)); 
			else
				res[i] = ch[i]-key;
		}
		else
		{
			res[i] = ch[i];
		}
		
		
	}
	res[i] = '\0';
}
