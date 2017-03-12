/*


									=================================
									| Created on: 08.03.2017        |
									| Edited on: 10.03.2017         |
									| By: Moldovan Alexandru-Vasile |
									=================================


*/

#include "MedicineRepository.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	testsMedicineRepo();

	MedicineRepo repo = createRepo();
	Controller ctrl = createController(&repo);

	addMedicine(&ctrl, "Algocalmin", 150.5, 1000, 40.5);
	addMedicine(&ctrl, "Paracetamol", 50, 200, 20.3);
	addMedicine(&ctrl, "Parasinus", 100, 367, 30);
	addMedicine(&ctrl, "Nurofen", 10, 0, 80);
	addMedicine(&ctrl, "Ibuprofen", 55, 0, 100);
	addMedicine(&ctrl, "Vitamina C", 25, 0, 12.99);
	addMedicine(&ctrl, "Bioparox", 70, 7, 980);
	addMedicine(&ctrl, "Claritine", 180, 105, 50);
	addMedicine(&ctrl, "Panadol", 20, 0, 36.20);
	addMedicine(&ctrl, "Espumisan", 89, 31, 45);
	addMedicine(&ctrl, "Strepsils", 50, 16, 32.5);
	addMedicine(&ctrl, "Essentiale", 80, 18, 24.9);
	addMedicine(&ctrl, "Aspirina", 40, 0, 10);

	UI ui = createUI(&ctrl);

	startUI(&ui);

	_CrtDumpMemoryLeaks();

	return 0;
}