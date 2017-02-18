#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

class MNS : public NameServerInterface{

public:
	MNS();
	~MNS();
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;

private:
	std::map<HostName, IPAddress> lookup_map;
};

#endif