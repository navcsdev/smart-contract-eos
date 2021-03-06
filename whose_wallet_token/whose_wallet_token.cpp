/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <whose_wallet_token.hpp>

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
       eosio::print( "Hello World: ", eosio::name(code), "->", eosio::name(action), "\n" );
       whose_wallet_token::currency().apply(code, action);
    }

} // extern "C"
