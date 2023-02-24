#pragma once
#include <State.h>

namespace StateMachine
{

    class StateMachine
    {
    private:
        State* currentState;
        bool canChange(const State* next);
    public:
        StateMachine();
        //sets currentState = next if both current->CanExitState() and next->CanEnterState() return true. If current == next, nothing happens
        void trySetState(State* next);
        //same as trySetState, but OnExitState and OnEnterState will trigger even if current == next
        void tryResetState(State* next);
        //same as trySetState, but does not check canEnter or canExit 
        void forceSetState(State* next);
        //same as tryResetState, but does not check canEnter or canExit  
        void forceResetState(State* next);
        const State* getCurrentState() const{return currentState;}
    };

}