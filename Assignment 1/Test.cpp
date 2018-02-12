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

	 Person * person = new Person(first_name, last_name,
		 nationality);
	 Athlete * athlete = new Athlete(first_name, last_name, nationality,
		 distance);

	 cout << "athlete distance is "<< athlete->get_distance() << 
		 "name is "<< athlete->get_first_name() <<" "
		 << athlete->get_last_name()
		 << "nationality is " << athlete->get_nationality() << endl;

	 cout << "person info is " << person->get_first_name() << " "
		 << person->get_first_name() << ", " << person->get_nationality()
		 << endl;

	 delete athlete;
	 
	 delete person;
	system("pause");
}

