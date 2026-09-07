# Skill: Track Errors

Use this workflow whenever a mistake appears during C++ practice.

## When to update

Update `trackers/error-log.md` when there is:

- A compile error caused by syntax or type misunderstanding.
- A runtime bug such as out-of-bounds access or null pointer dereference.
- A wrong-answer pattern in an algorithm.
- A repeated misconception about STL containers, pointers, references, loops, or complexity.

## What to record

Add one row with:

- Date
- Topic
- Mistake
- Why it fails
- Correct pattern

## Example

```md
| 2026-09-07 | Vector indexing | Used `nums[nums.size()]` | Last valid index is `nums.size() - 1` | Use `nums.back()` or `nums[nums.size() - 1]` |
```

