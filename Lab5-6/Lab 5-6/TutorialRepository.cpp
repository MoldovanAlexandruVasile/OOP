#include "TutorialRepository.h"
#include <string>

using namespace std;

int Repository::addTutorial(const Tutorial& t)
{
	if (this->tutorials.testExist(t) == -1)
	{
		this->tutorials = this->tutorials + t;
		return 1;
	}
	return 0;
}

int Repository::deleteTutorial(const Tutorial& t)
{
	if (this->tutorials.testExist(t) != -1)
	{
		this->tutorials.deleteT(t);
		return 1;
	}
	return 0;
}

int Repository::updateTutorial(const Tutorial& t)
{
	if (this->tutorials.testExist(t) != -1)
	{
		this->tutorials.update(t);
		return 1;
	}
	return 0;
}

int Repository::testExistInRepo(const Tutorial& t)
{
	int res = this->tutorials.testExist(t);
	return res;
}

int Repository::testExistInRepoByPresenter(const Tutorial& t)
{
	int res = this->tutorials.testExistByPresenter(t);
	return res;
}

int Repository::getSizeRepo()
{
	return this->tutorials.getSize();
}

Tutorial Repository::findByPresenterAndTitle(const std::string& presenter, const std::string& title)
{
	Tutorial* tutorialsInDynamicArray = this->tutorials.getAllElems();
	if (tutorialsInDynamicArray == NULL)
		return Tutorial{};

	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		Tutorial t = tutorialsInDynamicArray[i];
		if (t.getPresenter() == presenter && t.getTitle() == title)
			return t;
	}

	return Tutorial{};
}