#include "PlayList.h"


PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::addPlayList(const Tutorial& t)
{
	this->tutorials.add(t);
}

void PlayList::deletePlayList(const Tutorial& t)
{
	if (this->tutorials.testExist(t) != -1)
	{
		this->tutorials.deleteT(t);
	}
}

void PlayList::updateTutorialPlayList(const Tutorial& t)
{
	if (this->tutorials.testExist(t) != -1)
	{
		this->tutorials.update(t);
	}
}

Tutorial PlayList::getCurrentTutorial()
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	Tutorial* elems = this->tutorials.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Tutorial{};
}


Tutorial PlayList::findByPresenterAndTitle(const std::string& presenter, const std::string& title)
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

//void PlayList::play()
//{
//	if (this->tutorials.getSize() == 0)
//		return;
//	this->current = 0;
//	Tutorial currentTutorial = this->getCurrentTutorial();
//	currentTutorial.play();
//}
//
//void PlayList::next()
//{
//	if (this->tutorials.getSize() == 0)
//		return;
//	this->current++;
//	Tutorial currentTutorial = this->getCurrentTutorial();
//	currentTutorial.play();
//}

bool PlayList::isEmpty()
{
	return this->tutorials.getSize() == 0;
}