g++ ../code/std.cpp -o portal
ulimit -s hard
for ((i = 1; i <= 4; ++i));
do
./portal < $i.in > $i.ans
done
