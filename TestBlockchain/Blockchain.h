#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;

public:
    Blockchain(int diff);

    void addBlock(const std::vector<Transaction>& transactions);
    const std::vector<Block>& getChain() const;
    bool isChainValid() const;
    void printChain() const;

private:
    std::string getCurrentTimestamp() const;
};

#endif  
