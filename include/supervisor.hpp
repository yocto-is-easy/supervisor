#pragma once

#include <vector>
#include <string>

#include <midf.hpp>

MIDF_DECL_PORT(supervisor, 9999);

MIDF_DECL_FUNC(int, supervisor, inform_about_me, midf::function<bool>);

MIDF_DECL_FUNC_NO_ARGS(std::vector<std::string>, supervisor, get_services);
MIDF_DECL_FUNC(bool, supervisor, get_state_by_name, std::string);
