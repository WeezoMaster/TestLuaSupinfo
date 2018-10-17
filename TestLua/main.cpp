
#include <iostream>
#include "sol.hpp"
#include <stdlib.h>
#include <string>
#include "Robot.entity.hpp"

void bindEntities(sol::state& state) {
	state.new_usertype<Robot>("Robot", sol::constructors<Robot()>(),
		"SpeakItalian", &Robot::SpeakItalian,
		"SpeakHylian", &Robot::SpeakHylian,
		"SpeakLatin", &Robot::SpeakLatin
		);
}

int main() {

	std::string userChoice;

	sol::state state;
	state.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);
	bindEntities(state);

	Robot robot;
	robot.ParseScripts(state);
	robot.CallScript("OnInit");

	while (userChoice != "exit") {
		std::getline(std::cin, userChoice);

		if (!robot.CallScript(userChoice))
			std::cout << "Script non trouve" << std::endl;
	}

}
