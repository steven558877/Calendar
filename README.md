**Calendar -- 桌面小日曆進階版**
===
---

摘要
---
在現今，市面上已充滿了各種式樣的行事曆，各個都有他吸引人們去使用他們的特色。像是有些做的特別精美，有些是功能非常強，一個行事曆除了本身的功能外，還包含了 To-do list 及備忘錄及備忘錄在內，十分實用 。

但是， 儘管有了這麼多樣的行事曆，我們小組還是覺得某些功能放在行事曆內可能會很好用，但是到目前為止還沒看過有人實做出來。因此我們這次的專題就是想嘗試把那些我們覺得有用的功能實做出來，並使用看看，看成效如何!

我們將實作的功能有提到行事曆就會有的功能，像是新增行程、定時提醒等，除此之外附加以下功能 ：

> 1. 錄音功能：增加錄音提醒功能，當使用者在新增行程時我們讓使用者能夠錄音。這個錄音會在接近使用者的行程時連同提醒一起播放，即當使用者收到通知時就會播放當初預錄好的聲音回想起 這個行程的細節 。
> 2. Google map 導航功能：當使用者的行程是要前往某處時，以往的行事曆最多就只能顯示目的地圖，我們除了顯示地圖的功能外，我們還讓他直接根據目前的位置幫使用者導航，能夠讓使用者更知道應該如何抵達。
> 3. 緩衝功能：當使用者在新增行程時都會在行程內紀錄開始、結束的時間及地點。若使用者有複數行程排在同一天，通常都需要 交通時間，故若兩個行程雖沒重疊但是相隔太近時，會產生來不及 趕到目的地的狀況。因此我們會在新增行程時檢查該行程之開始、結束時間，計算緩衝時間，若相距過短時提醒使用者。
> 4. 統計圖表： 行事曆在使用一段時間後會累積一定數量的行程，此時我們可以用這些行程裡的資訊，像是出席人員、時間、地點等等之資訊做成統計圖表，既能讓使用者查看沒注意到的資訊， 也能增加一點使用行事曆的樂趣

工具說明
---

> 1. Google Calender API + Direction API：使用google 行事曆與導航功能的API
> 2. Brecord：錄音程式，可錄製麥克風聲音與系統聲音
> 3. Mplayer：音訊播放程式，可當鬧鐘使用
> 4. At：提醒功能，可提前使用者預先訂定的計畫
> 5. QT Designer：基於 C++ 語言專門用來開發 GUI 介面的程式

目前
---
> ![](http://i.imgur.com/OqYpHa8.jpg)
> ![](http://i.imgur.com/57kyYtd.jpg)
> ![](http://i.imgur.com/56nkZtG.jpg)
