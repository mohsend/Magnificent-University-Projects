/*
 * 
 */


namespace BinaryTree
{

// The Node structure itself
typedef struct treenode
{
  int data;
  ptree lc, rc;
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

}
