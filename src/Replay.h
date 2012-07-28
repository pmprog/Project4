#ifndef _REPLAY_FILE_H
#define _REPLAY_FILE_H

#include <string>
#include <list>
#include "sparrowCore.h"

#define REPLAY_ENTRY_SIZE 3
#define REPLAY_VERSION 2

class Replay
{
public:
	struct ReplayEntry
	{
		Uint32 delta;
		SspInput frameInput;
		std::list< int > numbers;
	};
	struct ReplayInfo
	{
		std::string name;
		int score;
		int timecode;
		int version;
	};

public:
	Replay( );
	virtual ~Replay();

	void addEntry( Uint32 delta );
	int playEntry();
	int getFrameCount();

	bool loadFromFile( const std::string &filename );
	void saveToFile( const std::string &filename );

	ReplayInfo info;

	bool playing;

protected:
	void getReplayButtons( SspInput &buttons );
	void setReplayButtons( const SspInput &buttons );
	std::string buttonsToString( const SspInput &buttons );
	void stringToButtons( const std::string &str, SspInput &buttons );

	std::list< ReplayEntry > entries;
	int frameCount;

private:

};


#endif // _REPLAY_FILE_H


