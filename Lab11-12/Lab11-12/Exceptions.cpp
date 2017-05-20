#include "Exceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char *RepositoryException::what()
{
	return this->message.c_str();
}

const char *DuplicateTutorialException::what()
{
	return "\n\tThere is another tutorial with the same presenter and title !\n";
}

const char *InexistenTutorialException::what()
{
	return "\n\tThere are no tutorials with the given presenter and title !\n";
}