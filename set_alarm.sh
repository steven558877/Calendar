#echo "./home/erer/Calendar/Alarm" $1 $2 $3 $4 $5 $6 $7 | at $8 $2 
echo "DISPLAY=:0 /home/erer/Calendar/Alarm" $1 $2 $3 \"$4\" $5 $6 $7 | at $8 $2
