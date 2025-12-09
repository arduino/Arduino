Starting the Foundation platform
For more information see Command-line overview.

Starting the model using ARM Trusted Firmware, UEFI, Linux kernel and filesystem on a block device
To start the model, use:


  ./Foundation_Platform \

  --data=fvp_bl1.bin@0x0 \

  --data=fvp_fip.bin@0x8000000 \

  --block-device=filesystem.img
fvp_bl1.bin and fvp_fip.bin can be downloaded from the Linaro website at http://releases.linaro.org/latest/openembedded/aarch64/.

Starting the model using a kernel and initramfs
To start the model with a kernel and initramfs:

Build an initramfs in to the kernel.
Use the boot-wrapper to create an AXF (probably called linux-system.axf).
Launch the AXF on the Foundation Platform using:

./Linux64_Foundation_v8/Foundation_v8 --image linux-system.axf
Starting the model using usermode networking
Use:


./Foundation_v8 --network=nat --image linux-system.axf
Starting the model using a kernel and filesystem on a block device
Use:


./Foundation_v8 --image linux-system.axf --block-device filesystem.img
The Linux kernel must be compiled with CONFIG_VIRTIO, CONFIG_VIRTIO_MMIO, CONFIG_VIRTIO_RING, and CONFIG_VIRTIO_BLK and the kernel boot arguments provided in the boot wrapper must include root=/dev/vda. This is the device name of the virtio system block.
