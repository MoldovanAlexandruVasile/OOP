#include "Medicine.h"
#include <string.h>
#include <stdio.h>

Medicine createMedicine(char name[], double concentration, double quantity, double price)
{
	Medicine m;
	strcpy(m.name, name);
	m.concentration = concentration;
	m.quantity = quantity;
	m.price = price;

	return m;
}

char *getName(Medicine *m)
{
	return m->name;
}

double getConcentration(Medicine *m)
{
	return m->concentration;
}

double getQuantity(Medicine *m)
{
	return m->quantity;
}

double getPrice(Medicine *m)
{
	return m->price;
}

void toString(Medicine m, char str[])
{
	sprintf(str, "       Medcine: %-15s         Concentration: %-7.2lf        Quantity: %-7.2lf         Price: %-7.2lf", m.name, m.concentration, m.quantity, m.price);
}