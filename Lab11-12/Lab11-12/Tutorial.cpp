#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>

int Tutorial::currentInstances = 0;
int Tutorial::allInstances = 0;

Tutorial::Tutorial() : title(""), presenter(""), likes(0), duration(Duration()), source("")
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

std::vector<std::string> tokenize(std::string s, char del)
{
	std::stringstream ss(s);
	std::string aux;
	std::vector<std::string> res;
	while (getline(ss, aux, del))
		res.push_back(aux);
	return res;
}

std::istream & operator >> (std::istream & is, Tutorial & t)
{
	std::string s;
	getline(is, s);
	std::vector<std::string> res = tokenize(s, ',');
	if (res.size() != 6)
		return is;
	t.presenter = res[0];
	t.title = res[1];
	t.likes = atoi(res[2].c_str());
	t.duration.setMinutes(atoi(res[3].c_str()));
	t.duration.setSeconds(atoi(res[4].c_str()));
	t.source = res[5];
	return is;
}

std::ostream & operator<<(std::ostream & os, Tutorial & t)
{
	os << t.presenter << "," << t.title << "," << t.likes << "," << t.duration.getMinutes() << "," << t.duration.getSeconds() << "," << t.source << "\n";
	return os;
}
