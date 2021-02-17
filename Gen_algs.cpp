#include "Header.h"


void Genetic_alg::solve(std::vector<int>& solution)
{
	if (desk_size <= 4)
	{
		std::cout << "No Solution:(";
		return;
	}
	new_population();
	std::srand(unsigned(std::time(0)));
	std::vector<int> x, y, child;
	std::vector<std::vector<int>> population_;
	x.resize(desk_size);
	y.resize(desk_size);
	child.resize(desk_size);
	population_.resize(population_size);
	int k = 0;
	do {
		for (int i = 0; i < population_size; i++)
		{
			random_selection(x, y);
			reproduce(x, y, child);
			mutate(child);
			population_[i]=child;
			if (attack_count(child) == 0)
			{
				solution = child;
				//std::cout << i<<'\n';
				return;
			}
		}
		k++;
		population = population_;
	} while (true);
}

int Genetic_alg::fitness_func(const std::vector<int>& v)
{
	return not_attack_count(v);
}

void Genetic_alg::new_population()
{
	std::vector<int> v;
	v.resize(desk_size);
	for (int i = 0; i < population_size; i++)
	{
		for (int i = 0; i < desk_size; i++)
			v[i]=(1 + rand() % desk_size);
		population[i]=v;
	}
}

void Genetic_alg::reproduce(const std::vector<int>& x, const std::vector<int>& y, std::vector<int>& child)
{
	int c = 1 + std::rand() % (desk_size - 1);
	auto it = std::copy(x.begin(), x.begin() + c + 1, child.begin());
	std::copy(y.begin() + c + 1, y.end(), it);
}

void Genetic_alg::mutate(std::vector<int>& v)
{
	int c = std::rand() % desk_size;
	int l = 1 + std::rand() % desk_size;
	v[c] = l;
}

void Genetic_alg::random_selection(std::vector<int>& x, std::vector<int>& y)
{
	int c = std::rand() % population_size;
	x = population[c];
	int diff = 1000;
	for (int i = 0; i < population_size; i++)
	{
		int n = abs(fitness_func(x) - fitness_func(population[i]));
		if (n < diff && n != 0)
		{
			y = population[i];
			diff = n;
		}
	}
}