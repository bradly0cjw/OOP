# 專案說明 (Project Explanation)

## 專案簡介
這是一個物件導向程式設計 (OOP) 的練習專案 (Lab 02)，主要功能是模擬一個簡單的食物點餐與製作系統。專案展示了如何使用 C++ 的類別 (Class)、繼承 (Inheritance)、介面 (Interface) 以及智慧指標 (Smart Pointers) 來建構軟體架構。

## 主要組件 (Components)

### 1. 食物類別 (Food Classes)
專案定義了多種食物類別，皆繼承自共同介面或抽象類別：
- **Burger (漢堡)**: 由麵包 (Bread)、肉 (Meat)、生菜 (Lettuce)、起司 (Cheese) 等配料組成。
- **SideDish (附餐)**: 如薯條 (French Fries)、雞塊 (Nuggets) 等。
- **Drink (飲料)**: 如可樂 (Cola)、紅茶 (Black Tea) 等。
- **Dessert (甜點)**: 如巧克力 (Chocolate)、布丁 (Pudding) 等。
這些類別負責儲存配料 (Ingredients) 和客製化選項 (Options)。

### 2. 管理器 (Manager)
`Manager` 類別扮演類似「經理」或「廚房控管」的角色。它可以接收一組食物訂單，並統一呼叫 `MakeFood()` 方法來製作所有食物。它會自動判斷食物是需要 `Cook` (烹飪) 還是 `Prepare` (準備)。

### 3. 驗證器 (Validator)
`Validator` 類別體現了「關注點分離」(Separation of Concerns) 的設計原則。它將「驗證食物配料是否正確」的邏輯從食物類別中獨立出來。這使得食物類別只需專注於數據存儲，而複雜的規則檢查由 `Validator` 統一處理。

### 4. 組合 (Composition)
在專案中，**組合**的體現主要在於 `Burger`、`SideDish`、`Drink`、`Dessert` 等食物類別中。
- 這些類別內部都有 `std::vector<Ingredient> ingredients;` 的成員變數。
- 這代表食物物件**包含**了配料物件，並且配料的生命週期依附於食物物件。這是標準的「組合」關係 (Has-a)。

