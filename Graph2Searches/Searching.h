#pragma once
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
class Searching
{
public:
	Searching();
	~Searching();
	void DepthFirstPrintIterative(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string source);
	void DepthFirstPrintRecursive(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string source);
	void BreadthFirstPrint(std::unordered_map<std::string, std::vector<std::string>>&graph, std::string source);
private:

};

Searching::Searching()
{
}

Searching::~Searching()
{
}

void Searching::DepthFirstPrintIterative(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string source) {
	std::stack<std::string> stack;
	stack.push(source);
	while (stack.size() > 0)
	{
		std::string current = stack.top();
		stack.pop();
		std::cout << current << "\n";
		for (auto it : graph[current])
		{
			stack.push(it);
		}
	}
}
void Searching::DepthFirstPrintRecursive(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string source) {

	std::cout << source << "\n";
	for (auto neighbour : graph[source])
	{
		DepthFirstPrintRecursive(graph, neighbour);
	}
}
void Searching::BreadthFirstPrint(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string source) {
	std::deque<std::string> queue;
	queue.push_front(source);
	while (queue.size() > 0)
	{
		std::string current = queue.front();
		queue.pop_front();
		std::cout << current << '\n';
		for (auto neighbour : graph[current])
		{
			queue.push_back(neighbour);
		}
	}
}