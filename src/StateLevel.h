#ifndef _LEVEL_STATE_H
#define _LEVEL_STATE_H

#include <vector>

#include "StateBase.h"
#include "UnitBase.h"
#include "Timer.h"
#include "ShapeRect.h"
#include "ShapeCircle.h"
#include "Events.h"
#include "ScoreNormal.h"

#define PLAYER_CLASS UnitPlayer

class PLAYER_CLASS;

class StateLevel : public StateBase
{
public:
	StateLevel();
	virtual ~StateLevel();

	int update( Uint32 delta );
	void render( SDL_Surface *target );

	void addUnit( UnitBase *newUnit );
	// This function takes ownership of the event passed!
	void addEvent( EventBase *newEvent );

	PLAYER_CLASS *player;
	ScoreNormal scoreKeeper;

#ifdef _DEBUG
	std::string debugString;
#endif
protected:
	void spawnUnits( Uint32 delta );
	void handleEvents( Uint32 delta );

	std::vector<UnitBase *> units;
	std::vector<UnitBase *> unitQueue;
	std::vector<EventBase *> eventQueue;
	Timer spawnTimer;
	ShapeRect corner[4];
	ShapeRect side[4];
	ShapeCircle center;

#ifdef _DEBUG
	spFontPointer debugText;
#endif

private:
};


#endif // _LEVEL_STATE_H

