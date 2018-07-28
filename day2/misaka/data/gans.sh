g++ ../code/std.cpp -o misaka
ulimit -s hard
for ((i = 1; i <= 25; ++i));
do
./misaka < $i.in > $i.ans
done
