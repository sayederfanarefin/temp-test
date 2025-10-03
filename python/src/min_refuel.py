# python/src/min_refuel.py
from typing import List
import heapq

def min_refuel_stops(target: int, startFuel: int, stations: List[List[int]]) -> int:
    fuel = startFuel
    pq = []  # max-heap via negative values
    i = 0
    stops = 0
    n = len(stations)
    while fuel < target:
        while i < n and stations[i][0] <= fuel:
            heapq.heappush(pq, -stations[i][0])
            i += 1
        if not pq:  # no reachable station
            return -1
        fuel += -heapq.heappop(pq)
        stops += 1
    return stops
