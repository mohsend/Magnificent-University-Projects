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
	LinkedList *head;
	LinkedList *pointer;
	head = new LinkedList;
	pointer = head;
	 
	pointer->setData(0);
	for (int i = 1; i < 6; i++)
	{
		int in;
		cout << i << ") ";
		cin >> in;
		pointer = pointer->push(in);
	}
	
	cout << "print all:" << endl;
	print_all(head);
	cout << "travese:" << endl;
	travese(head);
	cout << "reverse travese:" << endl;
	reverse_travese(head);
	
	return 0;
}
