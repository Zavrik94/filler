echo "In this tests Player 'O' must win!" > p1
for i in {1..5}
do
	./filler_vm -f maps/map00 -p1 ./azavrazh.filler -p2 players/carli.filler | grep "==" >> p1
	echo >> p1
done
for i in {1..5}
do
	./filler_vm -f maps/map01 -p1 ./azavrazh.filler -p2 players/carli.filler | grep "==" >> p1
	echo >> p1
done
for i in {1..5}
do
	./filler_vm -f maps/map02 -p1 ./azavrazh.filler -p2 players/carli.filler | grep "==" >> p1
	echo >> p1
done


echo "In this tests Player 'X' must win!" > p2
for i in {1..5}
do
	./filler_vm -f maps/map00 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> p2
	echo >> p2
done
for i in {1..5}
do
	./filler_vm -f maps/map01 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> p2
	echo >> p2
done
for i in {1..5}
do
	./filler_vm -f maps/map02 -p2 ./azavrazh.filler -p1 players/carli.filler | grep "==" >> p2
	echo >> p2
done