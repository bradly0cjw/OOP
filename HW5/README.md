# Homework 05

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

> Email: t111590004@ntut.org.tw、t112820018@ntut.org.tw    
> MS Teams: 張意昌、許景喬  
> Discord 群組  
⚠️ Due: 2025/12/01 23:59 ⚠️

## 說明

### 目標

- [ ] 了解並學習使用繼承。
- [ ] 了解並學習使用多型。

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt
./
├── CMakeLists.txt
├── .clang-format
├── README.md
├── LICENSE
├── files.cmake
├─include
│    ├─Ore
│    │    └── BreakExp.hpp
│    │    └── CoalOre.hpp
│    │    └── DiamondOre.hpp
│    │    └── DurabilityCost.hpp
│    │    └── GoldOre.hpp
│    │    └── IronOre.hpp
│    │    └── ObsidianOre.hpp
│    │    └── Ore.hpp
│    │    └── Product.hpp
│    │    └── SmeltExp.hpp
│    ├─Pickaxe
│    │    └── DiamondPickaxe.hpp
│    │    └── Durability.hpp
│    │    └── GoldPickaxe.hpp
│    │    └── IronPickaxe.hpp
│    │    └── Pickaxe.hpp
│    │    └── PickaxeType.hpp
│    │    └── StonePickaxe.hpp
│    │    └── WoodenPickaxe.hpp
│    └── Furnace.hpp
├─scripts
│    └── CodeCoverage.cmake
│    └── coverage.sh
├─src
│    ├─Ore
│    │    └── BreakExp.cpp
│    │    └── CoalOre.cpp
│    │    └── DiamondOre.cpp
│    │    └── DurabilityCost.cpp
│    │    └── GoldOre.cpp
│    │    └── IronOre.cpp
│    │    └── ObsidianOre.cpp
│    │    └── Ore.cpp
│    │    └── Product.cpp
│    │    └── SmeltExp.cpp
│    ├─Pickaxe
│    │    └── DiamondPickaxe.cpp
│    │    └── Durability.cpp
│    │    └── GoldPickaxe.cpp
│    │    └── IronPickaxe.cpp
│    │    └── Pickaxe.cpp
│    │    └── PickaxeType.cpp
│    │    └── StonePickaxe.cpp
│    │    └── WoodenPickaxe.cpp
│    └── Furnace.cpp
└─test
     ├─Ore
     │    └── ut_coal_ore.cpp
     │    └── ut_diamond_ore.cpp
     │    └── ut_gold_ore.cpp
     │    └── ut_iron_ore.cpp
     │    └── ut_obsician_ore.cpp
     │    └── ut_ore.cpp
     │    └── ut_smeltable_ore.cpp
     ├─Pickaxe
     │    └── ut_diamond_pickaxe.cpp
     │    └── ut_gold_pickaxe.cpp
     │    └── ut_iron_pickaxe.cpp
     │    └── ut_pickaxe.cpp
     │    └── ut_stone_pickaxe.cpp
     │    └── ut_wooden_pickaxe.cpp
     └── ut_furnace.cpp
