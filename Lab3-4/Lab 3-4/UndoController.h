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
Input:  c - pointer of the controller
Output: 1 - If there can be made an undo operation
		0 - If there can't be made an undo operation
*/
int checkUndo(undoController* c);

/*
The function checks if we can make redo operations
Input:  c - pointer of the controller
Output: 1 - If there can be made an redo operation
		0 - If there can't be made an redo operation
*/
int checkRedo(undoController* c);

/*
The function makes the undo operation
Input:  c - pointer of the controller
Output: 1 - If the undo operation has been made
		0 - If the undo operation hasn't been made
*/
int undo(undoController* c);


/*
The function makes the redo operation
Input:  c - pointer of the controller
Output: 1 - If the redo operation has been made
		0 - If the redo operation hasn't been made
*/
int redo(undoController* c);