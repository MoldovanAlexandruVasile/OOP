#pragma once
#include "MedicineRepository.h"

typedef struct
{
	MedicineRepo *repo;
}Controller;

Controller createController(MedicineRepo *r);

/*
Adds a new medicine in the repository
returns 
*/
int addMedicine(Controller *c, char name[], double concentration, double quantity, double price);

MedicineRepo *getRepo(Controller *c);

/*
Returns a repository of planets that have the given string
*/
MedicineRepo filterByName(Controller *c, char name[]);
