#pragma once

#include <stack>
#include <algorithm>
#include <memory>

struct CommandParam {
    double val;
};

class CommandBase {
public:
    virtual void excute() = 0;
    virtual void undo() = 0;
    virtual void redo()
    {
        excute();
    }

    void setCommandParam(const CommandParam& para)
    {
        m_param = para;
    }

protected:
    CommandParam m_param;
};

class AddCommand : public CommandBase {
public:
    void excute() override
    {
        m_param.val++;
    }

    void undo() override
    {
        m_param.val--;
    }

};

class SqrtCommand : public CommandBase {
public:
    void excute() override
    {
        m_param.val = pow(m_param.val, 2);
    }

    void undo() override
    {
        m_param.val = sqrt(m_param.val);
    }
};

class CommandManager {
public:
    void excuteCommand(std::shared_ptr<CommandBase> cmd)
    {
        cmd->excute();
        m_undoStack.push(cmd);
    }

    void undo()
    {
        if (!m_undoStack.empty())
        {
            auto cmd = m_undoStack.top();
            cmd->undo();
            m_undoStack.pop();
            m_redoStack.push(cmd);
        }
    }

    void redo()
    {
        if (!m_redoStack.empty())
        {
            auto cmd = m_redoStack.top();
            cmd->redo();
            m_redoStack.pop();
            m_undoStack.push(cmd);
        }
    }

private:
    std::stack<std::shared_ptr<CommandBase>> m_undoStack;
    std::stack<std::shared_ptr<CommandBase>> m_redoStack;
};