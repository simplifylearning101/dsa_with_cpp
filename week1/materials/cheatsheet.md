# C++ STL Containers Cheat Sheet (Hours 1–11)

This cheat sheet covers STL containers from Hours 1–11: vectors, arrays/deques, strings, stacks, queues, priority queues, sets, maps, multisets, multimaps, unordered sets, unordered maps, and unordered multimaps. Each section includes declarations, key operations, time complexities, and examples for coding interview preparation.

## Hour 1: Vector
**Header**: `<vector>`  
**Description**: Dynamic array with contiguous storage, resizable.  
**Real-World Analogy**: Shopping list that grows/shrinks.  
**Declaration**: `vector<T> v;`  
**Key Operations**:  
- `push_back(x)`: O(1) amortized – Add element to end.  
- `pop_back()`: O(1) – Remove last element.  
- `v[i]`: O(1) – Random access.  
- `size()`: O(1) – Number of elements.  
- `empty()`: O(1) – Check if empty.  
- `clear()`: O(n) – Remove all elements.  
**Example**:
```cpp
#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);  // v = [1, 2, 3, 4]
    cout << v[0] << endl;  // Output: 1
    cout << "Size: " << v.size() << endl;  // Output: 4
}
```

## Hour 2: Array and Deque
**Header**: `<array>`, `<deque>`  
**Description**:  
- `array`: Fixed-size array, stack-allocated.  
- `deque`: Double-ended queue, supports fast insertions at both ends.  
**Real-World Analogy**: Array as a fixed-size bookshelf; deque as a conveyor belt.  
**Declarations**:  
- `array<T, N> arr;`  
- `deque<T> dq;`  
**Key Operations**:  
- Array: `arr[i]`: O(1) – Random access; `size()`: O(1).  
- Deque: `push_back(x)`, `push_front(x)`: O(1); `pop_back()`, `pop_front()`: O(1); `dq[i]`: O(1).  
**Example**:
```cpp
#include <array>
#include <deque>
#include <iostream>
using namespace std;
int main() {
    array<int, 3> arr = {1, 2, 3};  // Fixed size
    deque<int> dq = {2, 3};
    dq.push_front(1);  // dq = [1, 2, 3]
    cout << arr[0] << " " << dq[0] << endl;  // Output: 1 1
}
```

## Hour 3: String
**Header**: `<string>`  
**Description**: Dynamic sequence of characters.  
**Real-World Analogy**: Editable text message.  
**Declaration**: `string s;`  
**Key Operations**:  
- `s += c`: O(1) amortized – Append character.  
- `s.substr(pos, len)`: O(n) – Extract substring.  
- `s.find(str)`: O(n*m) – Find substring.  
- `size()`: O(1) – Length.  
**Example**:
```cpp
#include <string>
#include <iostream>
using namespace std;
int main() {
    string s = "hello";
    s += " world";  // s = "hello world"
    cout << s.substr(0, 5) << endl;  // Output: hello
    cout << (s.find("world") != string::npos ? "Found" : "Not found") << endl;  // Output: Found
}
```

## Hour 4: Stack
**Header**: `<stack>`  
**Description**: LIFO (Last-In, First-Out) container.  
**Real-World Analogy**: Stack of plates.  
**Declaration**: `stack<T> st;`  
**Key Operations**:  
- `push(x)`: O(1) – Add to top.  
- `pop()`: O(1) – Remove top.  
- `top()`: O(1) – Access top.  
- `empty()`: O(1) – Check if empty.  
- `size()`: O(1) – Number of elements.  
**Example**:
```cpp
#include <stack>
#include <iostream>
using namespace std;
int main() {
    stack<int> st;
    st.push(1); st.push(2);  // Stack: [2, 1]
    cout << st.top() << endl;  // Output: 2
    st.pop();  // Stack: [1]
    cout << "Size: " << st.size() << endl;  // Output: 1
}
```

## Hour 5: Queue
**Header**: `<queue>`  
**Description**: FIFO (First-In, First-Out) container.  
**Real-World Analogy**: Line at a ticket counter.  
**Declaration**: `queue<T> q;`  
**Key Operations**:  
- `push(x)`: O(1) – Add to back.  
- `pop()`: O(1) – Remove front.  
- `front()`: O(1) – Access front.  
- `back()`: O(1) – Access back.  
- `empty()`: O(1); `size()`: O(1).  
**Example**:
```cpp
#include <queue>
#include <iostream>
using namespace std;
int main() {
    queue<int> q;
    q.push(1); q.push(2);  // Queue: [1, 2]
    cout << q.front() << endl;  // Output: 1
    q.pop();  // Queue: [2]
    cout << "Size: " << q.size() << endl;  // Output: 1
}
```

