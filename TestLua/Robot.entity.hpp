#ifndef robot_entity_hpp
#define robot_entity_hpp

#include "sol.hpp"
#include <stdlib.h>
#include <string>
#include <map>
#include <memory>

class Robot {

public:

	Robot();

	void ParseScripts(sol::state& state);

	void MapFunctions(sol::state& state, sol::table& table);

	bool CallScript(std::string scriptName);

	void SpeakItalian();
	void SpeakHylian();
	void SpeakLatin();

private:
	std::map<std::string, std::unique_ptr<sol::function>> scripts;

};

#endif