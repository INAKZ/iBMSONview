# iBMSONview

DXライブラリを使ったBMSONのビューワ

fbmsonplayがうまく動かんし自作しようかとしたけどなんかよくわからんエラーが出て絶望してる

## 今どんな感じ？

起動するとウィンドウが出る

bmsonファイルをD&Dするとパースして色々解析を試みてぶっこわれる

最近複数回ファイルを突っ込んでもメモリリークが起こらないようになりました

## 参考URL
- [bmson仕様書](https://bmson-spec.readthedocs.io/en/master/)

- [bmson / Bemuse Project](https://bmson.nekokan.dyndns.info/)

  こちらを基に作成します

- [ubmplay(UCN-Soft)](http://ucn.tokonats.net/)

- [mbmplay(霧中の蒼鳥)](https://mistyblue.info/)

  パク参考にさせていただきます

- [RapidJSON](https://rapidjson.org/)

  bmsonの解析に使ってます　具体的にはググってコピペして
  
- [Python Tutor](https://pythontutor.com/visualize.html)

  視覚的にプログラムの動作を確認できる奴　すごい便利（こなみ）

## 開発について

個人の趣味でテキトーに作ってますが協力とかも一応受け付けてます

中の人に直接改善案を言ってもいいですしfork -> pull requestとかでもok

**ただし個人開発故反映は中の人の都合調子気分次第です**　あしからず

### なんかよくわからんエラー（くるしみ）

- [ ] bmson/bmsonutil.cpp 491行目の処理が終わるとtmpscが狂う

→もう眠いので後日調べる

- [ ] なんか起動してるだけで使用メモリが増える

→多分どうしようもないんじゃないかな

- [x] ~~ファイルをD&Dするとなんかヒープぶっ壊れてるでってエラー出る~~

→DXライブラリの仕様上D&Dされたファイルのパスは有限長でないといけないみたい

- [x] ~~bmsonを放り込むとエクスプローラーもろとも応答なしになる~~

→なんかよくわからんけど直ったのでヨシ！

- [x] ~~起動したての"初期状態"でesc押して終了しようとするとブレークポイントがどうとか出る~~

→配列のdeleteをdelete[]にして解決

### 目下の目標

- [x] bmsoninfoの取得
- [ ] 音鳴らしてオブジェクト降らす

### 将来的な目標

- [ ] コマンドラインからの起動
- [ ] BGI,BGA対応
- [ ] BPM,拍子イベント対応
- [ ] エディタも作る

## 作ってる人
いなくーず/INAKZ

- [いなくーず・こあ(webpage)](https://inakz.github.io/)
- [twitter](https://twitter.com/INAKZgrepe)

