import heapq
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    traversal_order = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            traversal_order.append(node)
            queue.extend(graph.get(node, []))  # Add unvisited neighbors

    return traversal_order


def dfs(graph, start):
    visited = set()
    stack = [start]
    traversal_order = []

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            traversal_order.append(node)
            stack.extend(reversed(graph.get(node, [])))  # Reverse to maintain correct order

    return traversal_order


def prims(graph):
    if not graph:
        return [], 0  # Return empty MST if the graph is empty

    start_node = next(iter(graph))  # Pick an arbitrary start node
    mst_edges = []
    total_cost = 0
    visited = set()

    # Min heap to store edges based on weight
    min_heap = [(0, start_node, None)]  # (cost, node, parent)
    
    while min_heap:
        cost, node, parent = heapq.heappop(min_heap)
        
        if node in visited:
            continue

        visited.add(node)
        if parent is not None:
            mst_edges.append((parent, node, cost))
            total_cost += cost

        for neighbor_cost, neighbor in graph.get(node, []):
            if neighbor not in visited:
                heapq.heappush(min_heap, (neighbor_cost, neighbor, node))

    return mst_edges, total_cost


class DisjointSet:
    def __init__(self, vertices):
        self.parent = {v: v for v in vertices}
        self.rank = {v: 0 for v in vertices}

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])  # Path compression
        return self.parent[v]

    def union(self, v1, v2):
        root1, root2 = self.find(v1), self.find(v2)
        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

def kruskal(graph):
    edges = []
    for node in graph:
        for cost, neighbor in graph[node]:
            if (neighbor, node, cost) not in edges:  # Avoid duplicate edges
                edges.append((cost, node, neighbor))

    edges.sort()  # Sort edges by weight
    vertices = list(graph.keys())
    ds = DisjointSet(vertices)

    mst_edges = []
    total_cost = 0

    for cost, node1, node2 in edges:
        if ds.find(node1) != ds.find(node2):
            ds.union(node1, node2)
            mst_edges.append((node1, node2, cost))
            total_cost += cost

    return mst_edges, total_cost


def bellman_ford(graph, vertices, start):
    # Step 1: Initialize distances
    INF = float('inf')
    distance = {i: INF for i in range(vertices)}
    distance[start] = 0

    # Step 2: Relax all edges |V| - 1 times
    for _ in range(vertices - 1):
        for u, v, weight in graph:
            if distance[u] != INF and distance[u] + weight < distance[v]:
                distance[v] = distance[u] + weight

    # Step 3: Check for negative-weight cycles
    for u, v, weight in graph:
        if distance[u] != INF and distance[u] + weight < distance[v]:
            raise ValueError("Graph contains a negative-weight cycle")

    return distance



def dijkstra(graph, vertices, start):
    INF = float('inf')
    distance = {i: INF for i in range(vertices)}
    distance[start] = 0
    priority_queue = [(0, start)]  # Min-heap (distance, node)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # If current distance is greater than known distance, skip processing
        if current_distance > distance[current_node]:
            continue

        for neighbor, weight in graph.get(current_node, []):
            new_distance = current_distance + weight
            if new_distance < distance[neighbor]:  # Relaxation step
                distance[neighbor] = new_distance
                heapq.heappush(priority_queue, (new_distance, neighbor))

    return distance



def a_star(graph, vertices, start, goal, heuristic):
    INF = float('inf')
    distance = {i: INF for i in range(vertices)}
    distance[start] = 0

    priority_queue = [(heuristic[start], 0, start, [])]  # (f(n), g(n), node, path)
    
    while priority_queue:
        _, g_n, current_node, path = heapq.heappop(priority_queue)
        path = path + [current_node]

        if current_node == goal:
            return distance[goal], path  # Shortest distance and path
        
        for neighbor, weight in graph.get(current_node, []):
            new_g_n = g_n + weight
            f_n = new_g_n + heuristic.get(neighbor, INF)  # f(n) = g(n) + h(n)

            if new_g_n < distance[neighbor]:  # Relaxation step
                distance[neighbor] = new_g_n
                heapq.heappush(priority_queue, (f_n, new_g_n, neighbor, path))

    return INF, []  # No path found
