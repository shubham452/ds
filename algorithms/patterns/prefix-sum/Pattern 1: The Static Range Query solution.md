Below is a **clean, interview-ready arrangement** of your notes for **Pattern 1: Static Range Query (Read-Only)**.
I’ve **organized, standardized terminology, removed redundancy**, and aligned all examples to **one mental template** so this becomes easy to recall and apply.

---

# 📌 Pattern 1: Static Range Query (Read-Only)

## 🎯 Goal

You are given an array that **does not change**, and you must answer **multiple range queries** efficiently.

Typical operations:

* Range **Sum**
* Range **XOR**
* Count / Frequency in range

---

## 🧠 Key Idea: Prefix Accumulation

Instead of recomputing range values repeatedly, **precompute cumulative information once**, then answer each query in **O(1)**.

---

## ⏱ Complexity

| Phase        | Time         |
| ------------ | ------------ |
| Build Prefix | **O(n)**     |
| Each Query   | **O(1)**     |
| Total        | **O(n + q)** |

---

## 🔹 Main Template: Prefix Sum (Most Important)

### 📌 Use Case

> “Calculate sum of elements between indices **L and R**.”

### 🧩 Logic

```
Sum(L, R) = prefix[R + 1] - prefix[L]
```

### 🧪 Template

```cpp
vector<long long> prefix(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}

// Query
long long sum = prefix[right + 1] - prefix[left];
```

📌 `prefix[i]` stores sum of elements from `0 → i-1`

---

## 🔸 Sub-Pattern 1.A: XOR Prefix Sum

### 📌 Use Case

> “Find XOR of elements in range [L, R].”

### 🧠 Why It Works

```
x ^ x = 0
x ^ 0 = x
```

XOR behaves like addition with cancellation (similar to subtraction in sums).

### 🧩 Logic

```
XOR(L, R) = prefixXor[R + 1] ^ prefixXor[L]
```

### 🧪 Template

```cpp
vector<int> prefixXor(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefixXor[i + 1] = prefixXor[i] ^ nums[i];
}

int ans = prefixXor[R + 1] ^ prefixXor[L];
```

---

# ✅ LeetCode Problems Using This Pattern

---

## 🟢 303. Range Sum Query – Immutable

### 🧠 Pattern

Classic **Static Range Sum Query**

### 💡 Approach

* Build prefix sum once in constructor
* Answer queries in O(1)

### ✅ Code

```cpp
class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        prefix.push_back(0);
        for (int x : nums) {
            prefix.push_back(prefix.back() + x);
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
```

---

## 🟢 2559. Count Vowel Strings in Ranges

### 🧠 Pattern

Prefix **count** array (same idea as prefix sum)

### 💡 Approach

1. Convert problem to **0/1 array**
2. Build prefix count
3. Answer range queries

### ✅ Code

```cpp
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        for (int i = 0; i < n; i++) {
            int k = words[i].size();
            prefix[i + 1] = prefix[i] +
                (isVowel(words[i][0]) && isVowel(words[i][k - 1]));
        }

        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        return ans;
    }
};
```

📌 This is **prefix sum on boolean values**

---

## 🟢 2574. Left and Right Sum Differences

### 🧠 Pattern

Prefix sum for **left**, suffix sum for **right**

### 💡 Observation

```
LeftSum[i]  = sum of elements before i
RightSum[i] = sum of elements after i
```

### ✅ Code

```cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int left = prefix[i];
            int right = prefix[n] - prefix[i + 1];
            ans[i] = abs(left - right);
        }
        return ans;
    }
};
```

📌 Optimized to **single prefix array**

---

# 🧠 When to Instantly Think “Prefix Sum”

If the problem says:

* “Range sum / count / XOR”
* “Multiple queries”
* “Array is immutable”
* “Left / right accumulation”

➡ **Pattern 1: Static Range Query**

---

# 🏁 One-Line Interview Summary

> “Since the array is read-only and we have multiple range queries, I precompute a prefix array so each query can be answered in O(1).”

---

If you want next:

* 🔹 **Pattern 2: Difference Array (Range Updates)**
* 🔹 **2D Prefix Sum**
* 🔹 **Prefix + HashMap**
* 🔹 **Sliding Window vs Prefix Sum**

Just say the word 👍
