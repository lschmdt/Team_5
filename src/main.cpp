#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"
#include "Experiment.hpp"
#include <vector>
#include <tclap/CmdLine.h>
using namespace TCLAP;


int main( int argc, char **argv ) {
	
	
	std::vector<int> markers;
	
	CmdLine cmd( "Ask the marker site to the user" );

	MultiArg< double > numbers( "n", "numbers", "Give me some numbers", false, "double" ); 
	cmd.add(numbers);
	cmd.parse(argc,argv);
	for (auto n : numbers.getValue()) {markers.push_back(n);}
	
	Simulation S(markers);
	S.printTerminal();
	std::cout << "tout va mal" << std::endl;
	for (int i(0); i < 6 ; ++i) {
		S.createNewGeneration();
	}
	S.printTerminal();
	
		
	std::vector<Simulation*> sim=std::vector<Simulation*>{new Simulation(markers), new Simulation(markers), new Simulation(markers)};
	Experiment exp(sim);
	
	exp.runall(10);

	
	return 0;
}
