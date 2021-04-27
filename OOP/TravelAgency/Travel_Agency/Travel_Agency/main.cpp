#include "Repository.h"
#include "WishList.h"
#include "Validator.h"
#include "Service.h"
#include "UserInterface.h"
#include "Test.h"

#include <crtdbg.h>

/*
FileRepository testBlanita() {
	FileRepository rp1{ "" };
	return rp1;
}
*/

int main() {

	{
		TestTravelAgency test;
		test.runAllTests();

		/*
		// test copy constructor 
		auto rp3 = testBlanita();

		// test assignment constructor
		FileRepository rp1{ "" };
		FileRepository rp2{ "" };
		
		rp1 = rp2;
		*/


		/*
		MemoryRepository repository{ };
		FileRepository file_repository{"offers_file.txt"};
		LabActivityRepository lab_activity_repository { 0.5 };
		WishList wish_list{ };
		const TravelAgencyValidator validator{ };
		Service service{file_repository, validator, wish_list };
		UI ui{ service };
		ui.runUI();
	    */

	}

	_CrtDumpMemoryLeaks();
	return 0;
}