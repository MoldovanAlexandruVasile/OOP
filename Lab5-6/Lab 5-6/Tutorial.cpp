#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>

Tutorial::Tutorial() : title(""), presenter(""), likes(0) , duration(Duration()), source("") {}

Tutorial::Tutorial(const std::string& presenter, const std::string& title, const int likes, const Duration& duration, const std::string& source)
{
	this->presenter = presenter;
	this->title = title;
	this->likes = likes;
	this->duration = duration;
	this->source = source;
}

void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}