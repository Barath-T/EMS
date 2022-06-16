#include<iostream>
#include<fstream>
#include<string.h>

//EVERY FUNCTION WILL WRITE INTO LOG FILE

using namespace std;
int intValidate(const char* print);
char* passwordValidate(const char* print);
class Employee;
class LeaveReq;

//template <typename T> class ModReq;
template <typename T> class LQueue;
template <typename T> class LL;
template <typename T> class Node;

template <typename T>
void MergeSort(Node<T>** head);
template <typename T>
void MergeSort(Node<T>** head);

class User {
public:
	char name[50], desig[50], gender, branch[50], address[50], mail[50];
	int salary;
	long long int phno;
	int yoj;

	char pw[16];

};

class Admin :public User {
private:
	int id;
public:
	static int count;
	Admin() {
		salary = NULL;
		phno = NULL;
		yoj = NULL;
	}
	Admin(int id, char* name, char gender, char* branch, char* address, int salary, long long int phno, char* mail, int yoj, char* pw) : id(id) {
		memcpy(this->name, name, sizeof(this->name));
		strcpy(this->desig, (char*)"Manager");
		this->gender = gender;
		memcpy(this->branch, branch, sizeof(this->branch));
		memcpy(this->address, address, sizeof(this->address));
		this->salary = salary;
		this->phno = phno;
		memcpy(this->mail, mail, sizeof(this->mail));
		this->yoj = yoj;

		memcpy(this->pw, pw, sizeof(this->pw));

		//addToFile();
	}
	int getId() {
		return id;
	}

	static void init_admin();

	void addToFile();
	void getData();
	static void fromTheFile(LL<Admin>* adminLL);
	static void allToFile(LL<Admin>* adminLL);

	void displayData();
	//get data
	//display data

	//create employee
	//modify data of any employee
	//search employee
	//sorting
	//delete employee
	//display all employee
	void createEmployee(LL<Employee>* empLL);
	void modifyEmployee(LL<Employee>* empLL);
	static void searchEmployee(LL<Employee>* empLL);
	static void sortingByName(LL<Employee>* empLL);
	static void displayAllEmployee(LL<Employee>* empLL);
	void deleteEmployee(LL<Employee>* empLL);

	//accepting and removing leave requests
	//accepting modification requests
	//display attendence

	void acceptLeave(LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL);
	void removeLeave(LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL);

	//void acceptPhno(LL<Employee>* empLL, LQueue < ModReq < long long int >> *modQ, LL<ModReq<long long int>>* statusLL);
	//void acceptMail(LL<Employee>* empLL, LQueue < ModReq < char[50] >>* modQ, LL<ModReq<char[50]>>* statusLL);
	//	
	//void removePhnoReq(LQueue<ModReq<long long int>>* modQ, LL<ModReq<long long int>>* statusLL);
	//void removeMailReq(LQueue<ModReq<char[50]>>* modQ, LL<ModReq<char[50]>>* statusLL);

	//admin login

	bool operator==(Admin& other) const;

	static Admin login(LL<Admin>* adminLL);

	static void adminFunctions(Admin& adminUser, LL<Employee>* empLL, LL<Admin>*  adminLL, LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL);
};

class Employee : public User {
private:
	int id;
public:
	static int count;
	Employee() {
		salary = NULL;
		phno = NULL;
		yoj = NULL;
	}
	Employee(int id, char* name, char* desig, char gender, char* branch, char* address, int salary, long long int phno, char* mail, int yoj, char* pw) : id(id) {
		memcpy(this->name, name, sizeof(this->name));
		memcpy(this->desig, desig, sizeof(this->desig));
		this->gender = gender;
		memcpy(this->branch, branch, sizeof(this->branch));
		memcpy(this->address, address, sizeof(this->address));
		this->salary = salary;
		this->phno = phno; memcpy(this->mail, mail, sizeof(this->mail));
		this->yoj = yoj;

		memcpy(this->pw, pw, sizeof(this->pw));
		//addToFile();
	}
	int getId() {
		return id;
	}

	void addToFile();
	static void fromTheFile(LL<Employee>* empLL);
	static void allToFile(LL<Employee>* empLL);

	void getData();
	//get data
	//display data
	void displayData();

	//modification request
	//attendence
	//leave request

	void leaveRequest(LQueue<LeaveReq>* leaveQ);

	//void modificationRequestPhno(LQueue<ModReq<long long int>>* modQ);
	//void modificationRequestMail(LQueue<ModReq<char[50]>>* modQ);

	//employee login
	bool operator==(Employee& other) const;

	static Employee login(LL<Employee>* empLL);

	static void empFunctions(Employee& empUser, LL<Employee>* empLL, LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL);
};

class LeaveReq {
private:
	int id;

public:
	static int count;
	Employee emp;
	char reason[120];
	bool status;

