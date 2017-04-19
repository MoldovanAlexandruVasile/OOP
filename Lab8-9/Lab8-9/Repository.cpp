#include "Repository.h"

using namespace std;

int Repository::find(const Tutorial& t)
{
	for (int i = 0; i < this->tutorials.size(); i++)
		if (tutorials[i].getPresenter() == t.getPresenter() && tutorials[i].getTitle() == t.getTitle())
			return i;
	return -1;
}

Tutorial Repository::findByPresenterAndTitle(const std::string& presenter, const std::string& title)
{
	std::vector<Tutorial> v = this->getAll();
	if (v.size() == 0)
		return Tutorial{};

	for (int i = 0; i < this->tutorials.size(); i++)
	{
		Tutorial t = v[i];
		if (t.getPresenter() == presenter && t.getTitle() == title)
			return t;
	}

	return Tutorial{};
}

int Repository::addTutorial(const Tutorial& t)
{
	if (this->find(t) == -1)
	{
		this->tutorials.push_back(t);
		return 1;
	}
	return 0;
}

int Repository::deleteTutorial(const Tutorial& t)
{
	int pos = this->find(t);
	if (pos != -1)
	{
		this->tutorials.erase(tutorials.begin() + pos);
		return 1;
	}
	return 0;
}

int Repository::updateTutorial(const Tutorial& t)
{
	if (this->find(t) != -1)
	{
		this->deleteTutorial(t);
		this->addTutorial(t);
		return 1;
	}
	return 0;
}

std::vector<Tutorial> Repository::getAll()
{
	return this->tutorials;
}

int Repository::testExist(const Tutorial& t)
{
	for (int i = 0; i < this->tutorials.size(); i++)
		if (this->tutorials[i].presenter == t.getPresenter())
			return i;
	return -1;
}