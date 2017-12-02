#include <iostream>
#include "../../src/Generation.hpp"
#include "../../src/Simulation.hpp"
#include "../../src/Allele.hpp"
#include "../../gtest/include/gtest/gtest.h"
#include <array>

using namespace std;

/*!Test if the table that readFromFile function returns contains the nucleotides choser by the marker site table
 * (test on the test.fa file)
 */
TEST (SimulationTest, readFromFile_) 
{
	Simulation sim(new Generation(true));
	ifstream inputFile;
	//inputFile.open("../test/test/test.fa");
	inputFile.open("../res/test.fa");
	
	vector<int> test = {0,2,4,6};
	vector<string> Alleles = sim.readFromFile(test, inputFile);
	
	EXPECT_EQ(Alleles[0], "TCAC");
	EXPECT_EQ(Alleles[1], "TCAC");
	EXPECT_EQ(Alleles[2], "TCTC");
	
	inputFile.close();	
}
TEST (SimulationTest, readFromFile_2) 
{	vector<int> test = {0,2,4,6};
	Simulation sim(test);
	Generation* gen(sim.getEvolutionPop().back());
	cout<<gen->getAlleles().size();
	/*	Here we verify that the allele sequence is not saved twice if it is 
	 * 	the same sequence.	*/
	EXPECT_EQ(gen->getAlleles()[0]->getSequence(), "TCAC");
	EXPECT_EQ(gen->getAlleles()[1]->getSequence(), "TCTC");
}

TEST (GenerationTest, sort) {
	Generation gen ({"aa","ca","aa","ca","aa","ta","ga","aa","ta","ta"});
	EXPECT_EQ(gen.getAlleles()[0]->getFrequency(), 4/10.);
	EXPECT_EQ(gen.getAlleles()[1]->getFrequency(), 2/10.);
	EXPECT_EQ(gen.getAlleles()[2]->getFrequency(), 3/10.);
	EXPECT_EQ(gen.getAlleles()[3]->getFrequency(), 1/10.);
}


TEST (SimulationTest, createNewGeneration_AncientGeneration) {
	Simulation S (new Generation ({"aa","ca","aa","ca","aa","ta","ga","aa","ta","ta"}));
	S.createNewGeneration();
	EXPECT_EQ(S.getEvolutionPop()[0]->getAlleles()[0]->getFrequency(), 4/10.);
	EXPECT_EQ(S.getEvolutionPop()[0]->getAlleles()[1]->getFrequency(), 2/10.);
	EXPECT_EQ(S.getEvolutionPop()[0]->getAlleles()[2]->getFrequency(), 3/10.);
	EXPECT_EQ(S.getEvolutionPop()[0]->getAlleles()[3]->getFrequency(), 1/10.);
}

TEST (SimulationTest, createNewGeneration_NewGeneration) {
	Simulation S (new Generation ({"aa","ca","aa","ca","aa","ta","ga","aa","ta","ta"}));
	S.createNewGeneration();
	double sum(0);
	for (size_t i (0); i < S.getEvolutionPop()[1]->getAlleles().size(); ++i) {
		sum += S.getEvolutionPop()[1]->getAlleles()[i]->getFrequency();
	}
	EXPECT_NEAR(sum, 1.0, 1e-9);
}

TEST (SimulationTest, CreateNewGeneration_averageFrequencies_shouldEqual_initialFrequencies) {
	
	std::array<double, 4> averageFreq = {{0, 0, 0, 0}}; //car 4 alleles dans ce cas precis
	
	int nbGen (10000);
	
	for (int i(0); i < nbGen ; ++i) {   //moyenne des frequences arbitrairement faite sur 10000 
									 
		Simulation S (new Generation ({"aa","ca","aa","ca","aa","ta","ga","aa","ta","ta"}));
		S.createNewGeneration();
		for (int j(0); j< 4 ; ++j) { 
			averageFreq[j]+= (S.getEvolutionPop()).back()->getAlleles()[j]->getFrequency();
		}
	}
	
	for (int k(0); k<4; ++k) {
		averageFreq[k] /= double(nbGen);
	}
	EXPECT_NEAR(averageFreq[0], 4/10., 0.02);
	EXPECT_NEAR(averageFreq[1], 2/10., 0.02);
	EXPECT_NEAR(averageFreq[2], 3/10., 0.02);
	EXPECT_NEAR(averageFreq[3], 1/10., 0.02);
}

