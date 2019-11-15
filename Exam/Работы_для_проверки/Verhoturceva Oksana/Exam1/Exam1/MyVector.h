#pragma once
#include<iostream>

using namespace std;

template <typename T> class MyVector
{
private:
	T *_array;
	int _arraySize;
public:
	void push_back(T data)
	{
		T *_result = new T[++this->_arraySize];

		for (int index = 0; index < this->_arraySize; index++)
		{
			if (index != this->_arraySize - 1)
			{
				_result[index] = this->_array[index];
			}
			else
			{
				_result[index] = data;
				break;
			}
		}
		delete[] this->_array;
		this->_array = _result;
	}

	T pop()
	{
		return this->popIndex(this->_arraySize - 1);
	}

	void clear()
	{
		if (this->_array != NULL)
		{
			::ZeroMemory(this->_array, this->_arraySize);
		}
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}

	T operator [](int index)
	{
		return this->_array[index];
	}

	int size()
	{
		return this->_arraySize;
	}

	void pushIndex(T data, int index)
	{
		int oldSize = this->_arraySize;

		this->_arraySize = (this->_arraySize >= index) ? (++this->_arraySize) : (this->_arraySize + (index - this->_arraySize));

		T *_result = new T[this->_arraySize];

		int arrIndex = 0;

		for (int index2 = 0; index2 < this->_arraySize; index2++)
		{
			if (index2 == index)
			{
				_result[index2] = data;
				continue;
			}

			if (arrIndex != oldSize)
			{
				_result[index2] = this->_array[arrIndex++];
			}
		}
		delete[] this->_array;
		this->_array = _result;
	}

	T popIndex(int index)
	{
		T *_result = new T[--this->_arraySize];

		T resItem;

		int resIndex = 0;

		for (int index2 = 0; index2 < this->_arraySize + 1; index2++)
		{
			T item = this->_array[index2];

			if (index == index2)
			{
				resItem = item;
				continue;
			}
			_result[resIndex++] = this->_array[index2];
		}
		delete[] this->_array;
		this->_array = _result;
		return resItem;
	}

	MyVector()
	{
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}

};
void printMyVector(MyVector<int> vector)
{
	int size = vector.size();

	if (!size)
	{
		cout << "В Векторе нет элементов!" << endl;
		return;
	}

	for (int index = 0; index < vector.size(); index++)
	{
		cout << index << " Элемент вектора: " << vector[index] << endl;
	}
}