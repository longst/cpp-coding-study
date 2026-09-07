# Copilot Instructions for This Study Repo

This repository is a personal C++ learning record. When helping in this repo, prioritize teaching, clarity, and mistake tracking.

## Study style

- Explain C++ concepts in simple terms.
- Prefer small examples over large abstractions.
- When reviewing code, identify the exact bug, explain why it fails, and show the corrected version.
- Use beginner-friendly C++ unless the learner asks for advanced techniques.

## Required tracking habits

When a learning session includes a meaningful mistake or misconception, update:

- `trackers/error-log.md`

When a data structure or STL container is studied, update:

- `trackers/data-structures.md`

When a reusable learning workflow is created, add it under:

- `skills/`

## Problem note format

For each problem, use this structure:

```md
# Problem Name

## Pattern

## Key idea

## Common mistakes

## Correct solution

## Complexity
```

## C++ preferences

- Use `std::vector`, `std::string`, and STL containers when appropriate.
- Use references for large objects, e.g. `const std::vector<int>&`.
- Pass small primitive types like `int` by value.
- Avoid converting large digit arrays into integer types because of overflow.
- For in-place array problems, modify `std::vector<int>& nums` directly and return `k`.

