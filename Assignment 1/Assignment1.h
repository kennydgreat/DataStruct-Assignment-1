/*This Header file contains the class declarations of the 
Person and Athlete classes*/

#include <iostream> 
using namespace std;

class Person {
	//Members variables 
	/*A person's first name, last name and nationality*/
private:
	char * first_name;
	char * last_name;
	char * nationality;

	//Memebers Functions
public:
	Person() {}; //Default constructor
	//Parameter constructor
	Person(char * first_name, char* last_name, char*nationality);
	~Person(); // Decontructor

	//Getters
	char * get_first_name() { return first_name; }
	char * get_last_name() { return last_name; }
	char * get_nationality() { return nationality; }
};
 /*This class is derived from the Person's class. It has
  a distance variable which is the distance jumped by the althele*/
class Athlete: public Person {
	//Memeber variables
private:
	char * distance; //Distance jumped
	//Memeber functions
public:
	//Constructor
	Athlete(char * first_name, char * last_name, char * nationality
	, char * distance);
	~Athlete(); //Decontructor

	//Getters 
	char * get_distance() { return distance; }
};
// overloaded operator for printing 
std::ostream& operator<<(std::ostream& out, const Athlete& athlete);