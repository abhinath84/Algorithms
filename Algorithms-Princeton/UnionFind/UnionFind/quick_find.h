#include <iostream>

/* 
  Quick-find [eager approach] 
*/

/*    |------------|------------|------ |------|
      | algorithm  | initialize | union | find |
      |------------|------------|------ |------|
      |     UF     |     N      |   N   |   1  |
      |------------|------------|------ |------|

      Quick-find defect. Union too expensive.

      Ex. Takes N^2 (quadratic) array accesses to process sequence of N union commands
          on N objects.
*/

class UF
{
  public:
    UF();
    UF(const int &n);
    UF(const UF &others);
    ~UF();

    bool Connected(int begin, int end) const;
    void Union(int begin, int end);

  private:
    void init();

  private:
    int *id;
    int size;
};



/* 
  Quick-union [lazy approach] 
*/

/*    |----------------|------------|------ |------|
      |    algorithm   | initialize | union | find |
      |----------------|------------|------ |------|
      |  QuickUnionUF  |     N      |   N   |   N  |
      |----------------|------------|------ |------|

      Quick-union defect.
        - Trees can get tall.
        - Find too expensive (could be N array accesses).
*/
class QuickUnionUF
{
  public:
    QuickUnionUF();
    QuickUnionUF(const int &n);
    QuickUnionUF(const QuickUnionUF &others);
    ~QuickUnionUF();

    bool Connected(int begin, int end) const;
    void Union(int begin, int end);

  private:
    void init();
    int  root(const int &val) const;

  private:
    int *id;
    int size;
};
