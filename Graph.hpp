/*
 * Graph.hpp
 *
 *  Created on: Jan 6, 2012
 *      Author: iashraf
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include<map>
#include <stdlib.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

	typedef boost::adjacency_list
	<
		//Store all edges as a std::vector
		boost::vecS,
		//Store all vertices in a std::vector
		boost::vecS,
		//Relations are both ways (in this example)
		boost::directedS,
		//All vertices are function names of type std::string
		boost::property<boost::vertex_name_t,std::string>,
		//All edges are weights equal to the communication in bytes
		boost::property<boost::edge_weight_t,unsigned long long>,
		//Graph itself has a std::string name
		boost::property<boost::graph_name_t,std::string>
	> Graph;

	typedef std::map<std::string, Graph::vertex_descriptor>vName2DescMAP;

	void insertComm(std::string prod, std::string cons, unsigned long int bytes);
	unsigned long long calculateCommunication(std::vector<std::string>partList);
	void printGraph();


#endif /* GRAPH_HPP_ */
