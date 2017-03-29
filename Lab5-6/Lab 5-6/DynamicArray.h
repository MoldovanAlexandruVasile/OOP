#pragma once
#include "Tutorial.h"

template<class TElement>
class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	DynamicVector(int capacity = 50);

	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	/*
	This function adds a new item to the repository.
	*/
	void add(TElement e);

	/*
	This function deletes an item to the repository.
	*/
	void deleteT(TElement e);

	/*
	This function deletes an item to the repository.
	*/
	void update(TElement e);

	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: -1 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int testExist(TElement e);

	/*
	This function updates an item from the repository.
	INPUT:  e - The tutorial.
	OUTPUT: -1 - If the tutorial does not exist in the repository.
			pos - If the tutorial exists, his position will be returnes.
	*/
	int testExistByPresenter(TElement e);

	//Returns the size of the dynamic vector.
	int getSize() const;

	//Returns the all elements of the vector.
	TElement* getAllElems() const;

	//Create the operator "="
	DynamicVector& operator=(DynamicVector v) 
	{
		if (this == &v)
			return *this;
		this->size = v.size;
		this->capacity = v.capacity;
		delete[] this->elems;
		this->elems = new TElement[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->elems[i] = v.elems[i];
		return *this;
	}

	//Creates the operator "+"
	DynamicVector& operator+(TElement e)
	{
		if (this->size == this->capacity)
			this->resize();
		this->elems[this->size] = e;
		this->size++;
		return *this;
	}

private:
	//Resizes the vector.
	void resize(double factor = 2);
};


template<class TElement>
void DynamicVector<TElement>::add(TElement e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}


template<class TElement>
void DynamicVector<TElement>::deleteT(TElement e)
{
	int pos = -1;
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			pos = i;
	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}


template<class TElement>
void DynamicVector<TElement>::update(TElement e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			this->elems[i] = e;
}


template<class TElement>
DynamicVector<TElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}


template<class TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector<TElement>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}


template<class TElement>
DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elems;
}


template<class TElement>
int DynamicVector<TElement>::testExist(TElement e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			return i;
	return -1;
}


template<class TElement>
int DynamicVector<TElement>::testExistByPresenter(TElement e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter())
			return i;
	return -1;
}


template<class TElement>
void DynamicVector<TElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}


template<class TElement>
TElement* DynamicVector<TElement>::getAllElems() const
{
	return this->elems;
}


template<class TElement>
int DynamicVector<TElement>::getSize() const
{
	return this->size;
}


template<class TElement>
DynamicVector<TElement> operator+(TElement e, DynamicVector<TElement> v)
{
	v.add(e);
	return v;
}
