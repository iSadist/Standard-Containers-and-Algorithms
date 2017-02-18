#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>

class VNS : public NameServerInterface{

public:
	VNS();
	~VNS();
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;

private:
	std::vector<std::pair<HostName, IPAddress>> lookup_vector;
};

#endif