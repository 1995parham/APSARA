# APSARA
[![Travis](https://img.shields.io/travis/1995parham/APSARA.svg?style=flat-square)](https://travis-ci.org/1995parham/APSARA)

## Introduction
The high demand for Internet bandwidth
has led to increasingly higherspeed links
and caused an associated demand for routers
with a high aggregate switching capacity.
At the highest speeds, input-queued (IQ)
switches have become the architecture of choice,
mainly because the memory bandwidth of their packet
buffers is very low compared to that of output-queued and
shared-memory architectures.

## APSARA
Let X(t) be the matching determined by
Apsara at time t, and let Q(t + 1) be the queue
lengths at the beginning of time t + 1. At time
t + 1, Apsara does the following:
* Determine neighbors N[X(t)] of X(t) and matching Z(t + 1)
that correspond to the Hamiltonian walk at time t + 1.
* Let S(t + 1) = N[X(t)] U Z(t + 1) U X(t).
Compute the weight of every matching Y ∈ S(t + 1) as W(Y) = Σij y_{ij} * q_{ij}(t + 1).
* Determine the matching at time t + 1 given by
X(t + 1) = arg max (U ∈ S(t + 1)) (W(U))

## Implementation
My personal implementation of APSARA algorithm exists at `src/switch-apsara.c` but you can
create your implementation in this platform easily, you must implement
following method:
```c
void switch_next_matching(struct sw *s)
```
for better use of this simple switch simulating platform it is better to
read these structure:
```c
struct sw {
	const struct matching *m;
	int in_port;
	int out_port;
	int **queue;
	int throughput;
	int t;
}
```
```c
struct matching {
	int n, m;
	int *match;
}
```
## Switch Throughput
These results were obtained with this program.

| Ports | Throughput | Load | Simulation Cycles |
| :---- | :--------: | :--: | ----------------: |
| 4     |  0.999909  | 0.80 | 31058             |
| 5     |  0.999876  | 0.80 | 31058             |
| 6     |  0.999779  | 0.80 | 31058             |
| 7     |  0.999708  | 0.80 | 31058             |
| 8     |  0.999611  | 0.80 | 31058             |

## Special Thanks
I want to thank **Mr.FarKiani** for helping me to debug this program.
