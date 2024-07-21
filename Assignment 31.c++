new and delete operator, Inheritance

1. Define a class Person with instance members name and age. Also define member
functions setName(), setAge(), getName(), getAge(). Now define class Employee by
inheriting Person class. In the Employee class define empid and salary as instance
members. Also define setEmpid, setSalary, getEmpid, getSalary.
2. Write a C++ program to add two numbers using single inheritance. Accept these two
numbers from the user in base class and display the sum of these two numbers in
derived class.
3. Write a C++ program to calculate the percentage of a student using multi-level
inheritance. Accept the marks of three subjects in base class. A class will be derived
from the above mentioned class which includes a function to find the total marks
obtained and another class derived from this class which calculates and displays the
percentage of students.
4. Write a C++ program to design a base class Person (name, address,
phone_no). Derive a class Employee (eno, ename) from Person. Derive a
class Manager (designation, department name, basic-salary) from
Employee. Write a menu driven program to:
a. Accept all details of 'n' managers.
b. Display manager having highest salary
Output -

5. Write a C++ program to define a base class Item (item-no, name, price).
Derive a class Discounted-Item (discount-percent). A customer purchases

'n' items. Display the item-wise bill and total amount using appropriate
format.
Output -

6. Write a C++ program to demonstrate how a common friend function can
be used to exchange the private values of two classes. (Use call by
reference method).
7. Write class declarations and member function definitions for a C++ base
class to represent an Employee (emp-code, name).
Derive two classes as Fulltime (daily rate, number of days, salary) and
Parttime (number of working hours, hourly rate, salary).
Write a menu driven program to:
1. Accept the details of ‘n’ employees.
2. Display the details of ‘n’ employees.

3. Search a given Employee by emp-code.
Output -

8 - In a bank, different customers have savings account. Some customers may
have taken a loan from the bank. So bank always maintain information about
bank depositors and borrowers.
Design a Base class Customer (name, phone-number). Derive a class
Depositor(accno, balance) from Customer.
Again, derive a class Borrower (loan-no, loan-amt) from Depositor.
Write necessary member functions to read and display the details of ‘n’
customers.

Output -

9. Write a C++ program to implement the following class hierarchy:
Student: id, name
StudentExam (derived from Student): Marks of 6 subjects
StudentResult (derived from StudentExam) : percentage
Define appropriate functions to accept and display details.
Create 'n' objects of the StudentResult class and display the marklist.
Output -

10. Consider two base classes
worker(int code, char name, float salary),
officer(float DA, HRA)
class manger(float TA(is 10% of salary), gross salary) is derived from both base

Solution:-

1. #include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    string getName() { return name; }
    int getAge() { return age; }
};

class Employee : public Person {
private:
    int empid;
    float salary;
public:
    void setEmpid(int empid) { this->empid = empid; }
    void setSalary(float salary) { this->salary = salary; }
    int getEmpid() { return empid; }
    float getSalary() { return salary; }
};

int main() {
    Employee emp;
    emp.setName("John Doe");
    emp.setAge(30);
    emp.setEmpid(123);
    emp.setSalary(50000);

    cout << "Employee Details:" << endl;
    cout << "Name: " << emp.getName() << endl;
    cout << "Age: " << emp.getAge() << endl;
    cout << "Employee ID: " << emp.getEmpid() << endl;
    cout << "Salary: " << emp.getSalary() << endl;

    return 0;
}

2. #include <iostream>
using namespace std;

class Base {
protected:
    int num1, num2;
public:
    void setNumbers(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }
};

class Derived : public Base {
public:
    void displaySum() {
        cout << "Sum: " << num1 + num2 << endl;
    }
};

int main() {
    Derived obj;
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    obj.setNumbers(n1, n2);
    obj.displaySum();
    return 0;
}

3. #include <iostream>
using namespace std;

class Base {
protected:
    int marks1, marks2, marks3;
public:
    void setMarks(int m1, int m2, int m3) {
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }
};

class Intermediate : public Base {
protected:
    int totalMarks;
public:
    void calculateTotal() {
        totalMarks = marks1 + marks2 + marks3;
    }
    int getTotalMarks() { return totalMarks; }
};

class Derived : public Intermediate {
public:
    void displayPercentage() {
        float percentage = (totalMarks / 3.0);
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Derived student;
    int m1, m2, m3;
    cout << "Enter marks for three subjects: ";
    cin >> m1 >> m2 >> m3;
    student.setMarks(m1, m2, m3);
    student.calculateTotal();
    student.displayPercentage();
    return 0;
}

4. #include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string address;
    string phone_no;
public:
    void setData(string name, string address, string phone_no) {
        this->name = name;
        this->address = address;
        this->phone_no = phone_no;
    }
};

class Employee : public Person {
protected:
    int eno;
    string ename;
public:
    void setEmployeeData(int eno, string ename) {
        this->eno = eno;
        this->ename = ename;
    }
};

