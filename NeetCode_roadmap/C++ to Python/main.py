"""
=========================================================
PYTHON FOR COMPETITIVE PROGRAMMING
(C++ Equivalents Included as Comments)
=========================================================

"""

# =========================================================
# IMPORTS USED IN CP
# =========================================================

import sys
from collections import deque, defaultdict, Counter
import heapq

input = sys.stdin.readline

# =========================================================
# VECTOR -> LIST
# =========================================================

# C++
#
# vector<int> arr;
# arr.push_back(5);
# arr.push_back(10);
# cout << arr[0];

arr = []

arr.append(5)
arr.append(10)

print("List:", arr)
print("First Element:", arr[0])

# =========================================================
# 2D VECTOR -> LIST OF LISTS
# =========================================================

# C++
#
# vector<vector<int>> result;
# vector<int> level;
#
# level.push_back(1);
# level.push_back(2);
#
# result.push_back(level);

result = []
level = [1, 2]

result.append(level)

print("2D List:", result)

# =========================================================
# LOOPS
# =========================================================

# C++
#
# for(int i=0;i<n;i++)
# {
# }

n = 5

for i in range(n):
    print("Index:", i)

# ---------------------------------------------------------

# C++
#
# for(auto x : arr)
# {
#     cout << x;
# }

for x in arr:
    print("Value:", x)

# =========================================================
# STACK
# =========================================================

# C++
#
# stack<int> st;
#
# st.push(10);
# st.push(20);
#
# cout << st.top();
#
# st.pop();

stack = []

stack.append(10)
stack.append(20)

print("Stack Top:", stack[-1])

stack.pop()

print("After Pop:", stack)

# =========================================================
# QUEUE
# =========================================================

# C++
#
# queue<int> q;
#
# q.push(10);
# q.push(20);
#
# cout << q.front();
#
# q.pop();

q = deque()

q.append(10)
q.append(20)

print("Queue Front:", q[0])

q.popleft()

print("Queue:", list(q))

# =========================================================
# HASHMAP -> DICTIONARY
# =========================================================

# C++
#
# unordered_map<int,int> mp;
#
# mp[5] = 100;
# mp[10] = 200;

mp = {}

mp[5] = 100
mp[10] = 200

print("Dictionary:", mp)

# =========================================================
# SET
# =========================================================

# C++
#
# unordered_set<int> st;
#
# st.insert(5);
# st.insert(10);

st = set()

st.add(5)
st.add(10)

print("Set:", st)

# =========================================================
# SORTING
# =========================================================

# C++
#
# sort(arr.begin(), arr.end());

arr = [5, 1, 9, 3, 2]

arr.sort()

print("Sorted:", arr)

# ---------------------------------------------------------

# C++
#
# sort(arr.begin(), arr.end(), greater<int>());

arr.sort(reverse=True)

print("Reverse Sorted:", arr)

# =========================================================
# PRIORITY QUEUE (MIN HEAP)
# =========================================================

# C++
#
# priority_queue<int, vector<int>, greater<int>> pq;

pq = []

heapq.heappush(pq, 10)
heapq.heappush(pq, 3)
heapq.heappush(pq, 7)

print("Min Heap:", pq)

smallest = heapq.heappop(pq)

print("Popped:", smallest)

# =========================================================
# MAX HEAP
# =========================================================

# C++
#
# priority_queue<int> pq;

pq = []

heapq.heappush(pq, -10)
heapq.heappush(pq, -3)
heapq.heappush(pq, -7)

largest = -heapq.heappop(pq)

print("Largest:", largest)

# =========================================================
# FAST INPUT ARRAY
# =========================================================

# C++
#
# int n;
# cin >> n;
#
# vector<int> arr(n);
#
# for(int i=0;i<n;i++)
# {
#     cin >> arr[i];
# }

# Python
#
# n = int(input())
# arr = list(map(int, input().split()))

# Example:
#
# Input:
# 5
# 1 2 3 4 5

# =========================================================
# LIST COMPREHENSION
# =========================================================

# C++
#
# vector<int> arr;
#
# for(int i=0;i<10;i++)
# {
#     arr.push_back(i);
# }

arr = [i for i in range(10)]

print("List Comprehension:", arr)

# =========================================================
# COMMON BUILT-IN FUNCTIONS
# =========================================================

arr = [1, 2, 3, 4, 5]

print("Sum:", sum(arr))
print("Max:", max(arr))
print("Min:", min(arr))
print("Length:", len(arr))

# =========================================================
# COUNTER
# =========================================================

# C++
#
# unordered_map<int,int> freq;
#
# for(auto x : arr)
# {
#     freq[x]++;
# }

arr = [1, 1, 2, 2, 2, 3]

freq = Counter(arr)

print("Counter:", freq)

# =========================================================
# DEFAULTDICT
# =========================================================

# C++
#
# unordered_map<int, vector<int>> graph;

graph = defaultdict(list)

graph[1].append(2)
graph[1].append(3)

print("DefaultDict:", dict(graph))

# =========================================================
# BFS TEMPLATE
# =========================================================

# C++
#
# queue<int> q;
#
# q.push(start);
#
# while(!q.empty())
# {
#     int node = q.front();
#     q.pop();
# }

q = deque([0])

visited = {0}

while q:
    node = q.popleft()

# =========================================================
# DFS ITERATIVE TEMPLATE
# =========================================================

# C++
#
# stack<int> st;
#
# st.push(start);
#
# while(!st.empty())
# {
#     int node = st.top();
#     st.pop();
# }

stack = [0]

visited = {0}

while stack:
    node = stack.pop()

# =========================================================
# DFS RECURSIVE TEMPLATE
# =========================================================

# C++
#
# void dfs(int node)
# {
#     visited[node] = true;
#
#     for(auto child : graph[node])
#     {
#         if(!visited[child])
#             dfs(child);
#     }
# }

graph = defaultdict(list)
visited = set()

def dfs(node):
    visited.add(node)

    for child in graph[node]:
        if child not in visited:
            dfs(child)

# =========================================================
# BINARY TREE NODE
# =========================================================

# C++
#
# struct TreeNode
# {
#     int val;
#     TreeNode* left;
#     TreeNode* right;
# };

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# =========================================================
# LEVEL ORDER TRAVERSAL (BFS)
# =========================================================

# C++ Equivalent:
#
# vector<vector<int>> levelOrder(TreeNode* root)

def levelOrder(root):

    if not root:
        return []

    result = []

    q = deque([root])

    while q:

        level_size = len(q)

        current_level = []

        for _ in range(level_size):

            curr = q.popleft()

            current_level.append(curr.val)

            if curr.left:
                q.append(curr.left)

            if curr.right:
                q.append(curr.right)

        result.append(current_level)

    return result

# =========================================================
# STRING OPERATIONS
# =========================================================

# C++
#
# string s = "hello";

s = "hello"

print(s.upper())
print(s.lower())
print(s[::-1])      # reverse
print(s[1:4])       # substring

# =========================================================
# USEFUL CP ONE-LINERS
# =========================================================

# Unique Elements

arr = [1, 1, 2, 3, 3]

unique = list(set(arr))

# Reverse List

arr.reverse()

# Sorted Copy

sorted_arr = sorted(arr)

# =========================================================
# END OF CHEATSHEET
# =========================================================

print("\nPython CP Cheat Sheet Loaded Successfully!")