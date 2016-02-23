echo removing *.bin
rm /media/$USER/disk/*.bin
echo removed!
sleep 0.5s
echo copying *.bin to the board
cp *.bin /media/$USER/disk/
echo copied!

