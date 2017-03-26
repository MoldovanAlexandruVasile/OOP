#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();

	int addTutorialToRepo();
	int deleteTutorialFromRepo();
	int updateTutorialFromRepo();
	void displayAllTutorialsRepo();
};