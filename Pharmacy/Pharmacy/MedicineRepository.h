#pragma once
#include "Medicine.h"

typedef struct
{
	Medicine medicines[100];
	int length;
}MedicineRepo;

/*
Creates a repository for the medicines.
*/
MedicineRepo createRepo();


/*
Checks if a medicine does already exists
Input:   v - Pointer to the MedicineRepo
	     name = The medicine name
Returns: pos - if it exists (pos = position)
	     -1 - not founded
*/ 
int find(MedicineRepo *v, char name[]);


/*
Adds a new medicine to the repository
Input:  v - Pointer to the MedicineRepo
Output: 1 - if it does not exist
	    0 - if it exists
*/
int add(MedicineRepo *v, Medicine m);


/*
Deletes a medicine from the repository
Input:  v - Pointer to the MedicineRepo
Output: 1 - if it has been deleted
	    0 - if it does not exist
*/
int delete(MedicineRepo *v, Medicine m);


/*
Deletes a medicine from the repository
Input:  v - Pointer to the MedicineRepo
Output: 1 - if it has been updated
	    0 - if it does not exist
*/
int update(MedicineRepo *v, Medicine m);


/*
Returns the length of the repo.
*/
int getLength(MedicineRepo *v);

/*
Returns the medicine from the position 'pos'.
*/
Medicine *getMedicineOnPos(MedicineRepo *v, int pos);


void testsMedicineRepo();

