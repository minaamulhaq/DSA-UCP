
#include"OfflineCourse.h"
#include"OnlineCourse.h"

int main() {
    OnlineCourse oc(6, 10);   
    OfflineCourse ofc(3, 5); 

    oc.duration();
    ofc.duration();

    return 0;
}