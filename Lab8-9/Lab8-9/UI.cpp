#include "UI.h"
#include <string>
#include "TutorialValidator.h"
#include "Exceptions.h"

using namespace std;

void UI::printMenu()
{
	cout << "\n===================================================\n" << endl;
	cout << "\t~MENU~\n" << endl;
	cout << "     1. Admin." << endl;
	cout << "     2. User." << endl;
	cout << "     0. Exit." << endl;
}

void UI::printAdminMenu()
{
	cout << "\n   ======================================================\n" << endl;
	cout << "\n\t\t     ~Manage tutorials repository~\n" << endl;
	cout << "\t\t 1. Add tutorial." << endl;
	cout << "\t\t 2. Delete tutorial." << endl;
	cout << "\t\t 3. Update tutorial." << endl;
	cout << "\t\t 4. Display all." << endl;
	cout << "\t\t 5. Display instances." << endl;
	cout << "\t\t 0. Back." << endl;
}

void UI::printUserMenu()
{
	cout << "\n   =============================================================\n" << endl;
	cout << "\n\t\t     ~User options~\n" << endl;
	cout << "\t\t 1. Display avaible tutorials from database." << endl;
	cout << "\t\t 2. Display existing tutorials from database with a given presenter." << endl;
	cout << "\t\t 3. Display your tutorial playlist." << endl;
	cout << "\t\t 4. Add a tutorial to your playlist." << endl;
	cout << "\t\t 5. Delete a tutorial from your playlist." << endl;
	cout << "\t\t 6. Watch." << endl;
	cout << "\t\t 7. Watch the next tutorial." << endl;
	cout << "\t\t 0. Back." << endl;
}

void UI::addTutorialToRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);
	int likes;
	cout << "\tLikes: ";
	cin >> likes;
	cin.ignore();
	double minutes = 0, seconds = 0;
	cout << "\tEnter the duration: " << endl;
	cout << "\t\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\t\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "\tYoutube link: ";
	std::string link;
	getline(cin, link);

	try
	{
		this->ctrl.addTutorialToRepository(presenter, title, likes, minutes, seconds, link);
	}
	catch (TutorialException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}

	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::deleteTutorialFromRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);

	try
	{
		this->ctrl.deleteTutorialFromRepository(presenter, title, 0, 0, 0, "");
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateTutorialFromRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);
	int likes;
	cout << "\tLikes: ";
	cin >> likes;
	cin.ignore();
	double minutes = 0, seconds = 0;
	cout << "\tEnter the duration: " << endl;
	cout << "\t\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\t\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "\tYoutube link: ";
	std::string link;
	getline(cin, link);

	try
	{
		this->ctrl.updateTutorialToRepository(presenter, title, likes, minutes, seconds, link);
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}

	Tutorial t{ presenter,title, likes, Duration{ minutes, seconds }, link };
	if (this->ctrl.testExistFromPlayListC(t) != -1)
		this->ctrl.updateTutorialToPlayList(presenter, title, likes, minutes, seconds, link);
}

void UI::displayAllTutorialsRepo()
{
	std::vector<Tutorial> v = this->ctrl.getRepo().getAll();
	if (v.size() == 0)
	{
		cout << "\n\tThere are no tutorials in the playlist.\n" << endl;
		return;
	}
	cout << "\n==========================================================================\n" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		Tutorial t = v[i];
		Duration d = t.getDuration();
		cout << "  Tutorial by: " << t.getPresenter() << endl;
		cout << "  Title: " << t.getTitle() << endl;
		cout << "  Number of likes: " << t.getLikes() << endl;
		cout << "  Duration: " << d.getMinutes() << ":" << d.getSeconds() << endl;
		cout << "\n==========================================================================\n" << endl;
	}

}


void UI::displayAllTutorialsPlayList()
{
	std::vector<Tutorial> v = this->ctrl.getPlayList()->getAll();
	if (v.size() == 0)
	{
		cout << "\n\tThere are no tutorials in the playlist.\n" << endl;
		return;
	}
	cout << "\n==========================================================================\n" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		Tutorial t = v[i];
		Duration d = t.getDuration();
		cout << "  Tutorial by: " << t.getPresenter() << endl;
		cout << "  Title: " << t.getTitle() << endl;
		cout << "  Number of likes: " << t.getLikes() << endl;
		cout << "  Duration: " << d.getMinutes() << ":" << d.getSeconds() << endl;
		cout << "\n==========================================================================\n" << endl;
	}
}


