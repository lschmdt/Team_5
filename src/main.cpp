#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"

int main(int argc, char**argv) {
	Simulation S ({new Generation({"a","a","a","a","a","a","a","b"})});
	S.printTerminal();
	std::cout << "tout va mal" << std::endl;
	for (int i(0); i < 6 ; ++i) {
		S.createNewGeneration();
	}
	S.printTerminal();
	
		
	std::vector<int> markers= std::vector<int>{3,4,7};
	Simulation S2(markers);
	S2.printTerminal();
	S2.run(3);
	
	return 0;
}
