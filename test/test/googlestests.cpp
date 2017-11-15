#include <iostream>
#include "Generation.hpp"
#include "Simulation.hpp"
#include "Allele.hpp"
#include "gtest/gtest.h"

/*!Test if the table that readFromFile function returns contains the nucleotides choser by the marker site table
 * (test on the test.fa file)
 */
TEST (SimulationTest, readFromFile_) 
{
	Simulation sim;
	ifstream inputFile;
	inputFile.open("test.fa");
	
	vector<int> test = {0,2,4,6};
	vector<string> Alleles;
	Alleles = readFromFile(test, inputFile);
	
	EXPECT_EQ(Alleles[0], "TCAC");
	EXPECT_EQ(Alleles[1], "TCAC");
	EXPECT_EQ(Alleles[2], "TCTC");

	
}

int main(int argc, char **argv) 
{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
