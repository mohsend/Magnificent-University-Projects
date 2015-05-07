namespace BST
{
typedef struct treenode
{
  int data;
  ptree lc, rc;
} ptree;

bool BSTinsert (ptree t, int x)
{
  if (x == t->data)
  {
    cout << "ERROR: already exists!" << endl;
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

ptree newNode(int x)
{
  ptree temp;
  temp = new(treenode);
  temp->data = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}
}
