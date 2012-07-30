#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v;
  cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

  v.resize(1000);
  cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

  v.resize(1);
  cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

  v.clear();
  cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

  v.reserve(1);
  cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
}
