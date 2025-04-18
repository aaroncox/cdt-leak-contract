#pragma once

#include <eosio.system/eosio.system.hpp>
#include <eosio.token/eosio.token.hpp>

using namespace eosio;
using namespace std;

namespace buggy {

struct buggy_struct {
  eosiosystem::eosio_global_state global;
  eosiosystem::powerup_state powerup;
  eosiosystem::exchange_state ram;
  eosiosystem::rex_pool rex;
};

class [[eosio::contract("buggy")]] buggy : public contract {
public:
  using contract::contract;

  [[eosio::action, eosio::read_only]] buggy_struct foo();
  using foo_action = eosio::action_wrapper<"foo"_n, &buggy::foo>;

private:
  eosiosystem::eosio_global_state get_global();
  eosiosystem::powerup_state get_powerup();
  eosiosystem::exchange_state get_rammarket();
  eosiosystem::rex_pool get_rex_pool();
};

} // namespace buggy
