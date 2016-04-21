# Insteresting chpater in Reading Material

## <Algorithms Unplugged>
1. 31 Dynamic Programming – Evolutionary Distance
2. 41 Simulated Annealing

## Simulated Annealing
1. Simulated annealing (SA) is a probabilistic technique for approximating the _global optimum_ of a given function.[1]
2. it is a __metaheuristic__ to approximate global optimization in a large search space. Metaheuristics use the neighbours of a solution as a way to explore the solutions space, and although they prefer better neighbours, they also accept worse neighbours in order to avoid getting stuck in local optima.[1]
3. a slow decrease in the probability of accepting worse solutions as it explores the solution space. Accepting worse solutions is a fundamental property of metaheuristics because it allows for a more extensive search for the optimal solution.[1]
4. The goal is to bring the system, from an arbitrary initial state, to a state with the minimum possible energy.[1]
5. _probabilistically_ decides between moving the system to state s' or staying in state s. These probabilities ultimately lead the system to move to states of _lower energy_.[1]
6. this step is repeated until the system reaches a state that is good enough for the application, or until a given computation budget has been exhausted.[1]

## Modeling simulated annealing as  arandom walk on a search graph
1. vertices are all possible states, edges are the candidate moves.
2. The diameter of the search graph must be small.
## tiling game
1. tiling game. the domino game.: as many neighboring sides of tiles of the same color as possible.
2. exactly solve only for relatively small input size.
3. Simulating a process that involves first heating and them slowliy cooling some material.
4. monicrystalline state of silicon. smallest energy possible
4. tiling game, 'bond' between two neighboring tiles is stronger if sides with the same color face each other.

1. the tiles widly jump about
2. the lower the temprature gets, the harder it becomdes to tear a tile from its positioni
3. the more stable bonds they have with their neighors, the stonger they stick to their position.

1. method of steepest descent, only climbs upward, never downward.
2. P395-Algorithm

### Term
1. The neighbours of a state
2. a move: the states are altered in order to find neighbouring states. These moves usually result in _minimal alterations_ of the last state.
3. Acceptance probabilities: P(e, e', T),  depends on the energies e = E(s) and e' = E(s') of the two states, and on a global time-varying parameter T called the temperature. 1)When T tends to zero, the probability P(e, e', T) must tend to zero. For sufficiently small values of T, the system will then increasingly favor moves that go "downhill". With T=0 the procedure reduces to the greedy algorithm, which makes only the downhill transitions. 2) for a large T, the evolution of s is sensitive to coarser energy variations, while it is sensitive to finer energy variations when T is small.
4. 1 not essential condition: the probability P(e, e', T) was equal to 1 when e'<\e
5. 2 not essential condition: the probability of accepting a move decreases when the difference e'-e increases
6. The annealing schedule:  end with T=0

### The travellingSalesperson Problem
1. total mileage traveled becomes as small as possible
2. Find some solution to start with(Put the cities in some arbitrary order).
3. One approach: randomly choose a segment of the tour and traverse it in the opposite direction.
4. Second approach: visit soome city at a different point in time.
5. If the new one is better, we keep it, otherwise we return to the older tour.(only climbs upward.)
6. the state space, the energy (goal) function E(), the candidate generator procedure neighbour(), the acceptance probability function P(), and the annealing schedule temperature() AND initial temperature.
### paper jogger.
1. perfectly aligned stack of paper
2. turn the vibration from strong to gentle.

### Problems that can use simulated annealing
1. solution can be judged by number.
2. An initial solution can be easily computed
3. There are simple adjustment rules that _locally_ change a solution.
4. Every solution can be turned into every other solution by the adjustment rules.
5. often used when the search space is discrete[1]

### Advantage
1. simulated annealing may be preferable to alternatives such as brute-force search or gradient descent.

### Adaptive simulated annealing algorithms
1. connecting the cooling schedule to the search progress.

### restarting of simulated annealing
1. move back to a solution that was significantly better rather than always moving from the current state.
2. restarting based on a fixed number of steps, based on whether the current energy is too high compared to the best energy obtained so far, restarting randomly, etc.
### 
1. Boltzmann factor can be used as probability between two state.(代价函数,接受准则)


# My project
1. Implement simulated annealing in c++ using generic programming and object-oriented programming
2. Choose TSP problem and implement in c++
3. Fixed memory error in code
4. Batch run the program and analysis the simulated annealing algorithm in solving NP-complete problem.
5. Monte Carlo time step??? 
6. draw figure in R
7. draw 10 configuration (for p=0.9999)
## Thinking-The relationship between Monte Carlo simulatioin and simulated annealing
1. tempering techniques, more efficient Monte Carlo algorithms
2. Sometimes, an optimization problem can also be formulated as a Monte Carlo sampling problem.
3. SA is an optimization method, not simulation method.
4. The temperature parameter

[1]: https://en.wikipedia.org/wiki/Simulated_annealing
[2]: Monte Carlo Strategies in Scitific Computing. we are interested in finding the minimum of a target function, h(x), defined on a possibly complex configuration space. when T is sufficiently small, resulting random draws will most likely be located in the vicinity of the global minimum of h(x).


