gante
=====

C++ Gante Component

甘特圖開發筆記 V1.0 


特性：

1.文件夾特性：只要包含子任務，則本身無工作時間，其完成時間依賴其子任務最長完成時間計

    總任務A(包含以下)
        任務步驟1(包含以下)
            具體實施1
            具體實施2
            具體實施3
        任務步驟2(包含以下)
            具體實施4
            具體實施5
            具體實施6            


2.工序特性：每個任務都有各自完成時間，任務間沒有包含關係，有上下階依賴關係 （暫時不處理，可由1類變形得到）

    製造流程1 (依賴製造流程2，製造流程5)
        製造流程2 (依賴製造流程3，製造流程4)
            製造流程3
            製造流程4
        製造流程5
            製造流程6
                製造流程7    
            製造流程8


任務數據

1.任務對象

2.任務列表

3.任務對象关系

4.變更任務後通知控件更新

5.實現列表與列表之間批量複製數據

6.任务升级降级处理

7.任务增删改处理

8.任务数据导出处理


主體控件

1.GanteGrid - 甘特圖畫框

    Background
    BarStyle
    BarText
    Column
    Columns
    Header
    Link
    Text
    ScrollPanel
    Splitter
    
2.TreeGrid - 樹型數據列表

    TitleBar
    Column
    Node    
    ButtonColumn
    ComboBoxColumn
    DateColumn
    NumberColumn
    CustomNumberColumn
    PopupColumn
    StringsColumn
    TextColumn
    TreeColumn    
    
3.Ganter    -   甘特數據內部

    DataItem
    Datas
    DataValue
    DataValues
    HD_Day
    HD_Month
    HD_Week
    Holiday
    Holidays
    
4.OverViewChart  - 縱覽簡圖

5.HintWindow    - 提示框

6.FactoryCalendar   - 工廠日曆
    
    



