# Linux Process Scheduler Simulation (C)

This project is a userspace simulation of Linux-style CPU scheduling algorithms,
implemented in C for learning and experimentation.

## Implemented Algorithms
- First Come First Serve (FCFS)
- Round Robin (RR)

## Features
- Process lifecycle simulation (READY, RUNNING, TERMINATED)
- Time slicing for Round Robin
- Completion time tracking
- Deterministic scheduling for analysis

## Scope & Limitations
- This is a simulation, not kernel-level scheduling
- No real threads or context switching
- Designed to understand scheduling trade-offs and behavior

## How to Run
```bash
gcc scheduler.c -o scheduler
./scheduler
 
---

## STEP 6 — Commit properly (critical)

Make **multiple commits**, not one big dump:

```bash
git add scheduler.h
git commit -m "Define process structure and scheduler interface"

git add scheduler.c
git commit -m "Implement FCFS and Round Robin scheduling simulation"

git add README.md
git commit -m "Add documentation and usage instructions"
