#include "GlorwynsEncryption.h"


void getBytes(unsigned char input, unsigned char* output) {
	int worth = 1;
	for (int c = 7; c >= 0; c--) {
		if (input & worth) {
			output[c] = 1;
		}
		else {
			output[c] = 0;
		}
		worth *= 2;
	}
}

char pressBytes(unsigned char* input) {
	int worth = 1;
	unsigned char output = 0;
	for (int c = 7; c >= 0; c--) {
		if (input[c] == 1) {
			output += input[c] * worth;
		}
		worth *= 2;
	}
	return(output);
}


char* encryptA(Key key, char* message) {
	//key.size = strlen(message);
	srand(key.keyA * key.size);
	
	char* decompressed = calloc(key.size * 8, sizeof(unsigned char));
	for (int c = 0; c < key.size; c++) {
		getBytes(message[c], &decompressed[c * 8]);
	}
	
	char temp = 0;
	key.pos = calloc((key.size * 8) , sizeof(int));
	for (int c = (key.size * 8) - 1; c >= 1; c--) {
		temp = decompressed[c];
		key.pos[c] = rand() % c;
		decompressed[c] = decompressed[key.pos[c]];
		decompressed[key.pos[c]] = temp;
	}
	
	char* compressed = calloc(key.size + 1, sizeof(unsigned char));
	for (int c = 0; c < key.size; c++) {
		compressed[c] = pressBytes(&decompressed[c * 8]);
	}

	compressed[key.size + 1] = '\0';
	free(decompressed);
	return(compressed);

}

char* decryptA(Key key, char* data) {
	//key.size = strlen(data);
	srand(key.keyA * key.size);

	char* decompressed = calloc(key.size * 8, sizeof(unsigned char));
	for (int c = 0; c < key.size; c++) {
		getBytes(data[c], &decompressed[c * 8]);
	}

	char temp = 0;
	key.pos = calloc((key.size * 8), sizeof(int));
	for (int c = (key.size * 8) - 1; c >= 1; c--) {
		key.pos[c] = (int)rand() % c;
	}
	for (int c = 1; c < key.size * 8; c++) {
		temp = decompressed[c];
		decompressed[c] = decompressed[key.pos[c]];
		decompressed[key.pos[c]] = temp;
	}

	char* compressed = calloc(key.size + 1, sizeof(unsigned char));
	for (int c = 0; c < key.size; c++) {
		compressed[c] = pressBytes(&decompressed[c * 8]);
	}

	compressed[key.size + 1] = '\0';
	free(decompressed);
	return(compressed);

}