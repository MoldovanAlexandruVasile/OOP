#include "Repository.h"
#include <string>

using namespace std;

int Repository::addTutorial(const Tutorial& t)
{
	int res = this->tutorials.add(t);
	return res;
}

int Repository::deleteTutorial(const Tutorial& t)
{
	int res = this->tutorials.deleteT(t);
	return res;
}

int Repository::updateTutorial(const Tutorial& t)
{
	int res = this->tutorials.update(t);
	return res;
}

int Repository::testExistInRepo(const Tutorial& t)
{
	int res = this->tutorials.testExist(t);
	return res;
}

int Repository::getSizeRepo()
{
	return this->tutorials.getSize();
}