/*


												=================================
												| Created on: 08.03.2017        |
												| Edited on: 18.03.2017         |
												| By: Moldovan Alexandru-Vasile |
												=================================


*/


#include "MedicineRepository.h"
#include "UI.h"
#include <crtdbg.h>
#include "UndoController.h"
#include<stdio.h>
#include"Windows.h"

int main()
{
	testsMedicineRepo();

	MedicineRepo* repo = createRepo();
	Controller* ctrl = createController(repo);

	undoController* undoCtrl = createUndoController();

	addMedicine(ctrl, "Algocalmin", 80, 50, 40.5);
	addMedicine(ctrl, "Paracetamol", 50, 200, 20.3);
	addMedicine(ctrl, "Parasinus", 100, 367, 30);
	addMedicine(ctrl, "Nurofen", 10, 0, 80);
	addMedicine(ctrl, "Ibuprofen", 55, 0, 100);
	addMedicine(ctrl, "Bioparox", 70, 7, 980);
	addMedicine(ctrl, "Aurobindo", 45, 200, 50.5);
	addMedicine(ctrl, "Claritine", 180, 105, 50);
	addMedicine(ctrl, "Panadol", 20, 0, 36.20);
	addMedicine(ctrl, "Espumisan", 89, 31, 45);
	addMedicine(ctrl, "Strepsils", 50, 16, 32.5);
	addMedicine(ctrl, "Essentiale", 80, 18, 24.9);
	addMedicine(ctrl, "Aspirina", 40, 0, 10);
	addMedicine(ctrl, "Acamol", 90, 67, 100);

	newOperation(undoCtrl);
	addList(undoCtrl, repo);

	UI* ui = createUI(ctrl);

	startUI(ui, undoCtrl);

	destroyUndoController(undoCtrl);


	destroyUI(ui);

	if (_CrtDumpMemoryLeaks())
	{
		printf("    There are some memory leaks !");
		system("pause");
	}

	return 0;
}