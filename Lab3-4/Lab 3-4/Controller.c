#include "Controller.h"
#include <string.h>

Controller* createController(MedicineRepo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	return c;
}

void destroyController(Controller * c)
{
	destroyRepo(c->repo);
	free(c);
}

int addMedicine(Controller* c, char* name, double concentration, double quantity, double price)
{
	Medicine* m = createMedicine(name, concentration, quantity, price);
	int res = add(c->repo, m);
	if (res == 0)
		destroyMedicine(m);
	return res;
}

int deleteMedicine(Controller* c, char* name, double concentration, double quantity, double price)
{
	Medicine* m = createMedicine(name, concentration, quantity, price);
	int res = deleteM(c->repo, m);
	destroyMedicine(m);
	return res;
}

int updateMedicine(Controller* c, char* name, double concentration, double quantity, double price)
{
	Medicine* m = createMedicine(name, concentration, quantity, price);
	int res1 = deleteM(c->repo, m);
	int res2 = 0;
	if (res1 == 1)
		res2 = add(c->repo, m);
	if (res1 == 0)
		destroyMedicine(m);
	return res2;
}

void sort(Controller* c)
{
	sortRepo(c->repo);
}

MedicineRepo* getRepo(Controller* c)
{
	return c->repo;
}

MedicineRepo* filterByName(Controller* c, char name[])
{
	MedicineRepo* res = createRepo();
	if (strcmp(name, "null") == 0)
	{
		for (int i = 0; i < getLength(c->repo); i++)
		{
			Medicine *m = getMedicineOnPos(c->repo, i);
			if (m->quantity > 0)
			{
				Medicine* newMedicine = createMedicine(m->name, m->concentration, m->quantity, m->price);
				add(res, newMedicine);
			}
		}
		return res;
	}

	for (int i = 0; i < getLength(c->repo); i++)
	{
		Medicine* m = getMedicineOnPos(c->repo, i);
		if (strstr(getName(m), name) != NULL && m->quantity > 0)
		{
			Medicine* newMedicine = createMedicine(m->name, m->concentration, m->quantity, m->price);
			add(res, newMedicine);
		}
	}
	return res;
}

MedicineRepo* filterByQuantity(Controller* c, double x)
{
	MedicineRepo* res = createRepo();

	for (int i = 0; i < getLength(c->repo); i++)
	{
		Medicine* m = getMedicineOnPos(c->repo, i);
		if (m->quantity < x)
		{
			Medicine* newMedicine = createMedicine(m->name, m->concentration, m->quantity, m->price);
			add(res, newMedicine);
		}
	}
	return res;
}

MedicineRepo* filterByConcentration(Controller* c, char name[])
{
	MedicineRepo* res = createRepo();
	for (int i = 0; i < getLength(c->repo); i++)
	{
		Medicine *m = getMedicineOnPos(c->repo, i);
		if (strstr(getName(m), name) != NULL && m->quantity > 0)
		{
			Medicine* newMedicine = createMedicine(m->name, m->concentration, m->quantity, m->price);
			add(res, newMedicine);
		}
	}
	sortRepoConcentration(res);
	return res;
}