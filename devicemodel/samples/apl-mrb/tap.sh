#!/bin/bash

echo "dm_run: before tap preparing" > /dev/kmsg

tap_exist=$(ip a | grep acrn_"$1" | awk '{print $1}')
if [ "$tap_exist"x != "x" ]; then
  echo "tap device existed, reuse acrn_$1"
else
  ip tuntap add dev acrn_$1 mode tap
fi

# if acrn-br0 exists, add VM's unique tap device under it
br_exist=$(ip a | grep acrn-br0 | awk '{print $1}')
if [ "$br_exist"x != "x" -a "$tap_exist"x = "x" ]; then
  echo "acrn-br0 bridge aleady exists, adding new tap device to it..."
  ip link set acrn_"$1" master acrn-br0
  ip link set dev acrn_"$1" down
  ip link set dev acrn_"$1" up
fi

echo "dm_run: after tap preparing" > /dev/kmsg
