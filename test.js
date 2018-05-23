Eos = require('eosjs') // Eos = require('./src')
binaryen = require('binaryen')
// Optional configuration..
config = {
  keyProvider: ['5KZ2ytRsGMxRAycpFqFnkRF8mNfZTomQKnaXzh1FtbRPgbaTAF3'], // WIF string or array of keys..
  httpEndpoint: 'http://192.168.0.127:8888',
  broadcast: true,
  sign: true,
  binaryen
}

eos = Eos.Localnet(config)
//eos.getBlock(706).then(result => {console.log(result)})
//eos.getBlock({block_num_or_id: 706}).then(result => console.log(JSON.stringify(result)))
//eos.getInfo({}).then(result => {console.log(result)})
options = {broadcast: true,sign: true}
pubkey = "EOS6qnCLMm5d67JdP11EF31Kf4UUNr6ktUKBqPsDhSXADT1CHfNG2"
try {
 //eos.transfer({from: "eosio.token", to: "jgrpsdirkmza", quantity: "1 SYS", memo: "transfer to user"}, options).then(result => {console.log(result)})
  //eos.transfer()
}
catch(err){
 console.log(err)
}

eos.transaction(tr => {
  tr.newaccount({
    creator: 'eosio.token',
    name: 'hellosam1111',
    owner: pubkey,
    active: pubkey
  })
})
//eos.transfer()
//eos.transfer('eosio.token', 'jgrpsdirkmza', '1.0000 SYS', '', false)
