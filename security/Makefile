#
# Makefile for the kernel security code
#

obj-$(CONFIG_KEYS)			+= keys/
subdir-$(CONFIG_SECURITY_SELINUX)	+= selinux
subdir-$(CONFIG_SECURITY_SMACK)		+= smack

# always enable default capabilities
obj-y		+= commoncap.o

# Object file lists
obj-$(CONFIG_SECURITY)			+= security.o capability.o inode.o
# Must precede capability.o in order to stack properly.
obj-$(CONFIG_SECURITY_SELINUX)		+= selinux/built-in.o
obj-$(CONFIG_SECURITY_SMACK)		+= smack/built-in.o
obj-$(CONFIG_SECURITY_ROOTPLUG)		+= root_plug.o
obj-$(CONFIG_SECURITY_LOWMEM)		+= commoncap.o lowmem.o
obj-$(CONFIG_CGROUP_DEVICE)		+= device_cgroup.o
