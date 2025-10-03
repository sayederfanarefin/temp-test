import pytest
from src.min_refuel import min_refuel_stops

def test_no_stations_but_enough_start():
    assert min_refuel_stops(250, 300, []) == 0

def test_cannot_reach_first_station():
    assert min_refuel_stops(100, 9, [[10, 100]]) == -1

def test_many_small_stations_cumulative():
    # Need to take each small station to reach the target
    stations = [[5,4],[9,4],[13,4],[17,4],[21,4]]
    assert min_refuel_stops(25, 5, stations) == 5

def test_greedy_choose_largest_reachable():
    # Best is to take the 60 at 10, then 60 at 60 -> 2 stops
    stations = [[10,60],[20,30],[30,30],[60,60]]
    assert min_refuel_stops(130, 10, stations) == 2

def test_regression_skip_every_other_station_bug():
    stations = [[10,5],[15,10]]
    assert min_refuel_stops(20, 10, stations) == 2

def test_large_values_no_overflow():
    assert min_refuel_stops(10**6, 10**6, []) == 0

def test_tight_chain_exact_zero_at_end():
    stations = [[10,10],[20,10],[30,10]]
    # start=10: reach 10 refuel->20 reach 20 refuel->30 reach 30 refuel->40 reach 40 target with 0
    assert min_refuel_stops(40, 10, stations) == 3

@pytest.mark.parametrize(
    "target,startFuel,stations,ans",
    [
        (50, 25, [[25,10],[35,10],[45,10]], 2),
        (70, 10, [[10,30],[20,20],[30,20],[40,20]], 3),
        (200, 100, [[100,1],[150,50],[160,40],[170,30]], 2),
        (300, 1, [], -1),
    ],
)
def test_more_cases(target, startFuel, stations, ans):
    assert min_refuel_stops(target, startFuel, stations) == ans
