#include "Controller.h"

int Controller::addTutorialToRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.addTutorial(t);
	return res;
}

int Controller::deleteTutorialFromRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.deleteTutorial(t);
	return res;
}

int Controller::testExistFromRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.find(t);
	return res;
}

int Controller::testExistFromPlayListC(const Tutorial& t)
{
	int res = this->playList.testExistInPlayList(t);
	return res;
}

int Controller::testExistFromRepositoryByPresenter(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.testExist(t);
	return res;
}

int Controller::updateTutorialToRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.updateTutorial(t);
	return res;
}

void Controller::updateTutorialToPlayList(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	this->playList.updateTutorialPlayList(t);
}

void Controller::addTutorialToPlayList(const Tutorial& t)
{
	this->playList.addPlayList(t);
}

void Controller::deleteTutorialToPlayList(const std::string& presenter, const std::string& title)
{
	Tutorial t = { presenter, title, 0, Duration{ 0, 0 }, "" };
	this->playList.deletePlayList(t);
}

void Controller::startPlayList()
{
	this->playList.play();
}

void Controller::nextTutorialPlayList()
{
	this->playList.next();
}