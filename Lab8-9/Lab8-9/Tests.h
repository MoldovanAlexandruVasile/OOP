#include "Controller.h"
#include <assert.h>
#include <vector>

using namespace std;

void testRepo()
{
	assert(Tutorial::allInstances == 0);
	assert(Tutorial::currentInstances == 0);

	Repository repoForTest{};
	Controller ctrl{ repoForTest };

	std::vector<Tutorial> v = ctrl.getRepo().getAll();
	assert(v.size() == 0);

	Tutorial t{ "Linux Tutorial", "Learn Vi Editor Basics in 20 minutes", 418 ,Duration{ 23, 54 }, "https://www.youtube.com/watch?v=S24LN5h_pac" };
	Duration d = t.getDuration();
	Tutorial aux = ctrl.getRepo().findByPresenterAndTitle(t.getPresenter(), t.getTitle());
	assert(aux.getPresenter() == "");

	//We check if the tutorial does already exist or not in the repo by presenter.
	assert(ctrl.testExistFromRepositoryByPresenter(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == -1);

	//We check if the tutorial does already exist or not in the repo.
	assert(ctrl.testExistFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == -1);

	//We try t=to update, but it can't be done.
	assert(ctrl.updateTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 0);

	//We add to to repo the tutorial.
	assert(ctrl.addTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 1);

	//We check if the tutorial does already exist or not in the repo.
	assert(ctrl.testExistFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) != -1);

	//Test if we got it in the repo
	assert(ctrl.testExistFromRepositoryByPresenter(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) != -1);

	//Test the length of the repository.
	std::vector<Tutorial> v1 = ctrl.getRepo().getAll();
	assert(v1.size() == 1);

	//Try to add it again.
	assert(ctrl.addTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 0);

	//Fails to add it.
	std::vector<Tutorial> v3 = ctrl.getRepo().getAll();
	assert(v3.size() == 1);

	//We check if we have the tutorial
	Tutorial aux2 = ctrl.getRepo().findByPresenterAndTitle(t.getPresenter(), t.getTitle());
	assert(aux2.getPresenter() == t.getPresenter());

	//We update t
	assert(ctrl.updateTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) != 0);

	//We check if the tutorial does already exist or not in the repo.
	assert(ctrl.testExistFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) != -1);

	//Test again the length
	std::vector<Tutorial> v4 = ctrl.getRepo().getAll();
	assert(v4.size() == 1);

	//We delete the tutorial
	assert(ctrl.deleteTutorialFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 1);

	//We check if the tutorial does already exist or not in the repo.
	assert(ctrl.testExistFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == -1);

	//The repository is empty
	std::vector<Tutorial> v5 = ctrl.getRepo().getAll();
	assert(v5.size() == 0);

	//Try to delete it again
	assert(ctrl.deleteTutorialFromRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 0);

	//The repository is still empty
	std::vector<Tutorial> v6 = ctrl.getRepo().getAll();
	assert(v6.size() == 0);

	//We check if the tutorial does already exist or not in the repo by presenter.
	assert(ctrl.testExistFromRepositoryByPresenter(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == -1);

	assert(ctrl.addTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 1);
	Tutorial aux3 = ctrl.getRepo().findByPresenterAndTitle("Gheorghe", t.getTitle());
	assert(aux2.getPresenter() != "");

	//Test the play of the tutorial.
	//t.play();

}

void testPlayList()
{
	PlayList repoForTest{};
	Repository repo{};
	Controller ctrl{ repo };

	//The playlist is empty
	std::vector<Tutorial> v = ctrl.getPlayList().getAll();
	assert(v.size() == 0);

	//Check ig the playList is empty.
	assert(ctrl.getPlayList().isEmpty() == true);

	//We check if we have a tutorial with a given presenter and title
	Tutorial aux3 = ctrl.getPlayList().findByPresenterAndTitle("Ed Sheeran", "Hpw to sing");
	assert(aux3.getPresenter() == "");
	assert(aux3.getTitle() == "");
	
	//Check the current tutorial
	Tutorial aux = ctrl.getPlayList().getCurrentTutorial();
	assert(aux.getPresenter() == "");

	Tutorial t{ "Linux Tutorial", "Learn Vi Editor Basics in 20 minutes", 418 ,Duration{ 23, 54 }, "https://www.youtube.com/watch?v=S24LN5h_pac" };
	Duration d = t.getDuration();
	//we add it first in the repo.
	assert(ctrl.addTutorialToRepository(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource()) == 1);

	//We add to to repo the tutorial.
	ctrl.addTutorialToPlayList(t);

	//We try to play it.
	//ctrl.startPlayList();
	//ctrl.nextTutorialPlayList();

	Tutorial aux2 = ctrl.getPlayList().getCurrentTutorial();
	assert(aux2.getPresenter() != "");

	//Test the length of the repository.
	std::vector<Tutorial> v2 = ctrl.getPlayList().getAll();
	assert(v2.size() == 1);

	//The element does exist already in the playlist.
	assert(ctrl.testExistFromPlayListC(t) != -1);

	//The length it is the same.
	std::vector<Tutorial> v3 = ctrl.getPlayList().getAll();
	assert(v3.size() == 1);

	//We update t
	ctrl.updateTutorialToPlayList(t.getPresenter(), t.getTitle(), t.getLikes(), d.getMinutes(), d.getSeconds(), t.getSource());

	//Test again the length
	std::vector<Tutorial> v4 = ctrl.getPlayList().getAll();
	assert(v4.size() == 1);

	//We delete the tutorial
	ctrl.deleteTutorialToPlayList(t.getPresenter(), t.getTitle());

	//The repository is empty
	std::vector<Tutorial> v5 = ctrl.getPlayList().getAll();
	assert(v5.size() == 0);

	//Try to delete it again
	ctrl.deleteTutorialToPlayList(t.getPresenter(), t.getTitle());

	//The repository is still empty
	std::vector<Tutorial> v6 = ctrl.getPlayList().getAll();
	assert(v6.size() == 0);

	//Test the play and next
	//ctrl.startPlayList();
	//ctrl.nextTutorialPlayList();
	
	//We add the tutorial
	ctrl.addTutorialToPlayList(t);

	//We test if we find him in the repo
	Tutorial aux4 = ctrl.getPlayList().findByPresenterAndTitle("Linux Tutorial", "Learn Vi Editor Basics in 20 minutes");
	assert(aux4.getPresenter() != "");
	
	//We test if we got another tutorial in the playlist
	Tutorial aux5 = ctrl.getPlayList().findByPresenterAndTitle("a", "b");
	assert(aux5.getPresenter() == "");
}