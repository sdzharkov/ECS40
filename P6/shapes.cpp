#include <iostream>
#include <cstring>
#include <climits>
#include <iomanip>
#include <cctype>
#include <cstdlib>

using namespace std;


class Shape
{
public:
  friend ostream& operator << (ostream& output, const Shape &rhs);
  virtual void write(ostream& output) const = 0;
}; //


class IntersectingLines: public Shape
{
public:
  void write(ostream& output) const
  { 
  cout << "    /\\\n   /  \\\n  /    \\\n /      \\\n/        \\\n";
  }  //
}; // 


class ParallelLines: public Shape
{
public:
    void write(ostream& output) const
    {
    
        cout << "|        |\n|        |\n|        |\n";
    } //
}; // 


class BaseLine: public Shape
{
public:
  void write(ostream& output) const
  {
    cout << "----------" << endl;
  } //
}; //


class BlankLines: public Shape
{
public:
  void write(ostream& output) const
  {
    cout << "\n\n";
  } //
}; //


class Circle: public Shape
{
public:
  void write(ostream& output) const
  {
     cout << "    *\n  *   *\n   * *\n";
  } //
}; //


ostream& operator << (ostream& output, const Shape &rhs)
{

  rhs.write(output);
  return output;
} //

int main()
{
  Shape *shapes[9];
  shapes[0] = new IntersectingLines;
  shapes[1] = new BaseLine;
  shapes[2] = new ParallelLines;
  shapes[3] = new BaseLine;
  shapes[4] = new BlankLines;
  shapes[5] = new Circle;
  shapes[6] = new IntersectingLines;
  shapes[7] = new BaseLine;
  shapes[8] = new IntersectingLines;
    
  for (int i = 0; i < 9; ++i)
    cout << *shapes[i];
    
  return 0;
} //
