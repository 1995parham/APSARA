# APSARA
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
Compute the weight of every matching Y ∈ S(t + 1) as W(Y) = Σij yij * qij(t + 1).
* Determine the matching at time t + 1 given by
X(t + 1) = arg
