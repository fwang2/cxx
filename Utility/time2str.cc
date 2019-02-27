// demo: convert time to string format

#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;
int main(void) {
    time_t now = time(0);
    stringstream ss;
    string path;
    // convert now to string form
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;
    tm * ltm = localtime(&now);
    ss << (1900+ltm->tm_year) << "-";
    ss.width(2);
    ss.fill('0');
    ss << (1 + ltm->tm_mon) << "-";
    ss.width(2);
    ss << ltm->tm_mday << "-";
    ss.width(2);
    ss << ltm->tm_hour;
    ss.width(2);
    ss << ltm->tm_min;
    ss.width(2);
    ss << ltm->tm_sec;
    cout << ss.str() << endl;
    return 0;
}
