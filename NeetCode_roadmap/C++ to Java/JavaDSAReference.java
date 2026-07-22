import java.io.*;
import java.util.*;

/*
 * ============================================================
 *                    JAVA DSA REFERENCE
 * ============================================================
 *
 * Purpose:
 * A C++ -> Java DSA migration reference for competitive
 * programming, LeetCode, and interview preparation.
 *
 * Every major topic contains:
 * 1. C++ implementation in comments
 * 2. Equivalent Java implementation
 *
 * File: JavaDSAReference.java
 * ============================================================
 */
@SuppressWarnings("all")
public class JavaDSAReference {

    // ============================================================
    // 1. C++ -> JAVA BASIC MAPPING
    // ============================================================

    /*
     * C++:
     * int x = 10;
     * long long x = 10000000000LL;
     * string s = "hello";
     * bool flag = true;
     *
     * Java:
     * int x = 10;
     * long x = 10000000000L;
     * String s = "hello";
     * boolean flag = true;
     */

    /*
     * C++:
     * vector<int> v;
     *
     * Java:
     * ArrayList<Integer> v = new ArrayList<>();
     */

    /*
     * C++:
     * unordered_map<int, int> mp;
     *
     * Java:
     * HashMap<Integer, Integer> mp = new HashMap<>();
     */

    /*
     * C++:
     * unordered_set<int> st;
     *
     * Java:
     * HashSet<Integer> st = new HashSet<>();
     */

    /*
     * C++:
     * map<int, int> mp;
     *
     * Java:
     * TreeMap<Integer, Integer> mp = new TreeMap<>();
     */

    /*
     * C++:
     * set<int> st;
     *
     * Java:
     * TreeSet<Integer> st = new TreeSet<>();
     */

    /*
     * C++:
     * queue<int> q;
     *
     * Java:
     * Queue<Integer> q = new ArrayDeque<>();
     */

    /*
     * C++:
     * stack<int> st;
     *
     * Java:
     * Deque<Integer> st = new ArrayDeque<>();
     */

    /*
     * C++:
     * deque<int> dq;
     *
     * Java:
     * Deque<Integer> dq = new ArrayDeque<>();
     */

    /*
     * C++:
     * priority_queue<int, vector<int>, greater<int>> pq;
     *
     * Java:
     * PriorityQueue<Integer> pq = new PriorityQueue<>();
     */

    /*
     * C++:
     * priority_queue<int> pq;
     *
     * Java:
     * PriorityQueue<Integer> pq =
     *     new PriorityQueue<>(Collections.reverseOrder());
     */

    /*
     * C++:
     * INT_MAX
     * INT_MIN
     * LLONG_MAX
     *
     * Java:
     * Integer.MAX_VALUE
     * Integer.MIN_VALUE
     * Long.MAX_VALUE
     */

    // ============================================================
    // 2. JAVA COMPETITIVE PROGRAMMING TEMPLATE
    // ============================================================

    /*
     * C++:
     *
     * #include <bits/stdc++.h>
     * using namespace std;
     *
     * int main() {
     *     int n;
     *     cin >> n;
     * }
     *
     * Java:
     */

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;

            do {
                c = read();
            } while (c <= ' ');

            while (c > ' ') {
                sb.append((char) c);
                c = read();
            }

