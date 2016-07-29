all: mac ios android

clean:
	-rm -rf build/
	-rm -rf deps/build/
	-rm -rf output/

	-rm -rf obj/
	-rm -rf libs/
	-rm -rf djinni-output-temp/
	-rm GypAndroid.mk
	-rm *.target.mk
	-rm deps/*.target.mk
	
	-rm -rf platform/android/java_gen/*
	-rm -rf platform/android/jni_gen/*

	-rm -rf platform/ios/gen/
	
	#-rm -rf test_ldb
	#-rm test.sqlite
	#-rm play

gyp: ./deps/gyp

./deps/gyp:
	git submodule update --init

./deps/djinni:
	git submodule update --init

djinni-output-temp/gen.stamp core.cidl:
	./run_djinni.sh

djinni:
	./deps/gradle/gradlew djinni

# instruct gyp to build using the "xcode" build generator, also specify the OS
# (so we can conditionally compile using that var later)
build_mac/core.xcodeproj: deps/gyp deps/json11 core.gyp djinni
	PYTHONPATH=deps/gyp/pylib deps/gyp/gyp core.gyp -DOS=mac --depth=. -f xcode --generator-output=./project/mac -Icommon.gypi

build_ios/core.xcodeproj: deps/gyp deps/json11 core.gyp djinni
	PYTHONPATH=deps/gyp/pylib deps/gyp/gyp core.gyp -DOS=ios --depth=. -f xcode --generator-output=./project/ios -Icommon.gypi

GypAndroid.mk: deps/gyp deps/json11 core.gyp djinni
	ANDROID_BUILD_TOP=dirname PYTHONPATH=deps/gyp/pylib $(which ndk-build) deps/gyp/gyp --depth=. -f android -DOS=android --root-target libcore_android -Icommon.gypi core.gyp

xb-prettifier := $(shell command -v xcpretty >/dev/null 2>&1 && echo "xcpretty -c" || echo "cat")

# a simple place to test stuff out
play: build_mac/core.xcodeproj objc/play.m
	xcodebuild -project build_mac/core.xcodeproj -configuration Debug -target play_objc | ${xb-prettifier} && ./build/Debug/play_objc

mac: build_mac/core.xcodeproj
	xcodebuild -project build_mac/core.xcodeproj -configuration Release -target libcore_objc | ${xb-prettifier}

ios: build_ios/core.xcodeproj
	xcodebuild -project project/ios/core.xcodeproj -configuration Release -target libcore_objc | ${xb-prettifier}

# This file needs to be manually configured per system.
project/android/local.properties:
	@echo "Android SDK and NDK not properly configured, please create a project/android/local.properties file." && false

android: GypAndroid.mk project/android/local.properties
	cd project/android && ./gradlew app:assembleDebug && cd ..

test: build_mac/core.xcodeproj
	xcodebuild -project build_mac/core.xcodeproj -configuration Debug -target test | ${xb-prettifier} && ./build/Debug/test

cleanup_gyp: ./deps/gyp core.gyp common.gypi
	deps/gyp/tools/pretty_gyp.py deps/gtest.gyp > gtest_temp.gyp && mv gtest_temp.gyp deps/gtest.gyp
	deps/gyp/tools/pretty_gyp.py deps/json11.gyp > json11_temp.gyp && mv json11_temp.gyp deps/json11.gyp
	deps/gyp/tools/pretty_gyp.py deps/sqlite3.gyp > sqlite3_temp.gyp && mv sqlite3_temp.gyp deps/sqlite3.gyp
	deps/gyp/tools/pretty_gyp.py deps/simpleini.gyp > simpleini_temp.gyp && mv simpleini_temp.gyp deps/simpleini.gyp
	deps/gyp/tools/pretty_gyp.py core.gyp > core_temp.gyp && mv core_temp.gyp core.gyp
	deps/gyp/tools/pretty_gyp.py common.gypi > common_temp.gypi && mv common_temp.gypi common.gypi

.PHONY: djinni