TEST (SimulationTest, FitnessCoefficient_different) {

	Generation gen({"AAA", "CCC", "GGG", "TTT"});
	gen.setGenerationLength(10);
    
	gen.getAlleles()[0]->setFrequency(0.2);
	gen.getAlleles()[1]->setFrequency(0.2);
	gen.getAlleles()[2]->setFrequency(0.5);
	gen.getAlleles()[3]->setFrequency(0.1);
		
	gen.getAlleles()[0]->setFitness(0.1);
	gen.getAlleles()[1]->setFitness(0.3);
	gen.getAlleles()[2]->setFitness(0.8);
	gen.getAlleles()[3]->setFitness(-1);
	
	int nbSim(10);
	int nbGen(10000);
	double div_average(1/double(nbSim*nbGen));

	array<double, 3> averageFreq = {{0, 0, 0}}; 
	double SumFreqAlleleLethal(0);

 	for (int i(0); i< nbSim; ++i) {
		Simulation S (new Generation(gen), true);
		for (int j(0); j<nbGen ; ++j) {
			S.createNewGeneration();
			SumFreqAlleleLethal += S.getEvolutionPop().back()->getAlleles()[3]->getFrequency();
				for (int k(0); k<3; ++k) {
					 averageFreq[k]+= S.getEvolutionPop().back()->getAlleles()[k]->getFrequency();
				}
		}
	}
	
	for (size_t m(0); m < averageFreq.size(); ++m) {
		averageFreq[m] *= div_average;
	}
	
	EXPECT_EQ(SumFreqAlleleLethal, 0);
	EXPECT_TRUE(averageFreq[0] < averageFreq[1]);
	EXPECT_NEAR(averageFreq[2], 1, 0.02);

}

TEST (SimulationTest, FitnessCoefficient_equal) {

    int nbSim(5000);
    double div_nbSim(1/double(nbSim));
    double div_freq(1/double(10));
    array<double, 4> averageFreq = {{0, 0, 0, 0}}; 
    
	Generation gen({"AAA", "CCC", "GGG", "TTT"});
	gen.setGenerationLength(10);
	
	for(size_t i(0); i<4; ++i) {	
	   gen.getAlleles()[i]->setFrequency((4-i)*div_freq);
	   gen.getAlleles()[i]->setFitness(0.5);
	}
   
    for (int i(0); i < nbSim ; ++i) {   
        Simulation S (new Generation(gen),true);
	S.createNewGeneration();
		for (int j(0); j< 4 ; ++j) {
			averageFreq[j]+= (S.getEvolutionPop()).back()->getAlleles()[j]->getFrequency(); 
		}
    }

    for (int k(0); k<4; ++k) {
        averageFreq[k] *= div_nbSim;
    }

    EXPECT_NEAR(averageFreq[0], 4*div_freq, 0.02);
    EXPECT_NEAR(averageFreq[1], 3*div_freq, 0.02);
    EXPECT_NEAR(averageFreq[2], 2*div_freq, 0.02);
    EXPECT_NEAR(averageFreq[3], 1*div_freq, 0.02);
}



TEST (SimulationTest, MutationTestDifferentAllelesFelsenstein) {
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.3, 0.4, 0.2}, Felsenstein, {0.1, 0.4, 0.3}), false, false, true);

	for (int i(0); i < 200 ; ++i) {
		sim.createNewGeneration();
	}
	sim.printTerminal();
	
	bool same(false);

	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {	
			
		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			for (size_t k(0); k < sim.getEvolutionPop()[i]->getAlleles().size() ; ++k){
				if ( j!=k and sim.getEvolutionPop()[i]->getAlleles()[j]->getSequence() == sim.getEvolutionPop()[i]->getAlleles()[k]->getSequence())
				{ 
					same = true;
				}
			}
		}
	}
	EXPECT_EQ(false, same);
}

