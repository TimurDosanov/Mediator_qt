#ifndef MODULE_H
#define MODULE_H

#include <QObject>
#include <QList>

class Event;

//Base class of modules for inheritance
class Module : public QObject
{ Q_OBJECT
signals:
    void SendEvent(Event* event);
public slots:
   virtual void EventHandler(Event* event) = 0; // in derived class check for Event_type and dynamic_cast to evets
};

#endif // MODULE_H
