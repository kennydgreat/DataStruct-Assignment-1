#include "Assignment1.h"
void man(char * first_name, char* last_name, char*nationality) {
	Person * person = new Person(first_name, last_name,
		nationality);
}
int main() {
	 char first_name[4] = "Ken";
	char last_name[5] = "Kena";
	 char nationality[7] = "Kenyan";
	 char distance[3] = "10";

	/* Person * person = new Person(first_name, last_name,
		 nationality);
	 Athlete * athlete = new Athlete(first_name, last_name, nationality,
		 distance);

	 cout << *athlete;

	 cout << "person info is " << person->get_first_name() << " "
		 << person->get_first_name() << ", " << person->get_nationality()
		 << endl;


	 delete athlete;
	 
	 delete person;
	 */
	 vector<Athlete*> data_vector;
	 read_data_file(&data_vector);
	 if (!data_vector.empty()) {
		 for (unsigned int i = 0; i < data_vector.size(); i++)
		 {
			 cout << *data_vector.at(i) << endl;
		 }
	 }
	system("pause");
}

