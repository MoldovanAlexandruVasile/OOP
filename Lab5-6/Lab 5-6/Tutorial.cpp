#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>

int Tutorial::currentInstances = 0;
int Tutorial::allInstances = 0;

Tutorial::Tutorial() : title(""), presenter(""), likes(0) , duration(Duration()), source("") 
{
	this->allInstances++;
	this->currentInstances++;
}

Tutorial::Tutorial(const std::string& presenter, const std::string& title, const int likes, const Duration& duration, const std::string& source)
{
	this->presenter = presenter;
	this->title = title;
	this->likes = likes;
	this->duration = duration;
	this->source = source;
	this->allInstances++;
	this->currentInstances++;
}

Tutorial::~Tutorial()
{
	this->currentInstances--;
}

Tutorial::Tutorial(const Tutorial& t)
{
	this->presenter = t.presenter;
	this->title = t.title;
	this->likes = t.likes;
	this->duration = t.duration;
	this->source = t.source;
	this->allInstances++;
	this->currentInstances++;
}

void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}