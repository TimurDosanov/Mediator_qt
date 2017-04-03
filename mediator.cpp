#include "mediator.h"
#include "module.h"

using iterator = QList<Module*>::Iterator;

void Mediator::AddModule(Module *module)
{
    connect(module, SIGNAL(SendEvent(Event*)), this, SLOT(ReciveEvent(Event*)));
    connect(this, SIGNAL(BroadcastEvent(Event*)), module, SLOT(EventHandler(Event*)));

    m_module_list.append(module);
}

void Mediator::DeleteModule(Module *module)
{
    Module* temp;
    for (iterator it = m_module_list.begin(); it != m_module_list.end(); ++it) {
        temp = *it;
        if (temp == module) {
            m_module_list.removeOne(temp);
            delete temp;
        }
    }
}

void Mediator::ReciveEvent(Event *event)
{
    emit BroadcastEvent(event);
}
