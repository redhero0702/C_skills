#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE_X 4
#define SIZE_Y 4

typedef float fmatrix[SIZE_X][SIZE_Y];

int main(int argc, char *argv[]){

	//Note that the following assignment is not available.
	//fmatrix m1;
	//m1 = {{0}};
	//then the program will show ERROR MESSAGE BELOW
	//main.c:15:7: error: expected expression
	//        m1 = {{0}};

	fmatrix m1 = {{0}};
	fmatrix m2;

	
	int i;
	int j;
	for (i =0 ; i <SIZE_Y; i++){
		for (j =0; j<SIZE_Y; j++){
			printf ("m1[%d][%d] -> %f\n", i, j, m1[i][j]);
		}
	}
	
	return 0;
}
