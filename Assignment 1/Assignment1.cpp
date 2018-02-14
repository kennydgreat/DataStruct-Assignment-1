/*This cpp file is for the implementations of the Person, Athlete
class and all non member functions*/

#include "Assignment1.h"
#include <fstream>
//Constants
#ifndef ONE
#define ONE 1 
#endif
#ifndef FIFTHY
#define FIFTHY 50 
#endif
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
	delete first_name;
	delete last_name;
	delete nationality;
	cout << "Heap Memory blocks for Person object freed" << endl;
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
	delete distance;
	cout << "Heap memory blocks for Athlete object freed" << endl;
}
/*This is the overoad "<<" for printing Athlete objects*/
std::ostream& operator<<(std::ostream& out, const Athlete& athlete) {
	out << "Name: " << athlete.get_first_name() << " " <<
		athlete.get_last_name() << ", Distance Jumped: " <<
		athlete.get_distance() << endl;
	return out;
}
/*This function handles the file proicessing. It
1) Opens the file for reading
2) reads the string seperated by a space and saves them in 
 first_name, last_name, nationality and distance respectively
3) Creates an Athlete object using the strings and inserts the object
into a vector that is provided
*/
void read_data_file(vector<Athlete*> *data_vector) {
	char title[FIFTHY] ;
	char first_name[FIFTHY];
	char last_name[FIFTHY];
	char nationality[FIFTHY];
	char distance [FIFTHY];

	ifstream infile;
	infile.open("jump.txt");
	if (infile.fail()) {
		cout << "jump.txt not found" << endl;
		exit(1);
	}
	//Skipping the title
	infile.getline(title, FIFTHY);
	

	while (infile.good()) {
		// Geting first
		infile.getline(first_name, FIFTHY, ' ');
		infile.getline(last_name, FIFTHY, ' ');
		infile.getline(nationality, FIFTHY, ' ');
		infile.getline(distance, FIFTHY, '\n');
		Athlete *athlete = new Athlete(first_name, last_name,
			nationality, distance);
		data_vector->push_back(athlete);
	}
}
