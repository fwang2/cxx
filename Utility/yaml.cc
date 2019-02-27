#include <iostream>
#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>
using namespace std;

struct Bentry {
    string ip;
    int port;
    string devname;
};

namespace YAML {
    template<>
    struct convert<Bentry> {
        static Node encode(const Bentry& rhs) {
            Node node;
            node.push_back(rhs.ip);
            node.push_back(rhs.port);
            node.push_back(rhs.devname);
            return node;
        }

        static bool decode(const Node& node, Bentry& rhs) {
            if (!node.IsSequence() || node.size() !=3)
                return false;
            rhs.ip = node[0].as<string>();
            rhs.port = node[1].as<int>();
            rhs.devname = node[2].as<string>();
            return true;
        }
    };
}


int main(int argc, char** argv) {

    // read yaml and see where we will be listening to?

    YAML::Node config = YAML::LoadFile("bbx.yaml");

    Bentry b;

    if (config["bbs"] && config["bbs"].IsSequence()) {
        const YAML::Node& bbsVec = config["bbs"];
        for (size_t i=0; i < bbsVec.size(); i++) {
            b = bbsVec[i].as<Bentry>();
            cout << "IP = " << b.ip
                    << ", Port= " << b.port
                    << ", Dev name = " << b.devname << endl;
        }

    }
    // locate and check raw device

    // initialize it and build up metadata store

    // ping MDS and report the liveness

    // accept connection

    return 0;
}

