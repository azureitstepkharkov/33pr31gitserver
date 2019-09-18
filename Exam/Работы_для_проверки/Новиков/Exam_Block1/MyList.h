#pragma once
#include<iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class MyList
{
protected:

	template<typename T>
	class ListElement
	{
	public:
		T data;
		ListElement* next;
		ListElement* prev;

		ListElement(T data, ListElement* next = nullptr, ListElement* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}

		~ListElement() { size--; }

	};

	int size;
	ListElement<T> *head;
	ListElement<T> *tail;

public:
	MyList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void pusBack(T data)
	{
		size++;
		if (head == nullptr)
		{
			head = new ListElement<T>(data);
		}
		else
		{
			ListElement<T> *current = this->head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			tail = new ListElement<T>(data);
			tail->next = nullptr;
			tail->prev = current;
			current->next = tail;
		}
	}

	void Print()
	{
		ListElement<T> *current = this->head;
		while (current->next != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data << " ";
	}

	void revercePrint()
	{
		ListElement<T> *current = this->tail;
		while (current->prev != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << current->data << " ";
	}

	int getSize() { return this->size; }

	T& operator[](const int index)
	{
		if (index >= 0 && index <= getSize())
		{
			int count = 0;
			ListElement<T> *current = this->head;
			while (current != nullptr)
			{
				if (count == index)
				{
					return current->data;
				}
				current = current->next;
				count++;
			}
		}
		else
		{
			cout << "index has invalid value";
			throw invalid_argument("index has invalid value");
		}
	}

};

