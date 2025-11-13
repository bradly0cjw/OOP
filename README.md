# OOP2025[F] Midterm Exam

## 檔案架構

你的檔案架構必須至少符合以下的規格，才可以讓系統編譯你的專案。

```
.
├── CMakeLists.txt
├── files.cmake
├── include
│   ├── alcohol.hpp
│   ├── cost_ratio.hpp
│   ├── coupon.hpp
│   ├── deli.hpp
│   ├── food_product.hpp
│   ├── furniture.hpp
│   ├── item_type.hpp
│   ├── normal_product.hpp
│   ├── product_3c.hpp
│   ├── product.hpp
│   ├── snack.hpp
│   ├── vehicle.hpp
│   └── warrenty_product.hpp
├── src
│   ├── alcohol.cpp
│   ├── deli.cpp
│   ├── food_product.cpp
│   ├── furniture.cpp
│   ├── normal_product.cpp
│   ├── product_3c.cpp
│   ├── product.cpp
│   ├── snack.cpp
│   ├── vehicle.cpp
│   └── warrenty_product.cpp
└── test
    ├── ut_alcohol.cpp
    ├── ut_coupon_related.cpp
    ├── ut_deli.cpp
    ├── ut_food_product.cpp
    ├── ut_furniture.cpp
    ├── ut_normal_product.cpp
    ├── ut_product_3c.cpp
    ├── ut_product.cpp
    ├── ut_snack.cpp
    ├── ut_vehicle.cpp
    └── ut_warrenty_product.cpp
```

## 題目情境

你開了一間商店，叫做 IKNOD（伊克諾德）。現在你想要做一個 POS 機來幫助你結帳。在設計這個 POS 機之前，你希望可以先完成一些基本的功能歸類。在詳細調查過你的商店所賣的品項後，你發現大致上可以分類成以下的商品：

 - 電器類（吹風機、體重機、手機、筆電...）
 - 家具類（椅子、桌子、櫃子）
 - 汽機車（汽車、機車、重機）
 - 一般商品（延長線、湯匙、文具...）
 - 熟食區（飯糰、牛肉飯、豬排飯...）
 - 零食區（餅乾、糖果...）
 - 酒類（葡萄酒、清酒、燒酒、梅酒）

你希望可以實踐這些商品的類別，並且同時計算收益、成本與報廢。你的挑戰是嘗試找到一個好的方式來實作這些類別，透過繼承的方式盡可能減少實作量。

### 商品守則

| 商品分類 | 保固 | 珍食策略 | 保存期限 | 需驗證年齡 |    成本     |
|:----:|:--:|:----:|:----:|:-----:|:---------:|
| 電器類  | 是  |  -   |  -   |   -   | 售價 * 0.6  |
| 家具類  | 是  |  -   |  -   |   -   | 售價 * 0.9  |
| 汽機車  | 是  |  -   |  -   |   是   | 售價 * 0.8  |
| 一般商品 | 否  |  -   |  -   |   -   | 售價 * 0.75 |
| 熟食區  | 否  |  是   |  有   |   -   | 售價 * 0.8  |
| 零食區  | 否  |  否   |  有   |   -   | 售價 * 0.75 |
|  酒類  | 否  |  否   |  有   |   是   | 售價 * 0.6  |

### 折價策略

由於你希望可以吸引到一些顧客，所以你希望可以寄出「折價策略」，如果你使用對應的折價碼到商品上，可以進行折價，以下是你想到的折價碼。

|   折價碼   |        折價內容        |   折價碼   |        折價內容        |
|:----------:|:----------------------:|:----------:|:----------------------:|
| SAKETIME79 | 零食區 7 折且酒類 9 折 | BACK2SCHOOL | 電器類且一般商品 8 折 |
|  LUNCHTIME90  |    熟食區全面 9 折     |  NEWHOME70  |      家具類 7 折      |
| DRIVE90 |  汽機車 9 折  | TECHLIFE80 | 電器類 8 折 |
| WEEKEND80 | 酒類 8 折且零食區 8 折 | FESTIVE80 | 全館 8 折 |
| TEATIME80 | 熟食區與零食區 8 折 | HEALTHY90 | 電器類 9 折 |
| OOPALLPASS | 全館 10 折，成績也 10 折 | OOPALLFAILED | 全館免費 |

這邊的折價碼可以選擇一個商品進行使用，例如假設你有一個熟食「壽司」，那麼：

 - 使用 TEATIME85 可以將壽司的售價 * 0.8
 - 使用 LUNCHTIME90 可以將壽司的售價 * 0.9
 - 使用 OOPALLPASS 可以將壽司的售價 * 1
 - 使用 OOPALLFAILED 可以將壽司的售價 * 0
 - 使用 WEEKEND80 不會更改壽司的售價

