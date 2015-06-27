/*
 * Binary Search Tree
 * Functions:
 * 1. BSTinsert
 * 2. BSTsearch
 */
 
#ifndef BST_HPP
#define BST_HPP 1

#include "BinaryTree.hpp"

using namespace BinaryTree;

namespace BST
{

// Insert a new value to the BST
ptree BSTinsert (ptree t, Cstudent x)
{
  if (x.getId() == t->data.getId())
  {
    return NULL;
  }
  else if (x.getId() < t->data.getId())
  {
    if (t->lc == NULL)
    {
      //insert
      t->lc = newNode(x);
      return t->lc;
    }
    else
    {
      return BSTinsert(t->lc, x);
    }
  }
  else
  {
    if (t->rc == NULL)
    {
      //insert
      t->rc = newNode(x);
      return t->rc;
    }
    else
    {
      return BSTinsert(t->rc, x);
    }
  }
}

// Search for a value in a BST
ptree BSTsearch(ptree t, uint64_t q)
{
  if (t == NULL)
  {
    return NULL;
  }
  else
  {
    if (q == t->data.getId() )
    {
      return t;
    }
    else if (q < t->data.getId() )
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
#endif
