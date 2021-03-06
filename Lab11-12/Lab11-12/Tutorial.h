#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

	std::string toString()
	{
		std::stringstream ss;
		ss << this->minutes << ":" << this->seconds;
		return ss.str();
	}
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

	Tutorial(const std::string& presenter, const std::string& title, const int likes, const Duration& duration, const std::string& source);

	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	int getLikes() const { return likes; }
	Duration getDuration() const { return duration; }
	std::string getSource() const { return source; }

	void setPresenter(const std::string& p) { presenter = p; }
	void setTitle(const std::string& t) { title = t; }
	void setLikes(int l) { likes = l; }
	void setDuration(Duration d) { duration = d; }
	void setSource(const std::string& s) { source = s; }

	//Opens a tutorial in browser.
	void play();

	//Destructor
	~Tutorial();

	//Copy of the tutorial t.
	Tutorial(const Tutorial& t);

	friend std::istream & operator >> (std::istream & is, Tutorial& t);
	friend std::ostream & operator << (std::ostream & os, Tutorial& t);
};