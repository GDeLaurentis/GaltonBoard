#!/bin/bash
for i in pi@10.10.10.{11..16}
do 
	ssh $i sudo killall python &
done

wait
