#define _CRT_SECURE_NO_WARNINGS
#include "Blockchain.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Blockchain::Blockchain(int diff) : difficulty(diff) {
    // Создаем первый блок (генезис-блок)
    Block genesisBlock(0, std::vector<Transaction>(), getCurrentTimestamp(), "0");
    chain.push_back(genesisBlock);
}

void Blockchain::addBlock(const std::vector<Transaction>& transactions) {
    int index = chain.size();
    std::string timestamp = getCurrentTimestamp();
    std::string previousHash = chain.back().hash;

    Block newBlock(index, transactions, timestamp, previousHash);
    chain.push_back(newBlock);
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];
       
        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }

        // Проверяем правильность хэша текущего блока
        std::string calculatedHash = currentBlock.calculateHash();
        if (currentBlock.hash != calculatedHash) {
            return false;
        }
    }
    return true;
}

void Blockchain::printChain() const {
    for (const Block& block : chain) {
        std::cout << "Block Index: " << block.index << std::endl;
        std::cout << "Timestamp: " << block.timestamp << std::endl;
        std::cout << "Previous Hash: " << block.previousHash << std::endl;
        std::cout << "Hash: " << block.hash << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

std::string Blockchain::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
