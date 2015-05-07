// compile with g++ arrays.cpp -o arrays
#include <iostream>
using namespace std;

class Line{
public:
  int length;
  int* a;
  Line(int length): length(length) {
    a = new int[length];
  };
  int getFirst(){
    a[0] = 10;
    return a[0];
  };
};

int main( )
{
   Line line = Line(10);

   // set line length
   cout << "first element: " << line.getFirst() <<endl;

   return 0;
}
