#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <locale>

int main(void) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;
    using namespace std;
    // get current time from the clock
    ptime now = second_clock::local_time();
    date today = now.date();
    date_facet df;
    df.set_iso_format();
    cout.imbue(locale(cout.getloc()), &df);
    cout << today << endl;
    return 0;
}
