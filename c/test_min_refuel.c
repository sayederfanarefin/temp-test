#include <assert.h>
#include <stdio.h>

int min_refuel_stops(int target, int startFuel, int stations[][2], int n);

int main() {
    int (*st0)[2] = 0;
    assert(min_refuel_stops(1,1,st0,0) == 0);

    int st1[1][2] = {{10,100}};
    assert(min_refuel_stops(100,1,st1,1) == -1);

    int st2[4][2] = {{10,60},{20,30},{30,30},{60,40}};
    assert(min_refuel_stops(100,10,st2,4) == 2);

    int st3[4][2] = {{10,10},{20,50},{30,10},{60,60}};
    assert(min_refuel_stops(120,25,st3,4) == 2);

    printf("All C tests passed!\n");
    return 0;
}
