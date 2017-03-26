#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:
	//Creates the repository.
	Controller(const Repository& r) : repo(r) {}

	//Returns the repository of the tutorials.
	Repository getRepo() const { return repo; }

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
	int addTutorialToRepository(const std::string& presenter, const std::string& title,const int likes, double minutes, double seconds, const std::string& source);

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
	int deleteTutorialFromRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);

	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int updateTutorialToRepository(const std::string& artist, const std::string& title, const int likes, double minutes, double seconds, const std::string& source);
	
	
	/*
	This function adds a new item to the repository.
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
};

