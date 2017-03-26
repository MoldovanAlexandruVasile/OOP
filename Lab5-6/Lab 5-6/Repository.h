#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector tutorials;

public:
	//Returns the size of the repo.
	int getSizeRepo();

	Repository() {}

	/*
	This function adds a new item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does already exists in the repository.
			1 - If the tutorial has been added.
	*/
	int addTutorial(const Tutorial& t);
	

	/*
	This function deletes an item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exists in the repository, and nothing was deleted.
			1 - If the tutorial has been deleted.
	*/
	int deleteTutorial(const Tutorial& t);


	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int updateTutorial(const Tutorial& t);

	/*
	This function adds a new item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int testExistInRepo(const Tutorial& t);

	DynamicVector getTutorials() const { return tutorials; }
};