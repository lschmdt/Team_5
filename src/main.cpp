#include "Allele.hpp"
#include "Simulation.hpp"
#include "Generation.hpp"
#include "Experiment.hpp"
#include <vector>
#include <../tclap/CmdLine.h>
using namespace TCLAP;


int main( int argc, char **argv ) {
	
	
	/*std::vector<int> markers;
	std::vector<double> freq;
	std::vector<double> mutationParam;
	std::vector<double> mus;
	int generation;
	int replicate ;
	int pop;
	bool selection;
	bool sizeModification;
	bool mutate;
	
	
	try{
		CmdLine cmd( "Ask the marker site to the user" );

		MultiArg< int > markersPositions( "m", "markers", "Give me the markers positions", false, "int" ); 
		cmd.add(markersPositions);
		
		MultiArg<int> nb_alleles("n", "number_alleles", "Give me a number of alleles", false, "int");
		cmd.add(nb_alleles);
	
		MultiArg<double> frequencies("f", "frequencies", "Give me some frequencies", false, "double");
		cmd.add(frequencies);
		
		MultiArg<double> mutationParameters("mutParam", "mutation parameters", "Give me the mutations parameters", false, "double");
		cmd.add(mutationParameters);
		
		MultiArg<double> musCoefficientsMutation("mu", "coefficients mus", "Give me the mutation coefficients", false, "double");
		cmd.add(musCoefficientsMutation);
		
		SwitchArg selectionSwitch("selec", "selection", "Active the selection switch", cmd, false);
		SwitchArg sizeModifSwitch("size", "population size modification", "Active the population size modification switch", cmd, false);
		SwitchArg mutationSwitch("mutate","mutation", "Active the mutation switch", cmd, false);
		
        ValueArg<int> generations("g", "generations", "Give me an amount of generations required", false, 1, "int");
        cmd.add(generations);
		assert(generations.getValue()>=0);

        ValueArg<int> replicates("r", "replicates", "Give me an amount of replicates wanted", false, 1,"int");
        cmd.add(replicates);
        assert(replicates.getValue()>=0);

        ValueArg<int> populationsize("p", "populationsize", "Give me the size of the population", false, 1, "int");
        cmd.add(populationsize);

        assert(populationsize.getValue()>=0);
        
        cmd.parse(argc, argv);

        generation=(generations.getValue());
        
        replicate=(replicates.getValue());
        
        pop=(populationsize.getValue());
	
	
		for (auto f : frequencies.getValue()) {freq.push_back(f);}
		for (auto n : markersPositions.getValue()) {markers.push_back(n);}
		for (auto m : mutationParameters.getValue()) {mutationParam.push_back(m);}
		for (auto m : musCoefficientsMutation.getValue()) {mus.push_back(m);}
		for (auto m : musCoefficientsMutation.getValue()) {mus.push_back(m);}

		selection=(selectionSwitch.getValue());
		sizeModification=(sizeModifSwitch.getValue());
		mutate=(mutationSwitch.getValue());
		
		//assert((int)freq.size() == nb_alleles.getValue()); 
		
	} catch(TCLAP::ArgException &e) {std::cerr << "ERROR: " << e.error() << " for arg " << e.argId() << std::endl;}
	

	
	try{
	
		if (markers.empty())
		{
			Simulation S1(freq, selection, sizeModification, mutate); 
			
			S1.printTerminal();	
			for (int i(0); i < 6 ; ++i) {
				S1.createNewGeneration();
			}
			S1.printTerminal();
			
			std::vector<Simulation*> sim1 = std::vector<Simulation*> {new Simulation(freq, selection, sizeModification, mutate), new Simulation(freq, selection, sizeModification, mutate), new Simulation(freq, selection, sizeModification, mutate)};
			
			Experiment exp(sim1);
			exp.runall(300);
		} else {
			Simulation S2(markers, selection, sizeModification, mutate);
			
			S2.printTerminal();	
			for (int i(0); i < 6 ; ++i) {
				S2.createNewGeneration();
			}
			S2.printTerminal();
			
			std::vector<Simulation*> sim2 = std::vector<Simulation*>{new Simulation(markers, selection, sizeModification, mutate), new Simulation(markers, selection, sizeModification, mutate), new Simulation(markers, selection, sizeModification, mutate)};	
		
			Experiment exp(sim2);
			exp.runall(300);
		}

        //S.printTerminal();
        /*for (int i(0); i < generations ; ++i) {
            S.createNewGeneration();
        }
        S.printTerminal();*/
        
            
        //std::vector<Simulation*> sim=std::vector<Simulation*>{new Simulation(markers), new Simulation(markers), new Simulation(markers)};
      /*  std::vector<Simulation*> sim;
        for(int i(0);i<replicate;++i)
        {    if(!markers.empty())
            {    sim.push_back(new Simulation(markers, selection, sizeModification, mutate));
            } else {
            sim.push_back(new Simulation(freq, selection, sizeModification, mutate));
            }
        }
        Experiment exp(sim);
        
        exp.runall(generation);
    }
	
	catch(std::string& e){
		std::cerr << e << std::endl;
		return 1;
		}*/
	
	/* MAIN POUR TESTER MUTATION SUR 10 ALLELES ET 50 GENERATIONS
	 * 
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.5, 0.5, 0.5}), false,false, true);
	std::cout << "Fin construction simulation" << std::endl;

	for (int i(0); i < 50 ; ++i) {
		sim.createNewGeneration();
	}
	std::cout << "Fin create newGeneration" << std::endl;
	sim.printTerminal();*/
	
	//MAIN POUR TESTER LE CHANGEMENT DE TAILLE 
	 
	Simulation s ({0.5, 0.5, 0.5}, 100, false,true, false); 
	
	for (int i(0); i < 200 ; ++i) {
		s.createNewGeneration();
	}
	std::cout << "Fin create newGeneration" << std::endl;
	
	
	
	
	return 0;
}
