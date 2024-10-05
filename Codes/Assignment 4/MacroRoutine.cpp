#include "MacroRoutine.h"
#include <algorithm>
#include <iostream>

void MacroRoutine::addProcedure(Command* command) {
    commands.push_back(command);
}

void MacroRoutine::removeProcedure(Command* command) {
    commands.erase(std::remove(commands.begin(), commands.end(), command), commands.end());
}

void MacroRoutine::execute() {
    for (Command* command : commands) {
        command->execute();
    }
}
