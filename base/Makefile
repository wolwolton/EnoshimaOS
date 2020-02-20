./image/EFI/BOOT/BOOTX64.efi:	~/edk2/Conf/target.txt	~/edk2/MyBootLoader/boot.c
	$(shell cd ~/edk2 \n source ./edksetup.sh)
	build
	mkdir -p ./image
	mkdir -p ./image/EFI
	mkdir -p ./image/EFI/BOOT
	cp ~/edk2/Build/MyBootLoderX64/RELEASE_GCC5/X64/boot.efi ./image/EFI/BOOT/BOOTX64.efi
./image/enoshima.elf:	./main.cpp
	clang++ -c -nostdlib -O2 ./main.cpp -o ./build/main.o
	ld.lld --image-base 0x100000 --icf=none --entry MyMain ./build/main.o -o ./build/enoshima.elf
	mkdir -p ./image
	mkdir -p ./build
	cp ./build/enoshima.elf ./image/enoshima.elf

./build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd:	~/edk2/Build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd
	mkdir -p ./build
	mkdir -p ./build/OvmfX64
	mkdir -p ./build/OvmfX64/RELEASE_GCC5
	mkdir -p ./build/OvmfX64/RELEASE_GCC5/FV
	cp ~/edk2/Build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd ./build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd

./build/OVMF_VARS.fd:	~/edk2/OVMF_VARS.fd
	mkdir -p ./build
	cp ~/edk2/OVMF_VARS.fd ./build/OVMF_VARS.fd

build:	./image/EFI/BOOT/BOOTX64.efi	./image/enoshima.elf
	make run

run:	./build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd	./build/OVMF_VARS.fd
	qemu-system-x86_64 -drive if=pflash,format=raw,file=./build/OvmfX64/RELEASE_GCC5/FV/OVMF_CODE.fd -drive if=pflash,format=raw,file=./build/OVMF_VARS.fd -drive if=ide,format=raw,file=fat:rw:./image,index=0,media=disk
	 