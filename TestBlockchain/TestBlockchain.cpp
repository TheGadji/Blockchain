#include <iostream>
#include "Blockchain.h"
#include "Transaction.h"

int main() {
    int difficulty = 4;
    Blockchain blockchain(difficulty);

    // Создаем несколько транзакций
    Transaction tx1("Rouz", "Din", 2.5);
    Transaction tx2("Din", "Sem", 1.7);
    Transaction tx3("Sem", "Rouz", 0.8);

    // Создаем блоки с транзакциями и добавляем их в блокчейн
    std::vector<Transaction> block1Transactions = { tx1, tx2 };
    blockchain.addBlock(block1Transactions);

    std::vector<Transaction> block2Transactions = { tx3 };
    blockchain.addBlock(block2Transactions);

    // Выводим содержимое блокчейна
    blockchain.printChain();

    // Проверяем целостность блокчейна
    std::cout << "Blockchain is valid: " << (blockchain.isChainValid() ? "true" : "false") << std::endl;

    return 0;
}
