#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstring>

using namespace std;

// class User {
// public:
// 	char name[50], desig[50], gender, branch[50], address[50], mail[50];
// 	int salary;
// 	long long int phno;
// 	int yoj;

// 	char pw[16];

// };

// class Employee : public User {
// private:
// 	int id;
// public:
// 	static int count;
// 	Employee() {
// 		salary = NULL;
// 		phno = NULL;
// 		yoj = NULL;
// 	}
// 	Employee(int id, char* name, char* desig, char gender, char* branch, char* address, int salary, long long int phno, char* mail, int yoj, char* pw) : id(id) {
// 		memcpy(this->name, name, sizeof(this->name));
// 		memcpy(this->desig, desig, sizeof(this->desig));
// 		this->gender = gender;
// 		memcpy(this->branch, branch, sizeof(this->branch));
// 		memcpy(this->address, address, sizeof(this->address));
// 		this->salary = salary;
// 		this->phno = phno; memcpy(this->mail, mail, sizeof(this->mail));
// 		this->yoj = yoj;

// 		memcpy(this->pw, pw, sizeof(this->pw));
// 		//addToFile();
// 	}
// 	int getId() {
// 		return id;
// 	}
//     void displayData() {
// 	cout << id << " ";
// 	cout << name << " ";
// 	cout << desig<<" ";
// 	cout << gender << " ";
// 	cout << branch << " ";
// 	cout << address << " ";
// 	cout << salary << " ";
// 	cout << phno << " ";
// 	cout << yoj << " ";
// 	cout << pw << " ";
// 	cout << endl;
// }
// };

class A{
public:
int a, b, c;

A(int a, int b, int c):a(a), b(b), c(c){

}
};

int main() {
	// fstream employeeFile("employee.dat", ios::in | ios::binary);
	// int i = 0;
	// Employee buffer;
	// while (employeeFile.read((char*)&buffer, sizeof(Employee))) {
	// 	i += 1;
	// 	buffer.displayData();
	// }

	// fstream employeeFile("temp.dat", ios::in | ios::binary);
	// employeeFile.close();
	// if(rename("temp.dat", "employee.dat") == 0){
	// 	cout<<"renamed";
	// }

	// A a0(3, 4, 5);
	// A a1(7, 8, 9);
	// time_t now = time(0);
	// char* dt = ctime(&now);
	// dt[strcspn(dt, "\n")] = 0;
	// fstream testFile("test.csv", ios::in | ios::out | ios::app);
	// testFile<<dt<<", "<<a0.a<<", "<<a0.b<<", "<<a0.c<<"\n";
	// cin.get();

	// now = time(0);
	// dt = ctime(&now);
	// dt[strcspn(dt, "\n")] = 0;
	// testFile<<dt<<", "<<a1.a<<", "<<a1.b<<", "<<a1.c<<"\n";


	int a =10;
	char* word1;

	strcpy(word1, (char*)"barath");
	cout<<"hy";
	strcat(word1, to_string(a).c_str());
	cout<<"hy";

	cout<<word1;
}