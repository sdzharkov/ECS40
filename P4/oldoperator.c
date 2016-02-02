old operator

ostream& operator <<(ostream &os, const Plane &rhs)
{
  int leftRange = rhs.range / 1000;
  int rightRange = rhs.range % 1000;
  int leftFuel = rhs.fuel / 1000;
  int rightFuel = rhs.fuel % 1000;
  //os << setw(12) << left << rhs.name;
  os << left << setw(12) << rhs.name;
  os << setw(6) << rhs.passengers;
  /*
  if (rhs.range >= 1000)
  {
    os << rhs.range / 1000 << "," << setfill('0') << setw(3) 
         << right << rhs.range % 1000 << setfill(' ');
  }
  else
  {
    os << setw(5) << right << rhs.range;
  }
  */
  os << leftRange << "," << setfill('0') << setw(3) << right << rightRange << setfill(' ');
  //os << setw(4) << right << rhs.speed;
  os << setw(4) << right << rhs.speed;
  /*
  if (rhs.fuel >= 1000)
  {
    os << setw(5) << rhs.fuel / 1000 << ',' << setfill('0') << setw(3) 
         << rhs.fuel % 1000 << setfill(' ');
  }
  else
  {
    os << setw(10) << rhs.fuel;
   

  }*/  
  
  os << setw(5) << leftFuel << ',' << setfill('0') << setw(3) << right << rightFuel << setfill(' ');
 
