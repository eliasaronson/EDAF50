#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <string>
#include <vector>

using std::pair;
using std::vector;

class VNS: public NameServerInterface {
public: 

  void insert(const HostName&, const IPAddress&) override;
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName&) override;
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
  IPAddress lookup(const HostName&) const override;
  
private:
  vector<pair<HostName, IPAddress>> store;
};

#endif  // VNS_H
