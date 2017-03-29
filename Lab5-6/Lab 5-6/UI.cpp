#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << "\n===================================================\n" << endl;
	cout << "\t\t~MENU~" <<endl;
	cout << "     1. Manage tutorials repository." << endl;
	cout << "     2. Manage playlist." << endl;
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
	cout << "\t\t 0. Back." << endl;
}

int UI::addTutorialToRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);
	if (this->ctrl.testExistFromRepository(presenter, title, 0, 0, 0, "") != -1)
		return 0;
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

	return this->ctrl.addTutorialToRepository(presenter, title, likes, minutes, seconds, link);
}

int UI::deleteTutorialFromRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);

	return this->ctrl.deleteTutorialFromRepository(presenter, title, 0, 0, 0, "");
}

int UI::updateTutorialFromRepo()
{
	cout << "\n\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\tEnter the title: ";
	std::string title;
	getline(cin, title);
	if (this->ctrl.testExistFromRepository(presenter, title, 0, 0, 0, "") == -1)
		return 0;
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

	return this->ctrl.updateTutorialToRepository(presenter, title, likes, minutes, seconds, link);
}

void UI::displayAllTutorialsRepo()
{
	DynamicVector<Tutorial> v = this->ctrl.getRepo().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "\n\tThere are no tutorials in the playlist.\n" << endl;
		return;
	}
	cout << "\n==========================================================================\n" << endl;
	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial t = tutorials[i];
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
	DynamicVector<Tutorial> v = this->ctrl.getPlayList().getPlayList();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "\n\tThere are no tutorials in the repository.\n" << endl;
		return;
	}
	cout << "\n==========================================================================\n" << endl;
	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial t = tutorials[i];
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
	DynamicVector<Tutorial> v = this->ctrl.getRepo().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "\n\tThere are no tutorials in the repository.\n" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++)
	{
		if (tut.getPresenter() == tutorials[i].getPresenter())
		{
			Tutorial t = tutorials[i];
			Duration d = t.getDuration();
			cout << "\n==========================================================================\n" << endl;
			cout << "  Tutorial by: " << t.getPresenter() << endl;
			cout << "  Title: " << t.getTitle() << endl;
			cout << "  Number of likes: " << t.getLikes() << endl;
			cout << "  Duration: " << d.getMinutes() << ":" << d.getSeconds() << endl;
			cout << "\n\t 1. Like tutorial." << endl;
			cout << "\t 2. Add to watch list." << endl;
			cout << "\t 3. Watch tutorial." << endl;
			cout << "\t 0. Do nothing." << endl;
			int newCommand{ 0 };
			cout << "\n\t Your command: ";
			cin >> newCommand;
			cin.ignore();
			cout << "\n==========================================================================\n" << endl;
			switch (newCommand)
			{
			case 1:
			{
				this->ctrl.updateTutorialToRepository(tutorials[i].getPresenter(), tutorials[i].getTitle(), tutorials[i].getLikes() + 1, d.getMinutes(), d.getSeconds(), tutorials[i].getSource());
				this->ctrl.updateTutorialToPlayList(tutorials[i].getPresenter(), tutorials[i].getTitle(), tutorials[i].getLikes() + 1, d.getMinutes(), d.getSeconds(), tutorials[i].getSource());
				break;
			}
			case 2:
			{
				this->ctrl.addTutorialToPlayList(tutorials[i]);
				break;
			}
			case 3:
			{
				//to do browser redirect ///////////////////////////////////////////////////////////////
				break;
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
	this->ctrl.addTutorialToPlayList(t);
	cout << "\n\tThe tutorial has been added to your playlist !\n";
}


void UI::deleteTutorialToPlayListUI()
{
	cout << "\n\t\tEnter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "\t\tEnter the title: ";
	std::string title;
	getline(cin, title);
	Tutorial t = this->ctrl.getPlayList().findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" && t.getTitle() == "")
	{
		cout << "\n\tThere are no tutorials avaible with that input.\n" << endl;
		return;
	}
	this->ctrl.deleteTutorialToPlayList(t.getPresenter(), t.getTitle());
	cout << "\n\tThe tutorial has been removed from your playlist !\n";
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
					int res = this->addTutorialToRepo();
					if (res == 1) cout << "\n\t Tutorial added ! \n" << endl;
					else cout << "\n\t Tutorial does already exists !\n" << endl;
					break;
				}
				case 2:
				{
					int res = this->deleteTutorialFromRepo();
					if (res == 1) cout << "\n\t Tutorial deleted ! \n" << endl;
					else cout << "\n\t Tutorial does not exist !\n" << endl;
					break;
				}
				case 3:
				{
					int res = this->updateTutorialFromRepo();
					if (res == 1) cout << "\n\t Tutorial updated ! \n" << endl;
					else cout << "\n\t Tutorial does not exist !\n" << endl;
					break;
				}
				case 4:
				{
					this->displayAllTutorialsRepo();
					break;
				}
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
						cout << "\n\t There are no tutorials by " << presenter << " !"<< endl;
					else
					{
						Tutorial t{ presenter, "", 0, Duration{ 0, 0 }, "" };
						tutorialsByPresenter(t);
					}
					break;
				}
				case 3:
				{
					this->displayAllTutorialsPlayList();
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
				}
			}
		}
	}
}