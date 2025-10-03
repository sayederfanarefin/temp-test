import pytest
from src.min_refuel import min_refuel_stops

def test_example_1():
    assert min_refuel_stops(target=1, startFuel=1, stations=[]) == 0

def test_example_2():
    assert min_refuel_stops(target=100, startFuel=1, stations=[[10,100]]) == -1

def test_example_3():
    stations = [[10,60],[20,30],[30,30],[60,40]]
    assert min_refuel_stops(target=100, startFuel=10, stations=stations) == 2

def test_exact_fuel_arrival():
    assert min_refuel_stops(10, 10, []) == 0
    assert min_refuel_stops(10, 5, [[5,5]]) == 1

def test_zero_length_stations_possible():
    assert min_refuel_stops(20, 10, [[10, 10]]) == 1

def test_unreachable_due_to_gap():
    assert min_refuel_stops(100, 50, [[60,50]]) == -1

def test_multiple_choices_greedy_needed():
    stations = [[10,10],[20,50],[30,10],[60,60]]
    assert min_refuel_stops(120, 25, stations) == 2

def test_large_fuel_single_station_far():
    stations = [[50, 1000]]
    assert min_refuel_stops(600, 100, stations) == 1

@pytest.mark.parametrize(
    "target,startFuel,stations,ans",
    [
        (1, 2, [], 0),
        (100, 50, [[25,25],[50,25],[75,25]], 2),
        (200, 50, [[50,50],[100,50],[150,50]], 3),
        (300, 60, [[60,60],[120,60],[180,60],[240,60]], 4),
    ],
)
def test_parametrized(target, startFuel, stations, ans):
    assert min_refuel_stops(target, startFuel, stations) == ans
