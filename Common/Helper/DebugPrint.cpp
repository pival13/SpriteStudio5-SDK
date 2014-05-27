#include "DebugPrint.h"
#include "stdio.h"
#include <string>


#if _WIN32
	#include <Windows.h>
#endif



void DEBUG_PRINTF( const char* strFormat, ...   )
{
#if _WIN32
	char strBuffer[1024];

	va_list arglist;
	va_start( arglist, strFormat);
	_vsnprintf( strBuffer, 1024, strFormat, arglist);
	va_end( arglist);

	OutputDebugStringA( strBuffer );
#endif // MASTER_RELEASE
}

void	THROW_ERROR_MESSAGE_MAIN( std::string str , char* fname , size_t line )
{
	char	___str__buffer[1024];
	sprintf( ___str__buffer , "%s(%d) : %s \n" , fname , line , str.c_str() );
	std::string ___err_message = ___str__buffer;

	DEBUG_PRINTF( ___str__buffer );
	throw ThrowErrorMessage( 0 , ___err_message );
}
