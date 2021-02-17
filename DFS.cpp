#include "Header.h"

int attack_count(const std::vector<int>& desk)
{
	int count = 0;
	for (int i = 0; i < desk.size(); i++)
		for (int k = i + 1; k < desk.size(); k++)
			if ((abs(desk[i] - desk[k]) == k - i) || desk[i] == desk[k])
				count += 1;
	return count;
};

int not_attack_count(const std::vector<int>& desk)
{
	int n = desk.size();
	int sum = (1 + (n - 1)) / 2 * (n - 1);
	return sum - attack_count(desk);
};

void pretty_print(const std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int k = 0; k < v.size(); k++)
		{
			if (v[v.size() - 1 - i] != (k + 1))
				std::cout << "   |";
			else
				std::cout << " Q |";
		}
		std::cout << "\n";
		for (int k = 0; k < v.size(); k++)
			std::cout << "____";
		std::cout << "\n";
	}

};


void solution_dfs(int n, std::vector<int> & solution)
{
	if (n <= 4)
	{
		std::cout << "No Solution:(";
		return;
	}
	std::stack<std::vector<int>> stack;
	solution.clear();
	stack.push(solution);
	while (!stack.empty())
	{
		solution = stack.top();
		stack.pop();
		if (solution.size() < n)
		{
			solution.push_back(0);
			for (int i = 0; i < n; i++)
			{
				solution[solution.size()-1] = i+1;
				if (solution.size() == n)
				{
					if (attack_count(solution) == 0)
						return;
				}
				else stack.push(solution);
			}
		}
	}
}


void solution_bfs(int n, std::vector<int>& solution)
{
	if (n <= 4)
	{
		std::cout << "No Solution:(";
		return;
	}
	std::queue<std::vector<int>> q;
	solution.clear();
	q.push(solution);
	while (!q.empty())
	{
		solution = q.front();
		q.pop();
		if (solution.size() < n)
		{
			solution.push_back(0);
			for (int i = 0; i < n; i++)
			{
				solution[solution.size() - 1] = i + 1;
				if (solution.size() == n)
				{
					if (attack_count(solution) == 0)
						return;
				}
				else q.push(solution);
			}
		}
	}
}