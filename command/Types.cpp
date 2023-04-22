//
// Created by mszawerd on 22.04.23.
//
#include "Types.h"
#include <iostream>

void Application::executeCommand(Command* command) {
    if (command->execute()) {
        history.push(command);
    }
}

void Application::undo() {
    Command *command = history.pop();
    if (command != nullptr) {
        command->undo();
        delete command;
    }
}

void Application::run() {
    printf("Provide initial string\n");
    std::string init;
    std::getline(std::cin, init);
    Editor editor(init);
    std::cout<<"1. Append\n2.Remove\n3.Copy\n4.Undo\n";
    std::cout<<editor.getText()<<"\n";
    int choose;
    std::cin >> choose;
    while (std::cin) {
        switch (choose) {
            case 1: {
                executeCommand(new AppendCommand(*this, editor));
            }
                break;
            case 2: {
                executeCommand(new RemoveCommand(*this, editor));
            }
                break;
            case 3: {
                executeCommand(new CopyCommand(*this, editor));
            }
                break;
            case 4:
                undo();
                break;
            default:
                break;
        }
        std::cout<<editor.getText()<<"\n";
        std::cout<<"1. Append\n2.Remove\n3.Copy\n4.Undo\n";
        std::cin>>choose;
    }
}