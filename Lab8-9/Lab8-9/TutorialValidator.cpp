#include "TutorialValidator.h"

using namespace std;

TutorialException::TutorialException(std::vector<std::string> _errors): errors{ _errors }
{
}

std::vector<std::string> TutorialException::getErrors() const
{
	return this->errors;
}

void TutorialValidator::validate(const Tutorial& t)
{
	vector<string> errors;
	if (t.getPresenter().size() < 1)
		errors.push_back("\n\t\tThe presenter can't be NULL !\n");
	if (t.getTitle().size() < 1)
		errors.push_back("\n\t\tThe title can't be NULL !\n");
	if (t.getSource().size() < 1)
		errors.push_back("\n\t\tThe source can't be NULL !\n");
	if (t.getLikes() < 0)
		errors.push_back("\n\t\tThe tutorial can't have negative numbers of likes !\n");
	if (t.getDuration().getMinutes() < 0)
		errors.push_back("\n\t\tThe minutes can't be negative !\n");
	if (t.getDuration().getSeconds() < 0)
		errors.push_back("\n\t\tThe seconds can't be negative !\n");	
	
	if (errors.size() > 0)
		throw TutorialException(errors);
}