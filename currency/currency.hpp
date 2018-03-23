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
            asset symbol;

            EOSLIB_SERIALIZE( balance, (owner)(symbol) )
        };

        bool apply( account_name contract, action_name act) {
            print("apply\n");
            bool isEnd = currency::apply(contract, act);
            // bool isEnd = false;
            if (isEnd) return isEnd;
            switch( act ) {
                case N(balance):
                    print( "balance\n");
                    on( unpack_action_data<balance>(), contract );
                    return true;
            }

            return false;
        }

        void on( const balance& b, const account_name contract) {
            print("on balance\n");
            auto sym = b.symbol.symbol;
            // get_balance(b.owner, sym);
            accounts to_acnts( contract, b.owner );
            auto to = to_acnts.get( sym );
            print(to->balance);
            // return true;
        }
};