TEST (SimulationTest, MutationTestDifferentAllelesKimura) {
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.1, 0.05, 0.2}, Kimura, {0.7}), false, false, true);

	for (int i(0); i < 200 ; ++i) {
		sim.createNewGeneration();
	}
	sim.printTerminal();
	
	bool same(false);

	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {	

		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			for (size_t k(0); k < sim.getEvolutionPop()[i]->getAlleles().size() ; ++k){
				if ( j!=k and sim.getEvolutionPop()[i]->getAlleles()[j]->getSequence() == sim.getEvolutionPop()[i]->getAlleles()[k]->getSequence())
				{ 
					same = true;
				}
			}
		}
	}
	EXPECT_EQ(false, same);
}

TEST (SimulationTest, MutationTestDifferentAllelesJukesKantor) {
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.5, 0.5, 0.5}, JukesKantor), false, false, true);

	for (int i(0); i < 200 ; ++i) {
		sim.createNewGeneration();
	}
	sim.printTerminal();
	
	bool same(false);

	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {	
		

		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			for (size_t k(0); k < sim.getEvolutionPop()[i]->getAlleles().size() ; ++k){
				if ( j!=k and sim.getEvolutionPop()[i]->getAlleles()[j]->getSequence() == sim.getEvolutionPop()[i]->getAlleles()[k]->getSequence())
				{ 
					same = true;
				}
			}
		}
	}
	EXPECT_EQ(false, same);
}

TEST (SimulationTest, MutationTestFrequencySumFelsenstein) {
	/*cout << "SimulationTest" << endl;
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.5, 0.5, 0.5}), false, true);
	//std::cout << "Fin construction simulation" << std::endl;

	for (int i(0); i < 50 ; ++i) {
		sim.createNewGeneration();
	}
	//std::cout << "Fin create newGeneration" << std::endl;
	sim.printTerminal();
	
	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {
		double sum (0);
		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			sum += sim.getEvolutionPop()[i]->getAlleles()[j]->getFrequency();
		}
		EXPECT_NEAR(sum, 1.0, 1e-6);
	}*/
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.7, 0.8, 0.01}, Felsenstein, {0.1, 0.4, 0.3}), false, false, true);

	for (int i(0); i < 50 ; ++i) {
		sim.createNewGeneration();
	}
	
	sim.printTerminal();
	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {
		double sum (0.0);
		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			sum += sim.getEvolutionPop()[i]->getAlleles()[j]->getFrequency();
		}
		EXPECT_NEAR(sum, 1.0, 1e-6);
	}
}

TEST (SimulationTest, MutationTestFrequencySumKimura) {
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.1, 0.1, 0.1}, Kimura, {0.4}), false, false, true);

	for (int i(0); i < 50 ; ++i) {
		sim.createNewGeneration();
	}
	
	sim.printTerminal();
	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {
		double sum (0.0);
		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			sum += sim.getEvolutionPop()[i]->getAlleles()[j]->getFrequency();
		}
		EXPECT_NEAR(sum, 1.0, 1e-6);
	}
}


TEST (SimulationTest, MutationTestFreqenySumJukesKantor) {
	
	Simulation sim(new Generation({"ACC","GCC","CCC","GCC","GCC","GCC","CCC","CCC","GCC","GCC"}, {0.1, 0.4, 0.8}, JukesKantor), false, false, true);


	for (int i(0); i < 50 ; ++i) {
		sim.createNewGeneration();
	}
	
	sim.printTerminal();
	for (size_t i(0); i < sim.getEvolutionPop().size();  ++i) {
		double sum (0.0);
		for (size_t j (0); j <  sim.getEvolutionPop()[i]->getAlleles().size(); ++j) {
			sum += sim.getEvolutionPop()[i]->getAlleles()[j]->getFrequency();
		}
		EXPECT_NEAR(sum, 1.0, 1e-6);
	}
}

TEST (SimulationTest, Variation_in_population_size) 
{ 
	vector<double> frequencies({0.5,0.5,0.5}); 
	
	Simulation s (frequencies, 100, false, true, false); 
	int size_pop (s.getEvolutionPop()[0]->getNbIndividuals());
	
	for (int i(0); i<200; ++i) 
	{ 
		s.createNewGeneration(); 
	}
	
	EXPECT_NE(size_pop, s.getEvolutionPop().back()->getNbIndividuals());
		
}


int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