            return sb.toString();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        char nextChar() throws IOException {
            return next().charAt(0);
        }
    }

    // ============================================================
    // 3. ARRAYS
    // ============================================================

    /*
     * C++:
     *
     * int arr[n];
     * int arr[] = {1, 2, 3, 4, 5};
     *
     * Java:
     */

    static void arrayBasics() {
        int n = 5;

        int[] arr = new int[n];

        int[] values = {1, 2, 3, 4, 5};

        int first = values[0];

        int length = values.length;

        System.out.println(first);
        System.out.println(length);
    }

    /*
     * C++:
     *
     * vector<vector<int>> matrix(n, vector<int>(m));
     *
     * Java:
     */

    static void matrixBasics() {
        int n = 3;
        int m = 4;

        int[][] matrix = new int[n][m];

        matrix[0][0] = 10;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    /*
     * C++:
     *
     * sort(arr.begin(), arr.end());
     *
     * Java:
     */

    static void arrayUtilities() {
        int[] arr = {5, 2, 8, 1, 3};

        Arrays.sort(arr);

        Arrays.fill(arr, -1);

        int[] copy = Arrays.copyOf(arr, arr.length);

        System.out.println(Arrays.toString(copy));
    }

    // ============================================================
    // 4. STRINGS
    // ============================================================

    /*
     * C++:
     *
     * string s = "hello";
     * cout << s.length();
     * cout << s[0];
     * s += " world";
     *
     * Java:
     */

    static void stringBasics() {
        String s = "hello";

        int length = s.length();

        char first = s.charAt(0);

        String sub = s.substring(1, 4);

        boolean contains = s.contains("ell");

        int index = s.indexOf('l');

        boolean equal = s.equals("hello");

        char[] chars = s.toCharArray();

        System.out.println(length);
        System.out.println(first);
        System.out.println(sub);
        System.out.println(contains);
        System.out.println(index);
        System.out.println(equal);
        System.out.println(Arrays.toString(chars));
    }

    /*
     * C++:
     *
     * string ans;
     * ans += 'a';
     * ans += "hello";
     * reverse(ans.begin(), ans.end());
     *
     * Java:
     */

    static void stringBuilderBasics() {
        StringBuilder sb = new StringBuilder();

        sb.append('a');
        sb.append("hello");

        sb.reverse();

        sb.deleteCharAt(0);

        String result = sb.toString();

        System.out.println(result);
    }

    // ============================================================
    // 5. ARRAYLIST
    // ============================================================

    /*
     * C++:
     *
     * vector<int> v;
     * v.push_back(10);
     * v[0];
     * v.pop_back();
     * v.size();
     *
     * Java:
     */

    static void arrayListBasics() {
        ArrayList<Integer> list = new ArrayList<>();

        list.add(10);
        list.add(20);

        int value = list.get(0);

        list.set(0, 100);

        list.remove(0);

        int size = list.size();

        boolean empty = list.isEmpty();

        boolean contains = list.contains(20);

        Collections.sort(list);

        Collections.reverse(list);

        System.out.println(value);
        System.out.println(size);
        System.out.println(empty);
        System.out.println(contains);
    }

    // ============================================================
    // 6. HASHMAP
    // ============================================================

    /*
     * C++:
     *
     * unordered_map<int, int> mp;
     *
     * mp[5] = 10;
     * cout << mp[5];
     *
     * if (mp.count(5)) {}
     *
     * mp.erase(5);
     *
     * Java:
     */

    static void hashMapBasics() {
        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(5, 10);

        int value = map.get(5);

        boolean exists = map.containsKey(5);

        map.remove(5);

        int size = map.size();

        System.out.println(value);
        System.out.println(exists);
        System.out.println(size);
    }

    /*
     * C++:
     *
     * unordered_map<int, int> freq;
     *
     * for (int x : arr) {
     *     freq[x]++;
     * }
     *
     * Java:
     */

    static HashMap<Integer, Integer> frequencyMap(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int x : arr) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }

        return freq;
    }

    /*
     * C++:
     *
     * unordered_map<char, int> freq;
     *
     * for (char c : s) {
     *     freq[c]++;
     * }
     *
     * Java:
     */

    static HashMap<Character, Integer> characterFrequency(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();

        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        return freq;
    }

    /*
     * C++:
     *
     * for (auto &[key, value] : mp) {
     *     cout << key << " " << value;
     * }
     *
     * Java:
     */

    static void iterateHashMap(HashMap<Integer, Integer> map) {
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();

            System.out.println(key + " " + value);
        }
    }

    // ============================================================
    // 7. HASHSET
    // ============================================================

    /*
     * C++:
     *
     * unordered_set<int> st;
     * st.insert(10);
     * st.count(10);
     * st.erase(10);
     *
     * Java:
     */

    static void hashSetBasics() {
        HashSet<Integer> set = new HashSet<>();

        set.add(10);

        boolean exists = set.contains(10);

        set.remove(10);

        int size = set.size();

        System.out.println(exists);
        System.out.println(size);
    }

    // ============================================================
    // 8. TREEMAP
    // ============================================================

    /*
     * C++:
     *
     * map<int, int> mp;
     *
     * Java:
     */

    static void treeMapBasics() {
        TreeMap<Integer, Integer> map = new TreeMap<>();

        map.put(5, 100);
        map.put(2, 200);
        map.put(8, 300);

        int first = map.firstKey();
        int last = map.lastKey();

        Integer floor = map.floorKey(6);
        Integer ceiling = map.ceilingKey(6);

        Integer lower = map.lowerKey(5);
        Integer higher = map.higherKey(5);

        System.out.println(first);
        System.out.println(last);
        System.out.println(floor);
        System.out.println(ceiling);
        System.out.println(lower);
        System.out.println(higher);
    }

    // ============================================================
    // 9. TREESET
    // ============================================================

    /*
     * C++:
     *
     * set<int> st;
     *
     * st.insert(10);
     * st.erase(10);
     * st.lower_bound(x);
     * st.upper_bound(x);
     *
     * Java:
     */

    static void treeSetBasics() {
        TreeSet<Integer> set = new TreeSet<>();

        set.add(10);
        set.add(20);
        set.add(30);

        set.remove(10);

        boolean exists = set.contains(20);

        Integer floor = set.floor(25);
        Integer ceiling = set.ceiling(25);

        Integer lower = set.lower(20);
        Integer higher = set.higher(20);

        System.out.println(exists);
        System.out.println(floor);
        System.out.println(ceiling);
        System.out.println(lower);
        System.out.println(higher);
    }

    // ============================================================
    // 10. STACK
    // ============================================================

    /*
     * C++:
     *
     * stack<int> st;
     * st.push(10);
     * st.top();
     * st.pop();
     * st.empty();
     *
     * Java:
     *
     * Use Deque instead of the legacy Stack class.
     */

    static void stackBasics() {
        Deque<Integer> stack = new ArrayDeque<>();

        stack.push(10);
        stack.push(20);

        int top = stack.peek();

        int removed = stack.pop();

        boolean empty = stack.isEmpty();

        System.out.println(top);
        System.out.println(removed);
        System.out.println(empty);
    }

    // ============================================================
    // 11. QUEUE
    // ============================================================

    /*
     * C++:
     *
     * queue<int> q;
     * q.push(10);
     * q.front();
     * q.pop();
     *
     * Java:
     */

    static void queueBasics() {
        Queue<Integer> queue = new ArrayDeque<>();

        queue.offer(10);
        queue.offer(20);

        int front = queue.peek();

        int removed = queue.poll();

        boolean empty = queue.isEmpty();

        System.out.println(front);
        System.out.println(removed);
        System.out.println(empty);
    }

    // ============================================================
    // 12. DEQUE
    // ============================================================

    /*
     * C++:
     *
     * deque<int> dq;
     * dq.push_front(10);
     * dq.push_back(20);
     * dq.pop_front();
     * dq.pop_back();
     *
     * Java:
     */

    static void dequeBasics() {
        Deque<Integer> deque = new ArrayDeque<>();

        deque.addFirst(10);
        deque.addLast(20);

        int first = deque.peekFirst();
        int last = deque.peekLast();

        deque.removeFirst();
        deque.removeLast();

        System.out.println(first);
        System.out.println(last);
    }

    // ============================================================
    // 13. PRIORITY QUEUE / HEAP
    // ============================================================

    /*
     * C++:
     *
     * priority_queue<int, vector<int>, greater<int>> pq;
     *
     * Java:
     */

    static void minHeapBasics() {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        minHeap.offer(10);
        minHeap.offer(5);
        minHeap.offer(20);

        int smallest = minHeap.peek();

        int removed = minHeap.poll();

        System.out.println(smallest);
        System.out.println(removed);
    }

    /*
     * C++:
     *
     * priority_queue<int> pq;
     *
     * Java:
     */

    static void maxHeapBasics() {
        PriorityQueue<Integer> maxHeap =
                new PriorityQueue<>(Collections.reverseOrder());

        maxHeap.offer(10);
        maxHeap.offer(5);
        maxHeap.offer(20);

        System.out.println(maxHeap.peek());
    }

    /*
     * C++:
     *
     * priority_queue<pair<int, int>,
     *                vector<pair<int, int>>,
     *                greater<pair<int, int>>> pq;
     *
     * Java:
     */

    static void customPriorityQueue() {
        PriorityQueue<int[]> pq =
                new PriorityQueue<>(
                        (a, b) -> Integer.compare(a[1], b[1])
                );

        pq.offer(new int[]{1, 50});
        pq.offer(new int[]{2, 20});

        int[] current = pq.poll();

        System.out.println(current[0] + " " + current[1]);
    }

    // ============================================================
    // 14. PAIR
    // ============================================================

    /*
     * C++:
     *
     * pair<int, int> p = {10, 20};
     * cout << p.first << p.second;
     *
     * Java:
     *
     * For CP, int[] is often the simplest replacement.
     */

    static void pairUsingArray() {
        int[] pair = {10, 20};

        int first = pair[0];
        int second = pair[1];

        System.out.println(first + " " + second);
    }

    /*
     * C++:
     *
     * pair<int, int> p;
     *
     * Java custom class:
     */

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // ============================================================
    // 15. LINKED LIST
    // ============================================================

    /*
     * C++:
     *
     * struct ListNode {
     *     int val;
     *     ListNode* next;
     * };
     *
     * Java:
     */

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    /*
     * C++:
     *
     * ListNode* prev = nullptr;
     * ListNode* curr = head;
     *
     * while (curr != nullptr) {
     *     ListNode* next = curr->next;
     *     curr->next = prev;
     *     prev = curr;
     *     curr = next;
     * }
     *
     * Java:
     */

    static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;

            curr.next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    /*
     * C++:
     *
     * ListNode* slow = head;
     * ListNode* fast = head;
     *
     * while (fast && fast->next) {
     *     slow = slow->next;
     *     fast = fast->next->next;
     * }
     *
     * Java:
     */

    static ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    /*
     * C++:
     *
     * bool hasCycle(ListNode* head) {
     *     ListNode* slow = head;
     *     ListNode* fast = head;
     *
     *     while (fast && fast->next) {
     *         slow = slow->next;
     *         fast = fast->next->next;
     *
     *         if (slow == fast) return true;
     *     }
     *
     *     return false;
     * }
     *
     * Java:
     */

    static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // ============================================================
    // 16. BINARY TREE
    // ============================================================

    /*
     * C++:
     *
     * struct TreeNode {
     *     int val;
     *     TreeNode* left;
     *     TreeNode* right;
     * };
     *
     * Java:
     */

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /*
     * C++:
     *
     * void inorder(TreeNode* root) {
     *     if (!root) return;
     *
     *     inorder(root->left);
     *     cout << root->val;
     *     inorder(root->right);
     * }
     *
     * Java:
     */

    static void inorder(TreeNode root) {
        if (root == null) {
            return;
        }

        inorder(root.left);

        System.out.println(root.val);

        inorder(root.right);
    }

    /*
     * C++:
     *
     * void preorder(TreeNode* root) {
     *     if (!root) return;
     *
     *     cout << root->val;
     *     preorder(root->left);
     *     preorder(root->right);
     * }
     *
     * Java:
     */

    static void preorder(TreeNode root) {
        if (root == null) {
            return;
        }

        System.out.println(root.val);

        preorder(root.left);
        preorder(root.right);
    }

    /*
     * C++:
     *
     * void postorder(TreeNode* root) {
     *     if (!root) return;
     *
     *     postorder(root->left);
     *     postorder(root->right);
     *     cout << root->val;
     * }
     *
     * Java:
     */

    static void postorder(TreeNode root) {
        if (root == null) {
            return;
        }

        postorder(root.left);
        postorder(root.right);

        System.out.println(root.val);
    }

    /*
     * C++:
     *
     * queue<TreeNode*> q;
     * q.push(root);
     *
     * while (!q.empty()) {
     *     TreeNode* node = q.front();
     *     q.pop();
     * }
     *
     * Java:
     */

    static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null) {
            return ans;
        }

        Queue<TreeNode> queue = new ArrayDeque<>();

        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();

            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();

                level.add(node.val);

                if (node.left != null) {
                    queue.offer(node.left);
                }

                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            ans.add(level);
        }

        return ans;
    }

    // ============================================================
    // 17. BINARY SEARCH TREE
    // ============================================================

    /*
     * C++:
     *
     * TreeNode* insert(TreeNode* root, int val) {
     *     if (!root) return new TreeNode(val);
     *
     *     if (val < root->val)
     *         root->left = insert(root->left, val);
     *     else
     *         root->right = insert(root->right, val);
     *
     *     return root;
     * }
     *
     * Java:
     */

    static TreeNode insertBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }

        if (val < root.val) {
            root.left = insertBST(root.left, val);
        } else {
            root.right = insertBST(root.right, val);
        }

        return root;
    }

    /*
     * C++:
     *
     * bool search(TreeNode* root, int target) {
     *     if (!root) return false;
     *
     *     if (root->val == target) return true;
     *
     *     if (target < root->val)
     *         return search(root->left, target);
     *
     *     return search(root->right, target);
     * }
     *
     * Java:
     */

    static boolean searchBST(TreeNode root, int target) {
        if (root == null) {
            return false;
        }

        if (root.val == target) {
            return true;
        }

        if (target < root.val) {
            return searchBST(root.left, target);
        }

        return searchBST(root.right, target);
    }

    // ============================================================
    // 18. GRAPH REPRESENTATION
    // ============================================================

    /*
     * C++:
     *
     * vector<vector<int>> adj(n);
     *
     * adj[u].push_back(v);
     * adj[v].push_back(u);
     *
     * Java:
     */

    static List<Integer>[] createGraph(int n) {
        List<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        return adj;
    }

    static void addUndirectedEdge(
            List<Integer>[] adj,
            int u,
            int v
    ) {
        adj[u].add(v);
        adj[v].add(u);
    }

    // ============================================================
    // 19. GRAPH BFS
    // ============================================================

    /*
     * C++:
     *
     * queue<int> q;
     * vector<bool> visited(n, false);
     *
     * q.push(start);
     * visited[start] = true;
     *
     * while (!q.empty()) {
     *     int node = q.front();
     *     q.pop();
     *
     *     for (int next : adj[node]) {
     *         if (!visited[next]) {
     *             visited[next] = true;
     *             q.push(next);
     *         }
     *     }
     * }
     *
     * Java:
     */

    static void graphBFS(
            int start,
            List<Integer>[] adj
    ) {
        boolean[] visited = new boolean[adj.length];

        Queue<Integer> queue = new ArrayDeque<>();

        queue.offer(start);

        visited[start] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(next);
                }
            }
        }
    }

    // ============================================================
    // 20. GRAPH DFS
    // ============================================================

    /*
     * C++:
     *
     * void dfs(
     *     int node,
     *     vector<vector<int>>& adj,
     *     vector<bool>& visited
     * ) {
     *     visited[node] = true;
     *
     *     for (int next : adj[node]) {
     *         if (!visited[next]) {
     *             dfs(next, adj, visited);
     *         }
     *     }
     * }
     *
     * Java:
     */

    static void graphDFS(
            int node,
            List<Integer>[] adj,
            boolean[] visited
    ) {
        visited[node] = true;

        for (int next : adj[node]) {
            if (!visited[next]) {
                graphDFS(next, adj, visited);
            }
        }
    }

    // ============================================================
    // 21. WEIGHTED GRAPH
    // ============================================================

    /*
     * C++:
     *
     * vector<vector<pair<int, int>>> adj(n);
     *
     * adj[u].push_back({v, weight});
     *
     * Java:
     */

    static class Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static List<Edge>[] createWeightedGraph(int n) {
        List<Edge>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        return adj;
    }

    static void addWeightedEdge(
            List<Edge>[] adj,
            int u,
            int v,
            int weight
    ) {
        adj[u].add(new Edge(v, weight));
    }

    // ============================================================
    // 22. DIJKSTRA
    // ============================================================

    /*
     * C++:
     *
     * priority_queue<
     *     pair<int,int>,
     *     vector<pair<int,int>>,
     *     greater<pair<int,int>>
     * > pq;
     *
     * Java:
     */

    static int[] dijkstra(
            int n,
            List<Edge>[] adj,
            int source
    ) {
        int[] dist = new int[n];

        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<int[]> pq =
                new PriorityQueue<>(
                        (a, b) -> Integer.compare(a[1], b[1])
                );

        dist[source] = 0;

        pq.offer(new int[]{source, 0});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();

            int node = current[0];
            int distance = current[1];

            if (distance != dist[node]) {
                continue;
            }

            for (Edge edge : adj[node]) {
                int next = edge.to;

                int newDistance =
                        distance + edge.weight;

                if (newDistance < dist[next]) {
                    dist[next] = newDistance;

                    pq.offer(
                            new int[]{
                                    next,
                                    newDistance
                            }
                    );
                }
            }
        }

        return dist;
    }

    // ============================================================
    // 23. DISJOINT SET UNION / UNION FIND
    // ============================================================

    /*
     * C++:
     *
     * class DSU {
     *     vector<int> parent, size;
     *
     * public:
     *     DSU(int n) {
     *         parent.resize(n);
     *         size.resize(n, 1);
     *
     *         for (int i = 0; i < n; i++)
     *             parent[i] = i;
     *     }
     *
     *     int find(int x) {
     *         if (parent[x] == x)
     *             return x;
     *
     *         return parent[x] = find(parent[x]);
     *     }
     *
     *     void unite(int u, int v) {
     *         int pu = find(u);
     *         int pv = find(v);
     *
     *         if (pu == pv) return;
     *
     *         if (size[pu] < size[pv])
     *             swap(pu, pv);
     *
     *         parent[pv] = pu;
     *         size[pu] += size[pv];
     *     }
     * };
     *
     * Java:
     */

    static class DSU {
        int[] parent;
        int[] size;

        DSU(int n) {
            parent = new int[n];
            size = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        void union(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) {
                return;
            }

            if (size[pu] < size[pv]) {
                int temp = pu;
                pu = pv;
                pv = temp;
            }

            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // ============================================================
    // 24. TRIE
    // ============================================================

    /*
     * C++:
     *
     * struct TrieNode {
     *     TrieNode* child[26];
     *     bool isEnd;
     * };
     *
     * Java:
     */

    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd;
    }

    static class Trie {
        TrieNode root = new TrieNode();

        void insert(String word) {
            TrieNode current = root;

            for (char c : word.toCharArray()) {
                int index = c - 'a';

                if (current.children[index] == null) {
                    current.children[index] =
                            new TrieNode();
                }

                current = current.children[index];
            }

            current.isEnd = true;
        }

        boolean search(String word) {
            TrieNode current = root;

            for (char c : word.toCharArray()) {
                int index = c - 'a';

                if (current.children[index] == null) {
                    return false;
                }

                current = current.children[index];
            }

            return current.isEnd;
        }

        boolean startsWith(String prefix) {
            TrieNode current = root;

            for (char c : prefix.toCharArray()) {
                int index = c - 'a';

                if (current.children[index] == null) {
                    return false;
                }

                current = current.children[index];
            }

            return true;
        }
    }

    // ============================================================
    // 25. BINARY SEARCH
    // ============================================================

    /*
     * C++:
     *
     * int left = 0;
     * int right = n - 1;
     *
     * while (left <= right) {
     *     int mid = left + (right - left) / 2;
     *
     *     if (arr[mid] == target)
     *         return mid;
     *
     *     if (arr[mid] < target)
     *         left = mid + 1;
     *     else
     *         right = mid - 1;
     * }
     *
     * Java:
     */

    static int binarySearch(
            int[] arr,
            int target
    ) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid =
                    left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    // ============================================================
    // 26. LOWER BOUND
    // ============================================================

    /*
     * C++:
     *
     * lower_bound(
     *     arr.begin(),
     *     arr.end(),
     *     target
     * );
     *
     * Meaning:
     * First index where arr[index] >= target.
     *
     * Java:
     */

    static int lowerBound(
            int[] arr,
            int target
    ) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid =
                    left + (right - left) / 2;

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    // ============================================================
    // 27. UPPER BOUND
    // ============================================================

    /*
     * C++:
     *
     * upper_bound(
     *     arr.begin(),
     *     arr.end(),
     *     target
     * );
     *
     * Meaning:
     * First index where arr[index] > target.
     *
     * Java:
     */

    static int upperBound(
            int[] arr,
            int target
    ) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid =
                    left + (right - left) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    // ============================================================
    // 28. SORTING
    // ============================================================

    /*
     * C++:
     *
     * sort(arr.begin(), arr.end());
     *
     * Java:
     */

    static void sortingBasics() {
        int[] arr = {5, 2, 8, 1};

        Arrays.sort(arr);

        Integer[] nums = {5, 2, 8, 1};

        Arrays.sort(
                nums,
                Collections.reverseOrder()
        );

        int[][] intervals = {
                {3, 5},
                {1, 2},
                {2, 4}
        };

        Arrays.sort(
                intervals,
                (a, b) ->
                        Integer.compare(a[0], b[0])
        );
    }

    /*
     * C++:
     *
     * sort(v.begin(), v.end(),
     *      [](auto &a, auto &b) {
     *          return a.second < b.second;
     *      });
     *
     * Java:
     */

    static void customListSorting() {
        List<Pair> list = new ArrayList<>();

        list.add(new Pair(1, 50));
        list.add(new Pair(2, 20));

        list.sort(
                (a, b) ->
                        Integer.compare(
                                a.second,
                                b.second
                        )
        );
    }

    // ============================================================
    // 29. RECURSION
    // ============================================================

    /*
     * C++:
     *
     * int factorial(int n) {
     *     if (n <= 1) return 1;
     *     return n * factorial(n - 1);
     * }
     *
     * Java:
     */

    static int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        return n * factorial(n - 1);
    }

    // ============================================================
    // 30. BACKTRACKING - SUBSETS
    // ============================================================

    /*
     * C++:
     *
     * void backtrack(
     *     int index,
     *     vector<int>& nums,
     *     vector<int>& current,
     *     vector<vector<int>>& ans
     * ) {
     *     if (index == nums.size()) {
     *         ans.push_back(current);
     *         return;
     *     }
     *
     *     current.push_back(nums[index]);
     *
     *     backtrack(
     *         index + 1,
     *         nums,
     *         current,
     *         ans
     *     );
     *
     *     current.pop_back();
     *
     *     backtrack(
     *         index + 1,
     *         nums,
     *         current,
     *         ans
     *     );
     * }
     *
     * Java:
     */

    static void subsets(
            int index,
            int[] nums,
            List<Integer> current,
            List<List<Integer>> ans
    ) {
        if (index == nums.length) {
            ans.add(new ArrayList<>(current));
            return;
        }

        current.add(nums[index]);

        subsets(
                index + 1,
                nums,
                current,
                ans
        );

        current.remove(current.size() - 1);

        subsets(
                index + 1,
                nums,
                current,
                ans
        );
    }

    // ============================================================
    // 31. DYNAMIC PROGRAMMING - 1D
    // ============================================================

    /*
     * C++:
     *
     * vector<int> dp(n + 1);
     *
     * dp[0] = 0;
     * dp[1] = 1;
     *
     * for (int i = 2; i <= n; i++) {
     *     dp[i] =
     *         dp[i - 1] +
     *         dp[i - 2];
     * }
     *
     * Java:
     */

    static int fibonacciDP(int n) {
        if (n <= 1) {
            return n;
        }

        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] =
                    dp[i - 1] +
                    dp[i - 2];
        }

        return dp[n];
    }

    // ============================================================
    // 32. DYNAMIC PROGRAMMING - MEMOIZATION
    // ============================================================

    /*
     * C++:
     *
     * vector<int> dp(n + 1, -1);
     *
     * int solve(int n) {
     *     if (n <= 1) return n;
     *
     *     if (dp[n] != -1)
     *         return dp[n];
     *
     *     return dp[n] =
     *         solve(n - 1) +
     *         solve(n - 2);
     * }
     *
     * Java:
     */

    static int[] memo;

    static int fibonacciMemo(int n) {
        if (n <= 1) {
            return n;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        return memo[n] =
                fibonacciMemo(n - 1) +
                fibonacciMemo(n - 2);
    }

    // ============================================================
    // 33. DYNAMIC PROGRAMMING - 2D
    // ============================================================

    /*
     * C++:
     *
     * vector<vector<int>> dp(
     *     n,
     *     vector<int>(m, -1)
     * );
     *
     * Java:
     */

    static int[][] create2DDP(int n, int m) {
        int[][] dp = new int[n][m];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return dp;
    }

    // ============================================================
    // 34. PREFIX SUM
    // ============================================================

    /*
     * C++:
     *
     * vector<int> prefix(n + 1);
     *
     * for (int i = 0; i < n; i++) {
     *     prefix[i + 1] =
     *         prefix[i] + arr[i];
     * }
     *
     * Java:
     */

    static int[] prefixSum(int[] arr) {
        int[] prefix =
                new int[arr.length + 1];

        for (int i = 0; i < arr.length; i++) {
            prefix[i + 1] =
                    prefix[i] + arr[i];
        }

        return prefix;
    }

    // ============================================================
    // 35. SLIDING WINDOW
    // ============================================================

    /*
     * C++:
     *
     * int left = 0;
     *
     * for (int right = 0; right < n; right++) {
     *     // add arr[right]
     *
     *     while (condition) {
     *         // remove arr[left]
     *         left++;
     *     }
     * }
     *
     * Java:
     */

    static int longestSubarrayAtMostKDistinct(
            int[] arr,
            int k
    ) {
        HashMap<Integer, Integer> freq =
                new HashMap<>();

        int left = 0;
        int answer = 0;

        for (int right = 0;
             right < arr.length;
             right++) {

            freq.put(
                    arr[right],
                    freq.getOrDefault(
                            arr[right],
                            0
                    ) + 1
            );

            while (freq.size() > k) {
                int value = arr[left];

                freq.put(
                        value,
                        freq.get(value) - 1
                );

                if (freq.get(value) == 0) {
                    freq.remove(value);
                }

                left++;
            }

            answer = Math.max(
                    answer,
                    right - left + 1
            );
        }

        return answer;
    }

    // ============================================================
    // 36. MONOTONIC STACK
    // ============================================================

    /*
     * C++:
     *
     * stack<int> st;
     *
     * for (int x : arr) {
     *     while (!st.empty() &&
     *            st.top() > x) {
     *         st.pop();
     *     }
     *
     *     st.push(x);
     * }
     *
     * Java:
     */

    static void monotonicStack(int[] arr) {
        Deque<Integer> stack =
                new ArrayDeque<>();

        for (int x : arr) {
            while (!stack.isEmpty()
                    && stack.peek() > x) {
                stack.pop();
            }

            stack.push(x);
        }
    }

    // ============================================================
    // 37. MONOTONIC QUEUE
    // ============================================================

    /*
     * C++:
     *
     * deque<int> dq;
     *
     * while (!dq.empty() &&
     *        dq.front() <= i - k) {
     *     dq.pop_front();
     * }
     *
     * while (!dq.empty() &&
     *        nums[dq.back()] <= nums[i]) {
     *     dq.pop_back();
     * }
     *
     * dq.push_back(i);
     *
     * Java:
     */

    static int[] slidingWindowMaximum(
            int[] nums,
            int k
    ) {
        int n = nums.length;

        int[] answer =
                new int[n - k + 1];

        Deque<Integer> deque =
                new ArrayDeque<>();

        for (int i = 0; i < n; i++) {

            while (!deque.isEmpty()
                    && deque.peekFirst()
                    <= i - k) {
                deque.pollFirst();
            }

            while (!deque.isEmpty()
                    && nums[deque.peekLast()]
                    <= nums[i]) {
                deque.pollLast();
            }

            deque.offerLast(i);

            if (i >= k - 1) {
                answer[i - k + 1] =
                        nums[deque.peekFirst()];
            }
        }

        return answer;
    }

    // ============================================================
    // 38. TOPOLOGICAL SORT - KAHN'S ALGORITHM
    // ============================================================

    /*
     * C++:
     *
     * vector<int> indegree(n, 0);
     * queue<int> q;
     *
     * for (int i = 0; i < n; i++) {
     *     if (indegree[i] == 0)
     *         q.push(i);
     * }
     *
     * Java:
     */

    static List<Integer> topologicalSort(
            int n,
            List<Integer>[] adj
    ) {
        int[] indegree = new int[n];

        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        Queue<Integer> queue =
                new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        List<Integer> order =
                new ArrayList<>();

        while (!queue.isEmpty()) {
            int node = queue.poll();

            order.add(node);

            for (int next : adj[node]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

        if (order.size() != n) {
            return new ArrayList<>();
        }

        return order;
    }

    // ============================================================
    // 39. FLOYD-WARSHALL
    // ============================================================

    /*
     * C++:
     *
     * for (int k = 0; k < n; k++) {
     *     for (int i = 0; i < n; i++) {
     *         for (int j = 0; j < n; j++) {
     *             dist[i][j] =
     *                 min(
     *                     dist[i][j],
     *                     dist[i][k] +
     *                     dist[k][j]
     *                 );
     *         }
     *     }
     * }
     *
     * Java:
     */

    static void floydWarshall(
            long[][] dist
    ) {
        int n = dist.length;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][k] == Long.MAX_VALUE
                            || dist[k][j] == Long.MAX_VALUE) {
                        continue;
                    }

                    dist[i][j] =
                            Math.min(
                                    dist[i][j],
                                    dist[i][k]
                                            + dist[k][j]
                            );
                }
            }
        }
    }

    // ============================================================
    // 40. FENWICK TREE / BINARY INDEXED TREE
    // ============================================================

    /*
     * C++:
     *
     * class Fenwick {
     *     vector<int> bit;
     *
     *     void add(int idx, int val) {
     *         for (; idx < bit.size();
     *              idx += idx & -idx)
     *             bit[idx] += val;
     *     }
     *
     *     int sum(int idx) {
     *         int ans = 0;
     *
     *         for (; idx > 0;
     *              idx -= idx & -idx)
     *             ans += bit[idx];
     *
     *         return ans;
     *     }
     * };
     *
     * Java:
     */

    static class FenwickTree {
        int[] bit;

        FenwickTree(int n) {
            bit = new int[n + 1];
        }

        void add(int index, int value) {
            for (int i = index;
                 i < bit.length;
                 i += i & -i) {

                bit[i] += value;
            }
        }

        int prefixSum(int index) {
            int answer = 0;

            for (int i = index;
                 i > 0;
                 i -= i & -i) {

                answer += bit[i];
            }

            return answer;
        }

        int rangeSum(
                int left,
                int right
        ) {
            return prefixSum(right)
                    - prefixSum(left - 1);
        }
    }

    // ============================================================
    // 41. SEGMENT TREE
    // ============================================================

    /*
     * C++:
     *
     * vector<int> tree(4 * n);
     *
     * build(node, start, end);
     * query(node, start, end, l, r);
     * update(node, start, end, index, value);
     *
     * Java:
     */

    static class SegmentTree {
        int n;
        int[] tree;

        SegmentTree(int[] arr) {
            n = arr.length;

            tree = new int[4 * n];

            build(
                    1,
                    0,
                    n - 1,
                    arr
            );
        }

        void build(
                int node,
                int left,
                int right,
                int[] arr
        ) {
            if (left == right) {
                tree[node] = arr[left];
                return;
            }

            int mid =
                    left + (right - left) / 2;

            build(
                    node * 2,
                    left,
                    mid,
                    arr
            );

            build(
                    node * 2 + 1,
                    mid + 1,
                    right,
                    arr
            );

            tree[node] =
                    Math.min(
                            tree[node * 2],
                            tree[node * 2 + 1]
                    );
        }

        int query(
                int node,
                int left,
                int right,
                int queryLeft,
                int queryRight
        ) {
            if (queryRight < left
                    || right < queryLeft) {
                return Integer.MAX_VALUE;
            }

            if (queryLeft <= left
                    && right <= queryRight) {
                return tree[node];
            }

            int mid =
                    left + (right - left) / 2;

            return Math.min(
                    query(
                            node * 2,
                            left,
                            mid,
                            queryLeft,
                            queryRight
                    ),
                    query(
                            node * 2 + 1,
                            mid + 1,
                            right,
                            queryLeft,
                            queryRight
                    )
            );
        }

        void update(
                int node,
                int left,
                int right,
                int index,
                int value
        ) {
            if (left == right) {
                tree[node] = value;
                return;
            }

            int mid =
                    left + (right - left) / 2;

            if (index <= mid) {
                update(
                        node * 2,
                        left,
                        mid,
                        index,
                        value
                );
            } else {
                update(
                        node * 2 + 1,
                        mid + 1,
                        right,
                        index,
                        value
                );
            }

            tree[node] =
                    Math.min(
                            tree[node * 2],
                            tree[node * 2 + 1]
                    );
        }

        int query(
                int left,
                int right
        ) {
            return query(
                    1,
                    0,
                    n - 1,
                    left,
                    right
            );
        }

        void update(
                int index,
                int value
        ) {
            update(
                    1,
                    0,
                    n - 1,
                    index,
                    value
            );
        }
    }

    // ============================================================
    // 42. COMMON JAVA UTILITIES
    // ============================================================

    /*
     * C++:
     *
     * max(a, b)
     * min(a, b)
     * abs(x)
     *
     * Java:
     */

    static void mathUtilities() {
        int a = 10;
        int b = 20;

        int maximum = Math.max(a, b);
        int minimum = Math.min(a, b);
        int absolute = Math.abs(-10);

        double power = Math.pow(2, 3);
        double squareRoot = Math.sqrt(16);

        System.out.println(maximum);
        System.out.println(minimum);
        System.out.println(absolute);
        System.out.println(power);
        System.out.println(squareRoot);
    }

    /*
     * C++:
     *
     * swap(a, b);
     *
     * Java:
     */

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;
    }

    /*
     * C++:
     *
     * reverse(v.begin(), v.end());
     *
     * Java:
     */

    static void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            swap(arr, left, right);

            left++;
            right--;
        }
    }

    /*
     * C++:
     *
     * string s = to_string(num);
     * int x = stoi(s);
     * long long y = stoll(s);
     *
     * Java:
     */

    static void stringNumberConversion() {
        int number = 123;

        String s =
                String.valueOf(number);

        int x =
                Integer.parseInt("123");

        long y =
                Long.parseLong("123456789");

        System.out.println(s);
        System.out.println(x);
        System.out.println(y);
    }

    // ============================================================
    // 43. COMMON 4-DIRECTION GRID TEMPLATE
    // ============================================================

    /*
     * C++:
     *
     * int dr[4] = {-1, 0, 1, 0};
     * int dc[4] = {0, 1, 0, -1};
     *
     * Java:
     */

    static final int[] DR =
            {-1, 0, 1, 0};

    static final int[] DC =
            {0, 1, 0, -1};

    static boolean isValidCell(
            int row,
            int col,
            int rows,
            int cols
    ) {
        return row >= 0
                && row < rows
                && col >= 0
                && col < cols;
    }

    // ============================================================
    // 44. GRID BFS TEMPLATE
    // ============================================================

    /*
     * C++:
     *
     * queue<pair<int,int>> q;
     *
     * q.push({sr, sc});
     *
     * while (!q.empty()) {
     *     auto [r, c] = q.front();
     *     q.pop();
     *
     *     for (int k = 0; k < 4; k++) {
     *         int nr = r + dr[k];
     *         int nc = c + dc[k];
     *     }
     * }
     *
     * Java:
     */

    static void gridBFS(
            int[][] grid,
            int startRow,
            int startCol
    ) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited =
                new boolean[rows][cols];

        Queue<int[]> queue =
                new ArrayDeque<>();

        queue.offer(
                new int[]{
                        startRow,
                        startCol
                }
        );

        visited[startRow][startCol] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();

            int row = current[0];
            int col = current[1];

            for (int k = 0; k < 4; k++) {
                int newRow =
                        row + DR[k];

                int newCol =
                        col + DC[k];

                if (isValidCell(
                        newRow,
                        newCol,
                        rows,
                        cols
                ) && !visited[newRow][newCol]) {

                    visited[newRow][newCol] = true;

                    queue.offer(
                            new int[]{
                                    newRow,
                                    newCol
                            }
                    );
                }
            }
        }
    }

    // ============================================================
    // 45. GRID DFS TEMPLATE
    // ============================================================

    /*
     * C++:
     *
     * void dfs(int r, int c) {
     *     if (invalid) return;
     *
     *     visited[r][c] = true;
     *
     *     for (int k = 0; k < 4; k++) {
     *         dfs(
     *             r + dr[k],
     *             c + dc[k]
     *         );
     *     }
     * }
     *
     * Java:
     */

    static void gridDFS(
            int row,
            int col,
            int[][] grid,
            boolean[][] visited
    ) {
        int rows = grid.length;
        int cols = grid[0].length;

        if (!isValidCell(
                row,
                col,
                rows,
                cols
        )) {
            return;
        }

        if (visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        for (int k = 0; k < 4; k++) {
            gridDFS(
                    row + DR[k],
                    col + DC[k],
                    grid,
                    visited
            );
        }
    }

    // ============================================================
    // 46. BIT MANIPULATION
    // ============================================================

    /*
     * C++:
     *
     * int bit = (n >> i) & 1;
     * n |= (1 << i);
     * n &= ~(1 << i);
     * n ^= (1 << i);
     *
     * Java:
     */

    static void bitManipulation() {
        int n = 10;
        int i = 2;

        int bit =
                (n >> i) & 1;

        n |= (1 << i);

        n &= ~(1 << i);

        n ^= (1 << i);

        int count =
                Integer.bitCount(n);

        boolean powerOfTwo =
                n > 0
                        && (n & (n - 1)) == 0;

        System.out.println(bit);
        System.out.println(count);
        System.out.println(powerOfTwo);
    }

    // ============================================================
    // 47. GCD / LCM
    // ============================================================

    /*
     * C++:
     *
     * int g = gcd(a, b);
     * int l = lcm(a, b);
     *
     * Java:
     */

    static long gcd(
            long a,
            long b
    ) {
        while (b != 0) {
            long temp = a % b;

            a = b;
            b = temp;
        }

        return Math.abs(a);
    }

    static long lcm(
            long a,
            long b
    ) {
        return Math.abs(
                a / gcd(a, b) * b
        );
    }

    // ============================================================
    // 48. MAIN
    // ============================================================

    /*
     * This file is primarily a reference library.
     *
     * For competitive programming, replace main() with your
     * problem-specific solution.
     */

    public static void main(String[] args) throws Exception {

        /*
         * Example:
         *
         * FastScanner fs = new FastScanner();
         *
         * int n = fs.nextInt();
         *
         * int[] arr = new int[n];
         *
         * for (int i = 0; i < n; i++) {
         *     arr[i] = fs.nextInt();
         * }
         */

        System.out.println(
                "Java DSA Reference Loaded"
        );
    }
}
