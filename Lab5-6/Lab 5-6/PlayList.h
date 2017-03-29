#pragma once
#include "DynamicArray.h"

class PlayList
{
private:
	DynamicVector<Tutorial> tutorials;
	int current;

public:
	PlayList();

	void addPlayList(const Tutorial& t);

	void deletePlayList(const Tutorial& t);

	void updateTutorialPlayList(const Tutorial& t);

	Tutorial PlayList::getCurrentTutorial();

	void play();
	
	void next();

	DynamicVector<Tutorial> getPlayList() const { return tutorials; }

	Tutorial findByPresenterAndTitle(const std::string& presenter, const std::string& title);

	bool isEmpty();
};