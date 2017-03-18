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

void newOperation(undoController* undoCtrl)
{
	for (int i = undoCtrl->index + 1; i < undoCtrl->n; i++)
		destroyRepo(undoCtrl->repoList[i]);

	undoCtrl->n = undoCtrl->index + 2;
	undoCtrl->index = undoCtrl->index + 1;
}

void addList(undoController* undoCtrl, MedicineRepo* repo)
{
	Medicine* med;

	undoCtrl->repoList[undoCtrl->index] = createRepo();

	for (int i = 0; i < repo->length; i++)
	{
		med = createMedicine(repo->medicines[i]->name, repo->medicines[i]->concentration, repo->medicines[i]->quantity\
			, repo->medicines[i]->price);

		add(undoCtrl->repoList[undoCtrl->index], med);
	}

}

int checkUndo(undoController* undoCtrl)
{
	return undoCtrl->index > 0;
}

int checkRedo(undoController* undoCtrl)
{
	return undoCtrl->index + 1 < undoCtrl->n;
}

int undo(undoController* undoCtrl, MedicineRepo* repo)
{
	if (checkUndo(undoCtrl))
	{

		Medicine* med;
		destroyRepo(repo);
		repo = createRepo();
		undoCtrl->index = undoCtrl->index - 1;
		for (int i = 0; i < undoCtrl->repoList[undoCtrl->index]->length; i++)
		{
			med = createMedicine(undoCtrl->repoList[undoCtrl->index]->medicines[i]->name, undoCtrl->repoList[undoCtrl->index]->medicines[i]->concentration, \
				undoCtrl->repoList[undoCtrl->index]->medicines[i]->quantity, undoCtrl->repoList[undoCtrl->index]->medicines[i]->price);

			add(repo, med);
		}

		return repo;
	}
	return repo;
}

int redo(undoController* undoCtrl, MedicineRepo* repo)
{
	if (checkRedo(undoCtrl))
	{

		Medicine* med;
		destroyRepo(repo);
		repo = createRepo();
		undoCtrl->index = undoCtrl->index + 1;
		for (int i = 0; i < undoCtrl->repoList[undoCtrl->index]->length; i++)
		{
			med = createMedicine(undoCtrl->repoList[undoCtrl->index]->medicines[i]->name, undoCtrl->repoList[undoCtrl->index]->medicines[i]->concentration, \
				undoCtrl->repoList[undoCtrl->index]->medicines[i]->quantity, undoCtrl->repoList[undoCtrl->index]->medicines[i]->price);

			add(repo, med);
		}
		return repo;
	}
	return repo;
}