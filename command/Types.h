//
// Created by mszawerd on 22.04.23.
//
#include <string>
#include <utility>
#include <vector>
#ifndef COMMAND_TYPES_H
#define COMMAND_TYPES_H
class Editor {
    std::string text;
public:
    Editor(std::string text): text(std::move(text)){}
    std::string getText(){
        return text;
    }

    void setText(std::string const& new_text){
        text = std::string(new_text);
    }

    void appendText(std::string const& new_text){
        text.append(new_text);
    }

    void removeLastChars(size_t toRemove){
        toRemove = std::min(toRemove, text.size());
        text.erase(text.size()-toRemove);
    }
};
class Command;
class CommandHistory{
    std::vector<Command*> history;
public:
    void push(Command* c){
        history.push_back(c);
    }

    Command* pop(){
        if(!history.empty()){
            Command* last = history.back();
            history.pop_back();
            return last;
        }
        return nullptr;
    }
    ~CommandHistory(){
        for(auto c: history){
            delete c;
        }
    }
};
class Application {
    std::string clipboard;
    CommandHistory history;
public:
    std::string getClipboard(){
        return clipboard;
    }

    void setClipboard(std::string text){
        clipboard = std::move(text);
    }

    void executeCommand(Command* command);
    void undo();
    void run();
};

class Command {
protected:
    Application& app;
    Editor& editor;
    std::string  backup;
public:
    Command(Application& app, Editor& editor): app(app), editor(editor){}
    void saveBackup(){
        backup = editor.getText();
    }

    void undo(){
        editor.setText(backup);
    }

    virtual bool execute()=0;
    virtual ~Command()=default;
};

class AppendCommand: public Command {
public:
    AppendCommand(Application& app, Editor& editor): Command(app, editor){}

    bool execute() override {
        saveBackup();
        editor.appendText(app.getClipboard());
        return true;
    }
};

class RemoveCommand: public Command {
public:
    RemoveCommand(Application& app, Editor& editor): Command(app, editor){}

    bool execute() override {
        saveBackup();
        editor.removeLastChars(1);
        return true;
    }
};

class CopyCommand: public Command {
public:
    CopyCommand(Application& app, Editor& editor): Command(app, editor){}
    bool execute() override {
        app.setClipboard(editor.getText());
        return false;
    }
};



#endif //COMMAND_TYPES_H
