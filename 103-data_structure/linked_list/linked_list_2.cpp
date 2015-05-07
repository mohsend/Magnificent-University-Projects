/*
 * 
 */

#include <iostream>
using namespace std;

sn* top = NULL;

void push(int in)
{
	sn* temp = new(sn);
	top->data = in;
	top->link = NULL;
	top->link = top;
	top = temp;
}

int pop()
{
	if (top == NULL)
	{
		// stack is empty
	}
	else
	{
		int data = top->data;
		temp = top;
		top = top->link;
		delete(temp);
		return data;
	}
}

int main(int argc, char **argv)
{
	
	return 0;
}