其中：
 - 每個商品只能使用一個折價卷，測試資料也只會使用一個折價卷，不會有一個商品使用兩個折價卷的情況出現。
 - 如果熟食區受到珍食策略的影響，就沒有打折，但我們也沒有測試這個東西，不會同時有珍食策略與使用折價卷的情況出現。

### 珍食策略

如果該商品符合珍食策略，則該商品打 8 折。

### 保固時間/保存期限確認

 - 如果確認的時間早於電器類保固時間，則可以保固。
     - 如果保固是 2024/04，但你在 2024/4/15 確認是可以保固的。
     - 如果保固是 2024/02，但你在 2024/4/15 確認是不行保固的。
 - 如果確認的時間晚於食品保存期限，則直接將售價歸零並且標示為「過期」。
     - 如果保存期限是 2024/04/25，但你在 2024/04/25 確認是可以吃的。
     - 如果保存期限是 2024/02/25，但你在 2024/04/15 確認是不行吃的。

### 成本計算

對於每一個商品，具有售價與成本，其中：

 - 成本會受到售價的影響，例如售價原先為 120 元，且成本為售價的 50%，則成本為 60 元。
 - 售價會受到折價卷的影響，例如售價原先為 120 元，使用 DRIVE90 後的價格為 108 元。

另外有三個規則，如下：
 - 當使用設定售價的函數時，需要重新設定成本。
 - 當使用設定折價卷的函數而導致售價變更時，你不需要重新計算新售價的成本。
 - 不存在設定折價卷後又改變售價的情況出現。

例如：
 - 一個商品的售價是 120 元，且成本為售價的 50%，則成本為 60 元。
 - 如果某天軒軒更改了售價，變成了 180 元，則成本變為 90 元。（第一個規則）
 - 但如果某個叫做圓柱的人使用了 DRIVE90 的折價卷，導致價格變成 162，但成本還是 90 元。（第二個規則）
 - 不會有情況在價格因為折價卷變成 162 的時候，又將價格設定成 240 的情況。（第三個規則）
   ~~如果你遇到這種情況，請撥打控八控控跟警察說有人在惡意哄抬價格。~~

## 規格需求

