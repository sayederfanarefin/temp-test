import java.util.*;

public class MinRefuelStops {
    public static int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int fuel = startFuel;
        int stops = 0;
        int index = 0;

        while (fuel < target) {
            while (index < stations.length && stations[index][0] <= fuel) {
                maxHeap.offer(stations[index][1]);
                index++;
            }

            if (maxHeap.isEmpty()) {
                return -1;
            }

            fuel += maxHeap.poll();
            stops++;
        }

        return stops;
    }
}
