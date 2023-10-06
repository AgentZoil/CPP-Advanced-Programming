#include "Event.h"

// Default constructor
Event::Event(){}

// Constructor
Event::Event(std::string eName, std::string description, int effect) :
    eName(eName), description(description), effect(effect) {}

// Set the name of the event
void Event::setName(std::string eName)
{
    this->eName = eName;
}

// Get the name of the event
std::string Event::getName()
{
    return eName;
}

// Set the description of the event
void Event::setDescription(std::string description)
{
    this->description = description;
}

// Get the description of the event
std::string Event::getDescription()
{
    return description;
}

// Set the effect of the event
void Event::setEffect(int effect)
{
    this->effect = effect;
}

// Get the effect of the event
int Event::getEffect()
{
    return effect;
}
