#include "StateWave.h"

#include <fstream>
#include "SpawnFile.h"

StateWave::StateWave( const std::string &levelFilename, const std::string &replayFilename ) :
	StateLevel( replayFilename ),
	__spawnHandler( this )
{
	spawnHandler = &__spawnHandler;
	if ( levelFilename[0] != 0 )
	{
		std::fstream file( levelFilename.c_str(), std::fstream::in );
		std::string line;
		if ( file.good() )
		{
			getline( file, line );
			__spawnHandler.load( file );
		}
		else
		{
			errorString = "Could not open wave data " + levelFilename;
		}
		file.close();
	}
	else
	{
		errorString = "Wave data missing!";
	}
	type = stWave;
}

StateWave::~StateWave()
{

}

int StateWave::update( Uint32 delta )
{
	return StateLevel::update( delta );
}

void StateWave::render( SDL_Surface *target )
{
	StateLevel::render( target );
}