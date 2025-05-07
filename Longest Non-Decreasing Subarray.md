# Problem: Longest Non-Decreasing Subarray

## Problem Statement

Given an array of integers `A`, find the length of the longest contiguous sub-array in which the elements are in **non-decreasing order**.

### Input

* First line contains an integer `N` — the size of array `A`.
* Second line contains `N` space-separated integers — the elements of array `A`.

### Output

* Print a single integer — the length of the longest sub-array whose elements are in non-decreasing order.

### Constraints

* $1 \leq N \leq 100000$
* $0 \leq A[i] \leq 1000000$

## Explanation

### Understanding the Problem

You are given an array of size `N`. You need to determine the length of the longest contiguous sub-array where each element is **greater than or equal to** the previous one.

This means you're looking for the longest sub-array such that:

```
A[i] <= A[i+1] <= A[i+2] ...
```

### Sample Input

```
4
9 1 2 2
```

### Sample Output

```
3
```

### Reasoning

In the array `[9, 1, 2, 2]`, the longest non-decreasing sub-array is `[1, 2, 2]`, which has a length of `3`.

## Efficient Approach

### Idea

* Iterate through the array while keeping track of the current length of the non-decreasing sub-array.
* Reset the current length when the sequence breaks (i.e., when a smaller element follows a larger one).
* Track the maximum length found during the process.

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int longestNonDecreasingSubarray(vector<int>& arr) {
    int maxLength = 1, currentLength = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] >= arr[i - 1]) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    return max(maxLength, currentLength);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << longestNonDecreasingSubarray(arr) << endl;
    return 0;
}
```

## Complexity Analysis

* **Time Complexity:** $O(N)$ — single pass through the array.
* **Space Complexity:** $O(1)$ — uses only a few integer variables.
