#include "UndoController.h"
#include <string.h>
#include<stdlib.h>

undoController* createUndoController()
{
	undoController* c = (undoController*)malloc(sizeof(undoController));
	c->repoList = (MedicineRepo*)malloc(100 * sizeof(MedicineRepo));
	c->index = -1;
	c->n = 0;
	return c;
}

void destroyUndoController(undoController* undoCtrl)
{
	for (int i = 0; i < undoCtrl->n; i++)
		destroyRepo(undoCtrl->repoList[i]);

	free(undoCtrl->repoList);
	free(undoCtrl);
}

void newOperation(undoController* undoctrl)
{
	for (int i = undoctrl->index + 1; i < undoctrl->n; i++)
		destroyRepo(undoctrl->repoList[i]);

	undoctrl->n = undoctrl->index + 2;
	undoctrl->index = undoctrl->index + 1;
}

void addList(undoController* undoctrl, MedicineRepo* repo)
{
	Medicine* med;

	undoctrl->repoList[undoctrl->index] = createRepo();

	for (int i = 0; i < repo->length; i++)
	{
		med = createMedicine(repo->medicines[i]->name, repo->medicines[i]->concentration, repo->medicines[i]->quantity\
			, repo->medicines[i]->price);

		add(undoctrl->repoList[undoctrl->index], med);
	}

}

int checkUndo(undoController* c)
{
	return c->index > 0;
}

int checkRedo(undoController* c)
{
	return c->index + 1 < c->n;
}

int undo(undoController* c, MedicineRepo* repo)
{
	if (checkUndo(c))
	{

		Medicine* med;
		destroyRepo(repo);
		repo = createRepo();
		c->index = c->index - 1;
		for (int i = 0; i < c->repoList[c->index]->length; i++)
		{
			med = createMedicine(c->repoList[c->index]->medicines[i]->name, c->repoList[c->index]->medicines[i]->concentration, \
				c->repoList[c->index]->medicines[i]->quantity, c->repoList[c->index]->medicines[i]->price);

			add(repo, med);
		}

		return repo;
	}
	return repo;
}

int redo(undoController* c, MedicineRepo* repo)
{
	if (checkRedo(c))
	{

		Medicine* med;
		destroyRepo(repo);
		repo = createRepo();
		c->index = c->index + 1;
		for (int i = 0; i < c->repoList[c->index]->length; i++)
		{
			med = createMedicine(c->repoList[c->index]->medicines[i]->name, c->repoList[c->index]->medicines[i]->concentration, \
				c->repoList[c->index]->medicines[i]->quantity, c->repoList[c->index]->medicines[i]->price);

			add(repo, med);
		}
		return repo;
	}
	return repo;
}