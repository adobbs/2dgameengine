#ifndef KEYPRESSEDEVENT_H
#define KEYPRESSEDEVENT_H

#include "../EventBus/Event.h"
#include <SDL2/SDL.h>

class KeyPressedEvent: public Event {
    public:
        SDL_Keycode symbol;
        
        KeyPressedEvent(SDL_Keycode symbol): symbol(symbol) {}
};

#endif
