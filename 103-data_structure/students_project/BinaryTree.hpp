/*
 * Binary Tree
 * Includes the node structure
 * Functions:
 * 1. newNode
 * 2. copy
 * 3. equal
 * 4. preOrder
 * 5. inOrder
 * 6. postOrder
 */

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1

#include <iostream>

namespace BinaryTree
{

// The Node structure itself
typedef struct treenode
{
  int data;
  treenode* lc;
  treenode* rc;
} *ptree;

// Function to make new node
ptree newNode(int x)
{
  ptree temp;
  temp = new(treenode);
  temp->data = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

// Function to make a copy of a tree
ptree copy (ptree t1)
{
	ptree t2;
	if (t1 == NULL)
	{
		return NULL;
	}
	else
	{
		t2 = newNode(t1->data);
		t2->lc = copy(t1->lc);
		t2->rc = copy(t1->rc);
		return t2;
	}
}

// Function to check if 2 trees are the same
bool equal (ptree t1, ptree t2)
{
	if ((t1 == NULL) && (t2 == NULL))
	{
		return true;
	}
	else if ((t1 != NULL) && (t2 != NULL))
	{
		if (t1->data == t2->data)
		{
			if (equal(t1->lc, t2->lc))
			{
				if (equal(t1->rc, t2->rc))
				{
					return true;
				}
			}
		}
	}
	return false;
}

// Prints the tree pre-order
// Traverse the root, left sub-tree, right sub-tree
void preOrder(ptree t)
{
	if (t)
	{
		std::cout << t->data << '\t';
		preOrder(t->lc);
		preOrder(t->rc);
	}
}

// Prints the tree in-order
// Traverse the left sub-tree, root, right sub-tree
void inOrder(ptree t)
{
	if (t)
	{
	  inOrder(t->lc);
	  std::cout << t->data << '\t';
	  inOrder(t->rc);
	}
}

// Prints the tree post-order
// Traverse left sub-tree, right sub-tree, root
void postOrder(ptree t)
{
	if (t)
	{
	  inOrder(t->lc);
	  inOrder(t->rc);
	  std::cout << t->data << '\t';
	}
}

}

#endif
