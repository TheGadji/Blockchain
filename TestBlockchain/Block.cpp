#include "Block.h"
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& t, const std::string& prevHash)
    : index(idx), transactions(txs), timestamp(t), previousHash(prevHash), nonce(0)
{
    mineBlock(4); // Запускаем процесс майнинга для поиска подходящего хэша
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << previousHash << nonce;
    for (const auto& tx : transactions) {
        ss << tx.sender << tx.recipient << tx.amount;
    }
    return sha256(ss.str());
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0'); // Устанавливаем цель с заданной сложностью (количество ведущих нулей)
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
}

std::string Block::sha256(const std::string& str) const {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}
