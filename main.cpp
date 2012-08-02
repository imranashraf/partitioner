//============================================================================
// Name        : Partitioner.cpp
// Author      : Imran Ashraf
// Version     :
// Copyright   : Your copyright notice
/*
 *
 	 Description : Q2 Partitioner
 *
 */
//============================================================================

#include <algorithm>
#include <memory>
#include <iostream>

#include "Xml.hpp"
#include "Graph.hpp"
#include "globabls.hpp"

using namespace std;

typedef std::vector<std::string>partList_t;
void validateArgs(int argc, char * argv[], string * xmlFileName,partList_t * partList);

int main(int argc, char * argv[])
{
	unsigned long long comm;
	string xmlFileName;
	partList_t partList;

	cout<<"=============="<<endl;
	cout<<" Partitioner "<<endl;
	cout<<"=============="<<endl;

	validateArgs(argc,argv,&xmlFileName,&partList);
	makeGraph(xmlFileName);
	printGraph();

	comm = calculateCommunication(partList);
	cout<<"Communication of the functions inside partition with the rest of graph = "<<humanReadable(comm)<<endl;

	return 0;
}

void validateArgs(int argc, char * argv[],string * xmlFileName,partList_t * partList)
{
	string fname;
	if(argc!=3)
	{
		cout<<"Please specify the correct arguments !"<<endl
			<<"Usage: "<<endl
			<<"argument 1 should be XML File name"<<endl
			<<"argument 2 should be File name to read Function Names for partition"<<endl;
	}
	else
	{
		*xmlFileName = argv[1];
		ifstream infile(argv[2]);
		if (infile.is_open())
		{
			while ( infile.good())
		    {
		       	infile>>fname;
		       	if (infile.eof())
		       		break;	// we have read all the functions
		       	else
		       		partList->push_back(fname);
		    }
		    infile.close();
		}
		else
		{
			cout << "Unable to open file"<<endl;
			exit(0);
		}
	}

	if(DEBUG)
	{
		cout<<endl<<"Partition list is:"<<endl;
		for(unsigned int i=0; i<partList->size();i++)
			cout<<"\t\t"<<partList->at(i)<<endl;
	}

}
