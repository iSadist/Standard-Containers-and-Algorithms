#include "vns.h"

#include <string>
#include <algorithm>
#include <iostream>

VNS::VNS(){}

VNS::~VNS(){}

void VNS::insert(const HostName& host, const IPAddress& ip){
	lookup_vector.push_back(make_pair(host, ip));
}

bool VNS::remove(const HostName& host){
	auto it = std::find_if(lookup_vector.begin(), lookup_vector.end(),
				[&](std::pair<HostName, IPAddress>& curr_pair) { return curr_pair.first == host; });
	if (it != lookup_vector.end()){
		lookup_vector.erase(it);
		return true;
	}
	return false;
}

IPAddress VNS::lookup(const HostName& host) const{
	auto lamb = [&](std::pair<HostName, IPAddress> curr_pair) { return curr_pair.first == host; };
	auto it = std::find_if(lookup_vector.begin(), lookup_vector.end(), lamb);
	if (it != lookup_vector.end()){
		return it->second;
	}
	return NON_EXISTING_ADDRESS;
}
