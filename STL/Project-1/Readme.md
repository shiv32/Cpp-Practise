
Covered (actual useful subset)

Containers (practical ones)
    vector          → default choice
    deque           → double-ended
    list            → rare but shows non-random iterator
    set / map       → ordered
    unordered_map   → hash-based
    stack, queue    → adapters

Iterators (core types)
    begin() / end()     → forward
    rbegin() / rend()   → reverse
    auto                → you almost never write raw iterator types

Algorithms you’ll use daily
    Searching       → find, binary_search
    Sorting         → sort
    Counting        → count
    Transform       → transform
    Removal         → remove + erase
    Aggregation     → accumulate
    Min/Max         → min_element, max_element
    Iteration       → for_each, copy

Straight truth (important for you as C++ dev)
    You don’t need “all STL”.
    If you deeply understand just:

        vector + sort + find + transform + accumulate

    you’re already ahead of most developers.