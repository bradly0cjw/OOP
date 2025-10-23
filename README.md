# Homework 03

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

> Email: t111590004@ntut.org.tw、t112820018@ntut.org.tw    
> MS Teams: 張意昌、許景喬  
> Discord 群組  
⚠️ Due: 2025/11/03 23:59 ⚠️

## 說明

### 目標

- [ ] 了解並學習使用繼承。
- [ ] 了解虛擬函數的應用。
- [ ] 了解純虛擬函數的應用。

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
│    └── CargoPaper.hpp
│    └── CargoTrain.hpp
│    └── ElectricalTrain.hpp
│    └── MaglevTrain.hpp
│    └── Ticket.hpp
│    └── Train.hpp
├─scripts
│    └── CodeCoverage.cmake
│    └── coverage.sh
├─src
│    └── CargoPaper.cpp
│    └── CargoTrain.cpp
│    └── ElectricalTrain.cpp
│    └── MaglevTrain.cpp
│    └── Ticket.cpp
│    └── Train.cpp
└─test
     └── ut_cargo.cpp
     └── ut_cargo_paper.cpp
     └── ut_electrical.cpp
     └── ut_maglev.cpp
     └── ut_ticket.cpp
```

## 題目評分

- [20%] ut_electrical
- [25%] ut_maglev
- [25%] ut_cargo
以上部分為 `ut_train` ，占比 `70` 分  
- [10%] ut_ticket
- [20%] ut_cargo_paper
- 以上部分為 `ut_ticket` ，占比 `30` 分  

作業總分為 `100` 分，如果你完成 (ut_all) 的話。  
`ut_all = ut_train + ut_ticket`  
## 注意事項

- 你不應該上傳 `/bin` 、`/cmake-build-debug` 等編譯後資料夾至專案上。
  - 你的功課不應該出現 `Memory Leak`，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 、 `/cmake-build-debug` 等資料夾存在在專案庫中，扣除作業總分 5 分。
- 請確保你有引入所有函式庫避免系統無法編譯成功。

## 敘述

> 嗨，歡迎參加 OOP 課程。
>
> 想必你已經完成了 Lecture 04 的課程，並瞭解這門課所使用的語言 C++ 的相關語法。  
> （若還不了解的話，可以查看 Lecture 04 的簡報）
>
> 在這個任務中，你會了解課堂上的繼承觀念如何運用在專案當中。

請嘗試完成任務，並在 `OJ` 上拿到綠色的 `Correct` 勾勾。

## 題目敘述

> 在這份任務中，我們嘗試設計一個簡易鐵路系統。

 `OOP` 是一個鐵道經營公司，支撐著臺灣的鐵道發展。
我們嘗試建立多個不同種類的火車，提供客戶多元化的運輸方案。

### 任務零、製作 `Train`

首先，觀察 `Train.hpp` ， 裡面有一個 `Train` 的 `class`。

| 變數名稱              | 定義     | 
|-------------------|--------|
| `TrainType type`  | 班次種類   | 
| `int trainNumber` | 列車班號   | 
| `int speedLimit`  | 列車速度上限 |
| `int speed`       | 列車速度   |
| `bool open`       | 列車是否啟動 |

請根據下列指示，完成任務：

- `Train(TrainType type,int trainNumber,int speedLimit)` 為火車的建構子，完成該建構函數，未給予數值的變數設定為 `0` ，包含未出現在建構子之變數。
- `TrainType GetType()` 取得 `Train` 火車班次種類。
- `int GetTrainNumber()` 取得 `Train` 列車班號。
- `int GetSpeed()` 取得 `Train` 火車速度。
- `int GetSpeedLimit()` 取得 `Train` 火車速度上限。
- `bool IsOpen()` ，取得火車是否啟動資訊。
- 將 `void PowerUp()` 設為虛擬函數，當啟動時，將列車 `open` 設為 `true` ，若其他列車有不同設定方法，會於該列車進行說明。
- `void PowerDown()` ，當關閉時，將列車 `open` 設為 `false`。
- 將 `void SpeedUp()` 設為純虛擬函數，會於每種列車說明其設計方法。
- 將 `void SpeedDown()` 設為純虛擬函數，會於每種列車說明其設計方法。

### 任務一、製作載客類型的 `Train`

所有的火車 (除了 `Train`)都應該要繼承 `Train` 。  
再來，我們有不同的 `Train` ，你將會在這裡完成不同種類的 `Train` 。  
首先請觀察 `ElectricalTrain.hpp`，裡面有一個 `ElectricalTrain` 的 `class` 。

| 變數名稱         | 定義      | 
|--------------|---------|
| `int powerLimit` | 電池容量限制  | 
| `int power` | 現有電量大小  | 
| `int seatLimit` | 座位容量限制  |
| `int seat` | 目前售出座位數 |

- `ElectricalTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit)` 進行 `ElectricalTrain` 的建構，未給予數值的變數設定為 `0` ，包含未出現在建構子之變數。
- `int GetPowerLimit()` 取得 `ElectricalTrain` 的電池容量。
- `int GetSeatLimit()` 取得 `ElectricalTrain` 的座位容量。 
- `void SetPowerLimit(int powerLimit)` 設定 `ElectricalTrain` 的電池容量，如果設定的容量不大於 `0` 或超過 `100` ，拋出 `invalid_argument()`。
- `int GetPower()` 取得 `ElectricalTrain` 的電量大小。
- `int GetSeat()` 取得 `ElectricalTrain` 的售出座位數。
- `void SetSeat()` 進行座位預約，每次增加 `1` 個 `seat` ，如果預約後會超過 `seatLimit`，拋出 `invalid_argument()`。
- `void Charge(int hour)` 將 `ElectricalTrain` 進行充電，一小時增加 `18` 的電量，電量不能超過 `powerLimit` 。

再來觀察 `MaglevTrain.hpp` 裡面有一個 `class` 叫做 `MaglevTrain`。

| 變數名稱         | 定義      | 
|--------------|---------|
| `int powerLimit` | 電池容量限制  | 
| `int power` | 現有電量大小  | 
| `int seatLimit` | 座位容量限制  |
| `int seat` | 目前售出座位數 |

- `MaglevTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit)` 進行 `ElectricalTrain` 的建構，未給予數值的變數設定為 `0`，包含未出現在建構子之變數 。
- `int GetPowerLimit()` 取得 `MaglevTrain` 的電池容量。
- `int GetSeatLimit()` 取得 `MaglevTrain` 的座位容量。
- `void SetPowerLimit(int powerLimit)` 設定 `MaglevTrain` 的電池容量，如果設定的容量不大於 `0` 或超過 `100` ，拋出 `invalid_argument()`。
- `int GetPower()` 取得 `MaglevTrain` 的電量大小。
- `int GetSeat()` 取得 `MaglevTrain` 的售出座位數。
- `void SetSeat()` 進行座位預約，每次增加 `1` 個 `seat` ，如果預約後會超過 `seatLimit`，拋出 `invalid_argument()`。
- `void Charge(int hour)` 將 `MaglevTrain` 進行充電，一小時增加 `14` 的電量，電量不能超過 `powerLimit` 。

最後則是 `CargoTrain.hpp` 裡面有一個 `class` 叫做 `CargoTrain`。

| 變數名稱             | 定義     | 
|------------------|--------|
| `int fuelLimit`  | 燃料容量限制 | 
| `int fuel`       | 現有燃料大小 | 
| `int cargoLimit` | 貨物容量限制 |
| `int cargo`      | 目前貨物容量 |

- `CargoTrain(int fuelLimit,int cargoLimit,TrainType type,int trainNumber,int speedLimit)` 進行 `ElectricalTrain` 的建構，未給予數值的變數設定為 `0`，包含未出現在建構子之變數。
- `int GetFuelLimit()` 取得 `CargoTrain` 的燃料容量限制。
- `int GetCargoLimit()` 取得 `CargoTrain` 的貨物容量限制。
- `void SetFuelLimit(int fuelLimit)` 設定 `CargoTrain` 的燃料容量，如果設定的容量不大於 `0` 或超過 `1000` ，拋出 `invalid_argument()`。 (`0 < fuelLimit <= 1000`)
- `int GetFuel()` 取得 `CargoTrain` 的油量。
- `int GetCargo()` 取得 `CargoTrain` 的售出座位數。
- `void AddCargo(int cargo)` 進行貨物裝載，如果預約後會超過 `cargoLimit`，拋出 `invalid_argument()`。
- `void AddFuel(int fuel)` 將 `CargoTrain` 增加燃料，油量不能超過 `fuelLimit` ，增加後若超過則拋出 `invalid_argument()`。

### 任務二、根據不同的 `Train` 製作不同的啟動與速度模組。

首先是 `ElectricalTrain`
- `void PowerUp()` 當啟動時，將列車 `open` 設為 `true` ，同時減少 `1` 點 `power` 。 (保證啟動時有 `power`)
- `void SpeedUp()` ，當每次呼叫該函數時，若 `power` 不為 `0` ，減少 `3` 點 `power` ，提高列車速度，公式為 `newSpeed = 15 + oldSpeed / 20 + oldSpeed` 。 ( `oldSpeed / 20` 向下取整)
- `void SpeedDown()` ，當每次呼叫該函數時，若 `power` 不為 `0` ，降低列車速度，公式為 `newSpeed = oldSpeed - 15` ，不可低於 `0` ；

再來是 `MaglevTrain`
- `void PowerUp()` 當啟動時，將列車 `open` 設為 `true` ，同時減少 `1` 點 `power` 。 (保證啟動時有 `power`)
- `void SpeedUp()` ，當每次呼叫該函數時，若 `power` 不為 `0` ，減少 `3` 點 `power` ，同時提高列車速度，公式為 `newSpeed = 30 + oldSpeed / 15 + oldSpeed`。 ( `oldSpeed / 15` 向下取整)
- `void SpeedDown()` ，當每次呼叫該函數時，若 `power` 不為 `0` ，降低列車速度，公式為 `newSpeed = oldSpeed - 30` ，不可低於 `0` ；

最後是 `CargoTrain`
- `void PowerUp()` 當啟動時，將列車 `open` 設為 `true` ，同時減少 `5` 點 `fuel` 。 (保證啟動時有 `fuel`)
- `void SpeedUp()` ，當每次呼叫該函數時，若 `fuel` 不為 `0` ，減少 `10` 點 `fuel` ，同時提高列車速度，不可高於 `speedLimit` ，增加速度方法如下：  
  - 若載重比小於 `0.3` ，公式為 `newSpeed = 15 + oldSpeed / 20 + oldSpeed`。( `oldSpeed / 20` 向下取整)
  - 若載重比在 `0.3` ~ `0.7` ，公式為 `newSpeed = 15 + oldSpeed / 25 + oldSpeed`。( `oldSpeed / 25` 向下取整)
  - 若載重比大於 `0.7` ， 公式為 `newSpeed = 15 + oldSpeed / 30 + oldSpeed` 。( `oldSpeed / 30` 向下取整)
  - 載重比定義為 (`cargo/cargoLimit`，無條件捨去至小數點第一位)
- `void SpeedDown()` ，當每次呼叫該函數時，若 `fuel` 不為 `0` ，降低列車速度，公式為 `newSpeed = oldSpeed - 15` ，不可低於 `0` 。

注意，當在 `SpeedUp()` 及 `SpeedDown()` 被呼叫時，若 `power` 或 `fuel` 為 `0` ，拋出 `invalid_argument()`。
注意，當在 `SpeedUp()` 被呼叫時，若 `power` 或 `fuel` 不夠進行加速，則不加速。
注意， `SpeedUp()` 及 `SpeedDown()` 被呼叫時，若速度高於 `speedLimit` 或低於 `0` 時需進行處理 (設為 `speedLimit` 或 `0`) 避免拋出 `invalid_argument()`。

### 任務三、製作 `Ticket`

接著，我們來建立 `Ticket` ，他在 `Ticket.hpp` 裡面

| 變數名稱               | 定義    | 
|--------------------|-------|
| `std::string dest` | 車票起站  | 
| `std::string src`  | 車票迄站  | 
| `int range`        | 起迄站距離 |
| `int price`        | 票價    |
| `int trainNumber`  | 班次號碼  |
| `TrainType type`   | 班次種類  |

- `Ticket(std::string dest,std::string src,int range,int trainNumber,TrainType type)` 為車票建構子，未設置之變數須設定為 `0` 。
- `std::string GetDest()` 回傳車票起站。
- `std::string GetSrc()` 回傳車票迄站。
- `int GetPrice()` 回傳票價。
- `int GetTrainNumber()` 回傳班次號碼。
- `TrainType GetTrainType()` 回傳種類。
- 將 `void CalculateTicketPrice()` 設為虛擬函數，將於任務四進行使用，車票基本規則如下：
  - 每公里費用為 `2` 元。
  - 班次種類為 `Express` 將里程費增加 `40%` ， `Limited` 將里程費增加 `20%` 。
  - 若班次為 `Express` 每 `100` 公里，增加 `25` 元服務費；里程不足 `100` 公里部分不計算。
  - 以 `Express` 班次說明，若搭乘一趟 `256` 公里之路途，則車票票價為 `2*256*1.4+(256/100)*25` 。

### 任務四、製作 `CargoPaper`

最後，我們來建立 `CargoPaper` ，他在 `CargoPaper.hpp` 裡面，需繼承 `Ticket` 

| 變數名稱                  | 定義            | 
|-----------------------|---------------|
| `std::string dest`    | 車票起站          | 
| `std::string src`     | 車票迄站          | 
| `int range`           | 起迄站距離         |
| `int price`           | 票價            |
| `int volume`          | 貨物重量 ( `Vehicle` 時為數量) |
| `CargoType cargoType` | 貨物種類          |
| `TrainType type`      | 班次種類          |

- `CargoPaper(std::string dest,std::string src,int range,int volume,CargoType cargoType)` 為貨單建構子，`Ticket` 的 `trainNumber` 及 `price` 設為 `0`，同時將 `TrainType type` 設定為 `TrainType::Cargo`。
- `int GetVolume()` 回傳貨物重量 (數量)。
- `TrainType GetTrainType()` 回傳種類。
- `CargoType GetCargoType()` 回傳貨物種類。
- 將 `void CalculateTicketPrice()` 進行覆寫，將於任務四進行使用，車票基本規則如下：
  - 每公里費用為 `4` 元。
  - 每載重 `100` 公斤的貨物，需酌收 `75` 元燃料費 (不足 `100` 公斤不計) ；當 `cargoType` 為 `Vehicle` 時，則是每台增收 `75` 元燃料費。
  - 貨物種類為 `Food` 和 `Drink` 時，需額外增收 `10%` 冷凍費。
  - 貨物種類為 `Electronics` 和 `Furniture` 時，需額外增收 `15%` 運送保護費。
  - 貨物種類為 `Vehicle` ，需額外增收 `20%` 載具奢侈稅。
  - 以 `Vehicle` 為例，若運輸 `75` 台， `150` 公里的距離時，運費為 `(4*150 + 75 * 75)*1.2`。
  - 以 `Food` 為例，若運輸 `48763` 公斤， `150` 公里的距離時，運費為 `(4*150 + 487 * 75)*1.1` 。

### 任務附註

- 你只需要實作任務所描述的function。
- 在後面的任務使用前面任務完成的 `Function` ，可以加快你的實作速度。
- 關於 `invalid_argument()` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/error/invalid_argument) 。
- `invalid_argument()` 內不用寫特定東西，且你應該使用 `#include<stdexcept>` 。

## Homework's meme

![HW meme](./docs/meme.png)