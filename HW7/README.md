# Homework 07

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：
> email: t111590004@ntut.org.tw、t112820018@ntut.org.tw
> MS Teams: 張意昌、許景喬
> Discord 群組
⚠️ Due: 2025/12/29 11:59 p.m. ⚠️

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt
.
├── files.cmake
├── CMakeLists.txt
├── LICENSE
├── README.md
├── include
│   ├── Building.hpp
│   ├── Company.hpp
│   ├── Device
│   │   ├── AirConditioner.hpp
│   │   ├── Dehumidifier.hpp
│   │   ├── Device.hpp
│   │   ├── DeviceType.hpp
│   │   ├── Fan.hpp
│   │   ├── Light.hpp
│   │   └── Loudspeaker.hpp
│   └── PowerSwitch
│       ├── MainPowerSwitch.hpp
│       ├── NormalPowerSwitch.hpp
│       ├── PowerSwitch.hpp
│       └── PowerSwitchState.hpp
├── scripts
│   ├── CodeCoverage.cmake
│   └── coverage.sh
├── src
│   ├── Building.cpp
│   ├── Company.cpp
│   ├── Device
│   │   ├── AirConditioner.cpp
│   │   ├── Dehumidifier.cpp
│   │   ├── Device.cpp
│   │   ├── Fan.cpp
│   │   ├── Light.cpp
│   │   └── Loudspeaker.cpp
│   └── PowerSwitch
│       ├── MainPowerSwitch.cpp
│       └── NormalPowerSwitch.cpp
└── test
    ├── Device
    │   ├── ut_air_conditioner.cpp
    │   ├── ut_dehumidifier.cpp
    │   ├── ut_device.cpp
    │   ├── ut_fan.cpp
    │   ├── ut_light.cpp
    │   └── ut_loudspeaker.cpp
    ├── PowerSwitch
    │   ├── ut_main_power_switch.cpp
    │   └── ut_normal_power_switch.cpp
    ├── test_utils.hpp
    ├── ut_building.cpp
    └── ut_company.cpp
