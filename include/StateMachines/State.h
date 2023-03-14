#pragma once
namespace StateMachines{

    /*this class is templated so you can control the type of the arguments that are passed to the functions
    Almost always, the way it is supposed to be used is:
        
    class My_State : public State<My_State> 
    {};

    ...

    class Whatever
    {
        StateMachine<My_State> sm;
        ...
    };

    That way, inside of (for example) CanExitState(next), you know that the next state is not just any State, but specifically My_State, and can access its members accordingly.
    */

    template <class T>
    class State
    {
    public:
        virtual State() = 0;
        virtual State(State<T> other) = 0;
        virtual ~State() = 0;

        virtual bool CanEnterState(const T* previousState) const {return true;}
        virtual bool CanExitState(const T* nextState) const {return true;}
        virtual void OnEnterState(T* previousState) = 0;
        virtual void OnExitState(T* nextState) = 0;
        virtual void OnUpdate() = 0;
    };
}