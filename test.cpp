#include <StateMachine.h>
#include <stdio.h>
#include <iostream>

using namespace StateMachines;

class StateA : public State
{
    bool CanEnterState(const State* previousState) const override
    {
        return false;
    }

    void OnEnterState(State* previous) override
    {
        printf("Entering State A\n");
    }

    void OnExitState(State* next) override
    {
        printf("Exiting State A\n");
    }

    void OnUpdate() override
    {
        printf("I'm on state A!\n");
    }
};

class StateB : public State
{
    void OnEnterState(State* previous) override
    {
        printf("Entering State B\n");
    }

    void OnExitState(State* next) override
    {
        printf("Exiting State B\n");
    }

    void OnUpdate() override
    {
        printf("I'm on state B!\n");
    }
};

class TestClass
{
    public:
    StateMachines::StateMachine<State> stateMachine;
    StateA stateA;
    StateB stateB;
};

int main()
{
    TestClass test;
    test.stateMachine.forceSetState(&test.stateA);


    char input = 'a';
    while(input != 'x')
    {
        std::cin >> input;
        if(input=='b')
            test.stateMachine.trySetState(&test.stateB);
        else if(input=='a')
            test.stateMachine.trySetState(&test.stateA);
        else if (input=='A')
        {
            test.stateMachine.forceResetState(&test.stateA);
        }
        test.stateMachine.getCurrentState()->OnUpdate();
    }
}