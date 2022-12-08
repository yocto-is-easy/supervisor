#include <map>
#include <string>
#include <mutex>
#include <thread>

#include "supervisor.hpp"

using namespace std;

INIT_MIDF_SERVER(supervisor);

std::map<string, midf::function<bool>> callbacks;

MIDF_IMPL_FUNC(int, supervisor, inform_about_me, midf::function<bool>) (midf::function<bool> callback) {
    callbacks[callback.of_service()] = callback;
    return 0;
}

MIDF_IMPL_FUNC(std::vector<std::string>, supervisor, get_services) () {
    std::vector<std::string> ret;
    for(const auto& cb : callbacks) {
        ret.push_back(cb.first);
    }
    return ret;
}

MIDF_IMPL_FUNC(bool, supervisor, get_state_by_name, std::string) (std::string service_name) {
    if(callbacks.find(service_name) != callbacks.end()) {
        try {
            return callbacks[service_name]();
        } catch(const std::exception& e) {
            return false;
        }
    }
    return false;
}

int main() {
    START_MIDF_SERVER_WITHOUT_OBSERVER(supervisor);
}
