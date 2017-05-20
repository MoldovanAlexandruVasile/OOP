#pragma once
#include "Repository.h"
#include "PlayList.h"
#include "TutorialValidator.h"

class Controller
{
private:
	Repository repo;
	PlayList *playList;
	TutorialValidator validator;
public:
	//Creates the repository.
	Controller(const Repository& r, PlayList *p) : repo(r), playList(p) {}

	//Returns the repository of the tutorials.
	Repository getRepo() const { return repo; }

	//Returns the repository of the playlists.
	PlayList *getPlayList() const { return playList; }

	/*
	This function adds a new item to the repository.
	INPUT:  presenter - The presenter name;
	title - The tutorial title;
	like - The number of likes of the video;
	minutes - The number of minutes of the video;
	seconds - The number of the seconds of the video;
	source - The link of the video.
	OUTPUT: 0 - If the tutorial does already exists in the repository.
	1 - If the tutorial has been added.
	*/
	void addTutorialToRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	/*
	This function deletes an item to the repository.
	INPUT:  presenter - The presenter name;
	title - The tutorial title;
	like - The number of likes of the video;
	minutes - The number of minutes of the video;
	seconds - The number of the seconds of the video;
	source - The link of the video.
	OUTPUT: 0 - If the tutorial does not exists in the repository, and nothing was deleted.
	1 - If the tutorial has been deleted.
	*/
	void deleteTutorialFromRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
	pos - If the tutorial exists, his position will be returnes.
	*/
	void updateTutorialToRepository(const std::string& artist, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);


	/*
	This function tests if a tutorial already exists in the repository.
	INPUT:  presenter - The presenter name;
	title - The tutorial title;
	like - The number of likes of the video;
	minutes - The number of minutes of the video;
	seconds - The number of the seconds of the video;
	source - The link of the video.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
	pos - If the tutorial exists, his position will be returnes.
	*/
	int testExistFromRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	/*
	This function tests if a tutorial already exists in the repository.
	INPUT:  presenter - The presenter name;
	title - The tutorial title;
	like - The number of likes of the video;
	minutes - The number of minutes of the video;
	seconds - The number of the seconds of the video;
	source - The link of the video.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
	pos - If the tutorial exists, his position will be returnes.
	*/
	int testExistFromRepositoryByPresenter(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	//Adds a tutorial to the playlist.
	void addTutorialToPlayList(const Tutorial& t);

	//Updates a tutorial from the playlist.
	void updateTutorialToPlayList(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	//Deletes a tutorial from the playlist.
	void deleteTutorialToPlayList(const std::string& presenter, const std::string& title);

	//Starts to play the first tutorial.
	void startPlayList();

	//Plays the next tutorial.
	void nextTutorialPlayList();

	/*
	This function tests if a tutorial already exists in the playlist.
	INPUT:  t - The tutorial;
	OUTPUT: 0 - If the tutorial does not exist in the repository.
	pos - If the tutorial exists, his position will be returnes.
	*/
	int testExistFromPlayListC(const Tutorial& t);

	void writeToFileC() { this->repo.writeToFile(); }
	void readFromFileC() { this->repo.readFromFile(); }

	void displayPlayListC() { return this->playList->executeThingsPL(); }

	std::vector<Tutorial> Controller::filterByPresenter(const std::string& presenter)
	{
		vector<Tutorial> tutorials = this->repo.getAll();
		int nTutorials = count_if(tutorials.begin(), tutorials.end(),
			[presenter](const Tutorial& t)
		{
			return t.getPresenter() == presenter;
		});

		vector<Tutorial> tutorialsByArtist(nTutorials);
		copy_if(tutorials.begin(), tutorials.end(), tutorialsByArtist.begin(),
			[presenter](const Tutorial& t)
		{
			return t.getPresenter() == presenter;
		});

		return tutorialsByArtist;
	}

};

