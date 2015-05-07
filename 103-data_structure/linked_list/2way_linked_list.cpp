/*
 * 
 */

#include <iostream>
using namespace std;

void add(sn* x, int in)
{
	sn* y = new(sn);
	sn* next = x->Rlink;
	y->Rlink = next;
	next->Llink= y;
	x->Rlink = y;
	y->Llink = x;
}

void del(sn* delthis)
{
	sn* prev = delthis->Llink;
	sn* next = delthis->Rlink;
	prev->Rlink = next;
	next->Llink = prev;
	delete(delthis);
}

int main(int argc, char **argv)
{
	
	return 0;
}
