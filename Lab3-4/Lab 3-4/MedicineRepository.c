#include "MedicineRepository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>

MedicineRepo* createRepo()
{
	MedicineRepo* v = (MedicineRepo*)malloc(sizeof(MedicineRepo));
	v->medicines = (Medicine*)malloc(100 * sizeof(Medicine));
	v->length = 0;

	return v;
}

void destroyRepo(MedicineRepo* v)
{

	for (int i = 0; i < v->length; i++)
		destroyMedicine(v->medicines[i]);
	free(v->medicines);
	free(v);

}

Medicine* find(MedicineRepo* v, char* name)
{
	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->medicines[i]->name, name) == 0)
			return v->medicines[i];
	}
	return NULL;
}

int add(MedicineRepo* v, Medicine* m)
{

	if (find(v, m->name) != NULL)
	{
		Medicine* aux = find(v, m->name);
		aux->quantity += m->quantity;
		return 0;
	}
	v->medicines[v->length] = m;
	v->length = v->length + 1;
	return 1;
}

int deleteM(MedicineRepo* v, Medicine* m)
{
	int position = -1;
	if (find(v, m->name) != NULL)
	{
		int i = 0;
		for (int i = 0; i < v->length; i++)
		{
			if (strcmp(v->medicines[i]->name, m->name) == 0)
			{
				position = i;
			}
		}
		destroyMedicine(v->medicines[position]);
		for (int i = position; i < v->length - 1; i++)
		{
			v->medicines[i] = v->medicines[i + 1];
		}
		v->length = v->length - 1;
		return 1;
	}
	return 0;
}


int getLength(MedicineRepo* v)
{
	return v->length;
}

Medicine* getMedicineOnPos(MedicineRepo* v, int pos)
{
	if (pos < 0 || pos >= v->length)
		return NULL;
	return v->medicines[pos];
}

void sortRepo(MedicineRepo* v)
{
	Medicine* aux;
	for (int i = 0; i < v->length - 1; i++)
	{
		for (int j = i + 1; j < v->length; j++)
		{
			if (strcmp(v->medicines[i]->name, v->medicines[j]->name)>0)
			{
				aux = v->medicines[i];
				v->medicines[i] = v->medicines[j];
				v->medicines[j] = aux;
			}
		}
	}
}

void sortRepoConcentration(MedicineRepo* v)
{
	Medicine* aux;
	for (int i = 0; i < v->length - 1; i++)
	{
		for (int j = i + 1; j < v->length; j++)
		{
			if (v->medicines[i]->concentration > v->medicines[j]->concentration)
			{
				aux = v->medicines[i];
				v->medicines[i] = v->medicines[j];
				v->medicines[j] = aux;
			}
		}
	}
}

MedicineRepo* copyRepo(MedicineRepo* v)
{
	MedicineRepo* res = createRepo();
	for (int i = 0; i < v->length; i++)
	{
		Medicine* m = createMedicine(v->medicines[i]->name, v->medicines[i]->concentration, v->medicines[i]->quantity, v->medicines[i]->price);
		add(res, m);
	}
	return res;
}

void initMedicineRepoForTests(MedicineRepo *v)
//Initiate the repo for test
{
	Medicine *m = createMedicine("Algocalmin", 100, 20, 50);
	add(v, m);
}

void test()
{
	MedicineRepo* v = createRepo();
	initMedicineRepoForTests(v);
	assert(getLength(v) == 1);

	Medicine *m = createMedicine("Paracetamol", 157, 45, 200);
	//We add the new medicine.
	assert(add(v, m) == 1);
	//We see if it has been added.
	assert(getLength(v) == 2);
	//We try again too add it, but it does already exists, so it will update the quantity.
	assert(add(v, m) == 0);
	//We delete the medicine.
	assert(deleteM(v, m) == 1);
	//We check if the medicine was deleted.
	assert(getLength(v) == 1);
	//We destroy the repo.
	destroyRepo(v);
}

void testsMedicineRepo()
//We run the test
{
	test();
}