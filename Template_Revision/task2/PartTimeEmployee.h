
// #include"Employee.h"
class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    void setDetails(int hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};