此處僅列出 public function 並且省略因繼承而具有的 public function。
你可以隨意地使用 virtual，或者新增 private/protected member/function。

 - `class Product`
     - `Product(std::string name, int cost, int price)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
     - `std::string GetName()`
         - 函數類別：Getter
         - 回傳：商品名稱（字串）
     - `std::string GetCost()`
         - 函數類別：Getter
         - 回傳：商品成本（整數）
     - `std::string GetPrice()`
         - 函數類別：Getter
         - 回傳：商品售價（整數）
     - `void SetName(std::string name)`
         - 函數類別：Setter
         - 敘述：用於設定商品名稱
         - 第一個參數 `std::string name`：商品名稱
     - `void SetCost(int cost)`
         - 函數類別：Setter
         - 敘述：用於設定商品成本
         - 第一個參數 `int cost`：商品成本
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
     - `void SetPrice(int price)`
         - 函數類別：Setter
         - 敘述：用於設定商品價格
         - 第一個參數 `int price`：商品售價
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外

 - `class WarrantyProduct` (繼承 `Product`)
     - `WarrentyProduct(std::string name, int cost, int price, int warrantyYear, int warrantyMonth)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int warrantyYear`：商品保固年份
         - 第五個參數 `int warrantyMonth`：商品保固月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyMonth 是負的，拋出 `std::invalid_arguments` 例外
     - `bool IsExpired(int year, int month, int day)`
         - 函數類別：Getter
         - 敘述：用於確定該商品是否已經過保固期限
         - 第一個參數 `int year`：當前時間（年）
         - 第二個參數 `int month`：當前時間（月）
         - 第三個參數 `int day`：當前時間（日）

 - `class FoodProduct` (繼承 `Product`)
     - `FoodProduct(std::string name, int cost, int price, int expiredYear, int expiredMonth, int expiredDay)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int expiredYear`：食品保存年
         - 第五個參數 `int expiredMonth`：食品保存月
         - 第六個參數 `int expiredDay`：食品保存日
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredMonth 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredDay 是負的，拋出 `std::invalid_arguments` 例外
     - `bool CheckExpired(int year, int month, int day)`
         - 函數類別：Setter
         - 敘述：用於確定該商品是否已經過期，如果過期，將售價設定為 0，並且回傳 true，否則回傳 false
         - 第一個參數 `int year`：當前時間（年）
         - 第二個參數 `int month`：當前時間（月）
         - 第三個參數 `int day`：當前時間（日）

 - `class NormalProduct`（繼承 `Product`）
     - `NormalProduct(std::string name, int cost, int price)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷

 - `class Product3C`（繼承 `WarrentyProduct`）
     - `Product3C(std::string name, int price, int warrantyYear, int warrantyMonth)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int price`：商品售價
         - 第三個參數 `int warrantyYear`：商品保固年份
         - 第四個參數 `int warrantyMonth`：商品保固月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 函數類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷

 - `class Furniture`（繼承 `WarrentyProduct`）
     - `Furniture(std::string name, int price, int warrantyYear, int warrantyMonth)`
         - 函數類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int warrantyYear`：商品保固年份
         - 第五個參數 `int warrantyMonth`：商品保固月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyMonth 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷

 - `class Vehicle`（繼承 `WarrentyProduct`）
     - `Vehicle(std::string name, int price, int warrantyYear, int warrantyMonth)`
         - 類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int warrantyYear`：商品保固年份
         - 第五個參數 `int warrantyMonth`：商品保固月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 warrantyMonth 是負的，拋出 `std::invalid_arguments` 例外
     - `void CheckAge(int age)`
         - 類別：Setter
         - 敘述：確認購買年齡（需滿 18 歲），否則拋出 `std::invalid_arguments` 例外。
         - 第一個參數 `int age`：年齡
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷

 - `class Deli`（繼承 `FoodProduct`）
     - `Deli(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay)`
         - 類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int expiredYear`：商品期限年份
         - 第五個參數 `int expiredMonth`：商品期限月份
         - 第六個參數 `int expiredDay`：商品期限月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredMonth 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredDay 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷
     - `void ApplyExpireCoupon()`
         - 類別：Setter
         - 敘述：用於設定該食物為[珍食策略](#珍食策略)。

 - `class Snack`（繼承 `FoodProduct`）
     - `Snack(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay)`
         - 類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int expiredYear`：商品期限年份
         - 第五個參數 `int expiredMonth`：商品期限月份
         - 第六個參數 `int expiredDay`：商品期限月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredMonth 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredDay 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷

 - `class Alocohol`（繼承 `FoodProduct`）
     - `Alocohol(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay)`
         - 類別：建構子
         - 第一個參數 `std::string name`：商品名字
         - 第二個參數 `int cost`：商品成本
         - 第三個參數 `int price`：商品售價
         - 第四個參數 `int expiredYear`：商品期限年份
         - 第五個參數 `int expiredMonth`：商品期限月份
         - 第六個參數 `int expiredDay`：商品期限月份
         - 如果 cost 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 price 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredYear 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredMonth 是負的，拋出 `std::invalid_arguments` 例外
         - 如果 expiredDay 是負的，拋出 `std::invalid_arguments` 例外
     - `void ApplyCoupon(Coupon coupon)`
         - 類別：Setter
         - 敘述：套用折價卷
         - 第一個參數 `Coupon coupon`：折價卷
     - `bool CheckAge(int age)`
         - 類別：Setter
         - 敘述：確認購買年齡（需滿 18 歲），否則拋出 `std::invalid_arguments` 例外。

## 配分

 - 完成 `Product` Class：20%
 - 完成 `NormalProduct` Class：10%
 - 完成 `WarrantyProduct`, `FoodProduct` Class：20%
 - 完成 `Product3C`, `Furniture`, `Deli`, `Vehicle`, `Snack`, `Alocohol` 除了 `ApplyCoupon` 函數的 Class：20%
 - 完成 `ApplyCoupon`, `ApplyExpireCoupon` 函數的功能：30%

我們會很嚴謹的測試所有的程式是妥善的，有 180+ 個測試。

## 備註
 - 我們提供給你很多有用的 header，你可以自己決定要不要使用
     - `cost_ratio.hpp` 幫你定義好了很多個 const，包含商品的打折比率，避免你寫錯。
     - `item_type.hpp` 幫你定義好了所有商品類別的 enum，如果你需要的話。
     - `coupon.hpp` 幫你定義好了所有折價卷的 enum，如果你需要的話。
 - 對於確認過期，你可以使用 $365 \times year + 31 \times month + day$ 來當成一個近似的天數數字比較，會較為方便處理。
 - 你可以隨意地使用 virtual/pure virtual，或者新增 private/protected member/function。
 - 對於第二個 Check Point 之後可能會有因為沒有繼承而導致編譯失敗的問題，你需要自己排除後執行測試。
