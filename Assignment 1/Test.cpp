/*This cpp file is the contains the main for the program. Here the 
data from the jump.txt is read and stored on vector.
The user is then asked for a threshold value. Once the the result is 
displayed the user can choice to either terminate the program or 
enter another threshold. */
#include "Assignment1.h"
void man(char * first_name, char* last_name, char*nationality) {
	Person * person = new Person(first_name, last_name,
		nationality);
}
int main() {
	//char that stores user controls
	char user_controls = 'C';
	  //creating vector on the heap
	 vector<Athlete*> * data_vector = new vector<Athlete*>;
	 char * threshold = NULL; 
	 //Reading for jump.txt file
	 read_data_file(*&data_vector);
	 //
	 if (!data_vector->empty()) {
		 cout << "Data was loaded successfully." << endl;
	 }
	 else{ 
		 cout << "Data loading was unsccuessfully." 
			 << " Unfortunately the program was not setup to handle this"
			 << " and will need to terminate itself." << endl
			 << "Please ensure that jump.txt isn't empty."<< endl;
		 exit(1);
	 }
	
	 
	 //loop sequence for entering threshold values
	 while (user_controls == 'c' || user_controls == 'C') {
		 
		 //Ask for threshold vaule
		 cout << "Please enter a distance threshold: ";

		//Keep asking for vaule while the input is bad.
		 while (!read_and_validate_threshold_input(&threshold))
		 {
			 cout << "Please enter a distance threshold: ";
		 }

		// find and display athletes that jumped higher than threshold
		 find_print_athlete_above_threshold(threshold, *&data_vector);
		 //Ask for user response for enter entering another threshold
		 // or terminating the program
		 cout << endl;
		 cout << "To enter another threshold press 'c' and enter" << endl;
		 cout << "To quit press any other key and enter " << endl;
		 cin >> user_controls;
	 }
	 cout << "Bye!";
	///freeing memorying 
	 free_up_memory_for_vector_data(*&data_vector);
	 delete data_vector;
	 delete[] threshold;
	 system("pause");
}