```

## 題目評分

- [5%] ut_ore.cpp
- [5%] ut_smeltable_ore.cpp
- [5%] ut_coal_ore.cpp
- [5%] ut_iron_ore.cpp
- [5%] ut_gold_ore.cpp
- [5%] ut_diamond_ore.cpp
- [5%] ut_obsician_ore.cpp
- 以上部分為 `ut_ore` （都在 test/Ore 資料夾中），占比 `35` 分
- [5%] ut_pickaxe.cpp
- [5%] ut_wooden_pickaxe.cpp
- [5%] ut_stone_pickaxe.cpp
- [5%] ut_iron_pickaxe.cpp
- [5%] ut_gold_pickaxe.cpp
- [5%] ut_diamond_pickaxe.cpp
- 以上部分為 `ut_pickaxe` （都在 test/Pickaxe 資料夾中），占比 `30` 分
- [35%] `ut_furnace`


作業總分為 `100` 分，如果你完成 (`ut_all`) 的話。

## 注意事項

- 你不應該上傳 `/bin` 、`/cmake-build-debug` 等編譯後資料夾至專案上。
  - 你的功課不應該出現 `Memory Leak`，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 、 `/cmake-build-debug` 等資料夾存在在專案庫中，扣除作業總分 5 分。
- 請確保你有引入所有函式庫避免系統無法編譯成功。

## 敘述

> 嗨，歡迎參加 OOP 課程。
> 想必你已經完成了期中考前的全部課程，並初步了解基礎的物件導向概念。  
> （若還不了解的話，可以查看目前已公布之所有簡報)
> 在這個任務中，你將會進行期中考的一個模擬，根據任務完成系統。

請嘗試完成任務，並在 `OJ` 上拿到綠色的 `Correct` 勾勾。

## 題目敘述

> 在這個任務中，你將基於 Minecraft 當中的開採礦物原則，模擬出一個基本的架構。

你會有幾個基本的礦物，經過熔爐燒製之後，就會產生出產物和經驗值。當中你需要判斷礦物能不能被熔煉。

且為了之後的擴展性，你會需要先判斷是否礦物能被適當的工具挖起。

以下的題目敘述將會以抽象化、需求化的描述方式，因此你需要結合題目需求與項目內程式碼，自行理解實作內容。若有任何對於題目解讀不理解、意思不清晰、概念衝突等，歡迎使用 TA 的 email 進行提問。

※免責聲明：此份作業只是已 Minecraft 做為出發，若有跟 Minecraft 中有不同的地方，請依照題目敘述完成作業。

### 礦物 Ore 的種類

| 礦物名稱 | 挖掘經驗  | 消耗的耐久度 | 燒制經驗 | 燒制後成品 | 是否能被燒制 |
|:----:|:-----:|:------:|:----:|:-----:|:------:|
| 煤炭礦  |  2.0  |   1    |  無   |   無   |   否    |
|  鐵礦  |   0   |   3    | 0.7  |   鐵   |   是    |
|  金礦  |   0   |   5    | 1.0  |  黃金   |   是    |
| 鑽石礦  |  4.0  |   10   |  無   |   無   |   否    |
| 黑曜石  |  8.0  |   40   |  無   |   無   |   否    |

而你可以使用繼承類別 `SmeltableOre`，代表說只要繼承該類別後，礦物就能被熔爐燒制。反之如果有類別沒有繼承 `SmeltableOre` 則代表該礦物不能被燒制。

### 鎬子 Pickaxe 的種類

| 鎬子名稱 |      可破壞的礦物       |     可掉落素材的礦物      | 耐久度  |
|:----:|:-----------------:|:-----------------:|:----:|
|  木鎬  |   煤炭礦、鐵礦、金礦、鑽石礦   |        煤炭礦        |  59  |
|  石鎬  |   煤炭礦、鐵礦、金礦、鑽石礦   |      煤炭礦、鐵礦       | 131  |
|  鐵鎬  | 煤炭礦、鐵礦、金礦、鑽石礦、黑曜石 |   煤炭礦、鐵礦、金礦、鑽石礦   | 250  |
|  金鎬  |   煤炭礦、鐵礦、金礦、鑽石礦   |        煤炭礦        |  32  |
| 鑽石鎬  | 煤炭礦、鐵礦、金礦、鑽石礦、黑曜石 | 煤炭礦、鐵礦、金礦、鑽石礦、黑曜石 | 1561 |

### 任務前提醒

請做此份作業的同學自己新增 private / protected 的 member / method 來儲存 object 內部的狀態以及行為

### 任務零、製作各種礦物

在 Ore 資料夾中的是 Ore 的父類別、子類別以及 Ore 會用到的各種常數

|         檔案名稱         |           檔案內容            |
|:--------------------:|:-------------------------:|
|      `Ore.hpp`       |         所有礦石的父類別          |
|  `SmeltableOre.hpp`  |   所有可燒製礦石的父類別 (繼承 Ore)    |
|    `CoalOre.hpp`     |         煤炭礦 (礦石)          |
|    `IronOre.hpp`     |          鐵礦 (礦石)          |
|    `GoldOre.hpp`     |          金礦 (礦石)          |
|   `DiamondOre.hpp`   |         鑽石礦 (礦石)          |
|  `ObsidianOre.hpp`   |         黑曜石 (礦石)          |
|    `Product.hpp`     | `enum`：不同類型的礦石 (可使用、不需修改) |
|    `BreakExe.hpp`    |    常數：挖掘經驗 (可使用、不需修改)     |
|    `SmeltExp.hpp`    |    常數：燒制經驗 (可使用、不需修改)     |
| `DurabilityCost.hpp` |   常數：消耗的耐久度 (可使用、不需修改)    |

而你可以使用繼承類別 `SmeltableOre`，代表說只要繼承該類別後，礦物就能被熔爐燒制。反之如果有類別沒有繼承 `SmeltableOre` 則代表該礦物不能被燒制。

- **礦石 `Ore`**
  - `Ore(Product product, int durabilityCost)`
    - 建構子
    - `product` 不可為 `Product::None` ，若為 `Product::None` 則丟出 `invalid_argument`。
    - 第一個參數：礦石的類型
    - 第二個參數：成功破壞所需要的鎬子耐久度
  - `~Ore()`
    - 解構子
    - 不需實作
  - `Product GetProduct()`
    - `product` 的 Getter
  - `int GetDurabilityCost()`
    - `durabilityCost` 的 Getter
  - `float GetBreakExp()`
    - 挖掘經驗的 Getter
    - 在此類別中不需實做 pure virtual function

- **可燒製礦石 `SmeltableOre`**
  - 繼承 `Ore`
  - `SmeltableOre(Product pro, int durabilityCost)`
    - 建構子
    - 第一個參數：礦石的類型
    - 第二個參數：成功破壞所需要的鎬子耐久度
  - `~SmeltableOre()`
    - 解構子
    - 不需實作
  - `float GetSmeltExp()`
    - 燒制經驗的 Getter
    - 在此類別中不需實做 pure virtual function

- **煤炭礦 `CoalOre`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `CoalOre()`
    - 建構子
    - 需將自己的礦石的類型 `procuct` 、成功破壞所需要的鎬子耐久度 `durabilityCost` 注入父類別
  - `float GetBreakExp()`
    - 覆寫父類別的 method
    - 回傳挖掘經驗

- **鐵礦 `IronOre`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `IronOre()`
    - 建構子
    - 需將自己的礦石的類型 `procuct` 、成功破壞所需要的鎬子耐久度 `durabilityCost` 注入父類別
  - `float GetBreakExp()`
    - 覆寫父類別的 method
    - 回傳挖掘經驗
  - `float GetSmeltExp()`
    - 覆寫父類別的 method
    - 回傳燒制經驗

- **金礦 `GoldOre`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `GoldOre()`
    - 建構子
    - 需將自己的礦石的類型 `procuct` 、成功破壞所需要的鎬子耐久度 `durabilityCost` 注入父類別
  - `float GetBreakExp()`
    - 覆寫父類別的 method
    - 回傳挖掘經驗
  - `float GetSmeltExp()`
    - 覆寫父類別的 method
    - 回傳燒制經驗

- **鑽石礦 `DiamondOre`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `DiamondOre()`
    - 建構子
    - 需將自己的礦石的類型 `procuct` 、成功破壞所需要的鎬子耐久度 `durabilityCost` 注入父類別
  - `float GetBreakExp()`
    - 覆寫父類別的 method
    - 回傳挖掘經驗

- **黑曜石 `ObsidianOre`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `ObsidianOre()`
    - 建構子
    - 需將自己的礦石的類型 `procuct` 、成功破壞所需要的鎬子耐久度 `durabilityCost` 注入父類別
  - `float GetBreakExp()`
    - 覆寫父類別的 method
    - 回傳挖掘經驗

### 任務一、製作各種鎬子

在 Pickaxe 資料夾中的是 Pickaxe 的父類別、子類別以及 Pickaxe 會用到的各種常數

|         檔案名稱         |           檔案內容            |
|:--------------------:|:-------------------------:|
|    `Pickaxe.hpp`     |         所有鎬子的父類別          |
| `WoodenPickaxe.hpp`  |            木鎬             |
|  `StonePickaxe.hpp`  |            石鎬             |
|  `IronPickaxe.hpp`   |            鐵鎬             |
|  `GoldPickaxe.hpp`   |            金鎬             |
| `DiamondPickaxe.hpp` |            鑽石鎬            |
|  `PickaxeType.hpp`   | `enum`：不同類型的鎬子 (可使用、不需修改) |
|   `Durability.hpp`   |   常數：消耗的耐久度 (可使用、不需修改)    |

- **鎬子 `Pickaxe`**
  - `Pickaxe(PickaxeType pickaxeType, int durability)`
    - 建構子
    - 第一個參數：鎬子的類型
    - 第二個參數：鎬子耐久度
  - `~Pickaxe()`
    - 解構子
    - 不需實作
  - `Product Mining(std::shared_ptr<Ore> &ore)`
    - 使用鎬子開採礦石，並回傳開採出的礦石種類
    - 在此類別中不需實做 pure virtual function

- **木鎬 `WoodenPickaxe`**
  - 自行判斷要繼承誰
  - 不可有子類別
  - `WoodenPickaxe()`
    - 建構子
    - 需將自己的鎬子的類型 `pickaxeType` 、鎬子耐久度 `durability` 注入父類別
  - `Product Mining(std::shared_ptr<Ore> &ore)`
    - 覆寫父類別的 method
    1. 當傳入的 `ore` 為 `nullptr` 時，丟出 `invalid_argument` ，反之繼續檢測下一個。
    2. 判斷鎬子 `Pickaxe` 的耐久度夠不夠破壞礦石 `ore` ，若不夠丟出 `invalid_argument` ，反之繼續檢測下一個。
    3. 判斷這個礦物能不能被該種類的鎬子**破壞**
      1. 若不能被鎬子破壞，丟出 `invalid_argument`。
      2. 反之，扣除鎬子消耗耐久度 `durability` ，並把 `ore` 指定為 `nullptr` ，繼續檢測下一個。
    4. 判斷這個礦物能不能在被該種類的鎬子破壞後**掉落素材**
      1. 若不會掉落素材則輸出 `Product::None`
      2. 反之，輸出該礦石的類型

- **石鎬 `StonePickaxe`** 、 **鐵鎬 `IronPickaxe`** 、 **金鎬 `GoldenPickaxe`** 、 **鑽石鎬 `DiamondPickaxe`**
  - 都跟 **木鎬 `WoodenPickaxe`** 同理（助教不想一直複製貼上，請自己完成）

### 任務二、製作熔爐

熔爐 `Furnace.hpp` 你需要使用 Function overload 重新實現增加礦物到熔爐的功能。

- **熔爐 `Furnace`**
  - `Furnace()`
    - 建構子
    - 設置儲存當下熔爐中礦物種類的變數為 `Product::None`，只要熔爐是空的就是 `Product::None`
    - 建立一個空的 `vector` 讓你可以放採到的礦物
  - `~Furnace()`
    - 解構子
    - 不需實作
  - `std::vector<std::shared_ptr<Ore>> PickupProduct()`
    - 淨空熔爐
  - `void AddOre(std::shared_ptr<SmeltableOre> ore)`
    - 新增可燒製的礦物到熔爐
    1. 若熔爐中礦物超過或等於64個，丟出 `invalid_argument`，反之繼續檢測下一個。
    2. 若熔爐中礦物的種類並非 `Product::None` or 傳入礦物的種類
      1. 若並非這兩個種類，丟出 `invalid_argument`
      2. 反之，設置儲存當下熔爐中礦物種類為 傳入礦物的種類，並把礦物放入熔爐中
  - `void AddAnyOre(std::shared_ptr<Ore> ore)`
    - 新增燒製的礦物到熔爐
    - 不可以燒製的礦物需丟出 `invalid_argument`，其他規則跟其他新增可燒製礦物的規則相同

### 任務附註

- 你只需要實作任務所描述的function。
- 在後面的任務使用前面任務完成的 `Function` ，可以加快你的實作速度。
- 關於 `invalid_argument()` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/error/invalid_argument) 。
- `invalid_argument()` 內不用寫特定東西，且你應該使用 `#include<stdexcept>` 。

## Homework's meme

![HW meme](https://hackmd.io/_uploads/BJqPIeLmJl.png)