## Hour 6: Priority Queue
**Header**: `<queue>`  
**Description**: Heap-based container, elements ordered by priority.  
**Real-World Analogy**: Emergency room priority list.  
**Declaration**: `priority_queue<T> pq;` (max-heap default)  
**Key Operations**:  
- `push(x)`: O(log n) – Add element.  
- `pop()`: O(log n) – Remove top.  
- `top()`: O(1) – Access top.  
- `empty()`: O(1); `size()`: O(1).  
**Example**:
```cpp
#include <queue>
#include <iostream>
using namespace std;
int main() {
    priority_queue<int> pq;  // Max heap
    pq.push(3); pq.push(1); pq.push(2);  // Heap: [3, 2, 1]
    cout << pq.top() << endl;  // Output: 3
    pq.pop();  // Heap: [2, 1]
    cout << "Size: " << pq.size() << endl;  // Output: 2
}
```

## Hour 7: Set
**Header**: `<set>`  
**Description**: Sorted container of unique elements (red-black tree).  
**Real-World Analogy**: Sorted guest list with no duplicates.  
**Declaration**: `set<T> s;`  
**Key Operations**:  
- `insert(x)`: O(log n) – Add element.  
- `erase(x)`: O(log n) – Remove element.  
- `find(x)`: O(log n) – Check if element exists.  
- `count(x)`: O(log n) – Returns 0 or 1.  
- `empty()`: O(1); `size()`: O(1).  
**Example**:
```cpp
#include <set>
#include <iostream>
using namespace std;
int main() {
    set<int> s;
    s.insert(2); s.insert(1); s.insert(2);  // Set: [1, 2]
    cout << (s.find(1) != s.end() ? "Found" : "Not found") << endl;  // Output: Found
    cout << "Size: " << s.size() << endl;  // Output: 2
}
```

## Hour 8: Map
**Header**: `<map>`  
**Description**: Sorted key-value pairs, unique keys (red-black tree).  
**Real-World Analogy**: Dictionary with sorted words.  
**Declaration**: `map<Key, T> m;`  
**Key Operations**:  
- `m[key] = value`: O(log n) – Insert/update.  
- `erase(key)`: O(log n) – Remove key.  
- `find(key)`: O(log n) – Check if key exists.  
- `count(key)`: O(log n) – Returns 0 or 1.  
- `empty()`: O(1); `size()`: O(1).  
**Example**:
```cpp
#include <map>
#include <iostream>
using namespace std;
int main() {
    map<string, int> m;
    m["apple"] = 5; m["banana"] = 3;  // Map: [apple:5, banana:3]
    cout << m["apple"] << endl;  // Output: 5
    cout << "Size: " << m.size() << endl;  // Output: 2
}
```

## Hour 9: Multiset and Multimap
**Header**: `<set>`, `<map>`  
**Description**:  
- `multiset`: Sorted container, allows duplicate elements.  
- `multimap`: Sorted key-value pairs, allows duplicate keys.  
**Real-World Analogy**: Multiset as a guest list with duplicates; multimap as a reverse index.  
**Declarations**:  
- `multiset<T> ms;`  
- `multimap<Key, T> mm;`  
**Key Operations**:  
- Multiset: `insert(x)`: O(log n); `erase(x)`: O(log n); `count(x)`: O(log n).  
- Multimap: `insert({key, value})`: O(log n); `equal_range(key)`: O(log n); `count(key)`: O(log n).  
**Example**:
```cpp
#include <set>
#include <map>
#include <iostream>
using namespace std;
int main() {
    multiset<int> ms;
    ms.insert(1); ms.insert(1);  // Multiset: [1, 1]
    cout << "Count of 1: " << ms.count(1) << endl;  // Output: 2
    
    multimap<string, int> mm;
    mm.insert({"apple", 1}); mm.insert({"apple", 2});  // Multimap: [apple:1, apple:2]
    cout << "Count of apple: " << mm.count("apple") << endl;  // Output: 2
}
```

## Hour 10: Unordered Set and Unordered Multiset
**Header**: `<unordered_set>`  
**Description**:  
- `unordered_set`: Hash-based, unique elements.  
- `unordered_multiset`: Hash-based, allows duplicates.  
**Real-World Analogy**: Unordered set as a unique guest list; unordered multiset as a bag of items.  
**Declarations**:  
- `unordered_set<T> us;`  
- `unordered_multiset<T> ums;`  
**Key Operations**:  
- `insert(x)`: O(1) average – Add element.  
- `erase(x)`: O(1) average – Remove element.  
- `find(x)`: O(1) average – Check if exists.  
- `count(x)`: O(1) average – Count occurrences.  
**Example**:
```cpp
#include <unordered_set>
#include <iostream>
using namespace std;
int main() {
    unordered_set<int> us;
    us.insert(2); us.insert(1); us.insert(2);  // Unordered set: [2, 1]
    cout << (us.find(1) != us.end() ? "Found" : "Not found") << endl;  // Output: Found
    
    unordered_multiset<int> ums;
    ums.insert(1); ums.insert(1);  // Unordered multiset: [1, 1]
    cout << "Count of 1: " << ums.count(1) << endl;  // Output: 2
}
```

