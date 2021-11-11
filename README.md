# iBMSONview

DXライブラリを使ったBMSONのビューワ

fbmsonplayがうまく動かんし自作しようかとしたけどなんかよくわからんエラーが出てて絶望してた

## 参考URL
- [bmson仕様書](https://bmson-spec.readthedocs.io/en/master/)

- [bmson / Bemuse Project](https://bmson.nekokan.dyndns.info/)

  こちらを基に作成します

- [ubmplay(UCN-Soft)](http://ucn.tokonats.net/)

- [mbmplay(霧中の蒼鳥)](https://mistyblue.info/)

  パク参考にさせていただきます

- [Python Tutor](https://pythontutor.com/visualize.html)

  すごい便利（こなみ）

## 開発について

個人の趣味でテキトーに作ってますが協力とかも一応受け付けてます

中の人に直接改善案を言ってもいいですしfork -> pull requestとかでもok

**ただし反映は中の人の気分次第です**　あしからず

### 目下の目標

- [ ] bmsoninfoの取得
- [ ] 音鳴らしてオブジェクト降らす

### 将来的な目標

- [ ] BGI,BGA対応
- [ ] BPM,拍子イベント対応
- [ ] エディタも作る

### なんかよくわからんエラー（くるしみ）

- [x] bmsonを読み込んでから終了しようとするとなんかヒープぶっ壊れてるでってエラー出る

→多分二つ下のと同じ配列関係

- [x] そもそもbmsonを放り込むとエクスプローラーもろとも応答なしになる

→なんかよくわからんけど直ったのでヨシ！

- [x] 起動したての"初期状態"でesc押して終了しようとするとブレークポイントがどうとか出る

→配列のdeleteをdelete[]にして解決

## 作ってる人
いなくーず/INAKZ

- [いなくーず・こあ(webpage)](https://inakz.github.io/)
- [twitter](https://twitter.com/INAKZgrepe)

