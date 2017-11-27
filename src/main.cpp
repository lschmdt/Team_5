#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"
#include "Experiment.hpp"
#include <vector>
#include <tclap/CmdLine.h>
using namespace TCLAP;


int main( int argc, char **argv ) {
	
	
	std::vector<int> markers;
	std::vector<double> freq;
	
	try{
		CmdLine cmd( "Ask the marker site to the user" );

		MultiArg< int > markersPositions( "m", "markers", "Give me the markers positions", false, "int" ); 
		cmd.add(markersPositions);
		
		MultiArg<int> nb_alleles("n", "number_alleles", "Give me a number of alleles", false, "int");
		cmd.add(nb_alleles);
	
		MultiArg<double> frequencies("f", "frequencies", "Give me some frequencies", false, "double");
		cmd.add(frequencies);
		cmd.parse(argc, argv);
	
		for (auto f : frequencies.getValue()) {freq.push_back(f);}
		for (auto n : markersPositions.getValue()) {markers.push_back(n);}
		//assert((int)freq.size() == nb_alleles.getValue()); 
		
	} catch(TCLAP::ArgException &e) {std::cerr << "ERROR: " << e.error() << " for arg " << e.argId() << std::endl;}
	

	
	try{
	
		if (markers.empty())
		{
			Simulation S1(freq); 
			
			S1.printTerminal();	
			for (int i(0); i < 6 ; ++i) {
				S1.createNewGeneration();
			}
			S1.printTerminal();
			std::vector<Simulation*> sim1 = std::vector<Simulation*> {new Simulation(freq), new Simulation(freq), new Simulation(freq)};
			
			Experiment exp(sim1);
			exp.runall(300);
		} else {
			Simulation S2(markers);
			
			S2.printTerminal();	
			for (int i(0); i < 6 ; ++i) {
				S2.createNewGeneration();
			}
			S2.printTerminal();
			
			std::vector<Simulation*> sim2 = std::vector<Simulation*>{new Simulation(markers), new Simulation(markers), new Simulation(markers)};	
		
			Experiment exp(sim2);
			exp.runall(300);
		}

	} 
	
	
	
	catch(std::string& e){
		std::cerr << e << std::endl;
		return 1;
		}
	
	return 0;
}