## Hour 11: Unordered Map and Unordered Multimap
**Header**: `<unordered_map>`  
**Description**:  
- `unordered_map`: Hash-based, unique key-value pairs.  
- `unordered_multimap`: Hash-based, allows duplicate keys.  
**Real-World Analogy**: Unordered map as a dictionary; unordered multimap as a reverse index.  
**Declarations**:  
- `unordered_map<Key, T> um;`  
- `unordered_multimap<Key, T> umm;`  
**Key Operations**:  
- Unordered Map: `um[key] = value`: O(1) average; `erase(key)`: O(1) average; `find(key)`: O(1) average.  
- Unordered Multimap: `insert({key, value})`: O(1) average; `equal_range(key)`: O(1) average; `count(key)`: O(1) average.  
**Example**:
```cpp
#include <unordered_map>
#include <iostream>
using namespace std;
int main() {
    unordered_map<string, int> um;
    um["apple"] = 5; um["banana"] = 3;  // Unordered map: [banana:3, apple:5]
    cout << um["apple"] << endl;  // Output: 5
    
    unordered_multimap<string, int> umm;
    umm.insert({"apple", 1}); umm.insert({"apple", 2});  // Unordered multimap: [apple:1, apple:2]
    cout << "Count of apple: " << umm.count("apple") << endl;  // Output: 2
}
```

## Key Comparisons
| Container | Ordered? | Duplicates? | Time Complexity | Use Case |
|-----------|----------|-------------|-----------------|----------|
| Vector    | No       | Yes         | O(1) access     | Dynamic arrays |
| Array     | No       | Yes         | O(1) access     | Fixed-size arrays |
| Deque     | No       | Yes         | O(1) ends       | Double-ended operations |
| String    | Yes      | Yes         | O(n) substr     | Text processing |
| Stack     | LIFO     | Yes         | O(1) push/pop   | LIFO operations |
| Queue     | FIFO     | Yes         | O(1) push/pop   | FIFO operations |
| Priority Queue | Heap | Yes     | O(log n) push   | Priority-based |
| Set       | Yes      | No          | O(log n) ops    | Unique, sorted |
| Map       | Yes      | No (keys)   | O(log n) ops    | Sorted key-value |
| Multiset  | Yes      | Yes         | O(log n) ops    | Sorted duplicates |
| Multimap  | Yes      | Yes (keys)  | O(log n) ops    | Sorted key-value duplicates |
| Unordered Set | No   | No          | O(1) avg ops    | Fast unique elements |
| Unordered Map | No   | No (keys)   | O(1) avg ops    | Fast key-value |
| Unordered Multiset | No | Yes     | O(1) avg ops    | Fast duplicates |
| Unordered Multimap | No | Yes (keys) | O(1) avg ops | Fast key-value duplicates |

## Interview Tips
- **Vector**: Use for dynamic arrays, random access.  
- **Array/Deque**: Use array for fixed size; deque for fast ends.  
- **String**: Use for text manipulation, substring operations.  
- **Stack/Queue**: Use for LIFO/FIFO problems (e.g., parentheses, BFS).  
- **Priority Queue**: Use for top-k or scheduling problems.  
- **Set/Map**: Use for sorted, unique elements or key-value pairs.  
- **Multiset/Multimap**: Use for sorted duplicates.  
- **Unordered Set/Map**: Use for O(1) average lookups.  
- **Unordered Multiset/Multimap**: Use for duplicates with fast lookups.  
- **Common Errors**:  
  - Check `find` results against `end()`.  
  - Avoid `operator[]` in `unordered_map` for read-only (it inserts).  
  - Ensure keys are hashable for unordered containers.  

## LeetCode Problems
- **Vector**: Two Sum (LeetCode 1) – O(n) with unordered map.  
- **String**: Longest Substring Without Repeating Characters (LeetCode 3).  
- **Stack**: Valid Parentheses (LeetCode 20).  
- **Queue**: Design Circular Queue (LeetCode 622).  
- **Priority Queue**: Kth Largest Element (LeetCode 215).  
- **Set**: Intersection of Two Arrays (LeetCode 349).  
- **Map**: Two Sum (LeetCode 1).  
- **Multiset/Multimap**: Top K Frequent Elements (LeetCode 347).  
- **Unordered Set**: Single Number (LeetCode 136).  
- **Unordered Map**: Two Sum (LeetCode 1), LRU Cache (LeetCode 146), Isomorphic Strings (LeetCode 205).  
- **Unordered Multimap**: Group Anagrams (LeetCode 49).