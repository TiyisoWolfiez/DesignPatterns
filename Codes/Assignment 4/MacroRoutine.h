#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include <vector>
#include <algorithm>
#include "Command.h"

class MacroRoutine {
public:
    void execute();
    void addProcedure(Command* command);
    void removeProcedure(Command* command);

private:
    std::vector<Command*> commands;
};

#endif // MACROROUTINE_H
