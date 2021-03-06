#include "quick_find.h"

UF::UF()
  :size(10)
{
  init();
}

UF::UF(const int &n)
  :size(n)
{
  init();
}

UF::UF(const UF &others)
  :size(others.size)
{
  if(id != NULL)
  {
    delete id;
    id = NULL;
  }

  id = new int[size];
  for(int i = 0; i < size; ++i)
    id[i] = others.id[i];
}

UF::~UF()
{
  size = 0;
  if(id != NULL)
  {
    delete id;
    id = NULL;
  }
}

/// Initialized each element of id array by itself
void UF::init()
{
  if(size > 0)
  {
    id = new int[size];

    for(int i= 0; i < size; ++i)
      id[i] = i;
  }
}

/// pair of numbers will be connected if and only if,
/// both have in same component. Means, both have same
/// value.
bool UF::Connected(int begin, int end) const
{
  return( id[begin] == id[end] );
}

/// change all the entries with id[begin] to id[end]
/// example: union(6, 1)
/// here all the entry have same value of id[6] will be
/// replaced by id[1]
void UF::Union(int begin, int end)
{
  if(!Connected(begin, end))
  {
    int bid = id[begin];
    int eid = id[end];

    for(int i = 0; i < size; ++i)
    {
      if(id[i] == bid)
        id[i] = eid;
    }
  }
}

//--------------------------------------------------------------------------------

QuickUnionUF::QuickUnionUF()
  :size(10)
{
  init();
}

QuickUnionUF::QuickUnionUF(const int &n)
  :size(n)
{
  init();
}

QuickUnionUF::QuickUnionUF(const QuickUnionUF &others)
  :size(others.size)
{
  if(id != NULL)
  {
    delete id;
    id = NULL;
  }

  id = new int[size];
  for(int i = 0; i < size; ++i)
    id[i] = others.id[i];
}

QuickUnionUF::~QuickUnionUF()
{
  size = 0;

  if(id != NULL)
  {
    delete id;
    id = NULL;
  }
}

/// Initialized each element of id array by itself
void QuickUnionUF::init()
{
  if(size > 0)
  {
    id = new int[size];

    for(int i= 0; i < size; ++i)
      id[i] = i;
  }
}

/// chase parent pointer untill reach root
int QuickUnionUF::root(const int &val) const
{
  int pos = val;

  while(id[pos] != pos)
    pos = id[pos];

  return pos;
}

/// pair of numbers will be connected if and only if,
/// both have in same root (parent).
bool QuickUnionUF::Connected(int begin, int end) const
{
  return( root(begin) == root(end) );
}

/// change root of 'begin' to point to root of 'end'.
/// example: union(6, 1)
/// if root(6) = 8
///    root(1) = 2
/// then change id[8] = 2
void QuickUnionUF::Union(int begin, int end)
{
  if(!Connected(begin, end))
  {
    int broot = root(begin);
    int eroot = root(end);

    id[broot] = eroot;
  }
}


//--------------------------------------------------------------------------------

WeightedQuickUnionUF::WeightedQuickUnionUF()
  :size(10)
{
  init();
}

WeightedQuickUnionUF::WeightedQuickUnionUF(const int &n)
  :size(n)
{
  init();
}

WeightedQuickUnionUF::WeightedQuickUnionUF(const WeightedQuickUnionUF &others)
  :id(NULL),
  sz(NULL),
  size(others.size)
{
  resize(&id, others.id, size);
  resize(&sz, others.sz, size);
}

WeightedQuickUnionUF::~WeightedQuickUnionUF()
{
  size = 0;

  remove(&id);
  remove(&sz);
}

/// Initialized each element of id array by itself
/// each element of sz by 1.
void WeightedQuickUnionUF::init()
{
  if(size > 0)
  {
    id = new int[size];
    sz = new int[size];
    for(int i= 0; i < size; ++i)
    {
      id[i] = i;
      sz[i] = 1;
    }
  }
}

void WeightedQuickUnionUF::resize(int **out, const int *in, const int size)
{
  if(size > 0)
  {
    remove(out);

    *out = new int[size];
    for(int i = 0; i < size; ++i)
      (*out)[i] = in[i];
  }
}

void WeightedQuickUnionUF::remove(int **ptr)
{
  if(*ptr != NULL)
  {
    delete *ptr;
    *ptr = NULL;
  }
}

/// chase parent pointer untill reach root
int WeightedQuickUnionUF::root(const int &val) const
{
  int pos = val;

  while(id[pos] != pos)
  {
    pos = id[pos];
    // id[pos] = id[id[pos]];
  }

  return pos;
}

/// pair of numbers will be connected if and only if,
/// both have in same root (parent).
bool WeightedQuickUnionUF::Connected(int begin, int end) const
{
  return( root(begin) == root(end) );
}

/// change root of small weighted tree by root of big weighted tree.
/// example: union(6, 1)
/// if root(6) = 8
///    root(1) = 2
///
/// then (if sz[8] < sz[2])
///     id[8] = 2
/// else
///     id[2] = 8
/// And increase sz accordingly.
void WeightedQuickUnionUF::Union(int begin, int end)
{
  int broot = root(begin);
  int eroot = root(end);

  if(sz[broot] < sz[eroot])
  {
    id[broot] = eroot;
    sz[eroot] += sz[broot];
  }
  else
  {
    id[eroot] = broot;
    sz[broot] +=sz[eroot];
  }
}
