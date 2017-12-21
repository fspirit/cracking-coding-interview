#include <iostream>
#include "../node.h"

struct List
{	
	List(): head(nullptr) {};
	Node * head;

	void Add(Node * node)
	{		
		if (head == nullptr)
		{
			head = node;
			return;
		}
		auto current = head;		
		while (current->next != nullptr)
			current = current->next;
		current->next = node;
	}

	void Delete(Node * node)
	{
		std::cout << "Deleting" << std::endl;
		if (head == node)
		{
			head = head->next;
			return;
		}
		auto prev = head;
		while (prev->next != nullptr)
		{
			if (prev->next == node)
			{
				prev->next = prev->next->next;
				break;
			}
			prev = prev->next;
		}
	}

	void Delete(int value)
	{		
		auto current = head;
		Node * prev = nullptr;
		while (current != nullptr)
		{
			if (current->value == value)
			{
				if (prev == nullptr)
				{
					head = current->next;
				}
				else if (current->next == nullptr)
				{
					prev->next = nullptr;
				}
				else
				{
					prev->next = current->next;
				}
				break;
			}
			prev = current;
			current = current->next;
		}	
	}

	void Print()
	{
		auto current = head;
		while (current != nullptr)
		{
			std::cout << current->value << " -> "; 
			current = current->next;
		}
		std::cout << std::endl;
	}

	int Size()
	{
		int size = 0;
		auto current = head;

		while (current != nullptr)
		{
			size++;
			current = current->next;
		}

		return size;
	}
};