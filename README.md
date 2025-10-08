# Homework 02

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

> Email: t111590004@ntut.org.tw、t112820018@ntut.org.tw    
> MS Teams: 張意昌、許景喬  
> Discord 群組  
⚠️ Due: 2025/10/20 23:59 ⚠️

## 說明

### 目標

- [ ] 了解並學會使用C++編寫程式。
- [ ] 學習使用Class。
- [ ] 學習使用Vector。
- [ ] 學習使用sort。
- [ ] 學習使用enum Class。
- [ ] 學會並撰寫Class中的method。

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt
.
│   .clang-format
│   .gitignore
│   CMakeLists.txt
│   files.cmake
│   LICENSE
│   README.md
│
├───include
│       Snack.hpp
│       Storage.hpp
│       StorageManager.hpp
│
├───scripts
│       CodeCoverage.cmake
│       coverage.sh
│
├───src
│       Snack.cpp
│       Storage.cpp
│       StorageManager.cpp
│
└───test
        ut_snack.cpp
        ut_storage.cpp
        ut_storage_manager.cpp

```

## 題目評分

- ［20%］完成 `Snack`。 (ut_snack.cpp)
- ［60%］完成 `Storage`。 (ut_storage.cpp)
- ［20%］完成 `StorageManager`。 (ut_storage_manager.cpp)

作業總分為 `100` ，如果你完成 (ut_all) 的話。

## 注意事項

- 你不應該上傳 `/bin` 資料夾至專案上。
  - 你的功課不應該出現 `Memory Leak`，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 資料夾存在在專案庫中，扣除作業總分 5 分。

## 敘述

> 嗨，歡迎參加 OOP 課程。
>
> 想必你已經完成了 Lecture 03 的課程，並瞭解這門課所使用的語言 C++ 的相關語法。  
> （若還不了解的話，可以查看 Lecture 03 的簡報）
>
> 在這個任務中，你會了解課堂上所教學的語法將如何使用。

請嘗試完成任務，並在 `OJ` 上拿到綠色的 `Correct` 勾勾。

## 題目敘述

> 在這個任務中，你將描述 Uriah 的糧食庫 `Storage`。

Uriah 住在中山區的一間小雅房，身為一個平日不是在朝九晚六實習，不然就是在努力精煉自己能力的資工大四生，每天凌晨夜深人靜的小確幸，不外乎就是打開糧食庫並拿點東西吃，接著繼續忙。

Uriah 的糧食庫可能有許多點心，例如：泡麵、餅乾、御飯糰、冰7林、*飛天義大利麵*、*新生高架橋*、*大直河濱公園的河水*、*長春松江路口的公車站*、*捷運行天宮站*等等，這些多樣性的糧食能夠有助於 Uriah 在吃完這些點心後充足了一些精力並繼續忙手邊的事情。

在這份作業中你需要完成一個管理糧食庫的程式。

### 任務零、了解題目架構，製作 `Snack` 的建構子

- 在 `include/Snack.hpp` 、 `include/Storage.hpp` 與 `include/StorageManager.hpp` 中，是我們這次要撰寫的 `class` 與 `method`。
- 你必須要在 `src/Snack.cpp` 、 `src/Storage.hpp` 與 `src/StorageManager.hpp` 完成所有的功能 。

首先請觀察 `include/Snack.hpp` ， `class Snack` 變數長這樣：

| 變數名稱               | 定義   | 
|--------------------|------|
| `std::string name` | 點心名稱 | 
| `int amount`       | 點心數量 | 

- 打開 `src/Snack.cpp` 並在這裡完成你剩下的實作。
- 對於 `class Snack` 的建構子，請根據傳入的點心的名稱、點心數量 (沒有輸入預設為 1 ) 。
- ※備註：在 `include/Snack.hpp` 中看到的建構子不會有 "Snack::"

| 建構子                                                    | 定義                  |
|--------------------------------------------------------|---------------------|
| `Snack::Snack(std::string snackName)`                  | 初始設定點心名稱，點心數量設為 1 。 |
| `Snack::Snack(std::string snackName, int snackAmount)` | 初始設定點心名稱與點心數量。      |

### 任務一、完成 `Snack` 剩下的 method

| method                                   | 定義                                          |
|------------------------------------------|---------------------------------------------|
| `std::string Snack::getName() const`     | 回傳 `Snack` 中的變數 name 。                      |
| `int Snack::getAmount() const`           | 回傳 `Snack` 中的變數 amount 。                    |
| `void Snack::setAmount(int snackAmount)` | 設置 `Snack` 中的變數 amount 為傳入的變數 snackAmount 。 |

### 任務二、觀察 `Storage` ， 製作 `Storage` 的建構子

| 儲存庫類型     | 變數名稱                   |
|-----------|------------------------| 
| 放糖果的儲存庫   | `StorageType::CANDY`   | 
| 放餅乾的儲存庫   | `StorageType::COOKIES` | 
| 放蛋糕的儲存庫   | `StorageType::CAKE`    | 
| 放其他東西的儲存庫 | `StorageType::OTHER`   | 

首先請觀察 `include/Storage.hpp` ， `class Storage` 變數長這樣：

| 變數名稱                        | 定義                 | 
|-----------------------------|--------------------|
| `std::vector<Snack> snacks` | 儲存點心的變數            | 
| `StorageType type`          | 糧食庫類型              | 
| `int amount`                | 糧食庫點心數量(不是點心的種類數量) | 
| `int capacity`              | 糧食庫容量              | 

- 打開 `src/Storage.cpp` 並在這裡完成你剩下的實作。
- 對於 `class Storage` 的建構子，請根據傳入的糧食庫類型、糧食庫的容量 (沒有輸入預設為 10 ) ，初始預設糧食庫點心數量為 0 。
- ※備註：在 `include/Storage.hpp` 中看到的建構子不會有 "Storage::"

| 建構子                                                              | 定義                                 |
|------------------------------------------------------------------|------------------------------------|
| `Storage::Storage(StorageType storageType)`                      | 初始設定糧食庫類型與糧食庫容量設為 10 ，糧食庫點心數量為 0 。 |
| `Storage::Storage(StorageType storageType, int storageCapacity)` | 初始設定糧食庫類型與糧食庫容量，糧食庫點心數量為 0 。       |

### 任務三、完成 `Storage` 剩下的 method

- 提示：在這個任務中會需使用 `vector` 中的 method。

| method                                                      | 定義                                                                                                                                                                                                                                                     |
|-------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `void Storage::add(std::string snackName)`                  | 將一個名稱為 `snackName` 的點心加入糧食庫時，需依以下規則進行：<br/>1. 檢查是否已放滿：若糧食庫已達容量上限，則拋出 `std::invalid_argument` 例外。<br/>2. 檢查是否已存在相同點心：<br/>若該點心已存在於糧食庫中，則僅更新其數量。<br/>若該點心尚未存在，則將其新增至 `vector snacks` 中。<br/>注意：在 `vector snacks` 中，不得同時存在兩個同名的 `Snack` 物件。               |
| `void Storage::add(std::string snackName, int snackAmount)` | 將 `snackAmount` 個名稱為 `snackName` 的點心加入糧食庫時，需依以下規則進行：<br/>1. 檢查是否已放滿：若糧食庫已達容量上限，則拋出 `std::invalid_argument` 例外。<br/>2. 檢查是否已存在相同點心：<br/>若該點心已存在於糧食庫中，則僅更新其數量。<br/>若該點心尚未存在，則將其新增至 `vector snacks` 中。<br/>注意：在 `vector snacks` 中，不得同時存在兩個同名的 `Snack` 物件。 |
| `void Storage::eat(std::string snackName, int snackAmount)` | 將 `snackAmount` 個名稱為 `snackName` 的點心從糧食庫拿出來吃時，需依以下規則進行：<br/>1. 檢查點心是否存在於糧食庫：若不在糧食庫，則拋出 `std::invalid_argument` 例外。<br/>2. 檢查該點心是否夠吃：<br/>若點心夠吃，則更新其數量。若剛好吃完，則把該點心從 `vector` 中移除。<br/>若點心不夠吃，則拋出 `std::invalid_argument` 例外。                            |
| `void Storage::eatFirst(int snackAmount)`                   | 將 `vector snacks` 中最前面的點心取出 `snackAmount` 個來吃時，需依以下規則進行：<br/>1. 檢查糧食庫中是否有點心可以吃：若沒有點心，則拋出 `std::invalid_argument` 例外。<br/>2. 檢查該點心是否夠吃：<br/>若點心夠吃，則更新其數量。若剛好吃完，則把該點心從 `vector` 中移除。<br/>若點心不夠吃，則拋出 `std::invalid_argument` 例外。                          |
| `void Storage::eatLast(int snackAmount)`                    | 將 `vector snacks` 中最後面的點心取出 `snackAmount` 個來吃時，需依以下規則進行：<br/>1. 檢查糧食庫中是否有點心可以吃：若沒有點心，則拋出 `std::invalid_argument` 例外。<br/>2. 檢查該點心是否夠吃：<br/>若點心夠吃，則更新其數量。若剛好吃完，則把該點心從 `vector` 中移除。<br/>若點心不夠吃，則拋出 `std::invalid_argument` 例外。                          |
| `void Storage::sortByAmount()`                              | 將 `vector snacks` 根據每種點心的**數量**由小排到大進行排序<br/>提示：利用 `std::sort` 以及自定義的 `compare function` 或是 `lambda function` 來完成。                                                                                                                                     |
| `void Storage::sortBySnackName()`                           | 將 `vector snacks` 根據每種點心的**名稱**安照字典序進行排序<br/>提示：利用 `std::sort` 以及自定義的 `compare function` 或是 `lambda function` 來完成。                                                                                                                                     |
| `void Storage::clear()`                                     | 將 `vector snacks` 清空。<br/>                                                                                                                                                                                                                             |
| `int Storage::getAmount() const`                            | 回傳 `Storage` 中的變數 amount 。                                                                                                                                                                                                                             |
| `int Storage::getCapacity() const`                          | 回傳 `Storage` 中的變數 capacity 。                                                                                                                                                                                                                           |
| `StorageType Storage::getType() const`                      | 回傳 `Storage` 中的變數 type 。                                                                                                                                                                                                                               |
| `const std::vector<Snack>& Storage::getSnacks() const`      | 回傳 `Storage` 中的變數 snacks 。                                                                                                                                                                                                                             |
| `void Storage::setCapacity(int storageCapacity)`            | 設置 `Storage` 中的變數 capacity 為傳入的變數 storageCapacity 。                                                                                                                                                                                                    |

### 任務四、觀察 `StorageManager` ， 製作 `StorageManager` 的建構子

首先請觀察 `include/StorageManager.hpp` ， `class StorageManager` 變數長這樣：

| 變數名稱                             | 定義       | 
|----------------------------------|----------|
| `std::vector<Storage> storages;` | 儲存糧食庫的變數 | 

- 打開 `src/StorageManager.cpp` 並在這裡完成你剩下的實作。
- 對於 `class StorageManager` 的建構子，請建構所有 `StorageType` 的糧食庫，並照著enum中的順序放到 `vector storages` 中。
- ※備註：在 `include/StorageManager.hpp` 中看到的建構子不會有 "StorageManager::"

| 建構子                                | 定義                                                        |
|------------------------------------|-----------------------------------------------------------|
| `StorageManager::StorageManager()` | 建構所有 `StorageType` 的糧食庫，並照著enum中的順序放到 `vector storages` 中 |

### 任務五、完成 `StorageManager` 剩下的 method

| method                                                                                          | 定義                                                                                                                                                                      |
|-------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `void StorageManager::AddAllStorageCapacity(int capacity)`                                      | 將所有儲存庫的容量都加 `capacity` 。                                                                                                                                                |
| `void StorageManager::moveCapacity(StorageType fromType, StorageType toType, int moveCapacity)` | 將 `moveCapacity` 個 `FromType` 糧食庫的容量移動到 `ToType` 糧食庫，需依以下規則進行：<br/>1. 檢查 `FromType` 糧食庫的容量是否有足夠的空位轉移<br/>若有足夠的空位，則更新兩個儲存庫的容量<br/>若沒有足夠的空位，則拋出 `std::invalid_argument` 。 |
| `std::vector<Storage>& StorageManager::getStorages()`                                           | 回傳 `StorageManager` 中的變數 storages 。                                                                                                                                     |

※ `&` 出現在 `std::vector<Storage>&`，代表的是 參考 (reference)
- 沒有 &：回傳一個新的 std::vector<Storage> 物件（拷貝一份出來）。
- 有 &：回傳的是原本的 std::vector<Storage> 的參考（不會額外複製）。

### 任務附註

- 你只需要實作任務所描述的 `class` 中的 `method` 。
- 在後面的任務使用前面任務完成的 `method` ，可以加快你的實作速度。
- 你可以先參考 `docs` 資料夾裡的東西。
- 關於 `vector` ，你可以參考 [這篇](http://en.cppreference.com/w/cpp/container/vector) 。
- 使用 `vector` 時你應該使用 `#include<vector>` 。
- 關於 `invalid_argument()` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/error/invalid_argument) 。
- `invalid_argument()` 內不用寫特定東西，且你應該使用 `#include<stdexcept>` 。
- 關於 `sort()` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/algorithm/sort) 。
- 使用 `sort()` 時你應該使用 `#include<algorithm>` 。

## Homework's meme

![HW meme](https://hackmd.io/_uploads/BkOWrvHJT.png)
