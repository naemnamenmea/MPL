# MPL

Connect the auxiliary header file...

```c++
...
#include "mplAux.h"
...
int main() {
    ...
}

```

## Quick Sort

```c++
...
#include "mplQuickSort.h"
...
template <class T>
using Comparator = std::function<bool(const T&, const T&)>;
...

QuickSort<T>(std::vector v);
QuickSort<T>(std::vector v, Comparator<T> comp);
QuickSort<T>(std::vector v, int from, int to);
QuickSort<T>(std::vector v, int from, int to, Comparator<T> comp);

...
```

### Usage example:

```c++

std::vector<int> v{ 15,1,9,0,-4,5 };

QuickSort<int>(v);
//QuickSort<int>(v, [](const int& a, const int& b) {return a > b;});
//QuickSort<int>(v, 0, v.size() - 1, [](const int& a, const int& b) {return a < b;});
for (auto i : v) std::cout << i << ' '; std::cout << std::endl;
std::cout << std::endl;

```

## Spiral Matrix

```c++
...
#include "mplSpiralMatrix.h"
...

std::vector<std::vector<T>> mtrx = getSpiralMatrx(int n, int m);

std::tuple<int, int, bool> ij = getPosCoord(int n, int m, int pos);

```

### Usage example:

```c++

int n = 6;
int m = 5;
auto mtrx = getSpiralMatrx(n, m);
printSpiralMatrx(mtrx);

int pos = 27;
auto ij = getPosCoord(n, m, pos);
std::cout << "pos = " << pos << ". (i,j) = (" << std::get<0>(ij) << "," << std::get<1>(ij) << ")." << std::endl;

```
