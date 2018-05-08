/*
CC18 - Compass Connections 2018
An app that provides a visual representation of interpersonal connections made.
Created by Scott Emerson
*/

#include "UnitTests.h"
#include "CCMachine.h"
#include <memory>

void runAllTests()
{
	CCUT::runAllTests();
}

int main()
{
	/*runAllTests();*/

	std::unique_ptr<CCMachine> machine = std::make_unique<CCMachine>();

	machine->execute();

	return 0;
}

