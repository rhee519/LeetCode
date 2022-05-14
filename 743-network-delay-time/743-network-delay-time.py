class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        heap, dist = [], [-1 for _ in range(n+1)]
        visited = set()
        adj = {i: {} for i in range(1, n+1)}
        
        
        for u, v, cost in times:
            adj[u][v] = cost
        # print(adj)
        # dijkstra
        dist[k] = 0
        heapq.heappush(heap, (dist[k], k))
        
        while heap:
            distance, u = heapq.heappop(heap)
            # dist[u] is fixed
            # if 0 <= dist[u] < distance:
            #     continue
            for v in adj[u]:
                if dist[v] == -1 or dist[v] > dist[u]+adj[u][v]:
                    dist[v] = dist[u]+adj[u][v]
                    heapq.heappush(heap, (dist[v], v))
                
        
        # print(dist[1:])
        # print("------------")
        return -1 if -1 in dist[1:] else max(dist)