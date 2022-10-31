#include <iostream>
#include <initializer_list>
#include <iterator> 
#include <vector>
#include <sstream>

#include "list.h"

using namespace std;

List::List() : last{new Node{nullptr, -100000, nullptr}}, first{last}
{

}

List::~List()
{
	
	Node* curr{first};
	while(curr -> next != last)
	{
		curr = curr -> next;
		remove(1);
	}
	delete first;
	delete last;
	
}

//----------------------------------------------------------------------

List::List(std::initializer_list<int> const& l) : List{}
{
	for (int i : l)
	{
		push(i);
	}
}

//----------------------------------------------------------------------

List::List( List& L) : List{}
{
    for(int i : L)
    {
        push(i);
    }
}

List::List(List&& l) : last{l.last}, first{l.first}
 		
{
	l.first = new Node{nullptr, 0, nullptr};
    l.last = new Node{nullptr, 0, nullptr};
    l.first -> next = l.last;
    l.last -> prev = l.first;
}

List::Node::Node(Node* prev, const int data, Node* next) : prev{prev}, data{data}, next{next}
{

}

List & List::operator=( List& L)
{
	List temp_list{L};
    swap(first, temp_list.first);
    swap(last, temp_list.last);

    return *this;
}


List & List::operator=(List&& l)
{

	/*Node* temp{last};
	last = l.last;
	l.last = temp;

	temp = first;
	first = l.first;
	l.first = temp;*/
	swap(last, l.last);
	swap(first, l.first);

	return *this;
}

/*void List::printList()
{
    Node* curr{first};
    cout << "From first" << endl;

    while (curr -> next != nullptr)
    {
        cout << curr -> data << endl;
        curr =     curr -> next;
    }

    curr = last;
    cout << endl << "From last" << endl;

    while (curr -> prev != nullptr)
    {
        curr = curr -> prev;
        cout << curr -> data << endl;
    }
}*/

stringstream List::printList()
{
	stringstream ss;
	Node* curr{first};
	cout <<"From first" << endl;

	while(curr -> next != nullptr)
	{
		ss << curr -> data << endl;
		curr = curr -> next;
	}

	curr = last;
	cout << endl << "From last" << endl;

	while(curr -> prev != nullptr)
	{
		curr = 	curr -> prev;
		ss << curr -> data << endl;
	}
	return ss;
}

void List::push(int new_data)
{
	Node* curr{first};

	if(curr -> next == nullptr)
	{
		first = new Node{nullptr, new_data, last};
		last -> prev = first;
	}	
	else
	{
		Node* end{last};

		while(end -> prev != nullptr)
		{
			end = end -> prev;
			int temp = end -> data;
		 	if(temp < new_data)
		 	{
	 			(end -> data) = new_data;  //5
		 		new_data = temp;   //9
			}
		}

		first = new Node{nullptr, new_data, end};
		end -> prev = first;
	}
}

void List::insertAfter(int index, int value)
{
	Node* curr {first};

	for (int i = 0; i < index; ++i)
	{
		curr = curr -> next;
	}

	Node* bla {curr -> prev};
	curr -> prev = new Node{curr -> prev, value, curr};
	bla -> next = curr -> prev;
}

void List::remove(int index)
{
  	Node* curr{first};
	if(index == 1)
	{
		first = first -> next;
	}
	else
	{
		for (int i = 1; i <= index; ++i)
		{
			curr = curr -> next;
		}

		Node* before{curr -> prev};
		before -> next = curr -> next;
		before = curr -> next;
		before -> prev = curr -> prev;
		
	}
	delete curr;
}

int List::at(int index) 
{
	Node* curr{first};
	index--;
	for (int i = 0; i < index; ++i)
	{
		curr = curr -> next;
	}
	return curr -> data;
}

listIterator List::begin()
{
	return listIterator(first);
}

listIterator List::end()
{
	return listIterator(last);
}

listIterator::listIterator(List::Node* const& n) : current{n}
{
	
}

listIterator& listIterator::operator =(listIterator const& it)
{
	current = it.current;
	return *this;
}

bool listIterator::operator !=(listIterator const& it)
{
	if (current  == it.current)
	{
		return false;	
	}
	return true;
}

listIterator& listIterator::operator ++()
{
	current = current -> next;
	return *this;
}

int listIterator::operator *()
{
	int value = current -> data;
	return value;
}

