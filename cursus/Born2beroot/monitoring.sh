#!/bin/bash

arch=$(uname -a)
pcpu=$(cat /proc/cpuinfo | grep "physical id" | wc -l)
vcpu=$(cat /proc/cpuinfo | grep "processor" | wc -l)
ucpu=$(top -bn1 | grep "Cpu" | awk '{print $2+$4}')
memused=$(free -m | grep "Mem" | awk '{print $3}')
memtotal=$(free -m | grep "Mem" | awk '{print $2}')
mempour=$(echo $memused $memtotal | awk '{print ($1 / $2) * 100}')
diskusage=$(df --total -m | grep "total" | awk '{print $3}')
disktotal=$(df --total -h | grep total | awk '{print $2}')
diskpour=$(df --total -h | grep "total" | awk '{print $5}')
date=$(who -b | awk '{print $3 " " $4}')
mac=$(ip a | grep ether | awk '{print $2}')
sudousage=$(journalctl _COMM=sudo | grep "COMMAND" | wc -l)

wall "	#Architecture: $arch
	#CPU physical : $pcpu
	#vCPU : $vcpu
	#Memory Usage: $memused/$(echo $memtotal)MB $(printf "%.2f" $mempour)%
	#Disk Usage: $diskusage/$disktotal ($diskpour)
	#CPU load: $ucpu%
	#Last boot: $date
	#LVM use: $(if grep -q "/dev/mapper" /etc/fstab; then echo "yes"; else echo "no"; fi)
	#Connexions TCP : $(ss | grep tcp | grep ESTAB | wc -l) ESTABLISHED
	#User log: $(who | sed -e '1d' | wc -l)
	#Network: IP $(ip a | grep "inet " | sed -n "n;p" | awk '{print $2}' | cut -d '/' -f 1) ($mac)
	#Sudo : $sudousage cmd
"
