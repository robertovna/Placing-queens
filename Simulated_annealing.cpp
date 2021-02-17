#include "Header.h"

double Sim_annealing::less_temp(double t)
{
	return init_temp * 0.1 / t;
}

double Sim_annealing::Probability(int diff_energy, double T)
{
	return 1 / (exp(diff_energy / T));
}

void Sim_annealing::new_desk()
{
	std::srand(unsigned(std::time(0)));
	desk.clear();
	for (int i = 0; i < desk_size; i++)
		desk.push_back((1 + rand() % desk_size));
}

void Sim_annealing::mutate(std::vector<int>& v)
{
	int c = std::rand() % desk_size;
	int l = 1 + std::rand() % desk_size;
	v[c] = l;
}

void Sim_annealing::solve(std::vector<int>& solution)
{
	if (desk_size<=4)
	{
		std::cout << "No Solution:(";
		return;
	}
	new_desk();
	std::srand(unsigned(std::time(0)));
	double T = init_temp;
	solution = desk;
	std::vector<int> curr(desk);
	for (int t = 0; t < t_max; t++)
	{
		if (T <= end_temp)
			return;
		solution = curr;
		mutate(solution);
		int e_old = not_attack_count(curr);
		int e_new = not_attack_count(solution);
		if (attack_count(solution) == 0)
		{
			std::cout << t << '\n';
			return;
		}
		int diff_energy = e_new - e_old;
		if (diff_energy > 0 || Probability(diff_energy, T) >= (double)(rand()) / RAND_MAX)
			curr = solution;
		T = less_temp(t);
	}
}