```

## 題目評分

此專案的評分將基於以下測試檔案的通過情況：

- **Device Tests (`test/Device/*.cpp`):**
  - [5%] `ut_device.cpp`
  - [5%] `ut_air_conditioner.cpp`
  - [5%] `ut_dehumidifier.cpp`
  - [5%] `ut_fan.cpp`
  - [5%] `ut_light.cpp`
  - [5%] `ut_loudspeaker.cpp`
- **PowerSwitch Tests (`test/PowerSwitch/*.cpp`):**
  - [15%] `ut_normal_power_switch.cpp`
  - [15%] `ut_main_power_switch.cpp`
- **Company Test:**
  - [30%] `ut_company.cpp`
- **Building Test:**
  - [10%] `ut_building.cpp`

## 題目情境

你現在是一個商業大樓的電力管理員，這棟大樓裡面每層樓都有一間公司，你需要管控整棟大樓的電力開關，並且關心每層樓的公司下班了沒。

※這棟大樓只有有開關的插座，沒有不帶開關的插座。

※你需要自己新增其private/protected中的 member or method

## 設備種類 Device資料夾

### 設備限制
|        設備        |    功率    |         其他限制 or 功能          |
|:----------------:|:--------:|:---------------------------:|
|     `Light`      |   5~20   |  亮度 intensity: 0~100，預設：0   |
|      `Fan`       |  15~40   |   強度 speed (有enum)，預設：Low   |
| `AirConditioner` | 500~2000 | 溫度 temperature: 10~35，預設：25 |
|  `Dehumidifier`  | 150~350  |   濕度 humidity: 0~100，預設：0   |
|  `Loudspeaker`   |  5~200   |    音量 volume: 0~100，預設：0    |

若不符合這些限制，丟出 `invalid_argument`

### 一般設備 `Device`

內涵設備類別、設備名稱、設備的使用功率

- `Device(DeviceType deviceType, std::string name, int power);`
  - 建構子
- `DeviceType getDeviceType();`
  - 回傳 Device 的種類
- `std::string getName();`
  - 回傳 Device 的名稱
- `int getPower();`
  - 取得 Device 的使用功率

### 電燈 `Light`

內涵電燈的亮度

- `Light(std::string name, int power);`
  - 建構子
  - name 電燈的名稱
  - power 電燈的使用功率
- `Light(std::string name, int power, int intensity);`
  - 建構子
  - name 電燈的名稱
  - power 電燈的使用功率
  - intensity 電燈的亮度
- `void setIntensity(int intensity);`
  - 設定 Light 的亮度
- `int getIntensity();`
  - 取得 Light 的亮度

### 電扇 `Fan`

內涵電扇的速度

- `Fan(std::string name, int power);`
  - 建構子
  - name 電扇的名稱
  - power 電扇的使用功率
- `Fan(std::string name, int power, FanSpeed speed);`
  - 建構子
  - name 電扇的名稱
  - power 電扇的使用功率
  - speed 電扇的強度
- `void setSpeed(FanSpeed speed);`
  - 設定 Fan 的強度
- `FanSpeed getSpeed();`
  - 取得 Fan 的強度

### 冷氣機 `AirConditioner`

內涵冷氣機的設定溫度

- `AirConditioner(std::string name, int power);`
  - 建構子
  - name 冷氣機的名稱
  - power 冷氣機的使用功率
- `AirConditioner(std::string name, int power, int temperature);`
  - 建構子
  - name 冷氣機的名稱
  - power 冷氣機的使用功率
  - temperature 冷氣機的設定溫度
- `void setTemperature(int temperature);`
  - 設定 AirConditioner 的溫度
- `int getTemperature();`
  - 取得 AirConditioner 的設定溫度

### 除濕機 `Dehumidifier`

內涵除濕機的設定濕度

- `Dehumidifier(std::string name, int power);`
  - 建構子
  - name 除濕機的名稱
  - power 除濕機的使用功率
- `Dehumidifier(std::string name, int power, int humidity);`
  - 建構子
  - name 除濕機的名稱
  - power 除濕機的使用功率
  - humidity 除濕機的設定濕度
- `void setHumidity(int humidity);`
  - 設定 Dehumidifier 的濕度
- `int getHumidity();`
  - 取得 Dehumidifier 的設定濕度

### 喇叭 `Loudspeaker`

內涵喇叭的音量

- `Loudspeaker(std::string name, int power);`
  - 建構子
  - name 喇叭的名稱
  - power 喇叭的使用功率
- `Loudspeaker(std::string name, int power, int volume);`
  - 建構子
  - name 喇叭的名稱
  - power 喇叭的使用功率
  - volume 喇叭的音量
- `void setVolume(int volume);`
  - 設定 Loudspeaker 的音量
- `int getVolume();`
  - 取得 Loudspeaker 的音量

## 開關種類

### 電源開關 `PowerSwitch`

此為電源開關的抽象基礎類別

- `PowerSwitch(std::string name);`
  - 建構子
- `std::string getName();`
  - 取得開關的名稱
- `virtual PowerSwitchState getState() = 0;`
  - 純虛擬函數，取得開關狀態
- `virtual void turnOn() = 0;`
  - 純虛擬函數，打開電源
- `virtual void turnOff() = 0;`
  - 純虛擬函數，關閉電源
- `virtual void flip() = 0;`
  - 純虛擬函數，將電源開關反轉
- `virtual int countPower() = 0;`
  - 純虛擬函數，計算使用功率

### 一般電源開關 `NormalPowerSwitch`

內含一個設備、紀錄開關的變數

- `NormalPowerSwitch(std::string name);`
  - 建構子，設備設定為 `nullptr`，初始狀態為關
- `NormalPowerSwitch(std::string name, std::shared_ptr<Device> device);`
  - 建構子，連接指定設備，初始狀態為關
- `std::shared_ptr<Device> getDevice();`
  - 取得此開關連接的設備
- `std::string getDeviceName();`
  - 取得設備的名稱
- `void addDevice(std::shared_ptr<Device> device);`
  - 把設備插上此帶有開關的插座上
  - 若已有設備連接，丟出 `invalid_argument`
- `std::shared_ptr<Device> removeDevice();`
  - 把插座上的設備移除
  - 若沒有設備連接，丟出 `invalid_argument`
- `std::shared_ptr<Device> changeDevice(std::shared_ptr<Device> device);`
  - 更換一個設備
  - 若沒有設備連接，丟出 `invalid_argument`
- `PowerSwitchState getState() override;`
  - 取得開關狀態
- `void turnOn() override;`
  - 把開關打開
- `void turnOff() override;`
  - 把開關關閉
- `void flip() override;`
  - 把開關翻轉
- `int countPower() override;`
  - 計算此開關連接的設備使用功率，如果開關為關，輸出0

### 電源總開關 `MainPowerSwitch`

內含儲存多個 `PowerSwitch` 的變數

- `MainPowerSwitch(std::string name);`
  - 建構子
- `MainPowerSwitch(std::string name, std::vector<std::shared_ptr<PowerSwitch>> powerSwitches);`
  - 建構子，使用傳入的 powerSwitches 初始化 (powerSwitches 裡面可含 `MainPowerSwitch`)
- `void addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);`
  - 增加一個 `PowerSwitch` (可為`MainPowerSwitch`)
- `void removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);`
  - 移除一個 `PowerSwitch`
- `std::vector<std::shared_ptr<PowerSwitch>> findPowerSwitchByName(std::string name);`
  - 遞迴地根據開關名稱尋找所有開關
- `std::vector<std::shared_ptr<Device>> findDeviceByName(std::string name);`
  - 遞迴地根據設備名稱尋找所有設備
- `std::vector<std::shared_ptr<Device>> findDeviceByDeviceType(DeviceType type);`
  - 遞迴地根據設備種類尋找所有設備

可以使用以下方式將父類別的物件轉型成子類別的物件
```c++
std::shared_ptr<父類別> a
std::shared_ptr<子類別> b = std::dynamic_pointer_cast<子類別>(a);
```
- `PowerSwitchState getState() override;`
  - 取得電源總開關狀態 (`NotDefined`, `On`, `Off`, `Mixed`)
  - `NotDefined` 裡面沒有 PowerSwitch
  - `On` 所有 PowerSwitch 皆為開
  - `Off` 所有 PowerSwitch 皆為關
  - `Mixed` PowerSwitch 有些開、有些關
- `void turnOn() override;`
  - 把所有連接的`PowerSwitch`打開
- `void turnOff() override;`
  - 把所有連接的`PowerSwitch`關閉
- `void flip() override;`
  - 把所有連接的`PowerSwitch`翻轉
- `int countPower() override;`
  - 計算所有連接的`PowerSwitch`的總使用功率

## 建築與公司

### 公司 `Company`

代表單一樓層的公司，管理該公司的總電源開關。

- `Company(std::string name, int floorNumber);`
  - 建構子
  - name 公司的名稱
  - floorNumber 公司的所在樓層
  - 公司的總電源開關名稱為 `"company" + std::to_string(floorNumber) + "_mainPowerSwitch"`
  - 初始設定為下班狀態
- `std::string getName();`
  - 取得公司的名稱
- `int getFloorNumber();`
  - 取得公司的所在樓層
- `std::shared_ptr<PowerSwitch> getMainSwitch();`
  - 取得公司的總開關
- `bool isWork();`
  - 回傳公司是否為上班狀態
- `void addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);`
  - 在公司總開關上新增其他開關，以及其設備
- `void removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);`
  - 移除某個開關
  - 若此開關為公司總開關，丟出 `invalid_argument`
- `std::vector<std::shared_ptr<PowerSwitch>> findPowerSwitchByName(std::string name);`
  - 遞迴地根據開關名稱尋找所有開關
- `std::vector<std::shared_ptr<Device>> findDeviceByName(std::string name);`
  - 遞迴地根據設備名稱尋找所有設備
- `std::vector<std::shared_ptr<Device>> findDeviceByType(DeviceType type);`
  - 遞迴地根據設備種類尋找所有設備
- `void work();`
  - 設定為上班狀態，並打開所有電源
- `void offWork();`
  - 設定為下班狀態，並關閉所有電源
- `int countPower();`
  - 計算公司總用電量

### 大樓 `Building`

代表整棟大樓，管理所有樓層的公司。

- `Building(int totalFloors);`
  - 建構子
  - 自動創建每層樓的公司
  - 樓層從1開始
  - totalFloors 總樓層數
  - 每間公司的名稱為 `"company" + std::to_string(floorNumber)`
- `int getTotalFloors();`
  - 取得總樓層數
- `std::vector<std::shared_ptr<Company>> getCompanies();`
  - 取得大樓內所有公司的列表
- `int CountWorkingCompanies();`
  - 計算正在上班的公司數量

## 備註
- 你不應該上傳 `/bin` 、`/cmake-build-debug` 等編譯後資料夾至專案庫上，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時發現，將扣除作業總分 5 分。
- 你的功課不應該出現 Memory Leak，否則將會扣作業總分 10 分。
- 請確保你有引入所有函式庫避免系統無法編譯成功。
- 關於 `invalid_argument()` ，你可以參考 [這篇](https://en.cppreference.com/w/cpp/error/invalid_argument) 。
- `invalid_argument()` 內不用寫特定東西，且你應該使用 `#include<stdexcept>` 。
- 計算方式為算完後數字取無條件捨去。

## Homework's meme

![HW meme](docs/meme.jpg)