class Manager : public Employee {
private:
    string designation;
    string department_name;
    float basic_salary;
public:
    void setManagerData(string designation, string department_name, float basic_salary) {
        this->designation = designation;
        this->department_name = department_name;
        this->basic_salary = basic_salary;
    }
    float getSalary() { return basic_salary; }
    void displayManager() {
        cout << "Name: " << ename << ", Designation: " << designation
             << ", Department: " << department_name << ", Salary: " << basic_salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    vector<Manager> managers(n);
    string name, address, phone_no, ename, designation, department_name;
    int eno;
    float basic_salary;

    for (int i = 0; i < n; i++) {
        cout << "Enter details of manager " << i + 1 << ": " << endl;
        cout << "Name: ";
        cin >> ename;
        cout << "Address: ";
        cin >> address;
        cout << "Phone No: ";
        cin >> phone_no;
        cout << "Employee No: ";
        cin >> eno;
        cout << "Designation: ";
        cin >> designation;
        cout << "Department Name: ";
        cin >> department_name;
        cout << "Basic Salary: ";
        cin >> basic_salary;

        managers[i].setData(name, address, phone_no);
        managers[i].setEmployeeData(eno, ename);
        managers[i].setManagerData(designation, department_name, basic_salary);
    }

    float highestSalary = managers[0].getSalary();
    int highestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (managers[i].getSalary() > highestSalary) {
            highestSalary = managers[i].getSalary();
            highestIndex = i;
        }
    }

    cout << "Manager with highest salary: " << endl;
    managers[highestIndex].displayManager();

    return 0;
}

5. #include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
    int item_no;
    string name;
    float price;
public:
    void setItemData(int item_no, string name, float price) {
        this->item_no = item_no;
        this->name = name;
        this->price = price;
    }
    float getPrice() { return price; }
    void displayItem() {
        cout << "Item No: " << item_no << ", Name: " << name << ", Price: " << price << endl;
    }
};

class DiscountedItem : public Item {
private:
    float discount_percent;
public:
    void setDiscount(float discount_percent) {
        this->discount_percent = discount_percent;
    }
    float calculateDiscount() {
        return price - (price * discount_percent / 100);
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<DiscountedItem> items(n);
    int item_no;
    string name;
    float price, discount_percent;

    for (int i = 0; i < n; i++) {
        cout << "Enter details of item " << i + 1 << ": " << endl;
        cout << "Item No: ";
        cin >> item_no;
        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Discount Percent: ";
        cin >> discount_percent;

        items[i].setItemData(item_no, name, price);
        items[i].setDiscount(discount_percent);
    }

    float totalAmount = 0;
    for (int i = 0; i < n; i++) {
        items[i].displayItem();
        float discountedPrice = items[i].calculateDiscount();
        cout << "Discounted Price: " << discountedPrice << endl;
        totalAmount += discountedPrice;
    }

    cout << "Total Amount: " << totalAmount << endl;

    return 0;
}

6. #include <iostream>
using namespace std;

class Class1;
class Class2;

class Class1 {
private:
    int value1;
public:
    void setValue(int value) { value1 = value; }
    void display() { cout << "Class1 Value: " << value1 << endl; }
    friend void exchange(Class1&, Class2&);
};

class Class2 {
private:
    int value2;
public:
    void setValue(int value) { value2 = value; }
    void display() { cout << "Class2 Value: " << value2 << endl; }
    friend void exchange(Class1&, Class2&);
};

void exchange(Class1 &c1, Class2 &c2) {
    int temp = c1.value1;
    c1.value1 = c2.value2;
    c2.value2 = temp;
}

int main() {
    Class1 obj1;
    Class2 obj2;

    obj1.setValue(100);
    obj2.setValue(200);

    cout << "Before exchange:" << endl;
    obj1.display();
    obj2.display();

    exchange(obj1, obj2);

    cout << "After exchange:" << endl;
    obj1.display();
    obj2.display();

    return 0;
}

7. #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int emp_code;
    string name;
public:
    Employee(int code = 0, string emp_name = "") : emp_code(code), name(emp_name) {}
    virtual void accept() = 0;
    virtual void display() const = 0;
    int getEmpCode() const { return emp_code; }
};

class Fulltime : public Employee {
private:
    float daily_rate;
    int number_of_days;
    float salary;
public:
    Fulltime(int code = 0, string emp_name = "", float rate = 0, int days = 0)
        : Employee(code, emp_name), daily_rate(rate), number_of_days(days), salary(rate * days) {}

    void accept() override {
        cout << "Enter Fulltime Employee Details: " << endl;
        cout << "Employee Code: ";
        cin >> emp_code;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Daily Rate: ";
        cin >> daily_rate;
        cout << "Number of Days: ";
        cin >> number_of_days;
        salary = daily_rate * number_of_days;
    }

