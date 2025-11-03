### Problem: Robot Tour Optimization 

Input: A set S of n points in the plane.

Output: What is the shortest cycle tour that visits each point in the set S?

### Nearest Neighbor Heuristic 

### 
~~~
NearestNeighbor(P)
Pick and visit an initial point p0 from P
p = p0
i = 0
While there are still unvisited points
i = i + 1
Select pi to be the closest unvisited point to pi−1
Visit pi
Return to p0 from pn−1
~~~


### Closest Pair Heuristic 

~~~
ClosestPair(P)
Let n be the number of points in set P.
For i = 1 to n − 1 do
d = ∞
For each pair of endpoints (s, t) from distinct vertex chains
if dist(s, t) ≤ d then sm = s, tm = t, and d = dist(s, t)
Connect (sm, tm) by an edge
Connect the two endpoints by an edge
~~~

Since this heuristic is always looking for the shorter path between points available to make a connection, it will not give the best possible output for a scenario like this:


<img width="1341" height="334" alt="image" src="https://github.com/user-attachments/assets/9aee93d4-1062-4360-acb0-b0ca88ad17ac" />


The image to the left is the optimal scenario, while the right is the solution the closest pair heuristic comes with. Below, the non optimal solution is blue, and the optimal solution is red, you can see that for most part of the function values, red is faster than blue. 


<img width="1333" height="737" alt="image" src="https://github.com/user-attachments/assets/599aaa19-9912-45af-94a4-f009c10d1d1f" />
