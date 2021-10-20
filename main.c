#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GlorwynsEncryption.h"


void main() {
	char* input = "This is a test message that may or may not have been a replacement for a previous one.";
	srand(time(NULL));
	
	Key key;
	key.keyA = rand();
	key.size = strlen(input);
	char* encrypted = encryptA(key, input);
	printf("Encrypted: %s\n", encrypted);
	printf("Decrypted: %s\n", decryptA(key, encrypted));
	







}