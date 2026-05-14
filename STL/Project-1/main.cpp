#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    // ===== SEQUENCE CONTAINERS =====
    vector<int> v = {4, 1, 3, 2, 5};
    deque<int> dq = {10, 20, 30};
    list<int> lst = {7, 3, 9, 1};

    // ===== ASSOCIATIVE CONTAINERS =====
    set<int> s = {3, 1, 4, 1}; // unique + sorted
    map<string, int> m = {{"a", 1}, {"b", 2}};

    // ===== UNORDERED =====
    unordered_map<string, int> um = {{"x", 10}, {"y", 20}};

    // ===== ADAPTERS =====
    stack<int> st;
    st.push(1);
    st.push(2);
    
    queue<int> q;
    q.push(10);
    q.push(20);

    cout << "Stack top: " << st.top() << endl;
    cout << "Queue front: " << q.front() << endl;

    // ===== ITERATORS =====
    cout << "\nVector (iterator): ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << "\nVector (reverse): ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";

    // ===== COMMON ALGORITHMS =====

    // sort
    sort(v.begin(), v.end());

    // find
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end())
        cout << "\nFound 3";

    // count
    cout << "\nCount of 3: " << count(v.begin(), v.end(), 3);

    // binary_search (needs sorted)
    cout << "\nBinary search 4: "
         << binary_search(v.begin(), v.end(), 4);

    // transform
    transform(v.begin(), v.end(), v.begin(), [](int x)
              { return x * 2; });

    // remove (erase-remove)
    v.erase(remove(v.begin(), v.end(), 4), v.end());

    // accumulate
    int sum = accumulate(v.begin(), v.end(), 0);

    // min/max
    cout << "\nMin: " << *min_element(v.begin(), v.end());
    cout << "\nMax: " << *max_element(v.begin(), v.end());

    // for_each
    cout << "\nVector: ";
    for_each(v.begin(), v.end(), [](int x)
             { cout << x << " "; });

    cout << "\nSum: " << sum << "\n";

    // ===== MAP ITERATION =====
    cout << "\nMap:\n";
    for (const auto &[k, val] : m)
        cout << k << " -> " << val << endl;

    // ===== SET =====
    cout << "\nSet: ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));

    cout << "\n";

    return 0;
}