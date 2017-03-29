/*
											=================================
											| Created on: 24.03.2017        |
											| Edited on: 28.03.2017         |
											| By: Moldovan Alexandru-Vasile |
											=================================
*/




#include "Tutorial.h"
#include "UI.h"
#include <Windows.h>
#include <assert.h>

using namespace std;


void test()
{
	Repository repoForTest{};

	assert(repoForTest.getSizeRepo() == 0);
	Tutorial t{ "Linux Tutorial", "Learn Vi Editor Basics in 20 minutes", 418 ,Duration{ 23, 54 }, "https://www.youtube.com/watch?v=S24LN5h_pac" };
	//We add to to repo the tutorial.
	assert(repoForTest.addTutorial(t) == 1);
	//Test the length of the repository.
	assert(repoForTest.getSizeRepo() == 1);
	//Try to add it again.
	assert(repoForTest.addTutorial(t) == 0);
	//Fails to add it.
	assert(repoForTest.getSizeRepo() == 1);
	//We update t
	assert(repoForTest.updateTutorial(t) != 0);
	//Test again the length
	assert(repoForTest.getSizeRepo() == 1);
	//We delete the tutorial
	assert(repoForTest.deleteTutorial(t) == 1);
	//The repository is empty
	assert(repoForTest.getSizeRepo() == 0);
	//Try to delete it again
	assert(repoForTest.deleteTutorial(t) == 0);
	//The repository is still empty
	assert(repoForTest.getSizeRepo() == 0);
}

int main()
{	
	test();

	Repository repo{};

	Tutorial t{ "Linux Tutorial", "Learn Vi Editor Basics in 20 minutes", 418 ,Duration{ 23, 54 }, "https://www.youtube.com/watch?v=S24LN5h_pac" };
	repo.addTutorial(t);
	Tutorial t1{ "337 Media Studios", "HOWTO: Basic Video Editing (Premiere CS5)", 2403, Duration{ 14, 58 }, "https://www.youtube.com/watch?v=iS5DRicnXIY" };
	repo.addTutorial(t1);
	Tutorial t2{ "TechMindBlow", "Adobe Premiere Pro CS6 - Basic Editing Introduction Tutorial", 6607, Duration{ 16, 02 }, "https://www.youtube.com/watch?v=kWTHWOY1usU" };
	repo.addTutorial(t2);
	Tutorial t3{ "Patrick WashingtonDC","Java Programming - Step by Step tutorial", 2228 ,Duration{87,25},"https://www.youtube.com/watch?v=3u1fu6f8Hto" };
	repo.addTutorial(t3);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}