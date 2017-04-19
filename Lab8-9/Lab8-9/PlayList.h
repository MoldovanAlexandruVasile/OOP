#pragma once
#include <vector>
#include "Tutorial.h"

using namespace std;

class PlayList
{
private:
	std::vector<Tutorial> tutorials;
	int current;

public:
	PlayList();

	//Adds a new tutorial to the playlist.
	void addPlayList(const Tutorial& t);

	//Deletes a tutorial from the playlist
	void deletePlayList(const Tutorial& t);

	//Updates a tutorial from the playlist
	void updateTutorialPlayList(const Tutorial& t);

	//Returns the position of the current tutorial we are
	Tutorial PlayList::getCurrentTutorial();

	//Plays the first tutorial.
	void play();

	//Plays the next tutorial.
	void next();

	//Returns the playlist of the tutorials
	std::vector<Tutorial> getPlayList() const { return tutorials; }

	//Returns the tutorial with a given presenter and name.
	Tutorial findByPresenterAndTitle(const std::string& presenter, const std::string& title);

	//Tests if the Tutorial does exist in the playlist.
	int testExistInPlayList(const Tutorial& t);

	//Checks if the playlist is empty or not.
	bool isEmpty();

	int find(const Tutorial& t);

	std::vector<Tutorial> getAll();
};