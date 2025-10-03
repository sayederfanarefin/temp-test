public class TestMinRefuelStops {
    public static void main(String[] args) {
        assert MinRefuelStops.minRefuelStops(1, 1, new int[][]{}) == 0;
        assert MinRefuelStops.minRefuelStops(100, 1, new int[][]{{10,100}}) == -1;
        int[][] st = {{10,60},{20,30},{30,30},{60,40}};
        assert MinRefuelStops.minRefuelStops(100, 10, st) == 2;
        int[][] st2 = {{10,10},{20,50},{30,10},{60,60}};
        assert MinRefuelStops.minRefuelStops(120, 25, st2) == 2;
        System.out.println("All Java tests passed!");
    }
}
