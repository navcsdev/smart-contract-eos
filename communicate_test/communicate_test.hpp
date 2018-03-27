/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eosio.hpp>

using namespace eosio;

class communicate_test {
    public:
        struct call {
            account_name caller;

            EOSLIB_SERIALIZE(call, (caller));
        };

        bool apply( account_name contract, action_name act) {
            switch (act) {
                case N(call):
                    on( unpack_action_data<call>() );
                    return true;
            }

            return false;
        }

        void on( const call& c) {
            print(c.caller);
            print("\n");
        }
};

