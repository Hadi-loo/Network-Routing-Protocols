# CN_CHomeworks3

This repo is a simulation of two routing protocols, distance vector and link state coded with c++.

## How to run
run the following commands in terminal:
```
make
./main.out
```

## Commands

### Topology
This command can be used to define the topology of the network.
```
topology s1-d1-c1 s2-d2-c2 s3-d3-c3 ...
```

### Show
This command can be used to view the adjacency matrix of the network.
```
show
```

### Remove s-d
This command can be used to remove an edge from two nodes
```
remove s1-s2
```

### Modify s-d-c
This command can be used to modify the cost of and edge
```
modify s-d-c
```
