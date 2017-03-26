#include "DynamicVector.h"


DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
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

int DynamicVector::add(const TElement& e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			return 0;
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
	return 1;
}

int DynamicVector::testExist(const TElement& e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			return i;
	return 0;
}

int DynamicVector::deleteT(const TElement& e)
{
	int pos = -1;
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
			pos = i;
	if (pos == -1)
		return 0;
	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
	return 1;
}

int DynamicVector::update(const TElement& e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].presenter == e.getPresenter() && this->elems[i].title == e.getTitle())
		{
			this->elems[i] = e;
			return 1;
		}
	return 0;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}