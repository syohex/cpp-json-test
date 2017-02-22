#include "json.hpp"

#include <string>

using json = nlohmann::json;

int main(void)
{
	std::string input("{\"foo\":bar,}");
	json j;

	try {
		j = json::parse(input);
	} catch(std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << j.dump() << std::endl;
	return 0;
}
