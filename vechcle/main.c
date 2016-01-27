#include <stdio.h>
#include <stdlib.h>
#include "car.h"

int main(int argc, char *argv[]){
	printf("hello world, this is main func\n");
	CAR c1;
	printf("brand: %s\n", c1.brand);
	printf("power: %d\n", c1.power);
	printf("status: %d\n", c1.carstatus);
	initCar(&c1, "BMW", 3, STOPPED);
	showCar(c1);
	checkCar(&c1);
	return 0;
}
