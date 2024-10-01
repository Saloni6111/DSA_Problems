import heapq 

def minRefuelStops(target, startFuel, stations):
    h = []  # A max heap (simulated using negative values because Python has a min-heap by default)
    output = 0  # keeps track of the number of refueling stops
    prev = 0   # keeps track of the previous position the car has been at (initially the start at 0 miles)
    fuel = startFuel   # remaining fuel in the car, initially set to startFuel
    # The last "station" is actually the target itself with 0 fuel.
    for distance, gas in stations + [[target, 0]]:
      
        fuel -= distance - prev
        # refuel from the largest available fuel station (using max heap)
        while h and fuel < 0:
            # Pop the largest fuel available from the heap
            fuel += -heapq.heappop(h)
            output += 1
        # If fuel is still negative, even after using all available refuels, it's impossible to reach
        if fuel < 0:
            return -1
        # Push the current station's fuel into the heap (as negative to simulate max heap behavior)
        heapq.heappush(h, -gas)
        prev = distance
    return output

if __name__ == "__main__":
    
    # Testcase: 01
    target = 1
    startFuel = 1
    stations = []
    result = minRefuelStops(target, startFuel, stations)
    print(result) # Expected output: 0
    
    # Testcase: 02
    target = 100
    startFuel = 1
    stations = [[10,100]]
    result = minRefuelStops(target, startFuel, stations)
    print(result) # Expected output: -1
    
    # Testacase: 03
    target = 100
    startFuel = 10
    stations = [[10,60],[20,30],[30,30],[60,40]]
    result = minRefuelStops(target, startFuel, stations)
    print(result) # Expected output: 2
