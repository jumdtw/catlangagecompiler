# catlangage compiler

知り合いの方のツイッターがにゃんにゃんしか言っていないので猫言葉からアセンブラをはいてくれるコンパイラを作成しました。

要はネタコードなのでできることはかなり制限されています。

使える数値は少なく、できることは特定の文字列の表示と＋－の演算のみです。また、演算も自動的にreturnする処理になっています。

## 各種数字と演算子

数字は０～７まで。７進数ではありません。普通に10進数です。
変数？そんなものは存在しません。
演算子は＋－のみ。
ただし、いくつか特手のものに関しては特別な意味を持っています。以下はそれらをまとめたものです。

meow にゃー
purr ゴロゴロ
roar ガオー

### 数値

meowを０、purrを１として表現している。
数値は "meow" から始まる

- ０：meowmeowmeowmeow
- １：meowmeowmeowpurr
- ２：meowmeowpurrmeow
- ３：meowmeowpurrpurr
- ４：meowpurrmeowmeow
- ５：meowpurrmeowpurr
- ６：meowpurrpurrmeow
- ７：meowpurrpurrpurr

### 演算子と文字列表示

演算子は "roar" から始まります。

+：roarmeow
-：roarpurr

文字列表示は "purr" から始まります。
他にも追加できるので追加してほしいものがあったらお問い合わせください。

"ステーキ食べたい"：purrmeowmeow
"おはようございます"：purrmeowpurr
"疲れた"：purrpurrpurr

## ebnf


expr = add

add = primary ("+" primary | "-" primary)* | meet | tired | hello

primary = num 
  
