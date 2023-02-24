#include <StateMachine.h>

namespace StateMachine
{
    StateMachine::StateMachine()
    {
        currentState = nullptr;
    }

    void StateMachine::trySetState(State* next)
    {
        if(canChange(next))      
            forceSetState(next);
    }

    void StateMachine::tryResetState(State* next)
    {
        if(canChange(next))
            forceResetState(next);
    }

    void StateMachine::forceSetState(State* next)
    {
        if(currentState != next)
            forceResetState(next);
    }

    void StateMachine::forceResetState(State* next)
    {
        if(currentState != nullptr)
            currentState->OnExitState(next);
        State* previous = currentState;
        currentState = next;
        currentState->OnEnterState(previous);
    }

    bool StateMachine::canChange(const State* next)
    {
        bool canDo = true;
        if(currentState != nullptr)
            canDo = canDo && currentState->CanExitState(next);
        
        if(next != nullptr)
            canDo = canDo && next->CanEnterState(currentState);
        else
            canDo = false;

        return canDo;
    }
}