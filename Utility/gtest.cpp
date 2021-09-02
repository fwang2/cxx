#include <iostream>

// note this is defined before including logging.h
#define NDEBUG
#include <glog/logging.h>
#include <stdio.h>
using namespace std;


int main(int argc, char* argv[]) {
    fclose(stderr);
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "Hello 2" << endl; 
    DLOG(INFO) << "Dlog info" << endl;
    LOG(ERROR) << "Error message" << endl;
    cerr << "You should not see stderr" << endl;
    cout << "You should see stdout" << endl;
}

