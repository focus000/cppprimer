# 未解决问题集

- 对于迭代器vt，为啥++vt++不报错

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> vi{1, 2, 3};
    auto vp = vi.begin(), ve = vi.end();
    auto vt = vp;
    ++vt++;
    cout << *vp << " "
         << *(vp + 1) << " "
         << *(vp + 2) << " "
         << *vt << endl;
    return 0;
}
```

输出为：1 2 3 2