	LeaveReq() {
		id = NULL;
		status = NULL;
	}
	LeaveReq(int id, Employee& emp, char* reason, bool status) : id(id), emp(emp), status(status) {
		this->emp = emp;
		memcpy(this->reason, reason, sizeof(this->reason));
		addToFile();
	}

	int getId() {
		return id;
	}

	void addToFile();

	static void fromTheFile(LQueue<LeaveReq>* leaveQ);
	static void allToFile(LQueue<LeaveReq>* leaveQ);

	static void fromTheFile(LL<LeaveReq>* leaveLL);
	static void allToFile(LL<LeaveReq>* leaveLL);

	void getData(Employee& emp, LQueue<LeaveReq>* leaveQ);
	void displayData();
	//get data and place request
	//display data
};

//template<typename T>
//class ModReq {
//private:
//	int id;
//
//public:
//	static int count;
//	Employee emp;
//	T change;
//	char field[20];
//	bool status;
//
//	ModReq() {
//		id = NULL;
//		status = NULL;
//	}
//	ModReq(int id, Employee& emp, T change, char* field, bool status) : id(id), emp(emp), status(status) {
//		this->emp = emp;
//		if (typeid(change) == typeid(char*)) {
//			memcpy(this->change, change, sizeof(this->change));
//		}
//		else {
//			this->change = change;
//		}
//		
//		memcpy(this->field, field, sizeof(this->field));
//	}
//
//	int getId() {
//		return id;
//	}
//
//	void addToFile();
//
//	static void fromTheFile(LQueue<ModReq>* modQ);
//	static void allToFile(LQueue<ModReq>* modQ);
//
//	static void fromTheFile(LL<ModReq>* modLL);
//	static void allToFile(LL<ModReq>* modLL);
//
//	void getData(Employee& emp, LQueue<ModReq>* modQ, char* field);
//	void displayData();
//	//get data and place request
//	//display data
//};

//DATASTRUCTURES
template<typename T>
class Node {

public:
	T data;
	Node<T>* next;
	Node() {
		next = NULL;
	}
	Node(T data, Node<T>* next) : data(data), next(next) {

	}

	int getId() {
		return data.getId();
	}
};

template<typename T>
class LL {
public:
	Node<T>* head;
	Node<T>* tail;


	LL() {
		head = NULL;
		tail = NULL;
	}

