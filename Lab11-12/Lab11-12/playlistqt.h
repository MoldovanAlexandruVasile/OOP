#ifndef PLAYLISTQT_H
#define PLAYLISTQT_H

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>

class PlaylistQt : public QWidget
{
	Q_OBJECT

public:
	PlaylistQt(Controller& c, QWidget *parent = 0);
	~PlaylistQt();

private:
	Controller& ctrl;
	std::vector<Tutorial> currentTutorialsInRepoList;
	std::vector<Tutorial> currentTutorialsInPlayList;

	QListWidget* playList;
	QListWidget* repoList;
	QLineEdit* titleEdit;
	QLineEdit* presenterEdit;
	QLineEdit* likesEdit;
	QLineEdit* durationEdit;
	QLineEdit* linkEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterButton;
	QPushButton* moveOneTutorialButton;
	QPushButton* moveAllTutorialsButton;
	QPushButton* watchButton;
	QPushButton* deletePlayListButton;
	QPushButton* likeButton;
	QPushButton* CSVButton;
	QRadioButton* sortButton;
	QRadioButton* shuffleButton;

	void initGUI();
	void populateRepoList();
	void populatePlaylist();
	int getRepoListSelectedIndex();
	int getPlayListSelectedIndex();
	void connectSignalsAndSlots();


private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();
	void listItemChangedPlayList();

	void addNewTutorial();
	void updateTutorial();
	void deleteTutorial();
	void deletePlayListTutorial();

	// filters the elements in the list, by the artist written in the artist edit box
	void filterRepoTutorials();
	void moveTutorialToPlaylist();
	void moveAllTutorials();
	void playTutorial();
	void sortedButtonHandler(bool checked);
	void shuffledButtonHandler(bool checked);
	void CSVOpenButtonHandler();
	void likeButtonHandler();

	std::vector<std::string> tokenize(const string& str, char delimiter)
	{
		vector <string> result;
		stringstream ss(str);
		string token;
		while (getline(ss, token, delimiter))
			result.push_back(token);

		return result;
	}
};

#endif // PLAYLISTQT_H
