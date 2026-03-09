// #include"Course.h"
class OnlineCourse : public Course {
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h) {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration() {
        int totalHours = weeks * hoursPerWeek;
        cout << "Online Course Duration: " << totalHours << " hours" << endl;
    }
};