	void appendNode(T data) {

		Node<T>* newNode = new Node<T>(data, NULL);

		if (tail == NULL && head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	Node<T>* searchNode(int id) {
		if (tail == NULL && head == NULL) {
			return NULL;
		}

		Node<T>* temp = head;
		while (temp != NULL) {
			if (temp->getId() == id) {
				return temp;
			}
			temp = temp->next;
		}

		return NULL;
	}

	void deleteNode(int id) {
		if (tail == NULL && head == NULL) {
			cout << "empty!"<<endl;
		}
		else if (head->getId() == id) {
			Node<T>* r_temp = head;//to return head

			Node<T>* temp = head->next;
			head->next = NULL;
			head = temp;

			delete r_temp;
		}
		else {
			Node<T>* r_temp;//to return deleted Node<T>

			Node<T>* temp = head;
			while (temp != NULL) {
				if (temp->next->getId() == id) {
					r_temp = temp->next;

					temp->next = temp->next->next;
					r_temp->next = NULL;

					delete r_temp;
					break;
				}
				temp = temp->next;
			}
			//return NULL;
		}


	}

	void displayLL() {
		if (head == NULL && tail == NULL) {
			cout << "NO EMPLOYEES FOUND!";
		}
		Node<T>* temp = head;
		while (temp != NULL) {
			temp->data.displayData();

			temp = temp->next;
		}
	}
	//insert Node<T>~
	//delete Node<T>~
	//modify data of a Node<T>!
	//sort all nodes
	//search in all nodes~
	//display all nodes~
	// 
	//retrives data from file and creates a Node<T>
	//save all Node<T>'s data in a file(rewrite the file)


};

template<typename T>
class LQueue {
public:
	Node<T>* head;
	Node<T>* tail;

	LQueue() {
		head = NULL;
		tail = NULL;
	}

	void enQueue(T data) {

		Node<T>* newNode = new Node<T>(data, NULL);

		if (tail == NULL && head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	Node<T>* deQueue() {
		if (tail == NULL && head == NULL) {
			return NULL;
		}
		else {
			Node<T>* r_temp = head;//to return head

			Node<T>* temp = head->next;
			head->next = NULL;
			head = temp;

			return r_temp;
		}
	}


	void displayNodes() {
		if (head == NULL && tail == NULL) {
			cout << "NO EMPLOYEES FOUND!";
		}
		Node<T>* temp = head;
		while (temp != NULL) {
			temp->data.displayData();

			temp = temp->next;
		}
	}
	//all queue operations
	//retrives data from file into a queue
	//writes the queue in a file
};

//ADMIN
void Admin::init_admin() {
	fstream adminFile("admin.dat", ios::in | ios::out | ios::binary);
	if (adminFile.peek() == EOF) {
		Admin firstAdmin(1000, (char*)"Admin", NULL, (char*)NULL, (char*)NULL, 00000, 00000000000, (char*)NULL, 0000, (char*)"admin");
		firstAdmin.addToFile();
	}
}

void Admin::addToFile() {
	fstream adminFile("admin.dat", ios::out | ios::app | ios::binary);

	adminFile.write((char*)this, sizeof(Admin));
}

void Admin::fromTheFile(LL<Admin>* adminLL) {
	//LL<Admin>* empLL = new LL<Admin>;
	fstream adminFile("Admin.dat", ios::in | ios::binary);
	int i = 0;
	Admin buffer;
	while (adminFile.read((char*)&buffer, sizeof(Admin))) {
		i += 1;
		adminLL->appendNode(buffer);
	}

	if (!i) {
		cout << "\n-----No Admin users-----" << endl;
	}
	else {
		cout << i << " Admin users" << endl;
	}
}

void Admin::allToFile(LL<Admin>* adminLL) {
	rename("admin.dat", "temp.dat");

	if (adminLL->head == NULL && adminLL->tail == NULL) {
		cout << "no data to add in file";
	}
	Node<Admin>* temp = adminLL->head;
	while (temp != NULL) {
		temp->data.addToFile();

		temp = temp->next;
	}

	remove("temp.dat");
}

void Admin::getData() {
	id = ++count;

	cin >> name;
	strcpy(desig, (char*)"Manager");
	cin >> gender;
	cin >> branch;
	cin >> address;
	cin >> salary;
	cin >> phno;
	cin >> mail;
	cin >> yoj;
	memcpy(pw, passwordValidate("\nCreate valid password (under 15 letters): "), sizeof(pw));

	addToFile();
}

void Admin::displayData() {
	cout << id << " ";
	cout << name << " ";
	cout << gender << " ";
	cout << branch << " ";
	cout << address << " ";
	cout << salary << " ";
	cout << phno << " ";
	cout << yoj << " ";
	cout << pw << " ";
	cout << endl;
}

void Admin::createEmployee(LL<Employee>* empLL) {
	Employee e;
	e.getData();

	empLL->appendNode(e);
}

void Admin::modifyEmployee(LL<Employee>* empLL) {
	int id;
	cout << "Id of employee: ";
	cin >> id;

	Node<Employee>* emp = empLL->searchNode(id);

	int ch;
	bool run = 1;

	while (run) {
		cout << "\nMODIFYING EMPLOYEE DATA";
		cout << "\n1. Phone Number";
		cout << "\n2. Mail";
		cout << "\n3. Address";
		cout << "\n4. Branch";
		cout << "\n5. Designation";
		cout << "\n6. Salary";
		cout << "\n7. back";
		
		cout << "\nEnter your choice: ";
		cin >> ch;

		if (ch == 1) {

			long long int phno;

			cout << "New phno of employee: ";
			cin >> phno;

			emp->data.phno = phno;
		}
		else if (ch == 2) {
			char mail[50];
			cout << "New mail of employee: ";
			cin >> mail;

			memcpy(emp->data.mail, (char*)mail, sizeof(mail));
		}
		else if (ch == 3) {
			char address[50];
			cout << "New address of employee: ";
			cin >> address;

			memcpy(emp->data.address, (char*)address, sizeof(address));
		}
		else if (ch == 4) {
			char branch[50];
			cout << "New branch of employee: ";
			cin >> branch;

			memcpy(emp->data.branch, (char*)branch, sizeof(branch));
		}
		else if (ch == 5) {
			char desig[50];
			cout << "New designation of employee: ";
			cin >> desig;

			memcpy(emp->data.desig, (char*)desig, sizeof(desig));
		}
		else if (ch == 6) {
			int salary;
			cout << "New salary of employee: ";
			cin >> salary;

			emp->data.salary = salary;
		}
		else if (ch == 7) {
			run = 0;
		}
		else {
			cout << "enter a valid input";
		}
	}
}

void Admin::searchEmployee(LL<Employee>* empLL) {
	int id;
	cin >> id;
	Node<Employee>* emp = empLL->searchNode(id);
	emp->data.displayData();
	
}

void Admin::sortingByName(LL<Employee>* empLL) {
	LL<Employee> emp = *empLL;

	MergeSort(&emp.head);

	emp.displayLL();
}

void Admin::displayAllEmployee(LL<Employee>* empLL) {
	empLL->displayLL();
}

void Admin::deleteEmployee(LL<Employee>* empLL) {

	int id;
	cin >> id;
	empLL->deleteNode(id);
}

void Admin::acceptLeave(LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL) {
	Node<LeaveReq>* lReq = LeaveQ->deQueue();
	lReq->data.status = 1;
	statusLL->appendNode(lReq->data);
}

void Admin::removeLeave(LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL) {
	Node<LeaveReq>* lReq = LeaveQ->deQueue();
	lReq->data.status = 0;
	statusLL->appendNode(lReq->data);
}

//MOD

//void Admin::acceptPhno(LL<Employee>* empLL, LQueue < ModReq < long long int >>* modQ, LL<ModReq<long long int>>* statusLL) {
//	Node<ModReq<long long int>>* mReq = modQ->deQueue();
//	mReq->data.status = 1;
//	statusLL->appendNode(mReq->data);
//
//	
//	Node<Employee>* emp = empLL->searchNode(mReq->data.getId());
//	emp->data.phno = mReq->data.change;
//}
//void Admin::acceptMail(LL<Employee>* empLL, LQueue < ModReq < char[50] >>* modQ, LL<ModReq<char[50]>>* statusLL) {
//	Node<ModReq<char[50]>>* mReq = modQ->deQueue();
//	mReq->data.status = 1;
//	statusLL->appendNode(mReq->data);
//
//	Node<Employee>* emp = empLL->searchNode(mReq->data.getId());
//	memcpy(emp->data.mail, mReq->data.change, sizeof(emp->data.mail));
//}
//
//void Admin::removePhnoReq(LQueue<ModReq<long long int>>* modQ, LL<ModReq<long long int>>* statusLL) {
//	Node<ModReq<long long int>>* mReq = modQ->deQueue();
//	mReq->data.status = 0;
//	statusLL->appendNode(mReq->data);
//}
//void Admin::removeMailReq(LQueue<ModReq<char[50]>>* modQ, LL<ModReq<char[50]>>* statusLL) {
//	Node<ModReq<char[50]>>* mReq = modQ->deQueue();
//	mReq->data.status = 0;
//	statusLL->appendNode(mReq->data);
//}

bool Admin::operator==(Admin& other) const {
	return !(this->id == other.getId() && strcmp(this->pw, other.pw));
}

Admin Admin::login(LL<Admin>* adminLL) {  //throwing 1 to go to last page
	Admin user;
	try {
		cout << "\n\n------------------------\n\n";
		cout << "\nEnter your id: ";
		user.id = intValidate("\nEnter valid id: ");

		cout << "\nEnter your password: ";
		strcpy(user.pw, passwordValidate("\nEnter valid password: "));

		Node<Admin>* _user = adminLL->searchNode(user.id);

		if (_user != NULL && user == _user->data) {
			user = _user->data;
			return user;
		}
		else {
			throw "\nWrong password or id! try again!";
		}
	}
	catch (const char* exception) {
		cout << exception << endl;

		int ch;
		cout << "\nWant to continue?( 1/0 ): ";
		ch = intValidate("\n\nEnter a valid choice: ");

		if (ch == 1) {
			Admin::login(adminLL);
		}
		else {
			throw 1;
		}
	}
}

void Admin::adminFunctions(Admin& adminUser, LL<Employee>* empLL,LL<Admin>* adminLL, LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL) {
	int ch, ch1, ch2;
	bool run = 1, run1 = 1, run2 = 1;
	
	while (run) {
		cout << "\n\t\t\t______________________________________________";
		cout << "\n\n\t\t\t\t\t *ADMIN*\n\n";
		cout << "\n\t\t\t\t1.Employee data";
		cout << "\n\t\t\t\t2.Leave requests";
		cout << "\n\t\t\t\t3.back";
		cout << "\n\t\t\t______________________________________________";
		cout << "\n\n\nEnter your choice:";

		cout << "Enter your choice: ";
		ch = intValidate("Enter a valid choice: ");

		switch (ch) {
		case 1:
			
			while (run1) {
				cout << "\n\t\t\t______________________________________________";
				cout << "\n\n\t\t\t\t\t *ADMIN MODE - Employee Data*\n\n";
				cout << "\n\t\t\t\t1.Create Employee";
				cout << "\n\t\t\t\t2.Modify Employee";
				cout << "\n\t\t\t\t3.Delete Employee";
				cout << "\n\t\t\t\t4.Search Employee";
				cout << "\n\t\t\t\t5.Sort and display employee by name";
				cout << "\n\t\t\t\t6.Display all Employee";
				cout << "\n\t\t\t\t7.back";
				cout << "\n\t\t\t______________________________________________";
				cout << "\n\n\nEnter your choice:";

				cout << "Enter your choice: ";
				ch1 = intValidate("Enter a valid choice: ");

				switch (ch1) {
				case 1:

					adminUser.createEmployee(empLL);

					break;
				case 2:

					adminUser.modifyEmployee(empLL);

					break;
				case 3:
					adminUser.deleteEmployee(empLL);

					break;
				case 4:
					adminUser.searchEmployee(empLL);
					break;
				case 5:
					adminUser.sortingByName(empLL);
					break;
				case 6:
					adminUser.displayAllEmployee(empLL);
					break;
				case 7:
					run1 = 0;
					break;
				default:
					cout << "\nEnter correct choice!( 1-7 )" << endl;
					break;
				}

			}
			break;
			case 2:
				while (run2) {
					cout << "\n\t\t\t______________________________________________";
					cout << "\n\n\t\t\t\t\t *ADMIN MODE - Leave requests*\n";
					cout << "\n\t\t\t\t1.Accept leave request";
					cout << "\n\t\t\t\t2.Reject leave request";
					cout << "\n\t\t\t\t3.Display leave request queue";
					cout << "\n\t\t\t\t4.Display leave request's status";
					cout << "\n\t\t\t\t5.back";
					cout << "\n\t\t\t______________________________________________";
					cout << "\n\n\nEnter your choice:";

					cout << "Enter your choice: ";
					ch2 = intValidate("Enter a valid choice: ");

					switch (ch2) {
					case 1:

						adminUser.acceptLeave(LeaveQ, statusLL);

						break;
					case 2:

						adminUser.removeLeave(LeaveQ, statusLL);

						break;
					case 3:
						LeaveQ->displayNodes();

						break;

					case 4:
						statusLL->displayLL();
						break;

					case 5:
						run2 = 0;
						continue;
					default:
						cout << "\nEnter correct choice!( 1-5 )" << endl;
						break;
					}
					
				}
				break;

			case 3:
				run = 0;
				break;

			default:
				cout << "\nEnter correct choice!( 1-3 )" << endl;
				break;
					
		}
		
		
	}
	
}

//EMPLOYEE
void Employee::addToFile() {
	fstream employeeFile("employee.dat", ios::out | ios::app | ios::binary);

	employeeFile.write((char*)this, sizeof(Employee));
}

void Employee::fromTheFile(LL<Employee>* empLL) {
	//LL<Employee>* empLL = new LL<Employee>;
	fstream employeeFile("employee.dat", ios::in | ios::binary);
	int i = 0;
	Employee buffer;
	while (employeeFile.read((char*)&buffer, sizeof(Employee))) {
		i += 1;
		empLL->appendNode(buffer);
	}

	if (!i) {
		cout << "\n-----No employee users-----" << endl;
	}
	else {
		cout << i << " employee users" << endl;
	}
}

void Employee::allToFile(LL<Employee>* empLL) {
	rename("employee.dat", "temp.dat");

	if (empLL->head == NULL && empLL->tail == NULL) {
		cout << "no data to add in file";
	}
	Node<Employee>* temp = empLL->head;
	while (temp != NULL) {
		temp->data.addToFile();

		temp = temp->next;
	}

	remove("temp.dat");
}

void Employee::getData() {
	id = ++count;

	cin >> name;
	cin >> desig;
	cin >> gender;
	cin >> branch;
	cin >> address;
	cin >> salary;
	cin >> phno;
	cin >> mail;
	cin >> yoj;
	memcpy(pw, passwordValidate("\nCreate valid password (under 15 letters): "), sizeof(pw));

	addToFile();
}

void Employee::displayData() {
	cout << id << " ";
	cout << name << " ";
	cout << desig<<" ";
	cout << gender << " ";
	cout << branch << " ";
	cout << address << " ";
	cout << salary << " ";
	cout << phno << " ";
	cout << yoj << " ";
	cout << pw << " ";
	cout << endl;
}

void Employee::leaveRequest(LQueue<LeaveReq>* leaveQ) {
	LeaveReq lReq;
	lReq.getData(*this, leaveQ);
	cout << "Request id: " << lReq.getId() << endl << endl;
}

void Employee::empFunctions(Employee& empUser, LL<Employee>* empLL, LQueue<LeaveReq>* LeaveQ, LL<LeaveReq>* statusLL) {
	int ch;
	bool run = 1;

	while (run) {
		cout << "\n\t\t\t______________________________________________";
		cout << "\n\n\t\t\t\t\t *Employee*\n\n";
		cout << "\n\t\t\t\t1.Request for leave";
		cout << "\n\t\t\t\t2.Show my details";
		cout << "\n\t\t\t\t3.back";
		cout << "\n\t\t\t______________________________________________";
		cout << "\n\n\nEnter your choice:";

		cout << "Enter your choice: ";
		ch = intValidate("Enter a valid choice: ");

		switch (ch) {
		case 1:
			empUser.leaveRequest(LeaveQ);
			break;
		case 2:
			empUser.displayData();
			break;

		case 3:
			run = 0;
			break;

		default:
			cout << "\nEnter correct choice!( 1-3 )" << endl;
			break;
		}
		
	}
}

//
//void Employee::modificationRequestPhno(LQueue<ModReq<long long int>>* modQ) {
//
//	ModReq<long long int> mod;
//	mod.getData(*this, modQ, (char*)"Phno");
//
//}
//
//void Employee::modificationRequestMail(LQueue<ModReq<char[50]>>* modQ) {
//	ModReq<char[50]> mod;
//	mod.getData(*this, modQ, (char*)"mail");
//}

bool Employee::operator==(Employee& other) const {
	return !(this->id == other.getId() && strcmp(this->pw, other.pw));
}

Employee Employee::login(LL<Employee>* empLL) {  //throwing 1 to go to last page
	Employee user;
	try {
		cout << "\n\n------------------------\n\n";
		cout << "\nEnter your id: ";
		user.id = intValidate("\nEnter valid id: ");

		cout << "\nEnter your password: ";
		strcpy(user.pw, passwordValidate("\nEnter valid password: "));

		Node<Employee>* _user = empLL->searchNode(user.id);

		if (_user != NULL && user == _user->data) {
			user = _user->data;
			return user;
		}
		else {
			throw "\nWrong password! try again!";
		}
	}
	catch (const char* exception) {
		cout << exception << endl;

		int ch;
		cout << "\nWant to continue?( 1/0 ): ";
		ch = intValidate("\n\nEnter a valid choice: ");

		if (ch == 1) {
			Employee::login(empLL);
		}
		else {
			throw 1;
		}
	}
}

//LEAVE REQUESTS
void LeaveReq::addToFile() {
	fstream leaveReqFile("leaveReq.dat", ios::out | ios::app | ios::binary);
	leaveReqFile.write((char*)this, sizeof(LeaveReq));
}

void LeaveReq::fromTheFile(LQueue<LeaveReq>* leaveQ) {
	//LL<Employee>* empLL = new LL<Employee>;
	fstream leaveReqFile("leaveReq.dat", ios::in | ios::out | ios::binary);
	int i = 0;
	LeaveReq buffer;
	while (leaveReqFile.read((char*)&buffer, sizeof(LeaveReq))) {
		i += 1;
		leaveQ->enQueue(buffer);
	}

	if (!i) {
		cout << "\n-----No leave requests-----" << endl;
	}
	else {
		cout << i << " Leave requests" << endl;
	}
}

void LeaveReq::allToFile(LQueue<LeaveReq>* leaveQ) {
	rename("leaveReq.dat", "temp.dat");

	if (leaveQ->head == NULL && leaveQ->tail == NULL) {
		cout << "no data to add in file";
	}

	Node<LeaveReq>* temp = leaveQ->head;
	while (temp != NULL) {
		temp->data.addToFile();

		temp = temp->next;
	}

	remove("temp.dat");
}

void LeaveReq::fromTheFile(LL<LeaveReq>* leaveLL) {
	//LL<Employee>* empLL = new LL<Employee>;
	fstream leaveReqFile("leaveReqstatus.dat", ios::in | ios::binary);
	int i = 0;
	LeaveReq buffer;
	while (leaveReqFile.read((char*)&buffer, sizeof(LeaveReq))) {
		i += 1;
		leaveLL->appendNode(buffer);
	}

	if (!i) {
		cout << "\n-----No leave requests-----" << endl;
	}
	else {
		cout << i << " Leave requests" << endl;
	}
}

void LeaveReq::allToFile(LL<LeaveReq>* leaveLL) {
	rename("leaveReqstatus.dat", "temp.dat");

	if (leaveLL->head == NULL && leaveLL->tail == NULL) {
		cout << "no data to add in file";
	}
	Node<LeaveReq>* temp = leaveLL->head;
	while (temp != NULL) {
		fstream leaveReqFile("leaveReqstatus.dat", ios::out | ios::app | ios::binary);
		leaveReqFile.write((char*)&temp->data, sizeof(LeaveReq));

		temp = temp->next;
	}

	remove("temp.dat");
}

void LeaveReq::getData(Employee& emp, LQueue<LeaveReq>* leaveQ) {

	this->id = ++count;
	this->emp = emp;
	cout << "\nEnter your reason: ";
	cin >> reason;

	leaveQ->enQueue(*this);
}

void LeaveReq::displayData() {
	cout << "\nRequest id: " << id << endl;
	cout << "\nAddress: " << reason << endl;

	cout << "\n\----------------";
	cout << "\nUser Details: ";
	emp.displayData();

}

//MOD REQUESTS

//template<typename T>
//void ModReq<T>::addToFile() {
//	fstream modReqFile("modReq.dat", ios::out | ios::app | ios::binary);
//	modReqFile.write((char*)this, sizeof(ModReq));
//}
//
//template<typename T>
//void ModReq<T>::fromTheFile(LQueue<ModReq>* modQ) {
//	//LL<Employee>* empLL = new LL<Employee>;
//	fstream modReqFile("modReq.dat", ios::in | ios::binary);
//	int i = 0;
//	ModReq buffer;
//	while (modReqFile.read((char*)&buffer, sizeof(ModReq))) {
//		i += 1;
//		modQ->enQueue(buffer);
//	}
//
//	if (!i) {
//		cout << "\n-----No modification requests-----" << endl;
//	}
//	else {
//		cout << i << " Modification requests" << endl;
//	}
//}
//
//template<typename T>
//void ModReq<T>::allToFile(LQueue<ModReq>* modQ) {
//	rename("modReq.dat", "temp.dat");
//
//	if (modQ->head == NULL && modQ->tail == NULL) {
//		cout << "no data to add in file";
//	}
//	Node<ModReq>* temp = modQ->head;
//	while (temp != NULL) {
//		temp->data.addToFile();
//
//		temp = temp->next;
//	}
//
//	remove("temp.dat");
//}
//
//template<typename T>
//void ModReq<T>::fromTheFile(LL<ModReq>* modLL) {
//	//LL<Employee>* empLL = new LL<Employee>;
//	fstream modReqFile("modReqstatus.dat", ios::in | ios::binary);
//	int i = 0;
//	ModReq buffer;
//	while (modReqFile.read((char*)&buffer, sizeof(ModReq))) {
//		i += 1;
//		modLL->appendNode(buffer);
//	}
//
//	if (!i) {
//		cout << "\n-----No leave requests-----" << endl;
//	}
//	else {
//		cout << i << " Leave requests" << endl;
//	}
//}
//
//template<typename T>
//void ModReq<T>::allToFile(LL<ModReq>* modLL) {
//	rename("modReqstatus.dat", "temp.dat");
//
//	if (modLL->head == NULL && modLL->tail == NULL) {
//		cout << "no data to add in file";
//	}
//	Node<ModReq>* temp = modLL->head;
//	while (temp != NULL) {
//		fstream modReqFile("modReqstatus.dat", ios::out | ios::app | ios::binary);
//		modReqFile.write((char*)&temp->data, sizeof(ModReq));
//
//		temp = temp->next;
//	}
//
//	remove("temp.dat");
//}
//
//template<typename T>
//void ModReq<T>::getData(Employee& emp, LQueue<ModReq>* modQ, char* field) {
//
//	this->id = ++count;
//	this->emp = emp;
//	cout << "\nEnter new data: ";
//	cin >> change;
//
//	memcpy(this->field, field, sizeof(this->field));
//
//	modQ->enQueue(*this);
//}
//
//template<typename T>
//void ModReq<T>::displayData() {
//	cout << "\nRequest id: " << id << endl;
//	cout << "\nmodification: " << change << endl;
//
//	cout << "\n\----------------";
//	cout << "\nUser Details: ";
//	emp.displayData();
//
//}

//FUNCTIONS
template<typename T>
Node<T>* Merge(Node<T>* h1, Node<T>* h2)
{
	Node<T>* t1 = new Node<T>;
	Node<T>* t2 = new Node<T>;
	Node<T>* temp = new Node<T>;

	if (h1 == NULL)
		return h2;

	if (h2 == NULL)
		return h1;

	t1 = h1;

	while (h2 != NULL)
	{
		t2 = h2;

		h2 = h2->next;
		t2->next = NULL;

		if (h1->data.name[0] > t2->data.name[0])
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}

	flag:
		if (t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		else if ((t1->next)->data.name[0] <= t2->data.name[0])
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}

	return h1;
}

template <typename T>
void MergeSort(Node<T>** head)
{
	Node<T>* first = new Node<T>;
	Node<T>* second = new Node<T>;
	Node<T>* temp = new Node<T>;
	first = *head;
	temp = *head;

	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}

	MergeSort(&first);
	MergeSort(&second);
   
	*head = Merge(first, second);
}

char* passwordValidate(const char* print) {
	char* variable = new char[15];
	while (1) {
		if (!(cin >> variable)) {
			cout << print;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (strlen(variable) >= 15) {
			cout << print;
			cin >> variable;
		}
		else {
			break;
		}
	}
	return variable;
}

int intValidate(const char* print) {
	int variable;
	while (1) {
		if (!(cin >> variable)) {
			cout << print;
			cin.clear();
			cin.ignore(20, '\n');
			continue;
		}

		break;
	}
	return variable;

}

template<class T>
int init_count(char* fileName) {                                            //initializes count to the last id found in the file
	fstream _file(fileName, ios::in | ios::binary);
	int i = 0;
	T buffer, lBuffer;
	while (_file.read((char*)&buffer, sizeof(T))) {
		lBuffer = buffer;
	}

	if (lBuffer.getId() < 1000) {
		return 1000;
	}

	return lBuffer.getId();
}

int Admin::count = 1000, Employee::count = 1000, LeaveReq::count = 1000;

int main() {
	fstream employeeFile("employee.dat", ios::in | ios::binary);
	int i = 0;
	Employee buffer;
	while (employeeFile.read((char*)&buffer, sizeof(Employee))) {
		i += 1;
		buffer.displayData();
	}

	Admin::init_admin();

	Admin::count = init_count<Admin>((char*)"admin.dat"); Employee::count = init_count<Employee>((char*)"employee.dat");
	LeaveReq::count = init_count<LeaveReq>((char*)"leavereq.dat");
	//ModReq<long long int>::count = init_count<ModReq<long long int>>((char*)"modreq.dat");
	//ModReq<char[50]>::count = init_count<ModReq<char[50]>>((char*)"modreq.dat");


	/*Employee emp1(1, (char*)"Barath", (char*)"support", 'm', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2021, (char*)"1234");
	Employee emp2(2, (char*)"Eswari", (char*)"manager", 'f', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2019, (char*)"1234");
	Employee emp3(3, (char*)"thirumoorthy", (char*)"support", 'm', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2015, (char*)"1234");
	Employee emp4(4, (char*)"Me", (char*)"support", 'm', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2015, (char*)"1234");
	Admin admin1(1, (char*)"ruthra", 'f', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2021, (char*)"1234");
	Admin admin2(2, (char*)"dhanu", 'f', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2019, (char*)"1234");
	Admin admin3(3, (char*)"amirtha", 'f', (char*)"Tirupur", (char*)"T.M.Poondi, Tirupur", 50000, 8778226764, (char*)"mymail@mail.com", 2015, (char*)"1234");
	*/
	LL<Employee>* empLL = new LL<Employee>;
	LL<Admin>* adminLL = new LL<Admin>;

	LQueue<LeaveReq>* leaveQ = new LQueue<LeaveReq>;
	LL<LeaveReq>* statusLL = new LL<LeaveReq>;
	/*
	empLL->appendNode(emp1);
	empLL->appendNode(emp2);
	empLL->appendNode(emp3);
	empLL->appendNode(emp4);
	*/


	Employee::fromTheFile(empLL);
	Admin::fromTheFile(adminLL);
	LeaveReq::fromTheFile(leaveQ);
	LeaveReq::fromTheFile(statusLL);

	int choice;
	Admin adminUser;
	Employee empUser;

	while (1) {
		cout << "\n\t\t\t______________________________________________";
		cout << "\n\n\t\t\t\t\t *LOGIN*\n\n";
		cout << "\n\t\t\t\t1.Admin";
		cout << "\n\t\t\t\t2.Employee user";
		cout << "\n\t\t\t\t3.Create user account";
		cout << "\n\t\t\t\t4.Back";
		cout << "\n\t\t\t______________________________________________";


		cout << "\n\nenter your choice: ";
		choice = intValidate("Enter a valid choice: ");

		switch (choice) {
		case 1:
			try {
				adminUser = Admin::login(adminLL);
				Admin::adminFunctions(adminUser, empLL, adminLL, leaveQ, statusLL);
			}
			catch (int ex) {
				continue;
			}

			break;
		case 2:
			try {
				empUser = Employee::login(empLL);
				Employee::empFunctions(empUser, empLL, leaveQ,statusLL);
				cout << "done";
			}
			catch (int ex) {
				continue;
			}
			break;
		case 3:
		{
			Employee u;
			u.getData();
			cout << "account created!!!-"<<u.getId() << endl;
		}
		break;
		case 4:
			Employee::allToFile(empLL);
			Admin::allToFile(adminLL);
			LeaveReq::allToFile(leaveQ);
			LeaveReq::allToFile(statusLL);
			exit(0);

		default:
			cout << "enter a valid choice!( 1-4 )" << endl;
		}
	}

	return 0;

	//empLL.deleteNode(2);

	//empLL.searchNode(3)->data.displayData();

	//empLL.displayLL();
	

	//Employee::fromTheFile(empLL);
	//empLL->displayLL();

	//MergeSort(&empLL->head);
	//cout << "after sorting";
	//empLL->displayLL();
	//Admin::sortingByName(empLL);

	//Admin::fromTheFile(adminLL);
	//adminLL->displayLL();

	

	
}																																																											