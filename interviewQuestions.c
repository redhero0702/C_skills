#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(void)
{
	unsigned int a = 6;
	int b = -20;
	(a+b > 6) ? puts("> 6") : puts("<= 6");
}

/* bit operations by macros */
#define SET_BIT(x,n) ((x) |= (1<<n))
#define CLR_BIT(x,n) ((x) &=  ~(1<<n))
#define CHK_BIT(x,n) ((x) & (1<<n) != 0 )
#define FLIP_BIT(x,n) ( (x) ^= (1<<n) )

/* bit operations by using functions */
#define BIT3 (0x1 << 3)
void set_bit3(long a){
	a = a | BIT3;
};

void clear_bits(long a){
	a = a & ~BIT3;
};

void get_bits(long a){
	int mask = 1 << 3;
	int masked_n = a & mask;
	int targetbit = masked_n >> 3;
};

/* define a function with a integer as parameter and return type is integer */
int samplefunc(volatile int para){
	printf("sample func, parameter is : %d\n", para);
	return 0;
}

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
	int a_arr[3] = {1,2,3};
	int b_arr[3] = {1,2,3};

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

	/* check how to manipulate with arrays and pointers to array */
	char strAry[] = "This is string";
	char *aryPtr = strAry;
	int *intPtr = (int*)strAry;

	printf("\t[Line01] strAry=%s\n", strAry); // This is string
	printf("\t[Line02] aryPtr=%s\n", aryPtr); // This is string
	//printf("\t[LineX] *aryPtr=%s\n", *aryPtr); // Segmentation fault, '*aryPtr' is a char
	printf("\t[Line03] sizeof(aryPtr)=%lu\n", sizeof(aryPtr)); // output pointer size 8 on 64bits OS, or 4 on 32 bits OS
	printf("\t[Line04] sizeof(*aryPtr)=%lu\n", sizeof(*aryPtr)); // 1 
	printf("\t[Line05] *aryPtr='%c'\n", *aryPtr);// 'T'
	printf("\t[Line06] *aryPtr+1='%c'\n", *aryPtr+1);// 'U' 
	printf("\t[Line07] *(aryPtr+1)='%c'\n", *(aryPtr+1)); //'h'
	printf("\t[Line08] sizeof(intPtr)=%lu\n", sizeof(intPtr)); // output 8 pointer size 8 on 64 bits OS, or 4 on 32 bits OS
	printf("\t[Line09] sizeof(*intPtr)=%lu\n", sizeof(*intPtr));// output 4

	/*without using conversion from int* to char*, the compiler will warn: format specifies type 'char *' but the argument has type 'int *' [-Wformat]*/
	printf("\t[Line10] intPtr=%s\n", (char *) intPtr); // This is string

	//printf("\t[LineX] *intPtr=%s\n", *intPtr); // Segmentation fault, '*intPtr' is a int 
	printf("\t[Line11] *intPtr='%c'\n", *intPtr); // 'T'
	printf("\t[Line12] *intPtr+1='%c'\n", *intPtr+1);// 'U'
	printf("\t[Line13] *(intPtr+1)='%c'\n", *(intPtr+1));// output ' ', moving 4 bytes (int type) from the beginning of 'This is string'.

	/*show out the next shift of arr1, the offset is the size of arr1, &arr1 + 1*/
	int arr1[5] = {1,2,3,4,5};

	printf("the address of the arr1: %p\n", arr1);
	printf("the address of the next shift of arr1: %p\n", (&arr1+1));

	/* How to declare with pointers and callbacks*/
	int a; // an integer
	int *b;// a pointer to an integer
	int **c;// a pointer to a pointer to an integer
	int d[10];//  an array of 10 integers
	int *e[10]; //an array of ten pointers to integers
	int (*f)[10];//a pointer to a array of ten integers
	int (*g)(int);//callback, a pointer to a function that takes an integer as an argument and returns an integer
	int (*h[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer
	
	/*constants and pointers*/
	const int limit = 500;
	const int *ptr2constint;
	int *const constptr2int;


	/*read input as integer
	int length = -1;
	while (length < 0){
		printf("%s","please input your string length:");
		scanf("%u", &length);
		printf("length: %u\n", length);
		if (length > 0)
			break;
	}
	*/
	
	/*read input as char array
	char hotel[100];
	printf("%s","please input your string:");
	scanf("%s", &hotel);
	printf("output hotel : %s\n", hotel);
	*/

	/*read input string into an allocated space
	printf("input your name:");
	char *fullname = (char*) malloc(100);
	scanf("%s", fullname);
	printf("your name is   : %s\n", fullname);
	free(fullname);
	*/

	/* how to use fgets to read input string */
	char *name[100];
	fgets(name, 100, stdin);
	fputs(name,stdout);

	return 0;
}



