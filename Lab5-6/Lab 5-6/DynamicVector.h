#pragma once
#include "Tutorial.h"

typedef Tutorial TElement;

class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:

	DynamicVector(int capacity = 10);

	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);

	/*
	This function adds a new item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does already exists in the repository.
			1 - If the tutorial has been added.
	*/
	int add(const TElement& e);

	/*
	This function deletes an item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exists in the repository.
			1 - If the tutorial has been deleted.
	*/
	int deleteT(const TElement& e);

	/*
	This function deletes an item to the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exists in the repository.
			1 - If the tutorial has been updated.
	*/
	int update(const TElement& e);

	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: 0 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int testExist(const TElement& e);

	//Returns the size of the dynamic vector.
	int getSize() const;

	//Returns the all elements of the vector.
	TElement* getAllElems() const;

private:
	void resize(double factor = 2);
};

