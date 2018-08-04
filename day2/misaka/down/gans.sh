g++ ../code/std.cpp -o misaka
ulimit -s hard
for ((i = 1; i <= 4; ++i));
do
./misaka < $i.in > $i.ans
done
