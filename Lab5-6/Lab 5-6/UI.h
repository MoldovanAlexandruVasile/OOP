#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	UI();

	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	int addTutorialToRepo();
	int deleteTutorialFromRepo();
	int updateTutorialFromRepo();
	void displayAllTutorialsRepo();
	void displayAllTutorialsPlayList();
	void tutorialsByPresenter(Tutorial t);
	void addTutorialToPlayListUI();
	void deleteTutorialToPlayListUI();
};