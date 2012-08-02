/*
 * Graph.cpp
 *
 *  Created on: Jan 6, 2012
 *      Author: iashraf
 */

#include<iostream>
#include<map>
#include<algorithm>

#include"Graph.hpp"
#include"globabls.hpp"

using namespace std;

Graph  myGraph;
vName2DescMAP vName2Desc;
typedef typename boost::graph_traits<Graph>::edge_descriptor Edge;
typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef typename boost::property_map<Graph, boost::vertex_name_t>::type VertexName;
typedef typename boost::property_map<Graph, boost::vertex_index_t>::type VertexIndex;
typedef typename boost::property_map<Graph, boost::edge_weight_t>::type EdgeWeight;
typedef typename boost::graph_traits<Graph>::vertex_iterator VertexIterator;
typedef typename boost::graph_traits<Graph>::edge_iterator EdgeIterator;

void insertComm(string prod, string cons, unsigned long int bytes)
{
	Graph::vertex_descriptor vp,vc;
	vName2DescMAP::iterator iter;

	iter = vName2Desc.find(prod);
	if(iter == vName2Desc.end() ) //not already seen
	{
		vp = add_vertex(prod,myGraph);
		vName2Desc[prod] = vp;
	}
	else
		vp = iter->second;

	iter = vName2Desc.find(cons);
	if(iter == vName2Desc.end() ) //not already seen
	{
		vc = add_vertex(cons,myGraph);
		vName2Desc[cons] = vc;
	}
	else
		vc = iter->second;

	boost::add_edge(vp,vc,bytes,myGraph);

}
bool isInPartition(Vertex v, std::vector<std::string>partList)
{
	VertexName name = get(boost::vertex_name, myGraph);
	for(unsigned int i=0; i<partList.size();i++)
	{
		if(name[v] == partList[i])
			return true;
	}
	return false;
}

unsigned long long calculateCommunication(std::vector<std::string>partList)
{
	unsigned long long comm = 0;

    Vertex src,targ;
    Edge edge;
	VertexIterator vi, vi_end;
	EdgeIterator ei, ei_end;
	//VertexIndex id = get(boost::vertex_index, myGraph);
	EdgeWeight weight = get(boost::edge_weight, myGraph);

	for(tie(ei,ei_end) =edges(myGraph); ei != ei_end; ++ei )
	{
		edge = *ei; //get the edge from this iterator ei
		src = boost::source(edge,myGraph);
		targ = boost::target(edge, myGraph);

		if	(
				(isInPartition(src,partList) == true && isInPartition(targ,partList) == false) ||
				(isInPartition(src,partList) == false && isInPartition(targ,partList) == true)
			)
		{
			comm += weight[edge];

			if(DEBUG)	cout<<"current : "<<setw(12)<<weight[edge]<<" Total : "<<setw(12)<<comm<<endl;
		}

	}

	return comm;
}

void printGraph()
{
	std::ofstream dotf("graph.dot");
	boost::dynamic_properties dp;
	dp.property("Bytes", get(boost::edge_weight, myGraph)); 
// 	dp.property("Bytes", get(EdgeWeight, myGraph)); 
	dp.property("node_id", get(boost::vertex_name, myGraph));
	boost::write_graphviz_dp(dotf,myGraph,dp);

	// Convert graph.dot file to test.pdf
	system("dot -Tpdf graph.dot -o graph.pdf");
}


//void printGraph()
//{
//	std::ofstream dotf("doc/graph.dot");
//	write_graphviz(std::cout, myGraph);
//	write_graphviz(dotf, myGraph);
//
//	// Convert test.dot file to test.pdf
//	system("dot -Tpdf doc/graph.dot -o doc/graph.pdf");
//
//	// open pdf graph in acrobat reader
//	//system("acroread doc/graph.pdf");
//}
//
