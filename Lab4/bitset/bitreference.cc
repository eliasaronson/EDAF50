#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {
    //
    // *** IMPLEMENT ***
    // This corresponds to the set() function in SimpleBitset.
    //
    // p_points set a pointer to itself with OR with a new long that is shifted
    // to pos.

    if (b) {
        *p_bits |= 1L << pos;
    } else {
        *p_bits &= ~ (1L << pos);
    }
    return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
    //
    // *** IMPLEMENT ***
    // Same as operator=(bool), but the bit is picked from rhs
    //
    if (rhs) {
        *p_bits |= 1L << pos;
    } else {
        *p_bits &= ~ (1L << pos);
    }
    return *this;
}

BitReference::operator bool() const {
    //
    // *** IMPLEMENT ***
    // This corresponds to the get() function in SimpleBitset.
    //Skapar en ny long med första biten 1 och flyttar den pos steg. Använder &
    //för att kopera alla bits som är lika mellan den och och kollar om detta
    //är lika med noll för då var den possitionen lika med 0 från början.
    
	  return (*p_bits & (1L << pos)) != 0;
}
