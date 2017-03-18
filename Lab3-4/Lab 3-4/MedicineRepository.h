#pragma once
#include "Medicine.h"

typedef struct
{
	Medicine** medicines;
	int length;
} MedicineRepo;

/// <summary>
/// Creates a MedicineRepo.
/// </summary>
MedicineRepo* createRepo();

/// <summary>
/// Destroys a given medicine repository. The memory is freed.
/// </summary>
void destroyRepo(MedicineRepo* v);

/// <summary>
/// Finds the medicine with the given name.
/// </summary>
/// <param name="v">Pointer to the MedicineRepo.</param>
/// <param name = "name">A string, the name to search for.</param>
/// <returns>The pointer to the medicine containing the given name, or null, if such a medicine does not exist.</returns>
Medicine* find(MedicineRepo* v, char* name);

/*
Adds a medicine to the repository of medicine.
Input:	- v - pointer to the MedicineRepo
		- m - medicine
Output: 1 - if the medicine was sucessfully added
		0 - if the medicine could not be added, as another medicine with the same symbol already exists in the MedicineRepo.
*/
int add(MedicineRepo* v, Medicine* m);

/*
Deletes a medicine from the repository of medicine.
Input:	- v - pointer to the MedicineRepo
		- m - medicine
Output: 1 - if the medicine was sucessfully deleted
		0 - if the medicine could not be deleted.
*/
int deleteM(MedicineRepo* v, Medicine* m);

int getLength(MedicineRepo* v);


/*
Returns the medicine on the given position in the MedicineRepository.
Input:	v - the MedicineRepository;
		pos - integer, the position;
Output: the medicine on the given postion, or an "empty" medicine.
*/
Medicine* getMedicineOnPos(MedicineRepo* v, int pos);

/*
Sorts the repository v, ascending, by concentration.
Input:  v - the MedicineRepository;
Output: The repository v, sorted ascending by concentration
*/
void sortRepoConcentration(MedicineRepo* v);

/*
Sorts the repository v, alphabetically.
Input:  v - the MedicineRepository;
Output: The repository v, sorted alphabetically.
*/
void sortRepo(MedicineRepo* v);

/*
Tests the medicine repo.
*/
void testsMedicineRepo();