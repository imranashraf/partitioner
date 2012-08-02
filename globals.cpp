#include<iostream>
#include <sstream>
#include "globabls.hpp"

// #define KB	(1024)
// #define MB	(1024 * 1024)
// #define GB	(1024 * 1024 * 1024)

#define KB	(1000)
#define MB	(1000 * 1000)
#define GB	(1000 * 1000 * 1000)

using namespace std;

string humanReadable(unsigned long long no)
{
	stringstream ss (stringstream::in | stringstream::out);
	
	if( no >= GB )
		ss<<(float)no/GB<<" GB";
	else if( no >= MB )
		ss<<(float)no/MB<<" MB";
	else if( no >= KB)
		ss<<(float)no/KB<<" KB";
	else
		ss<<no<<" B";

	return ss.str();
}