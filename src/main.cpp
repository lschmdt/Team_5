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
		
		/*ValueArg<int> nb_alleles("n", "number_alleles", "Give me a number of alleles", false, "int");
		cmd.add(nb_alleles);*/
	
		MultiArg<double> frequencies("f", "frequencies", "Give me some frequencies", false, "double");
		cmd.add(frequencies);
		cmd.parse(argc, argv);
	
		for (auto f : frequencies.getValue()) {freq.push_back(f);}
		for (auto n : markersPositions.getValue()) {markers.push_back(n);}
		//assert((int)freq.size() == nb_alleles.getValue()); 
		
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
		
		exp.runall(300);
	
	} catch(std::string& e){
		std::cerr << e << std::endl;
		return 1;
		}
	
	return 0;
}
