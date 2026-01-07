#include "CraftingTable.hpp"
#include <stdexcept>
#include "Material.hpp"
#include "Armor.hpp"
#include "Pickaxe.hpp"

CraftingTable::CraftingTable() : _craftInput(nullptr), _materialInput(nullptr), _output(nullptr) {}

void CraftingTable::SetCraftInput(std::shared_ptr<IConsumable> craftableItem) {
    if (!craftableItem) {
        // "若 Input 欄位為 nullptr ，應該 throw". Actually Set probably just sets it, 
        // but the table valid check is crucial.
        // Wait, "In Use SetCraftInput when putting material that cannot be crafted... throw".
        // If I pass null, maybe I'm clearing it?
        // But usually "SetInput(nullptr)" isn't explicitly forbidden unless "Input 欄位為 nullptr" refers to "When calling Craft/Smelt".
        // However, "若放入的材料不可以被製作成盔甲/鎬子，則你需要 throw std::invalid_argument"。
        // I will assume strictly checking Material.
        _craftInput = nullptr; // Reset first? Or check first?
        // Note: If I pass nullptr, GetMaterial crashes.
        // I should probably allow nullptr to clear? But the instruction says "Put in (Set)".
        // If I strictly follow "If material cannot be crafted -> throw", then passing something that "isn't a material" (null) might be weird.
        // But usually usage is: Set(item).
        // I'll check for nullptr and if checks pass, set it.
    }
    if (craftableItem) {
        Material m = craftableItem->GetMaterial();
        if (m != Material::Iron && m != Material::Gold && m != Material::Diamond) {
            throw std::invalid_argument("Invalid craft material");
        }
    }
    _craftInput = craftableItem;
}

void CraftingTable::SetMaterialInput(std::shared_ptr<IConsumable> materialItem) {
    if (materialItem) {
        if (materialItem->GetMaterial() != Material::Stick) {
             throw std::invalid_argument("Material input must be Stick");
        }
    }
    _materialInput = materialItem;
}

void CraftingTable::Craft() {
    if (_output) {
        throw std::invalid_argument("Output is not empty");
    }

    if (!_craftInput && !_materialInput) {
        throw std::invalid_argument("Inputs are empty");
    }

    if (!_craftInput && _materialInput) {
        throw std::invalid_argument("Missing craft material");
    }

    // Now we have _craftInput.
    Material m = _craftInput->GetMaterial();
    
    // If we have stick -> Pickaxe
    // If no stick -> Armor
    
    if (_materialInput) {
        // Pickaxe
        PickaxeType type;
        if (m == Material::Iron) type = PickaxeType::Iron;
        else if (m == Material::Gold) type = PickaxeType::Gold;
        else if (m == Material::Diamond) type = PickaxeType::Diamond;
        else throw std::invalid_argument("Should not happen due to Set check"); // Safety
        
        _output = std::make_shared<Pickaxe>(type);
    } else {
        // Armor
        // Wait, Is Copper valid for Armor? Table: "Copper: x x".
        // SetCraftInput check handles this.
        
        ArmorType type;
        if (m == Material::Iron) type = ArmorType::Iron;
        else if (m == Material::Gold) type = ArmorType::Gold;
        else if (m == Material::Diamond) type = ArmorType::Diamond;
        else throw std::invalid_argument("Should not happen due to Set check");

        _output = std::make_shared<Armor>(type);
    }

    // Clear inputs
    _craftInput = nullptr;
    _materialInput = nullptr;
}

std::shared_ptr<IEnchantable> CraftingTable::GetOutput() {
    if (!_output) {
        throw std::invalid_argument("Output is empty");
    }
    std::shared_ptr<IEnchantable> temp = _output;
    _output = nullptr;
    return temp;
}