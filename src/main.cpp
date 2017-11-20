#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"
#include "Experiment.hpp"
#include <vector>
#include <tclap/CmdLine.h>
using namespace TCLAP;


int main( int argc, char **argv ) {
	
	
	std::vector<int> markers;
	
	try{
		CmdLine cmd( "Ask the marker site to the user" );

		MultiArg< int > markersPositions( "m", "markers", "Give me the markers positions", false, "int" ); 
		cmd.add(markersPositions);
		cmd.parse(argc,argv);
		for (auto n : markersPositions.getValue()) {markers.push_back(n);}
	} catch(TCLAP::ArgException &e) {std::cerr << "ERROR: " << e.error() << " for arg " << e.argId() << std::endl;}
	
	
	try{
		Simulation S(markers);
		 
		S.printTerminal();
		for (int i(0); i < 6 ; ++i) {
			S.createNewGeneration();
		}
		S.printTerminal();
		
			
		std::vector<Simulation*> sim=std::vector<Simulation*>{new Simulation(markers), new Simulation(markers), new Simulation(markers)};
		Experiment exp(sim);
		
		exp.runall(10);
	
	} catch(string& e){
		std::cerr << e << std::endl;
		return 1;
		}
	
	return 0;
}
