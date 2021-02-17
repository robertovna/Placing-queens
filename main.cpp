#include "Header.h"

int main()
{
	//Desk size
	int n = 8;
	std::vector<int> solution;
	time_t start = clock();
	///********************Genetic Algorithm Solution
	Genetic_alg g(n,100);
	g.solve(solution);

	//********************Annealing emulation algorithm
	//Sim_annealing s(n);
	//s.solve(solution);

	//********************Algorithm with DFS BFS
	//solution_dfs(n,solution);
	//solution_bfs(n, solution);

	std::cout  << "Time : "<< double(clock() - start) / CLOCKS_PER_SEC<<"\n";
	pretty_print(solution);
	
}

//   |   |   |   |   |   | Q |   |   |   |
//________________________________________
//   |   |   |   |   |   |   |   | Q |   |
//________________________________________
//   |   |   | Q |   |   |   |   |   |   |
//________________________________________
//   |   |   |   |   | Q |   |   |   |   |
//________________________________________
// Q |   |   |   |   |   |   |   |   |   |
//________________________________________
//   |   |   |   |   |   |   |   |   | Q |
//________________________________________
//   | Q |   |   |   |   |   |   |   |   |
//________________________________________
//   |   |   |   | Q |   |   |   |   |   |
//________________________________________
//   |   | Q |   |   |   |   |   |   |   |
//________________________________________
//   |   |   |   |   |   |   | Q |   |   |
//________________________________________