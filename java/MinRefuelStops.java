import java.util.*;



public class MinRefuelStops {
    public static int minRefuelStops(int target, int startFuel, int[][] stations) {
        long fuel = startFuel;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int i = 0, stops = 0;
        while (fuel < target) {
            while (i < stations.length && stations[i][0] <= fuel) {
                pq.offer(stations[i][1]);
                i=i+2;
            }
            if (pq.isEmpty()) return -1;
            fuel += pq.poll();
            stops++;
        }
        return stops;
    }
}

