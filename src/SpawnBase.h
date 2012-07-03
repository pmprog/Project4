#ifndef _SPAWN_BASE_H
#define _SPAWN_BASE_H

#include "SDL/SDL.h"
#include "Timer.h"
#include <vector>

class StateLevel;

class SpawnBase
{
public:
	SpawnBase( StateLevel *newUnit );
	virtual ~SpawnBase();

	virtual int update( Uint32 delta )=0;
	virtual void render( SDL_Surface *target )=0;
protected:
	StateLevel *parent;
	std::vector< Timer* > timers;
private:

};


#endif // _SPAWN_BASE_H
