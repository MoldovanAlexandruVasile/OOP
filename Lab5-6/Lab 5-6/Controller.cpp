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
	int res = this->repo.testExistInRepo(t);
	return res;
}

int Controller::testExistFromRepositoryByPresenter(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.testExistInRepoByPresenter(t);
	return res;
}

int Controller::updateTutorialToRepository(const std::string& presenter, const std::string& title, const int likes, double minutes, double seconds, const std::string& source)
{
	Tutorial t{ presenter, title, likes, Duration{ minutes, seconds }, source };
	int res = this->repo.updateTutorial(t);
	return res;
}