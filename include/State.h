#pragma once
namespace StateMachine{

    class State
    {
    public:
        virtual bool CanEnterState(const State* previousState) const {return true;}
        virtual bool CanExitState(const State* nextState) const {return true;}
        virtual void OnEnterState(State* previousState) = 0;
        virtual void OnExitState(State* nextState) = 0;
        virtual void OnUpdate() = 0;
    };
}