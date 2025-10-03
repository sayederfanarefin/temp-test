import java.util.*;

public class TestMinRefuelStops {
    public static void main(String[] args) {
        // LeetCode examples
        assert MinRefuelStops.minRefuelStops(1, 1, new int[][]{}) == 0;
        assert MinRefuelStops.minRefuelStops(100, 1, new int[][]{{10,100}}) == -1;
        int[][] st = {{10,60},{20,30},{30,30},{60,40}};
        assert MinRefuelStops.minRefuelStops(100, 10, st) == 2;

        // No stations but enough start
        assert MinRefuelStops.minRefuelStops(250, 300, new int[][]{}) == 0;

        // Cannot reach the first station
        assert MinRefuelStops.minRefuelStops(100, 9, new int[][]{{10,100}}) == -1;

        // Many small stations cumulative
        int[][] smalls = {{5,4},{9,4},{13,4},{17,4},{21,4}};
        assert MinRefuelStops.minRefuelStops(25, 5, smalls) == 5;

        // Greedy must pick largest reachable
        int[][] st2 = {{10,60},{20,30},{30,30},{60,60}};
        assert MinRefuelStops.minRefuelStops(130, 10, st2) == 2;

        // Regression: skipping every other station should fail
        int[][] stSkip = {{10,5},{15,10}};
        assert MinRefuelStops.minRefuelStops(20, 10, stSkip) == 2;

        // Large values
        assert MinRefuelStops.minRefuelStops(1_000_000, 1_000_000, new int[][]{}) == 0;

        // Tight chain ending exactly at zero
        int[][] chain = {{10,10},{20,10},{30,10}};
        assert MinRefuelStops.minRefuelStops(40, 10, chain) == 3;

        int[][] a2 = {{10,30},{20,20},{30,20},{40,20}};
        assert MinRefuelStops.minRefuelStops(70, 10, a2) == 3;

        int[][] a3 = {{100,1},{150,50},{160,40},{170,30}};
        assert MinRefuelStops.minRefuelStops(200, 100, a3) == 2;

        System.out.println("All Java tests passed!");
    }
}
