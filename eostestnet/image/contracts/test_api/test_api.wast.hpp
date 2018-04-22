const char* const test_api_wast = R"=====(
(module
 (type $FUNCSIG$v (func))
 (type $FUNCSIG$vjj (func (param i64 i64)))
 (type $FUNCSIG$i (func (result i32)))
 (type $FUNCSIG$vii (func (param i32 i32)))
 (type $FUNCSIG$iii (func (param i32 i32) (result i32)))
 (type $FUNCSIG$iiiii (func (param i32 i32 i32 i32) (result i32)))
 (type $FUNCSIG$iiii (func (param i32 i32 i32) (result i32)))
 (type $FUNCSIG$viii (func (param i32 i32 i32)))
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$ij (func (param i64) (result i32)))
 (type $FUNCSIG$ijjjjii (func (param i64 i64 i64 i64 i32 i32) (result i32)))
 (type $FUNCSIG$ijjjji (func (param i64 i64 i64 i64 i32) (result i32)))
 (type $FUNCSIG$vj (func (param i64)))
 (type $FUNCSIG$j (func (result i64)))
 (type $FUNCSIG$jj (func (param i64) (result i64)))
 (type $FUNCSIG$jjj (func (param i64 i64) (result i64)))
 (type $FUNCSIG$ijj (func (param i64 i64) (result i32)))
 (type $FUNCSIG$vijjjj (func (param i32 i64 i64 i64 i64)))
 (type $FUNCSIG$vijji (func (param i32 i64 i64 i32)))
 (type $FUNCSIG$viiiii (func (param i32 i32 i32 i32 i32)))
 (type $FUNCSIG$iiiiii (func (param i32 i32 i32 i32 i32) (result i32)))
 (type $FUNCSIG$vijii (func (param i32 i64 i32 i32)))
 (type $FUNCSIG$ijjii (func (param i64 i64 i32 i32) (result i32)))
 (type $FUNCSIG$ijjjj (func (param i64 i64 i64 i64) (result i32)))
 (import "env" "__ashlti3" (func $__ashlti3 (param i32 i64 i64 i32)))
 (import "env" "__ashrti3" (func $__ashrti3 (param i32 i64 i64 i32)))
 (import "env" "__divti3" (func $__divti3 (param i32 i64 i64 i64 i64)))
 (import "env" "__lshlti3" (func $__lshlti3 (param i32 i64 i64 i32)))
 (import "env" "__lshrti3" (func $__lshrti3 (param i32 i64 i64 i32)))
 (import "env" "__modti3" (func $__modti3 (param i32 i64 i64 i64 i64)))
 (import "env" "__multi3" (func $__multi3 (param i32 i64 i64 i64 i64)))
 (import "env" "__udivti3" (func $__udivti3 (param i32 i64 i64 i64 i64)))
 (import "env" "__umodti3" (func $__umodti3 (param i32 i64 i64 i64 i64)))
 (import "env" "abort" (func $abort))
 (import "env" "action_data_size" (func $action_data_size (result i32)))
 (import "env" "assert_recover_key" (func $assert_recover_key (param i32 i32 i32 i32 i32)))
 (import "env" "assert_ripemd160" (func $assert_ripemd160 (param i32 i32 i32)))
 (import "env" "assert_sha1" (func $assert_sha1 (param i32 i32 i32)))
 (import "env" "assert_sha256" (func $assert_sha256 (param i32 i32 i32)))
 (import "env" "assert_sha512" (func $assert_sha512 (param i32 i32 i32)))
 (import "env" "cancel_deferred" (func $cancel_deferred (param i32)))
 (import "env" "check_authorization" (func $check_authorization (param i64 i64 i32 i32) (result i32)))
 (import "env" "current_sender" (func $current_sender (result i64)))
 (import "env" "db_idx64_store" (func $db_idx64_store (param i64 i64 i64 i64 i32) (result i32)))
 (import "env" "db_lowerbound_i64" (func $db_lowerbound_i64 (param i64 i64 i64 i64) (result i32)))
 (import "env" "db_store_i64" (func $db_store_i64 (param i64 i64 i64 i64 i32 i32) (result i32)))
 (import "env" "db_update_i64" (func $db_update_i64 (param i32 i64 i32 i32)))
 (import "env" "diveq_i128" (func $diveq_i128 (param i32 i32)))
 (import "env" "double_add" (func $double_add (param i64 i64) (result i64)))
 (import "env" "double_div" (func $double_div (param i64 i64) (result i64)))
 (import "env" "double_eq" (func $double_eq (param i64 i64) (result i32)))
 (import "env" "double_gt" (func $double_gt (param i64 i64) (result i32)))
 (import "env" "double_lt" (func $double_lt (param i64 i64) (result i32)))
 (import "env" "double_mult" (func $double_mult (param i64 i64) (result i64)))
 (import "env" "double_to_i64" (func $double_to_i64 (param i64) (result i64)))
 (import "env" "eosio_assert" (func $eosio_assert (param i32 i32)))
 (import "env" "get_action" (func $get_action (param i32 i32 i32 i32) (result i32)))
 (import "env" "get_active_producers" (func $get_active_producers (param i32 i32) (result i32)))
 (import "env" "get_context_free_data" (func $get_context_free_data (param i32 i32 i32) (result i32)))
 (import "env" "i64_to_double" (func $i64_to_double (param i64) (result i64)))
 (import "env" "is_privileged" (func $is_privileged (param i64) (result i32)))
 (import "env" "memcpy" (func $memcpy (param i32 i32 i32) (result i32)))
 (import "env" "memset" (func $memset (param i32 i32 i32) (result i32)))
 (import "env" "multeq_i128" (func $multeq_i128 (param i32 i32)))
 (import "env" "now" (func $now (result i32)))
 (import "env" "printhex" (func $printhex (param i32 i32)))
 (import "env" "printi" (func $printi (param i64)))
 (import "env" "printi128" (func $printi128 (param i32)))
 (import "env" "printn" (func $printn (param i64)))
 (import "env" "prints" (func $prints (param i32)))
 (import "env" "prints_l" (func $prints_l (param i32 i32)))
 (import "env" "printui" (func $printui (param i64)))
 (import "env" "publication_time" (func $publication_time (result i32)))
 (import "env" "read_action_data" (func $read_action_data (param i32 i32) (result i32)))
 (import "env" "read_transaction" (func $read_transaction (param i32 i32) (result i32)))
 (import "env" "recover_key" (func $recover_key (param i32 i32 i32 i32 i32) (result i32)))
 (import "env" "require_auth" (func $require_auth (param i64)))
 (import "env" "require_auth2" (func $require_auth2 (param i64 i64)))
 (import "env" "require_recipient" (func $require_recipient (param i64)))
 (import "env" "ripemd160" (func $ripemd160 (param i32 i32 i32)))
 (import "env" "send_context_free_inline" (func $send_context_free_inline (param i32 i32)))
 (import "env" "send_deferred" (func $send_deferred (param i32 i64 i32 i32)))
 (import "env" "send_inline" (func $send_inline (param i32 i32)))
 (import "env" "sha1" (func $sha1 (param i32 i32 i32)))
 (import "env" "sha256" (func $sha256 (param i32 i32 i32)))
 (import "env" "sha512" (func $sha512 (param i32 i32 i32)))
 (import "env" "tapos_block_num" (func $tapos_block_num (result i32)))
 (import "env" "tapos_block_prefix" (func $tapos_block_prefix (result i32)))
 (import "env" "transaction_size" (func $transaction_size (result i32)))
 (table 0 anyfunc)
 (memory $0 1 16)
 (data (i32.const 4) "\c0z\00\00")
 (data (i32.const 16) "\00\00\00\00\00\00\00\00")
 (data (i32.const 32) "action_size() == sizeof(dummy_action)\00")
 (data (i32.const 80) "read_action(30)\00")
 (data (i32.const 96) "read_action(100)\00")
 (data (i32.const 128) "read_action(5)\00")
 (data (i32.const 144) "read_action(sizeof(dummy_action))\00")
 (data (i32.const 192) "dummy13->a == DUMMY_ACTION_DEFAULT_A\00")
 (data (i32.const 240) "dummy13->b == DUMMY_ACTION_DEFAULT_B\00")
 (data (i32.const 288) "dummy13->c == DUMMY_ACTION_DEFAULT_C\00")
 (data (i32.const 336) "get_action failed\00")
 (data (i32.const 368) "pack_size does not match get_action size\00")
 (data (i32.const 416) "testapi\00")
 (data (i32.const 432) "expected testapi account\00")
 (data (i32.const 464) "get_context_free_data() not allowed in non-context free action\00")
 (data (i32.const 528) "dum13.a == DUMMY_ACTION_DEFAULT_A\00")
 (data (i32.const 576) "dum13.b == DUMMY_ACTION_DEFAULT_B\00")
 (data (i32.const 624) "dum13.c == DUMMY_ACTION_DEFAULT_C\00")
 (data (i32.const 672) "dummy_action\00")
 (data (i32.const 688) "Invalid name\00")
 (data (i32.const 704) "Invalid account\00")
 (data (i32.const 720) "read\00")
 (data (i32.const 736) "get_action size failed\00")
 (data (i32.const 768) "get\00")
 (data (i32.const 784) "size determination failed\00")
 (data (i32.const 816) "get_context_free_data failed\00")
 (data (i32.const 848) "invalid value\00")
 (data (i32.const 864) "test\00")
 (data (i32.const 880) "test\n\00")
 (data (i32.const 896) "transaction_size failed\00")
 (data (i32.const 928) "privileged_api should not be allowed\00")
 (data (i32.const 976) "producer_api should not be allowed\00")
 (data (i32.const 1024) "db_api should not be allowed\00")
 (data (i32.const 1056) "action send should not be allowed\00")
 (data (i32.const 1104) "write\00")
 (data (i32.const 1120) "cf_action\00")
 (data (i32.const 1136) "acc1\00")
 (data (i32.const 1152) "acc2\00")
 (data (i32.const 1168) "Should\'ve failed\00")
 (data (i32.const 1200) "require_auth\00")
 (data (i32.const 1216) "acc3\00")
 (data (i32.const 1232) "acc4\00")
 (data (i32.const 1248) "test_action::assert_false\00")
 (data (i32.const 1280) "test_action::assert_true\00")
 (data (i32.const 1312) "pub_time == publication_time()\00")
 (data (i32.const 1344) "the current receiver does not match\00")
 (data (i32.const 1392) "the current sender does not match\00")
 (data (i32.const 1440) "total == sizeof(uint32_t)\00")
 (data (i32.const 1472) "tmp == now()\00")
 (data (i32.const 1488) "ab\00")
 (data (i32.const 1504) "c\00test_prints\00")
 (data (i32.const 1520) "efg\00")
 (data (i32.const 1536) "abcde\00")
 (data (i32.const 1552) "abBde\00")
 (data (i32.const 1568) "1q1q1qAA\00")
 (data (i32.const 1584) "AAAAAA\00")
 (data (i32.const 1600) "abcdefghijk\00")
 (data (i32.const 1616) "abcdefghijkl\00")
 (data (i32.const 1632) "abcdefghijkl1\00")
 (data (i32.const 1648) "abcdefghijkl12\00")
 (data (i32.const 1664) "abcdefghijkl123\00")
 (data (i32.const 1680) "int64_t size != 8\00")
 (data (i32.const 1712) "uint64_t size != 8\00")
 (data (i32.const 1744) "uint32_t size != 4\00")
 (data (i32.const 1776) "int32_t size != 4\00")
 (data (i32.const 1808) "uint128_t size != 16\00")
 (data (i32.const 1840) "int128_t size != 16\00")
 (data (i32.const 1872) "uint8_t size != 1\00")
 (data (i32.const 1904) "account_name size !=  8\00")
 (data (i32.const 1936) "token_name size !=  8\00")
 (data (i32.const 1968) "table_name size !=  8\00")
 (data (i32.const 2000) "time size !=  4\00")
 (data (i32.const 2016) "key256 size != 32\00")
 (data (i32.const 2048) "eosio::char_to_symbol(\'1\') !=  1\00")
 (data (i32.const 2096) "eosio::char_to_symbol(\'2\') !=  2\00")
 (data (i32.const 2144) "eosio::char_to_symbol(\'3\') !=  3\00")
 (data (i32.const 2192) "eosio::char_to_symbol(\'4\') !=  4\00")
 (data (i32.const 2240) "eosio::char_to_symbol(\'5\') !=  5\00")
 (data (i32.const 2288) "eosio::char_to_symbol(\'a\') !=  6\00")
 (data (i32.const 2336) "eosio::char_to_symbol(\'b\') !=  7\00")
 (data (i32.const 2384) "eosio::char_to_symbol(\'c\') !=  8\00")
 (data (i32.const 2432) "eosio::char_to_symbol(\'d\') !=  9\00")
 (data (i32.const 2480) "eosio::char_to_symbol(\'e\') != 10\00")
 (data (i32.const 2528) "eosio::char_to_symbol(\'f\') != 11\00")
 (data (i32.const 2576) "eosio::char_to_symbol(\'g\') != 12\00")
 (data (i32.const 2624) "eosio::char_to_symbol(\'h\') != 13\00")
 (data (i32.const 2672) "eosio::char_to_symbol(\'i\') != 14\00")
 (data (i32.const 2720) "eosio::char_to_symbol(\'j\') != 15\00")
 (data (i32.const 2768) "eosio::char_to_symbol(\'k\') != 16\00")
 (data (i32.const 2816) "eosio::char_to_symbol(\'l\') != 17\00")
 (data (i32.const 2864) "eosio::char_to_symbol(\'m\') != 18\00")
 (data (i32.const 2912) "eosio::char_to_symbol(\'n\') != 19\00")
 (data (i32.const 2960) "eosio::char_to_symbol(\'o\') != 20\00")
 (data (i32.const 3008) "eosio::char_to_symbol(\'p\') != 21\00")
 (data (i32.const 3056) "eosio::char_to_symbol(\'q\') != 22\00")
 (data (i32.const 3104) "eosio::char_to_symbol(\'r\') != 23\00")
 (data (i32.const 3152) "eosio::char_to_symbol(\'s\') != 24\00")
 (data (i32.const 3200) "eosio::char_to_symbol(\'t\') != 25\00")
 (data (i32.const 3248) "eosio::char_to_symbol(\'u\') != 26\00")
 (data (i32.const 3296) "eosio::char_to_symbol(\'v\') != 27\00")
 (data (i32.const 3344) "eosio::char_to_symbol(\'w\') != 28\00")
 (data (i32.const 3392) "eosio::char_to_symbol(\'x\') != 29\00")
 (data (i32.const 3440) "eosio::char_to_symbol(\'y\') != 30\00")
 (data (i32.const 3488) "eosio::char_to_symbol(\'z\') != 31\00")
 (data (i32.const 3536) "a\00")
 (data (i32.const 3552) "eosio::string_to_name(a)\00")
 (data (i32.const 3584) "ba\00")
 (data (i32.const 3600) "eosio::string_to_name(ba)\00")
 (data (i32.const 3632) "cba\00")
 (data (i32.const 3648) "eosio::string_to_name(cba)\00")
 (data (i32.const 3680) "dcba\00")
 (data (i32.const 3696) "eosio::string_to_name(dcba)\00")
 (data (i32.const 3728) "edcba\00")
 (data (i32.const 3744) "eosio::string_to_name(edcba)\00")
 (data (i32.const 3776) "fedcba\00")
 (data (i32.const 3792) "eosio::string_to_name(fedcba)\00")
 (data (i32.const 3824) "gfedcba\00")
 (data (i32.const 3840) "eosio::string_to_name(gfedcba)\00")
 (data (i32.const 3872) "hgfedcba\00")
 (data (i32.const 3888) "eosio::string_to_name(hgfedcba)\00")
 (data (i32.const 3920) "ihgfedcba\00")
 (data (i32.const 3936) "eosio::string_to_name(ihgfedcba)\00")
 (data (i32.const 3984) "jihgfedcba\00")
 (data (i32.const 4000) "eosio::string_to_name(jihgfedcba)\00")
 (data (i32.const 4048) "kjihgfedcba\00")
 (data (i32.const 4064) "eosio::string_to_name(kjihgfedcba)\00")
 (data (i32.const 4112) "lkjihgfedcba\00")
 (data (i32.const 4128) "eosio::string_to_name(lkjihgfedcba)\00")
 (data (i32.const 4176) "mlkjihgfedcba\00")
 (data (i32.const 4192) "eosio::string_to_name(mlkjihgfedcba)\00")
 (data (i32.const 4240) "mlkjihgfedcba1\00")
 (data (i32.const 4256) "mlkjihgfedcba2\00")
 (data (i32.const 4272) "eosio::string_to_name(mlkjihgfedcba2)\00")
 (data (i32.const 4320) "mlkjihgfedcba55\00")
 (data (i32.const 4336) "mlkjihgfedcba14\00")
 (data (i32.const 4352) "eosio::string_to_name(mlkjihgfedcba14)\00")
 (data (i32.const 4400) "azAA34\00")
 (data (i32.const 4416) "azBB34\00")
 (data (i32.const 4432) "eosio::string_to_name N(azBB34)\00")
 (data (i32.const 4464) "AZaz12Bc34\00")
 (data (i32.const 4480) "eosio::string_to_name AZaz12Bc34\00")
 (data (i32.const 4528) "AAAAAAAAAAAAAAA\00")
 (data (i32.const 4544) "BBBBBBBBBBBBBDDDDDFFFGG\00")
 (data (i32.const 4576) "eosio::string_to_name BBBBBBBBBBBBBDDDDDFFFGG\00")
 (data (i32.const 4624) "eosio::name != N(azAA34)\00")
 (data (i32.const 4656) "eosio::name != N(0)\00")
 (data (i32.const 4688) "AA11\00")
 (data (i32.const 4704) "eosio::name != N(AA11)\00")
 (data (i32.const 4736) "11\00")
 (data (i32.const 4752) "eosio::name != N(11)\00")
 (data (i32.const 4784) "22\00")
 (data (i32.const 4800) "eosio::name != N(22)\00")
 (data (i32.const 4832) "AAAbbcccdd\00")
 (data (i32.const 4848) "eosio::name == eosio::name\00")
 (data (i32.const 4880) "11bbcccdd\00")
 (data (i32.const 4896) "N(11bbcccdd) == tmp\00")
 (data (i32.const 4928) "fixed_point128 instances comparison with same number of decimals\00")
 (data (i32.const 5008) "fixed_point128 instances with different number of decimals\00")
 (data (i32.const 5072) "fixed_point64 instances comparison with same number of decimals\00")
 (data (i32.const 5136) "fixed_point64 instances with different number of decimals\00")
 (data (i32.const 5200) "fixed_point32 instances comparison with same number of decimals\00")
 (data (i32.const 5264) "fixed_point32 instances with different number of decimals\00")
 (data (i32.const 5328) "fixed_point32 instances addition with zero decmimals\00")
 (data (i32.const 5392) "fixed_point64 instances addition with zero decmimals\00")
 (data (i32.const 5456) "fixed_point64 instances subtraction with zero decmimals\00")
 (data (i32.const 5520) "fixed_point32 instances subtraction with zero decmimals\00")
 (data (i32.const 5584) "fixed_point64 instances multiplication result in fixed_point128\00")
 (data (i32.const 5648) "fixed_point32 instances multiplication result in fixed_point64\00")
 (data (i32.const 5712) "divide by zero\00")
 (data (i32.const 5728) ".\00")
 (data (i32.const 5744) "fixed_point64 instances division result from operator and function and compare in fixed_point128\00")
 (data (i32.const 5856) "should\'ve thrown an error\00")
 (data (i32.const 5888) "test_multeq act.values[0] == act.values[2]\00")
 (data (i32.const 5936) "T[] size and unpacked size don\'t match\00")
 (data (i32.const 5984) "test_diveq act.values[0] == act.values[2]\00")
 (data (i32.const 6032) "test_i64_to_double i[0] == d\00")
 (data (i32.const 6064) "test_i64_to_double i[1] == d\00")
 (data (i32.const 6096) "test_i64_to_double i[2] == d\00")
 (data (i32.const 6128) "test_i64_to_double i[3] == d\00")
 (data (i32.const 6160) "test_i64_to_double 0 == d\00")
 (data (i32.const 6192) "test_double_to_i64 2 == i\00")
 (data (i32.const 6224) "test_double_to_i64 -2 == i\00")
 (data (i32.const 6256) "test_double_to_i64 100000 == i\00")
 (data (i32.const 6288) "test_double_to_i64 -100000 == i\00")
 (data (i32.const 6320) "test_double_to_i64 0 == i\00")
 (data (i32.const 6352) "double funcs\00")
 (data (i32.const 6368) "double_eq\00")
 (data (i32.const 6384) "double_gt\00")
 (data (i32.const 6400) "double_lt\00")
 (data (i32.const 6416) "__multi3 result should be -3000\00")
 (data (i32.const 6448) "__multi3 result should be 900\00")
 (data (i32.const 6480) "__multi3 result should be 10000\00")
 (data (i32.const 6512) "__multi3 result should be 100\00")
 (data (i32.const 6544) "__multi3 result should be -30\00")
 (data (i32.const 6576) "__divti3 result should be 0\00")
 (data (i32.const 6608) "__divti3 result should be -3\00")
 (data (i32.const 6640) "__divti3 result should be 1\00")
 (data (i32.const 6672) "__divti3 result should be 33\00")
 (data (i32.const 6704) "__divti3 result should be 100\00")
 (data (i32.const 6736) "__divti3 result should be -30\00")
 (data (i32.const 6768) "Should have eosio_asserted\00")
 (data (i32.const 6800) "__udivti3 result should be 0\00")
 (data (i32.const 6832) "__udivti3 result should be 1\00")
 (data (i32.const 6864) "__lshlti3 result should be 1\00")
 (data (i32.const 6896) "__lshlti3 result should be 2\00")
 (data (i32.const 6928) "__lshlti3 result should be 2^31\00")
 (data (i32.const 6960) "__lshlti3 result should be 2^63\00")
 (data (i32.const 6992) "__lshlti3 result should be 2^64\00")
 (data (i32.const 7024) "__lshlti3 result should be 2^127\00")
 (data (i32.const 7072) "__lshlti3 result should be 2^128\00")
 (data (i32.const 7120) "__ashlti3 result should be 1\00")
 (data (i32.const 7152) "__ashlti3 result should be 2\00")
 (data (i32.const 7184) "__ashlti3 result should be 2^31\00")
 (data (i32.const 7216) "__ashlti3 result should be 2^63\00")
 (data (i32.const 7248) "__ashlti3 result should be 2^64\00")
 (data (i32.const 7280) "__ashlti3 result should be 2^127\00")
 (data (i32.const 7328) "__ashlti3 result should be 2^128\00")
 (data (i32.const 7376) "__lshrti3 result should be 2^127\00")
 (data (i32.const 7424) "__lshrti3 result should be 2^126\00")
 (data (i32.const 7472) "__lshrti3 result should be 2^64\00")
 (data (i32.const 7504) "__lshrti3 result should be 2^63\00")
 (data (i32.const 7536) "__lshrti3 result should be 2^31\00")
 (data (i32.const 7568) "__lshrti3 result should be 2^0\00")
 (data (i32.const 7600) "__ashrti3 result should be -2^127\00")
 (data (i32.const 7648) "__ashrti3 result should be -2^126\00")
 (data (i32.const 7696) "__ashrti3 result should be -2^125\00")
 (data (i32.const 7744) "__ashrti3 result should be -2^63\00")
 (data (i32.const 7792) "__ashrti3 result should be -2^31\00")
 (data (i32.const 7840) "__ashrti3 result should be -2^0\00")
 (data (i32.const 7872) "__modti3 result should be -30\00")
 (data (i32.const 7904) "__modti3 result should be 30\00")
 (data (i32.const 7936) "__modti3 result should be 10\00")
 (data (i32.const 7968) "__modti3 result should be 0\00")
 (data (i32.const 8000) "should have thrown an error\00")
 (data (i32.const 8032) "real instance value is wrong\00")
 (data (i32.const 8064) "real division result is wrong\00")
 (data (i32.const 8096) "real multiplication result is wrong\00")
 (data (i32.const 8144) "real addition operation result is wrong\00")
 (data (i32.const 8192) "public key does not match\00")
 (data (i32.const 8224) "abc\00")
 (data (i32.const 8240) "sha1 test1\00")
 (data (i32.const 8256) "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq\00")
 (data (i32.const 8320) "sha1 test3\00")
 (data (i32.const 8336) "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu\00")
 (data (i32.const 8464) "sha1 test4\00")
 (data (i32.const 8480) "message digest\00")
 (data (i32.const 8496) "sha1 test5\00")
 (data (i32.const 8512) "\bax\16\bf\8f\01\cf\eaAA@\de]\ae\"#\b0\03a\a3\96\17z\9c\b4\10\ffa\f2\00\15\ad")
 (data (i32.const 8544) "sha256 test1\00")
 (data (i32.const 8560) "$\8dja\d2\068\b8\e5\c0&\93\0c>`9\a3<\e4Yd\ff!g\f6\ec\ed\d4\19\db\06\c1")
 (data (i32.const 8592) "sha256 test3\00")
 (data (i32.const 8608) "\cf[\16\a7x\af\83\80\03l\e5\9e{\04\927\0b$\9b\11\e8\f0zQ\af\acE\03z\fe\e9\d1")
 (data (i32.const 8640) "sha256 test4\00")
 (data (i32.const 8656) "\f7\84oU\cf#\e1N\eb\ea\b5\b4\e1U\0c\ad[P\9e3H\fb\c4\ef\a3\a1A=9<\b6P")
 (data (i32.const 8688) "sha256 test5\00")
 (data (i32.const 8704) "\dd\af5\a1\93az\ba\ccAsI\ae A1\12\e6\faN\89\a9~\a2\n\9e\ee\e6KU\d3\9a!\92\99*\'O\c1\a86\ba<#\a3\fe\eb\bdEMD#d<\e8\0e*\9a\c9O\a5L\a4\9f")
 (data (i32.const 8768) "sha512 test1\00")
 (data (i32.const 8784) " J\8f\c6\dd\a8/\n\0c\ed{\eb\8e\08\a4\16W\c1n\f4h\b2(\a8\'\9b\e31\a7\03\c35\96\fd\15\c1;\1b\07\f9\aa\1d;\eaWx\9c\a01\ad\85\c7\a7\1d\d7\03T\ecc\128\ca4E")
 (data (i32.const 8848) "sha512 test3\00")
 (data (i32.const 8864) "\8e\95\9bu\da\e3\13\da\8c\f4\f7(\14\fc\14?\8fwy\c6\eb\9f\7f\a1r\99\ae\ad\b6\88\90\18P\1d(\9eI\00\f7\e43\1b\99\de\c4\b5C:\c7\d3)\ee\b6\dd&T^\96\e5[\87K\e9\t")
 (data (i32.const 8928) "sha512 test4\00")
 (data (i32.const 8944) "\10}\bf8\9d\9e\9fq\a3\a9_l\05[\92Q\bcRh\c2\be\16\d6\c14\92\eaE\b0\19\9f3\t\e1dU\ab\1e\96\11\8e\8a\90]U\97\b7 8\dd\b3r\a8\98&\04m\e6f\87\bbB\0e|")
 (data (i32.const 9008) "sha512 test5\00")
 (data (i32.const 9024) "ripemd160 test1\00")
 (data (i32.const 9040) "ripemd160 test3\00")
 (data (i32.const 9056) "ripemd160 test4\00")
 (data (i32.const 9072) "ripemd160 test5\00")
 (data (i32.const 9104) "sha1 test2\00")
 (data (i32.const 9120) "\e3\b0\c4B\98\fc\1c\14\9a\fb\f4\c8\99o\b9$\'\aeA\e4d\9b\93L\a4\95\99\1bxR\b8U")
 (data (i32.const 9152) "sha256 test2\00")
 (data (i32.const 9168) "\cf\83\e15~\ef\b8\bd\f1T(P\d6m\80\07\d6 \e4\05\0bW\15\dc\83\f4\a9!\d3l\e9\ceG\d0\d1<]\85\f2\b0\ff\83\18\d2\87~\ec/c\b91\bdGAz\81\a582z\f9\'\da>")
 (data (i32.const 9232) "sha512 test2\00")
 (data (i32.const 9248) "ripemd160 test2\00")
 (data (i32.const 9264) "should have failed\00")
 (data (i32.const 9296) "producers.len != 21\00")
 (data (i32.const 9328) "Active producer\00")
 (data (i32.const 9344) "EwfUD\12\cd\11\ab\12\aeQt")
 (data (i32.const 9360) "active\00")
 (data (i32.const 17568) "send_message_large() should\'ve thrown an error\00")
 (data (i32.const 17616) "tapos_block_prefix does not match\00")
 (data (i32.const 17664) "tapos_block_num does not match\00")
 (data (i32.const 17696) "size: \00")
 (data (i32.const 17712) "transaction size does not match\00")
 (data (i32.const 17744) "EwfUD\12\cd\11\ab\12\aeQt")
 (data (i32.const 17760) "send_transaction_empty() should\'ve thrown an error\00")
 (data (i32.const 17824) "authorizer of onerror action does not match receiver of original action in the deferred transaction\00")
 (data (i32.const 17936) "send_transaction_large() should\'ve thrown an error\00")
 (data (i32.const 18000) "send_transaction_expiring_late() should\'ve thrown an error\00")
 (data (i32.const 18064) "deferred executed\n\00")
 (data (i32.const 18096) "context free actions cannot have authorizations\00")
 (data (i32.const 18144) "dummy\00")
 (data (i32.const 18160) "send_cfa_action_fail() should\'ve thrown an error\00")
 (data (i32.const 18224) "get_action error 0\00")
 (data (i32.const 18256) "\01\02\00\00\00\00\00\00\00\03\00\00\00")
 (data (i32.const 18272) "get_action error\00")
 (data (i32.const 18304) "data_as error\00")
 (data (i32.const 18320) "get_action error -1\00")
 (data (i32.const 18352) "\01\02\00\00\00\00\00\00\00\03\00\00\00")
 (data (i32.const 18368) "bool\00")
 (data (i32.const 18384) "int8\00")
 (data (i32.const 18400) "uint8\00")
 (data (i32.const 18416) "int16\00")
 (data (i32.const 18432) "uint16\00")
 (data (i32.const 18448) "int32\00")
 (data (i32.const 18464) "uint32\00")
 (data (i32.const 18480) "int64\00")
 (data (i32.const 18496) "uint64\00")
 (data (i32.const 18512) "float\00")
 (data (i32.const 18528) "double\00")
 (data (i32.const 18536) "\01\00\00\00\00\00\00\0082\8f\fc\c1\c0\f3?")
 (data (i32.const 18560) "struct\00")
 (data (i32.const 18568) "\n\00\00\00\14\00\00\00")
 (data (i32.const 18576) "staticArray\00")
 (data (i32.const 18592) "hello\00")
 (data (i32.const 18608) "string\00")
 (data (i32.const 18624) "vector\00")
 (data (i32.const 18640) "empty vector\00")
 (data (i32.const 18656) "\n\00\00\00\14\00\00\00\1e\00\00\00")
 (data (i32.const 18672) "std::array<T,N>\00")
 (data (i32.const 18688) "apple\00")
 (data (i32.const 18704) "cat\00")
 (data (i32.const 18720) "panda\00")
 (data (i32.const 18736) "map\00")
 (data (i32.const 18752) "tuple\00")
 (data (i32.const 18768) "eosio\00")
 (data (i32.const 18784) "onerror\00")
 (data (i32.const 18800) "onerror called\n\00")
 (data (i32.const 18816) "Unknown Test\00")
 (data (i32.const 27232) "malloc_from_freed was designed to only be called after _heap was completely allocated\00")
 (export "memory" (memory $0))
 (export "_ZeqRK11checksum256S1_" (func $_ZeqRK11checksum256S1_))
 (export "_ZN5eosio12require_authERKNS_16permission_levelE" (func $_ZN5eosio12require_authERKNS_16permission_levelE))
 (export "_ZN11test_action18read_action_normalEv" (func $_ZN11test_action18read_action_normalEv))
 (export "_ZN11test_action17test_dummy_actionEv" (func $_ZN11test_action17test_dummy_actionEv))
 (export "_ZN11test_action16read_action_to_0Ev" (func $_ZN11test_action16read_action_to_0Ev))
 (export "_ZN11test_action18read_action_to_64kEv" (func $_ZN11test_action18read_action_to_64kEv))
 (export "_ZN11test_action14test_cf_actionEv" (func $_ZN11test_action14test_cf_actionEv))
 (export "_ZN11test_action14require_noticeEyyy" (func $_ZN11test_action14require_noticeEyyy))
 (export "_ZN11test_action12require_authEv" (func $_ZN11test_action12require_authEv))
 (export "_ZN11test_action12assert_falseEv" (func $_ZN11test_action12assert_falseEv))
 (export "_ZN11test_action11assert_trueEv" (func $_ZN11test_action11assert_trueEv))
 (export "_ZN11test_action14assert_true_cfEv" (func $_ZN11test_action14assert_true_cfEv))
 (export "_ZN11test_action10test_abortEv" (func $_ZN11test_action10test_abortEv))
 (export "_ZN11test_action21test_publication_timeEv" (func $_ZN11test_action21test_publication_timeEv))
 (export "_ZN11test_action21test_current_receiverEyyy" (func $_ZN11test_action21test_current_receiverEyyy))
 (export "_ZN11test_action19test_current_senderEv" (func $_ZN11test_action19test_current_senderEv))
 (export "_ZN11test_action3nowEv" (func $_ZN11test_action3nowEv))
 (export "_ZN10test_print13test_prints_lEv" (func $_ZN10test_print13test_prints_lEv))
 (export "_ZN10test_print11test_printsEv" (func $_ZN10test_print11test_printsEv))
 (export "_ZN10test_print11test_printiEv" (func $_ZN10test_print11test_printiEv))
 (export "_ZN10test_print12test_printuiEv" (func $_ZN10test_print12test_printuiEv))
 (export "_ZN10test_print14test_printi128Ev" (func $_ZN10test_print14test_printi128Ev))
 (export "_ZN10test_print11test_printnEv" (func $_ZN10test_print11test_printnEv))
 (export "_ZN10test_types10types_sizeEv" (func $_ZN10test_types10types_sizeEv))
 (export "_ZN10test_types14char_to_symbolEv" (func $_ZN10test_types14char_to_symbolEv))
 (export "_ZN10test_types14string_to_nameEv" (func $_ZN10test_types14string_to_nameEv))
 (export "_ZN10test_types10name_classEv" (func $_ZN10test_types10name_classEv))
 (export "_ZN15test_fixedpoint16create_instancesEv" (func $_ZN15test_fixedpoint16create_instancesEv))
 (export "_ZN15test_fixedpoint13test_additionEv" (func $_ZN15test_fixedpoint13test_additionEv))
 (export "_ZN15test_fixedpoint16test_subtractionEv" (func $_ZN15test_fixedpoint16test_subtractionEv))
 (export "_ZN15test_fixedpoint19test_multiplicationEv" (func $_ZN15test_fixedpoint19test_multiplicationEv))
 (export "_ZN15test_fixedpoint13test_divisionEv" (func $_ZN15test_fixedpoint13test_divisionEv))
 (export "_ZN15test_fixedpoint18test_division_by_0Ev" (func $_ZN15test_fixedpoint18test_division_by_0Ev))
 (export "_ZN9test_math11test_multeqEv" (func $_ZN9test_math11test_multeqEv))
 (export "_ZN9test_math10test_diveqEv" (func $_ZN9test_math10test_diveqEv))
 (export "_ZN9test_math15test_diveq_by_0Ev" (func $_ZN9test_math15test_diveq_by_0Ev))
 (export "_ZN9test_math18test_i64_to_doubleEv" (func $_ZN9test_math18test_i64_to_doubleEv))
 (export "_ZN9test_math18test_double_to_i64Ev" (func $_ZN9test_math18test_double_to_i64Ev))
 (export "_ZN9test_math15test_double_apiEv" (func $_ZN9test_math15test_double_apiEv))
 (export "_ZN9test_math21test_double_api_div_0Ev" (func $_ZN9test_math21test_double_api_div_0Ev))
 (export "_Zli5_ULLLPKc" (func $_Zli5_ULLLPKc))
 (export "_Zli4_LLLPKc" (func $_Zli4_LLLPKc))
 (export "_ZN22test_compiler_builtins11test_multi3Ev" (func $_ZN22test_compiler_builtins11test_multi3Ev))
 (export "_ZN22test_compiler_builtins11test_divti3Ev" (func $_ZN22test_compiler_builtins11test_divti3Ev))
 (export "_ZN22test_compiler_builtins16test_divti3_by_0Ev" (func $_ZN22test_compiler_builtins16test_divti3_by_0Ev))
 (export "_ZN22test_compiler_builtins12test_udivti3Ev" (func $_ZN22test_compiler_builtins12test_udivti3Ev))
 (export "_ZN22test_compiler_builtins17test_udivti3_by_0Ev" (func $_ZN22test_compiler_builtins17test_udivti3_by_0Ev))
 (export "_ZN22test_compiler_builtins12test_lshlti3Ev" (func $_ZN22test_compiler_builtins12test_lshlti3Ev))
 (export "_ZN22test_compiler_builtins12test_ashlti3Ev" (func $_ZN22test_compiler_builtins12test_ashlti3Ev))
 (export "_ZN22test_compiler_builtins12test_lshrti3Ev" (func $_ZN22test_compiler_builtins12test_lshrti3Ev))
 (export "_ZN22test_compiler_builtins12test_ashrti3Ev" (func $_ZN22test_compiler_builtins12test_ashrti3Ev))
 (export "_ZN22test_compiler_builtins11test_modti3Ev" (func $_ZN22test_compiler_builtins11test_modti3Ev))
 (export "_ZN22test_compiler_builtins16test_modti3_by_0Ev" (func $_ZN22test_compiler_builtins16test_modti3_by_0Ev))
 (export "_ZN22test_compiler_builtins12test_umodti3Ev" (func $_ZN22test_compiler_builtins12test_umodti3Ev))
 (export "_ZN22test_compiler_builtins17test_umodti3_by_0Ev" (func $_ZN22test_compiler_builtins17test_umodti3_by_0Ev))
 (export "_ZNK5eosio4realplERKS0_" (func $_ZNK5eosio4realplERKS0_))
 (export "_ZNK5eosio4realmlERKS0_" (func $_ZNK5eosio4realmlERKS0_))
 (export "_ZNK5eosio4realdvERKS0_" (func $_ZNK5eosio4realdvERKS0_))
 (export "_ZN5eosioeqERKNS_4realES2_" (func $_ZN5eosioeqERKNS_4realES2_))
 (export "_ZN5eosiogtERKNS_4realES2_" (func $_ZN5eosiogtERKNS_4realES2_))
 (export "_ZN5eosioltERKNS_4realES2_" (func $_ZN5eosioltERKNS_4realES2_))
 (export "_ZN9test_real16create_instancesEv" (func $_ZN9test_real16create_instancesEv))
 (export "_ZN9test_real13test_divisionEv" (func $_ZN9test_real13test_divisionEv))
 (export "_ZN9test_real18test_division_by_0Ev" (func $_ZN9test_real18test_division_by_0Ev))
 (export "_ZN9test_real19test_multiplicationEv" (func $_ZN9test_real19test_multiplicationEv))
 (export "_ZN9test_real13test_additionEv" (func $_ZN9test_real13test_additionEv))
 (export "my_strlen" (func $my_strlen))
 (export "my_memcmp" (func $my_memcmp))
 (export "_ZN11test_crypto28test_recover_key_assert_trueEv" (func $_ZN11test_crypto28test_recover_key_assert_trueEv))
 (export "_ZN11test_crypto29test_recover_key_assert_falseEv" (func $_ZN11test_crypto29test_recover_key_assert_falseEv))
 (export "_ZN11test_crypto16test_recover_keyEv" (func $_ZN11test_crypto16test_recover_keyEv))
 (export "_ZN11test_crypto9test_sha1Ev" (func $_ZN11test_crypto9test_sha1Ev))
 (export "_ZN11test_crypto11test_sha256Ev" (func $_ZN11test_crypto11test_sha256Ev))
 (export "_ZN11test_crypto11test_sha512Ev" (func $_ZN11test_crypto11test_sha512Ev))
 (export "_ZN11test_crypto14test_ripemd160Ev" (func $_ZN11test_crypto14test_ripemd160Ev))
 (export "_ZN11test_crypto11sha256_nullEv" (func $_ZN11test_crypto11sha256_nullEv))
 (export "_ZN11test_crypto12sha1_no_dataEv" (func $_ZN11test_crypto12sha1_no_dataEv))
 (export "_ZN11test_crypto14sha256_no_dataEv" (func $_ZN11test_crypto14sha256_no_dataEv))
 (export "_ZN11test_crypto14sha512_no_dataEv" (func $_ZN11test_crypto14sha512_no_dataEv))
 (export "_ZN11test_crypto17ripemd160_no_dataEv" (func $_ZN11test_crypto17ripemd160_no_dataEv))
 (export "_ZN11test_crypto19assert_sha256_falseEv" (func $_ZN11test_crypto19assert_sha256_falseEv))
 (export "_ZN11test_crypto18assert_sha256_trueEv" (func $_ZN11test_crypto18assert_sha256_trueEv))
 (export "_ZN11test_crypto17assert_sha1_falseEv" (func $_ZN11test_crypto17assert_sha1_falseEv))
 (export "_ZN11test_crypto16assert_sha1_trueEv" (func $_ZN11test_crypto16assert_sha1_trueEv))
 (export "_ZN11test_crypto19assert_sha512_falseEv" (func $_ZN11test_crypto19assert_sha512_falseEv))
 (export "_ZN11test_crypto18assert_sha512_trueEv" (func $_ZN11test_crypto18assert_sha512_trueEv))
 (export "_ZN11test_crypto22assert_ripemd160_falseEv" (func $_ZN11test_crypto22assert_ripemd160_falseEv))
 (export "_ZN11test_crypto21assert_ripemd160_trueEv" (func $_ZN11test_crypto21assert_ripemd160_trueEv))
 (export "_ZN10test_chain16test_activeprodsEv" (func $_ZN10test_chain16test_activeprodsEv))
 (export "_Z9copy_dataPcjRNSt3__16vectorIcNS0_9allocatorIcEEEE" (func $_Z9copy_dataPcjRNSt3__16vectorIcNS0_9allocatorIcEEEE))
 (export "_ZN16test_transaction11send_actionEv" (func $_ZN16test_transaction11send_actionEv))
 (export "_ZN16test_transaction17send_action_emptyEv" (func $_ZN16test_transaction17send_action_emptyEv))
 (export "_ZN16test_transaction17send_action_largeEv" (func $_ZN16test_transaction17send_action_largeEv))
 (export "_ZN16test_transaction19send_action_recurseEv" (func $_ZN16test_transaction19send_action_recurseEv))
 (export "_ZN16test_transaction23send_action_inline_failEv" (func $_ZN16test_transaction23send_action_inline_failEv))
 (export "_ZN16test_transaction23test_tapos_block_prefixEv" (func $_ZN16test_transaction23test_tapos_block_prefixEv))
 (export "_ZN16test_transaction20test_tapos_block_numEv" (func $_ZN16test_transaction20test_tapos_block_numEv))
 (export "_ZN16test_transaction21test_read_transactionEv" (func $_ZN16test_transaction21test_read_transactionEv))
 (export "_ZN16test_transaction21test_transaction_sizeEv" (func $_ZN16test_transaction21test_transaction_sizeEv))
 (export "_ZN16test_transaction16send_transactionEyyy" (func $_ZN16test_transaction16send_transactionEyyy))
 (export "_ZN16test_transaction18send_action_senderEyyy" (func $_ZN16test_transaction18send_action_senderEyyy))
 (export "_ZN16test_transaction22send_transaction_emptyEyyy" (func $_ZN16test_transaction22send_transaction_emptyEyyy))
 (export "_ZN16test_transaction38send_transaction_trigger_error_handlerEyyy" (func $_ZN16test_transaction38send_transaction_trigger_error_handlerEyyy))
 (export "_ZN16test_transaction26assert_false_error_handlerERKN5eosio20deferred_transactionE" (func $_ZN16test_transaction26assert_false_error_handlerERKN5eosio20deferred_transactionE))
 (export "_ZN16test_transaction22send_transaction_largeEyyy" (func $_ZN16test_transaction22send_transaction_largeEyyy))
 (export "_ZN16test_transaction30send_transaction_expiring_lateEyyy" (func $_ZN16test_transaction30send_transaction_expiring_lateEyyy))
 (export "_ZN16test_transaction14deferred_printEv" (func $_ZN16test_transaction14deferred_printEv))
 (export "_ZN16test_transaction25send_deferred_transactionEyyy" (func $_ZN16test_transaction25send_deferred_transactionEyyy))
 (export "_ZN16test_transaction27cancel_deferred_transactionEv" (func $_ZN16test_transaction27cancel_deferred_transactionEv))
 (export "_ZN16test_transaction14send_cf_actionEv" (func $_ZN16test_transaction14send_cf_actionEv))
 (export "_ZN16test_transaction19send_cf_action_failEv" (func $_ZN16test_transaction19send_cf_action_failEv))
 (export "_ZN16test_transaction18read_inline_actionEv" (func $_ZN16test_transaction18read_inline_actionEv))
 (export "_ZN16test_transaction21read_inline_cf_actionEv" (func $_ZN16test_transaction21read_inline_cf_actionEv))
 (export "_ZN14test_checktime14checktime_passEv" (func $_ZN14test_checktime14checktime_passEv))
 (export "_ZN14test_checktime17checktime_failureEv" (func $_ZN14test_checktime17checktime_failureEv))
 (export "_ZN15test_permission19check_authorizationEyyy" (func $_ZN15test_permission19check_authorizationEyyy))
 (export "_ZN15test_datastream10test_basicEv" (func $_ZN15test_datastream10test_basicEv))
 (export "apply" (func $apply))
 (export "strlen" (func $strlen))
 (export "memcmp" (func $memcmp))
 (export "memccpy" (func $memccpy))
 (export "malloc" (func $malloc))
 (export "free" (func $free))
 (func $_ZeqRK11checksum256S1_ (param $0 i32) (param $1 i32) (result i32)
  (i32.eqz
   (call $memcmp
    (get_local $0)
    (get_local $1)
    (i32.const 32)
   )
  )
 )
 (func $_ZN5eosio12require_authERKNS_16permission_levelE (param $0 i32)
  (call $require_auth2
   (i64.load
    (get_local $0)
   )
   (i64.load offset=8
    (get_local $0)
   )
  )
 )
 (func $_ZN11test_action18read_action_normalEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 112)
    )
   )
  )
  (call $eosio_assert
   (i32.eq
    (call $action_data_size)
    (i32.const 13)
   )
   (i32.const 32)
  )
  (call $eosio_assert
   (i32.eq
    (call $read_action_data
     (get_local $0)
     (i32.const 30)
    )
    (i32.const 13)
   )
   (i32.const 80)
  )
  (call $eosio_assert
   (i32.eq
    (call $read_action_data
     (get_local $0)
     (i32.const 100)
    )
    (i32.const 13)
   )
   (i32.const 96)
  )
  (call $eosio_assert
   (i32.eq
    (call $read_action_data
     (get_local $0)
     (i32.const 5)
    )
    (i32.const 5)
   )
   (i32.const 128)
  )
  (call $eosio_assert
   (i32.eq
    (call $read_action_data
     (get_local $0)
     (i32.const 13)
    )
    (i32.const 13)
   )
   (i32.const 144)
  )
  (call $eosio_assert
   (i32.eq
    (i32.load8_u
     (get_local $0)
    )
    (i32.const 69)
   )
   (i32.const 192)
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=1 align=1
     (get_local $0)
    )
    (i64.const -6119884940280240521)
   )
   (i32.const 240)
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=9 align=1
     (get_local $0)
    )
    (i32.const 1951510034)
   )
   (i32.const 288)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 112)
   )
  )
 )
 (func $_ZN11test_action17test_dummy_actionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i64)
  (local $10 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $10
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 176)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (tee_local $3
     (call $get_action
      (i32.const 1)
      (i32.const 0)
      (i32.add
       (get_local $10)
       (i32.const 64)
      )
      (call $get_action
       (i32.const 1)
       (i32.const 0)
       (i32.add
        (get_local $10)
        (i32.const 64)
       )
       (i32.const 0)
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 336)
  )
  (call $_ZN5eosio10get_actionEmm
   (i32.add
    (get_local $10)
    (i32.const 24)
   )
   (i32.const 1)
   (i32.const 0)
  )
  (set_local $7
   (i64.extend_u/i32
    (i32.shr_s
     (tee_local $4
      (i32.sub
       (tee_local $0
        (i32.load
         (i32.add
          (get_local $10)
          (i32.const 44)
         )
        )
       )
       (tee_local $1
        (i32.load offset=40
         (get_local $10)
        )
       )
      )
     )
     (i32.const 4)
    )
   )
  )
  (set_local $5
   (i32.const 16)
  )
  (loop $label$0
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $0)
    )
   )
   (set_local $5
    (i32.add
     (i32.and
      (get_local $4)
      (i32.const -16)
     )
     (get_local $5)
    )
   )
  )
  (set_local $5
   (i32.sub
    (i32.sub
     (i32.add
      (get_local $3)
      (tee_local $0
       (i32.load offset=52
        (get_local $10)
       )
      )
     )
     (get_local $5)
    )
    (tee_local $3
     (i32.load
      (i32.add
       (get_local $10)
       (i32.const 56)
      )
     )
    )
   )
  )
  (set_local $7
   (i64.extend_u/i32
    (i32.sub
     (get_local $3)
     (get_local $0)
    )
   )
  )
  (loop $label$2
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const -1)
    )
   )
   (br_if $label$2
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (call $eosio_assert
   (i32.eqz
    (get_local $5)
   )
   (i32.const 368)
  )
  (set_local $7
   (i64.const 0)
  )
  (set_local $6
   (i64.const 59)
  )
  (set_local $5
   (i32.const 416)
  )
  (set_local $2
   (i64.load offset=24
    (get_local $10)
   )
  )
  (set_local $8
   (i64.const 0)
  )
  (loop $label$3
   (block $label$4
    (block $label$5
     (block $label$6
      (block $label$7
       (block $label$8
        (br_if $label$8
         (i64.gt_u
          (get_local $7)
          (i64.const 6)
         )
        )
        (br_if $label$7
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $5)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$6)
       )
       (set_local $9
        (i64.const 0)
       )
       (br_if $label$5
        (i64.le_u
         (get_local $7)
         (i64.const 11)
        )
       )
       (br $label$4)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $9
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $9
     (i64.shl
      (i64.and
       (get_local $9)
       (i64.const 31)
      )
      (i64.and
       (get_local $6)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (set_local $7
    (i64.add
     (get_local $7)
     (i64.const 1)
    )
   )
   (set_local $8
    (i64.or
     (get_local $9)
     (get_local $8)
    )
   )
   (br_if $label$3
    (i64.ne
     (tee_local $6
      (i64.add
       (get_local $6)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $8)
   )
   (i32.const 432)
  )
  (call $_ZN5eosio6action7data_asI12dummy_actionEET_v
   (i32.add
    (get_local $10)
    (i32.const 8)
   )
   (i32.add
    (get_local $10)
    (i32.const 24)
   )
  )
  (block $label$9
   (block $label$10
    (block $label$11
     (br_if $label$11
      (i64.ne
       (i64.load offset=9 align=1
        (get_local $10)
       )
       (i64.const 200)
      )
     )
     (drop
      (call $get_context_free_data
       (i32.const 0)
       (i32.const 0)
       (i32.const 0)
      )
     )
     (call $eosio_assert
      (i32.const 0)
      (i32.const 464)
     )
     (br_if $label$10
      (tee_local $5
       (i32.load offset=52
        (get_local $10)
       )
      )
     )
     (br $label$9)
    )
    (call $eosio_assert
     (i32.eq
      (i32.load8_u offset=8
       (get_local $10)
      )
      (i32.const 69)
     )
     (i32.const 528)
    )
    (call $eosio_assert
     (i64.eq
      (i64.load offset=9 align=1
       (get_local $10)
      )
      (i64.const -6119884940280240521)
     )
     (i32.const 576)
    )
    (call $eosio_assert
     (i32.eq
      (i32.load offset=17 align=1
       (get_local $10)
      )
      (i32.const 1951510034)
     )
     (i32.const 624)
    )
    (br_if $label$9
     (i32.eqz
      (tee_local $5
       (i32.load offset=52
        (get_local $10)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $10)
     (i32.const 56)
    )
    (get_local $5)
   )
   (call $_ZdlPv
    (get_local $5)
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $5
      (i32.load offset=40
       (get_local $10)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $10)
     (i32.const 44)
    )
    (get_local $5)
   )
   (call $_ZdlPv
    (get_local $5)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $10)
    (i32.const 176)
   )
  )
 )
 (func $_ZN5eosio10get_actionEmm (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $5
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (tee_local $3
     (call $get_action
      (get_local $1)
      (get_local $2)
      (i32.const 0)
      (i32.const 0)
     )
    )
    (i32.const 0)
   )
   (i32.const 736)
  )
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (get_local $5)
     (i32.and
      (i32.add
       (get_local $3)
       (i32.const 15)
      )
      (i32.const -16)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.eq
    (get_local $3)
    (call $get_action
     (get_local $1)
     (get_local $2)
     (get_local $4)
     (get_local $3)
    )
   )
   (i32.const 336)
  )
  (i64.store offset=16
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (i32.add
    (get_local $0)
    (i32.const 24)
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i32.store
   (tee_local $1
    (get_local $5)
   )
   (get_local $4)
  )
  (i32.store offset=8
   (get_local $1)
   (tee_local $2
    (i32.add
     (get_local $4)
     (get_local $3)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (get_local $3)
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (get_local $4)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (get_local $2)
     (tee_local $3
      (i32.add
       (get_local $4)
       (i32.const 8)
      )
     )
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (get_local $3)
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (get_local $1)
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNSt3__16vectorIcNS7_9allocatorIcEEEE
    (call $_ZN5eosiorsINS_10datastreamIPKcEENS_16permission_levelEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE
     (get_local $1)
     (i32.add
      (get_local $0)
      (i32.const 16)
     )
    )
    (i32.add
     (get_local $0)
     (i32.const 28)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 16)
   )
  )
 )
 (func $_ZN5eosio6action7data_asI12dummy_actionEET_v (param $0 i32) (param $1 i32)
  (local $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (set_local $2
   (i64.load offset=8
    (get_local $1)
   )
  )
  (set_local $7
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $4
   (i32.const 672)
  )
  (set_local $5
   (i64.const 0)
  )
  (loop $label$0
   (set_local $6
    (i64.const 0)
   )
   (block $label$1
    (br_if $label$1
     (i64.gt_u
      (get_local $7)
      (i64.const 11)
     )
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (i32.and
         (i32.add
          (tee_local $3
           (i32.load8_s
            (get_local $4)
           )
          )
          (i32.const -97)
         )
         (i32.const 255)
        )
        (i32.const 25)
       )
      )
      (set_local $3
       (i32.add
        (get_local $3)
        (i32.const 165)
       )
      )
      (br $label$2)
     )
     (set_local $3
      (select
       (i32.add
        (get_local $3)
        (i32.const 208)
       )
       (i32.const 0)
       (i32.lt_u
        (i32.and
         (i32.add
          (get_local $3)
          (i32.const -49)
         )
         (i32.const 255)
        )
        (i32.const 5)
       )
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.extend_u/i32
       (i32.and
        (get_local $3)
        (i32.const 31)
       )
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $7
    (i64.add
     (get_local $7)
     (i64.const 1)
    )
   )
   (set_local $5
    (i64.or
     (get_local $6)
     (get_local $5)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $5)
   )
   (i32.const 688)
  )
  (set_local $2
   (i64.load
    (get_local $1)
   )
  )
  (set_local $7
   (i64.const 0)
  )
  (set_local $6
   (i64.const 59)
  )
  (set_local $4
   (i32.const 416)
  )
  (set_local $5
   (i64.const 0)
  )
  (loop $label$4
   (block $label$5
    (block $label$6
     (block $label$7
      (block $label$8
       (block $label$9
        (br_if $label$9
         (i64.gt_u
          (get_local $7)
          (i64.const 6)
         )
        )
        (br_if $label$8
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$7)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$6
        (i64.le_u
         (get_local $7)
         (i64.const 11)
        )
       )
       (br $label$5)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $6)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $7
    (i64.add
     (get_local $7)
     (i64.const 1)
    )
   )
   (set_local $5
    (i64.or
     (get_local $8)
     (get_local $5)
    )
   )
   (br_if $label$4
    (i64.ne
     (tee_local $6
      (i64.add
       (get_local $6)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $5)
   )
   (i32.const 704)
  )
  (call $eosio_assert
   (i32.ne
    (tee_local $3
     (i32.sub
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 32)
       )
      )
      (tee_local $4
       (i32.load offset=28
        (get_local $1)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (get_local $4)
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $3)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 1)
    )
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $3)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 9)
    )
    (i32.add
     (get_local $4)
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEENS_16permission_levelEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i32)
  (local $7 i32)
  (set_local $7
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $7
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.le_u
       (tee_local $4
        (i32.wrap/i64
         (get_local $5)
        )
       )
       (tee_local $6
        (i32.shr_s
         (i32.sub
          (tee_local $2
           (i32.load offset=4
            (get_local $1)
           )
          )
          (tee_local $7
           (i32.load
            (get_local $1)
           )
          )
         )
         (i32.const 4)
        )
       )
      )
     )
     (call $_ZNSt3__16vectorIN5eosio16permission_levelENS_9allocatorIS2_EEE8__appendEj
      (get_local $1)
      (i32.sub
       (get_local $4)
       (get_local $6)
      )
     )
     (br_if $label$2
      (i32.ne
       (tee_local $7
        (i32.load
         (get_local $1)
        )
       )
       (tee_local $2
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
      )
     )
     (br $label$1)
    )
    (block $label$4
     (br_if $label$4
      (i32.ge_u
       (get_local $4)
       (get_local $6)
      )
     )
     (i32.store
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
      (tee_local $2
       (i32.add
        (get_local $7)
        (i32.shl
         (get_local $4)
         (i32.const 4)
        )
       )
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (get_local $7)
      (get_local $2)
     )
    )
   )
   (set_local $6
    (i32.load
     (tee_local $4
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
   )
   (loop $label$5
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (tee_local $3
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
        )
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (get_local $7)
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $6
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (get_local $3)
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $6
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (br_if $label$5
     (i32.ne
      (tee_local $7
       (i32.add
        (get_local $7)
        (i32.const 16)
       )
      )
      (get_local $2)
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNSt3__16vectorIcNS7_9allocatorIcEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (set_local $5
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $7
   (i32.const 0)
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $5)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $5
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $5
     (i32.add
      (get_local $5)
      (i32.const 1)
     )
    )
   )
   (set_local $6
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $7
        (i32.and
         (get_local $7)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $6)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (br_if $label$2
     (i32.le_u
      (tee_local $3
       (i32.wrap/i64
        (get_local $6)
       )
      )
      (tee_local $2
       (i32.sub
        (tee_local $7
         (i32.load offset=4
          (get_local $1)
         )
        )
        (tee_local $4
         (i32.load
          (get_local $1)
         )
        )
       )
      )
     )
    )
    (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
     (get_local $1)
     (i32.sub
      (get_local $3)
      (get_local $2)
     )
    )
    (set_local $5
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
     )
    )
    (set_local $4
     (i32.load
      (get_local $1)
     )
    )
    (br $label$1)
   )
   (br_if $label$1
    (i32.ge_u
     (get_local $3)
     (get_local $2)
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
    (tee_local $7
     (i32.add
      (get_local $4)
      (get_local $3)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.ge_u
    (i32.sub
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
     )
     (get_local $5)
    )
    (tee_local $5
     (i32.sub
      (get_local $7)
      (get_local $4)
     )
    )
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $4)
    (i32.load
     (tee_local $7
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (get_local $5)
   )
  )
  (i32.store
   (get_local $7)
   (i32.add
    (i32.load
     (get_local $7)
    )
    (get_local $5)
   )
  )
  (get_local $0)
 )
 (func $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.ge_u
         (i32.sub
          (tee_local $2
           (i32.load offset=8
            (get_local $0)
           )
          )
          (tee_local $6
           (i32.load offset=4
            (get_local $0)
           )
          )
         )
         (get_local $1)
        )
       )
       (br_if $label$2
        (i32.le_s
         (tee_local $4
          (i32.add
           (tee_local $3
            (i32.sub
             (get_local $6)
             (tee_local $5
              (i32.load
               (get_local $0)
              )
             )
            )
           )
           (get_local $1)
          )
         )
         (i32.const -1)
        )
       )
       (set_local $6
        (i32.const 2147483647)
       )
       (block $label$5
        (br_if $label$5
         (i32.gt_u
          (tee_local $2
           (i32.sub
            (get_local $2)
            (get_local $5)
           )
          )
          (i32.const 1073741822)
         )
        )
        (br_if $label$3
         (i32.eqz
          (tee_local $6
           (select
            (get_local $4)
            (tee_local $6
             (i32.shl
              (get_local $2)
              (i32.const 1)
             )
            )
            (i32.lt_u
             (get_local $6)
             (get_local $4)
            )
           )
          )
         )
        )
       )
       (set_local $2
        (call $_Znwj
         (get_local $6)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
      (loop $label$6
       (i32.store8
        (get_local $6)
        (i32.const 0)
       )
       (i32.store
        (get_local $0)
        (tee_local $6
         (i32.add
          (i32.load
           (get_local $0)
          )
          (i32.const 1)
         )
        )
       )
       (br_if $label$6
        (tee_local $1
         (i32.add
          (get_local $1)
          (i32.const -1)
         )
        )
       )
       (br $label$0)
      )
     )
     (set_local $6
      (i32.const 0)
     )
     (set_local $2
      (i32.const 0)
     )
     (br $label$1)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
     (get_local $0)
    )
    (unreachable)
   )
   (set_local $4
    (i32.add
     (get_local $2)
     (get_local $6)
    )
   )
   (set_local $6
    (tee_local $5
     (i32.add
      (get_local $2)
      (get_local $3)
     )
    )
   )
   (loop $label$7
    (i32.store8
     (get_local $6)
     (i32.const 0)
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$7
     (tee_local $1
      (i32.add
       (get_local $1)
       (i32.const -1)
      )
     )
    )
   )
   (set_local $5
    (i32.sub
     (get_local $5)
     (tee_local $2
      (i32.sub
       (i32.load
        (tee_local $3
         (i32.add
          (get_local $0)
          (i32.const 4)
         )
        )
       )
       (tee_local $1
        (i32.load
         (get_local $0)
        )
       )
      )
     )
    )
   )
   (block $label$8
    (br_if $label$8
     (i32.lt_s
      (get_local $2)
      (i32.const 1)
     )
    )
    (drop
     (call $memcpy
      (get_local $5)
      (get_local $1)
      (get_local $2)
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
   )
   (i32.store
    (get_local $0)
    (get_local $5)
   )
   (i32.store
    (get_local $3)
    (get_local $6)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (get_local $4)
   )
   (br_if $label$0
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (return)
  )
 )
 (func $_ZNSt3__16vectorIN5eosio16permission_levelENS_9allocatorIS2_EEE8__appendEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.ge_u
         (i32.shr_s
          (i32.sub
           (tee_local $2
            (i32.load offset=8
             (get_local $0)
            )
           )
           (tee_local $7
            (i32.load offset=4
             (get_local $0)
            )
           )
          )
          (i32.const 4)
         )
         (get_local $1)
        )
       )
       (br_if $label$2
        (i32.ge_u
         (tee_local $4
          (i32.add
           (tee_local $3
            (i32.shr_s
             (i32.sub
              (get_local $7)
              (tee_local $6
               (i32.load
                (get_local $0)
               )
              )
             )
             (i32.const 4)
            )
           )
           (get_local $1)
          )
         )
         (i32.const 268435456)
        )
       )
       (set_local $5
        (i32.const 268435455)
       )
       (block $label$5
        (br_if $label$5
         (i32.gt_u
          (i32.shr_s
           (tee_local $2
            (i32.sub
             (get_local $2)
             (get_local $6)
            )
           )
           (i32.const 4)
          )
          (i32.const 134217726)
         )
        )
        (br_if $label$3
         (i32.eqz
          (tee_local $5
           (select
            (get_local $4)
            (tee_local $5
             (i32.shr_s
              (get_local $2)
              (i32.const 3)
             )
            )
            (i32.lt_u
             (get_local $5)
             (get_local $4)
            )
           )
          )
         )
        )
        (br_if $label$1
         (i32.ge_u
          (get_local $5)
          (i32.const 268435456)
         )
        )
       )
       (set_local $2
        (call $_Znwj
         (i32.shl
          (get_local $5)
          (i32.const 4)
         )
        )
       )
       (set_local $7
        (i32.load
         (i32.add
          (get_local $0)
          (i32.const 4)
         )
        )
       )
       (set_local $6
        (i32.load
         (get_local $0)
        )
       )
       (br $label$0)
      )
      (i32.store
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
       (i32.add
        (get_local $7)
        (i32.shl
         (get_local $1)
         (i32.const 4)
        )
       )
      )
      (return)
     )
     (set_local $5
      (i32.const 0)
     )
     (set_local $2
      (i32.const 0)
     )
     (br $label$0)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
     (get_local $0)
    )
    (unreachable)
   )
   (call $abort)
   (unreachable)
  )
  (set_local $4
   (i32.sub
    (tee_local $3
     (i32.add
      (get_local $2)
      (i32.shl
       (get_local $3)
       (i32.const 4)
      )
     )
    )
    (tee_local $7
     (i32.sub
      (get_local $7)
      (get_local $6)
     )
    )
   )
  )
  (set_local $1
   (i32.add
    (get_local $3)
    (i32.shl
     (get_local $1)
     (i32.const 4)
    )
   )
  )
  (set_local $5
   (i32.add
    (get_local $2)
    (i32.shl
     (get_local $5)
     (i32.const 4)
    )
   )
  )
  (block $label$6
   (br_if $label$6
    (i32.lt_s
     (get_local $7)
     (i32.const 1)
    )
   )
   (drop
    (call $memcpy
     (get_local $4)
     (get_local $6)
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $0)
    )
   )
  )
  (i32.store
   (get_local $0)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $5)
  )
  (block $label$7
   (br_if $label$7
    (i32.eqz
     (get_local $6)
    )
   )
   (call $_ZdlPv
    (get_local $6)
   )
  )
 )
 (func $_ZN11test_action16read_action_to_0Ev
  (drop
   (call $read_action_data
    (i32.const 0)
    (call $action_data_size)
   )
  )
 )
 (func $_ZN11test_action18read_action_to_64kEv
  (drop
   (call $read_action_data
    (i32.const 65534)
    (call $action_data_size)
   )
  )
 )
 (func $_ZN11test_action14test_cf_actionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $9
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 128)
    )
   )
  )
  (call $_ZN5eosio10get_actionEmm
   (i32.add
    (get_local $9)
    (i32.const 72)
   )
   (i32.const 0)
   (i32.const 0)
  )
  (call $_ZN5eosio6action7data_asI9cf_actionEET_v
   (i32.add
    (get_local $9)
    (i32.const 64)
   )
   (i32.add
    (get_local $9)
    (i32.const 72)
   )
  )
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (block $label$6
         (block $label$7
          (block $label$8
           (br_if $label$8
            (i32.gt_u
             (tee_local $2
              (i32.add
               (tee_local $1
                (i32.load offset=64
                 (get_local $9)
                )
               )
               (i32.const -200)
              )
             )
             (i32.const 4)
            )
           )
           (block $label$9
            (br_table $label$9 $label$7 $label$6 $label$5 $label$4 $label$9
             (get_local $2)
            )
           )
           (drop
            (call $is_privileged
             (i64.load offset=80
              (get_local $9)
             )
            )
           )
           (call $eosio_assert
            (i32.const 0)
            (i32.const 928)
           )
           (br_if $label$2
            (tee_local $2
             (i32.load offset=100
              (get_local $9)
             )
            )
           )
           (br $label$1)
          )
          (br_if $label$3
           (i32.ne
            (get_local $1)
            (i32.const 100)
           )
          )
          (call $eosio_assert
           (i32.gt_s
            (tee_local $0
             (call $get_context_free_data
              (i32.load offset=68
               (get_local $9)
              )
              (i32.const 0)
              (i32.const 0)
             )
            )
            (i32.const 0)
           )
           (i32.const 784)
          )
          (i32.store offset=120
           (get_local $9)
           (i32.const 0)
          )
          (i64.store offset=112
           (get_local $9)
           (i64.const 0)
          )
          (set_local $2
           (i32.const 0)
          )
          (block $label$10
           (br_if $label$10
            (i32.eqz
             (get_local $0)
            )
           )
           (br_if $label$0
            (i32.le_s
             (get_local $0)
             (i32.const -1)
            )
           )
           (i32.store
            (i32.add
             (get_local $9)
             (i32.const 120)
            )
            (i32.add
             (tee_local $2
              (call $_Znwj
               (get_local $0)
              )
             )
             (get_local $0)
            )
           )
           (i32.store offset=112
            (get_local $9)
            (get_local $2)
           )
           (i32.store offset=116
            (get_local $9)
            (get_local $2)
           )
           (set_local $1
            (get_local $0)
           )
           (loop $label$11
            (i32.store8
             (get_local $2)
             (i32.const 0)
            )
            (i32.store offset=116
             (get_local $9)
             (tee_local $2
              (i32.add
               (i32.load offset=116
                (get_local $9)
               )
               (i32.const 1)
              )
             )
            )
            (br_if $label$11
             (tee_local $1
              (i32.add
               (get_local $1)
               (i32.const -1)
              )
             )
            )
           )
           (set_local $2
            (i32.load offset=112
             (get_local $9)
            )
           )
          )
          (call $eosio_assert
           (i32.eq
            (call $get_context_free_data
             (i32.load offset=68
              (get_local $9)
             )
             (get_local $2)
             (get_local $0)
            )
            (i32.sub
             (i32.load offset=116
              (get_local $9)
             )
             (i32.load offset=112
              (get_local $9)
             )
            )
           )
           (i32.const 816)
          )
          (call $eosio_assert
           (i32.gt_u
            (i32.sub
             (i32.load offset=116
              (get_local $9)
             )
             (tee_local $2
              (i32.load offset=112
               (get_local $9)
              )
             )
            )
            (i32.const 3)
           )
           (i32.const 720)
          )
          (drop
           (call $memcpy
            (i32.add
             (get_local $9)
             (i32.const 8)
            )
            (get_local $2)
            (i32.const 4)
           )
          )
          (i32.store offset=60
           (get_local $9)
           (tee_local $2
            (i32.load offset=8
             (get_local $9)
            )
           )
          )
          (call $eosio_assert
           (i32.eq
            (get_local $2)
            (i32.load offset=64
             (get_local $9)
            )
           )
           (i32.const 848)
          )
          (i32.store8
           (i32.add
            (i32.add
             (get_local $9)
             (i32.const 52)
            )
            (i32.const 4)
           )
           (i32.load8_u offset=868
            (i32.const 0)
           )
          )
          (i32.store offset=52
           (get_local $9)
           (i32.load offset=864 align=1
            (i32.const 0)
           )
          )
          (call $sha256
           (i32.add
            (get_local $9)
            (i32.const 52)
           )
           (i32.const 5)
           (i32.add
            (get_local $9)
            (i32.const 8)
           )
          )
          (call $assert_sha256
           (i32.add
            (get_local $9)
            (i32.const 52)
           )
           (i32.const 5)
           (i32.add
            (get_local $9)
            (i32.const 8)
           )
          )
          (drop
           (call $action_data_size)
          )
          (call $prints
           (i32.const 880)
          )
          (i32.store offset=48
           (get_local $9)
           (i32.const 42)
          )
          (drop
           (call $memccpy
            (i32.add
             (get_local $9)
             (i32.const 60)
            )
            (i32.add
             (get_local $9)
             (i32.const 48)
            )
            (i32.const 4)
            (i32.const 4)
           )
          )
          (call $eosio_assert
           (i32.ne
            (call $transaction_size)
            (i32.const 0)
           )
           (i32.const 896)
          )
          (br_if $label$3
           (i32.eqz
            (tee_local $2
             (i32.load offset=112
              (get_local $9)
             )
            )
           )
          )
          (i32.store offset=116
           (get_local $9)
           (get_local $2)
          )
          (call $_ZdlPv
           (get_local $2)
          )
          (br_if $label$2
           (tee_local $2
            (i32.load offset=100
             (get_local $9)
            )
           )
          )
          (br $label$1)
         )
         (drop
          (call $get_active_producers
           (i32.const 0)
           (i32.const 0)
          )
         )
         (call $eosio_assert
          (i32.const 0)
          (i32.const 976)
         )
         (br_if $label$2
          (tee_local $2
           (i32.load offset=100
            (get_local $9)
           )
          )
         )
         (br $label$1)
        )
        (set_local $4
         (i64.const 0)
        )
        (set_local $3
         (i64.const 59)
        )
        (set_local $2
         (i32.const 416)
        )
        (set_local $5
         (i64.const 0)
        )
        (loop $label$12
         (block $label$13
          (block $label$14
           (block $label$15
            (block $label$16
             (block $label$17
              (br_if $label$17
               (i64.gt_u
                (get_local $4)
                (i64.const 6)
               )
              )
              (br_if $label$16
               (i32.gt_u
                (i32.and
                 (i32.add
                  (tee_local $1
                   (i32.load8_s
                    (get_local $2)
                   )
                  )
                  (i32.const -97)
                 )
                 (i32.const 255)
                )
                (i32.const 25)
               )
              )
              (set_local $1
               (i32.add
                (get_local $1)
                (i32.const 165)
               )
              )
              (br $label$15)
             )
             (set_local $6
              (i64.const 0)
             )
             (br_if $label$14
              (i64.le_u
               (get_local $4)
               (i64.const 11)
              )
             )
             (br $label$13)
            )
            (set_local $1
             (select
              (i32.add
               (get_local $1)
               (i32.const 208)
              )
              (i32.const 0)
              (i32.lt_u
               (i32.and
                (i32.add
                 (get_local $1)
                 (i32.const -49)
                )
                (i32.const 255)
               )
               (i32.const 5)
              )
             )
            )
           )
           (set_local $6
            (i64.shr_s
             (i64.shl
              (i64.extend_u/i32
               (get_local $1)
              )
              (i64.const 56)
             )
             (i64.const 56)
            )
           )
          )
          (set_local $6
           (i64.shl
            (i64.and
             (get_local $6)
             (i64.const 31)
            )
            (i64.and
             (get_local $3)
             (i64.const 4294967295)
            )
           )
          )
         )
         (set_local $2
          (i32.add
           (get_local $2)
           (i32.const 1)
          )
         )
         (set_local $4
          (i64.add
           (get_local $4)
           (i64.const 1)
          )
         )
         (set_local $5
          (i64.or
           (get_local $6)
           (get_local $5)
          )
         )
         (br_if $label$12
          (i64.ne
           (tee_local $3
            (i64.add
             (get_local $3)
             (i64.const -5)
            )
           )
           (i64.const -6)
          )
         )
        )
        (set_local $4
         (i64.const 0)
        )
        (set_local $3
         (i64.const 59)
        )
        (set_local $2
         (i32.const 416)
        )
        (set_local $7
         (i64.const 0)
        )
        (loop $label$18
         (block $label$19
          (block $label$20
           (block $label$21
            (block $label$22
             (block $label$23
              (br_if $label$23
               (i64.gt_u
                (get_local $4)
                (i64.const 6)
               )
              )
              (br_if $label$22
               (i32.gt_u
                (i32.and
                 (i32.add
                  (tee_local $1
                   (i32.load8_s
                    (get_local $2)
                   )
                  )
                  (i32.const -97)
                 )
                 (i32.const 255)
                )
                (i32.const 25)
               )
              )
              (set_local $1
               (i32.add
                (get_local $1)
                (i32.const 165)
               )
              )
              (br $label$21)
             )
             (set_local $6
              (i64.const 0)
             )
             (br_if $label$20
              (i64.le_u
               (get_local $4)
               (i64.const 11)
              )
             )
             (br $label$19)
            )
            (set_local $1
             (select
              (i32.add
               (get_local $1)
               (i32.const 208)
              )
              (i32.const 0)
              (i32.lt_u
               (i32.and
                (i32.add
                 (get_local $1)
                 (i32.const -49)
                )
                (i32.const 255)
               )
               (i32.const 5)
              )
             )
            )
           )
           (set_local $6
            (i64.shr_s
             (i64.shl
              (i64.extend_u/i32
               (get_local $1)
              )
              (i64.const 56)
             )
             (i64.const 56)
            )
           )
          )
          (set_local $6
           (i64.shl
            (i64.and
             (get_local $6)
             (i64.const 31)
            )
            (i64.and
             (get_local $3)
             (i64.const 4294967295)
            )
           )
          )
         )
         (set_local $2
          (i32.add
           (get_local $2)
           (i32.const 1)
          )
         )
         (set_local $4
          (i64.add
           (get_local $4)
           (i64.const 1)
          )
         )
         (set_local $7
          (i64.or
           (get_local $6)
           (get_local $7)
          )
         )
         (br_if $label$18
          (i64.ne
           (tee_local $3
            (i64.add
             (get_local $3)
             (i64.const -5)
            )
           )
           (i64.const -6)
          )
         )
        )
        (set_local $4
         (i64.const 0)
        )
        (set_local $3
         (i64.const 59)
        )
        (set_local $2
         (i32.const 416)
        )
        (set_local $8
         (i64.const 0)
        )
        (loop $label$24
         (block $label$25
          (block $label$26
           (block $label$27
            (block $label$28
             (block $label$29
              (br_if $label$29
               (i64.gt_u
                (get_local $4)
                (i64.const 6)
               )
              )
              (br_if $label$28
               (i32.gt_u
                (i32.and
                 (i32.add
                  (tee_local $1
                   (i32.load8_s
                    (get_local $2)
                   )
                  )
                  (i32.const -97)
                 )
                 (i32.const 255)
                )
                (i32.const 25)
               )
              )
              (set_local $1
               (i32.add
                (get_local $1)
                (i32.const 165)
               )
              )
              (br $label$27)
             )
             (set_local $6
              (i64.const 0)
             )
             (br_if $label$26
              (i64.le_u
               (get_local $4)
               (i64.const 11)
              )
             )
             (br $label$25)
            )
            (set_local $1
             (select
              (i32.add
               (get_local $1)
               (i32.const 208)
              )
              (i32.const 0)
              (i32.lt_u
               (i32.and
                (i32.add
                 (get_local $1)
                 (i32.const -49)
                )
                (i32.const 255)
               )
               (i32.const 5)
              )
             )
            )
           )
           (set_local $6
            (i64.shr_s
             (i64.shl
              (i64.extend_u/i32
               (get_local $1)
              )
              (i64.const 56)
             )
             (i64.const 56)
            )
           )
          )
          (set_local $6
           (i64.shl
            (i64.and
             (get_local $6)
             (i64.const 31)
            )
            (i64.and
             (get_local $3)
             (i64.const 4294967295)
            )
           )
          )
         )
         (set_local $2
          (i32.add
           (get_local $2)
           (i32.const 1)
          )
         )
         (set_local $4
          (i64.add
           (get_local $4)
           (i64.const 1)
          )
         )
         (set_local $8
          (i64.or
           (get_local $6)
           (get_local $8)
          )
         )
         (br_if $label$24
          (i64.ne
           (tee_local $3
            (i64.add
             (get_local $3)
             (i64.const -5)
            )
           )
           (i64.const -6)
          )
         )
        )
        (drop
         (call $db_store_i64
          (get_local $5)
          (get_local $7)
          (get_local $8)
          (i64.const 0)
          (i32.const 864)
          (i32.const 4)
         )
        )
        (call $eosio_assert
         (i32.const 0)
         (i32.const 1024)
        )
        (br_if $label$2
         (tee_local $2
          (i32.load offset=100
           (get_local $9)
          )
         )
        )
        (br $label$1)
       )
       (set_local $4
        (i64.const 0)
       )
       (i64.store offset=8
        (get_local $9)
        (i64.const 0)
       )
       (set_local $3
        (i64.const 59)
       )
       (set_local $2
        (i32.const 416)
       )
       (set_local $5
        (i64.const 0)
       )
       (loop $label$30
        (block $label$31
         (block $label$32
          (block $label$33
           (block $label$34
            (block $label$35
             (br_if $label$35
              (i64.gt_u
               (get_local $4)
               (i64.const 6)
              )
             )
             (br_if $label$34
              (i32.gt_u
               (i32.and
                (i32.add
                 (tee_local $1
                  (i32.load8_s
                   (get_local $2)
                  )
                 )
                 (i32.const -97)
                )
                (i32.const 255)
               )
               (i32.const 25)
              )
             )
             (set_local $1
              (i32.add
               (get_local $1)
               (i32.const 165)
              )
             )
             (br $label$33)
            )
            (set_local $6
             (i64.const 0)
            )
            (br_if $label$32
             (i64.le_u
              (get_local $4)
              (i64.const 11)
             )
            )
            (br $label$31)
           )
           (set_local $1
            (select
             (i32.add
              (get_local $1)
              (i32.const 208)
             )
             (i32.const 0)
             (i32.lt_u
              (i32.and
               (i32.add
                (get_local $1)
                (i32.const -49)
               )
               (i32.const 255)
              )
              (i32.const 5)
             )
            )
           )
          )
          (set_local $6
           (i64.shr_s
            (i64.shl
             (i64.extend_u/i32
              (get_local $1)
             )
             (i64.const 56)
            )
            (i64.const 56)
           )
          )
         )
         (set_local $6
          (i64.shl
           (i64.and
            (get_local $6)
            (i64.const 31)
           )
           (i64.and
            (get_local $3)
            (i64.const 4294967295)
           )
          )
         )
        )
        (set_local $2
         (i32.add
          (get_local $2)
          (i32.const 1)
         )
        )
        (set_local $4
         (i64.add
          (get_local $4)
          (i64.const 1)
         )
        )
        (set_local $5
         (i64.or
          (get_local $6)
          (get_local $5)
         )
        )
        (br_if $label$30
         (i64.ne
          (tee_local $3
           (i64.add
            (get_local $3)
            (i64.const -5)
           )
          )
          (i64.const -6)
         )
        )
       )
       (set_local $4
        (i64.const 0)
       )
       (set_local $3
        (i64.const 59)
       )
       (set_local $2
        (i32.const 416)
       )
       (set_local $7
        (i64.const 0)
       )
       (loop $label$36
        (block $label$37
         (block $label$38
          (block $label$39
           (block $label$40
            (block $label$41
             (br_if $label$41
              (i64.gt_u
               (get_local $4)
               (i64.const 6)
              )
             )
             (br_if $label$40
              (i32.gt_u
               (i32.and
                (i32.add
                 (tee_local $1
                  (i32.load8_s
                   (get_local $2)
                  )
                 )
                 (i32.const -97)
                )
                (i32.const 255)
               )
               (i32.const 25)
              )
             )
             (set_local $1
              (i32.add
               (get_local $1)
               (i32.const 165)
              )
             )
             (br $label$39)
            )
            (set_local $6
             (i64.const 0)
            )
            (br_if $label$38
             (i64.le_u
              (get_local $4)
              (i64.const 11)
             )
            )
            (br $label$37)
           )
           (set_local $1
            (select
             (i32.add
              (get_local $1)
              (i32.const 208)
             )
             (i32.const 0)
             (i32.lt_u
              (i32.and
               (i32.add
                (get_local $1)
                (i32.const -49)
               )
               (i32.const 255)
              )
              (i32.const 5)
             )
            )
           )
          )
          (set_local $6
           (i64.shr_s
            (i64.shl
             (i64.extend_u/i32
              (get_local $1)
             )
             (i64.const 56)
            )
            (i64.const 56)
           )
          )
         )
         (set_local $6
          (i64.shl
           (i64.and
            (get_local $6)
            (i64.const 31)
           )
           (i64.and
            (get_local $3)
            (i64.const 4294967295)
           )
          )
         )
        )
        (set_local $2
         (i32.add
          (get_local $2)
          (i32.const 1)
         )
        )
        (set_local $4
         (i64.add
          (get_local $4)
          (i64.const 1)
         )
        )
        (set_local $7
         (i64.or
          (get_local $6)
          (get_local $7)
         )
        )
        (br_if $label$36
         (i64.ne
          (tee_local $3
           (i64.add
            (get_local $3)
            (i64.const -5)
           )
          )
          (i64.const -6)
         )
        )
       )
       (set_local $4
        (i64.const 0)
       )
       (set_local $3
        (i64.const 59)
       )
       (set_local $2
        (i32.const 416)
       )
       (set_local $8
        (i64.const 0)
       )
       (loop $label$42
        (block $label$43
         (block $label$44
          (block $label$45
           (block $label$46
            (block $label$47
             (br_if $label$47
              (i64.gt_u
               (get_local $4)
               (i64.const 6)
              )
             )
             (br_if $label$46
              (i32.gt_u
               (i32.and
                (i32.add
                 (tee_local $1
                  (i32.load8_s
                   (get_local $2)
                  )
                 )
                 (i32.const -97)
                )
                (i32.const 255)
               )
               (i32.const 25)
              )
             )
             (set_local $1
              (i32.add
               (get_local $1)
               (i32.const 165)
              )
             )
             (br $label$45)
            )
            (set_local $6
             (i64.const 0)
            )
            (br_if $label$44
             (i64.le_u
              (get_local $4)
              (i64.const 11)
             )
            )
            (br $label$43)
           )
           (set_local $1
            (select
             (i32.add
              (get_local $1)
              (i32.const 208)
             )
             (i32.const 0)
             (i32.lt_u
              (i32.and
               (i32.add
                (get_local $1)
                (i32.const -49)
               )
               (i32.const 255)
              )
              (i32.const 5)
             )
            )
           )
          )
          (set_local $6
           (i64.shr_s
            (i64.shl
             (i64.extend_u/i32
              (get_local $1)
             )
             (i64.const 56)
            )
            (i64.const 56)
           )
          )
         )
         (set_local $6
          (i64.shl
           (i64.and
            (get_local $6)
            (i64.const 31)
           )
           (i64.and
            (get_local $3)
            (i64.const 4294967295)
           )
          )
         )
        )
        (set_local $2
         (i32.add
          (get_local $2)
          (i32.const 1)
         )
        )
        (set_local $4
         (i64.add
          (get_local $4)
          (i64.const 1)
         )
        )
        (set_local $8
         (i64.or
          (get_local $6)
          (get_local $8)
         )
        )
        (br_if $label$42
         (i64.ne
          (tee_local $3
           (i64.add
            (get_local $3)
            (i64.const -5)
           )
          )
          (i64.const -6)
         )
        )
       )
       (drop
        (call $db_idx64_store
         (get_local $5)
         (get_local $7)
         (get_local $8)
         (i64.const 0)
         (i32.add
          (get_local $9)
          (i32.const 8)
         )
        )
       )
       (call $eosio_assert
        (i32.const 0)
        (i32.const 1024)
       )
       (br_if $label$2
        (tee_local $2
         (i32.load offset=100
          (get_local $9)
         )
        )
       )
       (br $label$1)
      )
      (i64.store
       (i32.add
        (get_local $9)
        (i32.const 32)
       )
       (i64.const 0)
      )
      (i64.store
       (i32.add
        (get_local $9)
        (i32.const 40)
       )
       (i64.const 0)
      )
      (i64.store offset=24
       (get_local $9)
       (i64.const 0)
      )
      (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
       (i32.add
        (get_local $9)
        (i32.const 112)
       )
       (i32.add
        (get_local $9)
        (i32.const 8)
       )
      )
      (call $send_inline
       (tee_local $2
        (i32.load offset=112
         (get_local $9)
        )
       )
       (i32.sub
        (i32.load offset=116
         (get_local $9)
        )
        (get_local $2)
       )
      )
      (block $label$48
       (br_if $label$48
        (i32.eqz
         (tee_local $2
          (i32.load offset=112
           (get_local $9)
          )
         )
        )
       )
       (i32.store offset=116
        (get_local $9)
        (get_local $2)
       )
       (call $_ZdlPv
        (get_local $2)
       )
      )
      (call $eosio_assert
       (i32.const 0)
       (i32.const 1056)
      )
      (block $label$49
       (br_if $label$49
        (i32.eqz
         (tee_local $2
          (i32.load
           (i32.add
            (get_local $9)
            (i32.const 36)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $9)
         (i32.const 40)
        )
        (get_local $2)
       )
       (call $_ZdlPv
        (get_local $2)
       )
      )
      (br_if $label$3
       (i32.eqz
        (tee_local $2
         (i32.load
          (i32.add
           (get_local $9)
           (i32.const 24)
          )
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $9)
        (i32.const 28)
       )
       (get_local $2)
      )
      (call $_ZdlPv
       (get_local $2)
      )
     )
     (br_if $label$1
      (i32.eqz
       (tee_local $2
        (i32.load offset=100
         (get_local $9)
        )
       )
      )
     )
    )
    (i32.store
     (i32.add
      (get_local $9)
      (i32.const 104)
     )
     (get_local $2)
    )
    (call $_ZdlPv
     (get_local $2)
    )
   )
   (block $label$50
    (br_if $label$50
     (i32.eqz
      (tee_local $2
       (i32.load offset=88
        (get_local $9)
       )
      )
     )
    )
    (i32.store
     (i32.add
      (get_local $9)
      (i32.const 92)
     )
     (get_local $2)
    )
    (call $_ZdlPv
     (get_local $2)
    )
   )
   (i32.store offset=4
    (i32.const 0)
    (i32.add
     (get_local $9)
     (i32.const 128)
    )
   )
   (return)
  )
  (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
   (i32.add
    (get_local $9)
    (i32.const 112)
   )
  )
  (unreachable)
 )
 (func $_ZN5eosio6action7data_asI9cf_actionEET_v (param $0 i32) (param $1 i32)
  (local $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (set_local $2
   (i64.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 1120)
  )
  (set_local $7
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $6)
          (i64.const 8)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $7
    (i64.or
     (get_local $8)
     (get_local $7)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $7)
   )
   (i32.const 688)
  )
  (set_local $2
   (i64.load
    (get_local $1)
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 416)
  )
  (set_local $7
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $6)
          (i64.const 6)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $7
    (i64.or
     (get_local $8)
     (get_local $7)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $7)
   )
   (i32.const 704)
  )
  (i64.store align=4
   (get_local $0)
   (i64.const 100)
  )
  (call $eosio_assert
   (i32.gt_u
    (tee_local $3
     (i32.sub
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 32)
       )
      )
      (tee_local $4
       (i32.load offset=28
        (get_local $1)
       )
      )
     )
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (get_local $4)
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.ne
    (i32.and
     (get_local $3)
     (i32.const -4)
    )
    (i32.const 4)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 4)
    )
    (i32.add
     (get_local $4)
     (i32.const 4)
    )
    (i32.const 4)
   )
  )
 )
 (func $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_ (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=8
   (get_local $0)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $0)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 16)
  )
  (set_local $2
   (i32.add
    (get_local $1)
    (i32.const 16)
   )
  )
  (set_local $6
   (i64.extend_u/i32
    (i32.shr_s
     (tee_local $4
      (i32.sub
       (tee_local $7
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 20)
         )
        )
       )
       (tee_local $3
        (i32.load offset=16
         (get_local $1)
        )
       )
      )
     )
     (i32.const 4)
    )
   )
  )
  (loop $label$0
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $6
      (i64.shr_u
       (get_local $6)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $3)
     (get_local $7)
    )
   )
   (set_local $5
    (i32.add
     (i32.and
      (get_local $4)
      (i32.const -16)
     )
     (get_local $5)
    )
   )
  )
  (set_local $5
   (i32.sub
    (i32.sub
     (tee_local $7
      (i32.load offset=28
       (get_local $1)
      )
     )
     (get_local $5)
    )
    (tee_local $3
     (i32.load
      (i32.add
       (get_local $1)
       (i32.const 32)
      )
     )
    )
   )
  )
  (set_local $4
   (i32.add
    (get_local $1)
    (i32.const 28)
   )
  )
  (set_local $6
   (i64.extend_u/i32
    (i32.sub
     (get_local $3)
     (get_local $7)
    )
   )
  )
  (loop $label$2
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const -1)
    )
   )
   (br_if $label$2
    (i64.ne
     (tee_local $6
      (i64.shr_u
       (get_local $6)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (set_local $7
   (i32.const 0)
  )
  (block $label$3
   (block $label$4
    (br_if $label$4
     (i32.eqz
      (get_local $5)
     )
    )
    (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
     (get_local $0)
     (i32.sub
      (i32.const 0)
      (get_local $5)
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $5
     (i32.load
      (get_local $0)
     )
    )
    (br $label$3)
   )
   (set_local $5
    (i32.const 0)
   )
  )
  (i32.store
   (get_local $8)
   (get_local $5)
  )
  (i32.store offset=8
   (get_local $8)
   (get_local $7)
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (get_local $7)
     (get_local $5)
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $5)
    (get_local $1)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (get_local $7)
     (tee_local $0
      (i32.add
       (get_local $5)
       (i32.const 8)
      )
     )
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (i32.add
     (get_local $1)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (get_local $8)
   (i32.add
    (get_local $5)
    (i32.const 16)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__16vectorIcNS6_9allocatorIcEEEE
    (call $_ZN5eosiolsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
     (get_local $8)
     (get_local $2)
    )
    (get_local $4)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i64)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $4
   (i64.extend_u/i32
    (i32.shr_s
     (i32.sub
      (i32.load offset=4
       (get_local $1)
      )
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 4)
    )
   )
  )
  (set_local $5
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (loop $label$0
   (set_local $3
    (i32.wrap/i64
     (get_local $4)
    )
   )
   (i32.store8 offset=15
    (get_local $7)
    (i32.or
     (i32.shl
      (tee_local $6
       (i64.ne
        (tee_local $4
         (i64.shr_u
          (get_local $4)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $3)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $2)
      )
      (get_local $5)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (tee_local $3
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
     (i32.add
      (get_local $7)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $5
     (i32.add
      (i32.load
       (get_local $3)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $6)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (tee_local $6
      (i32.load
       (get_local $1)
      )
     )
     (tee_local $1
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
     )
    )
   )
   (set_local $3
    (i32.add
     (get_local $0)
     (i32.const 4)
    )
   )
   (loop $label$2
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (tee_local $2
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
        )
       )
       (get_local $5)
      )
      (i32.const 7)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (get_local $3)
      )
      (get_local $6)
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $3)
     (tee_local $5
      (i32.add
       (i32.load
        (get_local $3)
       )
       (i32.const 8)
      )
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (get_local $2)
       )
       (get_local $5)
      )
      (i32.const 7)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (get_local $3)
      )
      (i32.add
       (get_local $6)
       (i32.const 8)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $3)
     (tee_local $5
      (i32.add
       (i32.load
        (get_local $3)
       )
       (i32.const 8)
      )
     )
    )
    (br_if $label$2
     (i32.ne
      (tee_local $6
       (i32.add
        (get_local $6)
        (i32.const 16)
       )
      )
      (get_local $1)
     )
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__16vectorIcNS6_9allocatorIcEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $7
   (i64.extend_u/i32
    (i32.sub
     (i32.load offset=4
      (get_local $1)
     )
     (i32.load
      (get_local $1)
     )
    )
   )
  )
  (set_local $6
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (set_local $2
    (i32.wrap/i64
     (get_local $7)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $7
         (i64.shr_u
          (get_local $7)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $2)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $4)
      )
      (get_local $6)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $6
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $3)
   )
  )
  (call $eosio_assert
   (i32.ge_s
    (i32.sub
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
     )
     (get_local $6)
    )
    (tee_local $5
     (i32.sub
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
      (tee_local $2
       (i32.load
        (get_local $1)
       )
      )
     )
    )
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load
     (tee_local $6
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (get_local $2)
    (get_local $5)
   )
  )
  (i32.store
   (get_local $6)
   (i32.add
    (i32.load
     (get_local $6)
    )
    (get_local $5)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN11test_action14require_noticeEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i64)
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 416)
  )
  (set_local $7
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $6)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $7
    (i64.or
     (get_local $8)
     (get_local $7)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 1136)
  )
  (set_local $9
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $6)
          (i64.const 3)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $9
    (i64.or
     (get_local $8)
     (get_local $9)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (block $label$12
   (block $label$13
    (block $label$14
     (br_if $label$14
      (i64.ne
       (get_local $7)
       (get_local $0)
      )
     )
     (call $require_recipient
      (get_local $9)
     )
     (set_local $6
      (i64.const 0)
     )
     (set_local $5
      (i64.const 59)
     )
     (set_local $4
      (i32.const 1152)
     )
     (set_local $7
      (i64.const 0)
     )
     (loop $label$15
      (block $label$16
       (block $label$17
        (block $label$18
         (block $label$19
          (block $label$20
           (br_if $label$20
            (i64.gt_u
             (get_local $6)
             (i64.const 3)
            )
           )
           (br_if $label$19
            (i32.gt_u
             (i32.and
              (i32.add
               (tee_local $3
                (i32.load8_s
                 (get_local $4)
                )
               )
               (i32.const -97)
              )
              (i32.const 255)
             )
             (i32.const 25)
            )
           )
           (set_local $3
            (i32.add
             (get_local $3)
             (i32.const 165)
            )
           )
           (br $label$18)
          )
          (set_local $8
           (i64.const 0)
          )
          (br_if $label$17
           (i64.le_u
            (get_local $6)
            (i64.const 11)
           )
          )
          (br $label$16)
         )
         (set_local $3
          (select
           (i32.add
            (get_local $3)
            (i32.const 208)
           )
           (i32.const 0)
           (i32.lt_u
            (i32.and
             (i32.add
              (get_local $3)
              (i32.const -49)
             )
             (i32.const 255)
            )
            (i32.const 5)
           )
          )
         )
        )
        (set_local $8
         (i64.shr_s
          (i64.shl
           (i64.extend_u/i32
            (get_local $3)
           )
           (i64.const 56)
          )
          (i64.const 56)
         )
        )
       )
       (set_local $8
        (i64.shl
         (i64.and
          (get_local $8)
          (i64.const 31)
         )
         (i64.and
          (get_local $5)
          (i64.const 4294967295)
         )
        )
       )
      )
      (set_local $4
       (i32.add
        (get_local $4)
        (i32.const 1)
       )
      )
      (set_local $6
       (i64.add
        (get_local $6)
        (i64.const 1)
       )
      )
      (set_local $7
       (i64.or
        (get_local $8)
        (get_local $7)
       )
      )
      (br_if $label$15
       (i64.ne
        (tee_local $5
         (i64.add
          (get_local $5)
          (i64.const -5)
         )
        )
        (i64.const -6)
       )
      )
     )
     (call $require_recipient
      (get_local $7)
     )
     (set_local $6
      (i64.const 0)
     )
     (set_local $5
      (i64.const 59)
     )
     (set_local $4
      (i32.const 1136)
     )
     (set_local $7
      (i64.const 0)
     )
     (loop $label$21
      (block $label$22
       (block $label$23
        (block $label$24
         (block $label$25
          (block $label$26
           (br_if $label$26
            (i64.gt_u
             (get_local $6)
             (i64.const 3)
            )
           )
           (br_if $label$25
            (i32.gt_u
             (i32.and
              (i32.add
               (tee_local $3
                (i32.load8_s
                 (get_local $4)
                )
               )
               (i32.const -97)
              )
              (i32.const 255)
             )
             (i32.const 25)
            )
           )
           (set_local $3
            (i32.add
             (get_local $3)
             (i32.const 165)
            )
           )
           (br $label$24)
          )
          (set_local $8
           (i64.const 0)
          )
          (br_if $label$23
           (i64.le_u
            (get_local $6)
            (i64.const 11)
           )
          )
          (br $label$22)
         )
         (set_local $3
          (select
           (i32.add
            (get_local $3)
            (i32.const 208)
           )
           (i32.const 0)
           (i32.lt_u
            (i32.and
             (i32.add
              (get_local $3)
              (i32.const -49)
             )
             (i32.const 255)
            )
            (i32.const 5)
           )
          )
         )
        )
        (set_local $8
         (i64.shr_s
          (i64.shl
           (i64.extend_u/i32
            (get_local $3)
           )
           (i64.const 56)
          )
          (i64.const 56)
         )
        )
       )
       (set_local $8
        (i64.shl
         (i64.and
          (get_local $8)
          (i64.const 31)
         )
         (i64.and
          (get_local $5)
          (i64.const 4294967295)
         )
        )
       )
      )
      (set_local $4
       (i32.add
        (get_local $4)
        (i32.const 1)
       )
      )
      (set_local $6
       (i64.add
        (get_local $6)
        (i64.const 1)
       )
      )
      (set_local $7
       (i64.or
        (get_local $8)
        (get_local $7)
       )
      )
      (br_if $label$21
       (i64.ne
        (tee_local $5
         (i64.add
          (get_local $5)
          (i64.const -5)
         )
        )
        (i64.const -6)
       )
      )
     )
     (set_local $6
      (i64.const 0)
     )
     (set_local $5
      (i64.const 59)
     )
     (set_local $4
      (i32.const 1152)
     )
     (set_local $9
      (i64.const 0)
     )
     (loop $label$27
      (block $label$28
       (block $label$29
        (block $label$30
         (block $label$31
          (block $label$32
           (br_if $label$32
            (i64.gt_u
             (get_local $6)
             (i64.const 3)
            )
           )
           (br_if $label$31
            (i32.gt_u
             (i32.and
              (i32.add
               (tee_local $3
                (i32.load8_s
                 (get_local $4)
                )
               )
               (i32.const -97)
              )
              (i32.const 255)
             )
             (i32.const 25)
            )
           )
           (set_local $3
            (i32.add
             (get_local $3)
             (i32.const 165)
            )
           )
           (br $label$30)
          )
          (set_local $8
           (i64.const 0)
          )
          (br_if $label$29
           (i64.le_u
            (get_local $6)
            (i64.const 11)
           )
          )
          (br $label$28)
         )
         (set_local $3
          (select
           (i32.add
            (get_local $3)
            (i32.const 208)
           )
           (i32.const 0)
           (i32.lt_u
            (i32.and
             (i32.add
              (get_local $3)
              (i32.const -49)
             )
             (i32.const 255)
            )
            (i32.const 5)
           )
          )
         )
        )
        (set_local $8
         (i64.shr_s
          (i64.shl
           (i64.extend_u/i32
            (get_local $3)
           )
           (i64.const 56)
          )
          (i64.const 56)
         )
        )
       )
       (set_local $8
        (i64.shl
         (i64.and
          (get_local $8)
          (i64.const 31)
         )
         (i64.and
          (get_local $5)
          (i64.const 4294967295)
         )
        )
       )
      )
      (set_local $4
       (i32.add
        (get_local $4)
        (i32.const 1)
       )
      )
      (set_local $6
       (i64.add
        (get_local $6)
        (i64.const 1)
       )
      )
      (set_local $9
       (i64.or
        (get_local $8)
        (get_local $9)
       )
      )
      (br_if $label$27
       (i64.ne
        (tee_local $5
         (i64.add
          (get_local $5)
          (i64.const -5)
         )
        )
        (i64.const -6)
       )
      )
     )
     (call $require_recipient
      (get_local $7)
     )
     (call $require_recipient
      (get_local $9)
     )
     (call $eosio_assert
      (i32.const 0)
      (i32.const 1168)
     )
     (br $label$13)
    )
    (br_if $label$12
     (i64.eq
      (get_local $9)
      (get_local $0)
     )
    )
    (set_local $6
     (i64.const 0)
    )
    (set_local $5
     (i64.const 59)
    )
    (set_local $4
     (i32.const 1152)
    )
    (set_local $7
     (i64.const 0)
    )
    (loop $label$33
     (block $label$34
      (block $label$35
       (block $label$36
        (block $label$37
         (block $label$38
          (br_if $label$38
           (i64.gt_u
            (get_local $6)
            (i64.const 3)
           )
          )
          (br_if $label$37
           (i32.gt_u
            (i32.and
             (i32.add
              (tee_local $3
               (i32.load8_s
                (get_local $4)
               )
              )
              (i32.const -97)
             )
             (i32.const 255)
            )
            (i32.const 25)
           )
          )
          (set_local $3
           (i32.add
            (get_local $3)
            (i32.const 165)
           )
          )
          (br $label$36)
         )
         (set_local $8
          (i64.const 0)
         )
         (br_if $label$35
          (i64.le_u
           (get_local $6)
           (i64.const 11)
          )
         )
         (br $label$34)
        )
        (set_local $3
         (select
          (i32.add
           (get_local $3)
           (i32.const 208)
          )
          (i32.const 0)
          (i32.lt_u
           (i32.and
            (i32.add
             (get_local $3)
             (i32.const -49)
            )
            (i32.const 255)
           )
           (i32.const 5)
          )
         )
        )
       )
       (set_local $8
        (i64.shr_s
         (i64.shl
          (i64.extend_u/i32
           (get_local $3)
          )
          (i64.const 56)
         )
         (i64.const 56)
        )
       )
      )
      (set_local $8
       (i64.shl
        (i64.and
         (get_local $8)
         (i64.const 31)
        )
        (i64.and
         (get_local $5)
         (i64.const 4294967295)
        )
       )
      )
     )
     (set_local $4
      (i32.add
       (get_local $4)
       (i32.const 1)
      )
     )
     (set_local $6
      (i64.add
       (get_local $6)
       (i64.const 1)
      )
     )
     (set_local $7
      (i64.or
       (get_local $8)
       (get_local $7)
      )
     )
     (br_if $label$33
      (i64.ne
       (tee_local $5
        (i64.add
         (get_local $5)
         (i64.const -5)
        )
       )
       (i64.const -6)
      )
     )
    )
    (br_if $label$12
     (i64.eq
      (get_local $7)
      (get_local $0)
     )
    )
   )
   (call $eosio_assert
    (i32.const 0)
    (i32.const 1168)
   )
  )
 )
 (func $_ZN11test_action12require_authEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (call $prints
   (i32.const 1200)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1216)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 3)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $require_auth
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1232)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 3)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $require_auth
   (get_local $4)
  )
 )
 (func $_ZN11test_action12assert_falseEv
  (call $eosio_assert
   (i32.const 0)
   (i32.const 1248)
  )
 )
 (func $_ZN11test_action11assert_trueEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1280)
  )
 )
 (func $_ZN11test_action14assert_true_cfEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1280)
  )
 )
 (func $_ZN11test_action10test_abortEv
  (call $abort)
  (unreachable)
 )
 (func $_ZN11test_action21test_publication_timeEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=12
   (get_local $0)
   (i32.const 0)
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 12)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=12
     (get_local $0)
    )
    (call $publication_time)
   )
   (i32.const 1312)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN11test_action21test_current_receiverEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $3
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $3)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=8
     (get_local $3)
    )
    (get_local $0)
   )
   (i32.const 1344)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $3)
    (i32.const 16)
   )
  )
 )
 (func $_ZN11test_action19test_current_senderEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i64.eq
    (call $current_sender)
    (i64.load offset=8
     (get_local $0)
    )
   )
   (i32.const 1392)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN11test_action3nowEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=12
   (get_local $0)
   (i32.const 0)
  )
  (call $eosio_assert
   (i32.eq
    (call $read_action_data
     (i32.add
      (get_local $0)
      (i32.const 12)
     )
     (i32.const 4)
    )
    (i32.const 4)
   )
   (i32.const 1440)
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=12
     (get_local $0)
    )
    (call $now)
   )
   (i32.const 1472)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN10test_print13test_prints_lEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store16 offset=14
   (get_local $0)
   (i32.const 25185)
  )
  (call $prints_l
   (i32.add
    (get_local $0)
    (i32.const 14)
   )
   (i32.const 2)
  )
  (call $prints_l
   (i32.add
    (get_local $0)
    (i32.const 14)
   )
   (i32.const 1)
  )
  (call $prints_l
   (i32.add
    (get_local $0)
    (i32.const 14)
   )
   (i32.const 0)
  )
  (call $prints_l
   (i32.const 864)
   (i32.const 4)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN10test_print11test_printsEv
  (call $prints
   (i32.const 1488)
  )
  (call $prints
   (i32.const 0)
  )
  (call $prints
   (i32.const 1504)
  )
  (call $prints
   (i32.const 0)
  )
  (call $prints
   (i32.const 1520)
  )
  (call $prints
   (i32.const 0)
  )
 )
 (func $_ZN10test_print11test_printiEv
  (call $printi
   (i64.const 0)
  )
  (call $printi
   (i64.const 556644)
  )
  (call $printi
   (i64.const -1)
  )
 )
 (func $_ZN10test_print12test_printuiEv
  (call $printui
   (i64.const 0)
  )
  (call $printui
   (i64.const 556644)
  )
  (call $printui
   (i64.const -1)
  )
 )
 (func $_ZN10test_print14test_printi128Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 48)
    )
   )
  )
  (i64.store offset=40
   (get_local $0)
   (i64.const -1)
  )
  (i64.store offset=32
   (get_local $0)
   (i64.const -1)
  )
  (i64.store offset=24
   (get_local $0)
   (i64.const 0)
  )
  (i64.store offset=16
   (get_local $0)
   (i64.const 0)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 87654323456)
  )
  (call $printi128
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
  (call $printi128
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
  (call $printi128
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 48)
   )
  )
 )
 (func $_ZN10test_print11test_printnEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1536)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 4)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1552)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 4)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1568)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$12
   (block $label$13
    (block $label$14
     (block $label$15
      (block $label$16
       (block $label$17
        (br_if $label$17
         (i64.gt_u
          (get_local $3)
          (i64.const 7)
         )
        )
        (br_if $label$16
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$15)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$14
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$13)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$12
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (call $printn
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1584)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$18
   (block $label$19
    (block $label$20
     (block $label$21
      (block $label$22
       (block $label$23
        (br_if $label$23
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$22
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$21)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$20
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$19)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$18
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1600)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$24
   (block $label$25
    (block $label$26
     (block $label$27
      (block $label$28
       (block $label$29
        (br_if $label$29
         (i64.gt_u
          (get_local $3)
          (i64.const 10)
         )
        )
        (br_if $label$28
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$27)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$26
        (i64.eq
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$25)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $2
    (i64.add
     (get_local $2)
     (i64.const -5)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$24
    (i64.ne
     (tee_local $3
      (i64.add
       (get_local $3)
       (i64.const 1)
      )
     )
     (i64.const 13)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1616)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$30
   (set_local $2
    (i64.const 0)
   )
   (block $label$31
    (br_if $label$31
     (i64.gt_u
      (get_local $3)
      (i64.const 11)
     )
    )
    (block $label$32
     (block $label$33
      (br_if $label$33
       (i32.gt_u
        (i32.and
         (i32.add
          (tee_local $0
           (i32.load8_s
            (get_local $1)
           )
          )
          (i32.const -97)
         )
         (i32.const 255)
        )
        (i32.const 25)
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 165)
       )
      )
      (br $label$32)
     )
     (set_local $0
      (select
       (i32.add
        (get_local $0)
        (i32.const 208)
       )
       (i32.const 0)
       (i32.lt_u
        (i32.and
         (i32.add
          (get_local $0)
          (i32.const -49)
         )
         (i32.const 255)
        )
        (i32.const 5)
       )
      )
     )
    )
    (set_local $2
     (i64.shl
      (i64.extend_u/i32
       (i32.and
        (get_local $0)
        (i32.const 31)
       )
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $2)
     (get_local $4)
    )
   )
   (br_if $label$30
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1632)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$34
   (set_local $5
    (i64.const 0)
   )
   (block $label$35
    (block $label$36
     (br_if $label$36
      (i64.gt_u
       (get_local $3)
       (i64.const 12)
      )
     )
     (block $label$37
      (block $label$38
       (br_if $label$38
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $1)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$37)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$36
      (i64.gt_u
       (get_local $3)
       (i64.const 11)
      )
     )
     (set_local $5
      (i64.shl
       (i64.and
        (get_local $5)
        (i64.const 31)
       )
       (i64.and
        (get_local $2)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$35)
    )
    (set_local $5
     (i64.and
      (get_local $5)
      (i64.const 15)
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$34
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1648)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$39
   (set_local $5
    (i64.const 0)
   )
   (block $label$40
    (block $label$41
     (br_if $label$41
      (i64.gt_u
       (get_local $3)
       (i64.const 13)
      )
     )
     (block $label$42
      (block $label$43
       (br_if $label$43
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $1)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$42)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$41
      (i64.gt_u
       (get_local $3)
       (i64.const 11)
      )
     )
     (set_local $5
      (i64.shl
       (i64.and
        (get_local $5)
        (i64.const 31)
       )
       (i64.and
        (get_local $2)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$40)
    )
    (set_local $5
     (i64.and
      (get_local $5)
      (i64.const 15)
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$39
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 1664)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$44
   (set_local $5
    (i64.const 0)
   )
   (block $label$45
    (block $label$46
     (br_if $label$46
      (i64.gt_u
       (get_local $3)
       (i64.const 14)
      )
     )
     (block $label$47
      (block $label$48
       (br_if $label$48
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $1)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$47)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$46
      (i64.gt_u
       (get_local $3)
       (i64.const 11)
      )
     )
     (set_local $5
      (i64.shl
       (i64.and
        (get_local $5)
        (i64.const 31)
       )
       (i64.and
        (get_local $2)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$45)
    )
    (set_local $5
     (i64.and
      (get_local $5)
      (i64.const 15)
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$44
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $printn
   (get_local $4)
  )
 )
 (func $_ZN10test_types10types_sizeEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1680)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1744)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1776)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1808)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1840)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1872)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1904)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1936)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1968)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2000)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2016)
  )
 )
 (func $_ZN10test_types14char_to_symbolEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2048)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2096)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2144)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2192)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2240)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2288)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2336)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2384)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2432)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2480)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2528)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2576)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2624)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2672)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2720)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2768)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2816)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2864)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2912)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 2960)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3008)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3056)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3104)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3152)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3200)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3248)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3296)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3344)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3392)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3440)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 3488)
  )
 )
 (func $_ZN10test_types14string_to_nameEv
  (local $0 i32)
  (local $1 i64)
  (local $2 i64)
  (local $3 i64)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3536)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i64.eq
        (get_local $1)
        (i64.const 0)
       )
      )
      (set_local $6
       (i64.const 0)
      )
      (br_if $label$2
       (i64.le_u
        (get_local $1)
        (i64.const 11)
       )
      )
      (br $label$1)
     )
     (block $label$4
      (block $label$5
       (br_if $label$5
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$4)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3536)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (br_if $label$9
       (i64.eq
        (get_local $1)
        (i64.const 0)
       )
      )
      (set_local $6
       (i64.const 0)
      )
      (br_if $label$8
       (i64.le_u
        (get_local $1)
        (i64.const 11)
       )
      )
      (br $label$7)
     )
     (block $label$10
      (block $label$11
       (br_if $label$11
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$10)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3552)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3584)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$12
   (block $label$13
    (block $label$14
     (block $label$15
      (block $label$16
       (block $label$17
        (br_if $label$17
         (i64.gt_u
          (get_local $1)
          (i64.const 1)
         )
        )
        (br_if $label$16
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$15)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$14
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$13)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$12
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3584)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$18
   (block $label$19
    (block $label$20
     (block $label$21
      (block $label$22
       (block $label$23
        (br_if $label$23
         (i64.gt_u
          (get_local $1)
          (i64.const 1)
         )
        )
        (br_if $label$22
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$21)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$20
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$19)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$18
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3600)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3632)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$24
   (block $label$25
    (block $label$26
     (block $label$27
      (block $label$28
       (block $label$29
        (br_if $label$29
         (i64.gt_u
          (get_local $1)
          (i64.const 2)
         )
        )
        (br_if $label$28
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$27)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$26
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$25)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$24
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3632)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$30
   (block $label$31
    (block $label$32
     (block $label$33
      (block $label$34
       (block $label$35
        (br_if $label$35
         (i64.gt_u
          (get_local $1)
          (i64.const 2)
         )
        )
        (br_if $label$34
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$33)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$32
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$31)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$30
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3648)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3680)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$36
   (block $label$37
    (block $label$38
     (block $label$39
      (block $label$40
       (block $label$41
        (br_if $label$41
         (i64.gt_u
          (get_local $1)
          (i64.const 3)
         )
        )
        (br_if $label$40
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$39)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$38
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$37)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$36
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3680)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$42
   (block $label$43
    (block $label$44
     (block $label$45
      (block $label$46
       (block $label$47
        (br_if $label$47
         (i64.gt_u
          (get_local $1)
          (i64.const 3)
         )
        )
        (br_if $label$46
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$45)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$44
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$43)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$42
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3696)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3728)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$48
   (block $label$49
    (block $label$50
     (block $label$51
      (block $label$52
       (block $label$53
        (br_if $label$53
         (i64.gt_u
          (get_local $1)
          (i64.const 4)
         )
        )
        (br_if $label$52
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$51)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$50
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$49)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$48
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3728)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$54
   (block $label$55
    (block $label$56
     (block $label$57
      (block $label$58
       (block $label$59
        (br_if $label$59
         (i64.gt_u
          (get_local $1)
          (i64.const 4)
         )
        )
        (br_if $label$58
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$57)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$56
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$55)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$54
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3744)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3776)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$60
   (block $label$61
    (block $label$62
     (block $label$63
      (block $label$64
       (block $label$65
        (br_if $label$65
         (i64.gt_u
          (get_local $1)
          (i64.const 5)
         )
        )
        (br_if $label$64
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$63)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$62
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$61)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$60
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3776)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$66
   (block $label$67
    (block $label$68
     (block $label$69
      (block $label$70
       (block $label$71
        (br_if $label$71
         (i64.gt_u
          (get_local $1)
          (i64.const 5)
         )
        )
        (br_if $label$70
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$69)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$68
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$67)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$66
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3792)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3824)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$72
   (block $label$73
    (block $label$74
     (block $label$75
      (block $label$76
       (block $label$77
        (br_if $label$77
         (i64.gt_u
          (get_local $1)
          (i64.const 6)
         )
        )
        (br_if $label$76
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$75)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$74
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$73)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$72
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3824)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$78
   (block $label$79
    (block $label$80
     (block $label$81
      (block $label$82
       (block $label$83
        (br_if $label$83
         (i64.gt_u
          (get_local $1)
          (i64.const 6)
         )
        )
        (br_if $label$82
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$81)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$80
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$79)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$78
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3840)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3872)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$84
   (block $label$85
    (block $label$86
     (block $label$87
      (block $label$88
       (block $label$89
        (br_if $label$89
         (i64.gt_u
          (get_local $1)
          (i64.const 7)
         )
        )
        (br_if $label$88
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$87)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$86
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$85)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$84
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3872)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$90
   (block $label$91
    (block $label$92
     (block $label$93
      (block $label$94
       (block $label$95
        (br_if $label$95
         (i64.gt_u
          (get_local $1)
          (i64.const 7)
         )
        )
        (br_if $label$94
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$93)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$92
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$91)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$90
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3888)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3920)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$96
   (block $label$97
    (block $label$98
     (block $label$99
      (block $label$100
       (block $label$101
        (br_if $label$101
         (i64.gt_u
          (get_local $1)
          (i64.const 8)
         )
        )
        (br_if $label$100
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$99)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$98
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$97)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$96
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3920)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$102
   (block $label$103
    (block $label$104
     (block $label$105
      (block $label$106
       (block $label$107
        (br_if $label$107
         (i64.gt_u
          (get_local $1)
          (i64.const 8)
         )
        )
        (br_if $label$106
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$105)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$104
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$103)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$102
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 3936)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3984)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$108
   (block $label$109
    (block $label$110
     (block $label$111
      (block $label$112
       (block $label$113
        (br_if $label$113
         (i64.gt_u
          (get_local $1)
          (i64.const 9)
         )
        )
        (br_if $label$112
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$111)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$110
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$109)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$108
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 3984)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$114
   (block $label$115
    (block $label$116
     (block $label$117
      (block $label$118
       (block $label$119
        (br_if $label$119
         (i64.gt_u
          (get_local $1)
          (i64.const 9)
         )
        )
        (br_if $label$118
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$117)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$116
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$115)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$114
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4000)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4048)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$120
   (block $label$121
    (block $label$122
     (block $label$123
      (block $label$124
       (block $label$125
        (br_if $label$125
         (i64.gt_u
          (get_local $1)
          (i64.const 10)
         )
        )
        (br_if $label$124
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$123)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$122
        (i64.eq
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$121)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $5
    (i64.add
     (get_local $5)
     (i64.const -5)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$120
    (i64.ne
     (tee_local $1
      (i64.add
       (get_local $1)
       (i64.const 1)
      )
     )
     (i64.const 13)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4048)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$126
   (block $label$127
    (block $label$128
     (block $label$129
      (block $label$130
       (block $label$131
        (br_if $label$131
         (i64.gt_u
          (get_local $1)
          (i64.const 10)
         )
        )
        (br_if $label$130
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$129)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$128
        (i64.eq
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$127)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $5
    (i64.add
     (get_local $5)
     (i64.const -5)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$126
    (i64.ne
     (tee_local $1
      (i64.add
       (get_local $1)
       (i64.const 1)
      )
     )
     (i64.const 13)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4064)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $6
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4112)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$132
   (set_local $5
    (i64.const 0)
   )
   (block $label$133
    (br_if $label$133
     (i64.gt_u
      (get_local $1)
      (i64.const 11)
     )
    )
    (block $label$134
     (block $label$135
      (br_if $label$135
       (i32.gt_u
        (i32.and
         (i32.add
          (tee_local $0
           (i32.load8_s
            (get_local $4)
           )
          )
          (i32.const -97)
         )
         (i32.const 255)
        )
        (i32.const 25)
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 165)
       )
      )
      (br $label$134)
     )
     (set_local $0
      (select
       (i32.add
        (get_local $0)
        (i32.const 208)
       )
       (i32.const 0)
       (i32.lt_u
        (i32.and
         (i32.add
          (get_local $0)
          (i32.const -49)
         )
         (i32.const 255)
        )
        (i32.const 5)
       )
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.extend_u/i32
       (i32.and
        (get_local $0)
        (i32.const 31)
       )
      )
      (i64.and
       (get_local $6)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $5)
     (get_local $2)
    )
   )
   (br_if $label$132
    (i64.ne
     (tee_local $6
      (i64.add
       (get_local $6)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $6
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4112)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$136
   (set_local $5
    (i64.const 0)
   )
   (block $label$137
    (br_if $label$137
     (i64.gt_u
      (get_local $1)
      (i64.const 11)
     )
    )
    (block $label$138
     (block $label$139
      (br_if $label$139
       (i32.gt_u
        (i32.and
         (i32.add
          (tee_local $0
           (i32.load8_s
            (get_local $4)
           )
          )
          (i32.const -97)
         )
         (i32.const 255)
        )
        (i32.const 25)
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 165)
       )
      )
      (br $label$138)
     )
     (set_local $0
      (select
       (i32.add
        (get_local $0)
        (i32.const 208)
       )
       (i32.const 0)
       (i32.lt_u
        (i32.and
         (i32.add
          (get_local $0)
          (i32.const -49)
         )
         (i32.const 255)
        )
        (i32.const 5)
       )
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.extend_u/i32
       (i32.and
        (get_local $0)
        (i32.const 31)
       )
      )
      (i64.and
       (get_local $6)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $5)
     (get_local $3)
    )
   )
   (br_if $label$136
    (i64.ne
     (tee_local $6
      (i64.add
       (get_local $6)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4128)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4176)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$140
   (set_local $6
    (i64.const 0)
   )
   (block $label$141
    (block $label$142
     (br_if $label$142
      (i64.gt_u
       (get_local $1)
       (i64.const 12)
      )
     )
     (block $label$143
      (block $label$144
       (br_if $label$144
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$143)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$142
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$141)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$140
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4176)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$145
   (set_local $6
    (i64.const 0)
   )
   (block $label$146
    (block $label$147
     (br_if $label$147
      (i64.gt_u
       (get_local $1)
       (i64.const 12)
      )
     )
     (block $label$148
      (block $label$149
       (br_if $label$149
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$148)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$147
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$146)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$145
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4192)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4240)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$150
   (set_local $6
    (i64.const 0)
   )
   (block $label$151
    (block $label$152
     (br_if $label$152
      (i64.gt_u
       (get_local $1)
       (i64.const 13)
      )
     )
     (block $label$153
      (block $label$154
       (br_if $label$154
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$153)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$152
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$151)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$150
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4256)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$155
   (set_local $6
    (i64.const 0)
   )
   (block $label$156
    (block $label$157
     (br_if $label$157
      (i64.gt_u
       (get_local $1)
       (i64.const 13)
      )
     )
     (block $label$158
      (block $label$159
       (br_if $label$159
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$158)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$157
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$156)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$155
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4272)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4320)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$160
   (set_local $6
    (i64.const 0)
   )
   (block $label$161
    (block $label$162
     (br_if $label$162
      (i64.gt_u
       (get_local $1)
       (i64.const 14)
      )
     )
     (block $label$163
      (block $label$164
       (br_if $label$164
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$163)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$162
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$161)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$160
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4336)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$165
   (set_local $6
    (i64.const 0)
   )
   (block $label$166
    (block $label$167
     (br_if $label$167
      (i64.gt_u
       (get_local $1)
       (i64.const 14)
      )
     )
     (block $label$168
      (block $label$169
       (br_if $label$169
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$168)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$167
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$166)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$165
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4352)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4400)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$170
   (block $label$171
    (block $label$172
     (block $label$173
      (block $label$174
       (block $label$175
        (br_if $label$175
         (i64.gt_u
          (get_local $1)
          (i64.const 5)
         )
        )
        (br_if $label$174
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$173)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$172
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$171)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$170
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4416)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$176
   (block $label$177
    (block $label$178
     (block $label$179
      (block $label$180
       (block $label$181
        (br_if $label$181
         (i64.gt_u
          (get_local $1)
          (i64.const 5)
         )
        )
        (br_if $label$180
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$179)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$178
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$177)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$176
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4432)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4464)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$182
   (block $label$183
    (block $label$184
     (block $label$185
      (block $label$186
       (block $label$187
        (br_if $label$187
         (i64.gt_u
          (get_local $1)
          (i64.const 9)
         )
        )
        (br_if $label$186
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$185)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$184
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$183)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$182
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4464)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$188
   (block $label$189
    (block $label$190
     (block $label$191
      (block $label$192
       (block $label$193
        (br_if $label$193
         (i64.gt_u
          (get_local $1)
          (i64.const 9)
         )
        )
        (br_if $label$192
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$191)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$190
        (i64.le_u
         (get_local $1)
         (i64.const 11)
        )
       )
       (br $label$189)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$188
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4480)
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4528)
  )
  (set_local $2
   (i64.const 0)
  )
  (loop $label$194
   (set_local $6
    (i64.const 0)
   )
   (block $label$195
    (block $label$196
     (br_if $label$196
      (i64.gt_u
       (get_local $1)
       (i64.const 14)
      )
     )
     (block $label$197
      (block $label$198
       (br_if $label$198
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$197)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$196
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$195)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $2
    (i64.or
     (get_local $6)
     (get_local $2)
    )
   )
   (br_if $label$194
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $1
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 4544)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$199
   (set_local $6
    (i64.const 0)
   )
   (block $label$200
    (block $label$201
     (br_if $label$201
      (i64.gt_u
       (get_local $1)
       (i64.const 22)
      )
     )
     (block $label$202
      (block $label$203
       (br_if $label$203
        (i32.gt_u
         (i32.and
          (i32.add
           (tee_local $0
            (i32.load8_s
             (get_local $4)
            )
           )
           (i32.const -97)
          )
          (i32.const 255)
         )
         (i32.const 25)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 165)
        )
       )
       (br $label$202)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
     (br_if $label$201
      (i64.gt_u
       (get_local $1)
       (i64.const 11)
      )
     )
     (set_local $6
      (i64.shl
       (i64.and
        (get_local $6)
        (i64.const 31)
       )
       (i64.and
        (get_local $5)
        (i64.const 4294967295)
       )
      )
     )
     (br $label$200)
    )
    (set_local $6
     (i64.and
      (get_local $6)
      (i64.const 15)
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $1
    (i64.add
     (get_local $1)
     (i64.const 1)
    )
   )
   (set_local $3
    (i64.or
     (get_local $6)
     (get_local $3)
    )
   )
   (br_if $label$199
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $2)
    (get_local $3)
   )
   (i32.const 4576)
  )
 )
 (func $_ZN10test_types10name_classEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4400)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $4)
    (i64.const 4017212585601400832)
   )
   (i32.const 4624)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 4656)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4688)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 3)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $4)
    (i64.const 580542139465728)
   )
   (i32.const 4704)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4736)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$12
   (block $label$13
    (block $label$14
     (block $label$15
      (block $label$16
       (block $label$17
        (br_if $label$17
         (i64.gt_u
          (get_local $3)
          (i64.const 1)
         )
        )
        (br_if $label$16
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$15)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$14
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$13)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$12
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $4)
    (i64.const 594475150812905472)
   )
   (i32.const 4752)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4784)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$18
   (block $label$19
    (block $label$20
     (block $label$21
      (block $label$22
       (block $label$23
        (br_if $label$23
         (i64.gt_u
          (get_local $3)
          (i64.const 1)
         )
        )
        (br_if $label$22
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$21)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$20
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$19)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$18
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $4)
    (i64.const 1188950301625810944)
   )
   (i32.const 4800)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4832)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$24
   (block $label$25
    (block $label$26
     (block $label$27
      (block $label$28
       (block $label$29
        (br_if $label$29
         (i64.gt_u
          (get_local $3)
          (i64.const 9)
         )
        )
        (br_if $label$28
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$27)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$26
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$25)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$24
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4832)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$30
   (block $label$31
    (block $label$32
     (block $label$33
      (block $label$34
       (block $label$35
        (br_if $label$35
         (i64.gt_u
          (get_local $3)
          (i64.const 9)
         )
        )
        (br_if $label$34
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$33)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$32
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$31)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$30
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $4)
    (get_local $6)
   )
   (i32.const 4848)
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4880)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$36
   (block $label$37
    (block $label$38
     (block $label$39
      (block $label$40
       (block $label$41
        (br_if $label$41
         (i64.gt_u
          (get_local $3)
          (i64.const 8)
         )
        )
        (br_if $label$40
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$39)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$38
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$37)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$36
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 4880)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$42
   (block $label$43
    (block $label$44
     (block $label$45
      (block $label$46
       (block $label$47
        (br_if $label$47
         (i64.gt_u
          (get_local $3)
          (i64.const 8)
         )
        )
        (br_if $label$46
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$45)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$44
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$43)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$42
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (get_local $6)
    (get_local $4)
   )
   (i32.const 4896)
  )
 )
 (func $_ZN15test_fixedpoint16create_instancesEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 4928)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5008)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5072)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5136)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5200)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5264)
  )
 )
 (func $_ZN15test_fixedpoint13test_additionEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5328)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5392)
  )
 )
 (func $_ZN15test_fixedpoint16test_subtractionEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5456)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5456)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5520)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5520)
  )
 )
 (func $_ZN15test_fixedpoint19test_multiplicationEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5584)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5648)
  )
 )
 (func $_ZN15test_fixedpoint13test_divisionEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (i64.store offset=24
   (get_local $0)
   (i64.const 0)
  )
  (i64.store offset=16
   (get_local $0)
   (i64.const 30030)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 128977867898880)
  )
  (call $printi128
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
  (call $prints
   (i32.const 5728)
  )
  (call $printi128
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5744)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 5744)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN15test_fixedpoint18test_division_by_0Ev
  (call $eosio_assert
   (i32.const 0)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 5712)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 5856)
  )
 )
 (func $_ZN9test_math11test_multeqEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 80)
    )
   )
  )
  (call $_ZN5eosio18unpack_action_dataI11u128_actionEET_v
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
  (i64.store offset=24
   (get_local $0)
   (i64.load
    (i32.add
     (get_local $0)
     (i32.const 40)
    )
   )
  )
  (i64.store offset=16
   (get_local $0)
   (i64.load offset=32
    (get_local $0)
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.load
    (i32.add
     (get_local $0)
     (i32.const 56)
    )
   )
  )
  (i64.store
   (get_local $0)
   (i64.load offset=48
    (get_local $0)
   )
  )
  (call $multeq_i128
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
   (get_local $0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load offset=16
       (get_local $0)
      )
      (i64.load offset=64
       (get_local $0)
      )
     )
     (i64.xor
      (i64.load offset=24
       (get_local $0)
      )
      (i64.load
       (i32.add
        (get_local $0)
        (i32.const 72)
       )
      )
     )
    )
   )
   (i32.const 5888)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 80)
   )
  )
 )
 (func $_ZN5eosio18unpack_action_dataI11u128_actionEET_v (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i64)
  (local $5 i32)
  (local $6 i32)
  (set_local $6
   (tee_local $3
    (i32.load offset=4
     (i32.const 0)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (tee_local $3
    (i32.sub
     (get_local $3)
     (i32.and
      (i32.add
       (tee_local $5
        (call $action_data_size)
       )
       (i32.const 15)
      )
      (i32.const -16)
     )
    )
   )
  )
  (drop
   (call $read_action_data
    (get_local $3)
    (get_local $5)
   )
  )
  (set_local $1
   (i32.add
    (get_local $3)
    (get_local $5)
   )
  )
  (set_local $5
   (i32.const 0)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $3)
     (get_local $1)
    )
    (i32.const 768)
   )
   (set_local $4
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (tee_local $2
         (i32.load8_u
          (get_local $3)
         )
        )
        (i32.const 127)
       )
       (tee_local $5
        (i32.and
         (get_local $5)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $4)
    )
   )
   (set_local $3
    (i32.add
     (get_local $3)
     (i32.const 1)
    )
   )
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $2)
     (i32.const 7)
    )
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.wrap/i64
     (get_local $4)
    )
    (i32.const 3)
   )
   (i32.const 5936)
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (get_local $1)
     (get_local $3)
    )
    (i32.const 47)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (get_local $3)
    (i32.const 48)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (get_local $6)
  )
 )
 (func $_ZN9test_math10test_diveqEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 80)
    )
   )
  )
  (call $_ZN5eosio18unpack_action_dataI11u128_actionEET_v
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
  (i64.store offset=24
   (get_local $0)
   (i64.load
    (i32.add
     (get_local $0)
     (i32.const 40)
    )
   )
  )
  (i64.store offset=16
   (get_local $0)
   (i64.load offset=32
    (get_local $0)
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.load
    (i32.add
     (get_local $0)
     (i32.const 56)
    )
   )
  )
  (i64.store
   (get_local $0)
   (i64.load offset=48
    (get_local $0)
   )
  )
  (call $diveq_i128
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
   (get_local $0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load offset=16
       (get_local $0)
      )
      (i64.load offset=64
       (get_local $0)
      )
     )
     (i64.xor
      (i64.load offset=24
       (get_local $0)
      )
      (i64.load
       (i32.add
        (get_local $0)
        (i32.const 72)
       )
      )
     )
    )
   )
   (i32.const 5984)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 80)
   )
  )
 )
 (func $_ZN9test_math15test_diveq_by_0Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (i64.store offset=24
   (get_local $0)
   (i64.const 0)
  )
  (i64.store offset=16
   (get_local $0)
   (i64.const 100)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $diveq_i128
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN9test_math18test_i64_to_doubleEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (drop
   (call $read_action_data
    (get_local $0)
    (i32.const 32)
   )
  )
  (call $eosio_assert
   (i64.eq
    (call $i64_to_double
     (i64.const 2)
    )
    (i64.load
     (get_local $0)
    )
   )
   (i32.const 6032)
  )
  (call $eosio_assert
   (i64.eq
    (call $i64_to_double
     (i64.const -2)
    )
    (i64.load offset=8
     (get_local $0)
    )
   )
   (i32.const 6064)
  )
  (call $eosio_assert
   (i64.eq
    (call $i64_to_double
     (i64.const 100000)
    )
    (i64.load offset=16
     (get_local $0)
    )
   )
   (i32.const 6096)
  )
  (call $eosio_assert
   (i64.eq
    (call $i64_to_double
     (i64.const -100000)
    )
    (i64.load offset=24
     (get_local $0)
    )
   )
   (i32.const 6128)
  )
  (call $eosio_assert
   (i64.eqz
    (call $i64_to_double
     (i64.const 0)
    )
   )
   (i32.const 6160)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN9test_math18test_double_to_i64Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (drop
   (call $read_action_data
    (get_local $0)
    (i32.const 32)
   )
  )
  (call $eosio_assert
   (i64.eq
    (call $double_to_i64
     (i64.load
      (get_local $0)
     )
    )
    (i64.const 2)
   )
   (i32.const 6192)
  )
  (call $eosio_assert
   (i64.eq
    (call $double_to_i64
     (i64.load offset=8
      (get_local $0)
     )
    )
    (i64.const -2)
   )
   (i32.const 6224)
  )
  (call $eosio_assert
   (i64.eq
    (call $double_to_i64
     (i64.load offset=16
      (get_local $0)
     )
    )
    (i64.const 100000)
   )
   (i32.const 6256)
  )
  (call $eosio_assert
   (i64.eq
    (call $double_to_i64
     (i64.load offset=24
      (get_local $0)
     )
    )
    (i64.const -100000)
   )
   (i32.const 6288)
  )
  (call $eosio_assert
   (i64.eqz
    (call $double_to_i64
     (i64.const 0)
    )
   )
   (i32.const 6320)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN9test_math15test_double_apiEv
  (call $eosio_assert
   (i64.eq
    (call $double_to_i64
     (call $double_mult
      (call $double_div
       (call $i64_to_double
        (i64.const 2)
       )
       (call $i64_to_double
        (i64.const 7)
       )
      )
      (call $double_add
       (call $i64_to_double
        (i64.const 3)
       )
       (call $i64_to_double
        (i64.const 2)
       )
      )
     )
    )
    (i64.const 1)
   )
   (i32.const 6352)
  )
  (call $eosio_assert
   (i32.eq
    (call $double_eq
     (call $double_div
      (call $i64_to_double
       (i64.const 5)
      )
      (call $i64_to_double
       (i64.const 9)
      )
     )
     (call $double_div
      (call $i64_to_double
       (i64.const 5)
      )
      (call $i64_to_double
       (i64.const 9)
      )
     )
    )
    (i32.const 1)
   )
   (i32.const 6368)
  )
  (call $eosio_assert
   (i32.eq
    (call $double_gt
     (call $double_div
      (call $i64_to_double
       (i64.const 9999999)
      )
      (call $i64_to_double
       (i64.const 7777777)
      )
     )
     (call $double_div
      (call $i64_to_double
       (i64.const 9999998)
      )
      (call $i64_to_double
       (i64.const 7777777)
      )
     )
    )
    (i32.const 1)
   )
   (i32.const 6384)
  )
  (call $eosio_assert
   (i32.eq
    (call $double_lt
     (call $double_div
      (call $i64_to_double
       (i64.const 9999998)
      )
      (call $i64_to_double
       (i64.const 7777777)
      )
     )
     (call $double_div
      (call $i64_to_double
       (i64.const 9999999)
      )
      (call $i64_to_double
       (i64.const 7777777)
      )
     )
    )
    (i32.const 1)
   )
   (i32.const 6400)
  )
 )
 (func $_ZN9test_math21test_double_api_div_0Ev
  (drop
   (call $double_div
    (call $i64_to_double
     (i64.const 1)
    )
    (call $double_add
     (call $i64_to_double
      (i64.const -5)
     )
     (call $i64_to_double
      (i64.const 5)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 5856)
  )
 )
 (func $_Zli5_ULLLPKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i64)
  (local $4 i64)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (tee_local $1
       (i32.load8_u
        (tee_local $6
         (i32.add
          (get_local $1)
          (select
           (select
            (i32.const 2)
            (i32.const 1)
            (tee_local $2
             (i32.eq
              (i32.load8_u
               (get_local $1)
              )
              (i32.const 45)
             )
            )
           )
           (get_local $2)
           (i32.eq
            (i32.load8_u
             (i32.add
              (get_local $1)
              (get_local $2)
             )
            )
            (i32.const 43)
           )
          )
         )
        )
       )
      )
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (set_local $5
     (i32.add
      (get_local $8)
      (i32.const 8)
     )
    )
    (set_local $7
     (i64.const 0)
    )
    (set_local $3
     (i64.const 0)
    )
    (loop $label$2
     (call $__multi3
      (get_local $8)
      (get_local $7)
      (get_local $3)
      (i64.const 10)
      (i64.const 0)
     )
     (set_local $3
      (i64.add
       (i64.add
        (i64.shr_s
         (tee_local $3
          (i64.extend_s/i32
           (i32.add
            (i32.shr_s
             (i32.shl
              (get_local $1)
              (i32.const 24)
             )
             (i32.const 24)
            )
            (i32.const -48)
           )
          )
         )
         (i64.const 63)
        )
        (i64.load
         (get_local $5)
        )
       )
       (select
        (i64.const 1)
        (i64.extend_u/i32
         (i64.lt_u
          (tee_local $7
           (i64.add
            (get_local $3)
            (tee_local $4
             (i64.load
              (get_local $8)
             )
            )
           )
          )
          (get_local $3)
         )
        )
        (i64.lt_u
         (get_local $7)
         (get_local $4)
        )
       )
      )
     )
     (set_local $1
      (i32.load8_u
       (get_local $6)
      )
     )
     (set_local $6
      (i32.add
       (get_local $6)
       (i32.const 1)
      )
     )
     (br_if $label$2
      (get_local $1)
     )
     (br $label$0)
    )
   )
   (set_local $7
    (i64.const 0)
   )
   (set_local $3
    (i64.const 0)
   )
  )
  (i64.store
   (get_local $0)
   (select
    (i64.sub
     (i64.const 0)
     (get_local $7)
    )
    (get_local $7)
    (get_local $2)
   )
  )
  (i64.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (select
    (i64.sub
     (i64.sub
      (i64.const 0)
      (get_local $3)
     )
     (i64.extend_u/i32
      (i64.ne
       (get_local $7)
       (i64.const 0)
      )
     )
    )
    (get_local $3)
    (get_local $2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
 )
 (func $_Zli4_LLLPKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i64)
  (local $4 i64)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (tee_local $1
       (i32.load8_u
        (tee_local $6
         (i32.add
          (get_local $1)
          (select
           (select
            (i32.const 2)
            (i32.const 1)
            (tee_local $2
             (i32.eq
              (i32.load8_u
               (get_local $1)
              )
              (i32.const 45)
             )
            )
           )
           (get_local $2)
           (i32.eq
            (i32.load8_u
             (i32.add
              (get_local $1)
              (get_local $2)
             )
            )
            (i32.const 43)
           )
          )
         )
        )
       )
      )
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (set_local $5
     (i32.add
      (get_local $8)
      (i32.const 8)
     )
    )
    (set_local $7
     (i64.const 0)
    )
    (set_local $3
     (i64.const 0)
    )
    (loop $label$2
     (call $__multi3
      (get_local $8)
      (get_local $7)
      (get_local $3)
      (i64.const 10)
      (i64.const 0)
     )
     (set_local $3
      (i64.add
       (i64.add
        (i64.shr_s
         (tee_local $3
          (i64.extend_s/i32
           (i32.add
            (i32.shr_s
             (i32.shl
              (get_local $1)
              (i32.const 24)
             )
             (i32.const 24)
            )
            (i32.const -48)
           )
          )
         )
         (i64.const 63)
        )
        (i64.load
         (get_local $5)
        )
       )
       (select
        (i64.const 1)
        (i64.extend_u/i32
         (i64.lt_u
          (tee_local $7
           (i64.add
            (get_local $3)
            (tee_local $4
             (i64.load
              (get_local $8)
             )
            )
           )
          )
          (get_local $3)
         )
        )
        (i64.lt_u
         (get_local $7)
         (get_local $4)
        )
       )
      )
     )
     (set_local $1
      (i32.load8_u
       (get_local $6)
      )
     )
     (set_local $6
      (i32.add
       (get_local $6)
       (i32.const 1)
      )
     )
     (br_if $label$2
      (get_local $1)
     )
     (br $label$0)
    )
   )
   (set_local $7
    (i64.const 0)
   )
   (set_local $3
    (i64.const 0)
   )
  )
  (i64.store
   (get_local $0)
   (select
    (i64.sub
     (i64.const 0)
     (get_local $7)
    )
    (get_local $7)
    (get_local $2)
   )
  )
  (i64.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (select
    (i64.sub
     (i64.sub
      (i64.const 0)
      (get_local $3)
     )
     (i64.extend_u/i32
      (i64.ne
       (get_local $7)
       (i64.const 0)
      )
     )
    )
    (get_local $3)
    (get_local $2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins11test_multi3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__multi3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -3000)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6416)
  )
  (call $__multi3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -3000)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6416)
  )
  (call $__multi3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 900)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6448)
  )
  (call $__multi3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 10000)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6480)
  )
  (call $__multi3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 100)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6512)
  )
  (call $__multi3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6544)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins11test_divti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__divti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6576)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -3)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6608)
  )
  (call $__divti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6640)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6640)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 3333)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6576)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 3333)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 33)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6672)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 1)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 100)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6704)
  )
  (call $__divti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 1)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6736)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins16test_divti3_by_0Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__divti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 0)
   (i64.const 0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 6768)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_udivti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2951479051793528258)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const 184467440737095516)
     )
    )
   )
   (i32.const 6800)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6800)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const -30)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6832)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6640)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 3333)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6576)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 3333)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 33)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6672)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 1)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 100)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6704)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 1)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 6736)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins17test_udivti3_by_0Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__udivti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 0)
   (i64.const 0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 6768)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_lshlti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6864)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6896)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 31)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2147483648)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6928)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 63)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 6960)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 64)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const 1)
     )
    )
   )
   (i32.const 6992)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 127)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
    )
   )
   (i32.const 7024)
  )
  (call $__lshlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 128)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7072)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_ashlti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7120)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7152)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 31)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2147483648)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7184)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 63)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7216)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 64)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const 1)
     )
    )
   )
   (i32.const 7248)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 127)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
    )
   )
   (i32.const 7280)
  )
  (call $__ashlti3
   (get_local $0)
   (i64.const 1)
   (i64.const 0)
   (i32.const 128)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7328)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_lshrti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
    )
   )
   (i32.const 7376)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const 4611686018427387904)
     )
    )
   )
   (i32.const 7424)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 63)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const 1)
     )
    )
   )
   (i32.const 7472)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 64)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7504)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 96)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 2147483648)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7536)
  )
  (call $__lshrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 127)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 1)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7568)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_ashrti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
    )
   )
   (i32.const 7600)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -4611686018427387904)
     )
    )
   )
   (i32.const 7648)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 2)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -2305843009213693952)
     )
    )
   )
   (i32.const 7696)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 64)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -9223372036854775808)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7744)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 95)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -4294967296)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7792)
  )
  (call $__ashrti3
   (get_local $0)
   (i64.const 0)
   (i64.const -9223372036854775808)
   (i32.const 127)
  )
  (call $eosio_assert
   (i64.eq
    (i64.and
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
    (i64.const -1)
   )
   (i32.const 7840)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins11test_modti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__modti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7872)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 30)
   (i64.const 0)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 30)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7904)
  )
  (call $__modti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7872)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 30)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 10)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7936)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 0)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins16test_modti3_by_0Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__modti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 0)
   (i64.const 0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 8000)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins12test_umodti3Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7872)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 30)
   (i64.const 0)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 30)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7904)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const -30)
   (i64.const -1)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const -30)
     )
     (i64.xor
      (i64.load offset=8
       (get_local $0)
      )
      (i64.const -1)
     )
    )
   )
   (i32.const 7872)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 30)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.xor
      (i64.load
       (get_local $0)
      )
      (i64.const 10)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7936)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const -100)
   (i64.const -1)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 0)
   (i64.const 0)
   (i64.const 100)
   (i64.const 0)
  )
  (call $eosio_assert
   (i64.eqz
    (i64.or
     (i64.load
      (get_local $0)
     )
     (i64.load offset=8
      (get_local $0)
     )
    )
   )
   (i32.const 7968)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN22test_compiler_builtins17test_umodti3_by_0Ev
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 0)
  )
  (call $__umodti3
   (get_local $0)
   (i64.const 100)
   (i64.const 0)
   (i64.const 0)
   (i64.const 0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 8000)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZNK5eosio4realplERKS0_ (param $0 i32) (param $1 i32) (result i64)
  (call $double_add
   (i64.load
    (get_local $0)
   )
   (i64.load
    (get_local $1)
   )
  )
 )
 (func $_ZNK5eosio4realmlERKS0_ (param $0 i32) (param $1 i32) (result i64)
  (call $double_mult
   (i64.load
    (get_local $0)
   )
   (i64.load
    (get_local $1)
   )
  )
 )
 (func $_ZNK5eosio4realdvERKS0_ (param $0 i32) (param $1 i32) (result i64)
  (call $double_div
   (call $i64_to_double
    (i64.load
     (get_local $0)
    )
   )
   (call $i64_to_double
    (i64.load
     (get_local $1)
    )
   )
  )
 )
 (func $_ZN5eosioeqERKNS_4realES2_ (param $0 i32) (param $1 i32) (result i32)
  (i32.eq
   (call $double_eq
    (i64.load
     (get_local $0)
    )
    (i64.load
     (get_local $1)
    )
   )
   (i32.const 1)
  )
 )
 (func $_ZN5eosiogtERKNS_4realES2_ (param $0 i32) (param $1 i32) (result i32)
  (i32.eq
   (call $double_gt
    (i64.load
     (get_local $0)
    )
    (i64.load
     (get_local $1)
    )
   )
   (i32.const 1)
  )
 )
 (func $_ZN5eosioltERKNS_4realES2_ (param $0 i32) (param $1 i32) (result i32)
  (i32.eq
   (call $double_lt
    (i64.load
     (get_local $0)
    )
    (i64.load
     (get_local $1)
    )
   )
   (i32.const 1)
  )
 )
 (func $_ZN9test_real16create_instancesEv
  (call $eosio_assert
   (i32.const 1)
   (i32.const 8032)
  )
 )
 (func $_ZN9test_real13test_divisionEv
  (call $eosio_assert
   (i64.eq
    (call $double_div
     (call $i64_to_double
      (i64.const 5)
     )
     (call $i64_to_double
      (i64.const 10)
     )
    )
    (call $double_div
     (call $i64_to_double
      (i64.const 5)
     )
     (call $i64_to_double
      (i64.const 10)
     )
    )
   )
   (i32.const 8064)
  )
 )
 (func $_ZN9test_real18test_division_by_0Ev
  (drop
   (call $double_div
    (call $i64_to_double
     (i64.const 5)
    )
    (call $i64_to_double
     (i64.const 0)
    )
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 5856)
  )
 )
 (func $_ZN9test_real19test_multiplicationEv
  (call $eosio_assert
   (i64.eq
    (call $double_mult
     (i64.const 5)
     (i64.const 10)
    )
    (call $double_mult
     (i64.const 5)
     (i64.const 10)
    )
   )
   (i32.const 8096)
  )
 )
 (func $_ZN9test_real13test_additionEv
  (local $0 i64)
  (local $1 i64)
  (local $2 i64)
  (local $3 i64)
  (set_local $0
   (call $double_div
    (call $i64_to_double
     (i64.const 5)
    )
    (call $i64_to_double
     (i64.const 10)
    )
   )
  )
  (set_local $1
   (call $double_div
    (call $i64_to_double
     (i64.const 5)
    )
    (call $i64_to_double
     (i64.const 10)
    )
   )
  )
  (set_local $2
   (call $double_div
    (call $i64_to_double
     (i64.const 5)
    )
    (call $i64_to_double
     (i64.const 2)
    )
   )
  )
  (set_local $3
   (call $double_div
    (call $i64_to_double
     (i64.const 5)
    )
    (call $i64_to_double
     (i64.const 2)
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (call $double_add
     (get_local $0)
     (get_local $2)
    )
    (call $double_add
     (get_local $1)
     (get_local $3)
    )
   )
   (i32.const 8144)
  )
 )
 (func $my_strlen (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (set_local $3
   (i32.const -1)
  )
  (loop $label$0
   (set_local $2
    (i32.add
     (get_local $0)
     (get_local $3)
    )
   )
   (set_local $3
    (tee_local $1
     (i32.add
      (get_local $3)
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (i32.load8_u
     (i32.add
      (get_local $2)
      (i32.const 1)
     )
    )
   )
  )
  (get_local $1)
 )
 (func $my_memcmp (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (get_local $2)
     )
    )
    (set_local $3
     (i32.const 0)
    )
    (loop $label$2
     (br_if $label$0
      (i32.ne
       (i32.load8_u
        (i32.add
         (get_local $0)
         (get_local $3)
        )
       )
       (i32.load8_u
        (i32.add
         (get_local $1)
         (get_local $3)
        )
       )
      )
     )
     (br_if $label$2
      (i32.lt_u
       (tee_local $3
        (i32.add
         (get_local $3)
         (i32.const 1)
        )
       )
       (get_local $2)
      )
     )
    )
    (return
     (i32.const 1)
    )
   )
   (return
    (i32.const 1)
   )
  )
  (i32.const 0)
 )
 (func $_ZN11test_crypto28test_recover_key_assert_trueEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 144)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (i32.const 132)
   )
  )
  (call $assert_recover_key
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (i32.add
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (i32.const 66)
   )
   (i32.const 66)
   (i32.add
    (get_local $0)
    (i32.const 40)
   )
   (i32.const 34)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 144)
   )
  )
 )
 (func $_ZN11test_crypto29test_recover_key_assert_falseEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 144)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (i32.const 132)
   )
  )
  (call $assert_recover_key
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (i32.add
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (i32.const 66)
   )
   (i32.const 66)
   (i32.add
    (get_local $0)
    (i32.const 40)
   )
   (i32.const 34)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 8000)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 144)
   )
  )
 )
 (func $_ZN11test_crypto16test_recover_keyEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 176)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $2)
     (i32.const 40)
    )
    (i32.const 132)
   )
  )
  (drop
   (call $recover_key
    (i32.add
     (get_local $2)
     (i32.const 40)
    )
    (i32.add
     (i32.add
      (get_local $2)
      (i32.const 40)
     )
     (i32.const 66)
    )
    (i32.const 66)
    (get_local $2)
    (i32.const 34)
   )
  )
  (set_local $0
   (i32.add
    (get_local $2)
    (i32.const 72)
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (loop $label$0
   (block $label$1
    (br_if $label$1
     (i32.eq
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $1)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $0)
        (get_local $1)
       )
      )
     )
    )
    (call $eosio_assert
     (i32.const 0)
     (i32.const 8192)
    )
   )
   (br_if $label$0
    (i32.ne
     (tee_local $1
      (i32.add
       (get_local $1)
       (i32.const 1)
      )
     )
     (i32.const 34)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 176)
   )
  )
 )
 (func $_ZN11test_crypto9test_sha1Ev
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha1
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 169)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 153)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 62)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 54)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 71)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 6)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 129)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 106)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 186)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 62)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 37)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 113)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 120)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 80)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 194)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 108)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 156)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 208)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 216)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 157)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 8240)
  )
  (call $sha1
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 132)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 152)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 62)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 68)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 28)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 59)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 210)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 110)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 186)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 174)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 74)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 161)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 249)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 81)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 41)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 229)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 229)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 70)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 112)
    )
   )
   (set_local $1
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 241)
    )
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8320)
  )
  (call $sha1
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$2
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 164)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 155)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 36)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 70)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 160)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 44)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 100)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 91)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 244)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 25)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 249)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 149)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 182)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 112)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 145)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 37)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 58)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 4)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 162)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 89)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 8464)
  )
  (call $sha1
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 193)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 34)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 82)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 206)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 218)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 139)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 232)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 153)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 77)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 95)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 160)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 41)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 10)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 71)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 35)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 28)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 29)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 22)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 170)
    )
   )
   (set_local $1
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 227)
    )
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8496)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto11test_sha256Ev
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha256
   (i32.const 8224)
   (i32.const 3)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (br_if $label$0
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8512)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$1
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 31)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8544)
  )
  (call $sha256
   (i32.const 8256)
   (i32.const 56)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$2
   (loop $label$3
    (br_if $label$2
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8560)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$3
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 31)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8592)
  )
  (call $sha256
   (i32.const 8336)
   (i32.const 112)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$4
   (loop $label$5
    (br_if $label$4
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8608)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$5
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 31)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8640)
  )
  (call $sha256
   (i32.const 8480)
   (i32.const 14)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$6
   (loop $label$7
    (br_if $label$6
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8656)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$7
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 31)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8688)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto11test_sha512Ev
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 64)
    )
   )
  )
  (call $sha512
   (i32.const 8224)
   (i32.const 3)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (br_if $label$0
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8704)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$1
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 63)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8768)
  )
  (call $sha512
   (i32.const 8256)
   (i32.const 56)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$2
   (loop $label$3
    (br_if $label$2
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8784)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$3
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 63)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8848)
  )
  (call $sha512
   (i32.const 8336)
   (i32.const 112)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$4
   (loop $label$5
    (br_if $label$4
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8864)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$5
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 63)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 8928)
  )
  (call $sha512
   (i32.const 8480)
   (i32.const 14)
   (get_local $2)
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$6
   (loop $label$7
    (br_if $label$6
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 8944)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$7
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 63)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 9008)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 64)
   )
  )
 )
 (func $_ZN11test_crypto14test_ripemd160Ev
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $ripemd160
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 142)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 178)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 8)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 247)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 224)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 93)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 152)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 122)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 155)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 4)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 74)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 142)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 152)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 198)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 176)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 135)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 241)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 90)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 11)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 252)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 9024)
  )
  (call $ripemd160
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 18)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 160)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 83)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 56)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 74)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 156)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 12)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 136)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 228)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 5)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 160)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 108)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 39)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 220)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 244)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 154)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 218)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 98)
    )
   )
   (br_if $label$1
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 235)
    )
   )
   (set_local $1
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 43)
    )
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 9040)
  )
  (call $ripemd160
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$2
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 111)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 63)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 163)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 155)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 107)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 80)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 60)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 56)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 79)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 145)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 154)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 73)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 167)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 170)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 92)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 44)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 8)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 189)
    )
   )
   (set_local $0
    (i32.const 0)
   )
   (br_if $label$2
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 251)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 69)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 9056)
  )
  (call $ripemd160
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $2)
    (i32.const 8)
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=8
      (get_local $2)
     )
     (i32.const 93)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=9
      (get_local $2)
     )
     (i32.const 6)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=10
      (get_local $2)
     )
     (i32.const 137)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=11
      (get_local $2)
     )
     (i32.const 239)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=12
      (get_local $2)
     )
     (i32.const 73)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=13
      (get_local $2)
     )
     (i32.const 210)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=14
      (get_local $2)
     )
     (i32.const 250)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=15
      (get_local $2)
     )
     (i32.const 229)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=16
      (get_local $2)
     )
     (i32.const 114)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=17
      (get_local $2)
     )
     (i32.const 184)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=18
      (get_local $2)
     )
     (i32.const 129)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=19
      (get_local $2)
     )
     (i32.const 177)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=20
      (get_local $2)
     )
     (i32.const 35)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=21
      (get_local $2)
     )
     (i32.const 168)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=22
      (get_local $2)
     )
     (i32.const 95)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=23
      (get_local $2)
     )
     (i32.const 250)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=24
      (get_local $2)
     )
     (i32.const 33)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=25
      (get_local $2)
     )
     (i32.const 89)
    )
   )
   (br_if $label$3
    (i32.ne
     (i32.load8_u offset=26
      (get_local $2)
     )
     (i32.const 95)
    )
   )
   (set_local $1
    (i32.eq
     (i32.load8_u offset=27
      (get_local $2)
     )
     (i32.const 54)
    )
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 9072)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto11sha256_nullEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha256
   (i32.const 0)
   (i32.const 100)
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto12sha1_no_dataEv
  (local $0 i32)
  (local $1 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $1
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (set_local $0
   (i32.const 0)
  )
  (call $sha1
   (i32.const 9088)
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=8
      (get_local $1)
     )
     (i32.const 218)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=9
      (get_local $1)
     )
     (i32.const 57)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=10
      (get_local $1)
     )
     (i32.const 163)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=11
      (get_local $1)
     )
     (i32.const 238)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=12
      (get_local $1)
     )
     (i32.const 94)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=13
      (get_local $1)
     )
     (i32.const 107)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=14
      (get_local $1)
     )
     (i32.const 75)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=15
      (get_local $1)
     )
     (i32.const 13)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=16
      (get_local $1)
     )
     (i32.const 50)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=17
      (get_local $1)
     )
     (i32.const 85)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=18
      (get_local $1)
     )
     (i32.const 191)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=19
      (get_local $1)
     )
     (i32.const 239)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=20
      (get_local $1)
     )
     (i32.const 149)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=21
      (get_local $1)
     )
     (i32.const 96)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=22
      (get_local $1)
     )
     (i32.const 24)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=23
      (get_local $1)
     )
     (i32.const 144)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=24
      (get_local $1)
     )
     (i32.const 175)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=25
      (get_local $1)
     )
     (i32.const 216)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=26
      (get_local $1)
     )
     (i32.const 7)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $1)
     )
     (i32.const 9)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 9104)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto14sha256_no_dataEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (call $sha256
   (i32.const 9088)
   (i32.const 0)
   (get_local $2)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (br_if $label$0
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 9120)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$1
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 31)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 9152)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto14sha512_no_dataEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 64)
    )
   )
  )
  (set_local $1
   (i32.const 0)
  )
  (call $sha512
   (i32.const 9088)
   (i32.const 0)
   (get_local $2)
  )
  (set_local $0
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (br_if $label$0
     (i32.ne
      (i32.load8_u
       (i32.add
        (get_local $0)
        (i32.const 9168)
       )
      )
      (i32.load8_u
       (i32.add
        (get_local $2)
        (get_local $0)
       )
      )
     )
    )
    (br_if $label$1
     (i32.le_u
      (tee_local $0
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (i32.const 63)
     )
    )
   )
   (set_local $1
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $1)
   (i32.const 9232)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 64)
   )
  )
 )
 (func $_ZN11test_crypto17ripemd160_no_dataEv
  (local $0 i32)
  (local $1 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $1
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (set_local $0
   (i32.const 0)
  )
  (call $ripemd160
   (i32.const 9088)
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=8
      (get_local $1)
     )
     (i32.const 156)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=9
      (get_local $1)
     )
     (i32.const 17)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=10
      (get_local $1)
     )
     (i32.const 133)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=11
      (get_local $1)
     )
     (i32.const 165)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=12
      (get_local $1)
     )
     (i32.const 197)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=13
      (get_local $1)
     )
     (i32.const 233)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=14
      (get_local $1)
     )
     (i32.const 252)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=15
      (get_local $1)
     )
     (i32.const 84)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=16
      (get_local $1)
     )
     (i32.const 97)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=17
      (get_local $1)
     )
     (i32.const 40)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=18
      (get_local $1)
     )
     (i32.const 8)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=19
      (get_local $1)
     )
     (i32.const 151)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=20
      (get_local $1)
     )
     (i32.const 126)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=21
      (get_local $1)
     )
     (i32.const 232)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=22
      (get_local $1)
     )
     (i32.const 245)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=23
      (get_local $1)
     )
     (i32.const 72)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=24
      (get_local $1)
     )
     (i32.const 178)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=25
      (get_local $1)
     )
     (i32.const 37)
    )
   )
   (br_if $label$0
    (i32.ne
     (i32.load8_u offset=26
      (get_local $1)
     )
     (i32.const 141)
    )
   )
   (set_local $0
    (i32.eq
     (i32.load8_u offset=27
      (get_local $1)
     )
     (i32.const 49)
    )
   )
  )
  (call $eosio_assert
   (get_local $0)
   (i32.const 9248)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto19assert_sha256_falseEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha256
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (i32.store8
   (get_local $0)
   (i32.xor
    (i32.load8_u
     (get_local $0)
    )
    (i32.const -1)
   )
  )
  (call $assert_sha256
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 9264)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto18assert_sha256_trueEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha256
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $assert_sha256
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $sha256
   (i32.const 8256)
   (i32.const 56)
   (get_local $0)
  )
  (call $assert_sha256
   (i32.const 8256)
   (i32.const 56)
   (get_local $0)
  )
  (call $sha256
   (i32.const 8336)
   (i32.const 112)
   (get_local $0)
  )
  (call $assert_sha256
   (i32.const 8336)
   (i32.const 112)
   (get_local $0)
  )
  (call $sha256
   (i32.const 8480)
   (i32.const 14)
   (get_local $0)
  )
  (call $assert_sha256
   (i32.const 8480)
   (i32.const 14)
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto17assert_sha1_falseEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha1
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store8 offset=8
   (get_local $0)
   (i32.xor
    (i32.load8_u offset=8
     (get_local $0)
    )
    (i32.const -1)
   )
  )
  (call $assert_sha1
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 9264)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto16assert_sha1_trueEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $sha1
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_sha1
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $sha1
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_sha1
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $sha1
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_sha1
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $sha1
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_sha1
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto19assert_sha512_falseEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 64)
    )
   )
  )
  (call $sha512
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (i32.store8
   (get_local $0)
   (i32.xor
    (i32.load8_u
     (get_local $0)
    )
    (i32.const -1)
   )
  )
  (call $assert_sha512
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 9264)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 64)
   )
  )
 )
 (func $_ZN11test_crypto18assert_sha512_trueEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 64)
    )
   )
  )
  (call $sha512
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $assert_sha512
   (i32.const 8224)
   (i32.const 3)
   (get_local $0)
  )
  (call $sha512
   (i32.const 8256)
   (i32.const 56)
   (get_local $0)
  )
  (call $assert_sha512
   (i32.const 8256)
   (i32.const 56)
   (get_local $0)
  )
  (call $sha512
   (i32.const 8336)
   (i32.const 112)
   (get_local $0)
  )
  (call $assert_sha512
   (i32.const 8336)
   (i32.const 112)
   (get_local $0)
  )
  (call $sha512
   (i32.const 8480)
   (i32.const 14)
   (get_local $0)
  )
  (call $assert_sha512
   (i32.const 8480)
   (i32.const 14)
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 64)
   )
  )
 )
 (func $_ZN11test_crypto22assert_ripemd160_falseEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $ripemd160
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store8 offset=8
   (get_local $0)
   (i32.xor
    (i32.load8_u offset=8
     (get_local $0)
    )
    (i32.const -1)
   )
  )
  (call $assert_ripemd160
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 9264)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN11test_crypto21assert_ripemd160_trueEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $ripemd160
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_ripemd160
   (i32.const 8224)
   (i32.const 3)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $ripemd160
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_ripemd160
   (i32.const 8256)
   (i32.const 56)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $ripemd160
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_ripemd160
   (i32.const 8336)
   (i32.const 112)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $ripemd160
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (call $assert_ripemd160
   (i32.const 8480)
   (i32.const 14)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
  )
 )
 (func $_ZN10test_chain16test_activeprodsEv
  (local $0 i32)
  (local $1 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $1
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 352)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $1)
     (i32.const 176)
    )
    (i32.const 169)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load8_u offset=176
     (get_local $1)
    )
    (i32.const 21)
   )
   (i32.const 9296)
  )
  (set_local $0
   (i32.const 1)
  )
  (drop
   (call $get_active_producers
    (i32.or
     (get_local $1)
     (i32.const 1)
    )
    (i32.const 168)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i64.eq
     (i64.load align=1
      (i32.add
       (get_local $1)
       (get_local $0)
      )
     )
     (i64.load align=1
      (i32.add
       (i32.add
        (get_local $1)
        (i32.const 176)
       )
       (get_local $0)
      )
     )
    )
    (i32.const 9328)
   )
   (br_if $label$0
    (i32.ne
     (tee_local $0
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
     )
     (i32.const 169)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 352)
   )
  )
 )
 (func $_Z9copy_dataPcjRNSt3__16vectorIcNS0_9allocatorIcEEEE (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (get_local $1)
    )
   )
   (set_local $4
    (i32.add
     (get_local $2)
     (i32.const 8)
    )
   )
   (set_local $5
    (i32.add
     (get_local $2)
     (i32.const 4)
    )
   )
   (loop $label$1
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.eq
        (tee_local $3
         (i32.load
          (get_local $5)
         )
        )
        (i32.load
         (get_local $4)
        )
       )
      )
      (i32.store8
       (get_local $3)
       (i32.load8_u
        (get_local $0)
       )
      )
      (i32.store
       (get_local $5)
       (i32.add
        (i32.load
         (get_local $5)
        )
        (i32.const 1)
       )
      )
      (br $label$2)
     )
     (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
      (get_local $2)
      (get_local $0)
     )
    )
    (set_local $0
     (i32.add
      (get_local $0)
      (i32.const 1)
     )
    )
    (br_if $label$1
     (tee_local $1
      (i32.add
       (get_local $1)
       (i32.const -1)
      )
     )
    )
   )
  )
 )
 (func $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_ (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.le_s
      (tee_local $7
       (i32.add
        (tee_local $3
         (i32.sub
          (tee_local $5
           (i32.load offset=4
            (get_local $0)
           )
          )
          (tee_local $4
           (i32.load
            (get_local $0)
           )
          )
         )
        )
        (i32.const 1)
       )
      )
      (i32.const -1)
     )
    )
    (set_local $6
     (i32.const 2147483647)
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (tee_local $2
         (i32.sub
          (i32.load offset=8
           (get_local $0)
          )
          (get_local $4)
         )
        )
        (i32.const 1073741822)
       )
      )
      (br_if $label$2
       (i32.eqz
        (tee_local $6
         (select
          (get_local $7)
          (tee_local $6
           (i32.shl
            (get_local $2)
            (i32.const 1)
           )
          )
          (i32.lt_u
           (get_local $6)
           (get_local $7)
          )
         )
        )
       )
      )
     )
     (set_local $7
      (call $_Znwj
       (get_local $6)
      )
     )
     (set_local $5
      (i32.load
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
     (set_local $4
      (i32.load
       (get_local $0)
      )
     )
     (br $label$0)
    )
    (set_local $6
     (i32.const 0)
    )
    (set_local $7
     (i32.const 0)
    )
    (br $label$0)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
    (get_local $0)
   )
   (unreachable)
  )
  (i32.store8
   (tee_local $3
    (i32.add
     (get_local $7)
     (get_local $3)
    )
   )
   (i32.load8_u
    (get_local $1)
   )
  )
  (set_local $1
   (i32.sub
    (get_local $3)
    (tee_local $5
     (i32.sub
      (get_local $5)
      (get_local $4)
     )
    )
   )
  )
  (set_local $6
   (i32.add
    (get_local $7)
    (get_local $6)
   )
  )
  (set_local $7
   (i32.add
    (get_local $3)
    (i32.const 1)
   )
  )
  (block $label$4
   (br_if $label$4
    (i32.lt_s
     (get_local $5)
     (i32.const 1)
    )
   )
   (drop
    (call $memcpy
     (get_local $1)
     (get_local $4)
     (get_local $5)
    )
   )
   (set_local $4
    (i32.load
     (get_local $0)
    )
   )
  )
  (i32.store
   (get_local $0)
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $7)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $6)
  )
  (block $label$5
   (br_if $label$5
    (i32.eqz
     (get_local $4)
    )
   )
   (call $_ZdlPv
    (get_local $4)
   )
  )
 )
 (func $_ZN16test_transaction11send_actionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (i32.store8
   (i32.add
    (get_local $7)
    (i32.const 92)
   )
   (i32.load8_u offset=9356
    (i32.const 0)
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 88)
   )
   (i32.load offset=9352 align=1
    (i32.const 0)
   )
  )
  (i64.store offset=80
   (get_local $7)
   (i64.load offset=9344 align=1
    (i32.const 0)
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 416)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 9360)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $7)
   (get_local $6)
  )
  (i64.store offset=8
   (get_local $7)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (tee_local $1
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $7)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $7)
   )
  )
  (i32.store offset=24
   (get_local $7)
   (get_local $1)
  )
  (i32.store
   (get_local $1)
   (i32.load offset=8
    (get_local $7)
   )
  )
  (i32.store offset=32
   (get_local $7)
   (tee_local $0
    (i32.add
     (get_local $1)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $7)
   )
  )
  (i32.store offset=28
   (get_local $7)
   (get_local $0)
  )
  (set_local $1
   (call $_ZN5eosio6actionC2I17test_dummy_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $7)
     (i32.const 40)
    )
    (i32.add
     (get_local $7)
     (i32.const 24)
    )
    (i32.add
     (get_local $7)
     (i32.const 80)
    )
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $0
      (i32.load offset=24
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (get_local $1)
  )
  (call $send_inline
   (tee_local $0
    (i32.load offset=8
     (get_local $7)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $7)
    )
    (get_local $0)
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $0
      (i32.load offset=8
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $0
      (i32.load offset=28
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 32)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$15
   (br_if $label$15
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 20)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 96)
   )
  )
 )
 (func $_ZN5eosio6actionC2I17test_dummy_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $5
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $4
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $3
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432478272688454)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $4)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $5)
   (i32.const 0)
  )
  (i64.store
   (get_local $5)
   (i64.const 0)
  )
  (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
   (get_local $5)
   (i32.const 13)
  )
  (call $eosio_assert
   (i32.gt_s
    (tee_local $4
     (i32.sub
      (i32.load offset=4
       (get_local $5)
      )
      (tee_local $1
       (i32.load
        (get_local $5)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $1)
    (get_local $2)
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $4)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
    (i32.add
     (get_local $2)
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $4)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 9)
    )
    (i32.add
     (get_local $2)
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (tee_local $1
      (i32.load offset=28
       (get_local $0)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (i32.add
     (get_local $0)
     (i32.const 28)
    )
    (i64.const 0)
   )
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 28)
   )
   (i64.load
    (get_local $5)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $5)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $5)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction17send_action_emptyEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (i32.store offset=88
   (get_local $7)
   (i32.const 0)
  )
  (set_local $3
   (i64.const 0)
  )
  (i64.store offset=80
   (get_local $7)
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 416)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 9360)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $7)
   (get_local $6)
  )
  (i64.store offset=8
   (get_local $7)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (tee_local $1
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $7)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $7)
   )
  )
  (i32.store offset=24
   (get_local $7)
   (get_local $1)
  )
  (i32.store
   (get_local $1)
   (i32.load offset=8
    (get_local $7)
   )
  )
  (i32.store offset=32
   (get_local $7)
   (tee_local $0
    (i32.add
     (get_local $1)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $7)
   )
  )
  (i32.store offset=28
   (get_local $7)
   (get_local $0)
  )
  (set_local $1
   (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311596421349198EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $7)
     (i32.const 40)
    )
    (i32.add
     (get_local $7)
     (i32.const 24)
    )
    (i32.add
     (get_local $7)
     (i32.const 80)
    )
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $0
      (i32.load offset=24
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (get_local $1)
  )
  (call $send_inline
   (tee_local $0
    (i32.load offset=8
     (get_local $7)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $7)
    )
    (get_local $0)
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $0
      (i32.load offset=8
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $0
      (i32.load offset=28
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 32)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$15
   (br_if $label$15
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 20)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $1
      (i32.load offset=80
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $7)
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 96)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311596421349198EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432477288202418)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction17send_action_largeEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i64)
  (local $10 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $10
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (set_local $2
   (i32.const 0)
  )
  (i32.store offset=88
   (get_local $10)
   (i32.const 0)
  )
  (i64.store offset=80
   (get_local $10)
   (i64.const 0)
  )
  (set_local $1
   (i32.add
    (get_local $10)
    (i32.const 88)
   )
  )
  (set_local $3
   (i32.const 0)
  )
  (set_local $4
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (set_local $0
     (i32.add
      (get_local $4)
      (i32.const 9376)
     )
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.eq
        (get_local $3)
        (get_local $2)
       )
      )
      (i32.store8
       (get_local $3)
       (i32.load8_u
        (get_local $0)
       )
      )
      (i32.store offset=84
       (get_local $10)
       (i32.add
        (i32.load offset=84
         (get_local $10)
        )
        (i32.const 1)
       )
      )
      (br_if $label$2
       (i32.ne
        (get_local $4)
        (i32.const 8191)
       )
      )
      (br $label$0)
     )
     (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
      (i32.add
       (get_local $10)
       (i32.const 80)
      )
      (get_local $0)
     )
     (br_if $label$0
      (i32.eq
       (get_local $4)
       (i32.const 8191)
      )
     )
    )
    (set_local $4
     (i32.add
      (get_local $4)
      (i32.const 1)
     )
    )
    (set_local $2
     (i32.load
      (get_local $1)
     )
    )
    (set_local $3
     (i32.load offset=84
      (get_local $10)
     )
    )
    (br $label$1)
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 416)
  )
  (set_local $7
   (i64.const 0)
  )
  (loop $label$4
   (block $label$5
    (block $label$6
     (block $label$7
      (block $label$8
       (block $label$9
        (br_if $label$9
         (i64.gt_u
          (get_local $6)
          (i64.const 6)
         )
        )
        (br_if $label$8
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$7)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$6
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$5)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $7
    (i64.or
     (get_local $8)
     (get_local $7)
    )
   )
   (br_if $label$4
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 9360)
  )
  (set_local $9
   (i64.const 0)
  )
  (loop $label$10
   (block $label$11
    (block $label$12
     (block $label$13
      (block $label$14
       (block $label$15
        (br_if $label$15
         (i64.gt_u
          (get_local $6)
          (i64.const 5)
         )
        )
        (br_if $label$14
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$13)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$12
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$11)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $9
    (i64.or
     (get_local $8)
     (get_local $9)
    )
   )
   (br_if $label$10
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $10)
   (get_local $9)
  )
  (i64.store offset=8
   (get_local $10)
   (get_local $7)
  )
  (i32.store
   (i32.add
    (tee_local $4
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $10)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $4)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $10)
   )
  )
  (i32.store offset=24
   (get_local $10)
   (get_local $4)
  )
  (i32.store
   (get_local $4)
   (i32.load offset=8
    (get_local $10)
   )
  )
  (i32.store offset=32
   (get_local $10)
   (tee_local $3
    (i32.add
     (get_local $4)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $4)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $10)
   )
  )
  (i32.store offset=28
   (get_local $10)
   (get_local $3)
  )
  (set_local $4
   (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $10)
     (i32.const 40)
    )
    (i32.add
     (get_local $10)
     (i32.const 24)
    )
    (i32.add
     (get_local $10)
     (i32.const 80)
    )
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $3
      (i32.load offset=24
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $10)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $10)
    (i32.const 8)
   )
   (get_local $4)
  )
  (call $send_inline
   (tee_local $3
    (i32.load offset=8
     (get_local $10)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $10)
    )
    (get_local $3)
   )
  )
  (block $label$17
   (br_if $label$17
    (i32.eqz
     (tee_local $3
      (i32.load offset=8
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $10)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 17568)
  )
  (block $label$18
   (br_if $label$18
    (i32.eqz
     (tee_local $3
      (i32.load offset=28
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 32)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (block $label$19
   (br_if $label$19
    (i32.eqz
     (tee_local $3
      (i32.load offset=16
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 20)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (block $label$20
   (br_if $label$20
    (i32.eqz
     (tee_local $4
      (i32.load offset=80
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $10)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $4)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $10)
    (i32.const 96)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432478272688454)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction19send_action_recurseEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i64)
  (local $10 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $10
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 1120)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $10)
     (i32.const 96)
    )
    (i32.const 1024)
   )
  )
  (set_local $2
   (i32.const 0)
  )
  (i32.store offset=88
   (get_local $10)
   (i32.const 0)
  )
  (i64.store offset=80
   (get_local $10)
   (i64.const 0)
  )
  (set_local $1
   (i32.add
    (get_local $10)
    (i32.const 88)
   )
  )
  (set_local $3
   (i32.const 0)
  )
  (set_local $4
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (set_local $0
     (i32.add
      (i32.add
       (get_local $10)
       (i32.const 96)
      )
      (get_local $4)
     )
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.eq
        (get_local $3)
        (get_local $2)
       )
      )
      (i32.store8
       (get_local $3)
       (i32.load8_u
        (get_local $0)
       )
      )
      (i32.store offset=84
       (get_local $10)
       (i32.add
        (i32.load offset=84
         (get_local $10)
        )
        (i32.const 1)
       )
      )
      (br_if $label$2
       (i32.ne
        (get_local $4)
        (i32.const 1023)
       )
      )
      (br $label$0)
     )
     (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
      (i32.add
       (get_local $10)
       (i32.const 80)
      )
      (get_local $0)
     )
     (br_if $label$0
      (i32.eq
       (get_local $4)
       (i32.const 1023)
      )
     )
    )
    (set_local $4
     (i32.add
      (get_local $4)
      (i32.const 1)
     )
    )
    (set_local $2
     (i32.load
      (get_local $1)
     )
    )
    (set_local $3
     (i32.load offset=84
      (get_local $10)
     )
    )
    (br $label$1)
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 416)
  )
  (set_local $7
   (i64.const 0)
  )
  (loop $label$4
   (block $label$5
    (block $label$6
     (block $label$7
      (block $label$8
       (block $label$9
        (br_if $label$9
         (i64.gt_u
          (get_local $6)
          (i64.const 6)
         )
        )
        (br_if $label$8
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$7)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$6
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$5)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $7
    (i64.or
     (get_local $8)
     (get_local $7)
    )
   )
   (br_if $label$4
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $5
   (i64.const 59)
  )
  (set_local $4
   (i32.const 9360)
  )
  (set_local $9
   (i64.const 0)
  )
  (loop $label$10
   (block $label$11
    (block $label$12
     (block $label$13
      (block $label$14
       (block $label$15
        (br_if $label$15
         (i64.gt_u
          (get_local $6)
          (i64.const 5)
         )
        )
        (br_if $label$14
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $4)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$13)
       )
       (set_local $8
        (i64.const 0)
       )
       (br_if $label$12
        (i64.le_u
         (get_local $6)
         (i64.const 11)
        )
       )
       (br $label$11)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $8
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $8
     (i64.shl
      (i64.and
       (get_local $8)
       (i64.const 31)
      )
      (i64.and
       (get_local $5)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $4)
     (i32.const 1)
    )
   )
   (set_local $6
    (i64.add
     (get_local $6)
     (i64.const 1)
    )
   )
   (set_local $9
    (i64.or
     (get_local $8)
     (get_local $9)
    )
   )
   (br_if $label$10
    (i64.ne
     (tee_local $5
      (i64.add
       (get_local $5)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $10)
   (get_local $9)
  )
  (i64.store offset=8
   (get_local $10)
   (get_local $7)
  )
  (i32.store
   (i32.add
    (tee_local $4
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $10)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $4)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $10)
   )
  )
  (i32.store offset=24
   (get_local $10)
   (get_local $4)
  )
  (i32.store
   (get_local $4)
   (i32.load offset=8
    (get_local $10)
   )
  )
  (i32.store offset=32
   (get_local $10)
   (tee_local $3
    (i32.add
     (get_local $4)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $4)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $10)
   )
  )
  (i32.store offset=28
   (get_local $10)
   (get_local $3)
  )
  (set_local $4
   (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy17750730571693710178EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $10)
     (i32.const 40)
    )
    (i32.add
     (get_local $10)
     (i32.const 24)
    )
    (i32.add
     (get_local $10)
     (i32.const 80)
    )
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $3
      (i32.load offset=24
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $10)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $10)
    (i32.const 8)
   )
   (get_local $4)
  )
  (call $send_inline
   (tee_local $3
    (i32.load offset=8
     (get_local $10)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $10)
    )
    (get_local $3)
   )
  )
  (block $label$17
   (br_if $label$17
    (i32.eqz
     (tee_local $3
      (i32.load offset=8
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $10)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (block $label$18
   (br_if $label$18
    (i32.eqz
     (tee_local $3
      (i32.load offset=28
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 32)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (block $label$19
   (br_if $label$19
    (i32.eqz
     (tee_local $3
      (i32.load offset=16
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 20)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (block $label$20
   (br_if $label$20
    (i32.eqz
     (tee_local $4
      (i32.load offset=80
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $10)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $4)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $10)
    (i32.const 1120)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy17750730571693710178EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -696013502015841438)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction23send_action_inline_failEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (i32.store offset=88
   (get_local $7)
   (i32.const 0)
  )
  (set_local $3
   (i64.const 0)
  )
  (i64.store offset=80
   (get_local $7)
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 416)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 9360)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $7)
   (get_local $6)
  )
  (i64.store offset=8
   (get_local $7)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (tee_local $1
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $7)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $7)
   )
  )
  (i32.store offset=24
   (get_local $7)
   (get_local $1)
  )
  (i32.store
   (get_local $1)
   (i32.load offset=8
    (get_local $7)
   )
  )
  (i32.store offset=32
   (get_local $7)
   (tee_local $0
    (i32.add
     (get_local $1)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $7)
   )
  )
  (i32.store offset=28
   (get_local $7)
   (get_local $0)
  )
  (set_local $1
   (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595419386437EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $7)
     (i32.const 40)
    )
    (i32.add
     (get_local $7)
     (i32.const 24)
    )
    (i32.add
     (get_local $7)
     (i32.const 80)
    )
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $0
      (i32.load offset=24
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (get_local $1)
  )
  (call $send_inline
   (tee_local $0
    (i32.load offset=8
     (get_local $7)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $7)
    )
    (get_local $0)
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $0
      (i32.load offset=8
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $0
      (i32.load offset=28
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 32)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$15
   (br_if $label$15
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 20)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $1
      (i32.load offset=80
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $7)
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 96)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595419386437EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432478290165179)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction23test_tapos_block_prefixEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 12)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=12
     (get_local $0)
    )
    (call $tapos_block_prefix)
   )
   (i32.const 17616)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN16test_transaction20test_tapos_block_numEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $0)
     (i32.const 12)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=12
     (get_local $0)
    )
    (call $tapos_block_num)
   )
   (i32.const 17664)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN16test_transaction21test_read_transactionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (get_local $2)
     (i32.and
      (i32.add
       (tee_local $1
        (call $transaction_size)
       )
       (i32.const 15)
      )
      (i32.const -16)
     )
    )
   )
  )
  (call $sha256
   (get_local $0)
   (call $read_transaction
    (get_local $0)
    (get_local $1)
   )
   (tee_local $1
    (get_local $2)
   )
  )
  (call $printhex
   (get_local $1)
   (i32.const 32)
  )
  (drop
   (get_local $2)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 32)
   )
  )
 )
 (func $_ZN16test_transaction21test_transaction_sizeEv
  (local $0 i32)
  (local $1 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $1
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=12
   (get_local $1)
   (i32.const 0)
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $1)
     (i32.const 12)
    )
    (i32.const 4)
   )
  )
  (set_local $0
   (call $transaction_size)
  )
  (call $prints
   (i32.const 17696)
  )
  (call $printi
   (i64.extend_u/i32
    (get_local $0)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=12
     (get_local $1)
    )
    (call $transaction_size)
   )
   (i32.const 17712)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 16)
   )
  )
 )
 (func $_ZN16test_transaction16send_transactionEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i64)
  (local $12 i64)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 112)
    )
   )
  )
  (set_local $5
   (i32.const 0)
  )
  (i32.store8
   (i32.add
    (i32.add
     (get_local $13)
     (i32.const 96)
    )
    (i32.const 12)
   )
   (i32.load8_u offset=17756
    (i32.const 0)
   )
  )
  (i32.store
   (i32.add
    (i32.add
     (get_local $13)
     (i32.const 96)
    )
    (i32.const 8)
   )
   (i32.load offset=17752 align=1
    (i32.const 0)
   )
  )
  (i64.store offset=96 align=4
   (get_local $13)
   (i64.load offset=17744 align=1
    (i32.const 0)
   )
  )
  (i32.store offset=88
   (get_local $13)
   (i32.const 0)
  )
  (i64.store offset=80
   (get_local $13)
   (i64.const 0)
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $7
   (i32.const 0)
  )
  (block $label$0
   (loop $label$1
    (set_local $3
     (i32.add
      (i32.add
       (get_local $13)
       (i32.const 96)
      )
      (get_local $7)
     )
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.eq
        (get_local $6)
        (get_local $5)
       )
      )
      (i32.store8
       (get_local $6)
       (i32.load8_u
        (get_local $3)
       )
      )
      (i32.store offset=84
       (get_local $13)
       (i32.add
        (i32.load offset=84
         (get_local $13)
        )
        (i32.const 1)
       )
      )
      (br_if $label$2
       (i32.ne
        (get_local $7)
        (i32.const 12)
       )
      )
      (br $label$0)
     )
     (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
      (i32.add
       (get_local $13)
       (i32.const 80)
      )
      (get_local $3)
     )
     (br_if $label$0
      (i32.eq
       (get_local $7)
       (i32.const 12)
      )
     )
    )
    (set_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
    (set_local $5
     (i32.load
      (i32.add
       (i32.add
        (get_local $13)
        (i32.const 80)
       )
       (i32.const 8)
      )
     )
    )
    (set_local $6
     (i32.load offset=84
      (get_local $13)
     )
    )
    (br $label$1)
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 60)
   )
   (i32.const 0)
  )
  (i32.store16 offset=36
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=44
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=48
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=52
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=56
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=32
   (get_local $13)
   (i32.add
    (get_local $7)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 64)
   )
   (i32.const 0)
  )
  (i32.store offset=68
   (get_local $13)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 72)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 76)
   )
   (i32.const 0)
  )
  (set_local $5
   (i32.add
    (get_local $13)
    (i32.const 68)
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 416)
  )
  (set_local $10
   (i64.const 0)
  )
  (loop $label$4
   (block $label$5
    (block $label$6
     (block $label$7
      (block $label$8
       (block $label$9
        (br_if $label$9
         (i64.gt_u
          (get_local $9)
          (i64.const 6)
         )
        )
        (br_if $label$8
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $6
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $6
         (i32.add
          (get_local $6)
          (i32.const 165)
         )
        )
        (br $label$7)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$6
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$5)
      )
      (set_local $6
       (select
        (i32.add
         (get_local $6)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $6)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $6)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $10
    (i64.or
     (get_local $11)
     (get_local $10)
    )
   )
   (br_if $label$4
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 9360)
  )
  (set_local $12
   (i64.const 0)
  )
  (loop $label$10
   (block $label$11
    (block $label$12
     (block $label$13
      (block $label$14
       (block $label$15
        (br_if $label$15
         (i64.gt_u
          (get_local $9)
          (i64.const 5)
         )
        )
        (br_if $label$14
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $6
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $6
         (i32.add
          (get_local $6)
          (i32.const 165)
         )
        )
        (br $label$13)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$12
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$11)
      )
      (set_local $6
       (select
        (i32.add
         (get_local $6)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $6)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $6)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $12
    (i64.or
     (get_local $11)
     (get_local $12)
    )
   )
   (br_if $label$10
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=8
   (get_local $13)
   (get_local $12)
  )
  (i64.store
   (get_local $13)
   (get_local $10)
  )
  (i32.store
   (i32.add
    (tee_local $7
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (get_local $13)
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 4)
   )
   (i32.load offset=4
    (get_local $13)
   )
  )
  (i32.store offset=16
   (get_local $13)
   (get_local $7)
  )
  (i32.store
   (get_local $7)
   (i32.load
    (get_local $13)
   )
  )
  (i32.store offset=24
   (get_local $13)
   (tee_local $6
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (i32.load offset=8
    (get_local $13)
   )
  )
  (i32.store offset=20
   (get_local $13)
   (get_local $6)
  )
  (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEEvDpOT_
   (get_local $5)
   (i32.add
    (get_local $13)
    (i32.const 16)
   )
   (i32.add
    (get_local $13)
    (i32.const 80)
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $7
      (i32.load offset=16
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=20
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $13)
    (i32.const 32)
   )
   (i64.const 0)
   (get_local $0)
  )
  (block $label$17
   (br_if $label$17
    (i32.eqz
     (tee_local $3
      (i32.load offset=68
       (get_local $13)
      )
     )
    )
   )
   (block $label$18
    (block $label$19
     (br_if $label$19
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $4
          (i32.add
           (get_local $13)
           (i32.const 72)
          )
         )
        )
       )
       (get_local $3)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $3)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$20
      (block $label$21
       (br_if $label$21
        (i32.eqz
         (tee_local $6
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $6)
       )
       (call $_ZdlPv
        (get_local $6)
       )
      )
      (block $label$22
       (br_if $label$22
        (i32.eqz
         (tee_local $6
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $6)
       )
       (call $_ZdlPv
        (get_local $6)
       )
      )
      (br_if $label$20
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 68)
       )
      )
     )
     (br $label$18)
    )
    (set_local $7
     (get_local $3)
    )
   )
   (i32.store
    (get_local $4)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$23
   (br_if $label$23
    (i32.eqz
     (tee_local $3
      (i32.load offset=56
       (get_local $13)
      )
     )
    )
   )
   (block $label$24
    (block $label$25
     (br_if $label$25
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $4
          (i32.add
           (get_local $13)
           (i32.const 60)
          )
         )
        )
       )
       (get_local $3)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $3)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$26
      (block $label$27
       (br_if $label$27
        (i32.eqz
         (tee_local $6
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $6)
       )
       (call $_ZdlPv
        (get_local $6)
       )
      )
      (block $label$28
       (br_if $label$28
        (i32.eqz
         (tee_local $6
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $6)
       )
       (call $_ZdlPv
        (get_local $6)
       )
      )
      (br_if $label$26
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 56)
       )
      )
     )
     (br $label$24)
    )
    (set_local $7
     (get_local $3)
    )
   )
   (i32.store
    (get_local $4)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$29
   (br_if $label$29
    (i32.eqz
     (tee_local $7
      (i32.load offset=80
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 112)
   )
  )
 )
 (func $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEEvDpOT_ (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.ge_u
      (tee_local $6
       (i32.add
        (tee_local $9
         (i32.div_s
          (i32.sub
           (i32.load offset=4
            (get_local $0)
           )
           (tee_local $8
            (i32.load
             (get_local $0)
            )
           )
          )
          (i32.const 40)
         )
        )
        (i32.const 1)
       )
      )
      (i32.const 107374183)
     )
    )
    (set_local $7
     (i32.const 107374182)
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (tee_local $8
         (i32.div_s
          (i32.sub
           (i32.load offset=8
            (get_local $0)
           )
           (get_local $8)
          )
          (i32.const 40)
         )
        )
        (i32.const 53687090)
       )
      )
      (br_if $label$2
       (i32.eqz
        (tee_local $7
         (select
          (get_local $6)
          (tee_local $7
           (i32.shl
            (get_local $8)
            (i32.const 1)
           )
          )
          (i32.lt_u
           (get_local $7)
           (get_local $6)
          )
         )
        )
       )
      )
     )
     (set_local $8
      (call $_Znwj
       (i32.mul
        (get_local $7)
        (i32.const 40)
       )
      )
     )
     (br $label$0)
    )
    (set_local $7
     (i32.const 0)
    )
    (set_local $8
     (i32.const 0)
    )
    (br $label$0)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
    (get_local $0)
   )
   (unreachable)
  )
  (set_local $3
   (i32.add
    (get_local $8)
    (i32.mul
     (get_local $7)
     (i32.const 40)
    )
   )
  )
  (set_local $4
   (i32.add
    (tee_local $8
     (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
      (tee_local $9
       (i32.add
        (get_local $8)
        (i32.mul
         (get_local $9)
         (i32.const 40)
        )
       )
      )
      (get_local $1)
      (get_local $2)
     )
    )
    (i32.const 40)
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (tee_local $7
       (i32.load
        (get_local $0)
       )
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.const 0)
      (get_local $7)
     )
    )
    (set_local $7
     (i32.add
      (get_local $1)
      (i32.const -20)
     )
    )
    (loop $label$6
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -32)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -12)
       )
      )
     )
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -40)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -20)
       )
      )
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -24)
       )
      )
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -16)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const -4)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -20)
      )
      (i32.load
       (get_local $7)
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $1
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
       )
      )
     )
     (i32.store
      (get_local $1)
      (i32.const 0)
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -12)
       )
      )
      (i64.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -4)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const 8)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -8)
      )
      (i32.load
       (i32.add
        (get_local $7)
        (i32.const 12)
       )
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $8
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
       )
      )
     )
     (i32.store
      (get_local $8)
      (i32.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (set_local $8
      (tee_local $9
       (i32.add
        (get_local $9)
        (i32.const -40)
       )
      )
     )
     (br_if $label$6
      (i32.ne
       (i32.add
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -40)
         )
        )
        (get_local $5)
       )
       (i32.const -20)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
    (br $label$4)
   )
   (set_local $1
    (get_local $7)
   )
  )
  (i32.store
   (get_local $0)
   (get_local $9)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $3)
  )
  (block $label$7
   (br_if $label$7
    (i32.eq
     (get_local $7)
     (get_local $1)
    )
   )
   (set_local $9
    (i32.sub
     (i32.const 0)
     (get_local $1)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const -24)
    )
   )
   (loop $label$8
    (block $label$9
     (br_if $label$9
      (i32.eqz
       (tee_local $8
        (i32.load
         (i32.add
          (get_local $7)
          (i32.const 12)
         )
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 16)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (block $label$10
     (br_if $label$10
      (i32.eqz
       (tee_local $8
        (i32.load
         (get_local $7)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 4)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (br_if $label$8
     (i32.ne
      (i32.add
       (tee_local $7
        (i32.add
         (get_local $7)
         (i32.const -40)
        )
       )
       (get_local $9)
      )
      (i32.const -24)
     )
    )
   )
  )
  (block $label$11
   (br_if $label$11
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
 )
 (func $_ZNK5eosio11transaction4sendEyy (param $0 i32) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $5
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (set_local $3
   (i32.const 0)
  )
  (i32.store offset=24
   (get_local $5)
   (i32.const 0)
  )
  (i64.store offset=16
   (get_local $5)
   (i64.const 0)
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (tee_local $4
       (call $_ZN5eosio9pack_sizeINS_11transactionEEEjRKT_
        (get_local $0)
       )
      )
     )
    )
    (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
     (i32.add
      (get_local $5)
      (i32.const 16)
     )
     (get_local $4)
    )
    (set_local $3
     (i32.load offset=20
      (get_local $5)
     )
    )
    (set_local $4
     (i32.load offset=16
      (get_local $5)
     )
    )
    (br $label$0)
   )
   (set_local $4
    (i32.const 0)
   )
  )
  (i32.store offset=4
   (get_local $5)
   (get_local $4)
  )
  (i32.store
   (get_local $5)
   (get_local $4)
  )
  (i32.store offset=8
   (get_local $5)
   (get_local $3)
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNS_18transaction_headerE
    (get_local $5)
    (get_local $0)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEENS_6actionEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
    (call $_ZN5eosiolsINS_10datastreamIPcEENS_6actionEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
     (get_local $5)
     (i32.add
      (get_local $0)
      (i32.const 24)
     )
    )
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
   )
  )
  (i64.store
   (get_local $5)
   (get_local $1)
  )
  (i64.store offset=8
   (get_local $5)
   (i64.const 0)
  )
  (call $send_deferred
   (get_local $5)
   (get_local $2)
   (tee_local $0
    (i32.load offset=16
     (get_local $5)
    )
   )
   (i32.sub
    (i32.load offset=20
     (get_local $5)
    )
    (get_local $0)
   )
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $5)
      )
     )
    )
   )
   (i32.store offset=20
    (get_local $5)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $5)
    (i32.const 32)
   )
  )
 )
 (func $_ZN5eosio9pack_sizeINS_11transactionEEEjRKT_ (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (set_local $7
   (i64.load32_u offset=12
    (get_local $0)
   )
  )
  (set_local $5
   (i32.const 12)
  )
  (loop $label$0
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (set_local $7
   (i64.load32_u offset=16
    (get_local $0)
   )
  )
  (loop $label$1
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$1
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (set_local $7
   (i64.load32_u offset=20
    (get_local $0)
   )
  )
  (loop $label$2
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$2
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (set_local $7
   (i64.extend_u/i32
    (i32.div_s
     (i32.sub
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
      (tee_local $6
       (i32.load offset=24
        (get_local $0)
       )
      )
     )
     (i32.const 40)
    )
   )
  )
  (loop $label$3
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$3
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (block $label$4
   (br_if $label$4
    (i32.eq
     (get_local $6)
     (get_local $1)
    )
   )
   (loop $label$5
    (set_local $5
     (i32.add
      (get_local $5)
      (i32.const 16)
     )
    )
    (set_local $7
     (i64.extend_u/i32
      (i32.shr_s
       (tee_local $4
        (i32.sub
         (tee_local $2
          (i32.load
           (i32.add
            (get_local $6)
            (i32.const 20)
           )
          )
         )
         (tee_local $3
          (i32.load offset=16
           (get_local $6)
          )
         )
        )
       )
       (i32.const 4)
      )
     )
    )
    (loop $label$6
     (set_local $5
      (i32.add
       (get_local $5)
       (i32.const 1)
      )
     )
     (br_if $label$6
      (i64.ne
       (tee_local $7
        (i64.shr_u
         (get_local $7)
         (i64.const 7)
        )
       )
       (i64.const 0)
      )
     )
    )
    (block $label$7
     (br_if $label$7
      (i32.eq
       (get_local $3)
       (get_local $2)
      )
     )
     (set_local $5
      (i32.add
       (i32.and
        (get_local $4)
        (i32.const -16)
       )
       (get_local $5)
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.add
       (get_local $5)
       (tee_local $2
        (i32.load
         (i32.add
          (get_local $6)
          (i32.const 32)
         )
        )
       )
      )
      (tee_local $3
       (i32.load offset=28
        (get_local $6)
       )
      )
     )
    )
    (set_local $7
     (i64.extend_u/i32
      (i32.sub
       (get_local $2)
       (get_local $3)
      )
     )
    )
    (loop $label$8
     (set_local $5
      (i32.add
       (get_local $5)
       (i32.const 1)
      )
     )
     (br_if $label$8
      (i64.ne
       (tee_local $7
        (i64.shr_u
         (get_local $7)
         (i64.const 7)
        )
       )
       (i64.const 0)
      )
     )
    )
    (br_if $label$5
     (i32.ne
      (tee_local $6
       (i32.add
        (get_local $6)
        (i32.const 40)
       )
      )
      (get_local $1)
     )
    )
   )
  )
  (set_local $7
   (i64.extend_u/i32
    (i32.div_s
     (i32.sub
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 40)
        )
       )
      )
      (tee_local $6
       (i32.load offset=36
        (get_local $0)
       )
      )
     )
     (i32.const 40)
    )
   )
  )
  (loop $label$9
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 1)
    )
   )
   (br_if $label$9
    (i64.ne
     (tee_local $7
      (i64.shr_u
       (get_local $7)
       (i64.const 7)
      )
     )
     (i64.const 0)
    )
   )
  )
  (block $label$10
   (br_if $label$10
    (i32.eq
     (get_local $6)
     (get_local $1)
    )
   )
   (loop $label$11
    (set_local $5
     (i32.add
      (get_local $5)
      (i32.const 16)
     )
    )
    (set_local $7
     (i64.extend_u/i32
      (i32.shr_s
       (tee_local $4
        (i32.sub
         (tee_local $2
          (i32.load
           (i32.add
            (get_local $6)
            (i32.const 20)
           )
          )
         )
         (tee_local $3
          (i32.load offset=16
           (get_local $6)
          )
         )
        )
       )
       (i32.const 4)
      )
     )
    )
    (loop $label$12
     (set_local $5
      (i32.add
       (get_local $5)
       (i32.const 1)
      )
     )
     (br_if $label$12
      (i64.ne
       (tee_local $7
        (i64.shr_u
         (get_local $7)
         (i64.const 7)
        )
       )
       (i64.const 0)
      )
     )
    )
    (block $label$13
     (br_if $label$13
      (i32.eq
       (get_local $3)
       (get_local $2)
      )
     )
     (set_local $5
      (i32.add
       (i32.and
        (get_local $4)
        (i32.const -16)
       )
       (get_local $5)
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.add
       (get_local $5)
       (tee_local $2
        (i32.load
         (i32.add
          (get_local $6)
          (i32.const 32)
         )
        )
       )
      )
      (tee_local $3
       (i32.load offset=28
        (get_local $6)
       )
      )
     )
    )
    (set_local $7
     (i64.extend_u/i32
      (i32.sub
       (get_local $2)
       (get_local $3)
      )
     )
    )
    (loop $label$14
     (set_local $5
      (i32.add
       (get_local $5)
       (i32.const 1)
      )
     )
     (br_if $label$14
      (i64.ne
       (tee_local $7
        (i64.shr_u
         (get_local $7)
         (i64.const 7)
        )
       )
       (i64.const 0)
      )
     )
    )
    (br_if $label$11
     (i32.ne
      (tee_local $6
       (i32.add
        (get_local $6)
        (i32.const 40)
       )
      )
      (get_local $1)
     )
    )
   )
  )
  (get_local $5)
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNS_18transaction_headerE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (i32.load offset=4
      (get_local $0)
     )
    )
    (i32.const 3)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load offset=4
     (get_local $0)
    )
    (get_local $1)
    (i32.const 4)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 4)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 1)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load offset=4
     (get_local $0)
    )
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
    (i32.const 2)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 2)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 1)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load offset=4
     (get_local $0)
    )
    (i32.add
     (get_local $1)
     (i32.const 6)
    )
    (i32.const 2)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 2)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 3)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load offset=4
     (get_local $0)
    )
    (i32.add
     (get_local $1)
     (i32.const 8)
    )
    (i32.const 4)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 4)
    )
   )
  )
  (set_local $6
   (i64.load32_u offset=12
    (get_local $1)
   )
  )
  (loop $label$0
   (set_local $5
    (i32.wrap/i64
     (get_local $6)
    )
   )
   (i32.store8 offset=13
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $2
       (i64.ne
        (tee_local $6
         (i64.shr_u
          (get_local $6)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $5)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (i32.add
        (get_local $0)
        (i32.const 8)
       )
      )
      (get_local $7)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (tee_local $5
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
     (i32.add
      (get_local $8)
      (i32.const 13)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $7
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $2)
   )
  )
  (set_local $6
   (i64.load32_u offset=16
    (get_local $1)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$1
   (set_local $2
    (i32.wrap/i64
     (get_local $6)
    )
   )
   (i32.store8 offset=14
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $6
         (i64.shr_u
          (get_local $6)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $2)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $4)
      )
      (get_local $7)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 14)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $7
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$1
    (get_local $3)
   )
  )
  (set_local $6
   (i64.load32_u offset=20
    (get_local $1)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$2
   (set_local $2
    (i32.wrap/i64
     (get_local $6)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $6
         (i64.shr_u
          (get_local $6)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $2)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $4)
      )
      (get_local $7)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $7
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$2
    (get_local $3)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEENS_6actionEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $5
   (i64.extend_u/i32
    (i32.div_s
     (i32.sub
      (i32.load offset=4
       (get_local $1)
      )
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 40)
    )
   )
  )
  (set_local $6
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (set_local $7
    (i32.wrap/i64
     (get_local $5)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $2
       (i64.ne
        (tee_local $5
         (i64.shr_u
          (get_local $5)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $7)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $3)
      )
      (get_local $6)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $4)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $4)
    (tee_local $6
     (i32.add
      (i32.load
       (get_local $4)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $2)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (tee_local $7
      (i32.load
       (get_local $1)
      )
     )
     (tee_local $3
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $0)
     (i32.const 4)
    )
   )
   (loop $label$2
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (tee_local $2
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
        )
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (get_local $4)
      )
      (get_local $7)
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $6
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (get_local $2)
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (get_local $4)
      )
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (i32.add
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (drop
     (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__16vectorIcNS6_9allocatorIcEEEE
      (call $_ZN5eosiolsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RKNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
       (get_local $0)
       (i32.add
        (get_local $7)
        (i32.const 16)
       )
      )
      (i32.add
       (get_local $7)
       (i32.const 28)
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (tee_local $7
       (i32.add
        (get_local $7)
        (i32.const 40)
       )
      )
      (get_local $3)
     )
    )
    (set_local $6
     (i32.load
      (get_local $4)
     )
    )
    (br $label$2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction18send_action_senderEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i64)
  (local $12 i64)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 112)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $13)
     (i32.const 104)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=96
   (get_local $13)
   (i32.const 0)
  )
  (i64.store offset=88
   (get_local $13)
   (i64.const 0)
  )
  (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
   (i32.add
    (get_local $13)
    (i32.const 104)
   )
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eq
      (tee_local $7
       (i32.load offset=92
        (get_local $13)
       )
      )
      (i32.load offset=96
       (get_local $13)
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=105
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$0)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 1)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$2
   (block $label$3
    (br_if $label$3
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=106
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$2)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 2)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=107
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$4)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 3)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$6
   (block $label$7
    (br_if $label$7
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=108
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$6)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 4)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$8
   (block $label$9
    (br_if $label$9
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=109
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$8)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 5)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$10
   (block $label$11
    (br_if $label$11
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=110
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$10)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 6)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$12
   (block $label$13
    (br_if $label$13
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=111
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (i32.add
      (i32.load offset=92
       (get_local $13)
      )
      (i32.const 1)
     )
    )
    (br $label$12)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 7)
    )
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 68)
   )
   (i32.const 0)
  )
  (i32.store16 offset=44
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=52
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=56
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=60
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=64
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=40
   (get_local $13)
   (i32.add
    (get_local $7)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 72)
   )
   (i32.const 0)
  )
  (i32.store offset=76
   (get_local $13)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 80)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 84)
   )
   (i32.const 0)
  )
  (set_local $5
   (i32.add
    (get_local $13)
    (i32.const 76)
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 416)
  )
  (set_local $10
   (i64.const 0)
  )
  (loop $label$14
   (block $label$15
    (block $label$16
     (block $label$17
      (block $label$18
       (block $label$19
        (br_if $label$19
         (i64.gt_u
          (get_local $9)
          (i64.const 6)
         )
        )
        (br_if $label$18
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$17)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$16
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$15)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $10
    (i64.or
     (get_local $11)
     (get_local $10)
    )
   )
   (br_if $label$14
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 9360)
  )
  (set_local $12
   (i64.const 0)
  )
  (loop $label$20
   (block $label$21
    (block $label$22
     (block $label$23
      (block $label$24
       (block $label$25
        (br_if $label$25
         (i64.gt_u
          (get_local $9)
          (i64.const 5)
         )
        )
        (br_if $label$24
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$23)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$22
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$21)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $12
    (i64.or
     (get_local $11)
     (get_local $12)
    )
   )
   (br_if $label$20
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $13)
   (get_local $12)
  )
  (i64.store offset=8
   (get_local $13)
   (get_local $10)
  )
  (i32.store
   (i32.add
    (tee_local $7
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $13)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $13)
   )
  )
  (i32.store offset=24
   (get_local $13)
   (get_local $7)
  )
  (i32.store
   (get_local $7)
   (i32.load offset=8
    (get_local $13)
   )
  )
  (i32.store offset=32
   (get_local $13)
   (tee_local $3
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $13)
   )
  )
  (i32.store offset=28
   (get_local $13)
   (get_local $3)
  )
  (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311597322538353EEEEEvDpOT_
   (get_local $5)
   (i32.add
    (get_local $13)
    (i32.const 24)
   )
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
  )
  (block $label$26
   (br_if $label$26
    (i32.eqz
     (tee_local $7
      (i32.load offset=24
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $13)
    (i32.const 40)
   )
   (i64.const 0)
   (get_local $0)
  )
  (block $label$27
   (br_if $label$27
    (i32.eqz
     (tee_local $4
      (i32.load offset=76
       (get_local $13)
      )
     )
    )
   )
   (block $label$28
    (block $label$29
     (br_if $label$29
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 80)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$30
      (block $label$31
       (br_if $label$31
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$32
       (br_if $label$32
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$30
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 76)
       )
      )
     )
     (br $label$28)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$33
   (br_if $label$33
    (i32.eqz
     (tee_local $4
      (i32.load offset=64
       (get_local $13)
      )
     )
    )
   )
   (block $label$34
    (block $label$35
     (br_if $label$35
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 68)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$36
      (block $label$37
       (br_if $label$37
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$38
       (br_if $label$38
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$36
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 64)
       )
      )
     )
     (br $label$34)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$39
   (br_if $label$39
    (i32.eqz
     (tee_local $7
      (i32.load offset=88
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=92
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 112)
   )
  )
 )
 (func $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311597322538353EEEEEvDpOT_ (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.ge_u
      (tee_local $6
       (i32.add
        (tee_local $9
         (i32.div_s
          (i32.sub
           (i32.load offset=4
            (get_local $0)
           )
           (tee_local $8
            (i32.load
             (get_local $0)
            )
           )
          )
          (i32.const 40)
         )
        )
        (i32.const 1)
       )
      )
      (i32.const 107374183)
     )
    )
    (set_local $7
     (i32.const 107374182)
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (tee_local $8
         (i32.div_s
          (i32.sub
           (i32.load offset=8
            (get_local $0)
           )
           (get_local $8)
          )
          (i32.const 40)
         )
        )
        (i32.const 53687090)
       )
      )
      (br_if $label$2
       (i32.eqz
        (tee_local $7
         (select
          (get_local $6)
          (tee_local $7
           (i32.shl
            (get_local $8)
            (i32.const 1)
           )
          )
          (i32.lt_u
           (get_local $7)
           (get_local $6)
          )
         )
        )
       )
      )
     )
     (set_local $8
      (call $_Znwj
       (i32.mul
        (get_local $7)
        (i32.const 40)
       )
      )
     )
     (br $label$0)
    )
    (set_local $7
     (i32.const 0)
    )
    (set_local $8
     (i32.const 0)
    )
    (br $label$0)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
    (get_local $0)
   )
   (unreachable)
  )
  (set_local $3
   (i32.add
    (get_local $8)
    (i32.mul
     (get_local $7)
     (i32.const 40)
    )
   )
  )
  (set_local $4
   (i32.add
    (tee_local $8
     (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311597322538353EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
      (tee_local $9
       (i32.add
        (get_local $8)
        (i32.mul
         (get_local $9)
         (i32.const 40)
        )
       )
      )
      (get_local $1)
      (get_local $2)
     )
    )
    (i32.const 40)
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (tee_local $7
       (i32.load
        (get_local $0)
       )
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.const 0)
      (get_local $7)
     )
    )
    (set_local $7
     (i32.add
      (get_local $1)
      (i32.const -20)
     )
    )
    (loop $label$6
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -32)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -12)
       )
      )
     )
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -40)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -20)
       )
      )
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -24)
       )
      )
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -16)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const -4)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -20)
      )
      (i32.load
       (get_local $7)
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $1
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
       )
      )
     )
     (i32.store
      (get_local $1)
      (i32.const 0)
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -12)
       )
      )
      (i64.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -4)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const 8)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -8)
      )
      (i32.load
       (i32.add
        (get_local $7)
        (i32.const 12)
       )
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $8
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
       )
      )
     )
     (i32.store
      (get_local $8)
      (i32.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (set_local $8
      (tee_local $9
       (i32.add
        (get_local $9)
        (i32.const -40)
       )
      )
     )
     (br_if $label$6
      (i32.ne
       (i32.add
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -40)
         )
        )
        (get_local $5)
       )
       (i32.const -20)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
    (br $label$4)
   )
   (set_local $1
    (get_local $7)
   )
  )
  (i32.store
   (get_local $0)
   (get_local $9)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $3)
  )
  (block $label$7
   (br_if $label$7
    (i32.eq
     (get_local $7)
     (get_local $1)
    )
   )
   (set_local $9
    (i32.sub
     (i32.const 0)
     (get_local $1)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const -24)
    )
   )
   (loop $label$8
    (block $label$9
     (br_if $label$9
      (i32.eqz
       (tee_local $8
        (i32.load
         (i32.add
          (get_local $7)
          (i32.const 12)
         )
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 16)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (block $label$10
     (br_if $label$10
      (i32.eqz
       (tee_local $8
        (i32.load
         (get_local $7)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 4)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (br_if $label$8
     (i32.ne
      (i32.add
       (tee_local $7
        (i32.add
         (get_local $7)
         (i32.const -40)
        )
       )
       (get_local $9)
      )
      (i32.const -24)
     )
    )
   )
  )
  (block $label$11
   (br_if $label$11
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311597322538353EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432476387013263)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction22send_transaction_emptyEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 48)
    )
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $8)
    (i32.const 28)
   )
   (i32.const 0)
  )
  (i32.store16 offset=4
   (get_local $8)
   (i32.const 0)
  )
  (i32.store offset=12
   (get_local $8)
   (i32.const 0)
  )
  (i32.store offset=16
   (get_local $8)
   (i32.const 0)
  )
  (i32.store offset=20
   (get_local $8)
   (i32.const 0)
  )
  (i32.store offset=24
   (get_local $8)
   (i32.const 0)
  )
  (i32.store
   (get_local $8)
   (i32.add
    (get_local $7)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $8)
    (i32.const 32)
   )
   (i32.const 0)
  )
  (i32.store offset=36
   (get_local $8)
   (i32.const 0)
  )
  (i32.store
   (tee_local $7
    (i32.add
     (get_local $8)
     (i32.const 40)
    )
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $8)
    (i32.const 44)
   )
   (i32.const 0)
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (get_local $8)
   (i64.const 0)
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 17760)
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.load offset=36
       (get_local $8)
      )
     )
    )
   )
   (block $label$1
    (block $label$2
     (br_if $label$2
      (i32.eq
       (tee_local $7
        (i32.load
         (get_local $7)
        )
       )
       (get_local $3)
      )
     )
     (set_local $4
      (i32.sub
       (i32.const 0)
       (get_local $3)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$3
      (block $label$4
       (br_if $label$4
        (i32.eqz
         (tee_local $5
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $5)
       )
       (call $_ZdlPv
        (get_local $5)
       )
      )
      (block $label$5
       (br_if $label$5
        (i32.eqz
         (tee_local $5
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $5)
       )
       (call $_ZdlPv
        (get_local $5)
       )
      )
      (br_if $label$3
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $4)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $8)
        (i32.const 36)
       )
      )
     )
     (br $label$1)
    )
    (set_local $7
     (get_local $3)
    )
   )
   (i32.store
    (i32.add
     (get_local $8)
     (i32.const 40)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$6
   (br_if $label$6
    (i32.eqz
     (tee_local $3
      (i32.load offset=24
       (get_local $8)
      )
     )
    )
   )
   (block $label$7
    (block $label$8
     (br_if $label$8
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $8)
           (i32.const 28)
          )
         )
        )
       )
       (get_local $3)
      )
     )
     (set_local $4
      (i32.sub
       (i32.const 0)
       (get_local $3)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$9
      (block $label$10
       (br_if $label$10
        (i32.eqz
         (tee_local $5
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $5)
       )
       (call $_ZdlPv
        (get_local $5)
       )
      )
      (block $label$11
       (br_if $label$11
        (i32.eqz
         (tee_local $5
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $5)
       )
       (call $_ZdlPv
        (get_local $5)
       )
      )
      (br_if $label$9
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $4)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $8)
        (i32.const 24)
       )
      )
     )
     (br $label$7)
    )
    (set_local $7
     (get_local $3)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 48)
   )
  )
 )
 (func $_ZN16test_transaction38send_transaction_trigger_error_handlerEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i64)
  (local $12 i64)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 76)
   )
   (i32.const 0)
  )
  (i32.store16 offset=52
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=60
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=64
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=68
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=72
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=48
   (get_local $13)
   (i32.add
    (get_local $7)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 80)
   )
   (i32.const 0)
  )
  (i32.store offset=84
   (get_local $13)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 92)
   )
   (i32.const 0)
  )
  (i32.store offset=40
   (get_local $13)
   (i32.const 0)
  )
  (set_local $9
   (i64.const 0)
  )
  (i64.store offset=32
   (get_local $13)
   (i64.const 0)
  )
  (set_local $5
   (i32.add
    (get_local $13)
    (i32.const 84)
   )
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 416)
  )
  (set_local $10
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $9)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $10
    (i64.or
     (get_local $11)
     (get_local $10)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 9360)
  )
  (set_local $12
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $9)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $12
    (i64.or
     (get_local $11)
     (get_local $12)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=8
   (get_local $13)
   (get_local $12)
  )
  (i64.store
   (get_local $13)
   (get_local $10)
  )
  (i32.store
   (i32.add
    (tee_local $7
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (get_local $13)
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 4)
   )
   (i32.load offset=4
    (get_local $13)
   )
  )
  (i32.store offset=16
   (get_local $13)
   (get_local $7)
  )
  (i32.store
   (get_local $7)
   (i32.load
    (get_local $13)
   )
  )
  (i32.store offset=24
   (get_local $13)
   (tee_local $3
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (i32.load offset=8
    (get_local $13)
   )
  )
  (i32.store offset=20
   (get_local $13)
   (get_local $3)
  )
  (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311595419386437EEEEEvDpOT_
   (get_local $5)
   (i32.add
    (get_local $13)
    (i32.const 16)
   )
   (i32.add
    (get_local $13)
    (i32.const 32)
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $7
      (i32.load offset=16
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=20
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $13)
    (i32.const 48)
   )
   (i64.const 0)
   (get_local $0)
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $7
      (i32.load offset=32
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=36
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $4
      (i32.load offset=84
       (get_local $13)
      )
     )
    )
   )
   (block $label$15
    (block $label$16
     (br_if $label$16
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 88)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$17
      (block $label$18
       (br_if $label$18
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$19
       (br_if $label$19
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$17
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 84)
       )
      )
     )
     (br $label$15)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$20
   (br_if $label$20
    (i32.eqz
     (tee_local $4
      (i32.load offset=72
       (get_local $13)
      )
     )
    )
   )
   (block $label$21
    (block $label$22
     (br_if $label$22
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 76)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$23
      (block $label$24
       (br_if $label$24
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$25
       (br_if $label$25
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$23
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 72)
       )
      )
     )
     (br $label$21)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 96)
   )
  )
 )
 (func $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311595419386437EEEEEvDpOT_ (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.ge_u
      (tee_local $6
       (i32.add
        (tee_local $9
         (i32.div_s
          (i32.sub
           (i32.load offset=4
            (get_local $0)
           )
           (tee_local $8
            (i32.load
             (get_local $0)
            )
           )
          )
          (i32.const 40)
         )
        )
        (i32.const 1)
       )
      )
      (i32.const 107374183)
     )
    )
    (set_local $7
     (i32.const 107374182)
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (tee_local $8
         (i32.div_s
          (i32.sub
           (i32.load offset=8
            (get_local $0)
           )
           (get_local $8)
          )
          (i32.const 40)
         )
        )
        (i32.const 53687090)
       )
      )
      (br_if $label$2
       (i32.eqz
        (tee_local $7
         (select
          (get_local $6)
          (tee_local $7
           (i32.shl
            (get_local $8)
            (i32.const 1)
           )
          )
          (i32.lt_u
           (get_local $7)
           (get_local $6)
          )
         )
        )
       )
      )
     )
     (set_local $8
      (call $_Znwj
       (i32.mul
        (get_local $7)
        (i32.const 40)
       )
      )
     )
     (br $label$0)
    )
    (set_local $7
     (i32.const 0)
    )
    (set_local $8
     (i32.const 0)
    )
    (br $label$0)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
    (get_local $0)
   )
   (unreachable)
  )
  (set_local $3
   (i32.add
    (get_local $8)
    (i32.mul
     (get_local $7)
     (i32.const 40)
    )
   )
  )
  (set_local $4
   (i32.add
    (tee_local $8
     (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595419386437EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
      (tee_local $9
       (i32.add
        (get_local $8)
        (i32.mul
         (get_local $9)
         (i32.const 40)
        )
       )
      )
      (get_local $1)
      (get_local $2)
     )
    )
    (i32.const 40)
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (tee_local $7
       (i32.load
        (get_local $0)
       )
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.const 0)
      (get_local $7)
     )
    )
    (set_local $7
     (i32.add
      (get_local $1)
      (i32.const -20)
     )
    )
    (loop $label$6
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -32)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -12)
       )
      )
     )
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -40)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -20)
       )
      )
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -24)
       )
      )
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -16)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const -4)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -20)
      )
      (i32.load
       (get_local $7)
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $1
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
       )
      )
     )
     (i32.store
      (get_local $1)
      (i32.const 0)
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -12)
       )
      )
      (i64.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -4)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const 8)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -8)
      )
      (i32.load
       (i32.add
        (get_local $7)
        (i32.const 12)
       )
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $8
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
       )
      )
     )
     (i32.store
      (get_local $8)
      (i32.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (set_local $8
      (tee_local $9
       (i32.add
        (get_local $9)
        (i32.const -40)
       )
      )
     )
     (br_if $label$6
      (i32.ne
       (i32.add
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -40)
         )
        )
        (get_local $5)
       )
       (i32.const -20)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
    (br $label$4)
   )
   (set_local $1
    (get_local $7)
   )
  )
  (i32.store
   (get_local $0)
   (get_local $9)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $3)
  )
  (block $label$7
   (br_if $label$7
    (i32.eq
     (get_local $7)
     (get_local $1)
    )
   )
   (set_local $9
    (i32.sub
     (i32.const 0)
     (get_local $1)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const -24)
    )
   )
   (loop $label$8
    (block $label$9
     (br_if $label$9
      (i32.eqz
       (tee_local $8
        (i32.load
         (i32.add
          (get_local $7)
          (i32.const 12)
         )
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 16)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (block $label$10
     (br_if $label$10
      (i32.eqz
       (tee_local $8
        (i32.load
         (get_local $7)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 4)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (br_if $label$8
     (i32.ne
      (i32.add
       (tee_local $7
        (i32.add
         (get_local $7)
         (i32.const -40)
        )
       )
       (get_local $9)
      )
      (i32.const -24)
     )
    )
   )
  )
  (block $label$11
   (br_if $label$11
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
 )
 (func $_ZN16test_transaction26assert_false_error_handlerERKN5eosio20deferred_transactionE (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $3
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 48)
    )
   )
  )
  (call $_ZN5eosio10get_actionEmm
   (i32.add
    (get_local $3)
    (i32.const 8)
   )
   (i32.const 1)
   (i32.const 0)
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eq
      (i32.load
       (i32.add
        (get_local $3)
        (i32.const 28)
       )
      )
      (tee_local $1
       (i32.load offset=24
        (get_local $3)
       )
      )
     )
    )
    (br_if $label$0
     (i32.eq
      (i32.load
       (i32.add
        (get_local $0)
        (i32.const 40)
       )
      )
      (tee_local $2
       (i32.load offset=36
        (get_local $0)
       )
      )
     )
    )
    (call $eosio_assert
     (i64.eq
      (i64.load
       (get_local $1)
      )
      (i64.load
       (get_local $2)
      )
     )
     (i32.const 17824)
    )
    (block $label$2
     (br_if $label$2
      (i32.eqz
       (tee_local $0
        (i32.load offset=36
         (get_local $3)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $3)
       (i32.const 40)
      )
      (get_local $0)
     )
     (call $_ZdlPv
      (get_local $0)
     )
    )
    (block $label$3
     (br_if $label$3
      (i32.eqz
       (tee_local $0
        (i32.load offset=24
         (get_local $3)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $3)
       (i32.const 28)
      )
      (get_local $0)
     )
     (call $_ZdlPv
      (get_local $0)
     )
    )
    (i32.store offset=4
     (i32.const 0)
     (i32.add
      (get_local $3)
      (i32.const 48)
     )
    )
    (return)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_out_of_rangeEv
    (i32.add
     (get_local $3)
     (i32.const 24)
    )
   )
   (unreachable)
  )
  (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_out_of_rangeEv
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
  )
  (unreachable)
 )
 (func $_ZN16test_transaction22send_transaction_largeEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (local $10 i32)
  (local $11 i32)
  (local $12 i64)
  (local $13 i64)
  (local $14 i64)
  (local $15 i64)
  (local $16 i64)
  (local $17 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $17
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 1120)
    )
   )
  )
  (set_local $11
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $17)
    (i32.const 1100)
   )
   (i32.const 0)
  )
  (i32.store16 offset=1076
   (get_local $17)
   (i32.const 0)
  )
  (i32.store offset=1084
   (get_local $17)
   (i32.const 0)
  )
  (i32.store offset=1088
   (get_local $17)
   (i32.const 0)
  )
  (i32.store offset=1092
   (get_local $17)
   (i32.const 0)
  )
  (i32.store offset=1096
   (get_local $17)
   (i32.const 0)
  )
  (i32.store offset=1072
   (get_local $17)
   (i32.add
    (get_local $11)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (i32.add
     (get_local $17)
     (i32.const 1072)
    )
    (i32.const 32)
   )
   (i32.const 0)
  )
  (i32.store offset=1108
   (get_local $17)
   (i32.const 0)
  )
  (i32.store
   (tee_local $5
    (i32.add
     (i32.add
      (get_local $17)
      (i32.const 1072)
     )
     (i32.const 40)
    )
   )
   (i32.const 0)
  )
  (i32.store
   (tee_local $6
    (i32.add
     (get_local $17)
     (i32.const 1116)
    )
   )
   (i32.const 0)
  )
  (set_local $3
   (i32.add
    (get_local $17)
    (i32.const 1108)
   )
  )
  (set_local $7
   (i32.add
    (i32.add
     (get_local $17)
     (i32.const 32)
    )
    (i32.const 8)
   )
  )
  (set_local $8
   (i32.const 0)
  )
  (loop $label$0
   (i32.store
    (get_local $7)
    (i32.const 0)
   )
   (i64.store offset=32
    (get_local $17)
    (i64.const 0)
   )
   (set_local $9
    (i32.const 0)
   )
   (set_local $10
    (i32.const 0)
   )
   (set_local $11
    (i32.const 0)
   )
   (block $label$1
    (loop $label$2
     (set_local $4
      (i32.add
       (i32.add
        (get_local $17)
        (i32.const 48)
       )
       (get_local $11)
      )
     )
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.eq
         (get_local $10)
         (get_local $9)
        )
       )
       (i32.store8
        (get_local $10)
        (i32.load8_u
         (get_local $4)
        )
       )
       (i32.store offset=36
        (get_local $17)
        (i32.add
         (i32.load offset=36
          (get_local $17)
         )
         (i32.const 1)
        )
       )
       (br_if $label$3
        (i32.ne
         (get_local $11)
         (i32.const 1023)
        )
       )
       (br $label$1)
      )
      (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
       (i32.add
        (get_local $17)
        (i32.const 32)
       )
       (get_local $4)
      )
      (br_if $label$1
       (i32.eq
        (get_local $11)
        (i32.const 1023)
       )
      )
     )
     (set_local $11
      (i32.add
       (get_local $11)
       (i32.const 1)
      )
     )
     (set_local $9
      (i32.load
       (get_local $7)
      )
     )
     (set_local $10
      (i32.load offset=36
       (get_local $17)
      )
     )
     (br $label$2)
    )
   )
   (set_local $13
    (i64.const 0)
   )
   (set_local $12
    (i64.const 59)
   )
   (set_local $11
    (i32.const 416)
   )
   (set_local $14
    (i64.const 0)
   )
   (loop $label$5
    (block $label$6
     (block $label$7
      (block $label$8
       (block $label$9
        (block $label$10
         (br_if $label$10
          (i64.gt_u
           (get_local $13)
           (i64.const 6)
          )
         )
         (br_if $label$9
          (i32.gt_u
           (i32.and
            (i32.add
             (tee_local $10
              (i32.load8_s
               (get_local $11)
              )
             )
             (i32.const -97)
            )
            (i32.const 255)
           )
           (i32.const 25)
          )
         )
         (set_local $10
          (i32.add
           (get_local $10)
           (i32.const 165)
          )
         )
         (br $label$8)
        )
        (set_local $15
         (i64.const 0)
        )
        (br_if $label$7
         (i64.le_u
          (get_local $13)
          (i64.const 11)
         )
        )
        (br $label$6)
       )
       (set_local $10
        (select
         (i32.add
          (get_local $10)
          (i32.const 208)
         )
         (i32.const 0)
         (i32.lt_u
          (i32.and
           (i32.add
            (get_local $10)
            (i32.const -49)
           )
           (i32.const 255)
          )
          (i32.const 5)
         )
        )
       )
      )
      (set_local $15
       (i64.shr_s
        (i64.shl
         (i64.extend_u/i32
          (get_local $10)
         )
         (i64.const 56)
        )
        (i64.const 56)
       )
      )
     )
     (set_local $15
      (i64.shl
       (i64.and
        (get_local $15)
        (i64.const 31)
       )
       (i64.and
        (get_local $12)
        (i64.const 4294967295)
       )
      )
     )
    )
    (set_local $11
     (i32.add
      (get_local $11)
      (i32.const 1)
     )
    )
    (set_local $13
     (i64.add
      (get_local $13)
      (i64.const 1)
     )
    )
    (set_local $14
     (i64.or
      (get_local $15)
      (get_local $14)
     )
    )
    (br_if $label$5
     (i64.ne
      (tee_local $12
       (i64.add
        (get_local $12)
        (i64.const -5)
       )
      )
      (i64.const -6)
     )
    )
   )
   (set_local $13
    (i64.const 0)
   )
   (set_local $12
    (i64.const 59)
   )
   (set_local $11
    (i32.const 9360)
   )
   (set_local $16
    (i64.const 0)
   )
   (loop $label$11
    (block $label$12
     (block $label$13
      (block $label$14
       (block $label$15
        (block $label$16
         (br_if $label$16
          (i64.gt_u
           (get_local $13)
           (i64.const 5)
          )
         )
         (br_if $label$15
          (i32.gt_u
           (i32.and
            (i32.add
             (tee_local $10
              (i32.load8_s
               (get_local $11)
              )
             )
             (i32.const -97)
            )
            (i32.const 255)
           )
           (i32.const 25)
          )
         )
         (set_local $10
          (i32.add
           (get_local $10)
           (i32.const 165)
          )
         )
         (br $label$14)
        )
        (set_local $15
         (i64.const 0)
        )
        (br_if $label$13
         (i64.le_u
          (get_local $13)
          (i64.const 11)
         )
        )
        (br $label$12)
       )
       (set_local $10
        (select
         (i32.add
          (get_local $10)
          (i32.const 208)
         )
         (i32.const 0)
         (i32.lt_u
          (i32.and
           (i32.add
            (get_local $10)
            (i32.const -49)
           )
           (i32.const 255)
          )
          (i32.const 5)
         )
        )
       )
      )
      (set_local $15
       (i64.shr_s
        (i64.shl
         (i64.extend_u/i32
          (get_local $10)
         )
         (i64.const 56)
        )
        (i64.const 56)
       )
      )
     )
     (set_local $15
      (i64.shl
       (i64.and
        (get_local $15)
        (i64.const 31)
       )
       (i64.and
        (get_local $12)
        (i64.const 4294967295)
       )
      )
     )
    )
    (set_local $11
     (i32.add
      (get_local $11)
      (i32.const 1)
     )
    )
    (set_local $13
     (i64.add
      (get_local $13)
      (i64.const 1)
     )
    )
    (set_local $16
     (i64.or
      (get_local $15)
      (get_local $16)
     )
    )
    (br_if $label$11
     (i64.ne
      (tee_local $12
       (i64.add
        (get_local $12)
        (i64.const -5)
       )
      )
      (i64.const -6)
     )
    )
   )
   (i64.store
    (tee_local $10
     (i32.add
      (get_local $17)
      (i32.const 8)
     )
    )
    (get_local $16)
   )
   (i32.store
    (tee_local $9
     (i32.add
      (i32.add
       (get_local $17)
       (i32.const 16)
      )
      (i32.const 8)
     )
    )
    (i32.const 0)
   )
   (i64.store
    (get_local $17)
    (get_local $14)
   )
   (i64.store offset=16
    (get_local $17)
    (i64.const 0)
   )
   (i32.store
    (get_local $9)
    (tee_local $4
     (i32.add
      (tee_local $11
       (call $_Znwj
        (i32.const 16)
       )
      )
      (i32.const 16)
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $11)
     (i32.const 12)
    )
    (i32.load
     (i32.add
      (get_local $17)
      (i32.const 12)
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $11)
     (i32.const 4)
    )
    (i32.load offset=4
     (get_local $17)
    )
   )
   (i32.store offset=16
    (get_local $17)
    (get_local $11)
   )
   (i32.store
    (get_local $11)
    (i32.load
     (get_local $17)
    )
   )
   (i32.store
    (i32.add
     (get_local $11)
     (i32.const 8)
    )
    (i32.load
     (get_local $10)
    )
   )
   (i32.store offset=20
    (get_local $17)
    (get_local $4)
   )
   (block $label$17
    (block $label$18
     (block $label$19
      (br_if $label$19
       (i32.ge_u
        (tee_local $11
         (i32.load
          (get_local $5)
         )
        )
        (i32.load
         (get_local $6)
        )
       )
      )
      (drop
       (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
        (get_local $11)
        (i32.add
         (get_local $17)
         (i32.const 16)
        )
        (i32.add
         (get_local $17)
         (i32.const 32)
        )
       )
      )
      (i32.store
       (get_local $5)
       (i32.add
        (i32.load
         (get_local $5)
        )
        (i32.const 40)
       )
      )
      (br_if $label$18
       (tee_local $11
        (i32.load offset=16
         (get_local $17)
        )
       )
      )
      (br $label$17)
     )
     (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311595436863162EEEEEvDpOT_
      (get_local $3)
      (i32.add
       (get_local $17)
       (i32.const 16)
      )
      (i32.add
       (get_local $17)
       (i32.const 32)
      )
     )
     (br_if $label$17
      (i32.eqz
       (tee_local $11
        (i32.load offset=16
         (get_local $17)
        )
       )
      )
     )
    )
    (i32.store offset=20
     (get_local $17)
     (get_local $11)
    )
    (call $_ZdlPv
     (get_local $11)
    )
   )
   (block $label$20
    (br_if $label$20
     (i32.eqz
      (tee_local $11
       (i32.load offset=32
        (get_local $17)
       )
      )
     )
    )
    (i32.store offset=36
     (get_local $17)
     (get_local $11)
    )
    (call $_ZdlPv
     (get_local $11)
    )
   )
   (br_if $label$0
    (i32.ne
     (tee_local $8
      (i32.add
       (get_local $8)
       (i32.const 1)
      )
     )
     (i32.const 32)
    )
   )
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $17)
    (i32.const 1072)
   )
   (i64.const 0)
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 17936)
  )
  (block $label$21
   (br_if $label$21
    (i32.eqz
     (tee_local $4
      (i32.load offset=1108
       (get_local $17)
      )
     )
    )
   )
   (block $label$22
    (block $label$23
     (br_if $label$23
      (i32.eq
       (tee_local $11
        (i32.load
         (tee_local $7
          (i32.add
           (get_local $17)
           (i32.const 1112)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $9
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $11
      (i32.add
       (get_local $11)
       (i32.const -24)
      )
     )
     (loop $label$24
      (block $label$25
       (br_if $label$25
        (i32.eqz
         (tee_local $10
          (i32.load
           (i32.add
            (get_local $11)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $11)
         (i32.const 16)
        )
        (get_local $10)
       )
       (call $_ZdlPv
        (get_local $10)
       )
      )
      (block $label$26
       (br_if $label$26
        (i32.eqz
         (tee_local $10
          (i32.load
           (get_local $11)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $11)
         (i32.const 4)
        )
        (get_local $10)
       )
       (call $_ZdlPv
        (get_local $10)
       )
      )
      (br_if $label$24
       (i32.ne
        (i32.add
         (tee_local $11
          (i32.add
           (get_local $11)
           (i32.const -40)
          )
         )
         (get_local $9)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $11
      (i32.load
       (i32.add
        (get_local $17)
        (i32.const 1108)
       )
      )
     )
     (br $label$22)
    )
    (set_local $11
     (get_local $4)
    )
   )
   (i32.store
    (get_local $7)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $11)
   )
  )
  (block $label$27
   (br_if $label$27
    (i32.eqz
     (tee_local $4
      (i32.load offset=1096
       (get_local $17)
      )
     )
    )
   )
   (block $label$28
    (block $label$29
     (br_if $label$29
      (i32.eq
       (tee_local $11
        (i32.load
         (tee_local $7
          (i32.add
           (get_local $17)
           (i32.const 1100)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $9
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $11
      (i32.add
       (get_local $11)
       (i32.const -24)
      )
     )
     (loop $label$30
      (block $label$31
       (br_if $label$31
        (i32.eqz
         (tee_local $10
          (i32.load
           (i32.add
            (get_local $11)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $11)
         (i32.const 16)
        )
        (get_local $10)
       )
       (call $_ZdlPv
        (get_local $10)
       )
      )
      (block $label$32
       (br_if $label$32
        (i32.eqz
         (tee_local $10
          (i32.load
           (get_local $11)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $11)
         (i32.const 4)
        )
        (get_local $10)
       )
       (call $_ZdlPv
        (get_local $10)
       )
      )
      (br_if $label$30
       (i32.ne
        (i32.add
         (tee_local $11
          (i32.add
           (get_local $11)
           (i32.const -40)
          )
         )
         (get_local $9)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $11
      (i32.load
       (i32.add
        (get_local $17)
        (i32.const 1096)
       )
      )
     )
     (br $label$28)
    )
    (set_local $11
     (get_local $4)
    )
   )
   (i32.store
    (get_local $7)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $11)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $17)
    (i32.const 1120)
   )
  )
 )
 (func $_ZN16test_transaction30send_transaction_expiring_lateEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i64)
  (local $12 i64)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 112)
    )
   )
  )
  (drop
   (call $read_action_data
    (i32.add
     (get_local $13)
     (i32.const 104)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=96
   (get_local $13)
   (i32.const 0)
  )
  (i64.store offset=88
   (get_local $13)
   (i64.const 0)
  )
  (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
   (i32.add
    (get_local $13)
    (i32.const 104)
   )
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eq
      (tee_local $7
       (i32.load offset=92
        (get_local $13)
       )
      )
      (i32.load offset=96
       (get_local $13)
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=105
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$0)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 1)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$2
   (block $label$3
    (br_if $label$3
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=106
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$2)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 2)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=107
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$4)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 3)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$6
   (block $label$7
    (br_if $label$7
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=108
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$6)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 4)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$8
   (block $label$9
    (br_if $label$9
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=109
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$8)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 5)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$10
   (block $label$11
    (br_if $label$11
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=110
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (tee_local $7
      (i32.add
       (i32.load offset=92
        (get_local $13)
       )
       (i32.const 1)
      )
     )
    )
    (br $label$10)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 6)
    )
   )
   (set_local $7
    (i32.load offset=92
     (get_local $13)
    )
   )
  )
  (block $label$12
   (block $label$13
    (br_if $label$13
     (i32.eq
      (get_local $7)
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 96)
       )
      )
     )
    )
    (i32.store8
     (get_local $7)
     (i32.load8_u offset=111
      (get_local $13)
     )
    )
    (i32.store offset=92
     (get_local $13)
     (i32.add
      (i32.load offset=92
       (get_local $13)
      )
      (i32.const 1)
     )
    )
    (br $label$12)
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE21__push_back_slow_pathIRKcEEvOT_
    (i32.add
     (get_local $13)
     (i32.const 88)
    )
    (i32.or
     (i32.add
      (get_local $13)
      (i32.const 104)
     )
     (i32.const 7)
    )
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 68)
   )
   (i32.const 0)
  )
  (i32.store16 offset=44
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=52
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=56
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=60
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=64
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=40
   (get_local $13)
   (i32.add
    (get_local $7)
    (i32.const 31536000)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 72)
   )
   (i32.const 0)
  )
  (i32.store offset=76
   (get_local $13)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 80)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 84)
   )
   (i32.const 0)
  )
  (set_local $5
   (i32.add
    (get_local $13)
    (i32.const 76)
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 416)
  )
  (set_local $10
   (i64.const 0)
  )
  (loop $label$14
   (block $label$15
    (block $label$16
     (block $label$17
      (block $label$18
       (block $label$19
        (br_if $label$19
         (i64.gt_u
          (get_local $9)
          (i64.const 6)
         )
        )
        (br_if $label$18
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$17)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$16
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$15)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $10
    (i64.or
     (get_local $11)
     (get_local $10)
    )
   )
   (br_if $label$14
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 9360)
  )
  (set_local $12
   (i64.const 0)
  )
  (loop $label$20
   (block $label$21
    (block $label$22
     (block $label$23
      (block $label$24
       (block $label$25
        (br_if $label$25
         (i64.gt_u
          (get_local $9)
          (i64.const 5)
         )
        )
        (br_if $label$24
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$23)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$22
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$21)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $12
    (i64.or
     (get_local $11)
     (get_local $12)
    )
   )
   (br_if $label$20
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $13)
   (get_local $12)
  )
  (i64.store offset=8
   (get_local $13)
   (get_local $10)
  )
  (i32.store
   (i32.add
    (tee_local $7
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $13)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $13)
   )
  )
  (i32.store offset=24
   (get_local $13)
   (get_local $7)
  )
  (i32.store
   (get_local $7)
   (i32.load offset=8
    (get_local $13)
   )
  )
  (i32.store offset=32
   (get_local $13)
   (tee_local $3
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $13)
   )
  )
  (i32.store offset=28
   (get_local $13)
   (get_local $3)
  )
  (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy9781311597322538353EEEEEvDpOT_
   (get_local $5)
   (i32.add
    (get_local $13)
    (i32.const 24)
   )
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
  )
  (block $label$26
   (br_if $label$26
    (i32.eqz
     (tee_local $7
      (i32.load offset=24
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $13)
    (i32.const 40)
   )
   (i64.const 0)
   (get_local $0)
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 18000)
  )
  (block $label$27
   (br_if $label$27
    (i32.eqz
     (tee_local $4
      (i32.load offset=76
       (get_local $13)
      )
     )
    )
   )
   (block $label$28
    (block $label$29
     (br_if $label$29
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 80)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$30
      (block $label$31
       (br_if $label$31
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$32
       (br_if $label$32
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$30
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 76)
       )
      )
     )
     (br $label$28)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$33
   (br_if $label$33
    (i32.eqz
     (tee_local $4
      (i32.load offset=64
       (get_local $13)
      )
     )
    )
   )
   (block $label$34
    (block $label$35
     (br_if $label$35
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 68)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$36
      (block $label$37
       (br_if $label$37
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$38
       (br_if $label$38
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$36
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 64)
       )
      )
     )
     (br $label$34)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$39
   (br_if $label$39
    (i32.eqz
     (tee_local $7
      (i32.load offset=88
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=92
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 112)
   )
  )
 )
 (func $_ZN16test_transaction14deferred_printEv
  (call $prints
   (i32.const 18064)
  )
 )
 (func $_ZN16test_transaction25send_deferred_transactionEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i64)
  (local $12 i64)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (set_local $7
   (call $now)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 76)
   )
   (i32.const 0)
  )
  (i32.store16 offset=52
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=60
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=64
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=68
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=72
   (get_local $13)
   (i32.const 0)
  )
  (i32.store offset=48
   (get_local $13)
   (i32.add
    (get_local $7)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 80)
   )
   (i32.const 0)
  )
  (i32.store offset=84
   (get_local $13)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 88)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 92)
   )
   (i32.const 0)
  )
  (i32.store offset=40
   (get_local $13)
   (i32.const 0)
  )
  (set_local $9
   (i64.const 0)
  )
  (i64.store offset=32
   (get_local $13)
   (i64.const 0)
  )
  (set_local $5
   (i32.add
    (get_local $13)
    (i32.const 84)
   )
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 416)
  )
  (set_local $10
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $9)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $10
    (i64.or
     (get_local $11)
     (get_local $10)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $9
   (i64.const 0)
  )
  (set_local $8
   (i64.const 59)
  )
  (set_local $7
   (i32.const 9360)
  )
  (set_local $12
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $9)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $7)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $11
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $9)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $11
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $11
     (i64.shl
      (i64.and
       (get_local $11)
       (i64.const 31)
      )
      (i64.and
       (get_local $8)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 1)
    )
   )
   (set_local $9
    (i64.add
     (get_local $9)
     (i64.const 1)
    )
   )
   (set_local $12
    (i64.or
     (get_local $11)
     (get_local $12)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $8
      (i64.add
       (get_local $8)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=8
   (get_local $13)
   (get_local $12)
  )
  (i64.store
   (get_local $13)
   (get_local $10)
  )
  (i32.store
   (i32.add
    (tee_local $7
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (get_local $13)
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 4)
   )
   (i32.load offset=4
    (get_local $13)
   )
  )
  (i32.store offset=16
   (get_local $13)
   (get_local $7)
  )
  (i32.store
   (get_local $7)
   (i32.load
    (get_local $13)
   )
  )
  (i32.store offset=24
   (get_local $13)
   (tee_local $3
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (i32.load offset=8
    (get_local $13)
   )
  )
  (i32.store offset=20
   (get_local $13)
   (get_local $3)
  )
  (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy17750730572681658536EEEEEvDpOT_
   (get_local $5)
   (i32.add
    (get_local $13)
    (i32.const 16)
   )
   (i32.add
    (get_local $13)
    (i32.const 32)
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $7
      (i32.load offset=16
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=20
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $13)
    (i32.const 68)
   )
   (i32.const 2)
  )
  (call $_ZNK5eosio11transaction4sendEyy
   (i32.add
    (get_local $13)
    (i32.const 48)
   )
   (i64.const -1)
   (get_local $0)
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $7
      (i32.load offset=32
       (get_local $13)
      )
     )
    )
   )
   (i32.store offset=36
    (get_local $13)
    (get_local $7)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $4
      (i32.load offset=84
       (get_local $13)
      )
     )
    )
   )
   (block $label$15
    (block $label$16
     (br_if $label$16
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 88)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$17
      (block $label$18
       (br_if $label$18
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$19
       (br_if $label$19
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$17
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 84)
       )
      )
     )
     (br $label$15)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (block $label$20
   (br_if $label$20
    (i32.eqz
     (tee_local $4
      (i32.load offset=72
       (get_local $13)
      )
     )
    )
   )
   (block $label$21
    (block $label$22
     (br_if $label$22
      (i32.eq
       (tee_local $7
        (i32.load
         (tee_local $6
          (i32.add
           (get_local $13)
           (i32.const 76)
          )
         )
        )
       )
       (get_local $4)
      )
     )
     (set_local $5
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const -24)
      )
     )
     (loop $label$23
      (block $label$24
       (br_if $label$24
        (i32.eqz
         (tee_local $3
          (i32.load
           (i32.add
            (get_local $7)
            (i32.const 12)
           )
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (block $label$25
       (br_if $label$25
        (i32.eqz
         (tee_local $3
          (i32.load
           (get_local $7)
          )
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
        (get_local $3)
       )
       (call $_ZdlPv
        (get_local $3)
       )
      )
      (br_if $label$23
       (i32.ne
        (i32.add
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const -40)
          )
         )
         (get_local $5)
        )
        (i32.const -24)
       )
      )
     )
     (set_local $7
      (i32.load
       (i32.add
        (get_local $13)
        (i32.const 72)
       )
      )
     )
     (br $label$21)
    )
    (set_local $7
     (get_local $4)
    )
   )
   (i32.store
    (get_local $6)
    (get_local $4)
   )
   (call $_ZdlPv
    (get_local $7)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 96)
   )
  )
 )
 (func $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJNS0_INS1_16permission_levelENS3_IS7_EEEER18test_action_actionILy14605617063041957888ELy17750730572681658536EEEEEvDpOT_ (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.ge_u
      (tee_local $6
       (i32.add
        (tee_local $9
         (i32.div_s
          (i32.sub
           (i32.load offset=4
            (get_local $0)
           )
           (tee_local $8
            (i32.load
             (get_local $0)
            )
           )
          )
          (i32.const 40)
         )
        )
        (i32.const 1)
       )
      )
      (i32.const 107374183)
     )
    )
    (set_local $7
     (i32.const 107374182)
    )
    (block $label$2
     (block $label$3
      (br_if $label$3
       (i32.gt_u
        (tee_local $8
         (i32.div_s
          (i32.sub
           (i32.load offset=8
            (get_local $0)
           )
           (get_local $8)
          )
          (i32.const 40)
         )
        )
        (i32.const 53687090)
       )
      )
      (br_if $label$2
       (i32.eqz
        (tee_local $7
         (select
          (get_local $6)
          (tee_local $7
           (i32.shl
            (get_local $8)
            (i32.const 1)
           )
          )
          (i32.lt_u
           (get_local $7)
           (get_local $6)
          )
         )
        )
       )
      )
     )
     (set_local $8
      (call $_Znwj
       (i32.mul
        (get_local $7)
        (i32.const 40)
       )
      )
     )
     (br $label$0)
    )
    (set_local $7
     (i32.const 0)
    )
    (set_local $8
     (i32.const 0)
    )
    (br $label$0)
   )
   (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
    (get_local $0)
   )
   (unreachable)
  )
  (set_local $3
   (i32.add
    (get_local $8)
    (i32.mul
     (get_local $7)
     (i32.const 40)
    )
   )
  )
  (set_local $4
   (i32.add
    (tee_local $8
     (call $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy17750730572681658536EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
      (tee_local $9
       (i32.add
        (get_local $8)
        (i32.mul
         (get_local $9)
         (i32.const 40)
        )
       )
      )
      (get_local $1)
      (get_local $2)
     )
    )
    (i32.const 40)
   )
  )
  (block $label$4
   (block $label$5
    (br_if $label$5
     (i32.eq
      (tee_local $1
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (tee_local $7
       (i32.load
        (get_local $0)
       )
      )
     )
    )
    (set_local $5
     (i32.sub
      (i32.const 0)
      (get_local $7)
     )
    )
    (set_local $7
     (i32.add
      (get_local $1)
      (i32.const -20)
     )
    )
    (loop $label$6
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -32)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -12)
       )
      )
     )
     (i64.store
      (i32.add
       (get_local $8)
       (i32.const -40)
      )
      (i64.load
       (i32.add
        (get_local $7)
        (i32.const -20)
       )
      )
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -24)
       )
      )
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -16)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const -4)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -20)
      )
      (i32.load
       (get_local $7)
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $1
        (i32.add
         (get_local $7)
         (i32.const 4)
        )
       )
      )
     )
     (i32.store
      (get_local $1)
      (i32.const 0)
     )
     (i64.store align=4
      (tee_local $1
       (i32.add
        (get_local $8)
        (i32.const -12)
       )
      )
      (i64.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (i32.store
      (tee_local $2
       (i32.add
        (get_local $8)
        (i32.const -4)
       )
      )
      (i32.const 0)
     )
     (i32.store
      (get_local $1)
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $7)
         (i32.const 8)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $8)
       (i32.const -8)
      )
      (i32.load
       (i32.add
        (get_local $7)
        (i32.const 12)
       )
      )
     )
     (i32.store
      (get_local $2)
      (i32.load
       (tee_local $8
        (i32.add
         (get_local $7)
         (i32.const 16)
        )
       )
      )
     )
     (i32.store
      (get_local $8)
      (i32.const 0)
     )
     (i64.store align=4
      (get_local $6)
      (i64.const 0)
     )
     (set_local $8
      (tee_local $9
       (i32.add
        (get_local $9)
        (i32.const -40)
       )
      )
     )
     (br_if $label$6
      (i32.ne
       (i32.add
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -40)
         )
        )
        (get_local $5)
       )
       (i32.const -20)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
    (br $label$4)
   )
   (set_local $1
    (get_local $7)
   )
  )
  (i32.store
   (get_local $0)
   (get_local $9)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $3)
  )
  (block $label$7
   (br_if $label$7
    (i32.eq
     (get_local $7)
     (get_local $1)
    )
   )
   (set_local $9
    (i32.sub
     (i32.const 0)
     (get_local $1)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const -24)
    )
   )
   (loop $label$8
    (block $label$9
     (br_if $label$9
      (i32.eqz
       (tee_local $8
        (i32.load
         (i32.add
          (get_local $7)
          (i32.const 12)
         )
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 16)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (block $label$10
     (br_if $label$10
      (i32.eqz
       (tee_local $8
        (i32.load
         (get_local $7)
        )
       )
      )
     )
     (i32.store
      (i32.add
       (get_local $7)
       (i32.const 4)
      )
      (get_local $8)
     )
     (call $_ZdlPv
      (get_local $8)
     )
    )
    (br_if $label$8
     (i32.ne
      (i32.add
       (tee_local $7
        (i32.add
         (get_local $7)
         (i32.const -40)
        )
       )
       (get_local $9)
      )
      (i32.const -24)
     )
    )
   )
  )
  (block $label$11
   (br_if $label$11
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy14605617063041957888ELy17750730572681658536EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -696013501027893080)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction27cancel_deferred_transactionEv
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -1)
  )
  (call $cancel_deferred
   (get_local $0)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
 )
 (func $_ZN16test_transaction14send_cf_actionEv
  (local $0 i32)
  (local $1 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $1
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 64)
    )
   )
  )
  (i64.store
   (i32.add
    (get_local $1)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (i32.add
    (get_local $1)
    (i32.const 40)
   )
   (i64.const 0)
  )
  (i64.store offset=24
   (get_local $1)
   (i64.const 0)
  )
  (i64.store offset=8
   (get_local $1)
   (i64.const 5666987383162142720)
  )
  (i64.store offset=16
   (get_local $1)
   (i64.const 6256973794934521856)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 18096)
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $1)
    (i32.const 48)
   )
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
  )
  (call $send_context_free_inline
   (tee_local $0
    (i32.load offset=48
     (get_local $1)
    )
   )
   (i32.sub
    (i32.load offset=52
     (get_local $1)
    )
    (get_local $0)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (tee_local $0
      (i32.load offset=48
       (get_local $1)
      )
     )
    )
   )
   (i32.store offset=52
    (get_local $1)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eqz
     (tee_local $0
      (i32.load offset=36
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 40)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (tee_local $0
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 24)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 28)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $1)
    (i32.const 64)
   )
  )
 )
 (func $_ZN16test_transaction19send_cf_action_failEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 96)
    )
   )
  )
  (i32.store offset=88
   (get_local $7)
   (i32.const 0)
  )
  (set_local $3
   (i64.const 0)
  )
  (i64.store offset=80
   (get_local $7)
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 18144)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 4)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 9360)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $5)
     (get_local $6)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=16
   (get_local $7)
   (get_local $6)
  )
  (i64.store offset=8
   (get_local $7)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (tee_local $1
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $7)
      (i32.const 8)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 4)
   )
   (i32.load offset=12
    (get_local $7)
   )
  )
  (i32.store offset=24
   (get_local $7)
   (get_local $1)
  )
  (i32.store
   (get_local $1)
   (i32.load offset=8
    (get_local $7)
   )
  )
  (i32.store offset=32
   (get_local $7)
   (tee_local $0
    (i32.add
     (get_local $1)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $1)
    (i32.const 8)
   )
   (i32.load offset=16
    (get_local $7)
   )
  )
  (i32.store offset=28
   (get_local $7)
   (get_local $0)
  )
  (set_local $1
   (call $_ZN5eosio6actionC2I18test_action_actionILy5666987383162142720ELy6256973794934521856EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $7)
     (i32.const 40)
    )
    (i32.add
     (get_local $7)
     (i32.const 24)
    )
    (i32.add
     (get_local $7)
     (i32.const 80)
    )
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $0
      (i32.load offset=24
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=28
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load
     (i32.add
      (get_local $1)
      (i32.const 20)
     )
    )
    (i32.load offset=16
     (get_local $1)
    )
   )
   (i32.const 18096)
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $7)
    (i32.const 8)
   )
   (get_local $1)
  )
  (call $send_context_free_inline
   (tee_local $0
    (i32.load offset=8
     (get_local $7)
    )
   )
   (i32.sub
    (i32.load offset=12
     (get_local $7)
    )
    (get_local $0)
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $0
      (i32.load offset=8
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=12
    (get_local $7)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $eosio_assert
   (i32.const 0)
   (i32.const 18160)
  )
  (block $label$14
   (br_if $label$14
    (i32.eqz
     (tee_local $0
      (i32.load offset=28
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 32)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$15
   (br_if $label$15
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 20)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $1
      (i32.load offset=80
       (get_local $7)
      )
     )
    )
   )
   (i32.store offset=84
    (get_local $7)
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 96)
   )
  )
 )
 (func $_ZN5eosio6actionC2I18test_action_actionILy5666987383162142720ELy6256973794934521856EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $6
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const 5666987383162142720)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const 6256973794934521856)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $6)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $7)
   (i32.const 0)
  )
  (i64.store
   (get_local $7)
   (i64.const 0)
  )
  (set_local $5
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.eq
     (tee_local $1
      (i32.load
       (get_local $2)
      )
     )
     (tee_local $4
      (i32.load offset=4
       (get_local $2)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (tee_local $3
      (i32.sub
       (get_local $4)
       (get_local $1)
      )
     )
    )
   )
   (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
    (get_local $7)
    (get_local $3)
   )
   (set_local $4
    (i32.load
     (i32.add
      (get_local $2)
      (i32.const 4)
     )
    )
   )
   (set_local $1
    (i32.load
     (get_local $2)
    )
   )
   (set_local $5
    (i32.load offset=4
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (get_local $1)
     (get_local $4)
    )
   )
   (loop $label$2
    (i32.store8 offset=15
     (get_local $7)
     (i32.load8_u
      (get_local $1)
     )
    )
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (get_local $5)
       (get_local $6)
      )
      (i32.const 0)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (get_local $6)
      (i32.add
       (get_local $7)
       (i32.const 15)
      )
      (i32.const 1)
     )
    )
    (set_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $4)
      (tee_local $1
       (i32.add
        (get_local $1)
        (i32.const 1)
       )
      )
     )
    )
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $1
      (i32.load
       (tee_local $6
        (i32.add
         (get_local $0)
         (i32.const 28)
        )
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (get_local $6)
    (i64.const 0)
   )
  )
  (i64.store align=4
   (get_local $6)
   (i64.load
    (get_local $7)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $7)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction18read_inline_actionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i64)
  (local $8 i64)
  (local $9 i32)
  (local $10 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $10
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 192)
    )
   )
  )
  (call $eosio_assert
   (i32.eq
    (call $get_action
     (i32.const 3)
     (i32.const 0)
     (i32.add
      (get_local $10)
      (i32.const 128)
     )
     (i32.const 64)
    )
    (i32.const -1)
   )
   (i32.const 18224)
  )
  (i32.store8
   (i32.add
    (get_local $10)
    (i32.const 124)
   )
   (i32.load8_u offset=18268
    (i32.const 0)
   )
  )
  (i32.store
   (i32.add
    (get_local $10)
    (i32.const 120)
   )
   (i32.load offset=18264 align=1
    (i32.const 0)
   )
  )
  (i64.store offset=112
   (get_local $10)
   (i64.load offset=18256 align=1
    (i32.const 0)
   )
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $4
   (i64.const 59)
  )
  (set_local $3
   (i32.const 416)
  )
  (set_local $6
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $5)
          (i64.const 6)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $3)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $7
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $5)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $7
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $7
     (i64.shl
      (i64.and
       (get_local $7)
       (i64.const 31)
      )
      (i64.and
       (get_local $4)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $3
    (i32.add
     (get_local $3)
     (i32.const 1)
    )
   )
   (set_local $5
    (i64.add
     (get_local $5)
     (i64.const 1)
    )
   )
   (set_local $6
    (i64.or
     (get_local $7)
     (get_local $6)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $4
      (i64.add
       (get_local $4)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $4
   (i64.const 59)
  )
  (set_local $3
   (i32.const 9360)
  )
  (set_local $8
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $5)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $3)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 165)
         )
        )
        (br $label$9)
       )
       (set_local $7
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $5)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $7
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $7
     (i64.shl
      (i64.and
       (get_local $7)
       (i64.const 31)
      )
      (i64.and
       (get_local $4)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $3
    (i32.add
     (get_local $3)
     (i32.const 1)
    )
   )
   (set_local $5
    (i64.add
     (get_local $5)
     (i64.const 1)
    )
   )
   (set_local $8
    (i64.or
     (get_local $7)
     (get_local $8)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $4
      (i64.add
       (get_local $4)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (i64.store offset=40
   (get_local $10)
   (get_local $8)
  )
  (i64.store offset=32
   (get_local $10)
   (get_local $6)
  )
  (i32.store
   (i32.add
    (tee_local $3
     (call $_Znwj
      (i32.const 16)
     )
    )
    (i32.const 12)
   )
   (i32.load
    (i32.add
     (i32.add
      (get_local $10)
      (i32.const 32)
     )
     (i32.const 12)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $3)
    (i32.const 4)
   )
   (i32.load offset=36
    (get_local $10)
   )
  )
  (i32.store
   (get_local $10)
   (get_local $3)
  )
  (i32.store
   (get_local $3)
   (i32.load offset=32
    (get_local $10)
   )
  )
  (i32.store offset=8
   (get_local $10)
   (tee_local $0
    (i32.add
     (get_local $3)
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.add
    (get_local $3)
    (i32.const 8)
   )
   (i32.load offset=40
    (get_local $10)
   )
  )
  (i32.store offset=4
   (get_local $10)
   (get_local $0)
  )
  (set_local $3
   (call $_ZN5eosio6actionC2I17test_dummy_actionILy14605617063041957888ELy9781311596421349198EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_
    (i32.add
     (get_local $10)
     (i32.const 72)
    )
    (get_local $10)
    (i32.add
     (get_local $10)
     (i32.const 112)
    )
   )
  )
  (block $label$12
   (br_if $label$12
    (i32.eqz
     (tee_local $0
      (i32.load
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=4
    (get_local $10)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $10)
    (i32.const 32)
   )
   (get_local $3)
  )
  (call $send_inline
   (tee_local $0
    (i32.load offset=32
     (get_local $10)
    )
   )
   (i32.sub
    (i32.load offset=36
     (get_local $10)
    )
    (get_local $0)
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (tee_local $0
      (i32.load offset=32
       (get_local $10)
      )
     )
    )
   )
   (i32.store offset=36
    (get_local $10)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (set_local $9
   (i32.const 0)
  )
  (call $eosio_assert
   (i32.ne
    (tee_local $0
     (call $get_action
      (i32.const 3)
      (i32.const 0)
      (i32.add
       (get_local $10)
       (i32.const 128)
      )
      (i32.const 64)
     )
    )
    (i32.const -1)
   )
   (i32.const 18272)
  )
  (i64.store
   (i32.add
    (get_local $10)
    (i32.const 56)
   )
   (i64.const 0)
  )
  (i64.store
   (tee_local $2
    (i32.add
     (get_local $10)
     (i32.const 64)
    )
   )
   (i64.const 0)
  )
  (i64.store offset=48
   (get_local $10)
   (i64.const 0)
  )
  (i32.store offset=24
   (get_local $10)
   (tee_local $1
    (i32.add
     (get_local $0)
     (i32.add
      (get_local $10)
      (i32.const 128)
     )
    )
   )
  )
  (i32.store offset=16
   (get_local $10)
   (i32.add
    (get_local $10)
    (i32.const 128)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (get_local $0)
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $10)
     (i32.const 32)
    )
    (i32.add
     (get_local $10)
     (i32.const 128)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (get_local $1)
     (tee_local $0
      (i32.or
       (i32.add
        (get_local $10)
        (i32.const 128)
       )
       (i32.const 8)
      )
     )
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (i32.add
      (get_local $10)
      (i32.const 32)
     )
     (i32.const 8)
    )
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store offset=20
   (get_local $10)
   (i32.add
    (i32.add
     (get_local $10)
     (i32.const 128)
    )
    (i32.const 16)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
    (i32.add
     (get_local $10)
     (i32.const 16)
    )
    (i32.add
     (i32.add
      (get_local $10)
      (i32.const 32)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__16vectorIcNS6_9allocatorIcEEEE
    (i32.add
     (get_local $10)
     (i32.const 16)
    )
    (tee_local $1
     (i32.add
      (get_local $10)
      (i32.const 60)
     )
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=40
     (get_local $10)
    )
    (i64.const -8665432477288202418)
   )
   (i32.const 688)
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=32
     (get_local $10)
    )
    (i64.const -3841127010667593728)
   )
   (i32.const 704)
  )
  (call $eosio_assert
   (i32.ne
    (tee_local $2
     (i32.sub
      (i32.load
       (get_local $2)
      )
      (tee_local $0
       (i32.load offset=60
        (get_local $10)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $10)
    (get_local $0)
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $2)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.or
     (get_local $10)
     (i32.const 1)
    )
    (i32.add
     (get_local $0)
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $2)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $10)
     (i32.const 9)
    )
    (i32.add
     (get_local $0)
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
  (block $label$14
   (br_if $label$14
    (i32.ne
     (i32.load8_u
      (get_local $10)
     )
     (i32.const 1)
    )
   )
   (br_if $label$14
    (i64.ne
     (i64.load offset=1 align=1
      (get_local $10)
     )
     (i64.const 2)
    )
   )
   (set_local $9
    (i32.eq
     (i32.load align=1
      (i32.add
       (get_local $10)
       (i32.const 9)
      )
     )
     (i32.const 3)
    )
   )
  )
  (call $eosio_assert
   (get_local $9)
   (i32.const 18304)
  )
  (call $eosio_assert
   (i32.eq
    (call $get_action
     (i32.const 3)
     (i32.const 1)
     (i32.add
      (get_local $10)
      (i32.const 128)
     )
     (i32.const 64)
    )
    (i32.const -1)
   )
   (i32.const 18320)
  )
  (block $label$15
   (br_if $label$15
    (i32.eqz
     (tee_local $0
      (i32.load
       (get_local $1)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $10)
     (i32.const 64)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$16
   (br_if $label$16
    (i32.eqz
     (tee_local $0
      (i32.load
       (i32.add
        (get_local $10)
        (i32.const 48)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $10)
     (i32.const 52)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$17
   (br_if $label$17
    (i32.eqz
     (tee_local $0
      (i32.load offset=28
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $3)
     (i32.const 32)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$18
   (br_if $label$18
    (i32.eqz
     (tee_local $0
      (i32.load offset=16
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $3)
     (i32.const 20)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $10)
    (i32.const 192)
   )
  )
 )
 (func $_ZN5eosio6actionC2I17test_dummy_actionILy14605617063041957888ELy9781311596421349198EEEEONSt3__16vectorINS_16permission_levelENS4_9allocatorIS6_EEEERKT_ (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $5
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $4
    (i32.add
     (get_local $0)
     (i32.const 24)
    )
   )
   (i64.const 0)
  )
  (i64.store align=4
   (tee_local $3
    (i32.add
     (get_local $0)
     (i32.const 32)
    )
   )
   (i64.const 0)
  )
  (i64.store
   (get_local $0)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=8
   (get_local $0)
   (i64.const -8665432477288202418)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.load
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $4)
   (i32.load offset=8
    (get_local $1)
   )
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i64.store align=4
   (get_local $1)
   (i64.const 0)
  )
  (i32.store offset=8
   (get_local $5)
   (i32.const 0)
  )
  (i64.store
   (get_local $5)
   (i64.const 0)
  )
  (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
   (get_local $5)
   (i32.const 13)
  )
  (call $eosio_assert
   (i32.gt_s
    (tee_local $4
     (i32.sub
      (i32.load offset=4
       (get_local $5)
      )
      (tee_local $1
       (i32.load
        (get_local $5)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $1)
    (get_local $2)
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $4)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
    (i32.add
     (get_local $2)
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $4)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 9)
    )
    (i32.add
     (get_local $2)
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (tee_local $1
      (i32.load offset=28
       (get_local $0)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (get_local $1)
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 36)
    )
    (i32.const 0)
   )
   (i64.store align=4
    (i32.add
     (get_local $0)
     (i32.const 28)
    )
    (i64.const 0)
   )
  )
  (i64.store align=4
   (i32.add
    (get_local $0)
    (i32.const 28)
   )
   (i64.load
    (get_local $5)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 36)
   )
   (i32.load
    (i32.add
     (get_local $5)
     (i32.const 8)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $5)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i32)
  (local $7 i32)
  (set_local $7
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $7
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.le_u
       (tee_local $4
        (i32.wrap/i64
         (get_local $5)
        )
       )
       (tee_local $6
        (i32.shr_s
         (i32.sub
          (tee_local $2
           (i32.load offset=4
            (get_local $1)
           )
          )
          (tee_local $7
           (i32.load
            (get_local $1)
           )
          )
         )
         (i32.const 4)
        )
       )
      )
     )
     (call $_ZNSt3__16vectorIN5eosio16permission_levelENS_9allocatorIS2_EEE8__appendEj
      (get_local $1)
      (i32.sub
       (get_local $4)
       (get_local $6)
      )
     )
     (br_if $label$2
      (i32.ne
       (tee_local $7
        (i32.load
         (get_local $1)
        )
       )
       (tee_local $2
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
      )
     )
     (br $label$1)
    )
    (block $label$4
     (br_if $label$4
      (i32.ge_u
       (get_local $4)
       (get_local $6)
      )
     )
     (i32.store
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
      (tee_local $2
       (i32.add
        (get_local $7)
        (i32.shl
         (get_local $4)
         (i32.const 4)
        )
       )
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (get_local $7)
      (get_local $2)
     )
    )
   )
   (set_local $6
    (i32.load
     (tee_local $4
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
   )
   (loop $label$5
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (tee_local $3
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
        )
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (get_local $7)
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $6
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (get_local $3)
       )
       (get_local $6)
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $6
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (br_if $label$5
     (i32.ne
      (tee_local $7
       (i32.add
        (get_local $7)
        (i32.const 16)
       )
      )
      (get_local $2)
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__16vectorIcNS6_9allocatorIcEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (set_local $5
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $7
   (i32.const 0)
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $5)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $5
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $5
     (i32.add
      (get_local $5)
      (i32.const 1)
     )
    )
   )
   (set_local $6
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $7
        (i32.and
         (get_local $7)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $6)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (br_if $label$2
     (i32.le_u
      (tee_local $3
       (i32.wrap/i64
        (get_local $6)
       )
      )
      (tee_local $2
       (i32.sub
        (tee_local $7
         (i32.load offset=4
          (get_local $1)
         )
        )
        (tee_local $4
         (i32.load
          (get_local $1)
         )
        )
       )
      )
     )
    )
    (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
     (get_local $1)
     (i32.sub
      (get_local $3)
      (get_local $2)
     )
    )
    (set_local $5
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (set_local $7
     (i32.load
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
     )
    )
    (set_local $4
     (i32.load
      (get_local $1)
     )
    )
    (br $label$1)
   )
   (br_if $label$1
    (i32.ge_u
     (get_local $3)
     (get_local $2)
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
    (tee_local $7
     (i32.add
      (get_local $4)
      (get_local $3)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.ge_u
    (i32.sub
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
     )
     (get_local $5)
    )
    (tee_local $5
     (i32.sub
      (get_local $7)
      (get_local $4)
     )
    )
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $4)
    (i32.load
     (tee_local $7
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
    (get_local $5)
   )
  )
  (i32.store
   (get_local $7)
   (i32.add
    (i32.load
     (get_local $7)
    )
    (get_local $5)
   )
  )
  (get_local $0)
 )
 (func $_ZN16test_transaction21read_inline_cf_actionEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 192)
    )
   )
  )
  (set_local $3
   (i32.const 0)
  )
  (call $eosio_assert
   (i32.eq
    (call $get_action
     (i32.const 2)
     (i32.const 0)
     (i32.add
      (get_local $4)
      (i32.const 128)
     )
     (i32.const 64)
    )
    (i32.const -1)
   )
   (i32.const 18224)
  )
  (i32.store8
   (i32.add
    (get_local $4)
    (i32.const 124)
   )
   (i32.load8_u offset=18364
    (i32.const 0)
   )
  )
  (i32.store
   (i32.add
    (i32.add
     (get_local $4)
     (i32.const 112)
    )
    (i32.const 8)
   )
   (i32.load offset=18360 align=1
    (i32.const 0)
   )
  )
  (i64.store offset=112
   (get_local $4)
   (i64.load offset=18352 align=1
    (i32.const 0)
   )
  )
  (i32.store
   (i32.add
    (i32.add
     (get_local $4)
     (i32.const 72)
    )
    (i32.const 24)
   )
   (i32.const 0)
  )
  (i64.store offset=88
   (get_local $4)
   (i64.const 0)
  )
  (i64.store offset=72
   (get_local $4)
   (i64.const -3841127010667593728)
  )
  (i64.store offset=80
   (get_local $4)
   (i64.const -8665432478235101900)
  )
  (i32.store offset=40
   (get_local $4)
   (i32.const 0)
  )
  (i64.store offset=32
   (get_local $4)
   (i64.const 0)
  )
  (call $_ZNSt3__16vectorIcNS_9allocatorIcEEE8__appendEj
   (i32.add
    (get_local $4)
    (i32.const 32)
   )
   (i32.const 13)
  )
  (call $eosio_assert
   (i32.gt_s
    (tee_local $1
     (i32.sub
      (i32.load offset=36
       (get_local $4)
      )
      (tee_local $0
       (i32.load offset=32
        (get_local $4)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (i32.add
     (get_local $4)
     (i32.const 112)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $1)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 1)
    )
    (i32.or
     (i32.add
      (get_local $4)
      (i32.const 112)
     )
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.add
     (get_local $1)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 9)
    )
    (i32.add
     (i32.add
      (get_local $4)
      (i32.const 112)
     )
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
  (i32.store
   (i32.add
    (get_local $4)
    (i32.const 108)
   )
   (i32.load offset=40
    (get_local $4)
   )
  )
  (i64.store offset=100 align=4
   (get_local $4)
   (i64.load offset=32
    (get_local $4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 18096)
  )
  (call $_ZN5eosio4packINS_6actionEEENSt3__16vectorIcNS2_9allocatorIcEEEERKT_
   (i32.add
    (get_local $4)
    (i32.const 32)
   )
   (i32.add
    (get_local $4)
    (i32.const 72)
   )
  )
  (call $send_context_free_inline
   (tee_local $0
    (i32.load offset=32
     (get_local $4)
    )
   )
   (i32.sub
    (i32.load offset=36
     (get_local $4)
    )
    (get_local $0)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (tee_local $0
      (i32.load offset=32
       (get_local $4)
      )
     )
    )
   )
   (i32.store offset=36
    (get_local $4)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (call $eosio_assert
   (i32.ne
    (tee_local $0
     (call $get_action
      (i32.const 2)
      (i32.const 0)
      (i32.add
       (get_local $4)
       (i32.const 128)
      )
      (i32.const 64)
     )
    )
    (i32.const -1)
   )
   (i32.const 18272)
  )
  (i64.store
   (i32.add
    (i32.add
     (get_local $4)
     (i32.const 32)
    )
    (i32.const 24)
   )
   (i64.const 0)
  )
  (i64.store
   (tee_local $1
    (i32.add
     (get_local $4)
     (i32.const 64)
    )
   )
   (i64.const 0)
  )
  (i64.store offset=48
   (get_local $4)
   (i64.const 0)
  )
  (i32.store offset=24
   (get_local $4)
   (tee_local $2
    (i32.add
     (get_local $0)
     (i32.add
      (get_local $4)
      (i32.const 128)
     )
    )
   )
  )
  (i32.store offset=16
   (get_local $4)
   (i32.add
    (get_local $4)
    (i32.const 128)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (get_local $0)
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $4)
     (i32.const 32)
    )
    (i32.add
     (get_local $4)
     (i32.const 128)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (get_local $2)
     (tee_local $0
      (i32.or
       (i32.add
        (get_local $4)
        (i32.const 128)
       )
       (i32.const 8)
      )
     )
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (i32.add
      (get_local $4)
      (i32.const 32)
     )
     (i32.const 8)
    )
    (get_local $0)
    (i32.const 8)
   )
  )
  (i32.store offset=20
   (get_local $4)
   (i32.add
    (i32.add
     (get_local $4)
     (i32.const 128)
    )
    (i32.const 16)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEENS_16permission_levelEEERT_S6_RNSt3__16vectorIT0_NS7_9allocatorIS9_EEEE
    (i32.add
     (get_local $4)
     (i32.const 16)
    )
    (i32.add
     (i32.add
      (get_local $4)
      (i32.const 32)
     )
     (i32.const 16)
    )
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__16vectorIcNS6_9allocatorIcEEEE
    (i32.add
     (get_local $4)
     (i32.const 16)
    )
    (tee_local $2
     (i32.add
      (get_local $4)
      (i32.const 60)
     )
    )
   )
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=40
     (get_local $4)
    )
    (i64.const -8665432478235101900)
   )
   (i32.const 688)
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=32
     (get_local $4)
    )
    (i64.const -3841127010667593728)
   )
   (i32.const 704)
  )
  (call $eosio_assert
   (i32.ne
    (tee_local $1
     (i32.sub
      (i32.load
       (get_local $1)
      )
      (tee_local $0
       (i32.load offset=60
        (get_local $4)
       )
      )
     )
    )
    (i32.const 0)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $4)
    (get_local $0)
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $1)
     (i32.const -1)
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.or
     (get_local $4)
     (i32.const 1)
    )
    (i32.add
     (get_local $0)
     (i32.const 1)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.add
     (get_local $1)
     (i32.const -9)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $4)
     (i32.const 9)
    )
    (i32.add
     (get_local $0)
     (i32.const 9)
    )
    (i32.const 4)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.ne
     (i32.load8_u
      (get_local $4)
     )
     (i32.const 1)
    )
   )
   (br_if $label$1
    (i64.ne
     (i64.load offset=1 align=1
      (get_local $4)
     )
     (i64.const 2)
    )
   )
   (set_local $3
    (i32.eq
     (i32.load align=1
      (i32.add
       (get_local $4)
       (i32.const 9)
      )
     )
     (i32.const 3)
    )
   )
  )
  (call $eosio_assert
   (get_local $3)
   (i32.const 18304)
  )
  (call $eosio_assert
   (i32.eq
    (call $get_action
     (i32.const 2)
     (i32.const 1)
     (i32.add
      (get_local $4)
      (i32.const 128)
     )
     (i32.const 64)
    )
    (i32.const -1)
   )
   (i32.const 18320)
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (tee_local $0
      (i32.load
       (get_local $2)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 64)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $0
      (i32.load
       (i32.add
        (get_local $4)
        (i32.const 48)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 52)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$4
   (br_if $label$4
    (i32.eqz
     (tee_local $0
      (i32.load offset=100
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 104)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (block $label$5
   (br_if $label$5
    (i32.eqz
     (tee_local $0
      (i32.load
       (i32.add
        (get_local $4)
        (i32.const 88)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 92)
    )
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $4)
    (i32.const 192)
   )
  )
 )
 (func $_ZN14test_checktime14checktime_passEv
  (call $printi
   (i64.const 49995000)
  )
 )
 (func $_ZN14test_checktime17checktime_failureEv
  (local $0 i64)
  (local $1 i64)
  (local $2 i64)
  (local $3 i64)
  (set_local $2
   (i64.const 0)
  )
  (set_local $1
   (i64.const 1)
  )
  (set_local $3
   (i64.const 0)
  )
  (loop $label$0
   (set_local $2
    (i64.add
     (i64.and
      (tee_local $0
       (get_local $2)
      )
      (i64.const 4294967295)
     )
     (get_local $3)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $1
      (i64.add
       (get_local $1)
       (i64.const -1)
      )
     )
     (i64.const 8446744073709551617)
    )
   )
  )
  (call $printi
   (i64.shr_s
    (i64.shl
     (i64.sub
      (get_local $0)
      (get_local $1)
     )
     (i64.const 32)
    )
    (i64.const 32)
   )
  )
 )
 (func $_ZN15test_permission19check_authorizationEyyy (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 48)
    )
   )
  )
  (call $_ZN5eosio18unpack_action_dataI14check_auth_msgEET_v
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
  )
  (i64.store offset=8
   (get_local $4)
   (i64.extend_s/i32
    (call $check_authorization
     (i64.load offset=16
      (get_local $4)
     )
     (i64.load offset=24
      (get_local $4)
     )
     (tee_local $3
      (i32.load offset=32
       (get_local $4)
      )
     )
     (i32.sub
      (i32.load
       (i32.add
        (get_local $4)
        (i32.const 36)
       )
      )
      (get_local $3)
     )
    )
   )
  )
  (block $label$0
   (block $label$1
    (br_if $label$1
     (i32.eq
      (tee_local $3
       (call $db_lowerbound_i64
        (get_local $0)
        (get_local $0)
        (get_local $0)
        (i64.const 1)
       )
      )
      (i32.const -1)
     )
    )
    (call $db_update_i64
     (get_local $3)
     (get_local $0)
     (i32.add
      (get_local $4)
      (i32.const 8)
     )
     (i32.const 8)
    )
    (br $label$0)
   )
   (drop
    (call $db_store_i64
     (get_local $0)
     (get_local $0)
     (get_local $0)
     (i64.const 1)
     (i32.add
      (get_local $4)
      (i32.const 8)
     )
     (i32.const 8)
    )
   )
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (tee_local $3
      (i32.load
       (i32.add
        (get_local $4)
        (i32.const 32)
       )
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $4)
     (i32.const 36)
    )
    (get_local $3)
   )
   (call $_ZdlPv
    (get_local $3)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $4)
    (i32.const 48)
   )
  )
 )
 (func $_ZN5eosio18unpack_action_dataI14check_auth_msgEET_v (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (get_local $4)
     (i32.and
      (i32.add
       (tee_local $1
        (call $action_data_size)
       )
       (i32.const 15)
      )
      (i32.const -16)
     )
    )
   )
  )
  (drop
   (call $read_action_data
    (get_local $2)
    (get_local $1)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 24)
   )
   (i32.const 0)
  )
  (i64.store offset=16 align=4
   (get_local $0)
   (i64.const 0)
  )
  (i32.store
   (tee_local $4
    (get_local $4)
   )
   (get_local $2)
  )
  (i32.store offset=8
   (get_local $4)
   (tee_local $3
    (i32.add
     (get_local $2)
     (get_local $1)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (get_local $1)
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $0)
    (get_local $2)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (get_local $3)
     (tee_local $1
      (i32.add
       (get_local $2)
       (i32.const 8)
      )
     )
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (get_local $1)
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (get_local $4)
   (i32.add
    (get_local $2)
    (i32.const 16)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPKcEE10public_keyEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE
    (get_local $4)
    (i32.add
     (get_local $0)
     (i32.const 16)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
  )
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEE10public_keyEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (set_local $5
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $7
   (i32.const 0)
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $5)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $5
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $5
     (i32.add
      (get_local $5)
      (i32.const 1)
     )
    )
   )
   (set_local $6
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $7
        (i32.and
         (get_local $7)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $6)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.le_u
       (tee_local $5
        (i32.wrap/i64
         (get_local $6)
        )
       )
       (tee_local $7
        (i32.div_s
         (i32.sub
          (tee_local $3
           (i32.load offset=4
            (get_local $1)
           )
          )
          (tee_local $4
           (i32.load
            (get_local $1)
           )
          )
         )
         (i32.const 34)
        )
       )
      )
     )
     (call $_ZNSt3__16vectorI10public_keyNS_9allocatorIS1_EEE8__appendEj
      (get_local $1)
      (i32.sub
       (get_local $5)
       (get_local $7)
      )
     )
     (br_if $label$2
      (i32.ne
       (tee_local $4
        (i32.load
         (get_local $1)
        )
       )
       (tee_local $3
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
      )
     )
     (br $label$1)
    )
    (block $label$4
     (br_if $label$4
      (i32.ge_u
       (get_local $5)
       (get_local $7)
      )
     )
     (i32.store
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
      (tee_local $3
       (i32.add
        (get_local $4)
        (i32.mul
         (get_local $5)
         (i32.const 34)
        )
       )
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (get_local $4)
      (get_local $3)
     )
    )
   )
   (set_local $7
    (i32.load
     (tee_local $5
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
   )
   (set_local $2
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
   )
   (loop $label$5
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (get_local $2)
       )
       (get_local $7)
      )
      (i32.const 33)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (get_local $4)
      (i32.load
       (get_local $5)
      )
      (i32.const 34)
     )
    )
    (i32.store
     (get_local $5)
     (tee_local $7
      (i32.add
       (i32.load
        (get_local $5)
       )
       (i32.const 34)
      )
     )
    )
    (br_if $label$5
     (i32.ne
      (get_local $3)
      (tee_local $4
       (i32.add
        (get_local $4)
        (i32.const 34)
       )
      )
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZNSt3__16vectorI10public_keyNS_9allocatorIS1_EEE8__appendEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.ge_u
         (i32.div_s
          (i32.sub
           (tee_local $2
            (i32.load offset=8
             (get_local $0)
            )
           )
           (tee_local $6
            (i32.load offset=4
             (get_local $0)
            )
           )
          )
          (i32.const 34)
         )
         (get_local $1)
        )
       )
       (br_if $label$2
        (i32.ge_u
         (tee_local $4
          (i32.add
           (tee_local $3
            (i32.div_s
             (i32.sub
              (get_local $6)
              (tee_local $5
               (i32.load
                (get_local $0)
               )
              )
             )
             (i32.const 34)
            )
           )
           (get_local $1)
          )
         )
         (i32.const 126322568)
        )
       )
       (set_local $6
        (i32.const 126322567)
       )
       (block $label$5
        (br_if $label$5
         (i32.gt_u
          (tee_local $2
           (i32.div_s
            (i32.sub
             (get_local $2)
             (get_local $5)
            )
            (i32.const 34)
           )
          )
          (i32.const 63161282)
         )
        )
        (br_if $label$3
         (i32.eqz
          (tee_local $6
           (select
            (get_local $4)
            (tee_local $6
             (i32.shl
              (get_local $2)
              (i32.const 1)
             )
            )
            (i32.lt_u
             (get_local $6)
             (get_local $4)
            )
           )
          )
         )
        )
       )
       (set_local $2
        (call $_Znwj
         (i32.mul
          (get_local $6)
          (i32.const 34)
         )
        )
       )
       (br $label$1)
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
      (loop $label$6
       (drop
        (call $memset
         (get_local $6)
         (i32.const 0)
         (i32.const 34)
        )
       )
       (i32.store
        (get_local $0)
        (tee_local $6
         (i32.add
          (i32.load
           (get_local $0)
          )
          (i32.const 34)
         )
        )
       )
       (br_if $label$6
        (tee_local $1
         (i32.add
          (get_local $1)
          (i32.const -1)
         )
        )
       )
       (br $label$0)
      )
     )
     (set_local $6
      (i32.const 0)
     )
     (set_local $2
      (i32.const 0)
     )
     (br $label$1)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
     (get_local $0)
    )
    (unreachable)
   )
   (set_local $4
    (i32.add
     (get_local $2)
     (i32.mul
      (get_local $6)
      (i32.const 34)
     )
    )
   )
   (set_local $6
    (tee_local $5
     (i32.add
      (get_local $2)
      (i32.mul
       (get_local $3)
       (i32.const 34)
      )
     )
    )
   )
   (loop $label$7
    (set_local $6
     (i32.add
      (call $memset
       (get_local $6)
       (i32.const 0)
       (i32.const 34)
      )
      (i32.const 34)
     )
    )
    (br_if $label$7
     (tee_local $1
      (i32.add
       (get_local $1)
       (i32.const -1)
      )
     )
    )
   )
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.mul
      (i32.div_s
       (tee_local $2
        (i32.sub
         (i32.load
          (tee_local $3
           (i32.add
            (get_local $0)
            (i32.const 4)
           )
          )
         )
         (tee_local $1
          (i32.load
           (get_local $0)
          )
         )
        )
       )
       (i32.const -34)
      )
      (i32.const 34)
     )
    )
   )
   (block $label$8
    (br_if $label$8
     (i32.lt_s
      (get_local $2)
      (i32.const 1)
     )
    )
    (drop
     (call $memcpy
      (get_local $5)
      (get_local $1)
      (get_local $2)
     )
    )
    (set_local $1
     (i32.load
      (get_local $0)
     )
    )
   )
   (i32.store
    (get_local $0)
    (get_local $5)
   )
   (i32.store
    (get_local $3)
    (get_local $6)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (get_local $4)
   )
   (br_if $label$0
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
   (return)
  )
 )
 (func $_ZN15test_datastream10test_basicEv
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 160)
    )
   )
  )
  (i32.store8 offset=144
   (get_local $8)
   (i32.const 1)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.ne
    (i32.load8_u offset=144
     (get_local $8)
    )
    (i32.const 0)
   )
   (i32.const 18368)
  )
  (i32.store8 offset=144
   (get_local $8)
   (i32.const 0)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.eqz
    (i32.load8_u offset=144
     (get_local $8)
    )
   )
   (i32.const 18368)
  )
  (i32.store8 offset=8
   (get_local $8)
   (i32.const 133)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load8_u offset=8
     (get_local $8)
    )
    (i32.load8_u offset=144
     (get_local $8)
    )
   )
   (i32.const 18384)
  )
  (i32.store8 offset=8
   (get_local $8)
   (i32.const 127)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load8_u offset=8
     (get_local $8)
    )
    (i32.load8_u offset=144
     (get_local $8)
    )
   )
   (i32.const 18400)
  )
  (i32.store16 offset=8
   (get_local $8)
   (i32.const 53191)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 2)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 2)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load16_u offset=8
     (get_local $8)
    )
    (i32.load16_u offset=144
     (get_local $8)
    )
   )
   (i32.const 18416)
  )
  (i32.store16 offset=8
   (get_local $8)
   (i32.const 12345)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 2)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 2)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load16_u offset=8
     (get_local $8)
    )
    (i32.load16_u offset=144
     (get_local $8)
    )
   )
   (i32.const 18432)
  )
  (i32.store offset=8
   (get_local $8)
   (i32.const -1234567890)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=8
     (get_local $8)
    )
    (i32.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18448)
  )
  (i32.store offset=8
   (get_local $8)
   (i32.const -1060399406)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.eq
    (i32.load offset=8
     (get_local $8)
    )
    (i32.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18464)
  )
  (i64.store offset=8
   (get_local $8)
   (i64.const -9223372036854775808)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=8
     (get_local $8)
    )
    (i64.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18480)
  )
  (i64.store offset=8
   (get_local $8)
   (i64.const 9223372036854775807)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i64.eq
    (i64.load offset=8
     (get_local $8)
    )
    (i64.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18496)
  )
  (i32.store offset=8
   (get_local $8)
   (i32.const 1067316150)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (f32.eq
    (f32.load offset=8
     (get_local $8)
    )
    (f32.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18512)
  )
  (i64.store offset=8
   (get_local $8)
   (i64.const 4599676419421066581)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.add
     (get_local $8)
     (i32.const 8)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (f64.eq
    (f64.load offset=8
     (get_local $8)
    )
    (f64.load offset=144
     (get_local $8)
    )
   )
   (i32.const 18528)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 18536)
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (tee_local $7
     (i32.or
      (i32.add
       (get_local $8)
       (i32.const 16)
      )
      (i32.const 4)
     )
    )
    (i32.const 18544)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (i32.add
      (get_local $8)
      (i32.const 144)
     )
     (i32.const 8)
    )
    (get_local $7)
    (i32.const 8)
   )
  )
  (call $eosio_assert
   (i32.and
    (i32.eq
     (i32.load offset=144
      (get_local $8)
     )
     (i32.const 1)
    )
    (f64.eq
     (f64.load offset=152
      (get_local $8)
     )
     (f64.const 1.23456)
    )
   )
   (i32.const 18560)
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 18568)
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (get_local $7)
    (i32.const 18572)
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $8)
     (i32.const 144)
    )
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.or
     (i32.add
      (get_local $8)
      (i32.const 144)
     )
     (i32.const 4)
    )
    (get_local $7)
    (i32.const 4)
   )
  )
  (call $eosio_assert
   (i32.and
    (i32.eq
     (i32.load offset=144
      (get_local $8)
     )
     (i32.const 10)
    )
    (i32.eq
     (i32.load offset=148
      (get_local $8)
     )
     (i32.const 20)
    )
   )
   (i32.const 18576)
  )
  (i32.store
   (i32.add
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (i32.const 8)
   )
   (i32.const 0)
  )
  (i64.store offset=16
   (get_local $8)
   (i64.const 0)
  )
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (block $label$6
         (br_if $label$6
          (i32.ge_u
           (tee_local $6
            (call $strlen
             (i32.const 18592)
            )
           )
           (i32.const -16)
          )
         )
         (block $label$7
          (block $label$8
           (block $label$9
            (br_if $label$9
             (i32.ge_u
              (get_local $6)
              (i32.const 11)
             )
            )
            (i32.store8 offset=16
             (get_local $8)
             (i32.shl
              (get_local $6)
              (i32.const 1)
             )
            )
            (set_local $2
             (i32.or
              (i32.add
               (get_local $8)
               (i32.const 16)
              )
              (i32.const 1)
             )
            )
            (br_if $label$8
             (get_local $6)
            )
            (br $label$7)
           )
           (set_local $2
            (call $_Znwj
             (tee_local $3
              (i32.and
               (i32.add
                (get_local $6)
                (i32.const 16)
               )
               (i32.const -16)
              )
             )
            )
           )
           (i32.store offset=16
            (get_local $8)
            (i32.or
             (get_local $3)
             (i32.const 1)
            )
           )
           (i32.store offset=24
            (get_local $8)
            (get_local $2)
           )
           (i32.store offset=20
            (get_local $8)
            (get_local $6)
           )
          )
          (drop
           (call $memcpy
            (get_local $2)
            (i32.const 18592)
            (get_local $6)
           )
          )
         )
         (i32.store8
          (i32.add
           (get_local $2)
           (get_local $6)
          )
          (i32.const 0)
         )
         (call $_ZN8testtypeINSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEE3runERKS6_PKc
          (i32.add
           (get_local $8)
           (i32.const 16)
          )
          (i32.const 18608)
         )
         (block $label$10
          (br_if $label$10
           (i32.eqz
            (i32.and
             (i32.load8_u offset=16
              (get_local $8)
             )
             (i32.const 1)
            )
           )
          )
          (call $_ZdlPv
           (i32.load offset=24
            (get_local $8)
           )
          )
         )
         (i32.store offset=24
          (get_local $8)
          (i32.const 0)
         )
         (i64.store offset=16
          (get_local $8)
          (i64.const 0)
         )
         (i64.store align=4
          (tee_local $6
           (call $_Znwj
            (i32.const 12)
           )
          )
          (i64.const 85899345930)
         )
         (i32.store offset=8
          (get_local $6)
          (i32.const 30)
         )
         (i32.store offset=16
          (get_local $8)
          (get_local $6)
         )
         (i32.store offset=24
          (get_local $8)
          (tee_local $6
           (i32.add
            (get_local $6)
            (i32.const 12)
           )
          )
         )
         (i32.store offset=20
          (get_local $8)
          (get_local $6)
         )
         (call $_ZN8testtypeINSt3__16vectorIiNS0_9allocatorIiEEEEE3runERKS4_PKc
          (i32.add
           (get_local $8)
           (i32.const 16)
          )
          (i32.const 18624)
         )
         (block $label$11
          (br_if $label$11
           (i32.eqz
            (tee_local $6
             (i32.load offset=16
              (get_local $8)
             )
            )
           )
          )
          (i32.store offset=20
           (get_local $8)
           (get_local $6)
          )
          (call $_ZdlPv
           (get_local $6)
          )
         )
         (set_local $6
          (i32.const 0)
         )
         (i32.store offset=24
          (get_local $8)
          (i32.const 0)
         )
         (i64.store offset=16
          (get_local $8)
          (i64.const 0)
         )
         (call $_ZN8testtypeINSt3__16vectorIiNS0_9allocatorIiEEEEE3runERKS4_PKc
          (i32.add
           (get_local $8)
           (i32.const 16)
          )
          (i32.const 18640)
         )
         (block $label$12
          (br_if $label$12
           (i32.eqz
            (tee_local $2
             (i32.load offset=16
              (get_local $8)
             )
            )
           )
          )
          (i32.store offset=20
           (get_local $8)
           (get_local $2)
          )
          (call $_ZdlPv
           (get_local $2)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 1104)
         )
         (drop
          (call $memcpy
           (i32.add
            (get_local $8)
            (i32.const 16)
           )
           (i32.const 18656)
           (i32.const 4)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 1104)
         )
         (drop
          (call $memcpy
           (get_local $7)
           (i32.const 18660)
           (i32.const 4)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 1104)
         )
         (drop
          (call $memcpy
           (tee_local $2
            (i32.or
             (i32.add
              (get_local $8)
              (i32.const 16)
             )
             (i32.const 8)
            )
           )
           (i32.const 18664)
           (i32.const 4)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 720)
         )
         (drop
          (call $memcpy
           (i32.add
            (get_local $8)
            (i32.const 144)
           )
           (i32.add
            (get_local $8)
            (i32.const 16)
           )
           (i32.const 4)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 720)
         )
         (drop
          (call $memcpy
           (i32.or
            (i32.add
             (get_local $8)
             (i32.const 144)
            )
            (i32.const 4)
           )
           (get_local $7)
           (i32.const 4)
          )
         )
         (call $eosio_assert
          (i32.const 1)
          (i32.const 720)
         )
         (drop
          (call $memcpy
           (i32.add
            (i32.add
             (get_local $8)
             (i32.const 144)
            )
            (i32.const 8)
           )
           (get_local $2)
           (i32.const 4)
          )
         )
         (block $label$13
          (br_if $label$13
           (i32.ne
            (i32.load offset=144
             (get_local $8)
            )
            (i32.const 10)
           )
          )
          (br_if $label$13
           (i32.ne
            (i32.load offset=148
             (get_local $8)
            )
            (i32.const 20)
           )
          )
          (set_local $6
           (i32.eq
            (i32.load
             (i32.add
              (get_local $8)
              (i32.const 152)
             )
            )
            (i32.const 30)
           )
          )
         )
         (call $eosio_assert
          (get_local $6)
          (i32.const 18672)
         )
         (i64.store align=4
          (i32.add
           (i32.add
            (get_local $8)
            (i32.const 16)
           )
           (i32.const 8)
          )
          (i64.const 0)
         )
         (i64.store offset=16
          (get_local $8)
          (i64.const 1)
         )
         (set_local $6
          (i32.or
           (i32.add
            (get_local $8)
            (i32.const 16)
           )
           (i32.const 4)
          )
         )
         (br_if $label$5
          (i32.ge_u
           (tee_local $7
            (call $strlen
             (i32.const 18688)
            )
           )
           (i32.const -16)
          )
         )
         (block $label$14
          (block $label$15
           (block $label$16
            (br_if $label$16
             (i32.ge_u
              (get_local $7)
              (i32.const 11)
             )
            )
            (i32.store8 offset=20
             (get_local $8)
             (i32.shl
              (get_local $7)
              (i32.const 1)
             )
            )
            (set_local $6
             (i32.add
              (get_local $6)
              (i32.const 1)
             )
            )
            (br_if $label$15
             (get_local $7)
            )
            (br $label$14)
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 28)
            )
            (tee_local $6
             (call $_Znwj
              (tee_local $2
               (i32.and
                (i32.add
                 (get_local $7)
                 (i32.const 16)
                )
                (i32.const -16)
               )
              )
             )
            )
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 24)
            )
            (get_local $7)
           )
           (i32.store offset=20
            (get_local $8)
            (i32.or
             (get_local $2)
             (i32.const 1)
            )
           )
          )
          (drop
           (call $memcpy
            (get_local $6)
            (i32.const 18688)
            (get_local $7)
           )
          )
         )
         (i32.store8
          (i32.add
           (get_local $6)
           (get_local $7)
          )
          (i32.const 0)
         )
         (i64.store align=4
          (i32.add
           (get_local $8)
           (i32.const 40)
          )
          (i64.const 0)
         )
         (i64.store offset=32
          (get_local $8)
          (i64.const 2)
         )
         (set_local $6
          (i32.add
           (get_local $8)
           (i32.const 36)
          )
         )
         (br_if $label$4
          (i32.ge_u
           (tee_local $7
            (call $strlen
             (i32.const 18704)
            )
           )
           (i32.const -16)
          )
         )
         (block $label$17
          (block $label$18
           (block $label$19
            (br_if $label$19
             (i32.ge_u
              (get_local $7)
              (i32.const 11)
             )
            )
            (i32.store8
             (i32.add
              (get_local $8)
              (i32.const 36)
             )
             (i32.shl
              (get_local $7)
              (i32.const 1)
             )
            )
            (set_local $6
             (i32.add
              (get_local $6)
              (i32.const 1)
             )
            )
            (br_if $label$18
             (get_local $7)
            )
            (br $label$17)
           )
           (set_local $6
            (call $_Znwj
             (tee_local $2
              (i32.and
               (i32.add
                (get_local $7)
                (i32.const 16)
               )
               (i32.const -16)
              )
             )
            )
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 36)
            )
            (i32.or
             (get_local $2)
             (i32.const 1)
            )
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 44)
            )
            (get_local $6)
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 40)
            )
            (get_local $7)
           )
          )
          (drop
           (call $memcpy
            (get_local $6)
            (i32.const 18704)
            (get_local $7)
           )
          )
         )
         (i32.store8
          (i32.add
           (get_local $6)
           (get_local $7)
          )
          (i32.const 0)
         )
         (i64.store align=4
          (i32.add
           (get_local $8)
           (i32.const 56)
          )
          (i64.const 0)
         )
         (i64.store offset=48
          (get_local $8)
          (i64.const 3)
         )
         (set_local $6
          (i32.add
           (get_local $8)
           (i32.const 52)
          )
         )
         (br_if $label$3
          (i32.ge_u
           (tee_local $7
            (call $strlen
             (i32.const 18720)
            )
           )
           (i32.const -16)
          )
         )
         (block $label$20
          (block $label$21
           (block $label$22
            (br_if $label$22
             (i32.ge_u
              (get_local $7)
              (i32.const 11)
             )
            )
            (i32.store8
             (i32.add
              (get_local $8)
              (i32.const 52)
             )
             (i32.shl
              (get_local $7)
              (i32.const 1)
             )
            )
            (set_local $6
             (i32.add
              (get_local $6)
              (i32.const 1)
             )
            )
            (br_if $label$21
             (get_local $7)
            )
            (br $label$20)
           )
           (set_local $6
            (call $_Znwj
             (tee_local $2
              (i32.and
               (i32.add
                (get_local $7)
                (i32.const 16)
               )
               (i32.const -16)
              )
             )
            )
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 52)
            )
            (i32.or
             (get_local $2)
             (i32.const 1)
            )
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 60)
            )
            (get_local $6)
           )
           (i32.store
            (i32.add
             (get_local $8)
             (i32.const 56)
            )
            (get_local $7)
           )
          )
          (drop
           (call $memcpy
            (get_local $6)
            (i32.const 18720)
            (get_local $7)
           )
          )
         )
         (set_local $2
          (i32.const 0)
         )
         (i32.store8
          (i32.add
           (get_local $6)
           (get_local $7)
          )
          (i32.const 0)
         )
         (i32.store offset=152
          (get_local $8)
          (i32.const 0)
         )
         (i32.store offset=148
          (get_local $8)
          (i32.const 0)
         )
         (i32.store offset=144
          (get_local $8)
          (tee_local $1
           (i32.or
            (i32.add
             (get_local $8)
             (i32.const 144)
            )
            (i32.const 4)
           )
          )
         )
         (set_local $0
          (i32.add
           (get_local $8)
           (i32.const 64)
          )
         )
         (set_local $5
          (i32.add
           (get_local $8)
           (i32.const 16)
          )
         )
         (set_local $4
          (i32.add
           (get_local $8)
           (i32.const 152)
          )
         )
         (br_if $label$1
          (i32.ne
           (get_local $1)
           (get_local $1)
          )
         )
         (br $label$2)
        )
        (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
         (i32.add
          (get_local $8)
          (i32.const 16)
         )
        )
        (unreachable)
       )
       (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
        (get_local $6)
       )
       (unreachable)
      )
      (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
       (get_local $6)
      )
      (unreachable)
     )
     (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
      (get_local $6)
     )
     (unreachable)
    )
    (set_local $9
     (i32.const 21)
    )
    (br $label$0)
   )
   (set_local $9
    (i32.const 3)
   )
  )
  (loop $label$23
   (block $label$24
    (block $label$25
     (block $label$26
      (block $label$27
       (block $label$28
        (block $label$29
         (block $label$30
          (block $label$31
           (block $label$32
            (block $label$33
             (block $label$34
              (block $label$35
               (block $label$36
                (block $label$37
                 (block $label$38
                  (block $label$39
                   (block $label$40
                    (block $label$41
                     (block $label$42
                      (block $label$43
                       (block $label$44
                        (block $label$45
                         (block $label$46
                          (block $label$47
                           (block $label$48
                            (block $label$49
                             (block $label$50
                              (block $label$51
                               (block $label$52
                                (block $label$53
                                 (block $label$54
                                  (block $label$55
                                   (block $label$56
                                    (block $label$57
                                     (block $label$58
                                      (block $label$59
                                       (block $label$60
                                        (block $label$61
                                         (block $label$62
                                          (block $label$63
                                           (block $label$64
                                            (block $label$65
                                             (block $label$66
                                              (block $label$67
                                               (block $label$68
                                                (block $label$69
                                                 (block $label$70
                                                  (block $label$71
                                                   (block $label$72
                                                    (block $label$73
                                                     (block $label$74
                                                      (block $label$75
                                                       (block $label$76
                                                        (block $label$77
                                                         (block $label$78
                                                          (block $label$79
                                                           (block $label$80
                                                            (block $label$81
                                                             (block $label$82
                                                              (block $label$83
                                                               (block $label$84
                                                                (block $label$85
                                                                 (block $label$86
                                                                  (block $label$87
                                                                   (block $label$88
                                                                    (block $label$89
                                                                     (block $label$90
                                                                      (block $label$91
                                                                       (block $label$92
                                                                        (br_table $label$75 $label$71 $label$92 $label$91 $label$90 $label$86 $label$83 $label$80 $label$78 $label$76 $label$74 $label$73 $label$72 $label$77 $label$81 $label$79 $label$82 $label$85 $label$84 $label$88 $label$87 $label$89 $label$70 $label$69 $label$68 $label$67 $label$66 $label$65 $label$64 $label$63 $label$61 $label$60 $label$59 $label$58 $label$57 $label$62 $label$56 $label$56
                                                                         (get_local $9)
                                                                        )
                                                                       )
                                                                       (set_local $2
                                                                        (i32.load offset=148
                                                                         (get_local $8)
                                                                        )
                                                                       )
                                                                       (br_if $label$55
                                                                        (i32.eq
                                                                         (i32.load offset=144
                                                                          (get_local $8)
                                                                         )
                                                                         (get_local $1)
                                                                        )
                                                                       )
                                                                       (set_local $9
                                                                        (i32.const 3)
                                                                       )
                                                                       (br $label$23)
                                                                      )
                                                                      (set_local $6
                                                                       (get_local $2)
                                                                      )
                                                                      (br_if $label$40
                                                                       (i32.eqz
                                                                        (get_local $2)
                                                                       )
                                                                      )
                                                                      (set_local $9
                                                                       (i32.const 4)
                                                                      )
                                                                      (br $label$23)
                                                                     )
                                                                     (br_if $label$41
                                                                      (tee_local $6
                                                                       (i32.load offset=4
                                                                        (tee_local $7
                                                                         (get_local $6)
                                                                        )
                                                                       )
                                                                      )
                                                                     )
                                                                     (br $label$42)
                                                                    )
                                                                    (set_local $7
                                                                     (get_local $1)
                                                                    )
                                                                    (br_if $label$32
                                                                     (get_local $2)
                                                                    )
                                                                    (br $label$33)
                                                                   )
                                                                   (set_local $6
                                                                    (get_local $1)
                                                                   )
                                                                   (set_local $9
                                                                    (i32.const 20)
                                                                   )
                                                                   (br $label$23)
                                                                  )
                                                                  (set_local $3
                                                                   (i32.eq
                                                                    (i32.load
                                                                     (tee_local $7
                                                                      (i32.load offset=8
                                                                       (get_local $6)
                                                                      )
                                                                     )
                                                                    )
                                                                    (get_local $6)
                                                                   )
                                                                  )
                                                                  (set_local $6
                                                                   (get_local $7)
                                                                  )
                                                                  (br_if $label$39
                                                                   (get_local $3)
                                                                  )
                                                                  (set_local $9
                                                                   (i32.const 5)
                                                                  )
                                                                  (br $label$23)
                                                                 )
                                                                 (br_if $label$38
                                                                  (i32.ge_s
                                                                   (i32.load offset=16
                                                                    (get_local $7)
                                                                   )
                                                                   (tee_local $6
                                                                    (i32.load
                                                                     (get_local $5)
                                                                    )
                                                                   )
                                                                  )
                                                                 )
                                                                 (set_local $9
                                                                  (i32.const 17)
                                                                 )
                                                                 (br $label$23)
                                                                )
                                                                (br_if $label$54
                                                                 (i32.eqz
                                                                  (get_local $2)
                                                                 )
                                                                )
                                                                (set_local $9
                                                                 (i32.const 18)
                                                                )
                                                                (br $label$23)
                                                               )
                                                               (br_if $label$52
                                                                (i32.load
                                                                 (tee_local $2
                                                                  (i32.add
                                                                   (get_local $7)
                                                                   (i32.const 4)
                                                                  )
                                                                 )
                                                                )
                                                               )
                                                               (br $label$53)
                                                              )
                                                              (set_local $3
                                                               (get_local $1)
                                                              )
                                                              (br_if $label$51
                                                               (get_local $2)
                                                              )
                                                              (set_local $9
                                                               (i32.const 16)
                                                              )
                                                              (br $label$23)
                                                             )
                                                             (set_local $7
                                                              (get_local $1)
                                                             )
                                                             (br_if $label$44
                                                              (i32.load
                                                               (tee_local $2
                                                                (get_local $1)
                                                               )
                                                              )
                                                             )
                                                             (br $label$45)
                                                            )
                                                            (set_local $2
                                                             (get_local $7)
                                                            )
                                                            (set_local $9
                                                             (i32.const 7)
                                                            )
                                                            (br $label$23)
                                                           )
                                                           (br_if $label$37
                                                            (i32.ge_s
                                                             (get_local $6)
                                                             (tee_local $7
                                                              (i32.load offset=16
                                                               (get_local $2)
                                                              )
                                                             )
                                                            )
                                                           )
                                                           (set_local $9
                                                            (i32.const 15)
                                                           )
                                                           (br $label$23)
                                                          )
                                                          (set_local $3
                                                           (get_local $2)
                                                          )
                                                          (br_if $label$46
                                                           (tee_local $7
                                                            (i32.load
                                                             (get_local $2)
                                                            )
                                                           )
                                                          )
                                                          (br $label$47)
                                                         )
                                                         (br_if $label$36
                                                          (i32.ge_s
                                                           (get_local $7)
                                                           (get_local $6)
                                                          )
                                                         )
                                                         (set_local $9
                                                          (i32.const 13)
                                                         )
                                                         (br $label$23)
                                                        )
                                                        (set_local $3
                                                         (i32.add
                                                          (get_local $2)
                                                          (i32.const 4)
                                                         )
                                                        )
                                                        (br_if $label$35
                                                         (tee_local $7
                                                          (i32.load offset=4
                                                           (get_local $2)
                                                          )
                                                         )
                                                        )
                                                        (set_local $9
                                                         (i32.const 9)
                                                        )
                                                        (br $label$23)
                                                       )
                                                       (set_local $7
                                                        (get_local $2)
                                                       )
                                                       (br_if $label$49
                                                        (i32.load
                                                         (tee_local $2
                                                          (get_local $3)
                                                         )
                                                        )
                                                       )
                                                       (br $label$50)
                                                      )
                                                      (set_local $7
                                                       (get_local $2)
                                                      )
                                                      (br_if $label$48
                                                       (i32.load
                                                        (get_local $2)
                                                       )
                                                      )
                                                      (set_local $9
                                                       (i32.const 10)
                                                      )
                                                      (br $label$23)
                                                     )
                                                     (i32.store offset=16
                                                      (tee_local $6
                                                       (call $_Znwj
                                                        (i32.const 32)
                                                       )
                                                      )
                                                      (i32.load
                                                       (get_local $5)
                                                      )
                                                     )
                                                     (drop
                                                      (call $_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_
                                                       (i32.add
                                                        (get_local $6)
                                                        (i32.const 20)
                                                       )
                                                       (i32.add
                                                        (get_local $5)
                                                        (i32.const 4)
                                                       )
                                                      )
                                                     )
                                                     (i32.store offset=8
                                                      (get_local $6)
                                                      (get_local $7)
                                                     )
                                                     (i64.store align=4
                                                      (get_local $6)
                                                      (i64.const 0)
                                                     )
                                                     (i32.store
                                                      (get_local $2)
                                                      (get_local $6)
                                                     )
                                                     (br_if $label$34
                                                      (i32.eqz
                                                       (tee_local $7
                                                        (i32.load
                                                         (i32.load offset=144
                                                          (get_local $8)
                                                         )
                                                        )
                                                       )
                                                      )
                                                     )
                                                     (set_local $9
                                                      (i32.const 11)
                                                     )
                                                     (br $label$23)
                                                    )
                                                    (i32.store offset=144
                                                     (get_local $8)
                                                     (get_local $7)
                                                    )
                                                    (set_local $6
                                                     (i32.load
                                                      (get_local $2)
                                                     )
                                                    )
                                                    (set_local $9
                                                     (i32.const 12)
                                                    )
                                                    (br $label$23)
                                                   )
                                                   (call $_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
                                                    (i32.load offset=148
                                                     (get_local $8)
                                                    )
                                                    (get_local $6)
                                                   )
                                                   (i32.store
                                                    (get_local $4)
                                                    (i32.add
                                                     (i32.load
                                                      (get_local $4)
                                                     )
                                                     (i32.const 1)
                                                    )
                                                   )
                                                   (set_local $9
                                                    (i32.const 1)
                                                   )
                                                   (br $label$23)
                                                  )
                                                  (br_if $label$43
                                                   (i32.ne
                                                    (tee_local $5
                                                     (i32.add
                                                      (get_local $5)
                                                      (i32.const 16)
                                                     )
                                                    )
                                                    (get_local $0)
                                                   )
                                                  )
                                                  (set_local $9
                                                   (i32.const 22)
                                                  )
                                                  (br $label$23)
                                                 )
                                                 (call $_ZN8testtypeINSt3__13mapIiNS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEENS0_4lessIiEENS5_INS0_4pairIKiS7_EEEEEEE3runERKSE_PKc
                                                  (i32.add
                                                   (get_local $8)
                                                   (i32.const 144)
                                                  )
                                                  (i32.const 18736)
                                                 )
                                                 (call $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE
                                                  (i32.add
                                                   (get_local $8)
                                                   (i32.const 144)
                                                  )
                                                  (i32.load offset=148
                                                   (get_local $8)
                                                  )
                                                 )
                                                 (br_if $label$31
                                                  (i32.eqz
                                                   (i32.and
                                                    (i32.load8_u
                                                     (i32.add
                                                      (get_local $8)
                                                      (i32.const 52)
                                                     )
                                                    )
                                                    (i32.const 1)
                                                   )
                                                  )
                                                 )
                                                 (set_local $9
                                                  (i32.const 23)
                                                 )
                                                 (br $label$23)
                                                )
                                                (call $_ZdlPv
                                                 (i32.load
                                                  (i32.add
                                                   (get_local $8)
                                                   (i32.const 60)
                                                  )
                                                 )
                                                )
                                                (set_local $9
                                                 (i32.const 24)
                                                )
                                                (br $label$23)
                                               )
                                               (br_if $label$30
                                                (i32.eqz
                                                 (i32.and
                                                  (i32.load8_u
                                                   (i32.add
                                                    (get_local $8)
                                                    (i32.const 36)
                                                   )
                                                  )
                                                  (i32.const 1)
                                                 )
                                                )
                                               )
                                               (set_local $9
                                                (i32.const 25)
                                               )
                                               (br $label$23)
                                              )
                                              (call $_ZdlPv
                                               (i32.load
                                                (i32.add
                                                 (get_local $8)
                                                 (i32.const 44)
                                                )
                                               )
                                              )
                                              (set_local $9
                                               (i32.const 26)
                                              )
                                              (br $label$23)
                                             )
                                             (br_if $label$29
                                              (i32.eqz
                                               (i32.and
                                                (i32.load8_u offset=20
                                                 (get_local $8)
                                                )
                                                (i32.const 1)
                                               )
                                              )
                                             )
                                             (set_local $9
                                              (i32.const 27)
                                             )
                                             (br $label$23)
                                            )
                                            (call $_ZdlPv
                                             (i32.load
                                              (i32.add
                                               (get_local $8)
                                               (i32.const 28)
                                              )
                                             )
                                            )
                                            (set_local $9
                                             (i32.const 28)
                                            )
                                            (br $label$23)
                                           )
                                           (i64.store align=4
                                            (i32.add
                                             (get_local $8)
                                             (i32.const 24)
                                            )
                                            (i64.const 0)
                                           )
                                           (i64.store offset=16
                                            (get_local $8)
                                            (i64.const 1)
                                           )
                                           (set_local $6
                                            (i32.or
                                             (i32.add
                                              (get_local $8)
                                              (i32.const 16)
                                             )
                                             (i32.const 4)
                                            )
                                           )
                                           (br_if $label$28
                                            (i32.gt_u
                                             (tee_local $7
                                              (call $strlen
                                               (i32.const 8224)
                                              )
                                             )
                                             (i32.const -17)
                                            )
                                           )
                                           (set_local $9
                                            (i32.const 29)
                                           )
                                           (br $label$23)
                                          )
                                          (br_if $label$27
                                           (i32.ge_u
                                            (get_local $7)
                                            (i32.const 11)
                                           )
                                          )
                                          (set_local $9
                                           (i32.const 35)
                                          )
                                          (br $label$23)
                                         )
                                         (i32.store8 offset=20
                                          (get_local $8)
                                          (i32.shl
                                           (get_local $7)
                                           (i32.const 1)
                                          )
                                         )
                                         (set_local $6
                                          (i32.add
                                           (get_local $6)
                                           (i32.const 1)
                                          )
                                         )
                                         (br_if $label$25
                                          (get_local $7)
                                         )
                                         (br $label$26)
                                        )
                                        (i32.store
                                         (i32.add
                                          (get_local $8)
                                          (i32.const 28)
                                         )
                                         (tee_local $6
                                          (call $_Znwj
                                           (tee_local $2
                                            (i32.and
                                             (i32.add
                                              (get_local $7)
                                              (i32.const 16)
                                             )
                                             (i32.const -16)
                                            )
                                           )
                                          )
                                         )
                                        )
                                        (i32.store
                                         (i32.add
                                          (get_local $8)
                                          (i32.const 24)
                                         )
                                         (get_local $7)
                                        )
                                        (i32.store offset=20
                                         (get_local $8)
                                         (i32.or
                                          (get_local $2)
                                          (i32.const 1)
                                         )
                                        )
                                        (set_local $9
                                         (i32.const 31)
                                        )
                                        (br $label$23)
                                       )
                                       (drop
                                        (call $memcpy
                                         (get_local $6)
                                         (i32.const 8224)
                                         (get_local $7)
                                        )
                                       )
                                       (set_local $9
                                        (i32.const 32)
                                       )
                                       (br $label$23)
                                      )
                                      (i32.store8
                                       (i32.add
                                        (get_local $6)
                                        (get_local $7)
                                       )
                                       (i32.const 0)
                                      )
                                      (i64.store offset=32
                                       (get_local $8)
                                       (i64.const 4614688343118974445)
                                      )
                                      (call $_ZN8testtypeINSt3__15tupleIJiNS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEdEEEE3runERKS8_PKc
                                       (i32.add
                                        (get_local $8)
                                        (i32.const 16)
                                       )
                                       (i32.const 18752)
                                      )
                                      (br_if $label$24
                                       (i32.eqz
                                        (i32.and
                                         (i32.load8_u offset=20
                                          (get_local $8)
                                         )
                                         (i32.const 1)
                                        )
                                       )
                                      )
                                      (set_local $9
                                       (i32.const 33)
                                      )
                                      (br $label$23)
                                     )
                                     (call $_ZdlPv
                                      (i32.load
                                       (i32.add
                                        (get_local $8)
                                        (i32.const 28)
                                       )
                                      )
                                     )
                                     (set_local $9
                                      (i32.const 34)
                                     )
                                     (br $label$23)
                                    )
                                    (i32.store offset=4
                                     (i32.const 0)
                                     (i32.add
                                      (get_local $8)
                                      (i32.const 160)
                                     )
                                    )
                                    (return)
                                   )
                                   (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
                                    (get_local $6)
                                   )
                                   (unreachable)
                                  )
                                  (set_local $9
                                   (i32.const 21)
                                  )
                                  (br $label$23)
                                 )
                                 (set_local $9
                                  (i32.const 16)
                                 )
                                 (br $label$23)
                                )
                                (set_local $9
                                 (i32.const 10)
                                )
                                (br $label$23)
                               )
                               (set_local $9
                                (i32.const 1)
                               )
                               (br $label$23)
                              )
                              (set_local $9
                               (i32.const 7)
                              )
                              (br $label$23)
                             )
                             (set_local $9
                              (i32.const 10)
                             )
                             (br $label$23)
                            )
                            (set_local $9
                             (i32.const 1)
                            )
                            (br $label$23)
                           )
                           (set_local $9
                            (i32.const 1)
                           )
                           (br $label$23)
                          )
                          (set_local $9
                           (i32.const 0)
                          )
                          (br $label$23)
                         )
                         (set_local $9
                          (i32.const 14)
                         )
                         (br $label$23)
                        )
                        (set_local $9
                         (i32.const 10)
                        )
                        (br $label$23)
                       )
                       (set_local $9
                        (i32.const 1)
                       )
                       (br $label$23)
                      )
                      (set_local $9
                       (i32.const 2)
                      )
                      (br $label$23)
                     )
                     (set_local $9
                      (i32.const 5)
                     )
                     (br $label$23)
                    )
                    (set_local $9
                     (i32.const 4)
                    )
                    (br $label$23)
                   )
                   (set_local $9
                    (i32.const 19)
                   )
                   (br $label$23)
                  )
                  (set_local $9
                   (i32.const 20)
                  )
                  (br $label$23)
                 )
                 (set_local $9
                  (i32.const 6)
                 )
                 (br $label$23)
                )
                (set_local $9
                 (i32.const 8)
                )
                (br $label$23)
               )
               (set_local $9
                (i32.const 9)
               )
               (br $label$23)
              )
              (set_local $9
               (i32.const 14)
              )
              (br $label$23)
             )
             (set_local $9
              (i32.const 12)
             )
             (br $label$23)
            )
            (set_local $9
             (i32.const 16)
            )
            (br $label$23)
           )
           (set_local $9
            (i32.const 18)
           )
           (br $label$23)
          )
          (set_local $9
           (i32.const 24)
          )
          (br $label$23)
         )
         (set_local $9
          (i32.const 26)
         )
         (br $label$23)
        )
        (set_local $9
         (i32.const 28)
        )
        (br $label$23)
       )
       (set_local $9
        (i32.const 36)
       )
       (br $label$23)
      )
      (set_local $9
       (i32.const 30)
      )
      (br $label$23)
     )
     (set_local $9
      (i32.const 32)
     )
     (br $label$23)
    )
    (set_local $9
     (i32.const 31)
    )
    (br $label$23)
   )
   (set_local $9
    (i32.const 34)
   )
   (br $label$23)
  )
 )
 (func $_ZN8testtypeINSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEE3runERKS6_PKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 160)
    )
   )
  )
  (i32.store offset=24
   (get_local $8)
   (i32.add
    (get_local $8)
    (i32.const 160)
   )
  )
  (i32.store offset=20
   (get_local $8)
   (i32.add
    (get_local $8)
    (i32.const 32)
   )
  )
  (i32.store offset=16
   (get_local $8)
   (i32.add
    (get_local $8)
    (i32.const 32)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (get_local $0)
   )
  )
  (i64.store
   (get_local $8)
   (i64.const 0)
  )
  (set_local $7
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $8)
   (i32.const 0)
  )
  (i32.store offset=20
   (get_local $8)
   (i32.load offset=16
    (get_local $8)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
    (i32.add
     (get_local $8)
     (i32.const 16)
    )
    (get_local $8)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (tee_local $4
      (select
       (i32.load offset=4
        (get_local $0)
       )
       (tee_local $3
        (i32.shr_u
         (tee_local $5
          (i32.load8_u
           (get_local $0)
          )
         )
         (i32.const 1)
        )
       )
       (tee_local $2
        (i32.and
         (get_local $5)
         (i32.const 1)
        )
       )
      )
     )
     (select
      (i32.load offset=4
       (get_local $8)
      )
      (i32.shr_u
       (tee_local $5
        (i32.load8_u
         (get_local $8)
        )
       )
       (i32.const 1)
      )
      (tee_local $5
       (i32.and
        (get_local $5)
        (i32.const 1)
       )
      )
     )
    )
   )
   (set_local $5
    (select
     (i32.load
      (i32.add
       (get_local $8)
       (i32.const 8)
      )
     )
     (i32.or
      (get_local $8)
      (i32.const 1)
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $0)
     (i32.const 1)
    )
   )
   (block $label$1
    (block $label$2
     (block $label$3
      (br_if $label$3
       (get_local $2)
      )
      (br_if $label$2
       (i32.eqz
        (get_local $4)
       )
      )
      (set_local $0
       (i32.sub
        (i32.const 0)
        (get_local $3)
       )
      )
      (loop $label$4
       (br_if $label$1
        (i32.ne
         (i32.load8_u
          (get_local $6)
         )
         (i32.load8_u
          (get_local $5)
         )
        )
       )
       (set_local $7
        (i32.const 1)
       )
       (set_local $5
        (i32.add
         (get_local $5)
         (i32.const 1)
        )
       )
       (set_local $6
        (i32.add
         (get_local $6)
         (i32.const 1)
        )
       )
       (br_if $label$4
        (tee_local $0
         (i32.add
          (get_local $0)
          (i32.const 1)
         )
        )
       )
       (br $label$0)
      )
     )
     (br_if $label$2
      (i32.eqz
       (get_local $4)
      )
     )
     (set_local $7
      (i32.eqz
       (call $memcmp
        (select
         (i32.load offset=8
          (get_local $0)
         )
         (get_local $6)
         (get_local $2)
        )
        (get_local $5)
        (get_local $4)
       )
      )
     )
     (br $label$0)
    )
    (set_local $7
     (i32.const 1)
    )
    (br $label$0)
   )
   (set_local $7
    (i32.const 0)
   )
  )
  (call $eosio_assert
   (get_local $7)
   (get_local $1)
  )
  (block $label$5
   (br_if $label$5
    (i32.eqz
     (i32.and
      (i32.load8_u
       (get_local $8)
      )
      (i32.const 1)
     )
    )
   )
   (call $_ZdlPv
    (i32.load
     (i32.add
      (get_local $8)
      (i32.const 8)
     )
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 160)
   )
  )
 )
 (func $_ZN8testtypeINSt3__16vectorIiNS0_9allocatorIiEEEEE3runERKS4_PKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $5
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 160)
    )
   )
  )
  (i32.store offset=24
   (get_local $5)
   (i32.add
    (get_local $5)
    (i32.const 160)
   )
  )
  (i32.store offset=20
   (get_local $5)
   (i32.add
    (get_local $5)
    (i32.const 32)
   )
  )
  (i32.store offset=16
   (get_local $5)
   (i32.add
    (get_local $5)
    (i32.const 32)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEiEERT_S5_RKNSt3__16vectorIT0_NS6_9allocatorIS8_EEEE
    (i32.add
     (get_local $5)
     (i32.const 16)
    )
    (get_local $0)
   )
  )
  (i64.store
   (get_local $5)
   (i64.const 0)
  )
  (set_local $4
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $5)
   (i32.const 0)
  )
  (i32.store offset=20
   (get_local $5)
   (i32.load offset=16
    (get_local $5)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEiEERT_S5_RNSt3__16vectorIT0_NS6_9allocatorIS8_EEEE
    (i32.add
     (get_local $5)
     (i32.const 16)
    )
    (get_local $5)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.sub
      (tee_local $2
       (i32.load offset=4
        (get_local $0)
       )
      )
      (tee_local $0
       (i32.load
        (get_local $0)
       )
      )
     )
     (i32.sub
      (i32.load offset=4
       (get_local $5)
      )
      (tee_local $3
       (i32.load
        (get_local $5)
       )
      )
     )
    )
   )
   (block $label$1
    (br_if $label$1
     (i32.eq
      (get_local $0)
      (get_local $2)
     )
    )
    (loop $label$2
     (br_if $label$0
      (i32.ne
       (i32.load
        (get_local $0)
       )
       (i32.load
        (get_local $3)
       )
      )
     )
     (set_local $3
      (i32.add
       (get_local $3)
       (i32.const 4)
      )
     )
     (br_if $label$2
      (i32.ne
       (get_local $2)
       (tee_local $0
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
     )
    )
   )
   (set_local $4
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $4)
   (get_local $1)
  )
  (block $label$3
   (br_if $label$3
    (i32.eqz
     (tee_local $0
      (i32.load
       (get_local $5)
      )
     )
    )
   )
   (i32.store offset=4
    (get_local $5)
    (get_local $0)
   )
   (call $_ZdlPv
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $5)
    (i32.const 160)
   )
  )
 )
 (func $_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_ (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i32.store8 offset=12
   (get_local $1)
   (tee_local $3
    (i32.eq
     (get_local $1)
     (get_local $0)
    )
   )
  )
  (block $label$0
   (block $label$1
    (block $label$2
     (br_if $label$2
      (get_local $3)
     )
     (block $label$3
      (block $label$4
       (block $label$5
        (loop $label$6
         (br_if $label$2
          (i32.load8_u offset=12
           (tee_local $2
            (i32.load offset=8
             (get_local $1)
            )
           )
          )
         )
         (block $label$7
          (block $label$8
           (block $label$9
            (br_if $label$9
             (i32.eq
              (tee_local $4
               (i32.load
                (tee_local $3
                 (i32.load offset=8
                  (get_local $2)
                 )
                )
               )
              )
              (get_local $2)
             )
            )
            (br_if $label$7
             (i32.eqz
              (get_local $4)
             )
            )
            (br_if $label$7
             (i32.load8_u offset=12
              (get_local $4)
             )
            )
            (set_local $4
             (i32.add
              (get_local $4)
              (i32.const 12)
             )
            )
            (br $label$8)
           )
           (br_if $label$5
            (i32.eqz
             (tee_local $4
              (i32.load offset=4
               (get_local $3)
              )
             )
            )
           )
           (br_if $label$5
            (i32.load8_u offset=12
             (get_local $4)
            )
           )
           (set_local $4
            (i32.add
             (get_local $4)
             (i32.const 12)
            )
           )
          )
          (i32.store8
           (i32.add
            (get_local $2)
            (i32.const 12)
           )
           (i32.const 1)
          )
          (i32.store8 offset=12
           (get_local $3)
           (tee_local $2
            (i32.eq
             (get_local $3)
             (get_local $0)
            )
           )
          )
          (i32.store8
           (get_local $4)
           (i32.const 1)
          )
          (set_local $1
           (get_local $3)
          )
          (br_if $label$6
           (i32.eqz
            (get_local $2)
           )
          )
          (br $label$2)
         )
        )
        (br_if $label$4
         (i32.eq
          (i32.load
           (get_local $2)
          )
          (get_local $1)
         )
        )
        (set_local $4
         (get_local $2)
        )
        (br $label$3)
       )
       (br_if $label$1
        (i32.eq
         (i32.load
          (get_local $2)
         )
         (get_local $1)
        )
       )
       (i32.store offset=4
        (get_local $2)
        (tee_local $1
         (i32.load
          (tee_local $4
           (i32.load offset=4
            (get_local $2)
           )
          )
         )
        )
       )
       (block $label$10
        (br_if $label$10
         (i32.eqz
          (get_local $1)
         )
        )
        (i32.store offset=8
         (get_local $1)
         (get_local $2)
        )
        (set_local $3
         (i32.load
          (i32.add
           (get_local $2)
           (i32.const 8)
          )
         )
        )
       )
       (i32.store offset=8
        (get_local $4)
        (get_local $3)
       )
       (i32.store
        (select
         (tee_local $3
          (i32.load
           (tee_local $1
            (i32.add
             (get_local $2)
             (i32.const 8)
            )
           )
          )
         )
         (i32.add
          (get_local $3)
          (i32.const 4)
         )
         (i32.eq
          (i32.load
           (get_local $3)
          )
          (get_local $2)
         )
        )
        (get_local $4)
       )
       (i32.store
        (get_local $1)
        (get_local $4)
       )
       (i32.store
        (get_local $4)
        (get_local $2)
       )
       (set_local $3
        (i32.load offset=8
         (get_local $4)
        )
       )
       (br $label$0)
      )
      (i32.store
       (get_local $2)
       (tee_local $1
        (i32.load offset=4
         (tee_local $4
          (i32.load
           (get_local $2)
          )
         )
        )
       )
      )
      (block $label$11
       (br_if $label$11
        (i32.eqz
         (get_local $1)
        )
       )
       (i32.store offset=8
        (get_local $1)
        (get_local $2)
       )
       (set_local $3
        (i32.load
         (i32.add
          (get_local $2)
          (i32.const 8)
         )
        )
       )
      )
      (i32.store offset=8
       (get_local $4)
       (get_local $3)
      )
      (i32.store
       (select
        (tee_local $3
         (i32.load
          (tee_local $1
           (i32.add
            (get_local $2)
            (i32.const 8)
           )
          )
         )
        )
        (i32.add
         (get_local $3)
         (i32.const 4)
        )
        (i32.eq
         (i32.load
          (get_local $3)
         )
         (get_local $2)
        )
       )
       (get_local $4)
      )
      (i32.store
       (get_local $1)
       (get_local $4)
      )
      (i32.store
       (i32.add
        (get_local $4)
        (i32.const 4)
       )
       (get_local $2)
      )
      (set_local $3
       (i32.load offset=8
        (get_local $4)
       )
      )
     )
     (i32.store8 offset=12
      (get_local $4)
      (i32.const 1)
     )
     (i32.store8 offset=12
      (get_local $3)
      (i32.const 0)
     )
     (i32.store offset=4
      (get_local $3)
      (tee_local $4
       (i32.load
        (tee_local $2
         (i32.load offset=4
          (get_local $3)
         )
        )
       )
      )
     )
     (block $label$12
      (br_if $label$12
       (i32.eqz
        (get_local $4)
       )
      )
      (i32.store offset=8
       (get_local $4)
       (get_local $3)
      )
     )
     (i32.store offset=8
      (get_local $2)
      (i32.load offset=8
       (get_local $3)
      )
     )
     (i32.store
      (select
       (tee_local $4
        (i32.load offset=8
         (get_local $3)
        )
       )
       (i32.add
        (get_local $4)
        (i32.const 4)
       )
       (i32.eq
        (i32.load
         (get_local $4)
        )
        (get_local $3)
       )
      )
      (get_local $2)
     )
     (i32.store offset=8
      (get_local $3)
      (get_local $2)
     )
     (i32.store
      (get_local $2)
      (get_local $3)
     )
    )
    (return)
   )
   (set_local $4
    (get_local $2)
   )
  )
  (i32.store8 offset=12
   (get_local $4)
   (i32.const 1)
  )
  (i32.store8 offset=12
   (get_local $3)
   (i32.const 0)
  )
  (i32.store
   (get_local $3)
   (tee_local $4
    (i32.load offset=4
     (tee_local $2
      (i32.load
       (get_local $3)
      )
     )
    )
   )
  )
  (block $label$13
   (br_if $label$13
    (i32.eqz
     (get_local $4)
    )
   )
   (i32.store offset=8
    (get_local $4)
    (get_local $3)
   )
  )
  (i32.store offset=8
   (get_local $2)
   (i32.load offset=8
    (get_local $3)
   )
  )
  (i32.store
   (select
    (tee_local $4
     (i32.load offset=8
      (get_local $3)
     )
    )
    (i32.add
     (get_local $4)
     (i32.const 4)
    )
    (i32.eq
     (i32.load
      (get_local $4)
     )
     (get_local $3)
    )
   )
   (get_local $2)
  )
  (i32.store offset=8
   (get_local $3)
   (get_local $2)
  )
  (i32.store
   (i32.add
    (get_local $2)
    (i32.const 4)
   )
   (get_local $3)
  )
 )
 (func $_ZN8testtypeINSt3__13mapIiNS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEENS0_4lessIiEENS5_INS0_4pairIKiS7_EEEEEEE3runERKSE_PKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (local $10 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $10
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 160)
    )
   )
  )
  (i32.store offset=24
   (get_local $10)
   (i32.add
    (get_local $10)
    (i32.const 160)
   )
  )
  (i32.store offset=20
   (get_local $10)
   (i32.add
    (get_local $10)
    (i32.const 32)
   )
  )
  (i32.store offset=16
   (get_local $10)
   (i32.add
    (get_local $10)
    (i32.const 32)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEiNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEEERT_SC_RKNS4_3mapIT0_T1_NS4_4lessISE_EENS8_INS4_4pairIKSE_SF_EEEEEE
    (i32.add
     (get_local $10)
     (i32.const 16)
    )
    (get_local $0)
   )
  )
  (i32.store
   (get_local $10)
   (i32.or
    (get_local $10)
    (i32.const 4)
   )
  )
  (set_local $9
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $10)
   (i32.const 0)
  )
  (i32.store offset=4
   (get_local $10)
   (i32.const 0)
  )
  (i32.store offset=20
   (get_local $10)
   (i32.load offset=16
    (get_local $10)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEiNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEEERT_SC_RNS4_3mapIT0_T1_NS4_4lessISE_EENS8_INS4_4pairIKSE_SF_EEEEEE
    (i32.add
     (get_local $10)
     (i32.const 16)
    )
    (get_local $10)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load offset=8
      (get_local $0)
     )
     (i32.load offset=8
      (get_local $10)
     )
    )
   )
   (block $label$1
    (br_if $label$1
     (i32.eq
      (tee_local $6
       (i32.load
        (get_local $0)
       )
      )
      (tee_local $2
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
    )
    (set_local $7
     (i32.load
      (get_local $10)
     )
    )
    (set_local $9
     (i32.const 0)
    )
    (loop $label$2
     (br_if $label$0
      (i32.ne
       (i32.load offset=16
        (tee_local $3
         (get_local $6)
        )
       )
       (i32.load offset=16
        (tee_local $8
         (get_local $7)
        )
       )
      )
     )
     (br_if $label$0
      (i32.ne
       (tee_local $5
        (select
         (i32.load offset=24
          (get_local $3)
         )
         (tee_local $4
          (i32.shr_u
           (tee_local $0
            (i32.load8_u offset=20
             (get_local $3)
            )
           )
           (i32.const 1)
          )
         )
         (tee_local $7
          (i32.and
           (get_local $0)
           (i32.const 1)
          )
         )
        )
       )
       (select
        (i32.load offset=24
         (get_local $8)
        )
        (i32.shr_u
         (tee_local $0
          (i32.load8_u offset=20
           (get_local $8)
          )
         )
         (i32.const 1)
        )
        (tee_local $0
         (i32.and
          (get_local $0)
          (i32.const 1)
         )
        )
       )
      )
     )
     (set_local $0
      (select
       (i32.load offset=28
        (get_local $8)
       )
       (i32.add
        (i32.add
         (get_local $8)
         (i32.const 20)
        )
        (i32.const 1)
       )
       (get_local $0)
      )
     )
     (set_local $6
      (i32.add
       (i32.add
        (get_local $3)
        (i32.const 20)
       )
       (i32.const 1)
      )
     )
     (block $label$3
      (block $label$4
       (br_if $label$4
        (get_local $7)
       )
       (br_if $label$3
        (i32.eqz
         (get_local $5)
        )
       )
       (set_local $7
        (i32.sub
         (i32.const 0)
         (get_local $4)
        )
       )
       (loop $label$5
        (br_if $label$0
         (i32.ne
          (i32.load8_u
           (get_local $6)
          )
          (i32.load8_u
           (get_local $0)
          )
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 1)
         )
        )
        (set_local $6
         (i32.add
          (get_local $6)
          (i32.const 1)
         )
        )
        (br_if $label$5
         (tee_local $7
          (i32.add
           (get_local $7)
           (i32.const 1)
          )
         )
        )
        (br $label$3)
       )
      )
      (br_if $label$3
       (i32.eqz
        (get_local $5)
       )
      )
      (br_if $label$0
       (call $memcmp
        (select
         (i32.load offset=28
          (get_local $3)
         )
         (get_local $6)
         (get_local $7)
        )
        (get_local $0)
        (get_local $5)
       )
      )
     )
     (block $label$6
      (block $label$7
       (br_if $label$7
        (i32.eqz
         (tee_local $0
          (i32.load offset=4
           (get_local $3)
          )
         )
        )
       )
       (loop $label$8
        (br_if $label$8
         (tee_local $0
          (i32.load
           (tee_local $6
            (get_local $0)
           )
          )
         )
        )
        (br $label$6)
       )
      )
      (br_if $label$6
       (i32.eq
        (i32.load
         (tee_local $6
          (i32.load offset=8
           (get_local $3)
          )
         )
        )
        (get_local $3)
       )
      )
      (set_local $7
       (i32.add
        (get_local $3)
        (i32.const 8)
       )
      )
      (loop $label$9
       (set_local $7
        (i32.add
         (tee_local $0
          (i32.load
           (get_local $7)
          )
         )
         (i32.const 8)
        )
       )
       (br_if $label$9
        (i32.ne
         (get_local $0)
         (i32.load
          (tee_local $6
           (i32.load offset=8
            (get_local $0)
           )
          )
         )
        )
       )
      )
     )
     (block $label$10
      (block $label$11
       (br_if $label$11
        (i32.eqz
         (tee_local $0
          (i32.load offset=4
           (get_local $8)
          )
         )
        )
       )
       (loop $label$12
        (br_if $label$12
         (tee_local $0
          (i32.load
           (tee_local $7
            (get_local $0)
           )
          )
         )
        )
        (br $label$10)
       )
      )
      (br_if $label$10
       (i32.eq
        (i32.load
         (tee_local $7
          (i32.load offset=8
           (get_local $8)
          )
         )
        )
        (get_local $8)
       )
      )
      (set_local $8
       (i32.add
        (get_local $8)
        (i32.const 8)
       )
      )
      (loop $label$13
       (set_local $8
        (i32.add
         (tee_local $0
          (i32.load
           (get_local $8)
          )
         )
         (i32.const 8)
        )
       )
       (br_if $label$13
        (i32.ne
         (get_local $0)
         (i32.load
          (tee_local $7
           (i32.load offset=8
            (get_local $0)
           )
          )
         )
        )
       )
      )
     )
     (br_if $label$2
      (i32.ne
       (get_local $6)
       (get_local $2)
      )
     )
    )
   )
   (set_local $9
    (i32.const 1)
   )
  )
  (call $eosio_assert
   (get_local $9)
   (get_local $1)
  )
  (call $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE
   (get_local $10)
   (i32.load offset=4
    (get_local $10)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $10)
    (i32.const 160)
   )
  )
 )
 (func $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE (param $0 i32) (param $1 i32)
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (get_local $1)
    )
   )
   (call $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE
    (get_local $0)
    (i32.load
     (get_local $1)
    )
   )
   (call $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE
    (get_local $0)
    (i32.load offset=4
     (get_local $1)
    )
   )
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (i32.and
       (i32.load8_u
        (i32.add
         (get_local $1)
         (i32.const 20)
        )
       )
       (i32.const 1)
      )
     )
    )
    (call $_ZdlPv
     (i32.load
      (i32.add
       (get_local $1)
       (i32.const 28)
      )
     )
    )
   )
   (call $_ZdlPv
    (get_local $1)
   )
  )
 )
 (func $_ZN8testtypeINSt3__15tupleIJiNS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEdEEEE3runERKS8_PKc (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (local $10 i32)
  (local $11 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $11
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 176)
    )
   )
  )
  (i32.store offset=40
   (get_local $11)
   (i32.add
    (get_local $11)
    (i32.const 176)
   )
  )
  (i32.store offset=32
   (get_local $11)
   (i32.add
    (get_local $11)
    (i32.const 48)
   )
  )
  (call $eosio_assert
   (i32.const 1)
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $11)
     (i32.const 48)
    )
    (get_local $0)
    (i32.const 4)
   )
  )
  (i32.store offset=36
   (get_local $11)
   (i32.or
    (i32.add
     (get_local $11)
     (i32.const 48)
    )
    (i32.const 4)
   )
  )
  (drop
   (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
    (i32.add
     (get_local $11)
     (i32.const 32)
    )
    (tee_local $8
     (i32.add
      (get_local $0)
      (i32.const 4)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.gt_s
    (i32.sub
     (i32.load offset=40
      (get_local $11)
     )
     (i32.load offset=36
      (get_local $11)
     )
    )
    (i32.const 7)
   )
   (i32.const 1104)
  )
  (drop
   (call $memcpy
    (i32.load offset=36
     (get_local $11)
    )
    (tee_local $2
     (i32.add
      (get_local $0)
      (i32.const 16)
     )
    )
    (i32.const 8)
   )
  )
  (i64.store
   (tee_local $7
    (i32.add
     (i32.add
      (get_local $11)
      (i32.const 8)
     )
     (i32.const 8)
    )
   )
   (i64.const 0)
  )
  (i64.store offset=8
   (get_local $11)
   (i64.const 0)
  )
  (i64.store offset=24
   (get_local $11)
   (i64.const 0)
  )
  (i32.store offset=36
   (get_local $11)
   (tee_local $9
    (i32.load offset=32
     (get_local $11)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=40
      (get_local $11)
     )
     (get_local $9)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $11)
     (i32.const 8)
    )
    (i32.load offset=36
     (get_local $11)
    )
    (i32.const 4)
   )
  )
  (i32.store offset=36
   (get_local $11)
   (i32.add
    (i32.load offset=36
     (get_local $11)
    )
    (i32.const 4)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
    (i32.add
     (get_local $11)
     (i32.const 32)
    )
    (tee_local $3
     (i32.or
      (i32.add
       (get_local $11)
       (i32.const 8)
      )
      (i32.const 4)
     )
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=40
      (get_local $11)
     )
     (i32.load offset=36
      (get_local $11)
     )
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (i32.add
      (get_local $11)
      (i32.const 8)
     )
     (i32.const 16)
    )
    (i32.load offset=36
     (get_local $11)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=36
   (get_local $11)
   (i32.add
    (i32.load offset=36
     (get_local $11)
    )
    (i32.const 8)
   )
  )
  (set_local $10
   (i32.const 0)
  )
  (block $label$0
   (br_if $label$0
    (i32.ne
     (i32.load
      (get_local $0)
     )
     (i32.load offset=8
      (get_local $11)
     )
    )
   )
   (br_if $label$0
    (i32.ne
     (tee_local $6
      (select
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 8)
        )
       )
       (tee_local $5
        (i32.shr_u
         (tee_local $9
          (i32.load8_u
           (get_local $8)
          )
         )
         (i32.const 1)
        )
       )
       (tee_local $4
        (i32.and
         (get_local $9)
         (i32.const 1)
        )
       )
      )
     )
     (select
      (i32.load
       (get_local $7)
      )
      (i32.shr_u
       (tee_local $9
        (i32.load8_u offset=12
         (get_local $11)
        )
       )
       (i32.const 1)
      )
      (tee_local $7
       (i32.and
        (get_local $9)
        (i32.const 1)
       )
      )
     )
    )
   )
   (set_local $9
    (i32.add
     (get_local $8)
     (i32.const 1)
    )
   )
   (set_local $8
    (select
     (i32.load
      (i32.add
       (i32.add
        (get_local $11)
        (i32.const 8)
       )
       (i32.const 12)
      )
     )
     (i32.add
      (get_local $3)
      (i32.const 1)
     )
     (get_local $7)
    )
   )
   (block $label$1
    (block $label$2
     (br_if $label$2
      (get_local $4)
     )
     (br_if $label$1
      (i32.eqz
       (get_local $6)
      )
     )
     (set_local $10
      (i32.const 0)
     )
     (set_local $0
      (i32.sub
       (i32.const 0)
       (get_local $5)
      )
     )
     (loop $label$3
      (br_if $label$0
       (i32.ne
        (i32.load8_u
         (get_local $9)
        )
        (i32.load8_u
         (get_local $8)
        )
       )
      )
      (set_local $8
       (i32.add
        (get_local $8)
        (i32.const 1)
       )
      )
      (set_local $9
       (i32.add
        (get_local $9)
        (i32.const 1)
       )
      )
      (br_if $label$3
       (tee_local $0
        (i32.add
         (get_local $0)
         (i32.const 1)
        )
       )
      )
      (br $label$1)
     )
    )
    (br_if $label$1
     (i32.eqz
      (get_local $6)
     )
    )
    (br_if $label$0
     (call $memcmp
      (select
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 12)
        )
       )
       (get_local $9)
       (get_local $4)
      )
      (get_local $8)
      (get_local $6)
     )
    )
   )
   (set_local $10
    (f64.eq
     (f64.load
      (get_local $2)
     )
     (f64.load
      (i32.add
       (get_local $11)
       (i32.const 24)
      )
     )
    )
   )
  )
  (call $eosio_assert
   (get_local $10)
   (get_local $1)
  )
  (block $label$4
   (br_if $label$4
    (i32.eqz
     (i32.and
      (i32.load8_u offset=12
       (get_local $11)
      )
      (i32.const 1)
     )
    )
   )
   (call $_ZdlPv
    (i32.load
     (i32.add
      (get_local $11)
      (i32.const 20)
     )
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $11)
    (i32.const 176)
   )
  )
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $7
   (i64.extend_u/i32
    (select
     (i32.load offset=4
      (get_local $1)
     )
     (i32.shr_u
      (tee_local $5
       (i32.load8_u
        (get_local $1)
       )
      )
      (i32.const 1)
     )
     (i32.and
      (get_local $5)
      (i32.const 1)
     )
    )
   )
  )
  (set_local $6
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (set_local $2
    (i32.wrap/i64
     (get_local $7)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $7
         (i64.shr_u
          (get_local $7)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $2)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $4)
      )
      (get_local $6)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $6
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $3)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eqz
     (tee_local $5
      (select
       (i32.load
        (i32.add
         (get_local $1)
         (i32.const 4)
        )
       )
       (i32.shr_u
        (tee_local $5
         (i32.load8_u
          (get_local $1)
         )
        )
        (i32.const 1)
       )
       (tee_local $2
        (i32.and
         (get_local $5)
         (i32.const 1)
        )
       )
      )
     )
    )
   )
   (set_local $3
    (i32.load offset=8
     (get_local $1)
    )
   )
   (call $eosio_assert
    (i32.ge_s
     (i32.sub
      (i32.load
       (i32.add
        (get_local $0)
        (i32.const 8)
       )
      )
      (get_local $6)
     )
     (get_local $5)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (tee_local $6
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
     (select
      (get_local $3)
      (i32.add
       (get_local $1)
       (i32.const 1)
      )
      (get_local $2)
     )
     (get_local $5)
    )
   )
   (i32.store
    (get_local $6)
    (i32.add
     (i32.load
      (get_local $6)
     )
     (get_local $5)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (i32.store offset=24
   (get_local $7)
   (i32.const 0)
  )
  (i64.store offset=16
   (get_local $7)
   (i64.const 0)
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__16vectorIcNS6_9allocatorIcEEEE
    (get_local $0)
    (i32.add
     (get_local $7)
     (i32.const 16)
    )
   )
  )
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (block $label$6
         (block $label$7
          (block $label$8
           (br_if $label$8
            (i32.ne
             (tee_local $5
              (i32.load offset=20
               (get_local $7)
              )
             )
             (tee_local $4
              (i32.load offset=16
               (get_local $7)
              )
             )
            )
           )
           (br_if $label$7
            (i32.and
             (i32.load8_u
              (get_local $1)
             )
             (i32.const 1)
            )
           )
           (i32.store16
            (get_local $1)
            (i32.const 0)
           )
           (set_local $4
            (i32.add
             (get_local $1)
             (i32.const 8)
            )
           )
           (br $label$6)
          )
          (i32.store
           (i32.add
            (get_local $7)
            (i32.const 8)
           )
           (i32.const 0)
          )
          (i64.store
           (get_local $7)
           (i64.const 0)
          )
          (br_if $label$0
           (i32.ge_u
            (tee_local $2
             (i32.sub
              (get_local $5)
              (get_local $4)
             )
            )
            (i32.const -16)
           )
          )
          (br_if $label$5
           (i32.ge_u
            (get_local $2)
            (i32.const 11)
           )
          )
          (i32.store8
           (get_local $7)
           (i32.shl
            (get_local $2)
            (i32.const 1)
           )
          )
          (set_local $6
           (i32.or
            (get_local $7)
            (i32.const 1)
           )
          )
          (br_if $label$4
           (get_local $2)
          )
          (br $label$3)
         )
         (i32.store8
          (i32.load offset=8
           (get_local $1)
          )
          (i32.const 0)
         )
         (i32.store offset=4
          (get_local $1)
          (i32.const 0)
         )
         (set_local $4
          (i32.add
           (get_local $1)
           (i32.const 8)
          )
         )
        )
        (call $_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEj
         (get_local $1)
         (i32.const 0)
        )
        (i32.store
         (get_local $4)
         (i32.const 0)
        )
        (i64.store align=4
         (get_local $1)
         (i64.const 0)
        )
        (br_if $label$2
         (tee_local $4
          (i32.load offset=16
           (get_local $7)
          )
         )
        )
        (br $label$1)
       )
       (set_local $6
        (call $_Znwj
         (tee_local $5
          (i32.and
           (i32.add
            (get_local $2)
            (i32.const 16)
           )
           (i32.const -16)
          )
         )
        )
       )
       (i32.store
        (get_local $7)
        (i32.or
         (get_local $5)
         (i32.const 1)
        )
       )
       (i32.store offset=8
        (get_local $7)
        (get_local $6)
       )
       (i32.store offset=4
        (get_local $7)
        (get_local $2)
       )
      )
      (set_local $3
       (get_local $2)
      )
      (set_local $5
       (get_local $6)
      )
      (loop $label$9
       (i32.store8
        (get_local $5)
        (i32.load8_u
         (get_local $4)
        )
       )
       (set_local $5
        (i32.add
         (get_local $5)
         (i32.const 1)
        )
       )
       (set_local $4
        (i32.add
         (get_local $4)
         (i32.const 1)
        )
       )
       (br_if $label$9
        (tee_local $3
         (i32.add
          (get_local $3)
          (i32.const -1)
         )
        )
       )
      )
      (set_local $6
       (i32.add
        (get_local $6)
        (get_local $2)
       )
      )
     )
     (i32.store8
      (get_local $6)
      (i32.const 0)
     )
     (block $label$10
      (block $label$11
       (br_if $label$11
        (i32.and
         (i32.load8_u
          (get_local $1)
         )
         (i32.const 1)
        )
       )
       (i32.store16
        (get_local $1)
        (i32.const 0)
       )
       (br $label$10)
      )
      (i32.store8
       (i32.load offset=8
        (get_local $1)
       )
       (i32.const 0)
      )
      (i32.store offset=4
       (get_local $1)
       (i32.const 0)
      )
     )
     (call $_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEj
      (get_local $1)
      (i32.const 0)
     )
     (i32.store
      (i32.add
       (get_local $1)
       (i32.const 8)
      )
      (i32.load
       (i32.add
        (get_local $7)
        (i32.const 8)
       )
      )
     )
     (i64.store align=4
      (get_local $1)
      (i64.load
       (get_local $7)
      )
     )
     (br_if $label$1
      (i32.eqz
       (tee_local $4
        (i32.load offset=16
         (get_local $7)
        )
       )
      )
     )
    )
    (i32.store offset=20
     (get_local $7)
     (get_local $4)
    )
    (call $_ZdlPv
     (get_local $4)
    )
   )
   (i32.store offset=4
    (i32.const 0)
    (i32.add
     (get_local $7)
     (i32.const 32)
    )
   )
   (return
    (get_local $0)
   )
  )
  (call $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
   (get_local $7)
  )
  (unreachable)
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEEiNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEEERT_SC_RKNS4_3mapIT0_T1_NS4_4lessISE_EENS8_INS4_4pairIKSE_SF_EEEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i64)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $6
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $4
   (i64.load32_u offset=8
    (get_local $1)
   )
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (set_local $7
    (i32.wrap/i64
     (get_local $4)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $4
         (i64.shr_u
          (get_local $4)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $7)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $2)
      )
      (get_local $6)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $6
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $3)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (tee_local $7
      (i32.load
       (get_local $1)
      )
     )
     (tee_local $2
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
   )
   (loop $label$2
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (get_local $1)
       )
       (get_local $6)
      )
      (i32.const 3)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (tee_local $3
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (i32.add
       (get_local $7)
       (i32.const 16)
      )
      (i32.const 4)
     )
    )
    (i32.store
     (get_local $3)
     (i32.add
      (i32.load
       (get_local $3)
      )
      (i32.const 4)
     )
    )
    (drop
     (call $_ZN5eosiolsINS_10datastreamIPcEEEERT_S5_RKNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
      (get_local $0)
      (i32.add
       (get_local $7)
       (i32.const 20)
      )
     )
    )
    (block $label$3
     (block $label$4
      (br_if $label$4
       (i32.eqz
        (tee_local $6
         (i32.load offset=4
          (get_local $7)
         )
        )
       )
      )
      (loop $label$5
       (br_if $label$5
        (tee_local $6
         (i32.load
          (tee_local $5
           (get_local $6)
          )
         )
        )
       )
       (br $label$3)
      )
     )
     (br_if $label$3
      (i32.eq
       (i32.load
        (tee_local $5
         (i32.load offset=8
          (get_local $7)
         )
        )
       )
       (get_local $7)
      )
     )
     (set_local $7
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
     )
     (loop $label$6
      (set_local $7
       (i32.add
        (tee_local $6
         (i32.load
          (get_local $7)
         )
        )
        (i32.const 8)
       )
      )
      (br_if $label$6
       (i32.ne
        (get_local $6)
        (i32.load
         (tee_local $5
          (i32.load offset=8
           (get_local $6)
          )
         )
        )
       )
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (get_local $5)
      (get_local $2)
     )
    )
    (set_local $6
     (i32.load
      (get_local $3)
     )
    )
    (set_local $7
     (get_local $5)
    )
    (br $label$2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPcEEiNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEEERT_SC_RNS4_3mapIT0_T1_NS4_4lessISE_EENS8_INS4_4pairIKSE_SF_EEEEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  (local $10 i64)
  (local $11 i32)
  (local $12 i32)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (call $_ZNSt3__16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE
   (get_local $1)
   (i32.load offset=4
    (get_local $1)
   )
  )
  (i32.store
   (get_local $1)
   (tee_local $2
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
   )
  )
  (set_local $5
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i32.store offset=4
   (get_local $1)
   (i32.const 0)
  )
  (set_local $6
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $10
   (i64.const 0)
  )
  (set_local $9
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $6)
     (i32.load
      (get_local $9)
     )
    )
    (i32.const 768)
   )
   (set_local $12
    (i32.load8_u
     (tee_local $6
      (i32.load
       (tee_local $7
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
     )
    )
   )
   (i32.store
    (get_local $7)
    (tee_local $6
     (i32.add
      (get_local $6)
      (i32.const 1)
     )
    )
   )
   (set_local $10
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $12)
        (i32.const 127)
       )
       (tee_local $5
        (i32.and
         (get_local $5)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $10)
    )
   )
   (set_local $5
    (i32.add
     (get_local $5)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $12)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eqz
     (tee_local $3
      (i32.wrap/i64
       (get_local $10)
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
   )
   (set_local $11
    (i32.const 0)
   )
   (loop $label$2
    (i32.store
     (tee_local $8
      (i32.add
       (get_local $13)
       (i32.const 8)
      )
     )
     (i32.const 0)
    )
    (i64.store
     (get_local $13)
     (i64.const 0)
    )
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (i32.add
         (get_local $0)
         (i32.const 8)
        )
       )
       (get_local $6)
      )
      (i32.const 3)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (i32.add
       (get_local $13)
       (i32.const 12)
      )
      (i32.load
       (tee_local $9
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (i32.const 4)
     )
    )
    (i32.store
     (get_local $9)
     (i32.add
      (i32.load
       (get_local $9)
      )
      (i32.const 4)
     )
    )
    (drop
     (call $_ZN5eosiorsINS_10datastreamIPcEEEERT_S5_RNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE
      (get_local $0)
      (get_local $13)
     )
    )
    (block $label$3
     (block $label$4
      (block $label$5
       (block $label$6
        (block $label$7
         (br_if $label$7
          (i32.eqz
           (tee_local $6
            (i32.load
             (get_local $2)
            )
           )
          )
         )
         (set_local $5
          (i32.load offset=12
           (get_local $13)
          )
         )
         (set_local $7
          (get_local $4)
         )
         (loop $label$8
          (block $label$9
           (block $label$10
            (br_if $label$10
             (i32.ge_s
              (get_local $5)
              (tee_local $12
               (i32.load offset=16
                (get_local $6)
               )
              )
             )
            )
            (set_local $7
             (get_local $6)
            )
            (br_if $label$9
             (tee_local $12
              (i32.load
               (get_local $6)
              )
             )
            )
            (br $label$6)
           )
           (br_if $label$5
            (i32.ge_s
             (get_local $12)
             (get_local $5)
            )
           )
           (set_local $7
            (i32.add
             (get_local $6)
             (i32.const 4)
            )
           )
           (br_if $label$5
            (i32.eqz
             (tee_local $12
              (i32.load offset=4
               (get_local $6)
              )
             )
            )
           )
          )
          (set_local $6
           (get_local $12)
          )
          (br $label$8)
         )
        )
        (set_local $6
         (get_local $2)
        )
        (br_if $label$3
         (i32.load
          (tee_local $7
           (get_local $2)
          )
         )
        )
        (br $label$4)
       )
       (set_local $7
        (get_local $6)
       )
      )
      (br_if $label$3
       (i32.load
        (get_local $7)
       )
      )
     )
     (i32.store offset=16
      (tee_local $12
       (call $_Znwj
        (i32.const 32)
       )
      )
      (i32.load offset=12
       (get_local $13)
      )
     )
     (i32.store
      (i32.add
       (get_local $12)
       (i32.const 28)
      )
      (i32.load
       (get_local $8)
      )
     )
     (i32.store
      (i32.add
       (get_local $12)
       (i32.const 24)
      )
      (i32.load offset=4
       (get_local $13)
      )
     )
     (i32.store offset=20
      (get_local $12)
      (i32.load
       (get_local $13)
      )
     )
     (i32.store
      (get_local $13)
      (i32.const 0)
     )
     (i32.store offset=4
      (get_local $13)
      (i32.const 0)
     )
     (i32.store
      (get_local $8)
      (i32.const 0)
     )
     (i32.store
      (get_local $12)
      (i32.const 0)
     )
     (i32.store offset=4
      (get_local $12)
      (i32.const 0)
     )
     (i32.store offset=8
      (get_local $12)
      (get_local $6)
     )
     (i32.store
      (get_local $7)
      (get_local $12)
     )
     (block $label$11
      (br_if $label$11
       (i32.eqz
        (tee_local $6
         (i32.load
          (i32.load
           (get_local $1)
          )
         )
        )
       )
      )
      (i32.store
       (get_local $1)
       (get_local $6)
      )
      (set_local $12
       (i32.load
        (get_local $7)
       )
      )
     )
     (call $_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
      (get_local $12)
     )
     (i32.store
      (tee_local $6
       (i32.add
        (get_local $1)
        (i32.const 8)
       )
      )
      (i32.add
       (i32.load
        (get_local $6)
       )
       (i32.const 1)
      )
     )
    )
    (block $label$12
     (br_if $label$12
      (i32.eqz
       (i32.and
        (i32.load8_u
         (get_local $13)
        )
        (i32.const 1)
       )
      )
     )
     (call $_ZdlPv
      (i32.load
       (get_local $8)
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (tee_local $11
       (i32.add
        (get_local $11)
        (i32.const 1)
       )
      )
      (get_local $3)
     )
    )
    (set_local $6
     (i32.load
      (get_local $9)
     )
    )
    (br $label$2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiolsINS_10datastreamIPcEEiEERT_S5_RKNSt3__16vectorIT0_NS6_9allocatorIS8_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (local $8 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $8
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $6
   (i64.extend_u/i32
    (i32.shr_s
     (i32.sub
      (i32.load offset=4
       (get_local $1)
      )
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 2)
    )
   )
  )
  (set_local $7
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $5
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (set_local $2
    (i32.wrap/i64
     (get_local $6)
    )
   )
   (i32.store8 offset=15
    (get_local $8)
    (i32.or
     (i32.shl
      (tee_local $3
       (i64.ne
        (tee_local $6
         (i64.shr_u
          (get_local $6)
          (i64.const 7)
         )
        )
        (i64.const 0)
       )
      )
      (i32.const 7)
     )
     (i32.and
      (get_local $2)
      (i32.const 127)
     )
    )
   )
   (call $eosio_assert
    (i32.gt_s
     (i32.sub
      (i32.load
       (get_local $4)
      )
      (get_local $7)
     )
     (i32.const 0)
    )
    (i32.const 1104)
   )
   (drop
    (call $memcpy
     (i32.load
      (get_local $5)
     )
     (i32.add
      (get_local $8)
      (i32.const 15)
     )
     (i32.const 1)
    )
   )
   (i32.store
    (get_local $5)
    (tee_local $7
     (i32.add
      (i32.load
       (get_local $5)
      )
      (i32.const 1)
     )
    )
   )
   (br_if $label$0
    (get_local $3)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (tee_local $5
      (i32.load
       (get_local $1)
      )
     )
     (tee_local $3
      (i32.load
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
     )
    )
   )
   (set_local $4
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
   )
   (loop $label$2
    (call $eosio_assert
     (i32.gt_s
      (i32.sub
       (i32.load
        (get_local $4)
       )
       (get_local $7)
      )
      (i32.const 3)
     )
     (i32.const 1104)
    )
    (drop
     (call $memcpy
      (i32.load
       (tee_local $2
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (get_local $5)
      (i32.const 4)
     )
    )
    (i32.store
     (get_local $2)
     (tee_local $7
      (i32.add
       (i32.load
        (get_local $2)
       )
       (i32.const 4)
      )
     )
    )
    (br_if $label$2
     (i32.ne
      (get_local $3)
      (tee_local $5
       (i32.add
        (get_local $5)
        (i32.const 4)
       )
      )
     )
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $8)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPcEEiEERT_S5_RNSt3__16vectorIT0_NS6_9allocatorIS8_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i64)
  (local $7 i32)
  (set_local $5
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $7
   (i32.const 0)
  )
  (set_local $6
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $5)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $5
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $5
     (i32.add
      (get_local $5)
      (i32.const 1)
     )
    )
   )
   (set_local $6
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $7
        (i32.and
         (get_local $7)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $6)
    )
   )
   (set_local $7
    (i32.add
     (get_local $7)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.le_u
       (tee_local $5
        (i32.wrap/i64
         (get_local $6)
        )
       )
       (tee_local $7
        (i32.shr_s
         (i32.sub
          (tee_local $3
           (i32.load offset=4
            (get_local $1)
           )
          )
          (tee_local $4
           (i32.load
            (get_local $1)
           )
          )
         )
         (i32.const 2)
        )
       )
      )
     )
     (call $_ZNSt3__16vectorIiNS_9allocatorIiEEE8__appendEj
      (get_local $1)
      (i32.sub
       (get_local $5)
       (get_local $7)
      )
     )
     (br_if $label$2
      (i32.ne
       (tee_local $4
        (i32.load
         (get_local $1)
        )
       )
       (tee_local $3
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
      )
     )
     (br $label$1)
    )
    (block $label$4
     (br_if $label$4
      (i32.ge_u
       (get_local $5)
       (get_local $7)
      )
     )
     (i32.store
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
      (tee_local $3
       (i32.add
        (get_local $4)
        (i32.shl
         (get_local $5)
         (i32.const 2)
        )
       )
      )
     )
    )
    (br_if $label$1
     (i32.eq
      (get_local $4)
      (get_local $3)
     )
    )
   )
   (set_local $7
    (i32.load
     (tee_local $5
      (i32.add
       (get_local $0)
       (i32.const 4)
      )
     )
    )
   )
   (set_local $2
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
   )
   (loop $label$5
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (get_local $2)
       )
       (get_local $7)
      )
      (i32.const 3)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (get_local $4)
      (i32.load
       (get_local $5)
      )
      (i32.const 4)
     )
    )
    (i32.store
     (get_local $5)
     (tee_local $7
      (i32.add
       (i32.load
        (get_local $5)
       )
       (i32.const 4)
      )
     )
    )
    (br_if $label$5
     (i32.ne
      (get_local $3)
      (tee_local $4
       (i32.add
        (get_local $4)
        (i32.const 4)
       )
      )
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZNSt3__16vectorIiNS_9allocatorIiEEE8__appendEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.ge_u
         (i32.shr_s
          (i32.sub
           (tee_local $7
            (i32.load offset=8
             (get_local $0)
            )
           )
           (tee_local $2
            (i32.load offset=4
             (get_local $0)
            )
           )
          )
          (i32.const 2)
         )
         (get_local $1)
        )
       )
       (br_if $label$2
        (i32.ge_u
         (tee_local $2
          (i32.add
           (tee_local $4
            (i32.shr_s
             (i32.sub
              (get_local $2)
              (tee_local $3
               (i32.load
                (get_local $0)
               )
              )
             )
             (i32.const 2)
            )
           )
           (get_local $1)
          )
         )
         (i32.const 1073741824)
        )
       )
       (set_local $6
        (i32.const 1073741823)
       )
       (block $label$5
        (br_if $label$5
         (i32.gt_u
          (i32.shr_s
           (tee_local $7
            (i32.sub
             (get_local $7)
             (get_local $3)
            )
           )
           (i32.const 2)
          )
          (i32.const 536870910)
         )
        )
        (br_if $label$3
         (i32.eqz
          (tee_local $6
           (select
            (get_local $2)
            (tee_local $6
             (i32.shr_s
              (get_local $7)
              (i32.const 1)
             )
            )
            (i32.lt_u
             (get_local $6)
             (get_local $2)
            )
           )
          )
         )
        )
        (br_if $label$1
         (i32.ge_u
          (get_local $6)
          (i32.const 1073741824)
         )
        )
       )
       (set_local $7
        (call $_Znwj
         (i32.shl
          (get_local $6)
          (i32.const 2)
         )
        )
       )
       (br $label$0)
      )
      (set_local $6
       (get_local $2)
      )
      (set_local $7
       (get_local $1)
      )
      (loop $label$6
       (i32.store
        (get_local $6)
        (i32.const 0)
       )
       (set_local $6
        (i32.add
         (get_local $6)
         (i32.const 4)
        )
       )
       (br_if $label$6
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -1)
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
       (i32.add
        (get_local $2)
        (i32.shl
         (get_local $1)
         (i32.const 2)
        )
       )
      )
      (return)
     )
     (set_local $6
      (i32.const 0)
     )
     (set_local $7
      (i32.const 0)
     )
     (br $label$0)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
     (get_local $0)
    )
    (unreachable)
   )
   (call $abort)
   (unreachable)
  )
  (set_local $3
   (i32.add
    (get_local $7)
    (i32.shl
     (get_local $6)
     (i32.const 2)
    )
   )
  )
  (set_local $6
   (tee_local $2
    (i32.add
     (get_local $7)
     (i32.shl
      (get_local $4)
      (i32.const 2)
     )
    )
   )
  )
  (set_local $7
   (get_local $1)
  )
  (loop $label$7
   (i32.store
    (get_local $6)
    (i32.const 0)
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 4)
    )
   )
   (br_if $label$7
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const -1)
     )
    )
   )
  )
  (set_local $4
   (i32.add
    (get_local $2)
    (i32.shl
     (get_local $1)
     (i32.const 2)
    )
   )
  )
  (set_local $1
   (i32.sub
    (get_local $2)
    (tee_local $7
     (i32.sub
      (i32.load
       (tee_local $5
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
      (tee_local $6
       (i32.load
        (get_local $0)
       )
      )
     )
    )
   )
  )
  (block $label$8
   (br_if $label$8
    (i32.lt_s
     (get_local $7)
     (i32.const 1)
    )
   )
   (drop
    (call $memcpy
     (get_local $1)
     (get_local $6)
     (get_local $7)
    )
   )
   (set_local $6
    (i32.load
     (get_local $0)
    )
   )
  )
  (i32.store
   (get_local $0)
   (get_local $1)
  )
  (i32.store
   (get_local $5)
   (get_local $4)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $3)
  )
  (block $label$9
   (br_if $label$9
    (i32.eqz
     (get_local $6)
    )
   )
   (call $_ZdlPv
    (get_local $6)
   )
  )
 )
 (func $apply (param $0 i64) (param $1 i64) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i64)
  (local $8 i64)
  (local $9 i64)
  (local $10 i64)
  (local $11 i32)
  (local $12 i32)
  (local $13 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $13
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 368)
    )
   )
  )
  (set_local $8
   (i64.const 0)
  )
  (set_local $7
   (i64.const 59)
  )
  (set_local $6
   (i32.const 18768)
  )
  (set_local $9
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $8)
          (i64.const 4)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $3
             (i32.load8_s
              (get_local $6)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $3
         (i32.add
          (get_local $3)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $10
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $8)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $3
       (select
        (i32.add
         (get_local $3)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $3)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $10
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $3)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $10
     (i64.shl
      (i64.and
       (get_local $10)
       (i64.const 31)
      )
      (i64.and
       (get_local $7)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 1)
    )
   )
   (set_local $8
    (i64.add
     (get_local $8)
     (i64.const 1)
    )
   )
   (set_local $9
    (i64.or
     (get_local $10)
     (get_local $9)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $7
      (i64.add
       (get_local $7)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (block $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (block $label$12
         (block $label$13
          (block $label$14
           (block $label$15
            (block $label$16
             (block $label$17
              (block $label$18
               (block $label$19
                (block $label$20
                 (block $label$21
                  (block $label$22
                   (block $label$23
                    (block $label$24
                     (block $label$25
                      (block $label$26
                       (block $label$27
                        (block $label$28
                         (block $label$29
                          (block $label$30
                           (block $label$31
                            (block $label$32
                             (block $label$33
                              (block $label$34
                               (block $label$35
                                (block $label$36
                                 (block $label$37
                                  (block $label$38
                                   (block $label$39
                                    (block $label$40
                                     (block $label$41
                                      (block $label$42
                                       (block $label$43
                                        (br_if $label$43
                                         (i64.ne
                                          (get_local $9)
                                          (get_local $1)
                                         )
                                        )
                                        (set_local $8
                                         (i64.const 0)
                                        )
                                        (set_local $7
                                         (i64.const 59)
                                        )
                                        (set_local $6
                                         (i32.const 18784)
                                        )
                                        (set_local $9
                                         (i64.const 0)
                                        )
                                        (loop $label$44
                                         (block $label$45
                                          (block $label$46
                                           (block $label$47
                                            (block $label$48
                                             (block $label$49
                                              (br_if $label$49
                                               (i64.gt_u
                                                (get_local $8)
                                                (i64.const 6)
                                               )
                                              )
                                              (br_if $label$48
                                               (i32.gt_u
                                                (i32.and
                                                 (i32.add
                                                  (tee_local $3
                                                   (i32.load8_s
                                                    (get_local $6)
                                                   )
                                                  )
                                                  (i32.const -97)
                                                 )
                                                 (i32.const 255)
                                                )
                                                (i32.const 25)
                                               )
                                              )
                                              (set_local $3
                                               (i32.add
                                                (get_local $3)
                                                (i32.const 165)
                                               )
                                              )
                                              (br $label$47)
                                             )
                                             (set_local $10
                                              (i64.const 0)
                                             )
                                             (br_if $label$46
                                              (i64.le_u
                                               (get_local $8)
                                               (i64.const 11)
                                              )
                                             )
                                             (br $label$45)
                                            )
                                            (set_local $3
                                             (select
                                              (i32.add
                                               (get_local $3)
                                               (i32.const 208)
                                              )
                                              (i32.const 0)
                                              (i32.lt_u
                                               (i32.and
                                                (i32.add
                                                 (get_local $3)
                                                 (i32.const -49)
                                                )
                                                (i32.const 255)
                                               )
                                               (i32.const 5)
                                              )
                                             )
                                            )
                                           )
                                           (set_local $10
                                            (i64.shr_s
                                             (i64.shl
                                              (i64.extend_u/i32
                                               (get_local $3)
                                              )
                                              (i64.const 56)
                                             )
                                             (i64.const 56)
                                            )
                                           )
                                          )
                                          (set_local $10
                                           (i64.shl
                                            (i64.and
                                             (get_local $10)
                                             (i64.const 31)
                                            )
                                            (i64.and
                                             (get_local $7)
                                             (i64.const 4294967295)
                                            )
                                           )
                                          )
                                         )
                                         (set_local $6
                                          (i32.add
                                           (get_local $6)
                                           (i32.const 1)
                                          )
                                         )
                                         (set_local $8
                                          (i64.add
                                           (get_local $8)
                                           (i64.const 1)
                                          )
                                         )
                                         (set_local $9
                                          (i64.or
                                           (get_local $10)
                                           (get_local $9)
                                          )
                                         )
                                         (br_if $label$44
                                          (i64.ne
                                           (tee_local $7
                                            (i64.add
                                             (get_local $7)
                                             (i64.const -5)
                                            )
                                           )
                                           (i64.const -6)
                                          )
                                         )
                                        )
                                        (br_if $label$43
                                         (i64.ne
                                          (get_local $9)
                                          (get_local $2)
                                         )
                                        )
                                        (call $_ZN5eosio18unpack_action_dataINS_20deferred_transactionEEET_v
                                         (i32.add
                                          (get_local $13)
                                          (i32.const 192)
                                         )
                                        )
                                        (call $prints
                                         (i32.const 18800)
                                        )
                                        (br_if $label$8
                                         (i32.eq
                                          (i32.load
                                           (i32.add
                                            (get_local $13)
                                            (i32.const 232)
                                           )
                                          )
                                          (tee_local $11
                                           (i32.load offset=228
                                            (get_local $13)
                                           )
                                          )
                                         )
                                        )
                                        (br_if $label$42
                                         (i64.ne
                                          (i64.load offset=8
                                           (get_local $11)
                                          )
                                          (i64.const -8665432478290165179)
                                         )
                                        )
                                        (call $_ZN16test_transaction26assert_false_error_handlerERKN5eosio20deferred_transactionE
                                         (i32.add
                                          (get_local $13)
                                          (i32.const 192)
                                         )
                                        )
                                        (br_if $label$37
                                         (i32.eqz
                                          (tee_local $11
                                           (i32.load offset=228
                                            (get_local $13)
                                           )
                                          )
                                         )
                                        )
                                        (set_local $12
                                         (i32.add
                                          (get_local $13)
                                          (i32.const 228)
                                         )
                                        )
                                        (br $label$41)
                                       )
                                       (set_local $8
                                        (i64.const 0)
                                       )
                                       (set_local $7
                                        (i64.const 59)
                                       )
                                       (set_local $6
                                        (i32.const 1120)
                                       )
                                       (set_local $9
                                        (i64.const 0)
                                       )
                                       (loop $label$50
                                        (block $label$51
                                         (block $label$52
                                          (block $label$53
                                           (block $label$54
                                            (block $label$55
                                             (br_if $label$55
                                              (i64.gt_u
                                               (get_local $8)
                                               (i64.const 8)
                                              )
                                             )
                                             (br_if $label$54
                                              (i32.gt_u
                                               (i32.and
                                                (i32.add
                                                 (tee_local $3
                                                  (i32.load8_s
                                                   (get_local $6)
                                                  )
                                                 )
                                                 (i32.const -97)
                                                )
                                                (i32.const 255)
                                               )
                                               (i32.const 25)
                                              )
                                             )
                                             (set_local $3
                                              (i32.add
                                               (get_local $3)
                                               (i32.const 165)
                                              )
                                             )
                                             (br $label$53)
                                            )
                                            (set_local $10
                                             (i64.const 0)
                                            )
                                            (br_if $label$52
                                             (i64.le_u
                                              (get_local $8)
                                              (i64.const 11)
                                             )
                                            )
                                            (br $label$51)
                                           )
                                           (set_local $3
                                            (select
                                             (i32.add
                                              (get_local $3)
                                              (i32.const 208)
                                             )
                                             (i32.const 0)
                                             (i32.lt_u
                                              (i32.and
                                               (i32.add
                                                (get_local $3)
                                                (i32.const -49)
                                               )
                                               (i32.const 255)
                                              )
                                              (i32.const 5)
                                             )
                                            )
                                           )
                                          )
                                          (set_local $10
                                           (i64.shr_s
                                            (i64.shl
                                             (i64.extend_u/i32
                                              (get_local $3)
                                             )
                                             (i64.const 56)
                                            )
                                            (i64.const 56)
                                           )
                                          )
                                         )
                                         (set_local $10
                                          (i64.shl
                                           (i64.and
                                            (get_local $10)
                                            (i64.const 31)
                                           )
                                           (i64.and
                                            (get_local $7)
                                            (i64.const 4294967295)
                                           )
                                          )
                                         )
                                        )
                                        (set_local $6
                                         (i32.add
                                          (get_local $6)
                                          (i32.const 1)
                                         )
                                        )
                                        (set_local $8
                                         (i64.add
                                          (get_local $8)
                                          (i64.const 1)
                                         )
                                        )
                                        (set_local $9
                                         (i64.or
                                          (get_local $10)
                                          (get_local $9)
                                         )
                                        )
                                        (br_if $label$50
                                         (i64.ne
                                          (tee_local $7
                                           (i64.add
                                            (get_local $7)
                                            (i64.const -5)
                                           )
                                          )
                                          (i64.const -6)
                                         )
                                        )
                                       )
                                       (block $label$56
                                        (br_if $label$56
                                         (i64.ne
                                          (get_local $9)
                                          (get_local $2)
                                         )
                                        )
                                        (call $_ZN11test_action14test_cf_actionEv)
                                        (br $label$6)
                                       )
                                       (block $label$57
                                        (br_if $label$57
                                         (i64.ne
                                          (get_local $2)
                                          (i64.const -8665432478235101900)
                                         )
                                        )
                                        (call $eosio_assert
                                         (i32.const 1)
                                         (i32.const 1280)
                                        )
                                        (br $label$6)
                                       )
                                       (call $require_auth
                                        (get_local $1)
                                       )
                                       (br_if $label$40
                                        (i64.gt_s
                                         (get_local $2)
                                         (i64.const -6575469300789510042)
                                        )
                                       )
                                       (br_if $label$36
                                        (i64.gt_s
                                         (get_local $2)
                                         (i64.const -8665432477185147988)
                                        )
                                       )
                                       (br_if $label$34
                                        (i64.gt_s
                                         (get_local $2)
                                         (i64.const -8665432478272688455)
                                        )
                                       )
                                       (br_if $label$30
                                        (i64.gt_s
                                         (get_local $2)
                                         (i64.const -8665432478353100900)
                                        )
                                       )
                                       (br_if $label$25
                                        (i64.eq
                                         (get_local $2)
                                         (i64.const -8665432480418408525)
                                        )
                                       )
                                       (br_if $label$9
                                        (i64.ne
                                         (get_local $2)
                                         (i64.const -8665432478739662525)
                                        )
                                       )
                                       (drop
                                        (call $read_action_data
                                         (i32.add
                                          (get_local $13)
                                          (i32.const 192)
                                         )
                                         (i32.const 8)
                                        )
                                       )
                                       (call $eosio_assert
                                        (i64.eq
                                         (i64.load offset=192
                                          (get_local $13)
                                         )
                                         (get_local $0)
                                        )
                                        (i32.const 1344)
                                       )
                                       (br $label$6)
                                      )
                                      (set_local $12
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 228)
                                       )
                                      )
                                     )
                                     (br_if $label$39
                                      (i32.eq
                                       (tee_local $6
                                        (i32.load
                                         (tee_local $5
                                          (i32.add
                                           (get_local $13)
                                           (i32.const 232)
                                          )
                                         )
                                        )
                                       )
                                       (get_local $11)
                                      )
                                     )
                                     (set_local $4
                                      (i32.sub
                                       (i32.const 0)
                                       (get_local $11)
                                      )
                                     )
                                     (set_local $6
                                      (i32.add
                                       (get_local $6)
                                       (i32.const -24)
                                      )
                                     )
                                     (loop $label$58
                                      (block $label$59
                                       (br_if $label$59
                                        (i32.eqz
                                         (tee_local $3
                                          (i32.load
                                           (i32.add
                                            (get_local $6)
                                            (i32.const 12)
                                           )
                                          )
                                         )
                                        )
                                       )
                                       (i32.store
                                        (i32.add
                                         (get_local $6)
                                         (i32.const 16)
                                        )
                                        (get_local $3)
                                       )
                                       (call $_ZdlPv
                                        (get_local $3)
                                       )
                                      )
                                      (block $label$60
                                       (br_if $label$60
                                        (i32.eqz
                                         (tee_local $3
                                          (i32.load
                                           (get_local $6)
                                          )
                                         )
                                        )
                                       )
                                       (i32.store
                                        (i32.add
                                         (get_local $6)
                                         (i32.const 4)
                                        )
                                        (get_local $3)
                                       )
                                       (call $_ZdlPv
                                        (get_local $3)
                                       )
                                      )
                                      (br_if $label$58
                                       (i32.ne
                                        (i32.add
                                         (tee_local $6
                                          (i32.add
                                           (get_local $6)
                                           (i32.const -40)
                                          )
                                         )
                                         (get_local $4)
                                        )
                                        (i32.const -24)
                                       )
                                      )
                                     )
                                     (set_local $6
                                      (i32.load
                                       (get_local $12)
                                      )
                                     )
                                     (br $label$38)
                                    )
                                    (br_if $label$35
                                     (i64.gt_s
                                      (get_local $2)
                                      (i64.const -6575469299402901114)
                                     )
                                    )
                                    (br_if $label$33
                                     (i64.le_s
                                      (get_local $2)
                                      (i64.const -6575469300549176619)
                                     )
                                    )
                                    (br_if $label$29
                                     (i64.gt_s
                                      (get_local $2)
                                      (i64.const -6575469299641207703)
                                     )
                                    )
                                    (br_if $label$24
                                     (i64.eq
                                      (get_local $2)
                                      (i64.const -6575469300549176618)
                                     )
                                    )
                                    (br_if $label$9
                                     (i64.ne
                                      (get_local $2)
                                      (i64.const -6575469300234199047)
                                     )
                                    )
                                    (call $_ZN22test_compiler_builtins11test_divti3Ev)
                                    (br $label$6)
                                   )
                                   (set_local $6
                                    (get_local $11)
                                   )
                                  )
                                  (i32.store
                                   (get_local $5)
                                   (get_local $11)
                                  )
                                  (call $_ZdlPv
                                   (get_local $6)
                                  )
                                 )
                                 (br_if $label$6
                                  (i32.eqz
                                   (tee_local $11
                                    (i32.load offset=216
                                     (get_local $13)
                                    )
                                   )
                                  )
                                 )
                                 (block $label$61
                                  (block $label$62
                                   (br_if $label$62
                                    (i32.eq
                                     (tee_local $6
                                      (i32.load
                                       (tee_local $5
                                        (i32.add
                                         (get_local $13)
                                         (i32.const 220)
                                        )
                                       )
                                      )
                                     )
                                     (get_local $11)
                                    )
                                   )
                                   (set_local $4
                                    (i32.sub
                                     (i32.const 0)
                                     (get_local $11)
                                    )
                                   )
                                   (set_local $6
                                    (i32.add
                                     (get_local $6)
                                     (i32.const -24)
                                    )
                                   )
                                   (loop $label$63
                                    (block $label$64
                                     (br_if $label$64
                                      (i32.eqz
                                       (tee_local $3
                                        (i32.load
                                         (i32.add
                                          (get_local $6)
                                          (i32.const 12)
                                         )
                                        )
                                       )
                                      )
                                     )
                                     (i32.store
                                      (i32.add
                                       (get_local $6)
                                       (i32.const 16)
                                      )
                                      (get_local $3)
                                     )
                                     (call $_ZdlPv
                                      (get_local $3)
                                     )
                                    )
                                    (block $label$65
                                     (br_if $label$65
                                      (i32.eqz
                                       (tee_local $3
                                        (i32.load
                                         (get_local $6)
                                        )
                                       )
                                      )
                                     )
                                     (i32.store
                                      (i32.add
                                       (get_local $6)
                                       (i32.const 4)
                                      )
                                      (get_local $3)
                                     )
                                     (call $_ZdlPv
                                      (get_local $3)
                                     )
                                    )
                                    (br_if $label$63
                                     (i32.ne
                                      (i32.add
                                       (tee_local $6
                                        (i32.add
                                         (get_local $6)
                                         (i32.const -40)
                                        )
                                       )
                                       (get_local $4)
                                      )
                                      (i32.const -24)
                                     )
                                    )
                                   )
                                   (set_local $6
                                    (i32.load
                                     (i32.add
                                      (get_local $13)
                                      (i32.const 216)
                                     )
                                    )
                                   )
                                   (br $label$61)
                                  )
                                  (set_local $6
                                   (get_local $11)
                                  )
                                 )
                                 (i32.store
                                  (get_local $5)
                                  (get_local $11)
                                 )
                                 (call $_ZdlPv
                                  (get_local $6)
                                 )
                                 (br $label$6)
                                )
                                (br_if $label$32
                                 (i64.le_s
                                  (get_local $2)
                                  (i64.const -8665432476325739330)
                                 )
                                )
                                (br_if $label$28
                                 (i64.gt_s
                                  (get_local $2)
                                  (i64.const -6575469302011795920)
                                 )
                                )
                                (br_if $label$23
                                 (i64.eq
                                  (get_local $2)
                                  (i64.const -8665432476325739329)
                                 )
                                )
                                (br_if $label$9
                                 (i64.ne
                                  (get_local $2)
                                  (i64.const -6575469302268922734)
                                 )
                                )
                                (i64.store offset=200
                                 (get_local $13)
                                 (i64.const 0)
                                )
                                (i64.store offset=192
                                 (get_local $13)
                                 (i64.const 0)
                                )
                                (call $__divti3
                                 (i32.add
                                  (get_local $13)
                                  (i32.const 192)
                                 )
                                 (i64.const 100)
                                 (i64.const 0)
                                 (i64.const 0)
                                 (i64.const 0)
                                )
                                (call $eosio_assert
                                 (i32.const 0)
                                 (i32.const 6768)
                                )
                                (br $label$6)
                               )
                               (br_if $label$31
                                (i64.le_s
                                 (get_local $2)
                                 (i64.const -5790280401120060142)
                                )
                               )
                               (br_if $label$27
                                (i64.gt_s
                                 (get_local $2)
                                 (i64.const -5790280400999598625)
                                )
                               )
                               (br_if $label$22
                                (i64.eq
                                 (get_local $2)
                                 (i64.const -5790280401120060141)
                                )
                               )
                               (br_if $label$9
                                (i64.ne
                                 (get_local $2)
                                 (i64.const -5790280401000535180)
                                )
                               )
                               (call $_ZN10test_types10types_sizeEv)
                               (br $label$6)
                              )
                              (br_if $label$26
                               (i64.le_s
                                (get_local $2)
                                (i64.const -8665432477579625277)
                               )
                              )
                              (br_if $label$21
                               (i64.eq
                                (get_local $2)
                                (i64.const -8665432477579625276)
                               )
                              )
                              (br_if $label$9
                               (i64.ne
                                (get_local $2)
                                (i64.const -8665432477288202418)
                               )
                              )
                              (call $eosio_assert
                               (i32.const 1)
                               (i32.const 1280)
                              )
                              (br $label$6)
                             )
                             (br_if $label$20
                              (i64.eq
                               (get_local $2)
                               (i64.const -6575469300789510041)
                              )
                             )
                             (br_if $label$19
                              (i64.eq
                               (get_local $2)
                               (i64.const -6575469300788910535)
                              )
                             )
                             (br_if $label$9
                              (i64.ne
                               (get_local $2)
                               (i64.const -6575469300561148988)
                              )
                             )
                             (call $_ZN22test_compiler_builtins11test_modti3Ev)
                             (br $label$6)
                            )
                            (br_if $label$18
                             (i64.eq
                              (get_local $2)
                              (i64.const -8665432477185147987)
                             )
                            )
                            (br_if $label$17
                             (i64.eq
                              (get_local $2)
                              (i64.const -8665432476560123846)
                             )
                            )
                            (br_if $label$9
                             (i64.ne
                              (get_local $2)
                              (i64.const -8665432476387013263)
                             )
                            )
                            (drop
                             (call $read_action_data
                              (i32.add
                               (get_local $13)
                               (i32.const 192)
                              )
                              (i32.const 8)
                             )
                            )
                            (call $eosio_assert
                             (i64.eq
                              (call $current_sender)
                              (i64.load offset=192
                               (get_local $13)
                              )
                             )
                             (i32.const 1392)
                            )
                            (br $label$6)
                           )
                           (br_if $label$16
                            (i64.eq
                             (get_local $2)
                             (i64.const -6575469299402901113)
                            )
                           )
                           (br_if $label$15
                            (i64.eq
                             (get_local $2)
                             (i64.const -6575469299349951025)
                            )
                           )
                           (br_if $label$9
                            (i64.ne
                             (get_local $2)
                             (i64.const -6575469299199638822)
                            )
                           )
                           (i64.store offset=200
                            (get_local $13)
                            (i64.const 0)
                           )
                           (i64.store offset=192
                            (get_local $13)
                            (i64.const 0)
                           )
                           (call $__umodti3
                            (i32.add
                             (get_local $13)
                             (i32.const 192)
                            )
                            (i64.const 100)
                            (i64.const 0)
                            (i64.const 0)
                            (i64.const 0)
                           )
                           (call $eosio_assert
                            (i32.const 0)
                            (i32.const 8000)
                           )
                           (br $label$6)
                          )
                          (br_if $label$14
                           (i64.eq
                            (get_local $2)
                            (i64.const -8665432478353100899)
                           )
                          )
                          (br_if $label$9
                           (i64.ne
                            (get_local $2)
                            (i64.const -8665432478290165179)
                           )
                          )
                          (call $eosio_assert
                           (i32.const 0)
                           (i32.const 1248)
                          )
                          (br $label$6)
                         )
                         (br_if $label$13
                          (i64.eq
                           (get_local $2)
                           (i64.const -6575469299641207702)
                          )
                         )
                         (br_if $label$9
                          (i64.ne
                           (get_local $2)
                           (i64.const -6575469299640583116)
                          )
                         )
                         (call $_ZN22test_compiler_builtins12test_ashlti3Ev)
                         (br $label$6)
                        )
                        (br_if $label$12
                         (i64.eq
                          (get_local $2)
                          (i64.const -6575469302011795919)
                         )
                        )
                        (br_if $label$9
                         (i64.ne
                          (get_local $2)
                          (i64.const -6575469301755127924)
                         )
                        )
                        (call $_ZN22test_compiler_builtins12test_udivti3Ev)
                        (br $label$6)
                       )
                       (br_if $label$11
                        (i64.eq
                         (get_local $2)
                         (i64.const -5790280400999598624)
                        )
                       )
                       (br_if $label$9
                        (i64.ne
                         (get_local $2)
                         (i64.const -5790280398527684980)
                        )
                       )
                       (call $_ZN10test_types14string_to_nameEv)
                       (br $label$6)
                      )
                      (br_if $label$10
                       (i64.ne
                        (get_local $2)
                        (i64.const -8665432478272688454)
                       )
                      )
                      (call $_ZN11test_action18read_action_normalEv)
                      (br $label$6)
                     )
                     (i32.store offset=192
                      (get_local $13)
                      (i32.const 0)
                     )
                     (call $eosio_assert
                      (i32.eq
                       (call $read_action_data
                        (i32.add
                         (get_local $13)
                         (i32.const 192)
                        )
                        (i32.const 4)
                       )
                       (i32.const 4)
                      )
                      (i32.const 1440)
                     )
                     (call $eosio_assert
                      (i32.eq
                       (i32.load offset=192
                        (get_local $13)
                       )
                       (call $now)
                      )
                      (i32.const 1472)
                     )
                     (br $label$6)
                    )
                    (call $_ZN22test_compiler_builtins11test_multi3Ev)
                    (br $label$6)
                   )
                   (call $_ZN11test_action12require_authEv)
                   (br $label$6)
                  )
                  (call $_ZN10test_types10name_classEv)
                  (br $label$6)
                 )
                 (drop
                  (call $read_action_data
                   (i32.const 65534)
                   (call $action_data_size)
                  )
                 )
                 (br $label$6)
                )
                (call $_ZN22test_compiler_builtins12test_lshrti3Ev)
                (br $label$6)
               )
               (call $_ZN22test_compiler_builtins12test_lshlti3Ev)
               (br $label$6)
              )
              (call $_ZN11test_action14require_noticeEyyy
               (get_local $0)
               (get_local $8)
               (get_local $8)
              )
              (br $label$6)
             )
             (i32.store offset=192
              (get_local $13)
              (i32.const 0)
             )
             (drop
              (call $read_action_data
               (i32.add
                (get_local $13)
                (i32.const 192)
               )
               (i32.const 4)
              )
             )
             (call $eosio_assert
              (i32.eq
               (i32.load offset=192
                (get_local $13)
               )
               (call $publication_time)
              )
              (i32.const 1312)
             )
             (br $label$6)
            )
            (i64.store offset=200
             (get_local $13)
             (i64.const 0)
            )
            (i64.store offset=192
             (get_local $13)
             (i64.const 0)
            )
            (call $__udivti3
             (i32.add
              (get_local $13)
              (i32.const 192)
             )
             (i64.const 100)
             (i64.const 0)
             (i64.const 0)
             (i64.const 0)
            )
            (call $eosio_assert
             (i32.const 0)
             (i32.const 6768)
            )
            (br $label$6)
           )
           (i64.store offset=200
            (get_local $13)
            (i64.const 0)
           )
           (i64.store offset=192
            (get_local $13)
            (i64.const 0)
           )
           (call $__modti3
            (i32.add
             (get_local $13)
             (i32.const 192)
            )
            (i64.const 100)
            (i64.const 0)
            (i64.const 0)
            (i64.const 0)
           )
           (call $eosio_assert
            (i32.const 0)
            (i32.const 8000)
           )
           (br $label$6)
          )
          (drop
           (call $read_action_data
            (i32.const 0)
            (call $action_data_size)
           )
          )
          (br $label$6)
         )
         (call $_ZN22test_compiler_builtins12test_ashrti3Ev)
         (br $label$6)
        )
        (call $_ZN22test_compiler_builtins12test_umodti3Ev)
        (br $label$6)
       )
       (call $_ZN10test_types14char_to_symbolEv)
       (br $label$6)
      )
      (br_if $label$7
       (i64.eq
        (get_local $2)
        (i64.const -8665432477679290202)
       )
      )
     )
     (set_local $8
      (i64.const 0)
     )
     (set_local $10
      (i64.const 59)
     )
     (set_local $6
      (i32.const 672)
     )
     (set_local $9
      (i64.const 0)
     )
     (loop $label$66
      (set_local $7
       (i64.const 0)
      )
      (block $label$67
       (br_if $label$67
        (i64.gt_u
         (get_local $8)
         (i64.const 11)
        )
       )
       (block $label$68
        (block $label$69
         (br_if $label$69
          (i32.gt_u
           (i32.and
            (i32.add
             (tee_local $3
              (i32.load8_s
               (get_local $6)
              )
             )
             (i32.const -97)
            )
            (i32.const 255)
           )
           (i32.const 25)
          )
         )
         (set_local $3
          (i32.add
           (get_local $3)
           (i32.const 165)
          )
         )
         (br $label$68)
        )
        (set_local $3
         (select
          (i32.add
           (get_local $3)
           (i32.const 208)
          )
          (i32.const 0)
          (i32.lt_u
           (i32.and
            (i32.add
             (get_local $3)
             (i32.const -49)
            )
            (i32.const 255)
           )
           (i32.const 5)
          )
         )
        )
       )
       (set_local $7
        (i64.shl
         (i64.extend_u/i32
          (i32.and
           (get_local $3)
           (i32.const 31)
          )
         )
         (i64.and
          (get_local $10)
          (i64.const 4294967295)
         )
        )
       )
      )
      (set_local $6
       (i32.add
        (get_local $6)
        (i32.const 1)
       )
      )
      (set_local $8
       (i64.add
        (get_local $8)
        (i64.const 1)
       )
      )
      (set_local $9
       (i64.or
        (get_local $7)
        (get_local $9)
       )
      )
      (br_if $label$66
       (i64.ne
        (tee_local $10
         (i64.add
          (get_local $10)
          (i64.const -5)
         )
        )
        (i64.const -6)
       )
      )
     )
     (block $label$70
      (br_if $label$70
       (i64.ne
        (get_local $9)
        (get_local $2)
       )
      )
      (call $_ZN11test_action17test_dummy_actionEv)
      (br $label$6)
     )
     (block $label$71
      (block $label$72
       (block $label$73
        (block $label$74
         (block $label$75
          (block $label$76
           (block $label$77
            (block $label$78
             (block $label$79
              (block $label$80
               (block $label$81
                (block $label$82
                 (block $label$83
                  (block $label$84
                   (block $label$85
                    (block $label$86
                     (block $label$87
                      (block $label$88
                       (block $label$89
                        (block $label$90
                         (block $label$91
                          (block $label$92
                           (block $label$93
                            (block $label$94
                             (block $label$95
                              (block $label$96
                               (block $label$97
                                (block $label$98
                                 (block $label$99
                                  (block $label$100
                                   (block $label$101
                                    (block $label$102
                                     (block $label$103
                                      (block $label$104
                                       (block $label$105
                                        (block $label$106
                                         (block $label$107
                                          (block $label$108
                                           (block $label$109
                                            (block $label$110
                                             (block $label$111
                                              (block $label$112
                                               (block $label$113
                                                (block $label$114
                                                 (block $label$115
                                                  (block $label$116
                                                   (block $label$117
                                                    (block $label$118
                                                     (block $label$119
                                                      (block $label$120
                                                       (block $label$121
                                                        (block $label$122
                                                         (block $label$123
                                                          (block $label$124
                                                           (block $label$125
                                                            (block $label$126
                                                             (block $label$127
                                                              (block $label$128
                                                               (block $label$129
                                                                (block $label$130
                                                                 (block $label$131
                                                                  (block $label$132
                                                                   (block $label$133
                                                                    (block $label$134
                                                                     (block $label$135
                                                                      (block $label$136
                                                                       (block $label$137
                                                                        (block $label$138
                                                                         (block $label$139
                                                                          (block $label$140
                                                                           (block $label$141
                                                                            (br_if $label$141
                                                                             (i64.le_s
                                                                              (get_local $2)
                                                                              (i64.const -4239006002805448792)
                                                                             )
                                                                            )
                                                                            (br_if $label$140
                                                                             (i64.gt_s
                                                                              (get_local $2)
                                                                              (i64.const -696013502478964675)
                                                                             )
                                                                            )
                                                                            (br_if $label$138
                                                                             (i64.gt_s
                                                                              (get_local $2)
                                                                              (i64.const -1293029287904642803)
                                                                             )
                                                                            )
                                                                            (br_if $label$134
                                                                             (i64.le_s
                                                                              (get_local $2)
                                                                              (i64.const -1297175521111935491)
                                                                             )
                                                                            )
                                                                            (br_if $label$126
                                                                             (i64.le_s
                                                                              (get_local $2)
                                                                              (i64.const -1297175520812080312)
                                                                             )
                                                                            )
                                                                            (br_if $label$110
                                                                             (i64.eq
                                                                              (get_local $2)
                                                                              (i64.const -1297175520812080311)
                                                                             )
                                                                            )
                                                                            (br_if $label$109
                                                                             (i64.eq
                                                                              (get_local $2)
                                                                              (i64.const -1297175520277163869)
                                                                             )
                                                                            )
                                                                            (br_if $label$71
                                                                             (i64.ne
                                                                              (get_local $2)
                                                                              (i64.const -1293029288721732840)
                                                                             )
                                                                            )
                                                                            (call $_ZN9test_real13test_additionEv)
                                                                            (br $label$6)
                                                                           )
                                                                           (br_if $label$139
                                                                            (i64.le_s
                                                                             (get_local $2)
                                                                             (i64.const -7587351443732945057)
                                                                            )
                                                                           )
                                                                           (br_if $label$137
                                                                            (i64.gt_s
                                                                             (get_local $2)
                                                                             (i64.const -7078304395291034138)
                                                                            )
                                                                           )
                                                                           (br_if $label$133
                                                                            (i64.le_s
                                                                             (get_local $2)
                                                                             (i64.const -7587351443299599511)
                                                                            )
                                                                           )
                                                                           (br_if $label$125
                                                                            (i64.le_s
                                                                             (get_local $2)
                                                                             (i64.const -7587351442891060093)
                                                                            )
                                                                           )
                                                                           (br_if $label$108
                                                                            (i64.eq
                                                                             (get_local $2)
                                                                             (i64.const -7587351442891060092)
                                                                            )
                                                                           )
                                                                           (br_if $label$107
                                                                            (i64.eq
                                                                             (get_local $2)
                                                                             (i64.const -7587351442863559481)
                                                                            )
                                                                           )
                                                                           (br_if $label$71
                                                                            (i64.ne
                                                                             (get_local $2)
                                                                             (i64.const -7587351442575377030)
                                                                            )
                                                                           )
                                                                           (call $sha1
                                                                            (i32.const 8224)
                                                                            (i32.const 3)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $assert_sha1
                                                                            (i32.const 8224)
                                                                            (i32.const 3)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $sha1
                                                                            (i32.const 8256)
                                                                            (i32.const 56)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $assert_sha1
                                                                            (i32.const 8256)
                                                                            (i32.const 56)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $sha1
                                                                            (i32.const 8336)
                                                                            (i32.const 112)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $assert_sha1
                                                                            (i32.const 8336)
                                                                            (i32.const 112)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $sha1
                                                                            (i32.const 8480)
                                                                            (i32.const 14)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (call $assert_sha1
                                                                            (i32.const 8480)
                                                                            (i32.const 14)
                                                                            (i32.add
                                                                             (get_local $13)
                                                                             (i32.const 192)
                                                                            )
                                                                           )
                                                                           (br $label$6)
                                                                          )
                                                                          (br_if $label$136
                                                                           (i64.gt_s
                                                                            (get_local $2)
                                                                            (i64.const -696013501453266857)
                                                                           )
                                                                          )
                                                                          (br_if $label$132
                                                                           (i64.le_s
                                                                            (get_local $2)
                                                                            (i64.const -696013502197092930)
                                                                           )
                                                                          )
                                                                          (br_if $label$124
                                                                           (i64.le_s
                                                                            (get_local $2)
                                                                            (i64.const -696013502015841439)
                                                                           )
                                                                          )
                                                                          (br_if $label$106
                                                                           (i64.eq
                                                                            (get_local $2)
                                                                            (i64.const -696013502015841438)
                                                                           )
                                                                          )
                                                                          (br_if $label$105
                                                                           (i64.eq
                                                                            (get_local $2)
                                                                            (i64.const -696013501581368598)
                                                                           )
                                                                          )
                                                                          (br_if $label$71
                                                                           (i64.ne
                                                                            (get_local $2)
                                                                            (i64.const -696013501554943131)
                                                                           )
                                                                          )
                                                                          (call $_ZN16test_transaction21test_read_transactionEv)
                                                                          (br $label$6)
                                                                         )
                                                                         (br_if $label$135
                                                                          (i64.le_s
                                                                           (get_local $2)
                                                                           (i64.const -7587351445800925700)
                                                                          )
                                                                         )
                                                                         (br_if $label$131
                                                                          (i64.le_s
                                                                           (get_local $2)
                                                                           (i64.const -7587351445208375856)
                                                                          )
                                                                         )
                                                                         (br_if $label$123
                                                                          (i64.le_s
                                                                           (get_local $2)
                                                                           (i64.const -7587351443887725216)
                                                                          )
                                                                         )
                                                                         (br_if $label$104
                                                                          (i64.eq
                                                                           (get_local $2)
                                                                           (i64.const -7587351443887725215)
                                                                          )
                                                                         )
                                                                         (br_if $label$103
                                                                          (i64.eq
                                                                           (get_local $2)
                                                                           (i64.const -7587351443788808834)
                                                                          )
                                                                         )
                                                                         (br_if $label$71
                                                                          (i64.ne
                                                                           (get_local $2)
                                                                           (i64.const -7587351443763769796)
                                                                          )
                                                                         )
                                                                         (call $_ZN11test_crypto14test_ripemd160Ev)
                                                                         (br $label$6)
                                                                        )
                                                                        (br_if $label$130
                                                                         (i64.le_s
                                                                          (get_local $2)
                                                                          (i64.const -696013503327366015)
                                                                         )
                                                                        )
                                                                        (br_if $label$122
                                                                         (i64.le_s
                                                                          (get_local $2)
                                                                          (i64.const -696013502719373095)
                                                                         )
                                                                        )
                                                                        (br_if $label$102
                                                                         (i64.eq
                                                                          (get_local $2)
                                                                          (i64.const -696013502719373094)
                                                                         )
                                                                        )
                                                                        (br_if $label$101
                                                                         (i64.eq
                                                                          (get_local $2)
                                                                          (i64.const -696013502690195168)
                                                                         )
                                                                        )
                                                                        (br_if $label$71
                                                                         (i64.ne
                                                                          (get_local $2)
                                                                          (i64.const -696013502688730040)
                                                                         )
                                                                        )
                                                                        (call $_ZN16test_transaction22send_transaction_emptyEyyy
                                                                         (get_local $0)
                                                                         (get_local $8)
                                                                         (get_local $8)
                                                                        )
                                                                        (br $label$6)
                                                                       )
                                                                       (br_if $label$129
                                                                        (i64.le_s
                                                                         (get_local $2)
                                                                         (i64.const -5767735918831569476)
                                                                        )
                                                                       )
                                                                       (br_if $label$121
                                                                        (i64.le_s
                                                                         (get_local $2)
                                                                         (i64.const -5767735918449313230)
                                                                        )
                                                                       )
                                                                       (br_if $label$100
                                                                        (i64.eq
                                                                         (get_local $2)
                                                                         (i64.const -5767735918449313229)
                                                                        )
                                                                       )
                                                                       (br_if $label$99
                                                                        (i64.eq
                                                                         (get_local $2)
                                                                         (i64.const -5767735918449313228)
                                                                        )
                                                                       )
                                                                       (br_if $label$71
                                                                        (i64.ne
                                                                         (get_local $2)
                                                                         (i64.const -4239006003864401096)
                                                                        )
                                                                       )
                                                                       (call $printi
                                                                        (i64.const 49995000)
                                                                       )
                                                                       (br $label$6)
                                                                      )
                                                                      (br_if $label$128
                                                                       (i64.le_s
                                                                        (get_local $2)
                                                                        (i64.const -696013500975343229)
                                                                       )
                                                                      )
                                                                      (br_if $label$120
                                                                       (i64.le_s
                                                                        (get_local $2)
                                                                        (i64.const -696013500238724021)
                                                                       )
                                                                      )
                                                                      (br_if $label$98
                                                                       (i64.eq
                                                                        (get_local $2)
                                                                        (i64.const -696013500238724020)
                                                                       )
                                                                      )
                                                                      (br_if $label$97
                                                                       (i64.eq
                                                                        (get_local $2)
                                                                        (i64.const -696013499608977787)
                                                                       )
                                                                      )
                                                                      (br_if $label$71
                                                                       (i64.ne
                                                                        (get_local $2)
                                                                        (i64.const -187209993639507722)
                                                                       )
                                                                      )
                                                                      (call $_ZN15test_datastream10test_basicEv)
                                                                      (br $label$6)
                                                                     )
                                                                     (br_if $label$127
                                                                      (i64.gt_s
                                                                       (get_local $2)
                                                                       (i64.const -8022470633028214611)
                                                                      )
                                                                     )
                                                                     (br_if $label$119
                                                                      (i64.gt_s
                                                                       (get_local $2)
                                                                       (i64.const -8022470633505015025)
                                                                      )
                                                                     )
                                                                     (br_if $label$96
                                                                      (i64.eq
                                                                       (get_local $2)
                                                                       (i64.const -8022470634635220200)
                                                                      )
                                                                     )
                                                                     (br_if $label$71
                                                                      (i64.ne
                                                                       (get_local $2)
                                                                       (i64.const -8022470633818130162)
                                                                      )
                                                                     )
                                                                     (call $eosio_assert
                                                                      (i32.const 1)
                                                                      (i32.const 5584)
                                                                     )
                                                                     (call $eosio_assert
                                                                      (i32.const 1)
                                                                      (i32.const 5648)
                                                                     )
                                                                     (br $label$6)
                                                                    )
                                                                    (br_if $label$118
                                                                     (i64.gt_s
                                                                      (get_local $2)
                                                                      (i64.const -1297175521372163305)
                                                                     )
                                                                    )
                                                                    (br_if $label$95
                                                                     (i64.eq
                                                                      (get_local $2)
                                                                      (i64.const -4239006002805448791)
                                                                     )
                                                                    )
                                                                    (br_if $label$71
                                                                     (i64.ne
                                                                      (get_local $2)
                                                                      (i64.const -1297175522691371959)
                                                                     )
                                                                    )
                                                                    (call $_ZN9test_math18test_double_to_i64Ev)
                                                                    (br $label$6)
                                                                   )
                                                                   (br_if $label$117
                                                                    (i64.gt_s
                                                                     (get_local $2)
                                                                     (i64.const -7587351443459632866)
                                                                    )
                                                                   )
                                                                   (br_if $label$94
                                                                    (i64.eq
                                                                     (get_local $2)
                                                                     (i64.const -7587351443732945056)
                                                                    )
                                                                   )
                                                                   (br_if $label$71
                                                                    (i64.ne
                                                                     (get_local $2)
                                                                     (i64.const -7587351443732941913)
                                                                    )
                                                                   )
                                                                   (call $_ZN11test_crypto11test_sha256Ev)
                                                                   (br $label$6)
                                                                  )
                                                                  (br_if $label$116
                                                                   (i64.gt_s
                                                                    (get_local $2)
                                                                    (i64.const -696013502330537454)
                                                                   )
                                                                  )
                                                                  (br_if $label$93
                                                                   (i64.eq
                                                                    (get_local $2)
                                                                    (i64.const -696013502478964674)
                                                                   )
                                                                  )
                                                                  (br_if $label$71
                                                                   (i64.ne
                                                                    (get_local $2)
                                                                    (i64.const -696013502364326232)
                                                                   )
                                                                  )
                                                                  (call $_ZN16test_transaction30send_transaction_expiring_lateEyyy
                                                                   (get_local $0)
                                                                   (get_local $8)
                                                                   (get_local $8)
                                                                  )
                                                                  (br $label$6)
                                                                 )
                                                                 (br_if $label$115
                                                                  (i64.gt_s
                                                                   (get_local $2)
                                                                   (i64.const -7587351445375451047)
                                                                  )
                                                                 )
                                                                 (br_if $label$92
                                                                  (i64.eq
                                                                   (get_local $2)
                                                                   (i64.const -7587351445800925699)
                                                                  )
                                                                 )
                                                                 (br_if $label$71
                                                                  (i64.ne
                                                                   (get_local $2)
                                                                   (i64.const -7587351445379665366)
                                                                  )
                                                                 )
                                                                 (drop
                                                                  (call $read_action_data
                                                                   (i32.add
                                                                    (get_local $13)
                                                                    (i32.const 192)
                                                                   )
                                                                   (i32.const 132)
                                                                  )
                                                                 )
                                                                 (call $assert_recover_key
                                                                  (i32.add
                                                                   (get_local $13)
                                                                   (i32.const 192)
                                                                  )
                                                                  (i32.add
                                                                   (i32.add
                                                                    (get_local $13)
                                                                    (i32.const 192)
                                                                   )
                                                                   (i32.const 66)
                                                                  )
                                                                  (i32.const 66)
                                                                  (i32.add
                                                                   (get_local $13)
                                                                   (i32.const 224)
                                                                  )
                                                                  (i32.const 34)
                                                                 )
                                                                 (br $label$6)
                                                                )
                                                                (br_if $label$114
                                                                 (i64.gt_s
                                                                  (get_local $2)
                                                                  (i64.const -1293029287114727251)
                                                                 )
                                                                )
                                                                (br_if $label$91
                                                                 (i64.eq
                                                                  (get_local $2)
                                                                  (i64.const -1293029287904642802)
                                                                 )
                                                                )
                                                                (br_if $label$71
                                                                 (i64.ne
                                                                  (get_local $2)
                                                                  (i64.const -1293029287455959611)
                                                                 )
                                                                )
                                                                (call $eosio_assert
                                                                 (i64.eq
                                                                  (call $double_div
                                                                   (call $i64_to_double
                                                                    (i64.const 5)
                                                                   )
                                                                   (call $i64_to_double
                                                                    (i64.const 10)
                                                                   )
                                                                  )
                                                                  (call $double_div
                                                                   (call $i64_to_double
                                                                    (i64.const 5)
                                                                   )
                                                                   (call $i64_to_double
                                                                    (i64.const 10)
                                                                   )
                                                                  )
                                                                 )
                                                                 (i32.const 8064)
                                                                )
                                                                (br $label$6)
                                                               )
                                                               (br_if $label$113
                                                                (i64.gt_s
                                                                 (get_local $2)
                                                                 (i64.const -5767735919218491584)
                                                                )
                                                               )
                                                               (br_if $label$90
                                                                (i64.eq
                                                                 (get_local $2)
                                                                 (i64.const -7078304395291034137)
                                                                )
                                                               )
                                                               (br_if $label$71
                                                                (i64.ne
                                                                 (get_local $2)
                                                                 (i64.const -5823726059754506790)
                                                                )
                                                               )
                                                               (drop
                                                                (call $read_action_data
                                                                 (i32.add
                                                                  (get_local $13)
                                                                  (i32.const 192)
                                                                 )
                                                                 (i32.const 169)
                                                                )
                                                               )
                                                               (call $eosio_assert
                                                                (i32.eq
                                                                 (i32.load8_u offset=192
                                                                  (get_local $13)
                                                                 )
                                                                 (i32.const 21)
                                                                )
                                                                (i32.const 9296)
                                                               )
                                                               (set_local $6
                                                                (i32.const 1)
                                                               )
                                                               (drop
                                                                (call $get_active_producers
                                                                 (i32.or
                                                                  (i32.add
                                                                   (get_local $13)
                                                                   (i32.const 16)
                                                                  )
                                                                  (i32.const 1)
                                                                 )
                                                                 (i32.const 168)
                                                                )
                                                               )
                                                               (loop $label$142
                                                                (call $eosio_assert
                                                                 (i64.eq
                                                                  (i64.load align=1
                                                                   (i32.add
                                                                    (i32.add
                                                                     (get_local $13)
                                                                     (i32.const 16)
                                                                    )
                                                                    (get_local $6)
                                                                   )
                                                                  )
                                                                  (i64.load align=1
                                                                   (i32.add
                                                                    (i32.add
                                                                     (get_local $13)
                                                                     (i32.const 192)
                                                                    )
                                                                    (get_local $6)
                                                                   )
                                                                  )
                                                                 )
                                                                 (i32.const 9328)
                                                                )
                                                                (br_if $label$142
                                                                 (i32.ne
                                                                  (tee_local $6
                                                                   (i32.add
                                                                    (get_local $6)
                                                                    (i32.const 8)
                                                                   )
                                                                  )
                                                                  (i32.const 169)
                                                                 )
                                                                )
                                                                (br $label$6)
                                                               )
                                                              )
                                                              (br_if $label$112
                                                               (i64.gt_s
                                                                (get_local $2)
                                                                (i64.const -696013501077006337)
                                                               )
                                                              )
                                                              (br_if $label$89
                                                               (i64.eq
                                                                (get_local $2)
                                                                (i64.const -696013501453266856)
                                                               )
                                                              )
                                                              (br_if $label$71
                                                               (i64.ne
                                                                (get_local $2)
                                                                (i64.const -696013501174438164)
                                                               )
                                                              )
                                                              (drop
                                                               (call $read_action_data
                                                                (i32.add
                                                                 (get_local $13)
                                                                 (i32.const 192)
                                                                )
                                                                (i32.const 4)
                                                               )
                                                              )
                                                              (call $eosio_assert
                                                               (i32.eq
                                                                (i32.load offset=192
                                                                 (get_local $13)
                                                                )
                                                                (call $tapos_block_prefix)
                                                               )
                                                               (i32.const 17616)
                                                              )
                                                              (br $label$6)
                                                             )
                                                             (br_if $label$111
                                                              (i64.gt_s
                                                               (get_local $2)
                                                               (i64.const -7587351446419414473)
                                                              )
                                                             )
                                                             (br_if $label$88
                                                              (i64.eq
                                                               (get_local $2)
                                                               (i64.const -8022470633028214610)
                                                              )
                                                             )
                                                             (br_if $label$71
                                                              (i64.ne
                                                               (get_local $2)
                                                               (i64.const -8022470632789685404)
                                                              )
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 4928)
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 5008)
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 5072)
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 5136)
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 5200)
                                                             )
                                                             (call $eosio_assert
                                                              (i32.const 1)
                                                              (i32.const 5264)
                                                             )
                                                             (br $label$6)
                                                            )
                                                            (br_if $label$87
                                                             (i64.eq
                                                              (get_local $2)
                                                              (i64.const -1297175521111935490)
                                                             )
                                                            )
                                                            (br_if $label$71
                                                             (i64.ne
                                                              (get_local $2)
                                                              (i64.const -1297175521003327467)
                                                             )
                                                            )
                                                            (drop
                                                             (call $double_div
                                                              (call $i64_to_double
                                                               (i64.const 1)
                                                              )
                                                              (call $double_add
                                                               (call $i64_to_double
                                                                (i64.const -5)
                                                               )
                                                               (call $i64_to_double
                                                                (i64.const 5)
                                                               )
                                                              )
                                                             )
                                                            )
                                                            (call $eosio_assert
                                                             (i32.const 0)
                                                             (i32.const 5856)
                                                            )
                                                            (br $label$6)
                                                           )
                                                           (br_if $label$86
                                                            (i64.eq
                                                             (get_local $2)
                                                             (i64.const -7587351443299599510)
                                                            )
                                                           )
                                                           (br_if $label$71
                                                            (i64.ne
                                                             (get_local $2)
                                                             (i64.const -7587351442991046735)
                                                            )
                                                           )
                                                           (call $sha1
                                                            (i32.const 8224)
                                                            (i32.const 3)
                                                            (i32.add
                                                             (get_local $13)
                                                             (i32.const 192)
                                                            )
                                                           )
                                                           (i32.store8 offset=192
                                                            (get_local $13)
                                                            (i32.xor
                                                             (i32.load8_u offset=192
                                                              (get_local $13)
                                                             )
                                                             (i32.const -1)
                                                            )
                                                           )
                                                           (call $assert_sha1
                                                            (i32.const 8224)
                                                            (i32.const 3)
                                                            (i32.add
                                                             (get_local $13)
                                                             (i32.const 192)
                                                            )
                                                           )
                                                           (call $eosio_assert
                                                            (i32.const 0)
                                                            (i32.const 9264)
                                                           )
                                                           (br $label$6)
                                                          )
                                                          (br_if $label$85
                                                           (i64.eq
                                                            (get_local $2)
                                                            (i64.const -696013502197092929)
                                                           )
                                                          )
                                                          (br_if $label$71
                                                           (i64.ne
                                                            (get_local $2)
                                                            (i64.const -696013502141982502)
                                                           )
                                                          )
                                                          (call $_ZN16test_transaction21read_inline_cf_actionEv)
                                                          (br $label$6)
                                                         )
                                                         (br_if $label$84
                                                          (i64.eq
                                                           (get_local $2)
                                                           (i64.const -7587351445208375855)
                                                          )
                                                         )
                                                         (br_if $label$71
                                                          (i64.ne
                                                           (get_local $2)
                                                           (i64.const -7587351444330131777)
                                                          )
                                                         )
                                                         (set_local $3
                                                          (i32.const 0)
                                                         )
                                                         (call $sha256
                                                          (i32.const 9088)
                                                          (i32.const 0)
                                                          (i32.add
                                                           (get_local $13)
                                                           (i32.const 192)
                                                          )
                                                         )
                                                         (set_local $6
                                                          (i32.const 0)
                                                         )
                                                         (block $label$143
                                                          (loop $label$144
                                                           (br_if $label$143
                                                            (i32.ne
                                                             (i32.load8_u
                                                              (i32.add
                                                               (get_local $6)
                                                               (i32.const 9120)
                                                              )
                                                             )
                                                             (i32.load8_u
                                                              (i32.add
                                                               (i32.add
                                                                (get_local $13)
                                                                (i32.const 192)
                                                               )
                                                               (get_local $6)
                                                              )
                                                             )
                                                            )
                                                           )
                                                           (br_if $label$144
                                                            (i32.le_u
                                                             (tee_local $6
                                                              (i32.add
                                                               (get_local $6)
                                                               (i32.const 1)
                                                              )
                                                             )
                                                             (i32.const 31)
                                                            )
                                                           )
                                                          )
                                                          (set_local $3
                                                           (i32.const 1)
                                                          )
                                                         )
                                                         (call $eosio_assert
                                                          (get_local $3)
                                                          (i32.const 9152)
                                                         )
                                                         (br $label$6)
                                                        )
                                                        (br_if $label$83
                                                         (i64.eq
                                                          (get_local $2)
                                                          (i64.const -696013503327366014)
                                                         )
                                                        )
                                                        (br_if $label$71
                                                         (i64.ne
                                                          (get_local $2)
                                                          (i64.const -696013502727104654)
                                                         )
                                                        )
                                                        (call $_ZN16test_transaction17send_action_emptyEv)
                                                        (br $label$6)
                                                       )
                                                       (br_if $label$82
                                                        (i64.eq
                                                         (get_local $2)
                                                         (i64.const -5767735918831569475)
                                                        )
                                                       )
                                                       (br_if $label$71
                                                        (i64.ne
                                                         (get_local $2)
                                                         (i64.const -5767735918449313234)
                                                        )
                                                       )
                                                       (call $prints
                                                        (i32.const 1488)
                                                       )
                                                       (call $prints
                                                        (i32.const 0)
                                                       )
                                                       (call $prints
                                                        (i32.const 1504)
                                                       )
                                                       (call $prints
                                                        (i32.const 0)
                                                       )
                                                       (call $prints
                                                        (i32.const 1520)
                                                       )
                                                       (call $prints
                                                        (i32.const 0)
                                                       )
                                                       (br $label$6)
                                                      )
                                                      (br_if $label$81
                                                       (i64.eq
                                                        (get_local $2)
                                                        (i64.const -696013500975343228)
                                                       )
                                                      )
                                                      (br_if $label$71
                                                       (i64.ne
                                                        (get_local $2)
                                                        (i64.const -696013500268167086)
                                                       )
                                                      )
                                                      (i32.store offset=192
                                                       (get_local $13)
                                                       (i32.const 0)
                                                      )
                                                      (drop
                                                       (call $read_action_data
                                                        (i32.add
                                                         (get_local $13)
                                                         (i32.const 192)
                                                        )
                                                        (i32.const 4)
                                                       )
                                                      )
                                                      (set_local $6
                                                       (call $transaction_size)
                                                      )
                                                      (call $prints
                                                       (i32.const 17696)
                                                      )
                                                      (call $printi
                                                       (i64.extend_u/i32
                                                        (get_local $6)
                                                       )
                                                      )
                                                      (call $eosio_assert
                                                       (i32.eq
                                                        (i32.load offset=192
                                                         (get_local $13)
                                                        )
                                                        (call $transaction_size)
                                                       )
                                                       (i32.const 17712)
                                                      )
                                                      (br $label$6)
                                                     )
                                                     (br_if $label$80
                                                      (i64.eq
                                                       (get_local $2)
                                                       (i64.const -8022470633505015024)
                                                      )
                                                     )
                                                     (br_if $label$71
                                                      (i64.ne
                                                       (get_local $2)
                                                       (i64.const -8022470633369446971)
                                                      )
                                                     )
                                                     (call $_ZN15test_fixedpoint13test_divisionEv)
                                                     (br $label$6)
                                                    )
                                                    (br_if $label$79
                                                     (i64.eq
                                                      (get_local $2)
                                                      (i64.const -1297175521372163304)
                                                     )
                                                    )
                                                    (br_if $label$71
                                                     (i64.ne
                                                      (get_local $2)
                                                      (i64.const -1297175521141522552)
                                                     )
                                                    )
                                                    (i64.store offset=200
                                                     (get_local $13)
                                                     (i64.const 0)
                                                    )
                                                    (i64.store offset=192
                                                     (get_local $13)
                                                     (i64.const 100)
                                                    )
                                                    (i64.store offset=24
                                                     (get_local $13)
                                                     (i64.const 0)
                                                    )
                                                    (i64.store offset=16
                                                     (get_local $13)
                                                     (i64.const 0)
                                                    )
                                                    (call $diveq_i128
                                                     (i32.add
                                                      (get_local $13)
                                                      (i32.const 192)
                                                     )
                                                     (i32.add
                                                      (get_local $13)
                                                      (i32.const 16)
                                                     )
                                                    )
                                                    (br $label$6)
                                                   )
                                                   (br_if $label$78
                                                    (i64.eq
                                                     (get_local $2)
                                                     (i64.const -7587351443459632865)
                                                    )
                                                   )
                                                   (br_if $label$71
                                                    (i64.ne
                                                     (get_local $2)
                                                     (i64.const -7587351443325747446)
                                                    )
                                                   )
                                                   (call $ripemd160
                                                    (i32.const 8224)
                                                    (i32.const 3)
                                                    (i32.add
                                                     (get_local $13)
                                                     (i32.const 192)
                                                    )
                                                   )
                                                   (i32.store8 offset=192
                                                    (get_local $13)
                                                    (i32.xor
                                                     (i32.load8_u offset=192
                                                      (get_local $13)
                                                     )
                                                     (i32.const -1)
                                                    )
                                                   )
                                                   (call $assert_ripemd160
                                                    (i32.const 8224)
                                                    (i32.const 3)
                                                    (i32.add
                                                     (get_local $13)
                                                     (i32.const 192)
                                                    )
                                                   )
                                                   (call $eosio_assert
                                                    (i32.const 0)
                                                    (i32.const 9264)
                                                   )
                                                   (br $label$6)
                                                  )
                                                  (br_if $label$77
                                                   (i64.eq
                                                    (get_local $2)
                                                    (i64.const -696013502330537453)
                                                   )
                                                  )
                                                  (br_if $label$71
                                                   (i64.ne
                                                    (get_local $2)
                                                    (i64.const -696013502305735710)
                                                   )
                                                  )
                                                  (call $_ZN16test_transaction16send_transactionEyyy
                                                   (get_local $0)
                                                   (get_local $8)
                                                   (get_local $8)
                                                  )
                                                  (br $label$6)
                                                 )
                                                 (br_if $label$76
                                                  (i64.eq
                                                   (get_local $2)
                                                   (i64.const -7587351445375451046)
                                                  )
                                                 )
                                                 (br_if $label$71
                                                  (i64.ne
                                                   (get_local $2)
                                                   (i64.const -7587351445310893855)
                                                  )
                                                 )
                                                 (drop
                                                  (call $read_action_data
                                                   (i32.add
                                                    (get_local $13)
                                                    (i32.const 192)
                                                   )
                                                   (i32.const 132)
                                                  )
                                                 )
                                                 (call $assert_recover_key
                                                  (i32.add
                                                   (get_local $13)
                                                   (i32.const 192)
                                                  )
                                                  (i32.add
                                                   (i32.add
                                                    (get_local $13)
                                                    (i32.const 192)
                                                   )
                                                   (i32.const 66)
                                                  )
                                                  (i32.const 66)
                                                  (i32.add
                                                   (get_local $13)
                                                   (i32.const 224)
                                                  )
                                                  (i32.const 34)
                                                 )
                                                 (call $eosio_assert
                                                  (i32.const 0)
                                                  (i32.const 8000)
                                                 )
                                                 (br $label$6)
                                                )
                                                (br_if $label$75
                                                 (i64.eq
                                                  (get_local $2)
                                                  (i64.const -1293029287114727250)
                                                 )
                                                )
                                                (br_if $label$71
                                                 (i64.ne
                                                  (get_local $2)
                                                  (i64.const -1293029286876198044)
                                                 )
                                                )
                                                (call $eosio_assert
                                                 (i32.const 1)
                                                 (i32.const 8032)
                                                )
                                                (br $label$6)
                                               )
                                               (br_if $label$74
                                                (i64.eq
                                                 (get_local $2)
                                                 (i64.const -5767735919218491583)
                                                )
                                               )
                                               (br_if $label$71
                                                (i64.ne
                                                 (get_local $2)
                                                 (i64.const -5767735918947814449)
                                                )
                                               )
                                               (i64.store offset=200
                                                (get_local $13)
                                                (i64.const -1)
                                               )
                                               (i64.store offset=192
                                                (get_local $13)
                                                (i64.const -1)
                                               )
                                               (i64.store offset=24
                                                (get_local $13)
                                                (i64.const 0)
                                               )
                                               (i64.store offset=16
                                                (get_local $13)
                                                (i64.const 0)
                                               )
                                               (i64.store offset=8
                                                (get_local $13)
                                                (i64.const 0)
                                               )
                                               (i64.store
                                                (get_local $13)
                                                (i64.const 87654323456)
                                               )
                                               (call $printi128
                                                (i32.add
                                                 (get_local $13)
                                                 (i32.const 192)
                                                )
                                               )
                                               (call $printi128
                                                (i32.add
                                                 (get_local $13)
                                                 (i32.const 16)
                                                )
                                               )
                                               (call $printi128
                                                (get_local $13)
                                               )
                                               (br $label$6)
                                              )
                                              (br_if $label$73
                                               (i64.eq
                                                (get_local $2)
                                                (i64.const -696013501077006336)
                                               )
                                              )
                                              (br_if $label$71
                                               (i64.ne
                                                (get_local $2)
                                                (i64.const -696013501027893080)
                                               )
                                              )
                                              (call $prints
                                               (i32.const 18064)
                                              )
                                              (br $label$6)
                                             )
                                             (br_if $label$72
                                              (i64.eq
                                               (get_local $2)
                                               (i64.const -7587351446419414472)
                                              )
                                             )
                                             (br_if $label$71
                                              (i64.ne
                                               (get_local $2)
                                               (i64.const -7587351446368672234)
                                              )
                                             )
                                             (call $sha512
                                              (i32.const 8224)
                                              (i32.const 3)
                                              (i32.add
                                               (get_local $13)
                                               (i32.const 192)
                                              )
                                             )
                                             (i32.store8 offset=192
                                              (get_local $13)
                                              (i32.xor
                                               (i32.load8_u offset=192
                                                (get_local $13)
                                               )
                                               (i32.const -1)
                                              )
                                             )
                                             (call $assert_sha512
                                              (i32.const 8224)
                                              (i32.const 3)
                                              (i32.add
                                               (get_local $13)
                                               (i32.const 192)
                                              )
                                             )
                                             (call $eosio_assert
                                              (i32.const 0)
                                              (i32.const 9264)
                                             )
                                             (br $label$6)
                                            )
                                            (call $_ZN9test_math18test_i64_to_doubleEv)
                                            (br $label$6)
                                           )
                                           (call $_ZN5eosio18unpack_action_dataI11u128_actionEET_v
                                            (i32.add
                                             (get_local $13)
                                             (i32.const 192)
                                            )
                                           )
                                           (i64.store offset=24
                                            (get_local $13)
                                            (i64.load
                                             (i32.add
                                              (get_local $13)
                                              (i32.const 200)
                                             )
                                            )
                                           )
                                           (i64.store offset=16
                                            (get_local $13)
                                            (i64.load offset=192
                                             (get_local $13)
                                            )
                                           )
                                           (i64.store offset=8
                                            (get_local $13)
                                            (i64.load
                                             (i32.add
                                              (get_local $13)
                                              (i32.const 216)
                                             )
                                            )
                                           )
                                           (i64.store
                                            (get_local $13)
                                            (i64.load offset=208
                                             (get_local $13)
                                            )
                                           )
                                           (call $diveq_i128
                                            (i32.add
                                             (get_local $13)
                                             (i32.const 16)
                                            )
                                            (get_local $13)
                                           )
                                           (call $eosio_assert
                                            (i64.eqz
                                             (i64.or
                                              (i64.xor
                                               (i64.load offset=16
                                                (get_local $13)
                                               )
                                               (i64.load offset=224
                                                (get_local $13)
                                               )
                                              )
                                              (i64.xor
                                               (i64.load offset=24
                                                (get_local $13)
                                               )
                                               (i64.load
                                                (i32.add
                                                 (get_local $13)
                                                 (i32.const 232)
                                                )
                                               )
                                              )
                                             )
                                            )
                                            (i32.const 5984)
                                           )
                                           (br $label$6)
                                          )
                                          (call $_ZN11test_crypto17ripemd160_no_dataEv)
                                          (br $label$6)
                                         )
                                         (call $_ZN11test_crypto9test_sha1Ev)
                                         (br $label$6)
                                        )
                                        (call $_ZN16test_transaction19send_action_recurseEv)
                                        (br $label$6)
                                       )
                                       (drop
                                        (call $read_action_data
                                         (i32.add
                                          (get_local $13)
                                          (i32.const 192)
                                         )
                                         (i32.const 4)
                                        )
                                       )
                                       (call $eosio_assert
                                        (i32.eq
                                         (i32.load offset=192
                                          (get_local $13)
                                         )
                                         (call $tapos_block_num)
                                        )
                                        (i32.const 17664)
                                       )
                                       (br $label$6)
                                      )
                                      (call $ripemd160
                                       (i32.const 8224)
                                       (i32.const 3)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $assert_ripemd160
                                       (i32.const 8224)
                                       (i32.const 3)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $ripemd160
                                       (i32.const 8256)
                                       (i32.const 56)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $assert_ripemd160
                                       (i32.const 8256)
                                       (i32.const 56)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $ripemd160
                                       (i32.const 8336)
                                       (i32.const 112)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $assert_ripemd160
                                       (i32.const 8336)
                                       (i32.const 112)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $ripemd160
                                       (i32.const 8480)
                                       (i32.const 14)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (call $assert_ripemd160
                                       (i32.const 8480)
                                       (i32.const 14)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                      )
                                      (br $label$6)
                                     )
                                     (drop
                                      (call $read_action_data
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                       (i32.const 132)
                                      )
                                     )
                                     (drop
                                      (call $recover_key
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 192)
                                       )
                                       (i32.add
                                        (i32.add
                                         (get_local $13)
                                         (i32.const 192)
                                        )
                                        (i32.const 66)
                                       )
                                       (i32.const 66)
                                       (i32.add
                                        (get_local $13)
                                        (i32.const 16)
                                       )
                                       (i32.const 34)
                                      )
                                     )
                                     (set_local $3
                                      (i32.add
                                       (get_local $13)
                                       (i32.const 224)
                                      )
                                     )
                                     (set_local $6
                                      (i32.const 0)
                                     )
                                     (loop $label$145
                                      (block $label$146
                                       (br_if $label$146
                                        (i32.eq
                                         (i32.load8_u
                                          (i32.add
                                           (i32.add
                                            (get_local $13)
                                            (i32.const 16)
                                           )
                                           (get_local $6)
                                          )
                                         )
                                         (i32.load8_u
                                          (i32.add
                                           (get_local $3)
                                           (get_local $6)
                                          )
                                         )
                                        )
                                       )
                                       (call $eosio_assert
                                        (i32.const 0)
                                        (i32.const 8192)
                                       )
                                      )
                                      (br_if $label$145
                                       (i32.ne
                                        (tee_local $6
                                         (i32.add
                                          (get_local $6)
                                          (i32.const 1)
                                         )
                                        )
                                        (i32.const 34)
                                       )
                                      )
                                      (br $label$6)
                                     )
                                    )
                                    (call $_ZN16test_transaction17send_action_largeEv)
                                    (br $label$6)
                                   )
                                   (call $_ZN16test_transaction22send_transaction_largeEyyy
                                    (get_local $0)
                                    (get_local $8)
                                    (get_local $8)
                                   )
                                   (br $label$6)
                                  )
                                  (call $_ZN10test_print11test_printnEv)
                                  (br $label$6)
                                 )
                                 (call $printi
                                  (i64.const 0)
                                 )
                                 (call $printi
                                  (i64.const 556644)
                                 )
                                 (call $printi
                                  (i64.const -1)
                                 )
                                 (br $label$6)
                                )
                                (call $_ZN16test_transaction18send_action_senderEyyy
                                 (get_local $0)
                                 (get_local $8)
                                 (get_local $8)
                                )
                                (br $label$6)
                               )
                               (call $_ZN16test_transaction38send_transaction_trigger_error_handlerEyyy
                                (get_local $0)
                                (get_local $8)
                                (get_local $8)
                               )
                               (br $label$6)
                              )
                              (call $eosio_assert
                               (i32.const 1)
                               (i32.const 5328)
                              )
                              (call $eosio_assert
                               (i32.const 1)
                               (i32.const 5392)
                              )
                              (br $label$6)
                             )
                             (set_local $7
                              (i64.const 0)
                             )
                             (set_local $10
                              (i64.const 1)
                             )
                             (set_local $8
                              (i64.const 0)
                             )
                             (loop $label$147
                              (set_local $7
                               (i64.add
                                (i64.and
                                 (tee_local $9
                                  (get_local $7)
                                 )
                                 (i64.const 4294967295)
                                )
                                (get_local $8)
                               )
                              )
                              (set_local $8
                               (i64.add
                                (get_local $8)
                                (i64.const 1)
                               )
                              )
                              (br_if $label$147
                               (i64.ne
                                (tee_local $10
                                 (i64.add
                                  (get_local $10)
                                  (i64.const -1)
                                 )
                                )
                                (i64.const 8446744073709551617)
                               )
                              )
                             )
                             (call $printi
                              (i64.shr_s
                               (i64.shl
                                (i64.sub
                                 (get_local $9)
                                 (get_local $10)
                                )
                                (i64.const 32)
                               )
                               (i64.const 32)
                              )
                             )
                             (br $label$6)
                            )
                            (call $_ZN11test_crypto11test_sha512Ev)
                            (br $label$6)
                           )
                           (call $_ZN16test_transaction25send_deferred_transactionEyyy
                            (get_local $0)
                            (get_local $8)
                            (get_local $8)
                           )
                           (br $label$6)
                          )
                          (call $sha512
                           (i32.const 8224)
                           (i32.const 3)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $assert_sha512
                           (i32.const 8224)
                           (i32.const 3)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $sha512
                           (i32.const 8256)
                           (i32.const 56)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $assert_sha512
                           (i32.const 8256)
                           (i32.const 56)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $sha512
                           (i32.const 8336)
                           (i32.const 112)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $assert_sha512
                           (i32.const 8336)
                           (i32.const 112)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $sha512
                           (i32.const 8480)
                           (i32.const 14)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (call $assert_sha512
                           (i32.const 8480)
                           (i32.const 14)
                           (i32.add
                            (get_local $13)
                            (i32.const 192)
                           )
                          )
                          (br $label$6)
                         )
                         (call $eosio_assert
                          (i64.eq
                           (call $double_mult
                            (i64.const 5)
                            (i64.const 10)
                           )
                           (call $double_mult
                            (i64.const 5)
                            (i64.const 10)
                           )
                          )
                          (i32.const 8096)
                         )
                         (br $label$6)
                        )
                        (call $_ZN15test_permission19check_authorizationEyyy
                         (get_local $0)
                         (get_local $8)
                         (get_local $8)
                        )
                        (br $label$6)
                       )
                       (call $_ZN16test_transaction11send_actionEv)
                       (br $label$6)
                      )
                      (call $eosio_assert
                       (i32.const 0)
                       (i32.const 5712)
                      )
                      (call $eosio_assert
                       (i32.const 0)
                       (i32.const 5712)
                      )
                      (call $eosio_assert
                       (i32.const 0)
                       (i32.const 5856)
                      )
                      (br $label$6)
                     )
                     (call $_ZN9test_math15test_double_apiEv)
                     (br $label$6)
                    )
                    (call $sha256
                     (i32.const 0)
                     (i32.const 100)
                     (i32.add
                      (get_local $13)
                      (i32.const 192)
                     )
                    )
                    (br $label$6)
                   )
                   (call $_ZN16test_transaction19send_cf_action_failEv)
                   (br $label$6)
                  )
                  (call $sha256
                   (i32.const 8224)
                   (i32.const 3)
                   (i32.add
                    (get_local $13)
                    (i32.const 192)
                   )
                  )
                  (i32.store8 offset=192
                   (get_local $13)
                   (i32.xor
                    (i32.load8_u offset=192
                     (get_local $13)
                    )
                    (i32.const -1)
                   )
                  )
                  (call $assert_sha256
                   (i32.const 8224)
                   (i32.const 3)
                   (i32.add
                    (get_local $13)
                    (i32.const 192)
                   )
                  )
                  (call $eosio_assert
                   (i32.const 0)
                   (i32.const 9264)
                  )
                  (br $label$6)
                 )
                 (call $_ZN16test_transaction14send_cf_actionEv)
                 (br $label$6)
                )
                (i32.store16 offset=192
                 (get_local $13)
                 (i32.const 25185)
                )
                (call $prints_l
                 (i32.add
                  (get_local $13)
                  (i32.const 192)
                 )
                 (i32.const 2)
                )
                (call $prints_l
                 (i32.add
                  (get_local $13)
                  (i32.const 192)
                 )
                 (i32.const 1)
                )
                (call $prints_l
                 (i32.add
                  (get_local $13)
                  (i32.const 192)
                 )
                 (i32.const 0)
                )
                (call $prints_l
                 (i32.const 864)
                 (i32.const 4)
                )
                (br $label$6)
               )
               (i64.store offset=200
                (get_local $13)
                (i64.const 0)
               )
               (i64.store offset=192
                (get_local $13)
                (i64.const -1)
               )
               (call $cancel_deferred
                (i32.add
                 (get_local $13)
                 (i32.const 192)
                )
               )
               (br $label$6)
              )
              (call $eosio_assert
               (i32.const 1)
               (i32.const 5456)
              )
              (call $eosio_assert
               (i32.const 1)
               (i32.const 5456)
              )
              (call $eosio_assert
               (i32.const 1)
               (i32.const 5520)
              )
              (call $eosio_assert
               (i32.const 1)
               (i32.const 5520)
              )
              (br $label$6)
             )
             (call $_ZN5eosio18unpack_action_dataI11u128_actionEET_v
              (i32.add
               (get_local $13)
               (i32.const 192)
              )
             )
             (i64.store offset=24
              (get_local $13)
              (i64.load
               (i32.add
                (get_local $13)
                (i32.const 200)
               )
              )
             )
             (i64.store offset=16
              (get_local $13)
              (i64.load offset=192
               (get_local $13)
              )
             )
             (i64.store offset=8
              (get_local $13)
              (i64.load
               (i32.add
                (get_local $13)
                (i32.const 216)
               )
              )
             )
             (i64.store
              (get_local $13)
              (i64.load offset=208
               (get_local $13)
              )
             )
             (call $multeq_i128
              (i32.add
               (get_local $13)
               (i32.const 16)
              )
              (get_local $13)
             )
             (call $eosio_assert
              (i64.eqz
               (i64.or
                (i64.xor
                 (i64.load offset=16
                  (get_local $13)
                 )
                 (i64.load offset=224
                  (get_local $13)
                 )
                )
                (i64.xor
                 (i64.load offset=24
                  (get_local $13)
                 )
                 (i64.load
                  (i32.add
                   (get_local $13)
                   (i32.const 232)
                  )
                 )
                )
               )
              )
              (i32.const 5888)
             )
             (br $label$6)
            )
            (call $_ZN11test_crypto12sha1_no_dataEv)
            (br $label$6)
           )
           (call $_ZN16test_transaction23send_action_inline_failEv)
           (br $label$6)
          )
          (call $sha256
           (i32.const 8224)
           (i32.const 3)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $assert_sha256
           (i32.const 8224)
           (i32.const 3)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $sha256
           (i32.const 8256)
           (i32.const 56)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $assert_sha256
           (i32.const 8256)
           (i32.const 56)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $sha256
           (i32.const 8336)
           (i32.const 112)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $assert_sha256
           (i32.const 8336)
           (i32.const 112)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $sha256
           (i32.const 8480)
           (i32.const 14)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (call $assert_sha256
           (i32.const 8480)
           (i32.const 14)
           (i32.add
            (get_local $13)
            (i32.const 192)
           )
          )
          (br $label$6)
         )
         (drop
          (call $double_div
           (call $i64_to_double
            (i64.const 5)
           )
           (call $i64_to_double
            (i64.const 0)
           )
          )
         )
         (call $eosio_assert
          (i32.const 0)
          (i32.const 5856)
         )
         (br $label$6)
        )
        (call $printui
         (i64.const 0)
        )
        (call $printui
         (i64.const 556644)
        )
        (call $printui
         (i64.const -1)
        )
        (br $label$6)
       )
       (call $_ZN16test_transaction18read_inline_actionEv)
       (br $label$6)
      )
      (set_local $3
       (i32.const 0)
      )
      (call $sha512
       (i32.const 9088)
       (i32.const 0)
       (i32.add
        (get_local $13)
        (i32.const 192)
       )
      )
      (set_local $6
       (i32.const 0)
      )
      (block $label$148
       (loop $label$149
        (br_if $label$148
         (i32.ne
          (i32.load8_u
           (i32.add
            (get_local $6)
            (i32.const 9168)
           )
          )
          (i32.load8_u
           (i32.add
            (i32.add
             (get_local $13)
             (i32.const 192)
            )
            (get_local $6)
           )
          )
         )
        )
        (br_if $label$149
         (i32.le_u
          (tee_local $6
           (i32.add
            (get_local $6)
            (i32.const 1)
           )
          )
          (i32.const 63)
         )
        )
       )
       (set_local $3
        (i32.const 1)
       )
      )
      (call $eosio_assert
       (get_local $3)
       (i32.const 9232)
      )
      (br $label$6)
     )
     (call $eosio_assert
      (i32.const 0)
      (i32.const 18816)
     )
     (br $label$6)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_out_of_rangeEv
     (i32.add
      (get_local $13)
      (i32.const 228)
     )
    )
    (unreachable)
   )
   (call $abort)
   (unreachable)
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $13)
    (i32.const 368)
   )
  )
 )
 (func $_ZN5eosio18unpack_action_dataINS_20deferred_transactionEEET_v (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (get_local $4)
     (i32.and
      (i32.add
       (tee_local $1
        (call $action_data_size)
       )
       (i32.const 15)
      )
      (i32.const -16)
     )
    )
   )
  )
  (drop
   (call $read_action_data
    (get_local $2)
    (get_local $1)
   )
  )
  (set_local $3
   (call $now)
  )
  (i32.store16 offset=4
   (get_local $0)
   (i32.const 0)
  )
  (i32.store offset=12
   (get_local $0)
   (i32.const 0)
  )
  (i32.store offset=16
   (get_local $0)
   (i32.const 0)
  )
  (i32.store offset=20
   (get_local $0)
   (i32.const 0)
  )
  (i32.store offset=24
   (get_local $0)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 28)
   )
   (i32.const 0)
  )
  (i32.store
   (get_local $0)
   (i32.add
    (get_local $3)
    (i32.const 60)
   )
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 32)
   )
   (i32.const 0)
  )
  (i32.store offset=36
   (get_local $0)
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 40)
   )
   (i32.const 0)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 44)
   )
   (i32.const 0)
  )
  (i32.store offset=4
   (tee_local $4
    (get_local $4)
   )
   (get_local $2)
  )
  (i32.store
   (get_local $4)
   (get_local $2)
  )
  (i32.store offset=8
   (get_local $4)
   (i32.add
    (get_local $2)
    (get_local $1)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNS_20deferred_transactionE
    (get_local $4)
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
  )
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNS_20deferred_transactionE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNS_18transaction_headerE
    (get_local $0)
    (get_local $1)
   )
  )
  (drop
   (call $_ZN5eosiorsINS_10datastreamIPKcEENS_6actionEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE
    (call $_ZN5eosiorsINS_10datastreamIPKcEENS_6actionEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE
     (get_local $0)
     (i32.add
      (get_local $1)
      (i32.const 24)
     )
    )
    (i32.add
     (get_local $1)
     (i32.const 36)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (i32.load offset=4
      (get_local $0)
     )
    )
    (i32.const 15)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 48)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 16)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $2
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 16)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $2)
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 64)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $2
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 8)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $2)
    )
    (i32.const 7)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 72)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 8)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $2
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 8)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $2)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 80)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 4)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (i32.add
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 4)
   )
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNS_18transaction_headerE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i32)
  (local $7 i32)
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (i32.load offset=4
      (get_local $0)
     )
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (get_local $1)
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 4)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 4)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 1)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 2)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 2)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 1)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 6)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 2)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 2)
    )
   )
  )
  (call $eosio_assert
   (i32.gt_u
    (i32.sub
     (i32.load offset=8
      (get_local $0)
     )
     (get_local $7)
    )
    (i32.const 3)
   )
   (i32.const 720)
  )
  (drop
   (call $memcpy
    (i32.add
     (get_local $1)
     (i32.const 8)
    )
    (i32.load offset=4
     (get_local $0)
    )
    (i32.const 4)
   )
  )
  (i32.store offset=4
   (get_local $0)
   (tee_local $7
    (i32.add
     (i32.load offset=4
      (get_local $0)
     )
     (i32.const 4)
    )
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
     )
    )
    (i32.const 768)
   )
   (set_local $2
    (i32.load8_u
     (tee_local $7
      (i32.load
       (tee_local $4
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
       )
      )
     )
    )
   )
   (i32.store
    (get_local $4)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $2)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $2)
     (i32.const 7)
    )
   )
  )
  (i64.store32 offset=12
   (get_local $1)
   (get_local $5)
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$1
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (get_local $3)
     )
    )
    (i32.const 768)
   )
   (set_local $2
    (i32.load8_u
     (tee_local $7
      (i32.load
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (get_local $4)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $2)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$1
    (i32.shr_u
     (get_local $2)
     (i32.const 7)
    )
   )
  )
  (i64.store32 offset=16
   (get_local $1)
   (get_local $5)
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $4
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$2
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (get_local $3)
     )
    )
    (i32.const 768)
   )
   (set_local $2
    (i32.load8_u
     (tee_local $7
      (i32.load
       (get_local $4)
      )
     )
    )
   )
   (i32.store
    (get_local $4)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $2)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$2
    (i32.shr_u
     (get_local $2)
     (i32.const 7)
    )
   )
  )
  (i64.store32 offset=20
   (get_local $1)
   (get_local $5)
  )
  (get_local $0)
 )
 (func $_ZN5eosiorsINS_10datastreamIPKcEENS_6actionEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i64)
  (local $6 i32)
  (local $7 i32)
  (set_local $7
   (i32.load offset=4
    (get_local $0)
   )
  )
  (set_local $6
   (i32.const 0)
  )
  (set_local $5
   (i64.const 0)
  )
  (set_local $2
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (set_local $3
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
  )
  (loop $label$0
   (call $eosio_assert
    (i32.lt_u
     (get_local $7)
     (i32.load
      (get_local $2)
     )
    )
    (i32.const 768)
   )
   (set_local $4
    (i32.load8_u
     (tee_local $7
      (i32.load
       (get_local $3)
      )
     )
    )
   )
   (i32.store
    (get_local $3)
    (tee_local $7
     (i32.add
      (get_local $7)
      (i32.const 1)
     )
    )
   )
   (set_local $5
    (i64.or
     (i64.extend_u/i32
      (i32.shl
       (i32.and
        (get_local $4)
        (i32.const 127)
       )
       (tee_local $6
        (i32.and
         (get_local $6)
         (i32.const 255)
        )
       )
      )
     )
     (get_local $5)
    )
   )
   (set_local $6
    (i32.add
     (get_local $6)
     (i32.const 7)
    )
   )
   (br_if $label$0
    (i32.shr_u
     (get_local $4)
     (i32.const 7)
    )
   )
  )
  (block $label$1
   (block $label$2
    (br_if $label$2
     (i32.le_u
      (tee_local $4
       (i32.wrap/i64
        (get_local $5)
       )
      )
      (tee_local $7
       (i32.div_s
        (i32.sub
         (tee_local $2
          (i32.load offset=4
           (get_local $1)
          )
         )
         (tee_local $6
          (i32.load
           (get_local $1)
          )
         )
        )
        (i32.const 40)
       )
      )
     )
    )
    (call $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE8__appendEj
     (get_local $1)
     (i32.sub
      (get_local $4)
      (get_local $7)
     )
    )
    (set_local $2
     (i32.load
      (i32.add
       (get_local $1)
       (i32.const 4)
      )
     )
    )
    (br $label$1)
   )
   (br_if $label$1
    (i32.ge_u
     (get_local $4)
     (get_local $7)
    )
   )
   (block $label$3
    (br_if $label$3
     (i32.eq
      (get_local $2)
      (tee_local $3
       (i32.add
        (get_local $6)
        (tee_local $4
         (i32.mul
          (get_local $4)
          (i32.const 40)
         )
        )
       )
      )
     )
    )
    (set_local $6
     (i32.sub
      (i32.sub
       (i32.const 0)
       (get_local $6)
      )
      (get_local $4)
     )
    )
    (set_local $4
     (i32.add
      (get_local $2)
      (i32.const -24)
     )
    )
    (loop $label$4
     (block $label$5
      (br_if $label$5
       (i32.eqz
        (tee_local $7
         (i32.load
          (i32.add
           (get_local $4)
           (i32.const 12)
          )
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $4)
        (i32.const 16)
       )
       (get_local $7)
      )
      (call $_ZdlPv
       (get_local $7)
      )
     )
     (block $label$6
      (br_if $label$6
       (i32.eqz
        (tee_local $7
         (i32.load
          (get_local $4)
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $4)
        (i32.const 4)
       )
       (get_local $7)
      )
      (call $_ZdlPv
       (get_local $7)
      )
     )
     (br_if $label$4
      (i32.ne
       (i32.add
        (tee_local $4
         (i32.add
          (get_local $4)
          (i32.const -40)
         )
        )
        (get_local $6)
       )
       (i32.const -24)
      )
     )
    )
   )
   (i32.store
    (i32.add
     (get_local $1)
     (i32.const 4)
    )
    (get_local $3)
   )
   (set_local $2
    (get_local $3)
   )
  )
  (block $label$7
   (br_if $label$7
    (i32.eq
     (tee_local $7
      (i32.load
       (get_local $1)
      )
     )
     (get_local $2)
    )
   )
   (set_local $4
    (i32.add
     (get_local $0)
     (i32.const 4)
    )
   )
   (loop $label$8
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (tee_local $6
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
        )
       )
       (i32.load
        (get_local $4)
       )
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (get_local $7)
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (tee_local $3
      (i32.add
       (i32.load
        (get_local $4)
       )
       (i32.const 8)
      )
     )
    )
    (call $eosio_assert
     (i32.gt_u
      (i32.sub
       (i32.load
        (get_local $6)
       )
       (get_local $3)
      )
      (i32.const 7)
     )
     (i32.const 720)
    )
    (drop
     (call $memcpy
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (i32.store
     (get_local $4)
     (i32.add
      (i32.load
       (get_local $4)
      )
      (i32.const 8)
     )
    )
    (drop
     (call $_ZN5eosiorsINS_10datastreamIPKcEEEERT_S6_RNSt3__16vectorIcNS7_9allocatorIcEEEE
      (call $_ZN5eosiorsINS_10datastreamIPKcEENS_16permission_levelEEERT_S7_RNSt3__16vectorIT0_NS8_9allocatorISA_EEEE
       (get_local $0)
       (i32.add
        (get_local $7)
        (i32.const 16)
       )
      )
      (i32.add
       (get_local $7)
       (i32.const 28)
      )
     )
    )
    (br_if $label$8
     (i32.ne
      (tee_local $7
       (i32.add
        (get_local $7)
        (i32.const 40)
       )
      )
      (get_local $2)
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZNSt3__16vectorIN5eosio6actionENS_9allocatorIS2_EEE8__appendEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (block $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (br_if $label$4
        (i32.ge_u
         (i32.div_s
          (i32.sub
           (tee_local $8
            (i32.load offset=8
             (get_local $0)
            )
           )
           (tee_local $7
            (i32.load offset=4
             (get_local $0)
            )
           )
          )
          (i32.const 40)
         )
         (get_local $1)
        )
       )
       (br_if $label$2
        (i32.ge_u
         (tee_local $6
          (i32.add
           (tee_local $5
            (i32.div_s
             (i32.sub
              (get_local $7)
              (tee_local $4
               (i32.load
                (get_local $0)
               )
              )
             )
             (i32.const 40)
            )
           )
           (get_local $1)
          )
         )
         (i32.const 107374183)
        )
       )
       (set_local $7
        (i32.const 107374182)
       )
       (block $label$5
        (br_if $label$5
         (i32.gt_u
          (tee_local $8
           (i32.div_s
            (i32.sub
             (get_local $8)
             (get_local $4)
            )
            (i32.const 40)
           )
          )
          (i32.const 53687090)
         )
        )
        (br_if $label$3
         (i32.eqz
          (tee_local $7
           (select
            (get_local $6)
            (tee_local $7
             (i32.shl
              (get_local $8)
              (i32.const 1)
             )
            )
            (i32.lt_u
             (get_local $7)
             (get_local $6)
            )
           )
          )
         )
        )
       )
       (set_local $8
        (call $_Znwj
         (i32.mul
          (get_local $7)
          (i32.const 40)
         )
        )
       )
       (br $label$1)
      )
      (set_local $8
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
      (loop $label$6
       (i64.store
        (get_local $7)
        (i64.const 0)
       )
       (i64.store offset=16 align=4
        (get_local $7)
        (i64.const 0)
       )
       (i64.store
        (i32.add
         (get_local $7)
         (i32.const 8)
        )
        (i64.const 0)
       )
       (i64.store align=4
        (i32.add
         (get_local $7)
         (i32.const 24)
        )
        (i64.const 0)
       )
       (i64.store align=4
        (i32.add
         (get_local $7)
         (i32.const 32)
        )
        (i64.const 0)
       )
       (i32.store
        (get_local $8)
        (tee_local $7
         (i32.add
          (i32.load
           (get_local $8)
          )
          (i32.const 40)
         )
        )
       )
       (br_if $label$6
        (tee_local $1
         (i32.add
          (get_local $1)
          (i32.const -1)
         )
        )
       )
       (br $label$0)
      )
     )
     (set_local $7
      (i32.const 0)
     )
     (set_local $8
      (i32.const 0)
     )
     (br $label$1)
    )
    (call $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
     (get_local $0)
    )
    (unreachable)
   )
   (set_local $2
    (i32.add
     (get_local $8)
     (i32.mul
      (get_local $7)
      (i32.const 40)
     )
    )
   )
   (set_local $7
    (tee_local $8
     (i32.add
      (get_local $8)
      (i32.mul
       (get_local $5)
       (i32.const 40)
      )
     )
    )
   )
   (loop $label$7
    (i64.store
     (get_local $7)
     (i64.const 0)
    )
    (i64.store offset=16 align=4
     (get_local $7)
     (i64.const 0)
    )
    (i64.store
     (i32.add
      (get_local $7)
      (i32.const 8)
     )
     (i64.const 0)
    )
    (i64.store align=4
     (i32.add
      (get_local $7)
      (i32.const 24)
     )
     (i64.const 0)
    )
    (i64.store align=4
     (i32.add
      (get_local $7)
      (i32.const 32)
     )
     (i64.const 0)
    )
    (set_local $7
     (i32.add
      (get_local $7)
      (i32.const 40)
     )
    )
    (br_if $label$7
     (tee_local $1
      (i32.add
       (get_local $1)
       (i32.const -1)
      )
     )
    )
   )
   (block $label$8
    (block $label$9
     (br_if $label$9
      (i32.eq
       (tee_local $1
        (i32.load
         (i32.add
          (get_local $0)
          (i32.const 4)
         )
        )
       )
       (tee_local $4
        (i32.load
         (get_local $0)
        )
       )
      )
     )
     (set_local $3
      (i32.sub
       (i32.const 0)
       (get_local $4)
      )
     )
     (set_local $1
      (i32.add
       (get_local $1)
       (i32.const -20)
      )
     )
     (loop $label$10
      (i64.store
       (i32.add
        (get_local $8)
        (i32.const -32)
       )
       (i64.load
        (i32.add
         (get_local $1)
         (i32.const -12)
        )
       )
      )
      (i64.store
       (i32.add
        (get_local $8)
        (i32.const -40)
       )
       (i64.load
        (i32.add
         (get_local $1)
         (i32.const -20)
        )
       )
      )
      (i64.store align=4
       (tee_local $4
        (i32.add
         (get_local $8)
         (i32.const -24)
        )
       )
       (i64.const 0)
      )
      (i32.store
       (tee_local $5
        (i32.add
         (get_local $8)
         (i32.const -16)
        )
       )
       (i32.const 0)
      )
      (i32.store
       (get_local $4)
       (i32.load
        (tee_local $6
         (i32.add
          (get_local $1)
          (i32.const -4)
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $8)
        (i32.const -20)
       )
       (i32.load
        (get_local $1)
       )
      )
      (i32.store
       (get_local $5)
       (i32.load
        (tee_local $4
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
      )
      (i32.store
       (get_local $4)
       (i32.const 0)
      )
      (i64.store align=4
       (tee_local $4
        (i32.add
         (get_local $8)
         (i32.const -12)
        )
       )
       (i64.const 0)
      )
      (i64.store align=4
       (get_local $6)
       (i64.const 0)
      )
      (i32.store
       (tee_local $5
        (i32.add
         (get_local $8)
         (i32.const -4)
        )
       )
       (i32.const 0)
      )
      (i32.store
       (get_local $4)
       (i32.load
        (tee_local $6
         (i32.add
          (get_local $1)
          (i32.const 8)
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $8)
        (i32.const -8)
       )
       (i32.load
        (i32.add
         (get_local $1)
         (i32.const 12)
        )
       )
      )
      (i32.store
       (get_local $5)
       (i32.load
        (tee_local $4
         (i32.add
          (get_local $1)
          (i32.const 16)
         )
        )
       )
      )
      (i32.store
       (get_local $4)
       (i32.const 0)
      )
      (i64.store align=4
       (get_local $6)
       (i64.const 0)
      )
      (set_local $8
       (i32.add
        (get_local $8)
        (i32.const -40)
       )
      )
      (br_if $label$10
       (i32.ne
        (i32.add
         (tee_local $1
          (i32.add
           (get_local $1)
           (i32.const -40)
          )
         )
         (get_local $3)
        )
        (i32.const -20)
       )
      )
     )
     (set_local $4
      (i32.load
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
     )
     (set_local $5
      (i32.load
       (get_local $0)
      )
     )
     (br $label$8)
    )
    (set_local $5
     (get_local $4)
    )
   )
   (i32.store
    (get_local $0)
    (get_local $8)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 4)
    )
    (get_local $7)
   )
   (i32.store
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
    (get_local $2)
   )
   (block $label$11
    (br_if $label$11
     (i32.eq
      (get_local $4)
      (get_local $5)
     )
    )
    (set_local $1
     (i32.sub
      (i32.const 0)
      (get_local $5)
     )
    )
    (set_local $7
     (i32.add
      (get_local $4)
      (i32.const -24)
     )
    )
    (loop $label$12
     (block $label$13
      (br_if $label$13
       (i32.eqz
        (tee_local $8
         (i32.load
          (i32.add
           (get_local $7)
           (i32.const 12)
          )
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $7)
        (i32.const 16)
       )
       (get_local $8)
      )
      (call $_ZdlPv
       (get_local $8)
      )
     )
     (block $label$14
      (br_if $label$14
       (i32.eqz
        (tee_local $8
         (i32.load
          (get_local $7)
         )
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $7)
        (i32.const 4)
       )
       (get_local $8)
      )
      (call $_ZdlPv
       (get_local $8)
      )
     )
     (br_if $label$12
      (i32.ne
       (i32.add
        (tee_local $7
         (i32.add
          (get_local $7)
          (i32.const -40)
         )
        )
        (get_local $1)
       )
       (i32.const -24)
      )
     )
    )
   )
   (br_if $label$0
    (i32.eqz
     (get_local $5)
    )
   )
   (call $_ZdlPv
    (get_local $5)
   )
  )
 )
 (func $_Znwj (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (block $label$0
   (br_if $label$0
    (tee_local $0
     (call $malloc
      (tee_local $1
       (select
        (get_local $0)
        (i32.const 1)
        (get_local $0)
       )
      )
     )
    )
   )
   (loop $label$1
    (set_local $0
     (i32.const 0)
    )
    (br_if $label$0
     (i32.eqz
      (tee_local $2
       (i32.load offset=18832
        (i32.const 0)
       )
      )
     )
    )
    (call_indirect $FUNCSIG$v
     (get_local $2)
    )
    (br_if $label$1
     (i32.eqz
      (tee_local $0
       (call $malloc
        (get_local $1)
       )
      )
     )
    )
   )
  )
  (get_local $0)
 )
 (func $_ZdlPv (param $0 i32)
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (get_local $0)
    )
   )
   (call $free
    (get_local $0)
   )
  )
 )
 (func $_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv (param $0 i32)
  (call $abort)
  (unreachable)
 )
 (func $_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEj (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (block $label$0
   (br_if $label$0
    (i32.ge_u
     (get_local $1)
     (i32.const -16)
    )
   )
   (set_local $2
    (i32.const 10)
   )
   (block $label$1
    (br_if $label$1
     (i32.eqz
      (i32.and
       (tee_local $5
        (i32.load8_u
         (get_local $0)
        )
       )
       (i32.const 1)
      )
     )
    )
    (set_local $2
     (i32.add
      (i32.and
       (tee_local $5
        (i32.load
         (get_local $0)
        )
       )
       (i32.const -2)
      )
      (i32.const -1)
     )
    )
   )
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.and
       (get_local $5)
       (i32.const 1)
      )
     )
     (set_local $3
      (i32.shr_u
       (i32.and
        (get_local $5)
        (i32.const 254)
       )
       (i32.const 1)
      )
     )
     (br $label$2)
    )
    (set_local $3
     (i32.load offset=4
      (get_local $0)
     )
    )
   )
   (set_local $4
    (i32.const 10)
   )
   (block $label$4
    (br_if $label$4
     (i32.lt_u
      (tee_local $1
       (select
        (get_local $3)
        (get_local $1)
        (i32.gt_u
         (get_local $3)
         (get_local $1)
        )
       )
      )
      (i32.const 11)
     )
    )
    (set_local $4
     (i32.add
      (i32.and
       (i32.add
        (get_local $1)
        (i32.const 16)
       )
       (i32.const -16)
      )
      (i32.const -1)
     )
    )
   )
   (block $label$5
    (br_if $label$5
     (i32.eq
      (get_local $4)
      (get_local $2)
     )
    )
    (block $label$6
     (block $label$7
      (br_if $label$7
       (i32.ne
        (get_local $4)
        (i32.const 10)
       )
      )
      (set_local $6
       (i32.const 1)
      )
      (set_local $1
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (set_local $2
       (i32.load offset=8
        (get_local $0)
       )
      )
      (set_local $7
       (i32.const 0)
      )
      (br $label$6)
     )
     (set_local $1
      (call $_Znwj
       (i32.add
        (get_local $4)
        (i32.const 1)
       )
      )
     )
     (block $label$8
      (br_if $label$8
       (i32.gt_u
        (get_local $4)
        (get_local $2)
       )
      )
      (br_if $label$5
       (i32.eqz
        (get_local $1)
       )
      )
     )
     (block $label$9
      (br_if $label$9
       (i32.and
        (tee_local $5
         (i32.load8_u
          (get_local $0)
         )
        )
        (i32.const 1)
       )
      )
      (set_local $7
       (i32.const 1)
      )
      (set_local $2
       (i32.add
        (get_local $0)
        (i32.const 1)
       )
      )
      (set_local $6
       (i32.const 0)
      )
      (br $label$6)
     )
     (set_local $2
      (i32.load offset=8
       (get_local $0)
      )
     )
     (set_local $6
      (i32.const 1)
     )
     (set_local $7
      (i32.const 1)
     )
    )
    (block $label$10
     (block $label$11
      (br_if $label$11
       (i32.and
        (get_local $5)
        (i32.const 1)
       )
      )
      (set_local $5
       (i32.shr_u
        (i32.and
         (get_local $5)
         (i32.const 254)
        )
        (i32.const 1)
       )
      )
      (br $label$10)
     )
     (set_local $5
      (i32.load offset=4
       (get_local $0)
      )
     )
    )
    (block $label$12
     (br_if $label$12
      (i32.eqz
       (tee_local $5
        (i32.add
         (get_local $5)
         (i32.const 1)
        )
       )
      )
     )
     (drop
      (call $memcpy
       (get_local $1)
       (get_local $2)
       (get_local $5)
      )
     )
    )
    (block $label$13
     (br_if $label$13
      (i32.eqz
       (get_local $6)
      )
     )
     (call $_ZdlPv
      (get_local $2)
     )
    )
    (block $label$14
     (br_if $label$14
      (i32.eqz
       (get_local $7)
      )
     )
     (i32.store offset=4
      (get_local $0)
      (get_local $3)
     )
     (i32.store offset=8
      (get_local $0)
      (get_local $1)
     )
     (i32.store
      (get_local $0)
      (i32.or
       (i32.add
        (get_local $4)
        (i32.const 1)
       )
       (i32.const 1)
      )
     )
     (return)
    )
    (i32.store8
     (get_local $0)
     (i32.shl
      (get_local $3)
      (i32.const 1)
     )
    )
   )
   (return)
  )
  (call $abort)
  (unreachable)
 )
 (func $_ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv (param $0 i32)
  (call $abort)
  (unreachable)
 )
 (func $_ZNKSt3__120__vector_base_commonILb1EE20__throw_out_of_rangeEv (param $0 i32)
  (call $abort)
  (unreachable)
 )
 (func $_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_ (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i64.store align=4
   (get_local $0)
   (i64.const 0)
  )
  (i32.store
   (tee_local $3
    (i32.add
     (get_local $0)
     (i32.const 8)
    )
   )
   (i32.const 0)
  )