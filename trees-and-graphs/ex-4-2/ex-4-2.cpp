#include <vector>
#include <set>
#include <iostream>


bool hasPath(std::vector<std::vector<int>>& graph, std::set<int>& visited, int from, int to)
{
	visited.insert(from);

	if (from == to)
		return true;

	auto children = graph[from];
	for (auto& c: children)
	{
		if (visited.find(c) == visited.end() && hasPath(graph, visited, c, to))
			return true;
		
	}
	return false;
}

int main()
{
	std::vector<std::vector<int>> graph = { {1,2}, {3}, {0}, {0} };
	std::set<int> visited;

	std::cout << hasPath(graph, visited, 0, 3) << std::endl;

	return 0;
}