#include "buggy/buggy.hpp"

namespace buggy {

eosiosystem::eosio_global_state buggy::get_global()
{
   eosiosystem::global_state_singleton global_table("eosio"_n, "eosio"_n.value);
   auto                                global = global_table.get_or_default();
   return global;
}

eosiosystem::powerup_state buggy::get_powerup()
{
   eosiosystem::powerup_state_singleton powerup_table("eosio"_n, 0);
   auto                                 powerup = powerup_table.get_or_default();
   return powerup;
}

eosiosystem::exchange_state buggy::get_rammarket()
{
   eosiosystem::exchange_state ram;
   eosiosystem::rammarket      rammarket_table("eosio"_n, "eosio"_n.value);
   auto                        rammarket_itr = rammarket_table.find(symbol("RAMCORE", 4).raw());
   if (rammarket_itr != rammarket_table.end()) {
      ram = *rammarket_itr;
   }
   return ram;
}

eosiosystem::rex_pool buggy::get_rex_pool()
{
   eosiosystem::rex_pool       rex;
   eosiosystem::rex_pool_table rex_table("eosio"_n, "eosio"_n.value);
   auto                        rex_itr = rex_table.begin();
   if (rex_itr != rex_table.end()) {
      rex = *rex_itr;
   }
   return rex;
}

[[eosio::action, eosio::read_only]] buggy_struct buggy::foo()
{
   return buggy_struct{
      .global  = get_global(),
      .powerup = get_powerup(),
   };
}

} // namespace buggy