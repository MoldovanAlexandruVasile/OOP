#include "MedicineRepository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>

MedicineRepo createRepo()
{
	MedicineRepo v;
	v.length = 0;
	return v;
}

int find(MedicineRepo *v, char name[])
{
	Medicine *m = NULL;
	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->medicines[i].name, name) == 0)
			return i;
	}
	return -1;
}


int add(MedicineRepo *v, Medicine m)
{
	if (find(v, m.name) != -1)
	{
		v->medicines[find(v, m.name)].quantity += m.quantity;
		return 0;
	}
	v->medicines[v->length] = m;
	v->length++;
	return 1;
}

int delete(MedicineRepo *v, Medicine m)
{
	if (find(v, m.name) != -1)
	{
		int pos = find(v, m.name);
		for (int i = pos; i < getLength(v); i++)
				v->medicines[i] = v->medicines[i + 1];
		v->length = v->length - 1;
		return 1;
	}
	return 0;
}

int update(MedicineRepo *v, Medicine m)
{
	if (find(v, m.name) != -1)
	{
		v->medicines[find(v, m.name)] = m;
		return 1;
	}
	return 0;
}

int getLength(MedicineRepo *v)
{
	return v->length;
}

Medicine *getMedicineOnPos(MedicineRepo *v, int pos)
{
	if (pos < 0 || pos >= v->length)
		return NULL;
	return &(*v).medicines[pos];
}


//====================== Tests ======================
void initMedicineRepoForTests(MedicineRepo* v)
{
	Medicine m = createMedicine("Algocalmin", 100, 20, 50);
	add(v, m);
}

void testAdd()
{
	Medicine m = createMedicine("Paracetamol", 157, 45, 200);
	
	MedicineRepo v = createRepo();
	initMedicineRepoForTests(&v);
	
	assert(getLength(&v) == 1);
	assert(add(&v, m) == 1);
	assert(getLength(&v) == 2);
	assert(add(&v, m) == 0);
	assert(delete(&v, m) == 1);
	assert(delete(&v, m) == 0);
	assert(add(&v, m) == 1);
	assert(update(&v, m) == 1);
}

void testsMedicineRepo()
{
	testAdd();
}