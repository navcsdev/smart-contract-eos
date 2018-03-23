#include <eosiolib/eos.hpp>
#include <eosiolib/db.hpp>
#include <string>

#ifndef USER_INFO
#define USER_INFO user_info
#endif

using namespace eosio;
namespace user_info {
  struct PACKED(user_info) {
    user_info() {};
    user_info(string address):address(address) {};
  }

  string address;

  struct move {
    uint32_t    row;
    uint32_t    column;
  };

  using UserInfos = eosio::table<N(user.info),N(user.info),N(user_infos),user_info,uint64_t>;
}