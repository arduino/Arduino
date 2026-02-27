Setting up a block device image for a root file system
#
method assumes that you have created a compressed filesystem for the files you want to add to the root file system.

To set up a block device image for a root file system:

Create an empy file (filename) of the correct size using:

#
- dd if=/dev/zero of=<filename> bs=1M count=<number of megabytes>
Make a filesystem inside that file using:

#
- mkfs.ext4 <filename>
Mount the filesystem on your host system using:

# 
- mkdir /mnt/AArch64

# 
- mount -o loop <filename> /mnt/AArch64
Extract your filesystem onto the device using:

#
- cd /mnt/AArch64

# 
- zcat /path/to/filesystem.cpio.gz | cpio -divmu --no-absolute-filenames

# 
- cd /
Unmount the device using:

#
- umount /mnt/AArch64
Your block-device image is ready for use. To use it in the Platform, configure the root device in the boot wrapper Makefile as root=/dev/vda and rebuild the boot wrapper.
Warning
For most networking protocols, using Network Address Translation (NAT) or usermode networking suffices. However, if you are trying to use an NFS server running on the same machine as the Platform, usermode networking will not work for this. Instead, configure networking using bridging. See Network connections.

Note
If you are using nfsroot, be careful that the IP address on your host machine does not change while you are using it. Poorly-configured DHCP servers can cause unexpected address changes to happen. This causes problems if you are relying on an NFS server for the root filesystem.