    void display() const override {
        cout << "Fulltime Employee Details:" << endl;
        cout << "Employee Code: " << emp_code << endl;
        cout << "Name: " << name << endl;
        cout << "Daily Rate: " << daily_rate << endl;
        cout << "Number of Days: " << number_of_days << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Parttime : public Employee {
private:
    int number_of_hours;
    float hourly_rate;
    float salary;
public:
    Parttime(int code = 0, string emp_name = "", int hours = 0, float rate = 0)
        : Employee(code, emp_name), number_of_hours(hours), hourly_rate(rate), salary(hours * rate) {}

    void accept() override {
        cout << "Enter Parttime Employee Details: " << endl;
        cout << "Employee Code: ";
        cin >> emp_code;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Number of Working Hours: ";
        cin >> number_of_hours;
        cout << "Hourly Rate: ";
        cin >> hourly_rate;
        salary = number_of_hours * hourly_rate;
    }

    void display() const override {
        cout << "Parttime Employee Details:" << endl;
        cout << "Employee Code: " << emp_code << endl;
        cout << "Name: " << name << endl;
        cout << "Number of Working Hours: " << number_of_hours << endl;
        cout << "Hourly Rate: " << hourly_rate << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    vector<Employee*> employees;
    int choice, emp_type, n, emp_code;

    while (true) {
        cout << "1. Add Employee\n2. Display All Employees\n3. Search Employee by Code\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of employees to add: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter type of employee (1 for Fulltime, 2 for Parttime): ";
                    cin >> emp_type;
                    Employee* emp;
                    if (emp_type == 1) {
                        emp = new Fulltime();
                    } else {
                        emp = new Parttime();
                    }
                    emp->accept();
                    employees.push_back(emp);
                }
                break;
            case 2:
                for (const auto& emp : employees) {
                    emp->display();
                    cout << endl;
                }
                break;
            case 3:
                cout << "Enter employee code to search: ";
                cin >> emp_code;
                for (const auto& emp : employees) {
                    if (emp->getEmpCode() == emp_code) {
                        emp->display();
                        break;
                    }
                }
                break;
            case 4:
                for (const auto& emp : employees) {
                    delete emp;
                }
                employees.clear();
                return 0;
        }
    }
}

8. #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer {
protected:
    string name;
    string phone_number;
public:
    void setData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone_number);
    }
    void display() {
        cout << "Name: " << name << ", Phone Number: " << phone_number << endl;
    }
};

class Depositor : public Customer {
protected:
    int acc_no;
    float balance;
public:
    void setData() {
        Customer::setData();
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Balance: ";
        cin >> balance;
    }
    void display() {
        Customer::display();
        cout << "Account Number: " << acc_no << ", Balance: " << balance << endl;
    }
};

class Borrower : public Depositor {
protected:
    int loan_no;
    float loan_amt;
public:
    void setData() {
        Depositor::setData();
        cout << "Enter Loan Number: ";
        cin >> loan_no;
        cout << "Enter Loan Amount: ";
        cin >> loan_amt;
    }
    void display() {
        Depositor::display();
        cout << "Loan Number: " << loan_no << ", Loan Amount: " << loan_amt << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    vector<Borrower> borrowers(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for customer " << i + 1 << ":\n";
        borrowers[i].setData();
    }

    cout << "\nCustomer Details:\n";
    for (int i = 0; i < n; ++i) {
        borrowers[i].display();
    }

    return 0;
}

9. #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
protected:
    int id;
    string name;
public:
    void setData() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

class StudentExam : public Student {
protected:
    int marks[6];
public:
    void setMarks() {
        cout << "Enter marks for 6 subjects:\n";
        for (int i = 0; i < 6; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
    void displayMarks() {
        cout << "Marks: ";
        for (int i = 0; i < 6; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class StudentResult : public StudentExam {
public:
    void displayPercentage() {
        int total = 0;
        for (int i = 0; i < 6; ++i) {
            total += marks[i];
        }
        float percentage = total / 6.0;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<StudentResult> students(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].setData();
        students[i].setMarks();
    }

    cout << "\nStudent Results:\n";
    for (int i = 0; i < n; ++i) {
        students[i].display();
        students[i].displayMarks();
        students[i].displayPercentage();
    }

    return 0;
}

10. #include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
    int code;
    string name;
    float salary;
public:
    Worker(int c, string n, float s) : code(c), name(n), salary(s) {}
    void displayWorker() {
        cout << "Code: " << code << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

class Officer {
protected:
    float DA;
    float HRA;
public:
    Officer(float d, float h) : DA(d), HRA(h) {}
    void displayOfficer() {
        cout << "DA: " << DA << ", HRA: " << HRA << endl;
    }
};

class Manager : public Worker, public Officer {
private:
    float TA;
    float gross_salary;
public:
    Manager(int c, string n, float s, float d, float h) : Worker(c, n, s), Officer(d, h) {
        TA = 0.1 * salary;
        gross_salary = salary + DA + HRA + TA;
    }
    void displayManager() {
        displayWorker();
        displayOfficer();
        cout << "TA: " << TA << ", Gross Salary: " << gross_salary << endl;
    }
};

int main() {
    Manager m1(101, "John", 50000, 5000, 4000);
    m1.displayManager();
    return 0;
}
