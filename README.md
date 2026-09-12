# Leetcode
Leetcode Contests Solutions

# LeetCode Solutions

Solutions organised by pattern rather than by problem number, because the pattern is the part that transfers.

**Profile:** [https://leetcode.com/u/golu_0409/](https://leetcode.com/u/golu_0409/)

**Rating:** Guardian — 2267 (top 1% worldwide)

**Languages:** C++

---

## Why organised by pattern

Problem-number directories are easy to generate and nearly useless to read. Almost every LeetCode problem is a known technique wearing a costume, and the skill worth building is recognising which one — usually within the first minute, before writing anything.

So the top-level structure here is the technique. If you want to see how sliding window behaves across a hard, a medium and a deceptively tricky easy, they're in the same folder.

---

## Repository structure

```
.
├── patterns/
│   ├── two-pointers/
│   ├── sliding-window/
│   ├── binary-search/
│   ├── monotonic-stack/
│   ├── heap-and-priority-queue/
│   ├── graphs-bfs-dfs/
│   ├── union-find/
│   ├── dynamic-programming/
│   │   ├── 1d/
│   │   ├── 2d-grid/
│   │   ├── subsequence/
│   │   ├── knapsack/
│   │   └── on-trees/
│   ├── intervals/
│   ├── backtracking/
│   ├── tries/
│   └── design/            # LRU cache, rate limiters, iterators
├── contests/              # weekly and biweekly contest solutions
└── notes/                 # pattern write-ups and recognition cues
```

Each solution carries a short header:

```java
// 239. Sliding Window Maximum                          [Hard]
// https://leetcode.com/problems/sliding-window-maximum/
//
// Pattern  : monotonic deque
// Cue      : "maximum over every window of fixed size" — a heap gives
//            O(n log k); a deque holding indices in decreasing order
//            of value gives O(n) because each index enters and leaves once
// Time     : O(n)      Space : O(k)
// Note     : I reached for a heap first. The deque only became obvious
//            once I asked what work the heap was repeating.
```

That last line is deliberate. Recording the wrong turn is more useful on a re-read than recording the right answer.

---

## Pattern recognition cues

The contents of `notes/` in compressed form — the signal in a problem statement that points at a technique:

| Cue in the problem | Usually means |
|---|---|
| "contiguous subarray" + a constraint that grows monotonically | Sliding window |
| Sorted input, or a pair/triplet summing to a target | Two pointers |
| "minimum k-th" / "top k" / streaming | Heap |
| "next greater" / "previous smaller" / span | Monotonic stack |
| Array is sorted, or the answer is monotone in some parameter | Binary search, possibly on the answer |
| "number of ways" / "minimum cost to reach" | Dynamic programming |
| Connectivity, components, cycle detection in undirected graphs | Union-Find |
| "all permutations" / "all valid combinations" | Backtracking |
| Prefix matching over many strings | Trie |
| Overlaps, merging, scheduling | Interval sort + sweep |

---

## Design problems

`patterns/design/` holds the system-flavoured problems — LRU and LFU cache, rate limiter, iterator design, time-based key-value store, median from a data stream. These are the ones closest to real backend work, and the only category where I'd say the LeetCode version genuinely resembles something I've had to build.

---

## Contest record

| Metric | Value |
|---|---|
| Rating | 2267 (Guardian) |
| Percentile | Top 1% |
| Contests attended | 74 |
| Best rank | 83 |



---

## Also

- Codeforces: Expert (1728), Global Rank 174 in Round 855 — [solutions repository](https://github.com/durgeshkk/Codeforces-Contests)
- CodeChef: 5-star (2005), Global Rank 30 in May Lunchtime 2022
- Google Kickstart 2022 Round H: Global Rank 676
