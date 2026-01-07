# LAB01 - Food Manager

> [!TIP]  
> 在本次Lab中，我們的目標是製作一個簡易的食物管理器。  
> 並且在這次的Lab中學會基本的多型處理。

## 題目敘述

> [!NOTE]  
> 這是一個簡易的食物管理系統  
> 你必須要透過簡易的 `Manager` 去管理所有的食物總類  
> 你可以根據需求自行新增物件/函數  

## 運作流程

> [!NOTE]  
> 我們在 `include/RandomFood.hpp` 中有設定好部份的食材隨機生成器，你可以在 `test/main` 中引用並查看結果。
> 同時 `include/Manager.hpp` 中有 `Manager` ，你必須要完成這個 `Manager` 並且在 `test/main` 裡面呼叫他。

## 你所擁有的物件

### Food
- Food  
  - 為所有物件的基礎物件。  
  - `void Cook` 需設成純虛擬函數。  
  - `Ingredient GetIngredient()` 取得物件的食材。  
  - `FoodType GetFoodType()`  取得食物種類。
  - `int GetPrice()`  取得食物價格。  
  - `void  CountFoodPrice()`  根據食物的食材，計算價格 。  

### Ingredient

- Ingredient
  - 在 `Ingredient` 有眾多食材，已經在命名旁邊附註中文。
  - 並且有一個 `Ingredient` 的物件，你可以存放每個食材。

- 關於食材，每一份相對應價格如下：

|    食材     | 價格 | 
|:---------:|:--:|
|   Base    | 20 | 
|   Meat    | 15 | 
|  Veggie   | 10 | 
| Seasoning | 0  | 
|   Sweet   | 15 | 
| DrinkBase | 10 | 

### Salad、Noodle、Burger、Drink、Soup

- Salad、Noodle、Burger、Drink、Soup
  - 各物件建構子，若有不符種類之食材，請拋出 `invalid_argument` 
  - 需覆寫 `void Cook`，內容如下 (以 `Salad` 為例) ：
    - 開頭需 `Prepared XXXX` 。
    - 再來寫 `There is ingredient` 。
    - 將每個 `Ingredient` 列出 。
    - 最後輸出 `Done XXXX` 。
    - 同時，將物件內設定一個 `FoodType type` 表達製作完之後的食物種類。

- 以下是每個食物的食材：

|   食物   | 基礎主食類 | 肉類 | 蔬菜 | 調味料 / 醬料 | 飲料類 | 甜點類 |
|:------:|:-----:|:--:|:--:|:--------:|:---:|:---:|
| Burger |   V   | V  | V  |    V     |  X  |  X  |
| Drink  |   X   | X  | X  |    X     |  V  |  X  |
| Noodle |   V   | V  | V  |    V     |  X  |  X  |
| Salad  |   X   | X  | V  |    V     |  X  |  X  |
|  Soup  |   X   | V  | V  |    V     |  X  |  X  |
| Dessert|   X   | X  | X  |    X     |  X  |  V  |

打勾部分代表可以出現在食物裡面，打叉部分代表一定不能出現在食物裡面

### Manager

- Manager
  - 透過多型對所有的物件進行管理 (使用 `Manage` 函式)
  - 使用多型烹煮所有的食物 (使用 `CookAllFood` 函式)
  - 當呼叫 `CountAllFoodPrice` 時，計算所有食物的價格
  - 當呼叫 `GetFood` 時，計算 `Manager` 內所有的食物 
  - 在進行設定時，需要根據食材設定價格

### Tools

- RandomFood  
  - 食材隨機生成器，除非你有新增食材，不然不需修改他。  
  - 若有在 `Ingredient.hpp` 新增食材，可以於 `RandomFood.cpp` 的 `Generate` 中新增/修改裡面的函數。
- ToString  
  - 將食材轉成字串的函數，除非你有新增食材，不然不需修改他。  
  - 可自行於 `ToString.hpp` 與 `ToString.cpp` 新增/修改函數。  

## 開放性任務 ( `extra point` )

> [!IMPORTANT]
> - 針對甜點類食材，新增甜點的 `class` 並且完善他的功能。
> - 你可以自由新增食材，需要告訴我們關於甜點類的食材限制以及食材價格。

## 評分標準

- 100分
  - 使用正確的繼承方法 (20分)
  - 使用正確的多形方法 (20分)
  - 完成Lab的基礎部分 (60分)
- 本作業依照實體 `Demo` 為主，只需要在寫完之後請助教評測即可。