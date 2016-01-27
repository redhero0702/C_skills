enum status{
	STOPPED,
	READY,
	RUNNING
};

typedef struct car{
	const char *brand;
	int power;
	enum status carstatus;
}CAR;

/*forward declaration, it enables to encapsulate a module */
struct X;

/*a Thing structure contains another structure X*/
struct Thing {
	int i;
	struct X* x_ptr;
};


int initCar(CAR *car, const char *brand, const int power, const enum status carstatus);
int showCar(CAR car);
int checkCar(CAR *car);
int start(CAR *car);
