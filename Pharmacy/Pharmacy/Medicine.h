#pragma once

typedef struct
{
	char name[50];
	double concentration;
	double quantity;
	double price;
}Medicine;

Medicine createMedicine(char name[], double concentration, double quantity, double price);
char *getName(Medicine *m);
double getConcentration(Medicine *m);
double getQuantity(Medicine *m);
double getPrice(Medicine *m);

void toString(Medicine m, char str[]);