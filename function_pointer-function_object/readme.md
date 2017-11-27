## 1. function pointer

In CS240 CA4, I need two ways to compare the strings, and the other operations are totally the same. I don't want to naively copy and paste the code, so I use function pointers here.<br>
The function that accept function pointer as an argument looks like:

```cpp

void Dish::moveUp(int curindex, const int type, vector<int> &v, bool (*cmp_le)(const string &, const string &)) {
    int parentindex;
    parentindex = curindex / 2;
    while (parentindex >= 1 && cmp_le(stringArray[v[curindex]].data, stringArray[v[parentindex]].data)) {
        if (type == ALPHA) {
            swapAll(alphaIndex, ALPHA, curindex, parentindex);
        } else if (type == LENGTH) {
            swapAll(lengthIndex, LENGTH, curindex, parentindex);
        }
        curindex = parentindex;
        parentindex = parentindex / 2;
    }
}

```

The two compare functions (one is the alphabetical and the other is length)

```cpp

bool Dish::cmp_Length_le(const string &a, const string &b) {
    return (a.length() <= b.length());
}

bool Dish::cmp_Alpha_le(const string &a, const string &b) {
    return a <= b;
}

```

When a new string is inserted, I can just call the moveUP functions twice with different compare function.<br>

```cpp

int Dish::insert(string s) {
    Triple tempTriple(s, (int) alphaIndex.size(), (int) lengthIndex.size());
    int isPlacedAt;
    stringArray.push_back(tempTriple);
    alphaIndex.push_back((int) stringArray.size() - 1);
    lengthIndex.push_back((int) stringArray.size() - 1);
    moveUp((int) alphaIndex.size() - 1, ALPHA, alphaIndex, cmp_Alpha_le);
    moveUp((int) lengthIndex.size() - 1, LENGTH, lengthIndex, cmp_Length_le);
    return (int) stringArray.size() - 1;
}

```

## 2. function object

While function pointer is very useful, function object is even stronger, it can accept arguments in the constructors so you can write all your comparsion functions in one class, and do not need to write so much conparsion functions. For example, when we build a heap, which in C++ STL, is priority_queue, we want both max heap and min heap. We can write a function object:

```cpp

class cmp {
  private:
    bool reverse;

  public:
    cmp(bool reverse) {
        this->reverse = reverse;
    }
    bool operator()(const int &a, const int &b) {
        if (reverse) {
            return (a > b);
        } else {
            return (a < b);
        }
    }
};

```

and when we use it:

```cpp

int main() {
    priority_queue<int, vector<int>, cmp> q1(false);
    priority_queue<int, vector<int>, cmp> q2(true);
    q1.push(10), q1.push(60), q1.push(50), q1.push(20);
    q2.push(10), q2.push(60), q2.push(50), q2.push(20);
    cout << "q1:" << endl;
    while (!q1.empty()) {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;
    cout << "q2:" << endl;
    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;
    return 0;
}

```

we get both max heap and min heap. Notice that we pass in a argument to the object(the "reverse"), so we do all the jobs in one class.
