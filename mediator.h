#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QList>

class Module;
class Event;

class Mediator : public QObject
{
    Q_OBJECT
public:
    explicit Mediator(QObject *parent = 0);

    void AddModule(Module* module);
    void DeleteModule(Module* module);
signals:
    void BroadcastEvent(Event* event);
public slots:
    void ReciveEvent(Event* event);
private:
    QList<Module*> m_module_list;
};



#endif // MEDIATOR_H
