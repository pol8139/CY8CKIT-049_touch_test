CY8CKIT-049_touch_test
===
PSoC 4200 Prototyping Kit (CY8CKIT-049-42XX)のタッチセンサ(CapSense)をテストするためのプログラムです。[CY8CKIT-049_touch_to_serial](https://github.com/pol8139/CY8CKIT-049_touch_to_serial/)を作る前、PSoC単体でタッチセンサが動くかどうか確かめるために作ったプログラムです。タッチセンサが触られているかどうかを0/1で表してUARTで送信しています。

## 使い方
このリポジトリをクローンした上で、SCB_Bootloaderディレクトリ([CY8CKIT-049-42xx Kit Only (Kit Design Files, Documentation, Examples)](http://japan.cypress.com/documentation/development-kitsboards/psoc-4-cy8ckit-049-4xxx-prototyping-kits)をインストール後PSoC CreatorのStart Page内Examples and Kitsから辿ることで同名ディレクトリのプロジェクトを生成できます)をクローンしたディレクトリと同じ場所に置きます。
```bash
$ git clone (ここ).git
$ ls
CY8CKIT-049_touch_test SCB_Bootloader
```
PSoC Creator上でビルドし、ブートローダーを経由してバイナリを書き込みます。

CY8CKIT-049を一度PCから外し、再び取り付けます。

シリアルターミナル(TeraTerm, Arduinoシリアルモニタ、など)を開いて、実際にPSoCの端子を触り、タッチセンサが動作しているか確認します。

![](https://i.imgur.com/34TfO1J.png)
