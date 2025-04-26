import heapq
import sys


def dijkstra(graph, start):
    n = len(graph)
    distances = [float('inf')] * n
    distances[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances


def find_best_city(n, roads):
    # Create a graph representation
    graph = [[] for _ in range(n)]

    for road in roads:
        a, b, l = road
        graph[a - 1].append((b - 1, l))  # Convert to 0-based index

    best_city = -1
    min_sum_distance = float('inf')

    for city in range(n):
        distances = dijkstra(graph, city)
        total_distance = sum(distances)

        if total_distance < min_sum_distance:
            min_sum_distance = total_distance
            best_city = city + 1  # Convert back to 1-based index

    return best_city, min_sum_distance


if __name__ == "__main__":
    input_data = input().strip().splitlines()
    n, m = map(int, input_data[0].split())

    roads = []
    for i in range(1, m + 1):
        a, b, l = map(int, input_data[i].split())
        roads.append((a, b, l))

    print(roads)
    best_city, min_sum_distance = find_best_city(n, roads)

    print(best_city, min_sum_distance)
