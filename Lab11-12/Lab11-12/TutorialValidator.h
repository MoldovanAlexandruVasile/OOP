#pragma once
#include <string>
#include "Tutorial.h"
#include <vector>

class TutorialException
{
private:
	std::vector<std::string> errors;

public:
	TutorialException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
	std::string getErrorsAsString() const;
};

class TutorialValidator
{
public:
	TutorialValidator() {}
	static void validate(const Tutorial& t);
};