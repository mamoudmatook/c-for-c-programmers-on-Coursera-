#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

// Increments p with the sum of (at most) the first n elements of d.
void sum(int &p, int n, vector<int> &d) { 
  for(int i = 0; (i < d.size()) && (i < n); i++) p += d[i];
}

int main() {
  int accum = 0;
  vector<int> data;
  for(int i = 0; i < N; i++) data.push_back(i);
  sum(accum, N, data);
  cout << "sum is " << accum << endl;
  return 0;
}
