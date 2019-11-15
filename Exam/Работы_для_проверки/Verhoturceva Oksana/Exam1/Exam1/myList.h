#pragma once
#include<iostream>

using namespace std;
template<typename T>
class MyList
{

private:
	template<typename T>
	class List
	{
	public:
		T data;
		List* next;
		List* prev;
		List(T data = T(), List* next = nullptr, List* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}

	};

	int size;
	List<T> *head;
	List<T> *end;

public:
	MyList()
	{
		size = 0;
		head = nullptr;
		end = nullptr;
	}

	void push_back(T data)
	{

		if (head == nullptr)
		{
			head = new List<T>(data);
		}
		else
		{
			List<T> *current = this->head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			size++;

			end = new List<T>(data);
			end->next = nullptr;
			end->prev = current;
			current->next = end;
		}
	}
	//void pop_front() {
	//	List<T> *temp = head;
	//	head = head->next;
	//	delete temp;
	//	size--;
	//}

	void Print()
	{
		List<T> *current = this->head;
		while (current->next != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data << " ";
	}

	void revercePrint()
	{
		List<T> *current = this->end;
		while (current->prev != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << current->data << " ";
	}

	int getSize() { return this->size; }

	T&  operator[](const int index)
	{
		int counter = 0;
		List <T> *current = this->head;

		while (current != nullptr)
		{
			if (count == index)
			{
				return current->data;
			}
			current = current->next;
			counter++;
		}
	}
};
