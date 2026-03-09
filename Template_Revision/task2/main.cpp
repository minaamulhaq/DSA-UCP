

#include"FullTimeEmployee.h"
#include"PartTimeEmployee.h"
int main() {
    FullTimeEmployee fullTime;
    PartTimeEmployee partTime;

    fullTime.setSalary(50000);      
    partTime.setDetails(20, 500);    

   
    cout << "Full-Time Employee Salary: " << fullTime.calculateSalary() << endl;
    cout << "Part-Time Employee Salary: " << partTime.calculateSalary() << endl;

    return 0;
}