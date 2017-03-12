#include "Controller.h"
#include <string.h>

Controller createController(MedicineRepo *r)
{
	Controller c;
	c.repo = r;
	return c;
}

int addMedicine(Controller *c, char name[], double concentration, double quantity, double price)
{
	Medicine m = createMedicine(name, concentration, quantity, price);
	int result = add(c->repo, m);
	return result;
}

int deleteMedicine(Controller *c, char name[], double concentration, double quantity, double price)
{
	Medicine m = createMedicine(name, concentration, quantity, price);
	int result = delete(c->repo, m);
	return result;
}


int updateMedicine(Controller *c, char name[], double concentration, double quantity, double price)
{
	Medicine m = createMedicine(name, concentration, quantity, price);
	int result = update(c->repo, m);
	return result;
}

MedicineRepo *getRepo(Controller *c)
{
	return c->repo;
}

MedicineRepo filterByName(Controller *c, char name[])
{
	MedicineRepo result = createRepo();
	if (strcmp(name, "null") == 0)
	{
		for (int i = 0; i < getLength(c->repo); i++)
		{
			Medicine m = *getMedicineOnPos(c->repo, i);
			if (m.quantity > 0) add(&result, m);
		}
		return result;
	}
	for (int i = 0; i < getLength(c->repo); i++)
	{
		Medicine m = *getMedicineOnPos(c->repo, i);
		if (strstr(getName(&m), name) != NULL && m.quantity > 0)
			add(&result, m);
	}
	return result;
}