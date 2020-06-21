#include <iostream>

using namespace std; 
 
int main() {

  int a, b, x, y, t, gcd, lcm;
 
  cout << "Enter two integers\n";
  cin >> &x; 
  cin >> &y; 
 
  a = x;
  b = y;
 
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
 
  gcd = a;
  lcm = (x*y)/gcd;
 
  cout << "Greatest common divisor of " << x << " and " << y << " = " << gcd << "\n" << endl; 
  cout << "Least common multiple of " << x << " and " << y << " = " << lcm << "\n" << endl;
 
  return 0;
}