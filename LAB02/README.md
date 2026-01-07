# LAB02 - Food Manager II

> [!TIP]  
> 在本次Lab中，我們的目標是製作一個簡易的食物管理器。  
> 並且在這次的Lab中學會組合與介面的概念。

## 題目敘述

> [!NOTE]  
> 延伸至上次的 `Lab`
> 這是一個簡易的食物管理系統  
> 你必須要透過簡易的 `Manager` 去管理所有的食物總類  
> 你可以根據需求自行新增物件/函數

## 運作流程

> [!NOTE]  
> 完成後在 `test/main.cpp` 中拔掉註解即可編譯並察看結果。

## 你所擁有的物件

### Ingredient

- Ingredient
    - 在 `Ingredient` 有眾多食材，已經在命名旁邊附註中文。
    - 並且有一個 `Ingredient` 的物件，你可以存放每個食材。

### Interface

- IFood
    - `std::vector<Ingredient> GetIngredient()`
        - 函數類別：Getter
        - 回傳：食材
    - `FoodType GetFoodType()`
        - 函數類別：Getter
        - 回傳：食物類型
    - `bool IsDone()`
        - 函數類別：Getter
        - 回傳：食物是否已煮熟/飲料是否已調製完畢
- ICookable
    - `void Cook()`
        - 敘述：用於食物的烹煮
        - 行為：當食物烹煮時，將食物標記為已烹熟 (使用布林值)
        - 注意：當食物已經烹飪完畢時，但又呼叫過一次，需拋出 `std::invalid_arguments` 例外
- IPreparable
    - `void Prepare()`
        - 敘述：用於飲料的調製
        - 行為：當調製飲料時，將飲料標記為調製完畢 (使用布林值)
        - 注意：當飲料已經調製完畢時，但又呼叫過一次，需拋出 `std::invalid_arguments` 例外
- ICustomizable
    - `void AddOption(Option option)`
        - 當食物已烹熟/飲料調製完畢時，拋出 `std::invalid_arguments` 例外
        - 若客製化選項與食物種類不符，拋出 `std::invalid_arguments` 例外
    - `Option GetOption()`
        - 函數類別：Getter
        - 回傳：客製化選項

### SideDish、Burger、Drink

- 以下是每個食物需繼承的介面以及對應的建構子/函數:
    - Burger
        - IFood
        - ICookable
        - ICustomizable
    - SideDish
        - IFood
        - ICookable
        - ICustomizable
    - Drink
        - IFood
        - IPreparable
        - ICustomizable

- 以下是每個食物的食材 ( `Ingredient` )：

|       食材       |  翻譯  |   可被應用    | 
|:--------------:|:----:|:---------:|
|     Bread      |  麵包  |  Burger   |
|      Meat      |  肉排  |  Burger   |
|    Lettuce     |  生菜  |  Burger   |
|     Cheese     |  起司  |  Burger   |
|  FrenchFries   |  薯條  | Side-Dish | 
|    Nuggets     |  雞塊  | Side-Dish |
|   HashBrowns   |  薯餅  | Side-Dish | 
|      Cola      |  可樂  |   Drink   | 
| CaramelMilkTea | 焦糖奶茶 |   Drink   |
|    BlackTea    |  紅茶  |   Drink   |
|   Chocolate    |      |  Desert   |
|    Pudding     |      |  Desert   |
|     Apple      |      |  Desert   |

- 以下是 `Option` (客製化) 種類：

|    客製內容    |  翻譯  |   可被應用    | 
|:----------:|:----:|:---------:|
|   Large    |  加大  |    All    |
| AddOnions  | 加洋蔥  |  Burger   |
| AddPickles | 加酸黃瓜 |  Burger   |
|  LessSalt  |  少鹽  | Side-Dish |
|   NoSalt   |  無鹽  | Side-Dish | 
|  LessIce   |  少冰  |   Drink   |
|   NoIce    |  去冰  |   Drink   | 

- 不論是 `Ingredient` 還是 `Option` ，若沒有傳入正確的值，需要拋出 `Invalid_argument`

### Manager

- Manager
    - `void SetFood(std::vector<std::shared_ptr<IFood>> food>)`
        - 函數類別：Setter
        - 傳入：食物
    - `void MakeFood()`
        - 敘述：當呼叫時根據相對應的食物進行操作
        - 行為：將食物煮熟或將飲料調製完畢
    - `std::vector<std::shared_ptr<IFood>> GetFood()`
        - 函數類別：Getter
        - 回傳：食物

### Tools

- ToString
    - 將食材/客製化選項轉成字串的函數，除非你有新增食材，不然不需修改他。
    - 可自行於 `ToString.hpp` 與 `ToString.cpp` 新增/修改函數。

## 開放性任務 ( `extra point` )

> [!IMPORTANT]
> - 新增任意一種類型的食物 (`麵類`、`沙拉`、`甜點`)
> - 可自行新增食材、介面
> - `Demo` 時須說明新增食物的限制、相關屬性 (可以用的食材等)

## 評分標準

- 100分
    - 使用正確的組合方法 (20分)
    - 使用正確的介面方法 (20分)
    - 完成Lab的基礎部分 (60分)
- 本作業依照實體 `Demo` 為主，只需要在寫完之後請助教評測即可。
- 我們會將測試內容寫在 `main.cpp` ，只需要拔掉註解後測試即可。

## 注意

- 若你想要加入新的檔案，請在 `include` 、 `src` 、 `test` 中加入之後，在 `files.cmake` 進行調整，新增方式如下：
    - `include` ： `INCLUDE_FILES`
    - `src` ： `SRC_FILES`
    - `test` ： `TEST_FILES`
    - 請根據對應的位置新增，新增檔名及副檔名即可