void UI::tutorialsByPresenter(Tutorial tut)
{
	std::vector<Tutorial> v = this->ctrl.getRepo().getAll();
	if (v.size() == 0)
	{
		cout << "\n\tThere are no tutorials in the repository.\n" << endl;
		return;
	}
	int newCommand = -1;
	while (newCommand != 0)
	{
		std::vector<Tutorial> v = this->ctrl.getRepo().getAll();
		for (int i = 0; i < v.size(); i++)
		{
			if (tut.getPresenter() == v[i].getPresenter())
			{
				Tutorial t = v[i];
				Duration d = t.getDuration();
				cout << "\n==========================================================================\n" << endl;
				cout << "  Tutorial by: " << t.getPresenter() << endl;
				cout << "  Title: " << t.getTitle() << endl;
				cout << "  Number of likes: " << t.getLikes() << endl;
				cout << "  Duration: " << d.getMinutes() << ":" << d.getSeconds() << endl;
				cout << "\n\t 1. Like tutorial." << endl;
				cout << "\t 2. Add to watch list." << endl;
				cout << "\t 3. Next." << endl;
				cout << "\t 0. Exit." << endl;
				cout << "\n\t Your command: ";
				newCommand = 0;
				cin >> newCommand;
				cin.ignore();
				cout << "\n==========================================================================\n" << endl;
				if (newCommand == 0)
					break;
				switch (newCommand)
				{
				case 1:
				{
					this->ctrl.updateTutorialToRepository(v[i].getPresenter(), v[i].getTitle(), v[i].getLikes() + 1, d.getMinutes(), d.getSeconds(), v[i].getSource());
					this->ctrl.updateTutorialToPlayList(v[i].getPresenter(), v[i].getTitle(), v[i].getLikes() + 1, d.getMinutes(), d.getSeconds(), v[i].getSource());
					cout << "\n\t Tutorial liked !\n" << endl;
					break;
				}
				case 2:
				{
					if (this->ctrl.testExistFromPlayListC(v[i]) == -1)
					{
						this->ctrl.addTutorialToPlayList(v[i]);
						cout << "\n\t The tutorial has been added to your playlist !\n" << endl;
					}
					else
						cout << "\n\t\t The tutorial does already exists in the playlist !" << endl;
					break;
				}
				}
			}
		}

	}
}

void UI::addTutorialToPlayListUI()
{
	cout << "\n\t\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\t\tEnter the title: ";
	std::string title;
	getline(cin, title);
	Tutorial t = this->ctrl.getRepo().findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" && t.getTitle() == "")
	{
		cout << "\n\tThere are no tutorials avaible with that input.\n" << endl;
		return;
	}
	try
	{
		this->ctrl.addTutorialToPlayList(t);
	}
	catch (TutorialException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}

	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}


void UI::deleteTutorialToPlayListUI()
{
	cout << "\n\t\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\t\tEnter the title: ";
	std::string title;
	getline(cin, title);
	Tutorial t = this->ctrl.getPlayList()->findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" && t.getTitle() == "")
	{
		cout << "\n\tThere are no tutorials avaible with that input.\n" << endl;
		return;
	}
	try
	{
		this->ctrl.deleteTutorialToPlayList(t.getPresenter(), t.getTitle());
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "\n\t Your command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandAdminRepo{ 0 };
				cout << "\n\t Your command: ";
				cin >> commandAdminRepo;
				cin.ignore();
				if (commandAdminRepo == 0)
					break;
				switch (commandAdminRepo)
				{
				case 1:
				{
					this->addTutorialToRepo();
					break;
				}
				case 2:
				{
					this->deleteTutorialFromRepo();
					break;
				}
				case 3:
				{
					this->updateTutorialFromRepo();
					break;
				}
				case 4:
				{
					this->displayAllTutorialsRepo();
					break;
				}
				case 5:
					cout << "\n\n \t All instances: " << Tutorial::allInstances << endl;
					cout << "\t Current instances: " << Tutorial::currentInstances << endl;
				}
			}
		}
		else
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUserRepo{ 0 };
				cout << "\n\t Your command: ";
				cin >> commandUserRepo;
				cin.ignore();
				if (commandUserRepo == 0)
					break;
				switch (commandUserRepo)
				{
				case 1:
				{
					this->displayAllTutorialsRepo();
					break;
				}
				case 2:
				{
					cout << "\n\tEnter the presenter: ";
					std::string presenter;
					getline(cin, presenter);
					if (this->ctrl.testExistFromRepositoryByPresenter(presenter, "", 0, 0, 0, "") == -1)
						cout << "\n\t There are no tutorials by " << presenter << " !" << endl;
					else
					{
						Tutorial t{ presenter, "", 0, Duration{ 0, 0 }, "" };
						tutorialsByPresenter(t);
					}
					break;
				}
				case 3:
				{
					this->ctrl.displayPlayListC();
					break;
				}
				case 4:
				{
					addTutorialToPlayListUI();
					break;
				}
				case 5:
				{
					deleteTutorialToPlayListUI();
					break;
				}
				case 6:
				{
					if (this->ctrl.getPlayList()->isEmpty())
					{
						cout << "\n\t\tNothing to watch, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.startPlayList();
					Tutorial t = this->ctrl.getPlayList()->getCurrentTutorial();
					cout << "\n\t\tNow watching: " << t.getPresenter() << " - " << t.getTitle() << endl;
					break;
				}
				case 7:
				{
					if (this->ctrl.getPlayList()->isEmpty())
					{
						cout << "\n\t\tNothing to watch, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.nextTutorialPlayList();
					Tutorial t = this->ctrl.getPlayList()->getCurrentTutorial();
					cout << "\n\t\tNow watching: " << t.getPresenter() << " - " << t.getTitle() << endl;
					break;
				}
				}
			}
		}
	}
	this->ctrl.writeToFileC();
}