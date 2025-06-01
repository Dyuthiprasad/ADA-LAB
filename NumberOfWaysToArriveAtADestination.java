import java.util.*;

class Solution {
    private static final int mod = 1_000_000_007;
    
    public int countPaths(int n, int[][] roads) {
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }

        long[] dist = new long[n];
        int[] ways = new int[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        pq.offer(new long[]{0, 0}); // {distance, node}

        while (!pq.isEmpty()) {
            long[] top = pq.poll();
            long d = top[0];
            int u = (int) top[1];

            if (d > dist[u]) continue; // Ignore outdated entries

            for (int[] neighbor : graph[u]) {
                int v = neighbor[0];
                long newDist = d + neighbor[1];

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.offer(new long[]{newDist, v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
}
