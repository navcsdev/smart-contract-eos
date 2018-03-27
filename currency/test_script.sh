eosiocpp -o currency.wast currency.cpp
cleos set contract currency currency.wast currency.abi
cleos push action currency balance '{"owner":"currency","symbol":"4408140"}' --permission currency@active