#include "car.h"
#include <stdio.h>
#include <stdlib.h>

int start(CAR *car){
	int OPERCODE;
	switch (car->carstatus){
		case STOPPED:
			car->carstatus = READY;
			OPERCODE = 0;
			break;
		case READY:
			OPERCODE = -1;
			break;
		case RUNNING:
			OPERCODE = -2;
			break;
	}
	return OPERCODE;
}

int initCar(CAR *car, const char *brand, const int power, const enum status carstatus){
	int initresult = 0;
	car->brand = brand;
	car->power = power;
	car->carstatus = carstatus;
	return initresult;
}

int showCar(CAR car){
	int initresult = 0;
	printf("brand:%s, power:%d, status:%d\n", 
	car.brand, 
	car.power,
	car.carstatus);
	return initresult;
}

static int enginetest(CAR *car){
	if (car->brand != NULL)
		return 0;
	else
		return 	-1;
}

int checkCar(CAR *car){
	printf("checking your car, %s...\n",car->brand);
	if (enginetest(car) == 0){
		printf("no issue with the car\n");
		return 0;
	} else{
		printf("The car needs to be repaired.\n");
		return -1;
	}
}

struct X{
	int xmember1;
	int xmember2;
};

int testThing(void){
	struct X xinstance;
	xinstance.xmember1 = 1;
	xinstance.xmember2 = 2;
	return 0;
}

