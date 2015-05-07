/*
 * 
 */

#include <iostream>
using namespace std;

sn* R, F;

void addq(int in)
{
	sn* temp = new(sn);
	temp->data = in;
	temp->link = NULL;
	
	if (F == NULL)
	{
		R = F = temp;
	}
	else
	{
	R->link = temp;
	R = temp;
	}
}

int delq()
{
	if (F == NULL)
	{
		// qeue is empty
	}
	else
	{
		int data = F->data;
		temp = F;
		F = temp->link;
		delete(temp);
		return data;
	}
}

int main(int argc, char **argv)
{
	
	return 0;
}
