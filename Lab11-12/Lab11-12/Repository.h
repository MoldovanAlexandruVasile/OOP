#pragma once
#include <vector>
#include "Tutorial.h"
#include <algorithm>
#include <fstream>

using namespace std;

class Repository
{
private:
	std::vector<Tutorial> tutorials;
	std::string filename;

public:
	//Returns the size of the repo.

	Repository(const std::string& filename);

	/*
	This function adds a new item to the repository.
	*/
	void addTutorial(const Tutorial& t);


	/*
	This function deletes an item to the repository.
	*/
	void deleteTutorial(const Tutorial& t);


	/*
	This function updates an item from the repository.
	*/
	void updateTutorial(const Tutorial& t);

	/*
	This function checks if an item exists in the repository.
	INPUT:  e - The tutorial.
	OUTPUT: -1 - If the tutorial does not exist in the repository.
	pos - If the tutorial exists, his position will be returnes.
	*/
	int find(const Tutorial& t);

	std::vector<Tutorial> getAll();

	Tutorial findByPresenterAndTitle(const std::string& presenter, const std::string& title);

	int testExist(const Tutorial& t);

	void writeToFile();
	void readFromFile();
};