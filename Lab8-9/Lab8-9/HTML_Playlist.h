#pragma once
#include "PlayList.h"

class HTML : public PlayList
{
public:
	void writeToFilePL() override
	{
		std::ofstream fout("PlayList.html");

		std::string rez = "<!DOCTYPE html>\n";
		rez += "<html>\n";
		rez += "<head>\n";
		rez += "<title>ShopBag</title>\n";
		rez += "</head>\n";
		rez += "<body>\n";
		rez += "<table border=\"1\">\n";
		rez += "<tr>\n";
		rez += "<td>Presenter</td>\n";
		rez += "<td>Title</td>\n";
		rez += "<td>Likes</td>\n";
		rez += "<td>Duration</td>\n";
		rez += "<td>Source</td>\n";
		rez += "</tr>\n";

		for (auto it : tutorials) {

			rez += "<tr>\n";
			std::stringstream ss1, ss2, ss3;

			ss1 << it.getLikes();
			ss2 << it.getDuration().getMinutes();
			ss3 << it.getDuration().getSeconds();

			rez += "<td>" + it.getPresenter() + "</td>\n";
			rez += "<td>" + it.getTitle() + "</td>\n";
			rez += "<td>" + ss1.str() + "</td>\n";
			rez += "<td>" + ss2.str() + ":" + ss3.str() + "</td>\n";
			rez += "<td><a href=\"" + it.getSource() + "\">" + "Link" + "</a></td>\n";

			rez += "</tr>\n";
		}

		rez += "</table>";
		rez += "</body>\n";
		rez += "</html>\n";

		fout << rez;
	}

	void executeThingsPL() override
	{
		this->writeToFilePL();
		ShellExecuteA(NULL, NULL, "chrome.exe", "PlayList.html", NULL, SW_SHOWMAXIMIZED);
	}
};