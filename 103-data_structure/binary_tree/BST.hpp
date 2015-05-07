/*
 * 
 */

#include <BinaryTree.hpp>

using namespace BinaryTree;

namespace BST
{

// Insert a new value to the BST
bool BSTinsert (ptree t, int x)
{
  if (x == t->data)
  {
    return false;
  }
  else if (x < t->data)
  {
    if (t->lc == NULL)
    {
      //insert
      t->lc = newNode(x);
      return true;
    }
    else
    {
      BSTinsert(t->lc, x);
    }
  }
  else
  {
    if (x->rc == NULL)
    {
      //insert
      t->rc = newNode(x);
      return true;
    }
    else
    {
      BSTinsert(t->rc, x);
    }
  }
}

// Search for a value in a BST
ptree BSTsearch(ptree t, int q)
{
  if (t == NULL)
  {
    return NULL;
  }
  else
  {
    if (q == t->data)
    {
      return t;
    }
    else if (q < t->data)
    {
      return BSTsearch(t->lc, q);
    }
    else
    {
      return BSTsearch(t->rc, q);
    }
  }
}

}
