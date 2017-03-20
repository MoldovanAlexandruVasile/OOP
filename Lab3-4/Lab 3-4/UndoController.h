#pragma once
#include "MedicineRepository.h"

typedef struct
{
	MedicineRepo** repoList;
	int n;
	int index;
} undoController;

/*
Creates a new controller for the undo/redo operation.
*/
undoController* createUndoController();

/*
Destroys the undoController.
Input:  undoCtrl - pointer for the undoController
*/
void destroyUndoController(undoController* undoCtrl);

/*
The function checks if we can make undo operations
Input:  undoCtrl - pointer of the controller
Output: 1 - If there can be made an undo operation
		0 - If there can't be made an undo operation
*/
int checkUndo(undoController* undoCtrl);

/*
The function checks if we can make redo operations
Input:  undoCtrl - pointer of the controller
Output: 1 - If there can be made an redo operation
		0 - If there can't be made an redo operation
*/
int checkRedo(undoController* undoCtrl);

/*
The function makes the undo operation
Input:  undoCtrl - pointer of the controller
Output: The repository
*/
int undo(undoController* undoCtrl);


/*
The function makes the redo operation
Input:  undoCtrl - pointer of the controller
Output: The repository
*/
int redo(undoController* undoCtrl);