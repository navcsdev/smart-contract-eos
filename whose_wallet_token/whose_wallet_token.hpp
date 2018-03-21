/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/multi_index.hpp>

using namespace eosio;

namespace whose_wallet_token {
    using std::string;
    using std::array;

    class currency {
        public:
            currency( account_name contract = current_receiver() ):_contract(contract) {}

            struct create {
                account_name issuer;
                asset maximum_supply;
                uint8_t issuer_can_freeze     = true;
                uint8_t issuer_can_recall     = true;
                uint8_t issuer_can_whitelist  = true;

                EOSLIB_SERIALIZE( create, (issuer)(maximum_supply)(issuer_can_freeze)(issuer_can_recall)(issuer_can_whitelist) )
            };

            struct account {
                asset balance;
                bool frozen = false;
                bool whitelist = true;
                uint64_t primary_key()const { return balance.symbol; }

                EOSLIB_SERIALIZE( account, (balance)(frozen)(whitelist) )
            };

            struct currency_stats {
                asset          supply;
                asset          max_supply;
                account_name   issuer;
                bool           can_freeze         = true;
                bool           can_recall         = true;
                bool           can_whitelist      = true;
                bool           is_frozen          = false;
                bool           enforce_whitelist  = false;

                uint64_t primary_key()const { return supply.symbol.name(); }

                EOSLIB_SERIALIZE( currency_stats, (supply)(max_supply)(issuer)(can_freeze)(can_recall)(can_whitelist)(is_frozen)(enforce_whitelist) )
            };

            typedef eosio::multi_index<N(accounts), account> accounts;
            typedef eosio::multi_index<N(stat), currency_stats> stats;

            bool apply( account_name contract, action_name act ) {
                if( contract != _contract )
                return false;

                switch( act ) {
                case N(issue):
                    print( "issue\n");
                    //  on( unpack_action_data<issue>() );
                    return true;
                case N(transfer):
                    print( "transfer\n");
                    //  on( unpack_action_data<transfer>() );
                    return true;
                case N(create):
                    print( "create\n");
                    on( unpack_action_data<create>() );
                    return true;
                }
                return false;
            }

            void on(const create& c) {
                print( "process create\n");
            }

        private:
            account_name _contract;
    };
}


