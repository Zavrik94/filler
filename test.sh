#!/bin/bash

PLAYERS="abanlin carli champely grati hcao superjeannot"

mkdir -p tests
for	pname in $PLAYERS
do

	echo "In this tests Player 'O' must win!" > tests/${pname}_p1
	for i in {1..5}
	do
		echo "Testing -p1 ./azavrazh.filler -p2 players/${pname}.filler ON map00"
		./filler_vm -f maps/map00 -p1 ./azavrazh.filler -p2 players/${pname}.filler | grep "==" >> tests/${pname}_p1 &
	done
	for i in {1..5}
	do
		echo "Testing -p1 ./azavrazh.filler -p2 players/${pname}.filler ON map01"
		./filler_vm -f maps/map01 -p1 ./azavrazh.filler -p2 players/${pname}.filler | grep "==" >> tests/${pname}_p1 &
	done
	for i in {1..5}
	do
		echo "Testing -p1 ./azavrazh.filler -p2 players/${pname}.filler ON map02"
		./filler_vm -f maps/map02 -p1 ./azavrazh.filler -p2 players/${pname}.filler | grep "==" >> tests/${pname}_p1 &
	done


	echo "In this tests Player 'X' must win!" > tests/${pname}_p2
	for i in {1..5}
	do
		echo "Testing -p1 players/${pname}.filler -p2 ./azavrazh.filler ON map00"
		./filler_vm -f maps/map00 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> tests/${pname}_p2 &
	done
	for i in {1..5}
	do
		echo "Testing -p1 players/${pname}.filler -p2 ./azavrazh.filler ON map01"
		./filler_vm -f maps/map01 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> tests/${pname}_p2 &
	done
	for i in {1..5}
	do
		echo "Testing -p1 players/${pname}.filler -p2 ./azavrazh.filler ON map02"
		./filler_vm -f maps/map02 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> tests/${pname}_p2 &
	done

done
