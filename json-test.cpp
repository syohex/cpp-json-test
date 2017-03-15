#include "json.hpp"

#include <iostream>
#include <string>

using json = nlohmann::json;

namespace {
	void testfunc1() {
		std::cout << "## NOT_FOUND_KEY test ##" << std::endl;

		json j;
		try {
			std::string not_found_value = j["not_found"].get<std::string>();
			std::cout << "not_found_value='" << not_found_value << "'" << std::endl;
		} catch(std::domain_error& e) {
			// access not existing key causes exception
			std::cout << "Error not_found_key:" << e.what() << std::endl;
		}
	}

	void testfunc2() {
		std::cout << "## json array  ##" << std::endl;

		json j = json::array();
		try {
			j["hoge"] = 10;
		} catch(std::domain_error& e) {
			// Using string key for array causes exception
			std::cout << "Error array with string index:" << e.what() << std::endl;
		}
	}
} // namespace

int main(void)
{
	std::string input("{\"foo\": \"bar\" }");
	json j;

	try {
		j = json::parse(input);
	} catch(std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << j.dump() << std::endl;

	testfunc1();
	testfunc2();

	return 0;
}
