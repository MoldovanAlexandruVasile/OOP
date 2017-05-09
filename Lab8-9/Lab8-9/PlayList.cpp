#include "PlayList.h"

int PlayList::find(const Tutorial& t)
{
	int pos = -1;
	for (int i = 0; i < this->tutorials.size(); i++)
		if (tutorials[i].getPresenter() == t.getPresenter() && tutorials[i].getTitle() == t.getTitle())
			if (pos == -1)
				pos = i;
	return pos;
}

PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::addPlayList(const Tutorial& t)
{
	this->tutorials.push_back(t);
}

void PlayList::deletePlayList(const Tutorial& t)
{
	if (this->find(t) != -1)
	{
		this->tutorials.erase(tutorials.begin() + this->find(t));
	}
}

void PlayList::updateTutorialPlayList(const Tutorial& t)
{
	if (this->find(t) != -1)
	{
		this->deletePlayList(t);
		this->addPlayList(t);
	}
}

Tutorial PlayList::getCurrentTutorial()
{
	if (this->current == this->tutorials.size())
		this->current = 0;
	std::vector<Tutorial> elems = this->getAll();
	if (elems.size() != 0)
		return elems[this->current];
	return Tutorial{};
}


Tutorial PlayList::findByPresenterAndTitle(const std::string& presenter, const std::string& title)
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

void PlayList::play()
{
	if (this->tutorials.size() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

void PlayList::next()
{
	if (this->tutorials.size() == 0)
		return;
	this->current++;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool PlayList::isEmpty()
{
	return this->tutorials.size() == 0;
}

int PlayList::testExistInPlayList(const Tutorial& t)
{
	int res = this->find(t);
	return res;
}

std::vector<Tutorial> PlayList::getAll()
{
	return this->tutorials;
}