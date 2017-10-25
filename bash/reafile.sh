
#!/bin/bash
filename="file.txt"
x=$((0))
name=""
while read -r line
do
    name="$line"
    if [[ "$x" == "9" ]]; then
        echo "$name"
    fi
    x=$(($x + 1))
done < "$filename"

name="$line"
if [[ "$x" == "9" ]]; then
    echo "$name"
fi