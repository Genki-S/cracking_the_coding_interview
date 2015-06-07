#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename T>
class ParallelStack {
  int parallelism;
  vector<T> v;
  vector<int> last_indices;
  public:
    ParallelStack(int n) : parallelism(n) {
      last_indices = vector<int>(parallelism);
      for (int i = 0; i < parallelism; ++i) {
        last_indices[i] = i;
      }
    }

    void push(int n, T val) {
      // cout << "push(" << n << ", " << val << ")" << endl;
      int i = last_indices[n];
      // cout << "i = " << i << endl;
      if (i >= v.size()) {
        v.resize(i + 1);
      }
      v[i] = val;
      last_indices[n] += parallelism;
    }

    T pop(int n) {
      // cout << "pop(" << n << ")" << endl;
      last_indices[n] -= parallelism;
      int i = last_indices[n];
      // cout << "i = " << i << endl;
      if (i < 0) {
        throw;
      }
      return v[i];
    }

    void print_vector() {
      for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
      }
      cout << endl;
    }
};

int main()
{
  ParallelStack<int> ps(3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ps.push(i, j);
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      assert(ps.pop(i) == 4 - j);
    }
  }
}
