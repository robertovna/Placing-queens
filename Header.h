#ifndef TASK
#define TASK

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>
#include <queue>

int attack_count(const std::vector<int>& desk);
int not_attack_count(const std::vector<int>& desk);
void pretty_print(const std::vector<int>& v);

void solution_dfs(int n, std::vector<int>& solution);
void solution_bfs(int n, std::vector<int>& solution);

class Sim_annealing
{
	std::vector<int> desk;
	int desk_size;
	double init_temp;
	double end_temp;
	int t_max;

	double less_temp(double t);
	double Probability(int diff_energy, double T);
	void new_desk();
	void mutate(std::vector<int>& v);

public:
	Sim_annealing(int n = 8, double init_t = 100, double end_t = 0.0000000001, int time_max = 1000000000) :init_temp(init_t), end_temp(end_t), desk_size(n), t_max(time_max) {}
	void solve(std::vector<int>& solution);
};


class Genetic_alg
{
	std::vector<std::vector<int>> population;
	int population_size;
	int desk_size;

	int fitness_func(const std::vector<int>& v);
	void new_population();
	void reproduce(const std::vector<int>& x, const std::vector<int>& y, std::vector<int>& child);
	void mutate(std::vector<int>& v);
	void random_selection(std::vector<int>& x, std::vector<int>& y);

public:
	Genetic_alg(int n=8, int pop_size = 5) :desk_size(n), population_size(pop_size) 
	{
		population.resize(population_size);
	}
	void solve(std::vector<int>& solution);
};
#endif
