/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include "currency.hpp"

extern "C" {
    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
        // eosio::currency().apply( code, action );
        // currency().apply(code, action);
        //token().apply(code, action);
        token().apply(code, action);
    }
}
