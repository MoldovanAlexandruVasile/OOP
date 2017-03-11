#include "UI.h"
#include <stdio.h>

UI createUI(Controller *c)
{
	UI ui;
	ui.ctrl = c;
	return ui;
}

void printMenu()
/*
Prints out the menu.
*/
{
	printf("\n \n \n          ~Menu~ \n \n");
	printf("    1. Add a medicine.\n");
	printf("    2. List all medicines.\n");
	printf("    3. Print avaible medicines with a given name.\n");
	printf("    4. Delete a medicine.\n");
	printf("    5. Update a medicine.\n");
	printf("    6. Medicines with low suply. (NOT IMPLEMENTED)\n");
	printf("    7. Undo.(NOT IMPLEMENTED)\n");
	printf("    8. Redo.(NOT IMPLEMENTED)\n");
	printf("    0. Exit.\n \n");
}


int validCommand(int command)
/*
Checks out if the command is valir or not
Input command - the given command
Output 1 - if it is valid
	   0 - it it's not valid
*/
{
	if (command >= 0 && command <= 8)
	{
		return 1;
	}
	return 0;
}

int readIntegerNumber(const char* message)
{
	char s[16];
	int result = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &result);
		flag = (r == 1);
		if (flag == 0)
			printf("\n    Invalid command !\n");
	}
	return result;
}

int addMedicineUI(UI *ui)
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

	return addMedicine(ui->ctrl, name, concentration, quantity, price);
}


int deleteMedicineUI(UI *ui)
{
	char name[50];
	double concentration;
	double quantity;
	double price;

	printf("\n");
	printf("        Name of the medicine: ");
	scanf("%s[49]", name);
	printf("\n");

	return deleteMedicine(ui->ctrl, name, 0, 0, 0);
}


int updateMedicineUI(UI *ui)
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


void listAllMedicines(UI *ui)
{
	MedicineRepo *repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		printf("\n There are no stored medicines. \n");
	}

	for (int i = 0; i < getLength(repo); i++)
	{
		char str[200];
		toString(*getMedicineOnPos(repo, i), str);
		printf("%s\n", str);
	}
}


void listMedicineWithName(UI *ui)
{
	char name[50];
	printf("        Name: ");
	scanf("%49s", name);

	MedicineRepo result = filterByName(ui->ctrl, name);
	int length = getLength(&result);
	if (length == 0)
	{
		printf("    There are no medicines with that input.");
	}
	else
	{
		for (int i = 0; i < getLength(&result) - 1; i++)
		{
			Medicine *m1 = getMedicineOnPos(&result, i);
			for (int j = i + 1; j < getLength(&result); j++)
			{
				Medicine *m2 = getMedicineOnPos(&result, j);
				if (strcmp(m1->name, m2->name)>0)
				{
					Medicine aux = createMedicine("", 0, 0, 0);
					aux = *m1;
					*m1 = *m2;
					*m2 = aux;
				}
			}
		}
		printf("\n");
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(*getMedicineOnPos(&result, i), str);
			printf("%s\n", str);
		}
	}
}

void startUI(UI* ui)
{
	int command = -1;
	while (command != 0)
	{
		printMenu();
		command = readIntegerNumber("    Your command: ");
		while (validCommand(command) == 0)
		{
			printf("\n    Invalid command !\n");
			command = readIntegerNumber("    Your command: ");
		}
		if (command == 0)
			break;

		else if (command == 1)
		{
			int res = addMedicineUI(ui);
			if (res == 1)
				printf("    Medicine successfully added !\n");
			else printf("    Quantity added !");
		}

		else if (command == 2)
		{
			printf("\n");
			listAllMedicines(ui);
			printf("\n");
		}

		else if (command == 3)
		{
			printf("\n        If you input 'null', you will see all the avaible medicines ! \n\n");
			listMedicineWithName(ui);
			printf("\n");
		}

		else if (command == 4)
		{
			printf("\n");
			int res = deleteMedicineUI(ui);
			if (res == 1)
			{
				printf("    Medicine successfully deleted !\n");
			}
			else printf("    Medicine does not exist !\n");
			printf("\n");
		}

		else if (command == 5)
		{
			printf("\n");
			int res = updateMedicineUI(ui);
			if (res == 1)
			{
				printf("    Medicine successfully updated !\n");
			}
			else printf("    Medicine does not exist !\n");
			printf("\n");
		}

		else if (command == 6)
		{
			break;
		}

		else if (command == 7)
		{
			break;
		}
		else if (command == 8)
		{
			break;
		}
	}
}