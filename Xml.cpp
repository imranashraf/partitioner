/*
 * Xml.cpp
 *
 *  Created on: Jan 6, 2012
 *      Author: iashraf
 */

#include <iostream>
#include "q2profiling.hxx"
#include "Xml.hpp"
#include "Graph.hpp"
#include "globabls.hpp"

using namespace q2profiling;
using namespace std;

void do_channel(ChannelType &ch)
{
//	cout<<"Channel "<<" < Producer : "<<ch.producer()
//		<<"   Consumer : "<<ch.consumer()
//		<<"   bytes : "<<ch.hBytes()<<" > "<<endl;

	stringstream ss;
	string str;
	ss<<ch.hBytes();
	ss>>str;
	insertComm( (string)ch.producer(), (string)ch.consumer(), atoi(str.c_str()));
}

void do_call(CallType & call)
{
	if(DEBUG)	cout<<"call < caller : "<<call.caller()<<"   callee : "<<call.callee() <<" > "<<endl;
}

void do_target(TargetType tr)
{
	if(DEBUG)	cout<<"target "<<endl;
}

void do_function(FunctionType fn)
{
	if(DEBUG)	cout<<"function name : "<< fn.name() <<endl;

	statistics stats( fn.statistics() );
	for_each(stats.target().begin() , stats.target().end() , do_target);
}

void do_application(ApplicationType &app)
{

	if(DEBUG)	cout<<"Application Name : "<<app.name() <<endl;

	QDUGraph qdu( app.QDUGraph() );
	for_each(qdu.channel().begin() , qdu.channel().end() , do_channel);

//	CallGraph cg( app.CallGraph() );
//	for_each(cg.call().begin() , cg.call().end() , do_call);
//
//	functions ftns( app.functions() );
//	for_each(ftns.function().begin() , ftns.function().end() , do_function);
}

int makeGraph(string xmlFName)
{
	try
	{
		auto_ptr<ProfilesType> doc(profiles(xmlFName));
		for_each(doc->application().begin() , doc->application().end() , do_application);
	}
	catch (const xml_schema::exception& e)
	{
		cerr << e << endl;
		return 1;
	}
	return 0;
}


