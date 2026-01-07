#include "Furnace.hpp"
#include <stdexcept>

Furnace::Furnace() : _input(nullptr), _output(nullptr) {}

void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    _input = input;
}

void Furnace::Smelt() {
    if (!_input) {
        throw std::invalid_argument("Input is empty");
    }
    if (_output) {
        throw std::invalid_argument("Output is full");
    }
    
    _output = _input->Smelt();
}

std::shared_ptr<Ingot> Furnace::GetOutput() {
    if (!_output) {
        throw std::invalid_argument("Output is empty");
    }
    // "GetOutput() 取得燒制完產物". 
    // Should I clear it? If I don't, subsequent calls get it again (infinite loop?).
    // If I do, I conform to "Take" semantics.
    // Given the note about "Infinite Ingot" from Furnace: "Furnace 的設計會導致 Ingot 能被無限產生出來...因為 Furnace 並沒有真的「擁有」 Ore 的資源".
    // This implies that _input is NOT cleared. If _output is also not cleared, we have double infinite?
    // I think _output should be cleared to simulate "Taking" the item.
    
    std::shared_ptr<Ingot> temp = _output;
    _output = nullptr;
    return temp;
}
