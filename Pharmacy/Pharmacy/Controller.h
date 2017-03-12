#pragma once
#include "MedicineRepository.h"

typedef struct
{
	MedicineRepo *repo;
}Controller;

/*
Creates a controller based on the repository of the medicines.
*/
Controller createController(MedicineRepo *r);

/*
Adds a new medicine in the repository. 
*/
int addMedicine(Controller *c, char name[], double concentration, double quantity, double price);

/*
Deletes a medicine from the repository.
*/
int deleteMedicine(Controller *c, char name[], double concentration, double quantity, double price);

/*
Uploades a medicine from the repository.
*/
int updateMedicine(Controller *c, char name[], double concentration, double quantity, double price);


MedicineRepo *getRepo(Controller *c);

/*
Returns a repository of medicines that have the given string.
*/
MedicineRepo filterByName(Controller *c, char name[]);
