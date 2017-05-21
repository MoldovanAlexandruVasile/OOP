#include "playlistqt.h"
#include <vector>
#include "Tutorial.h"
#include <QMessageBox>
#include "Exceptions.h"

PlaylistQt::PlaylistQt(Controller& c, QWidget *parent) : ctrl{ c }, QWidget{ parent }
{
	this->initGUI();
	this->currentTutorialsInRepoList = this->ctrl.getRepo().getAll();
	this->currentTutorialsInPlayList = this->ctrl.getPlayList()->getAll();
	this->populateRepoList();
}

PlaylistQt::~PlaylistQt()
{
}

void PlaylistQt::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the song data
	// - grid layout with buttons: add, delete, update, filter
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	// tutorial data
	QWidget* songDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ songDataWidget };
	this->presenterEdit = new QLineEdit{};
	this->titleEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	formLayout->addRow("&Presenter: ", presenterEdit);
	formLayout->addRow("&Title: ", titleEdit);
	formLayout->addRow("&Likes: ", likesEdit);
	formLayout->addRow("&Duration: ", durationEdit);
	formLayout->addRow("&Link: ", linkEdit);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton(" Add ");
	this->deleteButton = new QPushButton(" Delete ");
	this->updateButton = new QPushButton(" Update ");
	this->filterButton = new QPushButton(" Filter by presenter ");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(filterButton, 0, 3);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All tutorials" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(songDataWidget);
	leftSide->addWidget(buttonsWidget);

	// middle component: just two button - to add the songs from the reposiotory to the playlist
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneTutorialButton = new QPushButton{ " Add the selected tutorial to the playlist " };
	this->moveAllTutorialsButton = new QPushButton{ " Add all tutorials to the playlist" };
	this->sortButton = new QRadioButton(" Sort ");
	this->shuffleButton = new QRadioButton(" Shuffle ");
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneTutorialButton);
	vLayoutUpperPart->addWidget(this->moveAllTutorialsButton);
	vLayoutUpperPart->addWidget(this->sortButton);
	vLayoutUpperPart->addWidget(this->shuffleButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right component: the playlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	// playlist
	playList = new QListWidget{};

	// two buttons
	QWidget* playlistButtonsWidget = new QWidget{};
	QHBoxLayout* playlistButtonsLayout = new QHBoxLayout{ playlistButtonsWidget };
	this->watchButton = new QPushButton(" Watch ");
	this->deletePlayListButton = new QPushButton(" Delete from playlist ");
	playlistButtonsLayout->addWidget(deletePlayListButton);
	playlistButtonsLayout->addWidget(watchButton);

	// add everything to the right layout
	rightSide->addWidget(new QLabel{ "PlayList" });
	rightSide->addWidget(playList);
	rightSide->addWidget(playlistButtonsWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	// connect the signals and slots
	this->connectSignalsAndSlots();
}

void PlaylistQt::connectSignalsAndSlots()
{
	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->playList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChangedPlayList()));

	// add button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewTutorial()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTutorial()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateTutorial()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterRepoTutorials()));

	QObject::connect(this->moveOneTutorialButton, SIGNAL(clicked()), this, SLOT(moveTutorialToPlaylist()));
	QObject::connect(this->moveAllTutorialsButton, SIGNAL(clicked()), this, SLOT(moveAllTutorials()));

	QObject::connect(this->watchButton, SIGNAL(clicked()), this, SLOT(playTutorial()));
	QObject::connect(this->deletePlayListButton, SIGNAL(clicked()), this, SLOT(deletePlayListTutorial()));

	QObject::connect(this->sortButton, SIGNAL(toggled(bool)), this, SLOT(sortedButtonHandler(bool)));
	QObject::connect(this->shuffleButton, SIGNAL(toggled(bool)), this, SLOT(shuffledButtonHandler(bool)));
}

void PlaylistQt::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto s : this->currentTutorialsInRepoList)
	{
		QString itemInList = QString::fromStdString(s.getPresenter() + " - " + s.getTitle());
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		//QFont font("Courier", 20, 10, true);
		//item3->setFont(font);
		this->repoList->addItem(item3);
	}

	// set the selection on the first item in the list
	if (this->currentTutorialsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void PlaylistQt::populatePlaylist()
{
	// clear the list, if there are elements in it
	if (this->playList->count() > 0)
		this->playList->clear();

	for (auto s : this->ctrl.getPlayList()->getAll())
	{
		QString itemInList = QString::fromStdString(s.getPresenter() + " - " + s.getTitle());
		this->playList->addItem(itemInList);
	}
}

int PlaylistQt::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->presenterEdit->clear();
		this->titleEdit->clear();
		this->likesEdit->clear();
		this->durationEdit->clear();
		this->linkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void PlaylistQt::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial> tutorials = this->currentTutorialsInRepoList;

	// get the song at the selected index
	if (idx >= tutorials.size())
		return;
	Tutorial t = tutorials[idx];

	this->presenterEdit->setText(QString::fromStdString(t.getPresenter()));
	this->titleEdit->setText(QString::fromStdString(t.getTitle()));
	std::string s = to_string(t.getLikes());
	this->likesEdit->setText(QString::fromStdString(s));
	this->durationEdit->setText(QString::fromStdString(t.getDuration().toString()));
	this->linkEdit->setText(QString::fromStdString(t.getSource()));
}

