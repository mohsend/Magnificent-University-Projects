/*
 * 
 */

#include <iostream>
using namespace std;

void add(int in)
{
	temp = new(sn);
	if (endp == NULL)
	{
		temp->data = in;
		endp = temp;
		temp->link = temp;
	}
	else
	{
		temp->link = endp->link;
		endp->link = temp;
	}
}

int main(int argc, char **argv)
{
	
	return 0;
}
