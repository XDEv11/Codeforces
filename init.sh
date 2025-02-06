game="" number=5
if [ $# = 1 ]; then
	game=$1
elif [ $# = 2 ]; then
	game=$1 number=$2
else
	echo "... GAME (#PROBLEMS)"
	exit 1
fi
mkdir $game
if [ $? != 0 ]; then
	exit 1
fi
cp Makefile $game
for i in $( seq 1 $number ); do
	c=$(printf \\$(printf "%o\n" $(( 64 + $i ))))
	cp P.cpp $game/$c.cpp
done
cd $game

