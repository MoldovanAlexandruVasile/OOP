#pragma once
#include "MedicineRepository.h"

typedef struct
{
	MedicineRepo* repo;
} Controller;

Controller* createController(MedicineRepo* r);
void destroyController(Controller* c);

/// <summary>
/// Adds a medicine to the repository of medicines.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "name">A string, the name of the medicine.</param>
/// <param name = "concentration">Double, the concentration of the medicine</param>
/// <param name = "quantity">Double, the quantity of the medicine</param>
/// <param name = "price">Double, the price of the medicine</param>
/// <returns>1 - if the medicine was sucessfully added; 0 - if the medicine could not be added, but the quantity was updated.</returns>
int addMedicine(Controller* c, char* name, double concentration, double quantity, double price);

/// <summary>
/// Deletes a medicine to the repository of medicines.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "name">A string, the name of the medicine.</param>
/// <param name = "concentration">Double, the concentration of the medicine</param>
/// <param name = "quantity">Double, the quantity of the medicine</param>
/// <param name = "price">Double, the price of the medicine</param>
/// <returns>1 - if the medicine was sucessfully deleted; 0 - if the medicine could not be deleted.</returns>
int deleteMedicine(Controller* c, char* name, double concentration, double quantity, double price);

/// <summary>
/// Updates a medicine to the repository of medicines.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "name">A string, the name of the medicine.</param>
/// <param name = "concentration">Double, the concentration of the medicine</param>
/// <param name = "quantity">Double, the quantity of the medicine</param>
/// <param name = "price">Double, the price of the medicine</param>
/// <returns>1 - if the medicine was sucessfully updated; 0 - if the medicine could not be updated.</returns>
int updateMedicine(Controller* c, char* name, double concentration, double quantity, double price);

MedicineRepo* getRepo(Controller* c);

/// <summary>
/// Searches for the medicines containing a given name.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "name">A string, the searched  name; "null" - for all the medicines.</param>
/// <returns>A pointer to a repository of medicines, that have the name.</returns>
MedicineRepo* filterByName(Controller* c, char name[]);


/// <summary>
/// Searches for the medicines that have a smaller quantity, than the inputed one.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "x">The maximum quantity.</param>
/// <returns>A pointer to a repository of medicines, that have the quantity smaller than 'x'.</returns>
MedicineRepo* filterByQuantity(Controller* c, double x);


/// <summary>
/// Searches for the medicines containing a given name.
/// </summary>
/// <param name="c">Pointer to the Controller.</param>
/// <param name = "name">A string, the searched  name; "null" - for all the medicines.</param>
/// <returns>A pointer to a repository of medicines, that have the name, sorted by concentration ascending.</returns>
MedicineRepo* filterByConcentration(Controller* c, char name[]);


/// <summary>
/// Sorts the repository of medicines alphabetically
/// </summary>
/// <param name = "c">Pointer to the Controller</param>
/// <returns>The repository of medicines sorted alphabetically</returns>
void sort(Controller* c);