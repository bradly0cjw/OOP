#ifndef ENCHANTING_TABLE_HPP
#define ENCHANTING_TABLE_HPP

#include <memory>
#include "IEnchantable.hpp"
#include "IConsumable.hpp"
#include "Enchantment.hpp"

class EnchantingTable{
public:
    EnchantingTable();

    void SetEnchantItem(std::shared_ptr<IEnchantable> emchantable);
    void SetConsumeItem(std::shared_ptr<IConsumable> comsumable);
    void Enchant(Enchantment e);
    std::shared_ptr<IEnchantable> GetOutput();

private:
    std::shared_ptr<IEnchantable> _enchantItem;
    std::shared_ptr<IConsumable> _consumeItem;
    std::shared_ptr<IEnchantable> _output;
};

#endif