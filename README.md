# Network Routing Protocols

This repo contains a simulation of two famous routing protocols, **Distance Vector(DVRP)** and **Link State(LSRP)** coded with c++.

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

### lsrp
By using this command, the LSRP routing algorithm will be run through the network. if the source node are given as an argument, the algorithm works on that node, otherwise, the algorithm runs for every node in the network.   
   
LSRP is an algorithm used in scheduling problems to determine the order in which tasks should be processed. The goal is to minimize the overall delay or completion time of all tasks. In LSRP, the task with the least slack, which is the difference between the task's deadline and its execution time, is given the highest priority. By prioritizing tasks with less slack, LSRP aims to reduce the chance of missing deadlines and optimize overall performance.
```
lsrp s
```
![image](https://github.com/Hadi-loo/CN_CHomeworks_3/assets/88896798/0337c59b-2270-463a-91bf-2258ec3acd5f)


### dvrp
By using this command, the DVRP routing algorithm will be run through the network. if the source node are given as an argument, the algorithm works on that node, otherwise, the algorithm runs for every node in the network.   
     
DVRP is a variant of the Vehicle Routing Problem (VRP) that deals with dynamically changing conditions, such as real-time traffic or varying customer demands. The objective of DVRP is to optimize the routes and schedules for a fleet of vehicles to efficiently serve a set of customers. It involves making real-time decisions on vehicle assignment, route planning, and scheduling to minimize costs, such as fuel consumption or total travel time, while satisfying customer requirements. DVRP algorithms typically consider factors like current vehicle locations, customer requests, and traffic information to dynamically adjust the routes and schedules of vehicles in response to changing conditions.
```
dvrp s
```
![image](https://github.com/Hadi-loo/CN_CHomeworks_3/assets/88896798/26a6b043-51c5-4c3c-be86-e8c4cc695840)


## Evaluation:
The evaluation is done on the topolgy which is show below:   
LVRP on all nodes runtime: 1.97836e+06 ns   
DVRP on all nodes runtime: 224588 ns     
![image](https://github.com/Hadi-loo/CN_CHomeworks_3/assets/88896798/1ec343f0-ef4e-43de-ad02-e193850adb15)


Now we make a change into the topology, we omit the link between nodes 4 and 10, then we measure runtimes again:   
LVRP on all nodes runtime: 864461 ns   
DVRP on all nodes runtime: 210529 ns   
![image](https://github.com/Hadi-loo/CN_CHomeworks_3/assets/88896798/43d50729-321a-4650-9306-8dc01c6b6be2)


In both scenarios, DVRP works faster than LVRP.     
Note that in measuring the runtime of each algorithm, we didn't measured the print operations time, because it may result in high errors in the measured times, as the output of the LVRP is much more than DVRP. 

