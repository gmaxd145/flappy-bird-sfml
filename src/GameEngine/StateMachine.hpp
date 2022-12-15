#pragma once

#include "State.hpp"

#include <memory>
#include <stack>

typedef std::unique_ptr<State> statePtr;

class StateMachine
{
public:
    void addState(statePtr newState, bool isReplacing = true);
    void removeState();

    void processStateChanges();

    statePtr& getActiveState();

private:
    std::stack<statePtr> _states;
    statePtr _newState;

    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};