#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"
#include "Experiment.hpp"

int main(int argc, char**argv) {
	Simulation S ({new Generation({"a","a","a","a","a","a","a","b"})});
	S.printTerminal();
	std::cout << "tout va mal" << std::endl;
	for (int i(0); i < 6 ; ++i) {
		S.createNewGeneration();
	}
	S.printTerminal();
	
	
	std::vector<int> markers= std::vector<int>{3,4};
	std::vector<Simulation*> sim=std::vector<Simulation*>{new Simulation(markers), new Simulation(markers), new Simulation(markers)};
	Experiment exp(sim);
	
	exp.runall(10);
	
	return 0;
}
