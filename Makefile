all: build install monitor

build:
	platformio run

# ターゲットボードにアップロードします
install:
	platformio run --target=upload

# シリアルをモニタします
# デバイス指定したい場合はオプションを追加してください (-p /dev/xxx)
# モニタを止めたい場合 ctrl+[
monitor:
	platformio serialports monitor

clean:
	platformio run --target=clean

.PHONY: all build install clean monitor

