#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"

int main(int argc, char**argv) {
	Simulation S ({new Generation({"a","b","a","a","b","a","c","b"})});
	S.printTerminal();
	std::cout << "tout va mal" << std::endl;
	S.createNewGeneration();
	S.printTerminal();
	return 0;
}
