#include <assert.h>
#include <stdio.h>

int min_refuel_stops(int target, int startFuel, int stations[][2], int n);

int main() {
    // LeetCode examples
    int (*none)[2] = 0;
    assert(min_refuel_stops(1,1,none,0) == 0);

    int st1[1][2] = {{10,100}};
    assert(min_refuel_stops(100,1,st1,1) == -1);

    int st2[4][2] = {{10,60},{20,30},{30,30},{60,40}};
    assert(min_refuel_stops(100,10,st2,4) == 2);

    // No stations but enough start
    assert(min_refuel_stops(250,300,none,0) == 0);

    // Cannot reach first station
    int st3[1][2] = {{10,100}};
    assert(min_refuel_stops(100,9,st3,1) == -1);

    // Many small stations cumulative
    int smalls[5][2] = {{5,4},{9,4},{13,4},{17,4},{21,4}};
    assert(min_refuel_stops(25,5,smalls,5) == 5);

    // Greedy choose largest reachable
    int st4[4][2] = {{10,60},{20,30},{30,30},{60,60}};
    assert(min_refuel_stops(130,10,st4,4) == 2);

    // Regression: skipping every other station fails
    int stSkip[2][2] = {{10,5},{15,10}};
    assert(min_refuel_stops(20,10,stSkip,2) == 2);

    // Large values
    assert(min_refuel_stops(1000000,1000000,none,0) == 0);

    // Tight chain ending at zero
    int chain[3][2] = {{10,10},{20,10},{30,10}};
    assert(min_refuel_stops(40,10,chain,3) == 3);

    // More cases
    int a1[3][2] = {{25,10},{35,10},{45,10}};
    assert(min_refuel_stops(50,25,a1,3) == 2);

    int a2[4][2] = {{10,30},{20,20},{30,20},{40,20}};
    assert(min_refuel_stops(70,10,a2,4) == 3);

    int a3[4][2] = {{100,1},{150,50},{160,40},{170,30}};
    assert(min_refuel_stops(200,100,a3,4) == 2);

    printf("All C tests passed!\n");
    return 0;
}
