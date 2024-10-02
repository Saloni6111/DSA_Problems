import heapq
from typing import List

def minRefuelStops(target: int, startFuel: int, stations: List[List[int]]) -> int:
    """
    Calculate the minimum number of refueling stops needed to reach the target.
    
    Args:
    target (int): The distance to the target.
    startFuel (int): The initial amount of fuel in the car.
    stations (List[List[int]]): A list of stations, where each station is represented
                                as [distance_from_start, fuel_available].
    
    Returns:
    int: The minimum number of refueling stops needed to reach the target.
         Returns -1 if it is impossible to reach the target.
    """
    # Sort the stations by their distance from the start
    stations.sort(key=lambda x: x[0])
    
    max_heap = []  # Max heap to store available fuel (as negative values)
    refuel_count = 0
    previous_distance = 0
    current_fuel = startFuel
    index = 0
    n = len(stations)
    
    while current_fuel < target:
        # Add all stations within the current fuel range to the heap
        while index < n and stations[index][0] <= current_fuel:
            heapq.heappush(max_heap, -stations[index][1])  # Push negative to simulate max heap
            index += 1
        
        if not max_heap:
            # No available stations to refuel from
            return -1
        
        # Refuel with the station that offers the most fuel
        current_fuel += -heapq.heappop(max_heap)
        refuel_count += 1
    
    return refuel_count

if __name__ == "__main__":
    # Testcase 01
    target = 1
    startFuel = 1
    stations = []
    result = minRefuelStops(target, startFuel, stations)
    print(result)  # Expected output: 0
    
    # Testcase 02
    target = 100
    startFuel = 1
    stations = [[10, 100]]
    result = minRefuelStops(target, startFuel, stations)
    print(result)  # Expected output: -1
    
    # Testcase 03
    target = 100
    startFuel = 10
    stations = [[10, 60], [20, 30], [30, 30], [60, 40]]
    result = minRefuelStops(target, startFuel, stations)
    print(result)  # Expected output: 2
