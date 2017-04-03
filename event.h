#ifndef EVENT_H
#define EVENT_H

#include <cstdint>

using t_event_type = uint32_t;


//Base class of event for inheritance
class Event
{
public:
    Event(t_event_type type = 0)
        : m_type(type)
    {}

    t_event_type GetType() const            {return m_type;}
    void         SetType(t_event_type type) {m_type = type;}
private:
    t_event_type m_type;
};

#endif // EVENT_H
