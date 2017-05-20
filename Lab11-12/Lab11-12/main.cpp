#include "playlistqt.h"
#include <QtWidgets/QApplication>
#include "Tutorial.h"
#include <Windows.h>
#include "PlayList.h"
#include "CSV_Playlist.h"
#include "HTML_Playlist.h"
#include "Repository.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "Tutorials.txt" };
	CSV p;
	Controller ctrl{ repo, &p };
	PlaylistQt w{ ctrl };
	w.show();
	return a.exec();
}
