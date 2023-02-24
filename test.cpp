#include <StateMachine.h>
#include <stdio.h>
#include <iostream>

class StateA : public StateMachine::State
{
    bool CanEnterState(const State* previousState) const override
    {
        return false;
    }

    void OnEnterState(StateMachine::State* previous) override
    {
        printf("Entering State A\n");
    }

    void OnExitState(StateMachine::State* next) override
    {
        printf("Exiting State A\n");
    }

    void OnUpdate() override
    {

    }
};

class StateB : public StateMachine::State
{
    void OnEnterState(StateMachine::State* previous) override
    {
        printf("Entering State B\n");
    }

    void OnExitState(StateMachine::State* next) override
    {
        printf("Exiting State B\n");
    }

    void OnUpdate() override
    {

    }
};

class TestClass
{
    public:
    StateMachine::StateMachine stateMachine;
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
    }
}