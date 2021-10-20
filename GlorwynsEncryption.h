#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//plan for A encryption: Provide a key that will seed random.
//Then, generate enough position swappers for the whole thing to shuffle it up.
//Next, for encrypting it, you need to just go through the arrays of posA/posB
//and swap each position, but each position would be the specific bit being thrown around.

//Long term, I'd want to incorporate a longer key that'd allow seeding random,
//multiplying sections of data, etc. Perhaps even duplicating and garbage data.
struct key {
	unsigned int keyA;
	unsigned int* pos;
	unsigned int size;

	unsigned int positionsGenerated;
};
typedef struct key Key;

void getBytes(unsigned char input, unsigned char* output);
char pressBytes(unsigned char* input);

char* encryptA(Key key, char* message);
char* decryptA(Key key, char* data);