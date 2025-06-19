
#include <iostream>
#include "Command.h"

int main()
{
    std::shared_ptr<CommandBase> cmd = std::make_shared<AddCommand>();
    CommandManager mgr;
    mgr.excuteCommand(cmd);
    mgr.undo();
    mgr.redo();
}
