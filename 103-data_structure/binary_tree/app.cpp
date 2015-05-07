/*
 * a cpp program to make use of binary trees
 */

#include <iostream>
#include "BST.hpp"

using namespace std;
using namespace BinaryTree;
using namespace BST;

int main(int argc, char **argv)
{
	ptree head;
	cout << "Making a new node with 0 as head..." << endl;
	head = newNode(0);
	cout << "Insert as many nodes as you like, Enter 0 to end:" << endl;
	int input, count = 1;
	while (input)
	{
		cout << count << ") ";
		cin >> input;
		BSTinsert(head, input);
		count++;
	}
	cout << "The tree Traversed in-order: " << endl;
	inOrder(head);
	cout << "\nThe tree Traversed pre-order: " << endl;
	preOrder(head);
	cout << "\nThe tree Traversed post-order: " << endl;
	postOrder(head);
	
	return 0;
}
