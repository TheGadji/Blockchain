#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "Transaction.h"

struct Block {
    int index;
    std::string timestamp;
    std::vector<Transaction> transactions;
    std::string previousHash;
    std::string hash;
    int nonce;

    Block(int idx, const std::vector<Transaction>& txs, const std::string& t, const std::string& prevHash);

    std::string calculateHash() const;
    void mineBlock(int difficulty);
    std::string sha256(const std::string& str) const;
};

#endif  
