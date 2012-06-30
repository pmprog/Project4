#ifndef _SCORE_NORMAL_H
#define _SCORE_NORMAL_H

#include "ScoreBase.h"
#include <map>
#include "sparrowFont.h"

class ScoreNormal : public ScoreBase
{
public:
	ScoreNormal( StateLevel *newParent );
	virtual ~ScoreNormal();

	int getScore() const;

	int update( Uint32 delta );
	void handleEvent( EventBase const * const event );

	void render( SDL_Surface *target );
protected:
	int points;
	int kills;
	int streak;
	float multiplier;
	Timer comboTimer;
	Timer peaceTimer;
	std::map< int, int > pointMatrix;

	spFontPointer scoreText;
private:

};


#endif // _SCORE_NORMAL_H

