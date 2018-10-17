#include "Robot.entity.hpp"

Robot::Robot() {
}

void Robot::ParseScripts(sol::state& state) {
	sol::load_result loadedFile = state.load_file("Robot.lua");

	if (loadedFile.valid()) {
		loadedFile();
		sol::table table = state["Robot"];

		MapFunctions(state, table);
	};
}

void Robot::MapFunctions(sol::state& state, sol::table& table) {
	try {
		std::unordered_map<std::string, sol::reference> result;

		if (table.get_type() == sol::type::table) {

			if (!table.valid()) {
				std::cout << "Table is invalid" << std::endl;
				return;
			}

			for (auto& t : table) {
				auto k = t.first;
				auto v = t.second;
				result.emplace(k.as<std::string>(), v.as<sol::reference>());
			}

		}
		else {
			std::cout << "Element is not a table" << std::endl;
		}

		for (auto pair : result)
		{
			//-- Map functions
			if (pair.second.get_type() == sol::type::function) {
				scripts[pair.first] = std::make_unique<sol::function>(pair.second);
			}
		}

		result.clear();
	}
	catch (sol::error const& e) {
		std::cout << "CFunctionAction : LuaException: " << e.what() << std::endl;
	}
}

bool Robot::CallScript(std::string scriptName) {
	bool found = false;

	for (auto &pair : scripts)
	{
		if (pair.first == scriptName) {

			if (pair.second) {
				try {
					found = true;
					(*pair.second)(this);
				}
				catch (sol::error const& e) {
					std::cout << "LuaException: " << e.what() << std::endl;
				}
			}
		}
	}

	return found;
}

void Robot::SpeakItalian() {
	std::cout << "It's -a- me, Mario !" << std::endl;
}
void Robot::SpeakHylian() {
	std::cout << "Hyaaaaahhhh, HA, HYA, ARRRGH" << std::endl;
}
void Robot::SpeakLatin() {
	std::cout << "Lorem ipsum dolor sit amet" << std::endl;
}