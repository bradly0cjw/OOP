# Homework 06

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

> Email: t111590004@ntut.org.tw、t112820018@ntut.org.tw    
> MS Teams: 張意昌、許景喬  
> Discord 群組  
⚠️ Due: 2025/12/15 23:59 ⚠️

## 說明
這次的作業延續上一次作業的主題，不過新增了透過工作台（`CraftingTable`）製作盔甲以及附魔台 (`Enchanting Table`) 的邏輯，你需要按照上課所學的介面與組合概念，自行實作題目提供的介面並完成此作業。

> 對於熟悉 Minecraft 的同學，在這次作業中，挖礦的過程沒有[絲綢之觸](https://zh.minecraft.wiki/w/%E7%B2%BE%E5%87%86%E9%87%87%E9%9B%86?variant=zh-tw)的邏輯，
> e.g. 挖掉金礦不須考慮掉金原礦的邏輯。 並且不須考慮挖出之後的礦石數量或得到的礦物數量，一律視為一個。
> 而工作台只須考慮原料類型，並且只能製作盔甲，不須考慮置入數量和九宮格擺放方式 e.g. 鐵錠只能被製成鐵甲，銅錠不能被製作成避雷針
> 此外，為限縮範圍，附魔台僅提供部分附魔功能。

## 目標一、`Ore` 、 `ISmeltable` (20pt)

在 `Ore` class 中有 `bool BreakableBy(Pickaxe axe)` 的 method，請根據下表實作相對應的礦石破壞邏輯

|                  | `Wood` | `Stone` | `Gold` | `Iron` | `Diamond` |
|:----------------:|:------:|:-------:|:------:|:------:|:---------:|
|    `IronOre`     |   x    |    v    |   x    |   v    |     v     |
|    `GoldOre`     |   x    |    x    |   x    |   v    |     v     |
|   `CopperOre`    |   x    |    v    |   x    |   v    |     v     |
|   `DiamondOre`   |   x    |    x    |   x    |   v    |     v     |
| `LapisLazuliOre` |   x    |    v    |   x    |   v    |     v     |



此外， `IronOre`、`GoldOre` 以及 `CopperOre` class 應該實作 `ISmeltable` 介面，請根據下表實作相對應的燒制邏輯
並且回傳 `Ingot` 需對應相對應的材料，像是 `IronOre` 對應 `Material::Iron`

## 目標二、 `Ingot` 及 `IConsumable` (10pt)

`Ingot` 、 `Diamond` 、 `LapisLazuli` 以及 `Stick` class 應該實作 `IConsumable` 介面  
並且根據對應的材料回傳對應的內容，材料在 `Material.hpp` ，例如 `Ingot` 應該回傳 `Material::Iron` 、 `Material::Gold` 、 `Material::Copper`

## 目標三、 `Armor` 、 `Pickaxe` (10pt)

針對 `Armor` 以及 `Pickaxe` ，你必須將物件建構起來，並且完成 `PickaxeType` 的 `Getter` 。
針對 `Armor` 以及 `Pickaxe` ，有個 `IEnchantable` 介面，關於這個介面，你應該實作以下內容：

1. `void ApplyEnchantment(const Enchantment e)` 將附魔添加到裝備當中
2. 在建構物件時，請將 `Enchantment` 設定成 `Enchantment::NaN`  

## 目標四、`Furnace` 和 `CraftingTable` (30pt)

此處應該透過組合的概念實作 `Furnace` 和 `CraftingTable` 的邏輯，使用流程如下：

Furnace:

1. `SetInput(smeltableOre)` 置入可被燒制的礦石
2. `Smelt()` 開始燒制，並將產物放到 Output 欄位
3. `GetOutput()` 取得燒制完產物

CraftingTable:

1. `SetCraftInput(std::shared_ptr<IConsumable> craftableItem)` 置入可被製成盔甲/鎬子的礦物
2. `SetMaterialInput(std::shared_ptr<IConsumable> materialItem)` 置入可被製成鎬子的消耗物品
3. `Craft()` 開始合成，並將產物放到 `Output` 欄位，同時，若成功合成，須清除掉材料
4. `GetOutput()` 取得合成完的盔甲/鎬子，不用理解為啥是 `std::shared_ptr<IEnchantable>` ，只需要做 `Object Casting` 回傳即可，測資會再進行處理

> 注意事項：
> - `Furnace` 並不須實作 `ISmeltable`（因為熔爐本身不能被燒制），`CraftingTable` 同理 
> - 呼叫 `Smelt()` 和 `Craft()` 時若 Input 欄位為 `nullptr` ，應該 `throw std::invalid_argument` 
> - 在 `Craft()` 時，若只有 `craftableItem` ，則合成盔甲；若兩者都有則合成鎬子，若沒有 `craftableItem` 但有 `materialItem` 時，則 `throw std::invalid_argument` 。
> - 在 `Craft()` 時，若 Output 欄位不為 `nullptr`，也應該 `throw std::invalid_argument` 
> - 呼叫 `GetOutput()` 時若 Output 欄位為 `nullptr`，應該 `throw std::invalid_argument`  

關於鎬子，可以進行合成的礦物如下：

|                         |          合成鎬子          |         合成盔甲         |
|:-----------------------:|:----------------------:|:--------------------:|
|    `Material::Iron`     |  `PickaxeType::Iron`   | `ArmorType::Iron`  |
|    `Material::Gold`     |  `PickaxeType::Gold`   |  `ArmorType::Gold`   |
|   `Material::Copper`    |           x            |          x           |
|   `Material::Diamond`   | `PickaxeType::Diamond` | `ArmorType::Diamond` |
| `Material::LapisLazuli` |           x            |          x           |
|    `Material::Stick`    |           x            |          x           |

在使用 `SetCraftInput` 時，若放入的材料不可以被製作成盔甲/鎬子，則你需要 `throw std::invalid_argument` 。
在使用 `SetMaterialInput` 時，若放入的材料不為 `Material::Stick`，則你需要 `throw std::invalid_argument` 。

## 目標五、 `Enchanting Table` (30pt)

此處實作`Enchanting Table` 的邏輯，使用流程如下：

1. `SetEnchantItem(std::shared_ptr<IEnchantable> emchantable)` 置入可被附魔的物件
2. `SetConsumeItem(std::shared_ptr<IConsumable> comsumable)` 設定消耗元素 `青金石`
3. `Enchant(Enchantment e)` 進行附魔，並且將傳入的附魔設定在給定的裝備內，同時需消耗掉 `青金石`
4. `GetOutput()` 取得附魔後裝備

> 注意事項：
> - 呼叫 `Enchant(Enchantment e)` 時 ， 若沒有待附魔物件以及青金石，或是已有 `Output` ，則需拋出 `invalid_argument`  
> - 呼叫 `GetOutput()` 時若 Output 欄位為 `nullptr`，應該 `throw invalid_argument`  
> - 關於本題，附魔類型可參考 `Enchantment.hpp` ，並且同個物件一次最多只會有一個附魔在身上，不須考慮附魔與裝備屬性不合等問題

## Footnote
 
這次的作業可以看出介面跟組合能有效的解決鑽石問題（不是諧音笑話），`Diamond` 有 `IConsumable`， `CopperOre` 有 `ISmeltable`，而 `IronOre` 跟 `GoldOre` 則是兩個都有，在繼承的實作當中，就要讓某個類型被呼叫不該有的行為時拋出例外。透過型別上的保證，可以將一些邏輯檢查從 Run Time 移到 Compile Time，這樣的設計可以讓工程師在撰寫程式時，減少一些粗心錯誤的發生。

細心的同學可能會發現 `Furnace` 的設計會導致 `Ingot` 能被無限產生出來，因為 `Furnace` 並沒有真的「擁有」`Ore` 的資源，不過這會牽涉到 [Move Semantics](https://medium.com/@lucianoalmeida1/a-little-bit-about-std-move-efd9d554c09a) 的議題以及 [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr)，已經遠遠超出在這次的課程的內容，所以可以先暫時忽略這個邏輯漏洞。

## 配分

關於本次作業，總共配分如目標旁所述，其中可編譯檔如下：

- ut_checkpoint_1 (目標 `1` ~ 目標 `3`，共 `40` 分)
- ut_all (目標 `1` ~ 目標 `5`，共 `100` 分)

# HW Meme

![[]](./meme.jpg)
