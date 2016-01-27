#include <stdio.h>

enum enginestatus{
	PERFECT,
	NICE,
	GOOD,
	BAD,
	DANGEROUS
}enginestatus;

struct engine{
	unsigned int engineid;
	unsigned int ammount;
	const char * enginebrand;
	enum enginestatus estatus; 
};

static int showenginebrand(struct engine targetengine){
	printf("engine brand: %s\n",targetengine.enginebrand);
	return 0;
}

static int showengineid(struct engine targetengine){
	printf("engine id: %d\n",targetengine.engineid );
	return 0;
}

static int showenginestatus(struct engine targetengine){
	printf("engine status: %d\n",targetengine.estatus );
	return 0;
}

int showengineinfo(struct engine targetengine){
	printf("show engine info:\n");
	showengineid(targetengine);
	showenginebrand(targetengine);
	showenginestatus(targetengine);
	return 0;
}
