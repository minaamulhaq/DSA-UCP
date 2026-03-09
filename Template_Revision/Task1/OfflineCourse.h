#include"Course.h"
class OfflineCourse : public Course {
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h) {
        months = m;
        hoursPerDay = h;
    }

    void duration() {
        int totalHours = months * 30 * hoursPerDay;
        cout << "Offline Course Duration: " << totalHours << " hours" << endl;
    }
};