int PlaylistQt::getPlayListSelectedIndex()
{
	if (this->playList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->playList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->presenterEdit->clear();
		this->titleEdit->clear();
		this->likesEdit->clear();
		this->durationEdit->clear();
		this->linkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void PlaylistQt::listItemChangedPlayList()
{
	int idx = this->getPlayListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial> tutorials = this->ctrl.getPlayList()->getAll();

	// get the song at the selected index
	if (idx >= tutorials.size())
		return;
	Tutorial t = tutorials[idx];

	this->presenterEdit->setText(QString::fromStdString(t.getPresenter()));
	this->titleEdit->setText(QString::fromStdString(t.getTitle()));
	std::string s = to_string(t.getLikes());
	this->likesEdit->setText(QString::fromStdString(s));
	this->durationEdit->setText(QString::fromStdString(t.getDuration().toString()));
	this->linkEdit->setText(QString::fromStdString(t.getSource()));
}

void PlaylistQt::addNewTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();
	std::string likes = this->likesEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}
	std::string source = this->linkEdit->text().toStdString();

	try
	{
		this->ctrl.addTutorialToRepository(presenter, title, stod(likes), stod(durationTokens[0]), stod(durationTokens[1]), source);
		// refresh the list
		this->currentTutorialsInRepoList = this->ctrl.getRepo().getAll();
		this->populateRepoList();
	}
	catch (TutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::deleteTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();

	try
	{
		this->ctrl.deleteTutorialFromRepository(presenter, title, 0, 0, 0, "");
		// refresh the list
		this->currentTutorialsInRepoList = this->ctrl.getRepo().getAll();
		this->populateRepoList();
	}
	catch (InexistenTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::deletePlayListTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();

	try
	{
		this->ctrl.deleteTutorialToPlayList(presenter, title);
		// refresh the list
		this->currentTutorialsInPlayList = this->ctrl.getPlayList()->getAll();
		this->populatePlaylist();
	}
	catch (InexistenTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::updateTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();
	std::string likes = this->likesEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}
	std::string source = this->linkEdit->text().toStdString();

	try
	{
		this->ctrl.updateTutorialToRepository(presenter, title, stod(likes), stod(durationTokens[0]), stod(durationTokens[1]), source);
		// refresh the list
		this->currentTutorialsInRepoList = this->ctrl.getRepo().getAll();
		this->populateRepoList();
	}

	catch (TutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::filterRepoTutorials()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	if (presenter == "")
	{
		this->currentTutorialsInRepoList = this->ctrl.getRepo().getAll();
		this->populateRepoList();
		return;
	}

	this->currentTutorialsInRepoList = this->ctrl.filterByPresenter(presenter);
	this->populateRepoList();
}

void PlaylistQt::moveTutorialToPlaylist()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentTutorialsInRepoList.size())
		return;

	const Tutorial& t = this->currentTutorialsInRepoList[idx];
	try
	{
		this->ctrl.addTutorialToPlayList(t);
		this->populatePlaylist();
	}
	catch (TutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::moveAllTutorials()
{
	try
	{
		for (auto t : this->currentTutorialsInRepoList)
		{
			this->ctrl.addTutorialToPlayList(t);
		}
		this->populatePlaylist();
	}

	catch (TutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void PlaylistQt::playTutorial()
{
	int idx = this->getPlayListSelectedIndex();
	if (idx == -1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "No selected tutorial from playlist !");
		return;
	}
	else this->ctrl.getPlayList()->getAll()[idx].play();
}

void PlaylistQt::sortedButtonHandler(bool checked)
{
	if (checked == true)
	{
		repoList->clear();
		vector<Tutorial> v = ctrl.getRepo().getAll();
		sort(v.begin(), v.end(), [](Tutorial m1, Tutorial m2) {return m1.getPresenter() < m2.getPresenter(); });
		for (auto m : v) {
			new QListWidgetItem((m.getPresenter() + " - " + m.getTitle()).data(), repoList);
		}
	}
}

void PlaylistQt::shuffledButtonHandler(bool checked)
{
	if (checked == true)
	{
		repoList->clear();
		vector<Tutorial> v = ctrl.getRepo().getAll();
		for (auto m : v) {
			new QListWidgetItem((m.getPresenter() + " - "+ m.getTitle()).data(), repoList);
		}
	}
}