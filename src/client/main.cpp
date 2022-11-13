#include <iostream>
#include <vector>
#include <string>

#include "supervisor.hpp"

using namespace std;

int main(int argc, char** argv) {
    auto services = supervisor::get_services();

    for(auto service : services) {
        bool state = supervisor::get_state_by_name(service);
        cout << service << " : " << (state ? "online" : "offline") << endl;
    }
}
