#include "umns.h"
#include <algorithm>

using std::string;
using std::unordered_map;

void UMNS::insert(const HostName& h, const IPAddress& ip){
  store[h] = ip;
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool UMNS::remove(const HostName& h){
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
IPAddress UMNS::lookup(const HostName& h) const{
 auto it = store.find(h);
 if (it == store.end()) {
   return NON_EXISTING_ADDRESS;
 }
 else{
 return it->second;
 }
}

