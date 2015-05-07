/*
 * 
 */

#include <iostream>
using namespace std;

class LinkedList
{
	public:
		int data;
		LinkedList *link;
		
		LinkedList()
		{
			link = NULL;
		}
		int setData(int in)
		{
			data = in;
			return data;
		}
		int getData()
		{
			return data;
		}
		LinkedList* push(int in)
		{
			link = new LinkedList;
			link->setData(in);
			return link;
		}
		LinkedList* next()
		{
			return link;
		}
};

bool search(LinkedList* pointer, int query)
{
	while (pointer != NULL)
	{
		if (pointer->getData() == query)
		{
			return true;
		}
		pointer = pointer->next();
	}
	return false;
}

void print_all (LinkedList* pointer)
{
	while (pointer != NULL)
	{
		cout << pointer->getData() << '\t';
		pointer = pointer->next();
	}
	cout << endl;
}

void delete_(LinkedList* head,LinkedList* todel)
{
	while(head->link != todel)
	{
		head = head->next();
	}
	head->link = todel->link;
	delete(todel);
}

void push_inbetween(LinkedList* afterthis, int in)
{
	LinkedList* temp;
	temp = afterthis->link;
	
}

void travese (LinkedList* x)
{
	if (x == NULL)
	{
		cout << endl;
		return;
	}
	else
	{
		cout << x->data << '\t';
		travese(x->link);
	}
}

void reverse_travese (LinkedList* x)
{
	if (x == NULL)
	{
		cout << endl;
		return;
	}
	else
	{
		reverse_travese(x->link);
		cout << x->data << '\t';
	}
}

int main(int argc, char **argv)
{
	LinkedList *first;
	LinkedList *pointer;
	first = new LinkedList;
	pointer = first;
	 
	pointer->setData(1);
	pointer = pointer->push(2);
	pointer = pointer->push(3);
	pointer = pointer->push(4);
	
	print_all(first);
	travese(first);
	reverse_travese(first);
	
	return 0;
}
