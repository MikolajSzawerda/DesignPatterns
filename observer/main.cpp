#include <iostream>
#include "Types.h"

int main() {
    Editor editor;
    LoggingListener loggingListener("log.txt");
    EmailAlertsListener emailAlertsListener;
    editor.events.subscribe("open", &loggingListener);
    editor.events.subscribe("save", &emailAlertsListener);
    editor.openFile("hello_world.txt");
    editor.saveFile("hello_world.txt");
    editor.events.unsubscribe("save", &emailAlertsListener);
    editor.openFile("d2.txt");
    editor.openFile("d3.txt");
    editor.openFile("d4.txt");
    editor.openFile("d5.txt");

    return 0;
}
