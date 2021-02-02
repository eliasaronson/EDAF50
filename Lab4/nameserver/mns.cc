#include "mns.h"
#include <algorithm>

using std::string;
using std::vector;

void MNS::insert(const HostName& h, const IPAddress& ip){
  pair<string, unsigned int> temp(h, ip);
  store.insert(temp);
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool MNS::remove(const HostName& h){
  auto it = store.find(h);
  if (it == store.end()) {
   return false;
 }
 else{
  store.erase(it);
  return true;
 }
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress MNS::lookup(const HostName& h) const{
 auto it = store.find(h); 
 if (it == store.end()) {
   return NON_EXISTING_ADDRESS;
 }
 else{
 return it->second;
 }
}

