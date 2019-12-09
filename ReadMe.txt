编译hal文件：arm-linux-gcc -fPIC -shared hardcontrol.c -o libhardcontrol.so -I /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -nostdlib /work/android-5.0.2/prebuilts/ndk/9/platforms/android-19/arch-arm/usr/lib/libc.so
在安卓目录下查找find -name "libc.so"

继续编译hal文件： arm-linux-gcc -fPIC -shared hardcontrol.c -o libhardcontrol.so -I /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -nostdlib /work/android-5.0.2/prebuilts/ndk/9/platforms/android-19/arch-arm/usr/lib/libc.so -I /work/android-5.0.2/prebuilts/ndk/9/platforms/android-19/arch-arm/usr/include/ /work/android-5.0.2/prebuilts/ndk/9/platforms/android-19/arch-arm/usr/lib/liblog.so
在安卓目录下查找find -name "log.h"
在安卓目录下查找find -name "liblog*"
