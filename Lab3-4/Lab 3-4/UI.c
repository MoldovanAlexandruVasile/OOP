#include "UI.h"
#include <stdio.h>
#include "UndoController.h"

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	destroyController(ui->ctrl);
	free(ui);
}

/*
Prints the available menu for the problem
Input: -
Output: the menu is printed at the console
*/
void printMenu()
{
	printf("\n \n \n          ~Menu~ \n \n");
	printf("    1. Add a medicine.\n");
	printf("    2. List all medicines.\n");
	printf("    3. Print avaible medicines with a given name.\n");
	printf("    4. Delete a medicine.\n");
	printf("    5. Update a medicine.\n");
	printf("    6. Medicines with low supply.\n");
	printf("    7. Undo.\n");
	printf("    8. Redo.\n");
	printf("    0. Exit.\n \n");
	printf("\n    ============================================================== \n");
	printf("        Lab activity:\n\n ");
	printf("    9. List medicines with a given name, sorted by concentration.\n");
	printf("\n    ============================================================== \n \n");
}

/*
Verifies if the given command is valid
Input: command - integer
Output: 1 - if the command is valid
		0 - otherwise
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 9)
		return 1;
	return 0;
}

/*
Reads an integer number from the keyboard. Asks for number while read errors encoutered.
Input: the message to be displayed when asking the user for input.
Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("    Invalid data !\n");
	}
	return res;
}

int addMedicineUI(UI* ui)
{
	char name[50];
	double concentration, quantity, price;

	printf("        Name of the medicine: ");
	scanf("%49s", name);
	printf("        Concentration: ");
	scanf("%lf", &concentration);
	printf("        Quantity: ");
	scanf("%lf", &quantity);
	printf("        Price: ");
	scanf("%lf", &price);

	return addMedicine(ui->ctrl, name, concentration, quantity, price);
}

int deleteMedicineUI(UI* ui)
{
	char name[50];

	printf("        Name of the medicine: ");
	scanf("%49s", name);

	return deleteMedicine(ui->ctrl, name, 0, 0, 0);
}

int updateMedicineUI(UI* ui)
{
	char name[50];
	double concentration;
	double quantity;
	double price;

	printf("\n");
	printf("        Name of the medicine: ");
	scanf("%s[49]", name);
	printf("        Concentration: ");
	scanf("%lf", &concentration);
	printf("        Quantity: ");
	scanf("%lf", &quantity);
	printf("        Price: ");
	scanf("%lf", &price);
	printf("\n");

	return updateMedicine(ui->ctrl, name, concentration, quantity, price);
}

void listAllMedicines(UI* ui)
{
	MedicineRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		printf("    There are no stored medicines.");
	}

	for (int i = 0; i < getLength(repo); i++)
	{
		char str[200];
		toString(getMedicineOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listMedicinesWithName(UI* ui)
{
	char name[50];
	printf("        Name: ");
	scanf("%49s", name);
	printf("\n");

	MedicineRepo* res = filterByName(ui->ctrl, name);
	int length = getLength(res);
	if (length == 0)
	{
		printf("\n    There are no medicines with that name.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedicineOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}

void listMedicinesByQuantity(UI* ui)
{
	double quantity;
	printf("        Quantity: ");
	scanf("%lf", &quantity);
	printf("\n");

	MedicineRepo* res = filterByQuantity(ui->ctrl, quantity);
	int length = getLength(res);
	if (length == 0)
	{
		printf("\n    There are no medicines with less quantity.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedicineOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}

void listMedicinesByConcentration(UI* ui)
{
	char name[50];
	printf("        Name: ");
	scanf("%49s", name);
	printf("\n");

	MedicineRepo* res = filterByConcentration(ui->ctrl, name);
	int length = getLength(res);
	if (length == 0)
	{
		printf("\n    There are no medicines with the name.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedicineOnPos(res, i), str);
			printf("%s\n", str);
		}
	}
	destroyRepo(res);
}


void startUI(UI* ui, undoController* undoCtrl)
{
	while (1)
	{
		sort(ui->ctrl);
		printMenu();
		int command = readIntegerNumber("\n    Input command: ");
		while (validCommand(command) == 0)
		{
			printf("\n    Invalid command !\n");
			command = readIntegerNumber("\n    Input command: ");
		}
		printf("\n");
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addMedicineUI(ui);
			if (res == 1)
			{
				printf("\n    Medicine successfully added.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
			{
				printf("\n    Quantity added !\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			break;
		}
		case 2:
		{
			listAllMedicines(ui);
			break;
		}
		case 3:
		{
			printf("\n    If you input 'null', all the avaible medicines will be printed.\n \n");
			listMedicinesWithName(ui);
			break;
		}
		case 4:
		{
			int res = deleteMedicineUI(ui, undoCtrl);
			if (res == 1)
			{
				printf("\n    Medicine successfully deleted.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("\n    No such a medicine !\n");
			break;
		}
		case 5:
		{
			int res = updateMedicineUI(ui, undoCtrl);
			if (res == 1)
			{
				printf("\n    Medicine successfully updated.\n");
				newOperation(undoCtrl);
				addList(undoCtrl, ui->ctrl->repo);
			}
			else
				printf("\n    No such a medicine !\n");
			break;
		}
		case 6:
		{
			listMedicinesByQuantity(ui);
			break;
		}
		case 7:
		{
			if (checkUndo(undoCtrl) == 1)
			{
				ui->ctrl->repo = undo(undoCtrl, ui->ctrl->repo);
				printf("\n    Undo done !\n");
			}
			else
				printf("\n    Can't undo !\n");
			break;
		}
		case 8:
		{
			if (checkRedo(undoCtrl) == 1)
			{
				ui->ctrl->repo = redo(undoCtrl, ui->ctrl->repo);
				printf("\n    Redo done !\n");
			}
			else
				printf("\n    Can't redo !\n");
			break;
		}
		case 9:
		{
			listMedicinesByConcentration(ui);
			break;
		}
		}
	}
}