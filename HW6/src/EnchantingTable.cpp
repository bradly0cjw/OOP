#include "EnchantingTable.hpp"
#include <stdexcept>
#include "Material.hpp"

EnchantingTable::EnchantingTable() : _enchantItem(nullptr), _consumeItem(nullptr), _output(nullptr) {}

void EnchantingTable::SetEnchantItem(std::shared_ptr<IEnchantable> enchantable) {
    _enchantItem = enchantable;
}

void EnchantingTable::SetConsumeItem(std::shared_ptr<IConsumable> consumable) {
    _consumeItem = consumable;
}

void EnchantingTable::Enchant(Enchantment e) {
    if (_output) {
        throw std::invalid_argument("Output is not empty");
    }
    if (!_enchantItem || !_consumeItem) {
        throw std::invalid_argument("Missing inputs"); // "若沒有待附魔物件以及青金石... throw"
    }
    
    // Check if consume item is Lapis
    if (_consumeItem->GetMaterial() != Material::LapisLazuli) {
        throw std::invalid_argument("Consume item must be Lapis Lazuli");
    }

    // Apply enchantment
    _enchantItem->ApplyEnchantment(e);

    // Move to output
    _output = _enchantItem;

    // Clear inputs
    _enchantItem = nullptr;
    _consumeItem = nullptr;
}

std::shared_ptr<IEnchantable> EnchantingTable::GetOutput() {
    if (!_output) {
        throw std::invalid_argument("Output is empty");
    }
    std::shared_ptr<IEnchantable> temp = _output;
    _output = nullptr;
    return temp;
}
