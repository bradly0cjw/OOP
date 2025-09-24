# Homework 01

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

> Email: t111590004@ntut.org.tw、t112820018@ntut.org.tw    
> MS Teams: 張意昌、許景喬  
> Discord 群組  
⚠️ Due: 2025/10/06 23:59 ⚠️

## 說明

### 目標

- [ ] 了解並學會使用C++編寫程式。
- [ ] 學習使用Vector。
- [ ] 學習使用Switch ... Case。
- [ ] 學習使用enum Class。
- [ ] 學會並撰寫Function。

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
│    └── Order.hpp
│    └── Ticket.hpp
├─scripts
│    └── CodeCoverage.cmake
│    └── coverage.sh
├─src
│    └── Order.cpp
│    └── Ticket.cpp
└─test
     └── ut_order.cpp
     └── ut_ticket.cpp
```

## 題目評分

- ［60%］完成 `Ticket`。 (ut_ticket.cpp)
- ［40%］完成 `Order`。 (ut_order.cpp)

作業總分為 `100` ，如果你完成 (ut_all) 的話。  

## 注意事項

- 你不應該上傳 `/bin` 資料夾至專案上。
  - 你的功課不應該出現 `Memory Leak`，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 資料夾存在在專案庫中，扣除作業總分 5 分。

## 敘述

> 嗨，歡迎參加 OOP 課程。
>
> 想必你已經完成了 Lecture 02 的課程，並瞭解這門課所使用的語言 C++ 的相關語法。  
> （若還不了解的話，可以查看 Lecture 02 的簡報）
>
> 在這個任務中，你會了解課堂上所教學的語法將如何使用。

請嘗試完成任務，並在 `OJ` 上拿到綠色的 `Correct` 勾勾。

## 題目敘述

> 在這份任務中，我們嘗試設計一個簡易票價系統。

`C1dyeh` 是一家航空公司的老闆，由於最近飛日本的飛機太熱門，這次他委託我們設計出一個算票系統。

我們嘗試建立一個票價系統，透過設計出來的系統，可以知道機票資訊與售票金額。

### 任務零、了解題目架構，製作 `Tickets`

- 在 `include/Ticket.hpp` 與 `include/Order.hpp` 中，是我們這次要撰寫的 `function` 。  
- 你必須要在 `src/Ticket.cpp` 、 `src/Order.cpp` 完成所有的功能 。

首先請觀察 `include/Ticket.hpp` ， `struct Ticket` 變數長這樣：  

| 變數名稱              | 定義   | 
|-------------------|------|
| `TicketType type` | 機票種類 | 
| `int count`       | 機票價格 | 

- 對於 `Ticket MakeTicketOrder(TicketType type)` 請根據傳入的機票種類，製作相對應的 `ticket` 。

### 任務一、在CheckTicketPrice內回傳票的價格

| 票種  | 票價  | 變數名稱                   |
|-----|-----|------------------------| 
| 頭等艙 | 450 | `TicketType::First`    | 
| 商務艙 | 325 | `TicketType::Business` | 
| 經濟艙 | 200 | `TicketType::Economy`  | 

- 對於 `int CheckTicketPrice(Ticket ticket)` ，請根據傳入的 `Ticket ticket` 回傳相對應的價錢。  
- 如果 `ticket` 的價格與上述表格不符，你需要拋出 `invalid_argument()` 。  

### 任務二、觀察 `Order` ， 製作 `order`

首先請觀察 `include/Order.hpp` ， `struct Order` 變數長這樣：

| 變數名稱                          | 定義    | 
|-------------------------------|-------|
| `std::vector<Ticket> tickets` | 機票數量  | 
| `int totalCount`              | 訂單總價格 | 

- 對於 `Order MakeOrder(std::vector<Ticket> tickets)` 請根據傳入的變數，製作相對應的 `order` 。
- 若任一 `ticket` 的價錢與任務一表格不符，你需要拋出 `invalid_argument()` 。

### 任務三、在CheckSpecificTicketSales內計算售出特定類別機票的總價

- 對於 `int CheckSpecificTicketSales(TicketType type,Order order)` ，你需要根據 `type` 計算特定機票種類的總價。
- 保證票價與任務一表格相符。

### 任務附註

- 你只需要實作任務所描述的function。
- 在後面的任務使用前面任務完成的 `Function` ，可以加快你的實作速度。
- 關於 `invalid_argument()` 及 `std::vector` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/error/invalid_argument) 。
- 關於 `invalid_argument()` 及 `std::vector` ，你也可以參考 `docs/docs.cpp` 的簡易教學。  
- `invalid_argument()` 內不用寫特定東西，且你需引入 `#include<stdexcept>` 。

## Homework's meme

![HW meme](https://hackmd.io/_uploads/BJetVfnAA.gif)