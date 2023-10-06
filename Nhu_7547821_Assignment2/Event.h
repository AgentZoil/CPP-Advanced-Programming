#ifndef EVENT_H
#define EVENT_H
#include <vector>
#include <string>

class Event
{
    public:
    	std::string eName, description;
        int effect;
        Event(std::string eName, std::string description, int effect);
        Event();
        void setName(std::string eName);
        std::string getName();
        void setDescription(std::string description);
        std::string getDescription();
        void setEffect(int effect);
        int getEffect();
};

#endif
