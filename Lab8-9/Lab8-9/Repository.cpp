#include "Repository.h"
#include "Exceptions.h"

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

	if (! fout.is_open())
		throw FileException("The file could not be opened!");

	for (auto it : this->tutorials)
		fout << it;
	fout.close();
}

void Repository::readFromFile()
{
	std::ifstream fin("Tutorials.txt");

	if (! fin.is_open())
		throw FileException("The file could not be opened!");

	Tutorial t;
	while (fin >> t)
		this->tutorials.push_back(t);
	fin.close();
}

void Repository::addTutorial(const Tutorial& t)
{
	if (this->find(t) == -1)
		this->tutorials.push_back(t);
	else
		try
		{
			throw DuplicateTutorialException();
		}
	catch (InexistenTutorialException& e) {}
}

void Repository::deleteTutorial(const Tutorial& t)
{
	int pos = this->find(t);
	if (pos != -1)
	{
		this->tutorials.erase(tutorials.begin() + pos);
	}
	else
		throw InexistenTutorialException{};
}

void Repository::updateTutorial(const Tutorial& t)
{
	if (this->find(t) != -1)
	{
		this->deleteTutorial(t);
		this->addTutorial(t);
	}
	else
		throw InexistenTutorialException{};
}

Tutorial Repository::findByPresenterAndTitle(const std::string& presenter, const std::string& title)
{
	for (auto t : this->tutorials)
	{
		if (t.getPresenter() == presenter && t.getTitle() == title)
			return t;
	}

	throw InexistenTutorialException{};
}

std::vector<Tutorial> Repository::getAll()
{
	return this->tutorials;
}