#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* how to explain volatile */
int square(volatile int *ptr){
	return *ptr * *ptr;
}

/* 
// the previous square function is equal to the function shown below, the values of a and b are perhaps not the same. 
int square(volatile int *ptr) {
	int a,b;
	a = *ptr;
	b = *ptr;
	return a * b;
}

// the best way to implement the square will be described as below.
int square(volatile int *ptr) {
	int a;
	a = *ptr;
	return a * a;
}
*/

/* how to implement strcmp function */
int mystrcmp(const char* str1, const char* str2){
	int length = strlen(str1);
	int i;

	printf("str1 -> %s\n", str1);
	printf("str2 -> %s\n", str2);
	printf("length -> %d\n", length);

	if ( strlen(str1) != strlen(str2))
		return -1;

	for ( i = 0; i < length; i++){
		if (*(str1+i) != *(str2+i)){
			return -1;
		}
	} 
	return 0;
}

/* how to compare elements of two arrays */
int compareArray(int *arr1, int *arr2){
	int elements = sizeof(arr1) / sizeof (int);
	if (sizeof(arr1) != sizeof(arr2)){
		return -1;
	} else{
		int i;
		for (i = 0; i < elements; i++ ){
			if ( arr1[i] != arr2[i])
				return -1;
		}
		return 0;
	}
}

/* how to write a function without any parameter */ 
void fun1(void) {
	static int varinfun1;
	printf("hello fun1\n");
}

int main(void){
	/*how to dynamically allocate memory space with malloc*/
	int *ptr = (int *) malloc(sizeof(int));

	printf("the value of ptr: %d\n", *ptr);
	printf("the address of ptr: %p\n", ptr);
	printf("the address which ptr points to: %p\n", ptr);
	
	/* how to initialize two arrays */
	int a[3] = {1,2,3};
	int b[3] = {1,2,3};

	/* sizeof operator and strlen function*/
	const char* name1= "helloworld";
	const char* name2= "helloworld";
	printf("sizeof(name1) -> %lu\n", sizeof(name1)); // calculate the size of pointer
	printf("strlen(name1) -> %lu\n", strlen(name1)); // calculate the length of the string
	printf("sizeof(char) -> %lu\n", sizeof(char));  // calculate the size for a char type variable

	/*user-defined type*/
	typedef struct {
		const char *name;
		const char *ID;
	}CUSTOM;

	CUSTOM c1 = {"John Wang", "A123456789"};
	printf("custom name: %s\n",c1.name);
	printf("custom ID  : %s\n",c1.ID);

}



