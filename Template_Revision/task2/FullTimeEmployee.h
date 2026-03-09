#include"Employee.h"
class FullTimeEmployee : public Employee {
private:
    double fixedSalary;

public:
    void setSalary(double salary) {
        fixedSalary = salary;
    }

    double calculateSalary() {
        return fixedSalary;
    }
};