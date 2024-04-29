class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        graph = [[] for _ in range(n)]
        
        for u,v,w in times:
            graph[u - 1].append((w,v - 1))
        
        heap = []
        dist = [-1]*n
        for i in range(n):
            if i == k - 1:
                heap.append((0,i))
                dist[i] = 0
            else:
                dist[i] = 100*100+1
        
        heapq.heapify(heap)
        spt = set()
        s = 0
        
        while True:
            if len(heap) == 0:
                return -1
            _,u = heapq.heappop(heap)
            if u in spt:
                continue
            
            for w,v in graph[u]:
                if dist[v] >  w + dist[u]:
                    dist[v] = w + dist[u]
                    heapq.heappush(heap,(dist[v],v))
            spt.add(u)
            s+=1
            if s == n:
                return dist[u]
        
        return -1
        