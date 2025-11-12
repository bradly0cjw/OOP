# Homework 04

> 這份作業由物件導向程式設計助教群所製。 如有問題，歡迎使用以下方式聯繫助教：
> 如有問題，歡迎使用以下方式聯繫：
> MS Teams、Discord群組  
> email: t111590004@ntut.org.tw、t112820018@ntut.org.tw、xuan910625.cs13@nycu.edu.tw

⚠️ Due: 2025/11/17 23:59 ⚠️

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt
.
├── files.cmake
├── CMakeLists.txt
├── LICENSE
├── README.md
├── include
│   ├── bonus.hpp
│   ├── cylinder_engineer.hpp
│   ├── extern_sales.hpp
│   ├── infrastructure_engineer.hpp
│   ├── it_support_engineer.hpp
│   ├── person.hpp
│   ├── project_assistant.hpp
│   ├── project_manager.hpp
│   ├── salary.hpp
│   ├── service_score.hpp
│   ├── staff.hpp
│   ├── staff_level.hpp
│   ├── staff_no.hpp
│   ├── staff_sales.hpp
│   ├── title.hpp
│   └── vendor.hpp
├── src
│   ├── cylinder_engineer.cpp
│   ├── extern_sales.cpp
│   ├── infrastructure_engineer.cpp
│   ├── it_support_engineer.cpp
│   ├── person.cpp
│   ├── project_assistant.cpp
│   ├── project_manager.cpp
│   ├── staff.cpp
│   ├── staff_sales.cpp
│   └── vendor.cpp
└── test
    ├── ut_cylinder_engineer.cpp
    ├── ut_extern_sales.cpp
    ├── ut_infrastructure_engineer.cpp
    ├── ut_it_support_engineer.cpp
    ├── ut_person.cpp
    ├── ut_project_assistant.cpp
    ├── ut_project_manager.cpp
    ├── ut_staff.cpp
    ├── ut_staff_sales.cpp
    └── ut_vendor.cpp
