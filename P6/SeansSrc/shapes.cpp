// Author: Sean Davis 
// Created on May 15, 2015, 5:56 AM

#include <iostream>
using namespace std;

class Shape
{
  friend ostream& operator << (ostream & os, const Shape &shape);
  virtual void write(ostream &os) const = 0;
};  // class Shape


ostream& operator << (ostream & os, const Shape &shape)
{
  shape.write(os);
  return os;
} // operator<<


class IntersectingLines : public Shape
{
  void write(ostream &os) const;
};  // class IntersectingLines


void IntersectingLines::write(ostream &os) const
{
  os << "    /\\\n";
  os << "   /  \\\n";
  os << "  /    \\\n";
  os << " /      \\\n";
  os << "/        \\\n";
}  // write())


class BaseLine : public Shape
{
  void write(ostream &os) const;
};  // class BaseLine

void BaseLine::write(ostream &os) const
{
  os << "----------\n";
}  // write())

class ParallelLines : public Shape
{
  void write(ostream &os) const;
};  // class ParallelLines


void ParallelLines::write(ostream &os) const
{
  os << "|        |\n";
  os << "|        |\n";
  os << "|        |\n";
}  // write())


class BlankLines : public Shape
{
  void write(ostream &os) const;
};  // class BlankLines


void BlankLines::write(ostream &os) const
{
  os << "\n\n";
}  // write()


class Circle : public Shape
{
  void write(ostream &os) const;
}; // class Circle


void Circle::write(ostream &os) const
{
  os << "    *\n";
  os << "  *   *\n";
  os << "   * *\n";
}  // write()

int main(int argc, char** argv) 
{
  Shape *shapes[10];
  shapes[0] = new IntersectingLines();
  shapes[1] = new BaseLine();
  shapes[2] = new ParallelLines();
  shapes[3] = new BaseLine();
  shapes[4] =  new BlankLines();
  shapes[5] = new Circle();
  shapes[6] = new IntersectingLines();
  shapes[7] = new BaseLine();
  shapes[8] = new IntersectingLines();
  
  for (int i = 0; i < 9; i++)
    cout << *shapes[i];
  
  return 0;
} // main())

