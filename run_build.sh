export PICO_SDK_PATH=../pico-sdk
cd build/
cmake ..  -DPICO_BOARD=pico2_w -DPICO_PLATFORM=rp2350
make -j8