```

## 題目情境

你是一個圓柱製造工廠部門（Cylinder Manufacture Service Team, CMST）的高階主管，你希望可以設計一個包含門禁管理與薪水計算的人事管理系統，來方便管理內部（Staff）與外部供應商（Vendor）員工。

每個員工都有職種、職位編號（M、N、S 或 E）與職等（L1、L2 與 L3），職位編號與職等會影響底薪，而不同職種會有不同的額外紅利政策（EM、SALE）以及門禁政策（可進入/不可進入）。供應商也同時享有額外紅利，由服務考績（如果是 Engineer）或者業績數量（如果是 Sales）來決定。

## 員工組成

以下是這個部門可能會出現的職種

| 員工/供應商 |          職種           | 可進出工廠 | 服務考績 | 額外紅利 | 職位編號 |
|:-----------:|:-----------------------:|:----------:|:--------:|:--------:|:--------:|
|    Staff    |     Project Manager     |    Yes     |    No    |    EM    |    M     |
|    Staff    |    Project Assistant    |     No     |    No    |          |    N     |
|    Staff    |          Sales          |     No     |    No    |   SALE   |    S     |
|    Staff    |       Cylinder Engineer       |    Yes     |    No    |    EM    |    E     |
|   Vendor    |      Extern Sales       |     No     |   No    |   SALE   |    -     |
|   Vendor    | Infrastructure Engineer |    Yes     |   Yes    |    EM    |    -     |
|   Vendor    |   IT Support Engineer   |     No     |   Yes    |         |    -     |

其中，Vendor 的 Extern Sales 與 Staff 的 Sales 均有職等與額外紅利。

## 員工底薪

以下是該公司針對職等提供的每月底薪，你額外需要根據職等來進行薪水的調整，將該月薪 * 16 即可得到年薪。

| 職位編號 | 職等 |    薪水     |
|:--------:|:----:|:-----------:|
|    M     |  L1  | NT$ 120,000 |
|          |  L2  |   * 1.68    |
|          |  L3  |   * 2.32    |
|    S     |  L1  | NT$ 73,000  |
|          |  L2  |   * 1.17    |
|          |  L3  |   * 1.32    |
|    E     |  L1  | NT$ 93,000  |
|          |  L2  |   * 1.43    |
|          |  L3  |   * 1.82    |
|    N     |  L1  | NT$ 55,000  |
|          |  L2  |   * 1.12    |
|          |  L3  |   * 1.24    |

## 紅利

主要分成兩種紅利：進廠紅利（EM）與業績紅利（SALE），其中 Vendor 與 Staff 均享有紅利。

以下分紅為一年一次。

|      件酬      |      SALE 紅利      |
|:--------------:|:-------------------:|
| 0 < 件數 <= 10  | 總計件酬金額 * 0.1  |
| 10 < 件數 <= 20 | 總計件酬金額 * 0.15 |
| 20 < 件數 | 總計件酬金額 * 0.2  |

以下分紅為一年一次。

|   職位    | 職等 | 服務考績 | EM 紅利 |
|:---------:|:----:|:--------:|:-------:|
|  Vendor   |  -   |    A     | NT$ 26,300  |
|  Vendor   |  -   |    B     | NT$ 14,900  |
|  Vendor   |  -   |    C     | NT$  7,900  |
|  Vendor   |  -   |    D     | NT$  3,000  |
| Staff (M) |  L1  |    -     | NT$ 60,000  |
| Staff (M) |  L2  |    -     | NT$ 73,000  |
| Staff (M) |  L3  |    -     | NT$ 94,000  |
| Staff (E) |  L1  |    -     | NT$ 56,000  |
| Staff (E) |  L2  |    -     | NT$ 64,000  |
| Staff (E) |  L3  |    -     | NT$ 83,000  |

## 規格需求

此處僅列出 public function 並且省略因繼承而具有的 public function。你可以隨意地使用 virtual，或者新增 private/protected member/function。

請注意：由於我們會建構所有的 class 來進行測試，**請不要使用任何的 pure virtual function**。

 - class `Person`
     - `Person(std::string name, Title title, std::string phone, int ext)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `Title title`：職種名稱
        - 第三個參數 `std::string phone`：電話號碼
        - 第四個參數 `int ext`：分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
     - `std::string GetName()`
        - 函數類別：getter
        - 回傳該人員之名稱
     - `Title GetTitle()`
        - 函數類別：getter
        - 回傳該人員之職種名稱
     - `std::string GetPhone()`
        - 函數類別：getter
        - 回傳該人員之電話號碼 
     - `int GetExt()`
        - 函數類別：getter
        - 回傳該人員之分機
     - `void SetName(std::string name)`
        - 函數類別：setter
        - 設定該人員之名字
     - `void SetTitle(Title title)` 
        - 函數類別：setter
        - 設定該人員之職種 
     - `void SetPhoneExt(std::string phone, int ext)`
        - 函數類別：setter
        - 設定該人員之電話號碼與分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
     - `bool HaveEMPermission()`
        - 函數類別：getter
        - 回傳該人員是否有進廠權限

 - class `Staff`（繼承 class `Person`）
     - `Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `Title title`：職種名稱
        - 第三個參數 `std::string phone`：電話號碼
        - 第四個參數 `int ext`：分機
        - 第五個參數 `StaffNo staffNo`：職種編號
        - 第六個參數 `StaffLevel level`：職等
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
    - `StaffNo GetStaffNo()`
        - 函數類別：getter
        - 取得職種編號
    - `StaffLevel GetStaffLevel()`
        - 函數類別：getter
        - 取得職等
    - `int GetBasicSalary()`
        - 函數類別：getter
        - 取得基本年薪（僅計算底薪薪水）
    - `int GetBonus()`
        - 函數類別：getter
        - 取得年分紅
    - `int GetTotalSalary()`
        - 函數類別：getter
        - 取得總年薪

 - class `Vendor`（繼承 class `Person`）
     - `Vendor(std::string name, std::string phone, int ext)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
    - `void SetServiceScore(ServiceScore score)`
        - 函數類別：setter
        - 設定該員工之服務考績
    - `ServiceScore GetServiceScore()`
        - 函數類別：getter
        - 取得該員工之服務考績
    - `int GetBonus()`
        - 函數類別：getter
        - 取得年分紅

 - class `ProjectManager`（繼承 class `Staff`）
     - `ProjectManager(std::string name, std::string phone, int ext, StaffLevel level)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 第四個參數 `StaffLevel staffLevel`：職等
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外

 - final class `ProjectAssistant`（繼承 class `Staff`）
     - `ProjectAssistant(std::string name, std::string phone, int ext, StaffLevel level)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 第四個參數 `StaffLevel staffLevel`：職等
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外

 - final class `StaffSales`（繼承 class `Staff`）
     - `StaffSales(std::string name, std::string phone, int ext, StaffLevel level)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 第四個參數 `StaffLevel staffLevel`：職等
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
     - `void ApplyBonus(int totalSales, int count)`
        - 函數類別：setter
        - 第一個參數 `int totalSales`：總銷售額
        - 第二個參數 `int count`：數量

 - final class `CylinderEnginner`（繼承 class `Staff`）
     - `CylinderEngineer(std::string name, std::string phone, int ext, StaffLevel level)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 第四個參數 `StaffLevel staffLevel`：職等
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外

 - final class `ExternSales`（繼承 class `Vendor`）
     - `ExternSales(std::string name, std::string phone, int ext)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外
     - `void ApplyBonus(int totalSales, int count)`
        - 函數類別：setter
        - 第一個參數 `int totalSales`：總銷售額
        - 第二個參數 `int count`：數量

 - final class `InfrastructureEngineer`（繼承 class `Vendor`）
     - `InfrastructureEngineer(std::string name, std::string phone, int ext)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外

 - final class `ITSupportEngineer`（繼承 class `Vendor`）
     - `ITSupportEngineer(std::string name, std::string phone, int ext)`
        - 函數類別：建構子
        - 第一個參數 `std::string name`：名字
        - 第二個參數 `std::string phone`：電話號碼
        - 第三個參數 `int ext`：分機
        - 如果分機是負的，請拋出 `std::invalid_arguments` 例外


## 配分

 - 完成 `Person` Class：[20%] (ut_person)
 - 完成 `Staff` 與 `Vendor` Class：[20%] (ut_staff)
 - 完成 `ProjectManager`, `ProjectAssistant`, `CylinderEnginner`, `StaffSales`, `ExternSales`, `InfrastructureEngineer`, `ITSupportEngineer` [60%] (ut_all)

## 備註
 - 我們有提供給你一些可以用的 Enum 或者 const variable，歡迎多加利用，請參考：
   - `bonus.hpp` 具有許多與分紅相關的 const variable 與 enum。
   - `salary.hpp` 具有許多與薪水相關的 const variable。
   - `staff_level.hpp` 具有職等 enum。
   - `staff_no.hpp` 具有職位編號 enum。
   - `title.hpp` 具有職種 enum。
 - 你不應該上傳 /bin 、/cmake-build-debug 等編譯後資料夾至專案上。
   - 你不應該上傳 /bin 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 /bin 、 /cmake-build-debug 等資料夾存在在專案庫中，扣除作業總分 5 分。
   - 你的功課不應該出現 Memory Leak，否則將會扣作業總分 10 分。
 - 請確保你有引入所有函式庫避免系統無法編譯成功。
