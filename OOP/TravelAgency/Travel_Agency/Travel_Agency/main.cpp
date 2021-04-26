<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "DynamicArray.h"
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
#include "DynamicArray.h"
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
#include "Repository.h"
#include "WishList.h"
#include "Validator.h"
#include "Service.h"
#include "UserInterface.h"
#include "Test.h"

<<<<<<< HEAD
<<<<<<< HEAD
#include <crtdbg.h>

/*
FileRepository testBlanita() {
	FileRepository rp1{ "" };
	return rp1;
}
*/
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
#include <iostream>
#include <crtdbg.h>

using namespace std;
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

int main() {

	{
<<<<<<< HEAD
<<<<<<< HEAD
=======
		
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		TestTravelAgency test;
		test.runAllTests();

		/*
<<<<<<< HEAD
<<<<<<< HEAD
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

=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		Repository repository{ };
		FileRepository file_repository{"offers_file.txt"};
		WishList wish_list{ };
		TravelAgencyValidator validator{ };
		Service service{ file_repository, validator, wish_list };
		UI ui{ service };
		ui.runUI();
	    */
		
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	}

	_CrtDumpMemoryLeaks();
	return 0;
}