/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once
#include <eosiolib/eosio.hpp>
#include <eosiolib/currency.hpp>

using namespace eosio;

class token : public eosio::currency {
    public:
        struct balance {
            account_name owner;
            uint64_t symbol;

            EOSLIB_SERIALIZE( balance, (owner)(symbol) )
        };

        struct call {
            account_name caller;

            EOSLIB_SERIALIZE(call, (caller));
        };

        bool apply( account_name contract, action_name act) {
            print("apply\n");
            bool isEnd = currency::apply(contract, act);
            if (isEnd) return isEnd;
            switch( act ) {
                case N(balance):
                    print( "balance\n");
                    on( unpack_action_data<balance>(), contract );
                    return true;
            }

            return false;
        }

        void on( const balance& b, const uint64_t contract) {
            print("on balance\n");
            stats statstable(contract, b.symbol);
            print(b.symbol);
            print("\n");
            const auto& st = statstable.get( b.symbol );
            print(st.supply.symbol.value);

            action act( permission_level( N(currency), N(active) ), N(communicate), N(call), call{N(eosio)} );
            act.send();
        }
};
