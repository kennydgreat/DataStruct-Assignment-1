/*This cpp file is for the implementations of the Person, Athlete
class and all non member functions*/

#include "Assignment1.h"
#include <fstream>
/*This is the constructor of the Person class. It 
 1) Allocates memory on the heap for each variable of the object.
 2) Copys the strings from the parameters into the respective variable
	 memory block.
*/
Person::Person(char * first_name, char* last_name, char*nationality) {
//Allocating the exact amount of memory needed to save 
//hold the respective strings
	this->first_name = new char[strlen(first_name)+ONE];	
	this->last_name = new char[strlen(last_name) + ONE];
	this->nationality = new char[strlen(nationality)+ONE];

	//Check to make sure the allocation was successful
	if (!this->first_name || !this->last_name || !this->nationality) {
		cout << "Allocation for the Person's class variables failed"
			<< endl;
		exit(1);
	}
	//copying the contents of the parameters into the newly
	//allocated memory spots on the heap
	strcpy(this->first_name, first_name);
	strcpy(this->last_name, last_name);
	strcpy(this->nationality, nationality);
}

/*This is the deconstructor for the Person class. It
1) Frees up all memory allocation for each member variable*/
Person::~Person() {
	delete[] first_name;
	delete[] last_name;
	delete[] nationality;
}

/*This is the constructor for the Althele class. It 
1) calls the constructor of the base class (Person) passing in the 
	first 3 parameters
2) Allocates memory on the heap for distance variable
3) copys the fouth parameter into this spot on the heap*/
Athlete::Athlete(char * first_name, char * last_name, char * nationality
	, char * distance): Person(first_name, last_name, nationality) {
	this->distance = new char[strlen(distance)+ONE];
	if (!this->distance) {
		cout << "memory allocation for althele variable failed" << endl;
	}
	strcpy(this->distance, distance);
}

/*This is the deconstructor for the Athlete class. It
1) Frees up the memory block for the distance variable*/
Athlete::~Athlete() {
	delete[] distance;
}
/*This is the overoad "<<" for printing Athlete objects*/
std::ostream& operator<<(std::ostream& out, const Athlete& athlete) {
	out << athlete.get_first_name() << " " <<
		athlete.get_last_name() << " " <<
		athlete.get_distance() << endl;
	return out;
}
/*This function handles the file proicessing. It
1) Opens the file for reading
2) reads the string seperated by a space and saves them in 
 first_name, last_name, nationality and distance respectively
3) Creates an Athlete object using the strings and inserts the object
into the vector that is provided
*/
void read_data_file(vector<Athlete*> *data_vector) {
	char first_name[FIFTHY];
	char last_name[FIFTHY];
	char nationality[FIFTHY];
	char distance [FIFTHY];

	//Opening file for reading 
	ifstream infile;
	infile.open("jump.txt");
	if (infile.fail()) {
		cout << "jump.txt not found" << endl;
		exit(1);
	}
	//Skipping the title
	infile.ignore(FIFTHY, '\n');
	

	while (!infile.eof()) {
		// Geting firstname, last name, nationality, and distance jumped
		infile.getline(first_name, FIFTHY, ' ');
		infile.getline(last_name, FIFTHY, ' ');
		infile.getline(nationality, FIFTHY, ' ');
		infile.getline(distance, FIFTHY, '\n');
		Athlete *athlete = new Athlete(first_name, last_name,
			nationality, distance);
		data_vector->push_back(athlete);
	}
	infile.close();
}
/*
This function will be used to get and validate user input for the
 threshold value. it
1) Checks the input character by character returning false if a 
non digit character is found.
2) Returns true if all characters are digits.
3) creates a block of memory on the heap to store the accepted
user input
*/
bool read_and_validate_threshold_input(char ** threshold)
{
	char user_input[FIFTHY];
	cin >> user_input;
	
	for ( unsigned int i = 0; i < strlen(user_input); i++)
	{
		if (user_input[i] < '0' ||user_input[i] > '9') {
			if (user_input[i] != '.') {
				cout << "Input not number, please enter a number" << endl;
				return false;
			}
			
		}
	}
	*threshold = new char[strlen(user_input) + 1];
	strcpy(*threshold, user_input);
	return true;
}
/*This function does the search for athletes that jump above 
the threshold distance. It
1) Looks at each Athlete object in the vector and compares 
the distance string (converted to a double) with the threshold
(converted to a double)
2) Prints the Athlete info If the distance is above the threshold
and sets the nonefound boolean to false. 
3) If none where above the threshold the nonefound boolean stays
true and the "No athele jumped..." messgae is printed.*/
void find_print_athlete_above_threshold(char * threshold, 
	vector<Athlete*>* data_vector){
	bool nonefound = true;
	cout << "The athletes which exceeded " << threshold 
		<< "m are:" << endl;  
	for (unsigned int i = 0; i < data_vector->size(); i++) {
		if (atof(data_vector->at(i)->get_distance()) > atof(threshold)) {
			cout << *data_vector->at(i);
			nonefound = false;
		}
	}
	if (nonefound){
		cout << "No athlete jumped higher than " << threshold << "m" <<endl;
	}
}
/*This functions does the releasing of all allocated memory
from the heap. It
1) goes through the vector elements and frees the pointers(elements) to the
objects
2) emptys the vetor*/
void free_up_memory_for_vector_data(vector<Athlete*>* data_vector){
	for (int i = 0; i < data_vector->size(); i++) {
		delete data_vector->at(i);
	}
	data_vector->clear();
}


