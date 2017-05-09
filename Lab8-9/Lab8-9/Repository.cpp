#include "Repository.h"

using namespace std;

int Repository::find(const Tutorial& t)
{
	int pos = -1;
	int pos2 = 0;
	for (auto it : tutorials)
	{
		if (it.getPresenter() == t.getPresenter() && it.getTitle() == t.getTitle())
			pos = 0;
		if (pos == -1)
			pos2++;
	}
	if (pos == -1) return -1;
	return pos2;
}

int Repository::testExist(const Tutorial& t)
{
	int pos = -1;
	int pos2 = 0;
	for (auto it : tutorials)
	{
		if (it.getPresenter() == t.getPresenter())
			pos = 0;
		if (pos == -1)
			pos2++;
	}
	if (pos == -1) return -1;
	return pos2;
}

void Repository::writeToFile()
{
	std::ofstream fout("Tutorials.txt");
	for (auto it : this->tutorials)
		fout << it;
	fout.close();
}

void Repository::readFromFile()
{
	std::ifstream fin("Tutorials.txt");
	Tutorial t;
	while (fin >> t)
		this->tutorials.push_back(t);
	fin.close();
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

std::vector<Tutorial> Repository::getAll()
{
	return this->tutorials;
}