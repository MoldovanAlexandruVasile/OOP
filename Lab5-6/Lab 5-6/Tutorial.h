#pragma once
#include <iostream>

class Duration
{
private:
	double minutes;
	double seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(double min, double sec) : minutes(min), seconds(sec) {}

	double getMinutes() const { return minutes; }
	double getSeconds() const { return seconds; }
	void setMinutes(double min) { minutes = min; }
	void setSeconds(double sec) { seconds = sec; }
};

class Tutorial
{
public:
	std::string title;
	std::string presenter;
	int likes;
	Duration duration;
	std::string source;
	static int allInstances;
	static int currentInstances;

public:
	Tutorial();

	Tutorial(const std::string& presenter, const std::string& title,const int likes, const Duration& duration, const std::string& source);

	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	int getLikes() const { return likes; }
	Duration getDuration() const { return duration; }
	std::string getSource() const { return source; }

	//Opens a tutorial in browser.
	void play();

	//Destructor
	~Tutorial();

	//Copy of the tutorial t.
	Tutorial(const Tutorial& t);
};

