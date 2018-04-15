/*
 Name:		Sketch1.ino
 Created:	4/14/2018 7:38:15 AM
 Author:	Martin
*/
#define MAX_BUFFER_SIZE				40
const char f_buffer[ MAX_BUFFER_SIZE ] = "2018-04-14-07-40-35-6-52-19-25-\n";
char buffer[ MAX_BUFFER_SIZE ] = "2018-04-14-07-40-35-6-52-19-25-\n";
const char s_buffer[ MAX_BUFFER_SIZE ] = "2018-04-14-04-00-35-6-52-19-25-\n";
bool bIsChanged = false;
byte readByte;

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin( 9600 );
	while( !Serial )
	{
		//wait until Serial is initialized...
	}
	Serial.print( buffer );
}

// the loop function runs over and over again until power down or reset
void loop()
{
	if( Serial.available() )
	{
		readByte = Serial.read();
		if( readByte == 0x21 )
		{
			Serial.print( buffer );
			if( !bIsChanged )
			{
				memcpy( buffer, s_buffer, strlen( s_buffer ) );
				bIsChanged = true;
			}
			else
			{
				memcpy( buffer, f_buffer, strlen( f_buffer ) );
				bIsChanged = false;
			}
		}
	}	
}
